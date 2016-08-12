#ifndef SUBMODELSDIALOG_H
#define SUBMODELSDIALOG_H

#include <map>
#include <vector>

//(*Headers(SubModelsDialog)
#include <wx/dialog.h>
class wxPanel;
class wxGrid;
class wxStdDialogButtonSizer;
class wxCheckBox;
class wxNotebookEvent;
class wxNotebook;
class wxStaticText;
class wxFlexGridSizer;
class wxButton;
class wxGridEvent;
class wxChoice;
//*)


class wxBookCtrlEvent;

class Model;
class ModelPreview;
class SubBufferPanel;

class SubModelsDialog: public wxDialog
{
	public:

		SubModelsDialog(wxWindow* parent);
		virtual ~SubModelsDialog();
    
        void Setup(Model *m);
        void Save();

		//(*Declarations(SubModelsDialog)
		wxCheckBox* LayoutCheckbox;
		wxPanel* ModelPreviewPanelLocation;
		wxFlexGridSizer* SubBufferSizer;
		wxButton* AddRowButton;
		wxPanel* SubBufferPanelHolder;
		wxFlexGridSizer* PreviewSizer;
		wxStaticText* StaticText3;
		wxGrid* NodesGrid;
		wxButton* AddButton;
		wxNotebook* TypeNotebook;
		wxButton* DeleteButton;
		wxChoice* NameChoice;
		wxButton* DeleteRowButton;
		//*)

	protected:

		//(*Identifiers(SubModelsDialog)
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE3;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_CHECKBOX1;
		static const long ID_GRID1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		static const long ID_PANEL1;
		//*)

	public:

		//(*Handlers(SubModelsDialog)
		void OnAddButtonClick(wxCommandEvent& event);
		void OnDeleteButtonClick(wxCommandEvent& event);
		void OnNameChoiceSelect(wxCommandEvent& event);
		void OnNodesGridCellChange(wxGridEvent& event);
		void OnNodesGridCellSelect(wxGridEvent& event);
		void OnLayoutCheckboxClick(wxCommandEvent& event);
		void OnAddRowButtonClick(wxCommandEvent& event);
		void OnDeleteRowButtonClick(wxCommandEvent& event);
		void OnSubBufferRangeChange(wxCommandEvent& event);
		void OnNodesGridCellLeftClick(wxGridEvent& event);
		void OnTypeNotebookPageChanged(wxBookCtrlEvent& event);
		void OnNodesGridLabelLeftClick(wxGridEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
    
    
private:
    void SelectRow(int r);
    void Select(const wxString &name);
    void DisplayRange(const wxString &range);
    
    class SubModelInfo {
    public:
        wxString name;
        bool vertical;
        bool isRanges;
        wxString subBuffer;
        std::vector<wxString> strands;
    };
    
    Model *model;
    ModelPreview *modelPreview;
    SubBufferPanel *subBufferPanel;
    std::map<wxString, SubModelInfo> subModels;
    
};

#endif
