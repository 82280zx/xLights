#include "RipplePanel.h"
#include "../../include/padlock16x16-blue.xpm"
#include "EffectPanelUtils.h"

//(*InternalHeaders(RipplePanel)
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/slider.h>
#include <wx/intl.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/image.h>
//*)

//(*IdInit(RipplePanel)
const long RipplePanel::ID_STATICTEXT71 = wxNewId();
const long RipplePanel::ID_CHOICE_Ripple_Object_To_Draw = wxNewId();
const long RipplePanel::ID_BITMAPBUTTON20 = wxNewId();
const long RipplePanel::ID_STATICTEXT72 = wxNewId();
const long RipplePanel::ID_CHOICE_Ripple_Movement = wxNewId();
const long RipplePanel::ID_BITMAPBUTTON13 = wxNewId();
const long RipplePanel::ID_STATICTEXT74 = wxNewId();
const long RipplePanel::ID_SLIDER_Ripple_Thickness = wxNewId();
const long RipplePanel::IDD_TEXTCTRL_Ripple_Thickness = wxNewId();
const long RipplePanel::ID_BITMAPBUTTON14 = wxNewId();
const long RipplePanel::IDD_SLIDER_Ripple_Cycles = wxNewId();
const long RipplePanel::ID_TEXTCTRL_Ripple_Cycles = wxNewId();
const long RipplePanel::ID_CHECKBOX_Ripple3D = wxNewId();
const long RipplePanel::ID_BITMAPBUTTON17 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RipplePanel,wxPanel)
	//(*EventTable(RipplePanel)
	//*)
END_EVENT_TABLE()

RipplePanel::RipplePanel(wxWindow* parent)
{
	//(*Initialize(RipplePanel)
	wxTextCtrl* TextCtrl34;
	wxStaticText* StaticText176;
	wxFlexGridSizer* FlexGridSizer60;
	wxTextCtrl* TextCtrl33;
	wxSlider* Slider12;
	wxFlexGridSizer* FlexGridSizer57;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer57 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer57->AddGrowableCol(1);
	StaticText69 = new wxStaticText(this, ID_STATICTEXT71, _("Object to Draw"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT71"));
	FlexGridSizer57->Add(StaticText69, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Ripple_Object_To_Draw = new wxChoice(this, ID_CHOICE_Ripple_Object_To_Draw, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Ripple_Object_To_Draw"));
	Choice_Ripple_Object_To_Draw->SetSelection( Choice_Ripple_Object_To_Draw->Append(_("Circle")) );
	Choice_Ripple_Object_To_Draw->Append(_("Square"));
	Choice_Ripple_Object_To_Draw->Append(_("Triangle"));
	FlexGridSizer57->Add(Choice_Ripple_Object_To_Draw, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer57->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_Ripple_Object_To_Draw = new wxBitmapButton(this, ID_BITMAPBUTTON20, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON20"));
	BitmapButton_Ripple_Object_To_Draw->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer57->Add(BitmapButton_Ripple_Object_To_Draw, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText70 = new wxStaticText(this, ID_STATICTEXT72, _("Movement"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT72"));
	FlexGridSizer57->Add(StaticText70, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Ripple_Movement = new wxChoice(this, ID_CHOICE_Ripple_Movement, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Ripple_Movement"));
	Choice_Ripple_Movement->SetSelection( Choice_Ripple_Movement->Append(_("Explode")) );
	Choice_Ripple_Movement->Append(_("Implode"));
	FlexGridSizer57->Add(Choice_Ripple_Movement, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer57->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_Ripple_Movement = new wxBitmapButton(this, ID_BITMAPBUTTON13, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
	BitmapButton_Ripple_Movement->SetDefault();
	BitmapButton_Ripple_Movement->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer57->Add(BitmapButton_Ripple_Movement, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText72 = new wxStaticText(this, ID_STATICTEXT74, _("Thickness"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT74"));
	FlexGridSizer57->Add(StaticText72, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Ripple_Thickness = new wxSlider(this, ID_SLIDER_Ripple_Thickness, 3, 1, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Ripple_Thickness"));
	FlexGridSizer57->Add(Slider_Ripple_Thickness, 1, wxALL|wxEXPAND, 2);
	TextCtrl33 = new wxTextCtrl(this, IDD_TEXTCTRL_Ripple_Thickness, _("3"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), 0, wxDefaultValidator, _T("IDD_TEXTCTRL_Ripple_Thickness"));
	TextCtrl33->SetMaxLength(3);
	FlexGridSizer57->Add(TextCtrl33, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton_RippleThickness = new wxBitmapButton(this, ID_BITMAPBUTTON14, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON14"));
	BitmapButton_RippleThickness->SetDefault();
	BitmapButton_RippleThickness->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer57->Add(BitmapButton_RippleThickness, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText176 = new wxStaticText(this, wxID_ANY, _("Cycle Count"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer57->Add(StaticText176, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider12 = new wxSlider(this, IDD_SLIDER_Ripple_Cycles, 10, 0, 300, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Ripple_Cycles"));
	FlexGridSizer57->Add(Slider12, 1, wxALL|wxEXPAND, 2);
	TextCtrl34 = new wxTextCtrl(this, ID_TEXTCTRL_Ripple_Cycles, _("1.0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Ripple_Cycles"));
	TextCtrl34->SetMaxLength(4);
	FlexGridSizer57->Add(TextCtrl34, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer57->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer60 = new wxFlexGridSizer(0, 4, 0, 0);
	CheckBox_Ripple3D = new wxCheckBox(this, ID_CHECKBOX_Ripple3D, _("3D"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Ripple3D"));
	CheckBox_Ripple3D->SetValue(false);
	FlexGridSizer60->Add(CheckBox_Ripple3D, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton_Ripple3D = new wxBitmapButton(this, ID_BITMAPBUTTON17, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON17"));
	BitmapButton_Ripple3D->SetDefault();
	BitmapButton_Ripple3D->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer60->Add(BitmapButton_Ripple3D, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	FlexGridSizer57->Add(FlexGridSizer60, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer57);
	FlexGridSizer57->Fit(this);
	FlexGridSizer57->SetSizeHints(this);

	Connect(ID_BITMAPBUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RipplePanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RipplePanel::OnLockButtonClick);
	Connect(ID_SLIDER_Ripple_Thickness,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&RipplePanel::UpdateLinkedTextCtrl);
	Connect(IDD_TEXTCTRL_Ripple_Thickness,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&RipplePanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RipplePanel::OnLockButtonClick);
	Connect(IDD_SLIDER_Ripple_Cycles,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&RipplePanel::UpdateLinkedTextCtrlFloat);
	Connect(ID_TEXTCTRL_Ripple_Cycles,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&RipplePanel::UpdateLinkedSliderFloat);
	Connect(ID_BITMAPBUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RipplePanel::OnLockButtonClick);
	//*)
    SetName("ID_PANEL_RIPPLE");
}

RipplePanel::~RipplePanel()
{
	//(*Destroy(RipplePanel)
	//*)
}

PANEL_EVENT_HANDLERS(RipplePanel)