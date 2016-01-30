#ifndef EFFECTTREEDIALOG_H
#define EFFECTTREEDIALOG_H

//(*Headers(EffectTreeDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/treectrl.h>
//*)
#include <wx/xml/xml.h>
#include <wx/filename.h>

class xLightsFrame;

class EffectTreeDialog : public wxDialog
{
	public:

		EffectTreeDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~EffectTreeDialog();

		//(*Declarations(EffectTreeDialog)
		wxButton* btRename;
		wxButton* btImport;
		wxButton* btNewPreset;
		wxButton* btDelete;
		wxButton* btUpdate;
		wxTreeCtrl* TreeCtrl1;
		wxButton* btApply;
		wxButton* btAddGroup;
		//*)
        wxTreeItemId treeRootID;
        void InitItems(wxXmlNode *e);

	protected:

		//(*Identifiers(EffectTreeDialog)
		static const long ID_TREECTRL1;
		static const long ID_BUTTON6;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON7;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON8;
		//*)

	private:

		//(*Handlers(EffectTreeDialog)
		void OnbtApplyClick(wxCommandEvent& event);
		void OnbtNewPresetClick(wxCommandEvent& event);
		void OnbtUpdateClick(wxCommandEvent& event);
		void OnbtRenameClick(wxCommandEvent& event);
		void OnbtDeleteClick(wxCommandEvent& event);
		void OnbtAddGroupClick(wxCommandEvent& event);
		void OnTreeCtrl1ItemActivated(wxTreeEvent& event);
		void OnButton_OKClick(wxCommandEvent& event);
		void OnTreeCtrl1BeginDrag(wxTreeEvent& event);
		void OnTreeCtrl1EndDrag(wxTreeEvent& event);
		void OnbtImportClick(wxCommandEvent& event);
		//*)

        xLightsFrame* xLightParent;
		wxXmlNode *XrgbEffectsNode;
        wxTreeItemId m_draggedItem;
        void AddTreeElementsRecursive(wxXmlNode *EffectsNode, wxTreeItemId curGroupID);
        wxXmlNode* CreateEffectGroupNode(wxString& name);
        void ApplyEffect(bool dblClick=false);
        void AddImportedItemsRecursively(wxXmlNode* effects_node, wxTreeItemId curGroupID);
        void EffectsFileDirty();

		DECLARE_EVENT_TABLE()

    public:
        static bool PromptForName(wxWindow* parent, wxString *name, wxString prompt, wxString errorMsg); //static to allow re-use elsewhere -DJ
};

class MyTreeItemData : public wxTreeItemData
{
public:
    MyTreeItemData(wxXmlNode* desc, bool isGroup=false) {element=desc; _isGroup=isGroup; }

    wxXmlNode *GetElement() { return element; }
    bool IsGroup() { return _isGroup; }
private:
    wxXmlNode *element;
    bool _isGroup;
};

#endif
