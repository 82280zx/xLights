#ifndef DIMWHITEDIALOG_H
#define DIMWHITEDIALOG_H

//(*Headers(DimWhiteDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DimWhiteDialog: public wxDialog
{
    size_t& _startChannel;
    size_t& _nodes;
    size_t& _dim;
    std::string& _description;

	public:

		DimWhiteDialog(wxWindow* parent, size_t& startChannel, size_t& channels, size_t& dim, std::string& description,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DimWhiteDialog();

		//(*Declarations(DimWhiteDialog)
		wxButton* Button_Ok;
		wxTextCtrl* TextCtrl_Description;
		wxStaticText* StaticText2;
		wxSpinCtrl* SpinCtrl_Nodes;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button_Cancel;
		wxSpinCtrl* SpinCtrl_Brightness;
		wxStaticText* StaticText4;
		wxSpinCtrl* SpinCtrl_StartChannel;
		//*)

	protected:

		//(*Identifiers(DimWhiteDialog)
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DimWhiteDialog)
		void OnButton_OkClick(wxCommandEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
