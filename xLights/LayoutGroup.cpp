
#include <wx/wx.h>
#include <wx/xml/xml.h>

#include "LayoutGroup.h"
#include "xLightsMain.h"
#include "models/Model.h"
#include "PreviewPane.h"

LayoutGroup::LayoutGroup(const std::string & name, xLightsFrame* xl, wxXmlNode *node)
: mName(name), mScaleBackgroundImage(false), mBackgroundBrightness(100), mPreviewHidden(true), mPreviewCreated(false),
   mModelPreview(nullptr), xlights(xl), LayoutGroupXml(node), id_menu_item(wxNewId()), mPreviewPane(nullptr),
   mPosX(-1), mPosY(-1), mPaneWidth(-1), mPaneHeight(-1), ignore_size_and_pos(false)

{
    SetFromXml(node);
}

LayoutGroup::~LayoutGroup()
{
    previewModels.clear();
}

void LayoutGroup::SetBackgroundImage(const wxString &filename)
{
    if (mBackgroundImage != filename) {
        mBackgroundImage = filename;
        LayoutGroupXml->DeleteAttribute("backgroundImage");
        LayoutGroupXml->AddAttribute("backgroundImage", mBackgroundImage);
        if( mModelPreview != nullptr ) {
            mModelPreview->SetbackgroundImage(mBackgroundImage);
            if( !mPreviewHidden ) {
                mModelPreview->Refresh();
                mModelPreview->Update();
            }
        }
        xlights->MarkEffectsFileDirty();
    }
}

void LayoutGroup::SetBackgroundBrightness(int i)
{
    if (mBackgroundBrightness != i) {
        mBackgroundBrightness = i;
        LayoutGroupXml->DeleteAttribute("backgroundBrightness");
        LayoutGroupXml->AddAttribute("backgroundBrightness", wxString::Format("%d",mBackgroundBrightness));
        if( mModelPreview != nullptr ) {
            mModelPreview->SetBackgroundBrightness(mBackgroundBrightness);
        }
        xlights->MarkEffectsFileDirty();
    }
}

void LayoutGroup::SetBackgroundScaled(bool scaled)
{
    if (mScaleBackgroundImage != scaled) {
        mScaleBackgroundImage = scaled;
        LayoutGroupXml->DeleteAttribute("scaleImage");
        LayoutGroupXml->AddAttribute("scaleImage", wxString::Format("%d",scaled));
        if( mModelPreview != nullptr ) {
            mModelPreview->SetScaleBackgroundImage(scaled);
        }
        xlights->MarkEffectsFileDirty();
    }
}

void LayoutGroup::SetPreviewPosition(wxPoint point)
{
    if( !ignore_size_and_pos ) {
        LayoutGroupXml->DeleteAttribute("PosX");
        LayoutGroupXml->AddAttribute("PosX", wxString::Format("%d",point.x));
        LayoutGroupXml->DeleteAttribute("PosY");
        LayoutGroupXml->AddAttribute("PosY", wxString::Format("%d",point.y));
        xlights->MarkEffectsFileDirty();
    }
}

void LayoutGroup::SetPreviewSize(wxSize size_)
{
    if( !ignore_size_and_pos ) {
        LayoutGroupXml->DeleteAttribute("PaneWidth");
        LayoutGroupXml->AddAttribute("PaneWidth", wxString::Format("%d",size_.GetWidth()));
        LayoutGroupXml->DeleteAttribute("PaneHeight");
        LayoutGroupXml->AddAttribute("PaneHeight", wxString::Format("%d",size_.GetHeight()));
        LayoutGroupXml->DeleteAttribute("PosX");
        LayoutGroupXml->AddAttribute("PosX", wxString::Format("%d",size_.x));
        LayoutGroupXml->DeleteAttribute("PosY");
        LayoutGroupXml->AddAttribute("PosY", wxString::Format("%d",size_.y));
        xlights->MarkEffectsFileDirty();
    }
}

void LayoutGroup::SetFromXml(wxXmlNode* LayoutGroupNode)
{
    LayoutGroupXml = LayoutGroupNode;
    mName=LayoutGroupNode->GetAttribute("name").ToStdString();
    mBackgroundImage=LayoutGroupNode->GetAttribute("backgroundImage").ToStdString();
    mBackgroundBrightness=wxAtoi(LayoutGroupNode->GetAttribute("backgroundBrightness","100").ToStdString());
    mScaleBackgroundImage=wxAtoi(LayoutGroupNode->GetAttribute("scaleImage","0").ToStdString());
}

wxXmlNode* LayoutGroup::GetLayoutGroupXml() const {
    return this->LayoutGroupXml;
}

void LayoutGroup::SetModels(std::vector<Model*> &models)
{
    previewModels.clear();
    for (auto it = models.begin(); it != models.end(); it++) {
        previewModels.push_back(*it);
    }
}

void LayoutGroup::ResetPositions()
{
    if( mPreviewPane != nullptr ) {
        ModelPreview* modelPreview = xlights->GetLayoutPreview();
        mPaneWidth = modelPreview->GetVirtualCanvasWidth();
        mPaneHeight = modelPreview->GetVirtualCanvasHeight();
        mPreviewPane->SetSize(modelPreview->GetPosition().x+100, modelPreview->GetPosition().y+100, mPaneWidth, mPaneHeight);
    }
}

void LayoutGroup::SetPreviewActive(bool show)
{
    if( mPreviewCreated ) {
        mPreviewHidden = !show;
        mModelPreview->SetActive(show);
    }
}

const long LayoutGroup::AddToPreviewMenu(wxMenu* preview_menu)
{
    mMenuItemPreview = new wxMenuItem(preview_menu, id_menu_item, mName, wxEmptyString, wxITEM_CHECK);
    preview_menu->Append(mMenuItemPreview);
    return id_menu_item;
}

void LayoutGroup::ShowPreview(bool show)
{
    if( !mPreviewCreated ) {
        ignore_size_and_pos = true;
        ModelPreview* modelPreview = xlights->GetLayoutPreview();
        PreviewPane* preview = new PreviewPane(xlights, wxID_ANY, wxDefaultPosition, wxSize(modelPreview->GetVirtualCanvasWidth(), modelPreview->GetVirtualCanvasHeight()));
        mPreviewPane = preview;
        wxPanel* panel = preview->GetPreviewPanel();
        wxFlexGridSizer* panel_sizer = preview->GetPreviewPanelSizer();
        ModelPreview* new_preview = new ModelPreview(panel, GetModels(), false);
        new_preview->SetPreviewPane(preview);
        mModelPreview = new_preview;
        panel_sizer->Add(new_preview, 1, wxALL | wxEXPAND, 0);
        preview->SetLayoutGroup(this);

        if( !mPreviewCreated ) {
            mPaneWidth = wxAtoi(LayoutGroupXml->GetAttribute("PaneWidth", "-1"));
            mPaneHeight = wxAtoi(LayoutGroupXml->GetAttribute("PaneHeight", "-1"));
            mPosX = wxAtoi(LayoutGroupXml->GetAttribute("PosX", "-1"));
            mPosY = wxAtoi(LayoutGroupXml->GetAttribute("PosY", "-1"));
            if( mPaneWidth == -1 ) {
                mPaneWidth = modelPreview->GetVirtualCanvasWidth();
            }
            if( mPaneHeight == -1 ) {
                mPaneHeight = modelPreview->GetVirtualCanvasHeight();
            }
        }
        preview->SetSize(mPosX, mPosY, mPaneWidth, mPaneHeight);
        xlights->PreviewWindows.push_back(new_preview);
        new_preview->InitializePreview(mBackgroundImage,modelPreview->GetBackgroundBrightness());
        new_preview->SetScaleBackgroundImage(modelPreview->GetScaleBackgroundImage());
        new_preview->SetCanvasSize(modelPreview->GetVirtualCanvasWidth(),modelPreview->GetVirtualCanvasHeight());
        mPreviewCreated = true;
        mMenuItemPreview->Check(true);
        ignore_size_and_pos = false;
    }
    SetPreviewActive(show);
    mMenuItemPreview->Check(show);
}

