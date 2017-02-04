#ifndef PLAYLISTITEMVIDEOPANEL_H
#define PLAYLISTITEMVIDEOPANEL_H

//(*Headers(PlayListItemVideoPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/filepicker.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

class PlayListItemVideo;
class VideoFilePickerCtrl;

class PlayListItemVideoPanel: public wxPanel
{
    PlayListItemVideo* _video;

	public:

		PlayListItemVideoPanel(wxWindow* parent, PlayListItemVideo* video,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PlayListItemVideoPanel();

		//(*Declarations(PlayListItemVideoPanel)
		wxStaticText* StaticText2;
		VideoFilePickerCtrl* FilePickerCtrl_VideoFile;
		wxStaticText* StaticText1;
		wxCheckBox* CheckBox_Topmost;
		wxTextCtrl* TextCtrl_Delay;
		wxButton* Button_PositionWindow;
		//*)

	protected:

		//(*Identifiers(PlayListItemVideoPanel)
		static const long ID_STATICTEXT1;
		static const long ID_FILEPICKERCTRL1;
		static const long ID_BUTTON1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(PlayListItemVideoPanel)
		void OnButton_PositionWindowClick(wxCommandEvent& event);
		void OnFilePickerCtrl_VideoFileFileChanged(wxFileDirPickerEvent& event);
		void OnTextCtrl_DelayText(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
