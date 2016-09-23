
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/xml/xml.h>
#include "StarModel.h"

StarModel::StarModel(wxXmlNode *node, const ModelManager &manager, bool zeroBased) : ModelWithScreenLocation(manager)
{
    SetFromXml(node, zeroBased);
}

StarModel::~StarModel()
{
    //dtor
}


std::vector<std::string> StarModel::STAR_BUFFER_STYLES;

const std::vector<std::string> &StarModel::GetBufferStyles() const {
    struct Initializer {
        Initializer() {
            STAR_BUFFER_STYLES = Model::DEFAULT_BUFFER_STYLES;
            STAR_BUFFER_STYLES.push_back("Layer Star");
        }
    };
    static Initializer ListInitializationGuard;
    return STAR_BUFFER_STYLES;
}

void StarModel::GetBufferSize(const std::string &type, const std::string &transform, int &BufferWi, int &BufferHi) const {
    if (type == "Layer Star") {
        BufferHi = GetNumStrands();
        BufferWi = 0;
        for (int x = 0; x < BufferHi; x++) {
            int w = GetStarSize(x);
            if (w > BufferWi) {
                BufferWi = w;
            }
        }
        AdjustForTransform(transform, BufferWi, BufferHi);
    } else {
        Model::GetBufferSize(type, transform, BufferWi, BufferHi);
    }
}
void StarModel::InitRenderBufferNodes(const std::string &type,
                                      const std::string &transform,
                                      std::vector<NodeBaseClassPtr> &newNodes, int &BufferWi, int &BufferHi) const {
    if (type == "Layer Star") {
        BufferHi = GetNumStrands();
        BufferWi = 0;
        for (int x = 0; x < BufferHi; x++) {
            int w = GetStarSize(x);
            if (w > BufferWi) {
                BufferWi = w;
            }
        }
        for (int x = 0; x < BufferHi; x++) {
            int w = GetStarSize(x);
            for (int z = 0; z < w; z++) {

            }
        }
        for (auto it = Nodes.begin(); it != Nodes.end(); it++) {
            newNodes.push_back(NodeBaseClassPtr(it->get()->clone()));
        }

        int start = 0;
        for (int cur = 0; cur < starSizes.size(); cur++) {
            int numlights = starSizes[cur];
            if (numlights == 0) {
                continue;
            }

            for(size_t cnt=0; cnt<numlights; cnt++) {
                int n = cur;
                if (!SingleNode) {
                    n = cnt + start;
                } else {
                    n = cur;
                    if (n >= Nodes.size()) {
                        n = Nodes.size() - 1;
                    }
                }
                for (auto it = newNodes[n]->Coords.begin(); it != newNodes[n]->Coords.end(); it++) {
                    it->bufY = cur;
                    it->bufX = cnt * BufferWi / numlights;
                }
            }
            start += numlights;
        }
        ApplyTransform(transform, newNodes, BufferWi, BufferHi);
    } else {
        Model::InitRenderBufferNodes(type, transform, newNodes, BufferWi, BufferHi);
    }
}



int StarModel::GetStrandLength(int strand) const {
    return SingleNode ? 1 : GetStarSize(strand);
}
int StarModel::MapToNodeIndex(int strand, int node) const {
    int idx = 0;
    for (int x = 0; x < strand; x++) {
        idx += GetStarSize(x);
    }
    idx += node;
    return idx;
}
int StarModel::GetNumStrands() const {
    return starSizes.size();
}

bool StarModel::AllNodesAllocated() const 
{
    int allocated = 0;
    for (auto it = starSizes.begin(); it != starSizes.end(); ++it)
    {
        allocated += *it;
    }

    return (allocated == GetNodeCount());
}

// parm3 is number of points
// top left=top ccw, top right=top cw, bottom left=bottom cw, bottom right=bottom ccw

void StarModel::InitModel() {
    wxString tempstr=ModelXml->GetAttribute("starSizes");
    starSizes.resize(0);
    while (tempstr.size() > 0) {
        wxString t2 = tempstr;
        if (tempstr.Contains(",")) {
            t2 = tempstr.SubString(0, tempstr.Find(","));
            tempstr = tempstr.SubString(tempstr.Find(",") + 1, tempstr.length());
        } else {
            tempstr = "";
        }
        long i2 = 0;
        t2.ToLong(&i2);
        if ( i2 > 0) {
            starSizes.resize(starSizes.size() + 1);
            starSizes[starSizes.size() - 1] = i2;
        }
    }


    if (parm3 < 2) parm3=2; // need at least 2 arms
    SetNodeCount(parm1,parm2,rgbOrder);

    int maxLights = 0;
    int numlights=parm1*parm2;
    int cnt = 0;
    if (starSizes.size() == 0) {
        starSizes.resize(1);
        starSizes[0] = numlights;
    }
    for (int x = 0; x < starSizes.size(); x++) {
        if ((cnt + starSizes[x]) > numlights) {
            starSizes[x] = numlights - cnt;
        }
        cnt += starSizes[x];
        if (starSizes[x] > maxLights) {
            maxLights = starSizes[x];
        }
    }
    SetBufferSize(maxLights+1,maxLights+1);


    int LastStringNum=-1;
    int chan = 0,cursegment,nextsegment,x,y;
    int start = 0;

    for (int cur = 0; cur < starSizes.size(); cur++) {
        numlights = starSizes[cur];
        if (numlights == 0) {
            continue;
        }

        int offset=numlights/2;

        int coffset = (maxLights - numlights) / 2;
        /*
         if (cur > 0) {
         for (int f = cur; f > 0; f--) {
         int i = starSizes[f];
         int i2 = starSizes[f - 1];
         coffset += (i2 - i) / 2;
         }
         }
         */

        int numsegments=parm3*2;
        double segstart_x,segstart_y,segend_x,segend_y,segstart_pct,segend_pct,r,segpct,dseg;
        double dpct=1.0/(double)numsegments;
        double OuterRadius=offset;
        double InnerRadius=OuterRadius/2.618034;    // divide by golden ratio squared
        double pct=isBotToTop ? 0.5 : 0.0;          // % of circle, 0=top
        double pctIncr=1.0 / (double)numlights;     // this is cw
        if (IsLtoR != isBotToTop) pctIncr*=-1.0;    // adjust to ccw
        int ChanIncr=SingleChannel ?  1 : 3;
        for(size_t cnt=0; cnt<numlights; cnt++) {
            int n = cur;
            if (!SingleNode) {
                n = start + cnt;
            } else {
                n = cur;
                if (n >= Nodes.size()) {
                    n = Nodes.size() - 1;
                }
            }
            if (Nodes[n]->StringNum != LastStringNum) {
                LastStringNum=Nodes[n]->StringNum;
                chan=stringStartChan[LastStringNum];
            }
            Nodes[n]->ActChan=chan;
            if (!SingleNode) {
                chan+=ChanIncr;
            }
            size_t CoordCount=GetCoordCount(n);
            int lastx = 0, lasty = 0;
            for(size_t c=0; c < CoordCount; c++) {
                if (c >= numlights) {
                    Nodes[n]->Coords[c].bufX=lastx;
                    Nodes[n]->Coords[c].bufY=lasty;
                } else {
                    cursegment=(int)((double)numsegments*pct) % numsegments;
                    nextsegment=(cursegment+1) % numsegments;
                    segstart_pct=(double)cursegment / numsegments;
                    segend_pct=(double)nextsegment / numsegments;
                    dseg=pct - segstart_pct;
                    segpct=dseg / dpct;
                    r=cursegment%2==0 ? OuterRadius : InnerRadius;
                    segstart_x=r*sin(segstart_pct*2.0*M_PI);
                    segstart_y=r*cos(segstart_pct*2.0*M_PI);
                    r=nextsegment%2==0 ? OuterRadius : InnerRadius;
                    segend_x=r*sin(segend_pct*2.0*M_PI);
                    segend_y=r*cos(segend_pct*2.0*M_PI);
                    // now interpolate between segstart and segend
                    x=(segend_x - segstart_x)*segpct + segstart_x + offset + 0.5 + coffset;
                    y=(segend_y - segstart_y)*segpct + segstart_y + offset + 0.5 + coffset;
                    Nodes[n]->Coords[c].bufX=x;
                    Nodes[n]->Coords[c].bufY=y;
                    lastx = x;
                    lasty = y;
                    pct+=pctIncr;
                    if (pct >= 1.0) pct-=1.0;
                    if (pct < 0.0) pct+=1.0;
                }
            }
        }
        start += numlights;
    }

    CopyBufCoord2ScreenCoord();
}



static wxPGChoices TOP_BOT_LEFT_RIGHT;

void StarModel::AddTypeProperties(wxPropertyGridInterface *grid) {
    if (TOP_BOT_LEFT_RIGHT.GetCount() == 0) {
        TOP_BOT_LEFT_RIGHT.Add("Top Ctr-CCW");
        TOP_BOT_LEFT_RIGHT.Add("Top Ctr-CW");
        TOP_BOT_LEFT_RIGHT.Add("Bottom Ctr-CW");
        TOP_BOT_LEFT_RIGHT.Add("Bottom Ctr-CCW");
    }
    wxPGProperty *p = grid->Append(new wxUIntProperty("# Strings", "StarStringCount", parm1));
    p->SetAttribute("Min", 1);
    p->SetAttribute("Max", 640);
    p->SetEditor("SpinCtrl");

    if (SingleNode) {
        p = grid->Append(new wxUIntProperty("Lights/String", "StarLightCount", parm2));
        p->SetAttribute("Min", 1);
        p->SetAttribute("Max", 640);
        p->SetEditor("SpinCtrl");
    } else {
        p = grid->Append(new wxUIntProperty("Nodes/String", "StarLightCount", parm2));
        p->SetAttribute("Min", 1);
        p->SetAttribute("Max", 640);
        p->SetEditor("SpinCtrl");
    }

    p = grid->Append(new wxUIntProperty("# Points", "StarStrandCount", parm3));
    p->SetAttribute("Min", 1);
    p->SetAttribute("Max", 250);
    p->SetEditor("SpinCtrl");

    p = grid->Append(new wxEnumProperty("Starting Location", "StarStart", TOP_BOT_LEFT_RIGHT, IsLtoR ? (isBotToTop ? 2 : 0) : (isBotToTop ? 3 : 1)));
    p = grid->Append(new wxStringProperty("Layer Sizes", "StarLayerSizes", ModelXml->GetAttribute("starSizes")));
}
int StarModel::OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) {
    if ("StarStringCount" == event.GetPropertyName()) {
        ModelXml->DeleteAttribute("parm1");
        ModelXml->AddAttribute("parm1", wxString::Format("%d", (int)event.GetPropertyValue().GetLong()));
        SetFromXml(ModelXml, zeroBased);
        AdjustStringProperties(grid, parm1);
        return 3 | 0x0008;
    } else if ("StarLightCount" == event.GetPropertyName()) {
        ModelXml->DeleteAttribute("parm2");
        ModelXml->AddAttribute("parm2", wxString::Format("%d", (int)event.GetPropertyValue().GetLong()));
        SetFromXml(ModelXml, zeroBased);
        return 3 | 0x0008;
    } else if ("StarStrandCount" == event.GetPropertyName()) {
        ModelXml->DeleteAttribute("parm3");
        ModelXml->AddAttribute("parm3", wxString::Format("%d", (int)event.GetPropertyValue().GetLong()));
        SetFromXml(ModelXml, zeroBased);
        return 3 | 0x0008;
    } else if ("StarStart" == event.GetPropertyName()) {
        ModelXml->DeleteAttribute("Dir");
        ModelXml->AddAttribute("Dir", event.GetValue().GetLong() == 0 || event.GetValue().GetLong() == 2 ? "L" : "R");
        ModelXml->DeleteAttribute("StartSide");
        ModelXml->AddAttribute("StartSide", event.GetValue().GetLong() == 0 || event.GetValue().GetLong() == 1 ? "T" : "B");
        SetFromXml(ModelXml, zeroBased);
        return 3;
    } else if ("StarLayerSizes" == event.GetPropertyName()) {
        ModelXml->DeleteAttribute("starSizes");
        ModelXml->AddAttribute("starSizes", event.GetValue().GetString());
        SetFromXml(ModelXml, zeroBased);
        return 3;
    }

    return Model::OnPropertyGridChange(grid, event);
}
