#include "PinwheelPanel.h"
#include "../../include/padlock16x16-blue.xpm"
#include "EffectPanelUtils.h"

//(*InternalHeaders(PinwheelPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/bitmap.h>
#include <wx/slider.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(PinwheelPanel)
const long PinwheelPanel::ID_STATICTEXT65 = wxNewId();
const long PinwheelPanel::ID_SLIDER_Pinwheel_Arms = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_Pinwheel_Arms = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON11 = wxNewId();
const long PinwheelPanel::ID_STATICTEXT98 = wxNewId();
const long PinwheelPanel::ID_SLIDER_Pinwheel_ArmSize = wxNewId();
const long PinwheelPanel::ID_VALUECURVE_Pinwheel_ArmSize = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_Pinwheel_ArmSize = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON16 = wxNewId();
const long PinwheelPanel::ID_STATICTEXT76 = wxNewId();
const long PinwheelPanel::ID_SLIDER_Pinwheel_Twist = wxNewId();
const long PinwheelPanel::ID_VALUECURVE_Pinwheel_Twist = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_Pinwheel_Twist = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON12 = wxNewId();
const long PinwheelPanel::ID_STATICTEXT77 = wxNewId();
const long PinwheelPanel::ID_SLIDER_Pinwheel_Thickness = wxNewId();
const long PinwheelPanel::ID_VALUECURVE_Pinwheel_Thickness = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_Pinwheel_Thickness = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON18 = wxNewId();
const long PinwheelPanel::ID_SLIDER_Pinwheel_Speed = wxNewId();
const long PinwheelPanel::ID_VALUECURVE_Pinwheel_Speed = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_Pinwheel_Speed = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON26 = wxNewId();
const long PinwheelPanel::ID_STATICTEXT78 = wxNewId();
const long PinwheelPanel::ID_CHECKBOX_Pinwheel_Rotation = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON19 = wxNewId();
const long PinwheelPanel::ID_STATICTEXT82 = wxNewId();
const long PinwheelPanel::ID_CHOICE_Pinwheel_3D = wxNewId();
const long PinwheelPanel::ID_BITMAPBUTTON_Pinwheel3D = wxNewId();
const long PinwheelPanel::ID_STATICTEXT85 = wxNewId();
const long PinwheelPanel::ID_SLIDER_PinwheelXC = wxNewId();
const long PinwheelPanel::ID_VALUECURVE_PinwheelXC = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_PinwheelXC = wxNewId();
const long PinwheelPanel::ID_STATICTEXT83 = wxNewId();
const long PinwheelPanel::ID_VALUECURVE_PinwheelYC = wxNewId();
const long PinwheelPanel::IDD_TEXTCTRL_PinwheelYC = wxNewId();
const long PinwheelPanel::ID_SLIDER_PinwheelYC = wxNewId();
//*)

BEGIN_EVENT_TABLE(PinwheelPanel,wxPanel)
	//(*EventTable(PinwheelPanel)
	//*)
END_EVENT_TABLE()

PinwheelPanel::PinwheelPanel(wxWindow* parent)
{
	//(*Initialize(PinwheelPanel)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer59;
	wxTextCtrl* TextCtrl69;
	wxFlexGridSizer* FlexGridSizer63;
	wxTextCtrl* TextCtrl70;
	wxTextCtrl* TextCtrl68;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxTextCtrl* TextCtrl64;
	wxFlexGridSizer* FlexGridSizer62;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer55;
	wxTextCtrl* TextCtrl66;
	wxFlexGridSizer* FlexGridSizer61;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;
	wxTextCtrl* TextCtrl67;
	wxFlexGridSizer* FlexGridSizer64;
	wxStaticText* StaticText184;
	wxFlexGridSizer* FlexGridSizer68;
	wxFlexGridSizer* FlexGridSizer128;
	wxTextCtrl* TextCtrl65;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer55 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer55->AddGrowableCol(0);
	FlexGridSizer55->AddGrowableRow(2);
	FlexGridSizer128 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer128->AddGrowableCol(1);
	StaticText63 = new wxStaticText(this, ID_STATICTEXT65, _("#Arms"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
	FlexGridSizer128->Add(StaticText63, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Pinwheel_Arms = new wxSlider(this, ID_SLIDER_Pinwheel_Arms, 3, 1, 20, wxDefaultPosition, wxSize(80,20), 0, wxDefaultValidator, _T("ID_SLIDER_Pinwheel_Arms"));
	FlexGridSizer128->Add(Slider_Pinwheel_Arms, 1, wxALL|wxEXPAND, 2);
	TextCtrl64 = new wxTextCtrl(this, IDD_TEXTCTRL_Pinwheel_Arms, _("3"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Pinwheel_Arms"));
	TextCtrl64->SetMaxLength(3);
	FlexGridSizer128->Add(TextCtrl64, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton_PinwheelNumberArms = new wxBitmapButton(this, ID_BITMAPBUTTON11, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
	BitmapButton_PinwheelNumberArms->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer128->Add(BitmapButton_PinwheelNumberArms, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText84 = new wxStaticText(this, ID_STATICTEXT98, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT98"));
	FlexGridSizer128->Add(StaticText84, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	Slider_Pinwheel_ArmSize = new wxSlider(this, ID_SLIDER_Pinwheel_ArmSize, 100, 0, 400, wxDefaultPosition, wxSize(80,20), 0, wxDefaultValidator, _T("ID_SLIDER_Pinwheel_ArmSize"));
	FlexGridSizer1->Add(Slider_Pinwheel_ArmSize, 1, wxALL|wxEXPAND, 2);
	BitmapButton_Pinwheel_ArmSizeVC = new ValueCurveButton(this, ID_VALUECURVE_Pinwheel_ArmSize, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Pinwheel_ArmSize"));
	FlexGridSizer1->Add(BitmapButton_Pinwheel_ArmSizeVC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer128->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
	TextCtrl65 = new wxTextCtrl(this, IDD_TEXTCTRL_Pinwheel_ArmSize, _("100"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Pinwheel_ArmSize"));
	TextCtrl65->SetMaxLength(3);
	FlexGridSizer128->Add(TextCtrl65, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton_Pinwheel_ArmSize = new wxBitmapButton(this, ID_BITMAPBUTTON16, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON16"));
	BitmapButton_Pinwheel_ArmSize->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer128->Add(BitmapButton_Pinwheel_ArmSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText74 = new wxStaticText(this, ID_STATICTEXT76, _("Twist"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT76"));
	FlexGridSizer128->Add(StaticText74, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	Slider_Pinwheel_Twist = new wxSlider(this, ID_SLIDER_Pinwheel_Twist, 0, -360, 360, wxDefaultPosition, wxSize(80,20), 0, wxDefaultValidator, _T("ID_SLIDER_Pinwheel_Twist"));
	FlexGridSizer2->Add(Slider_Pinwheel_Twist, 1, wxALL|wxEXPAND, 2);
	BitmapButton_Pinwheel_TwistVC = new ValueCurveButton(this, ID_VALUECURVE_Pinwheel_Twist, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Pinwheel_Twist"));
	FlexGridSizer2->Add(BitmapButton_Pinwheel_TwistVC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer128->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
	TextCtrl66 = new wxTextCtrl(this, IDD_TEXTCTRL_Pinwheel_Twist, _("0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Pinwheel_Twist"));
	TextCtrl66->SetMaxLength(4);
	FlexGridSizer128->Add(TextCtrl66, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton_PinwheelTwist = new wxBitmapButton(this, ID_BITMAPBUTTON12, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
	BitmapButton_PinwheelTwist->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer128->Add(BitmapButton_PinwheelTwist, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText75 = new wxStaticText(this, ID_STATICTEXT77, _("Thick"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT77"));
	FlexGridSizer128->Add(StaticText75, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	Slider_Pinwheel_Thickness = new wxSlider(this, ID_SLIDER_Pinwheel_Thickness, 0, 0, 100, wxDefaultPosition, wxSize(80,20), 0, wxDefaultValidator, _T("ID_SLIDER_Pinwheel_Thickness"));
	FlexGridSizer3->Add(Slider_Pinwheel_Thickness, 1, wxALL|wxEXPAND, 2);
	BitmapButton_Pinwheel_ThicknessVC = new ValueCurveButton(this, ID_VALUECURVE_Pinwheel_Thickness, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Pinwheel_Thickness"));
	FlexGridSizer3->Add(BitmapButton_Pinwheel_ThicknessVC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer128->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
	TextCtrl67 = new wxTextCtrl(this, IDD_TEXTCTRL_Pinwheel_Thickness, _("0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Pinwheel_Thickness"));
	TextCtrl67->SetMaxLength(3);
	FlexGridSizer128->Add(TextCtrl67, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton_PinwheelThickness = new wxBitmapButton(this, ID_BITMAPBUTTON18, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON18"));
	BitmapButton_PinwheelThickness->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer128->Add(BitmapButton_PinwheelThickness, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText184 = new wxStaticText(this, wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer128->Add(StaticText184, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	Slider_Pinwheel_Speed = new wxSlider(this, ID_SLIDER_Pinwheel_Speed, 10, 0, 50, wxDefaultPosition, wxSize(80,20), 0, wxDefaultValidator, _T("ID_SLIDER_Pinwheel_Speed"));
	FlexGridSizer4->Add(Slider_Pinwheel_Speed, 1, wxALL|wxEXPAND, 2);
	BitmapButton_Pinwheel_SpeedVC = new ValueCurveButton(this, ID_VALUECURVE_Pinwheel_Speed, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Pinwheel_Speed"));
	FlexGridSizer4->Add(BitmapButton_Pinwheel_SpeedVC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer128->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
	TextCtrl70 = new wxTextCtrl(this, IDD_TEXTCTRL_Pinwheel_Speed, _("10"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Pinwheel_Speed"));
	TextCtrl70->SetMaxLength(3);
	FlexGridSizer128->Add(TextCtrl70, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BitmapButton7 = new wxBitmapButton(this, ID_BITMAPBUTTON26, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON26"));
	BitmapButton7->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer128->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer55->Add(FlexGridSizer128, 1, wxALL|wxEXPAND, 0);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	FlexGridSizer59 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText76 = new wxStaticText(this, ID_STATICTEXT78, _("Rotation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT78"));
	FlexGridSizer59->Add(StaticText76, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_Pinwheel_Rotation = new wxCheckBox(this, ID_CHECKBOX_Pinwheel_Rotation, _("CCW"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Pinwheel_Rotation"));
	CheckBox_Pinwheel_Rotation->SetValue(true);
	FlexGridSizer59->Add(CheckBox_Pinwheel_Rotation, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_PinwheelRotation = new wxBitmapButton(this, ID_BITMAPBUTTON19, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON19"));
	BitmapButton_PinwheelRotation->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer59->Add(BitmapButton_PinwheelRotation, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer59, 1, wxALL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer61 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText77 = new wxStaticText(this, ID_STATICTEXT82, _("3D"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT82"));
	FlexGridSizer61->Add(StaticText77, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Pinwheel_3D = new wxChoice(this, ID_CHOICE_Pinwheel_3D, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Pinwheel_3D"));
	Choice_Pinwheel_3D->SetSelection( Choice_Pinwheel_3D->Append(_("None")) );
	Choice_Pinwheel_3D->Append(_("3D"));
	Choice_Pinwheel_3D->Append(_("3D Inverted"));
	FlexGridSizer61->Add(Choice_Pinwheel_3D, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_Pinwheel3D = new wxBitmapButton(this, ID_BITMAPBUTTON_Pinwheel3D, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_Pinwheel3D"));
	BitmapButton_Pinwheel3D->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer61->Add(BitmapButton_Pinwheel3D, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer61, 1, wxALL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer55->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer63 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer63->AddGrowableCol(0);
	FlexGridSizer63->AddGrowableRow(0);
	FlexGridSizer62 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer62->AddGrowableCol(1);
	StaticText82 = new wxStaticText(this, ID_STATICTEXT85, _("X-axis Center"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT85"));
	FlexGridSizer62->Add(StaticText82, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_PinwheelXC = new wxSlider(this, ID_SLIDER_PinwheelXC, 0, -100, 100, wxDefaultPosition, wxSize(80,20), 0, wxDefaultValidator, _T("ID_SLIDER_PinwheelXC"));
	FlexGridSizer62->Add(Slider_PinwheelXC, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer62->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
	BitmapButton_PinwheelXCVC = new ValueCurveButton(this, ID_VALUECURVE_PinwheelXC, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_PinwheelXC"));
	FlexGridSizer5->Add(BitmapButton_PinwheelXCVC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	TextCtrl68 = new wxTextCtrl(this, IDD_TEXTCTRL_PinwheelXC, _("0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_PinwheelXC"));
	TextCtrl68->SetMaxLength(4);
	FlexGridSizer5->Add(TextCtrl68, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer62->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer63->Add(FlexGridSizer62, 1, wxALL|wxEXPAND, 0);
	FlexGridSizer68 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer68->AddGrowableRow(0);
	FlexGridSizer64 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticText81 = new wxStaticText(this, ID_STATICTEXT83, _("Y-axis center"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT83"));
	FlexGridSizer64->Add(StaticText81, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
	BitmapButton_PinwheelYCVC = new ValueCurveButton(this, ID_VALUECURVE_PinwheelYC, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_PinwheelYC"));
	FlexGridSizer6->Add(BitmapButton_PinwheelYCVC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	TextCtrl69 = new wxTextCtrl(this, IDD_TEXTCTRL_PinwheelYC, _("0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_PinwheelYC"));
	TextCtrl69->SetMaxLength(4);
	FlexGridSizer6->Add(TextCtrl69, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer64->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer68->Add(FlexGridSizer64, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	Slider_PinwheelYC = new wxSlider(this, ID_SLIDER_PinwheelYC, 0, -100, 100, wxDefaultPosition, wxSize(20,80), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER_PinwheelYC"));
	FlexGridSizer68->Add(Slider_PinwheelYC, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer63->Add(FlexGridSizer68, 1, wxALL|wxEXPAND, 0);
	FlexGridSizer55->Add(FlexGridSizer63, 1, wxALL|wxEXPAND, 0);
	SetSizer(FlexGridSizer55);
	FlexGridSizer55->Fit(this);
	FlexGridSizer55->SetSizeHints(this);

	Connect(ID_SLIDER_Pinwheel_Arms,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrl);
	Connect(IDD_TEXTCTRL_Pinwheel_Arms,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_SLIDER_Pinwheel_ArmSize,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Pinwheel_ArmSize,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnVCButtonClick);
	Connect(IDD_TEXTCTRL_Pinwheel_ArmSize,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_SLIDER_Pinwheel_Twist,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Pinwheel_Twist,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnVCButtonClick);
	Connect(IDD_TEXTCTRL_Pinwheel_Twist,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_SLIDER_Pinwheel_Thickness,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Pinwheel_Thickness,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnVCButtonClick);
	Connect(IDD_TEXTCTRL_Pinwheel_Thickness,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_SLIDER_Pinwheel_Speed,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Pinwheel_Speed,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnVCButtonClick);
	Connect(IDD_TEXTCTRL_Pinwheel_Speed,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON26,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON_Pinwheel3D,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnLockButtonClick);
	Connect(ID_SLIDER_PinwheelXC,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_PinwheelXC,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnVCButtonClick);
	Connect(IDD_TEXTCTRL_PinwheelXC,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_VALUECURVE_PinwheelYC,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PinwheelPanel::OnVCButtonClick);
	Connect(IDD_TEXTCTRL_PinwheelYC,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedSlider);
	Connect(ID_SLIDER_PinwheelYC,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&PinwheelPanel::UpdateLinkedTextCtrlVC);
	//*)
    SetName("ID_PANEL_PINWHEEL");

    Connect(wxID_ANY, EVT_VC_CHANGED, (wxObjectEventFunction)&PinwheelPanel::OnVCChanged, 0, this);

    BitmapButton_PinwheelXCVC->GetValue()->SetLimits(-100, 100);
    BitmapButton_PinwheelYCVC->GetValue()->SetLimits(-100, 100);
    BitmapButton_Pinwheel_ArmSizeVC->GetValue()->SetLimits(0, 400);
    BitmapButton_Pinwheel_SpeedVC->GetValue()->SetLimits(0, 50);
    BitmapButton_Pinwheel_ThicknessVC->GetValue()->SetLimits(0, 100);
    BitmapButton_Pinwheel_TwistVC->GetValue()->SetLimits(-360, 360);
}

PinwheelPanel::~PinwheelPanel()
{
	//(*Destroy(PinwheelPanel)
	//*)
}

PANEL_EVENT_HANDLERS(PinwheelPanel)
