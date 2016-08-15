#include "Element.h"
#include "../models/Model.h"
#include <list>

Element::Element(SequenceElements *p, const std::string &name) :
mEffectLayers(),
mName(name),
mVisible(true),
listener((ChangeListener *)p),
mCollapsed(false),
parent(p)
{
    
}
Element::~Element() {
    for (size_t x = 0; x < mEffectLayers.size(); x++) {
        delete mEffectLayers[x];
    }
    mEffectLayers.clear();
}
const std::string &Element::GetName() const
{
    return mName;
}
void Element::SetName(const std::string &name)
{
    mName = name;
    changeCount++;
    listener->IncrementChangeCount(this);
}

const std::string &Element::GetModelName() const {
    return mName;
}

bool Element::HasEffects() const {
    for (size_t x = 0; x < mEffectLayers.size(); x++) {
        if (mEffectLayers[x]->GetEffectCount() > 0) {
            return true;
        }
    }
    return false;
}


EffectLayer* Element::GetEffectLayerFromExclusiveIndex(int index)
{
    for( size_t i = 0; i < mEffectLayers.size(); i++ )
    {
        if( mEffectLayers[i]->GetIndex() == index )
            return mEffectLayers[i];
    }
    
    
    return nullptr;
}




EffectLayer* Element::GetEffectLayer(int index)
{
    if( index >= mEffectLayers.size() ) return nullptr;
    return mEffectLayers[index];
}

EffectLayer* Element::AddEffectLayer()
{
    std::unique_lock<std::recursive_mutex> lock(changeLock);
    EffectLayer* new_layer = new EffectLayer(this);
    mEffectLayers.push_back(new_layer);
    IncrementChangeCount(-1, -1);
    return new_layer;
}

EffectLayer* Element::InsertEffectLayer(int index)
{
    std::unique_lock<std::recursive_mutex> lock(changeLock);
    EffectLayer* new_layer = new EffectLayer(this);
    mEffectLayers.insert(mEffectLayers.begin()+index, new_layer);
    IncrementChangeCount(-1, -1);
    return new_layer;
}

void Element::RemoveEffectLayer(int index)
{
    std::unique_lock<std::recursive_mutex> lock(changeLock);
    EffectLayer *l = GetEffectLayer(index);
    mEffectLayers.erase(mEffectLayers.begin()+index);
    delete l;
    IncrementChangeCount(-1, -1);
}

size_t Element::GetEffectLayerCount()
{
    return mEffectLayers.size();
}

void Element::IncrementChangeCount(int sms, int ems)
{
    SetDirtyRange(sms, ems);
    changeCount++;
    
    listener->IncrementChangeCount(this);
}



TimingElement::TimingElement(SequenceElements *p, const std::string &name)
: Element(p, name),
    mFixed(0)
{
    
}
TimingElement::~TimingElement() {
}


SubModelElement::SubModelElement(ModelElement *p, const std::string &name)
: Element(p->GetSequenceElements(), name), mParentModel(p)
{
    AddEffectLayer();
}
SubModelElement::~SubModelElement() {
    
}


const std::string &SubModelElement::GetModelName() const {
    return mParentModel->GetModelName();
}


StrandElement::StrandElement(ModelElement *p, int strand)
: SubModelElement(p, ""),
  mStrand(strand),
  mShowNodes(false)
{
}
StrandElement::~StrandElement() {
    for (size_t x = 0; x < mNodeLayers.size(); x++) {
        delete mNodeLayers[x];
    }
    mNodeLayers.clear();
}
NodeLayer *StrandElement::GetNodeLayer(int n, bool create) {
    while (create && n >= mNodeLayers.size()) {
        mNodeLayers.push_back(new NodeLayer(this));
    }
    if (n < mNodeLayers.size()) {
        return mNodeLayers[n];
    }
    return nullptr;
}
void StrandElement::InitFromModel(Model &model) {
    int nc = model.GetStrandLength(mStrand);
    SetName(model.GetStrandName(mStrand));
    for (int x = 0; x < mNodeLayers.size(); x++) {
        mNodeLayers[x]->SetName(model.GetNodeName(x));
    }
    while (mNodeLayers.size() < nc) {
        NodeLayer *nl = new NodeLayer(this, model.GetNodeName(mNodeLayers.size()));
        mNodeLayers.push_back(nl);
    }
}

EffectLayer* StrandElement::GetEffectLayerFromExclusiveIndex(int index) {
    EffectLayer *l = Element::GetEffectLayerFromExclusiveIndex(index);
    if (l != nullptr) {
        return l;
    }
    for( size_t j = 0; j < mNodeLayers.size(); j++ ) {
        if (index == mNodeLayers[j]->GetIndex()) {
            return mNodeLayers[j];
        }
    }
    return nullptr;
}



ModelElement::ModelElement(SequenceElements *l, const std::string &name, bool selected)
:   Element(l, name),
    mSelected(selected),
    waitCount(0)
{
}

ModelElement::~ModelElement()
{
    //make sure none of the render threads are rendering this model
    std::unique_lock<std::recursive_mutex> lock(changeLock);
    while (waitCount > 0) {
        lock.unlock();
        wxSleep(1);
        lock.lock();
    }
    for (size_t x = 0; x < mStrands.size(); x++) {
        delete mStrands[x];
    }
    mStrands.clear();
}


int ModelElement::GetWaitCount() {
    return waitCount;
}
void ModelElement::IncWaitCount() {
    waitCount++;
}
void ModelElement::DecWaitCount() {
    waitCount--;
}



std::list<Effect*> GetEffectsBetween(EffectLayer* layer, int start, int end)
{
    std::list<Effect*> res;

    for (int i = 0; i < layer->GetEffectCount(); i++)
    {
        if (layer->GetEffect(i)->GetStartTimeMS() >= start && layer->GetEffect(i)->GetEndTimeMS() <= end)
        {
            res.push_back(layer->GetEffect(i));
        }
    }

    return res;
}

EffectLayer* ModelElement::GetEffectLayerFromExclusiveIndex(int index) {
    EffectLayer *l = Element::GetEffectLayerFromExclusiveIndex(index);
    if (l != nullptr) {
        return l;
    }
    for( size_t j = 0; j < mStrands.size(); j++ ) {
        l = mStrands[j]->GetEffectLayerFromExclusiveIndex(index);
        if (l != nullptr) {
            return l;
        }
    }
    return nullptr;
}
std::string  TimingElement::GetPapagayoExport(int fps) const
{
    if (mEffectLayers.size() != 3) return "";
    int ms = 1000 / fps;
    auto l = mEffectLayers.begin();
    EffectLayer* l1 = *l++;
    int l1count = l1->GetEffectCount();
    EffectLayer* l2 = *l++;
    EffectLayer* l3 = *l;

    std::string res = "lipsync version 1\nxlights.wav\n";
    wxString samppersec = wxString::Format("%d", fps);
    res += std::string(samppersec.c_str()) + "\n";
    int end = mEffectLayers.front()->GetEffect(l1count - 1)->GetEndTimeMS() / ms;
    res += std::string(wxString::Format("%d", end).c_str()) + "\n";
    res += "1\n"; // only ever one voice
    res += "\tVoice 1\n\t";
    for (int i = 0; i < l1count; i++)
    {
        res += l1->GetEffect(i)->GetEffectName() + "|";
    }
    res += "\n";
    res += "\t" + std::string(wxString::Format("%d", l1count).c_str()) + "\n";
    for (int i = 0; i < l1count; i++) // each line
    {
        res += "\t\t" + l1->GetEffect(i)->GetEffectName() + "\n";
        res += "\t\t" + std::string(wxString::Format("%d", l1->GetEffect(i)->GetStartTimeMS() / ms).c_str()) + "\n";
        res += "\t\t" + std::string(wxString::Format("%d", l1->GetEffect(i)->GetEndTimeMS() / ms).c_str()) + "\n";
        std::list<Effect*> words = GetEffectsBetween(l2, l1->GetEffect(i)->GetStartTimeMS(), l1->GetEffect(i)->GetEndTimeMS());
        res += "\t\t" + std::string(wxString::Format("%d", words.size()).c_str()) + "\n";
        for (auto w = words.begin(); w != words.end(); w++)
        {
            std::list<Effect*> ph = GetEffectsBetween(l3, (*w)->GetStartTimeMS(), (*w)->GetEndTimeMS());
            res += "\t\t\t" + (*w)->GetEffectName() + " " + std::string(wxString::Format("%d", (*w)->GetStartTimeMS() / ms).c_str()) + " " + std::string(wxString::Format("%d", (*w)->GetEndTimeMS() / ms).c_str()) + " " + std::string(wxString::Format("%d", ph.size()).c_str()) + "\n";
            for (auto p = ph.begin(); p != ph.end(); p++)
            {
                res += "\t\t\t\t" + std::string(wxString::Format("%d", (*p)->GetStartTimeMS() / ms).c_str()) + " " + (*p)->GetEffectName() + "\n";
            }
        }
    }

    return res;
}

std::string TimingElement::GetExport() const
{
    std::string res = "";

    for (auto l = mEffectLayers.begin(); l != mEffectLayers.end(); ++l)
    {
        res += "   <EffectLayer>\n";
        for (int i = 0; i < (*l)->GetEffectCount(); i++)
        {
            res += "      <Effect label=\""+(*l)->GetEffect(i)->GetEffectName()+
                              "\" starttime=\"" + std::string(wxString::Format("%d",(*l)->GetEffect(i)->GetStartTimeMS()))+
                              "\" endtime=\"" + std::string(wxString::Format("%d", (*l)->GetEffect(i)->GetEndTimeMS())) + 
                              "\" />\n";
        }
        res += "   </EffectLayer>\n";
    }

    return res;
}


void ModelElement::SetSelected(bool active)
{
    mSelected = active;
}

bool ModelElement::GetSelected()
{
    return mSelected;
}

void ModelElement::Init(Model &model) {
    if (model.GetDisplayAs() == "WholeHouse"
        || model.GetDisplayAs() == "ModelGroup") {
        //no strands for a whole house model
        return;
    }
    for (auto sm = model.GetSubModels().begin(); sm != model.GetSubModels().end(); sm++) {
        bool found = false;
        for (auto sm2 = mSubModels.begin(); sm2 != mSubModels.end(); sm2++) {
            found |= ((*sm2)->GetName() == (*sm)->Name());
        }
        if (!found) {
            mSubModels.push_back(new SubModelElement(this, (*sm)->Name()));
        }
    }
    int ns = model.GetNumStrands();
    for (int x = 0; x < ns; x++) {
        GetStrand(x, true)->InitFromModel(model);
    }
}

StrandElement* ModelElement::GetStrand(int index, bool create) {
    while (create && index >= mStrands.size()) {
        StrandElement* new_layer = new StrandElement(this, mStrands.size());
        mStrands.push_back(new_layer);
        IncrementChangeCount(-1, -1);
    }
    if (index >= mStrands.size()) {
        return nullptr;
    }
    return mStrands[index];
}

int ModelElement::GetSubModelCount() const {
    return mSubModels.size() +  mStrands.size();
}
SubModelElement *ModelElement::GetSubModel(int i) {
    if (i < mSubModels.size()) {
        return mSubModels[i];
    }
    i -= mSubModels.size();
    if (i >= mStrands.size()) {
        return nullptr;
    }
    return mStrands[i];
}
SubModelElement *ModelElement::GetSubModel(const std::string &name, bool create) {
    for (auto a = mSubModels.begin(); a != mSubModels.end(); a++) {
        if (name == (*a)->GetName()) {
            return *a;
        }
    }
    for (auto a = mStrands.begin(); a != mStrands.end(); a++) {
        if (name == (*a)->GetName()) {
            return *a;
        }
    }
    if (create) {
        mSubModels.push_back(new SubModelElement(this, name));
        return mSubModels.back();
    }
    return nullptr;
}



