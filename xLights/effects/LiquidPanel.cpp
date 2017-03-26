#include "LiquidPanel.h"
#include "EffectPanelUtils.h"

//(*InternalHeaders(LiquidPanel)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/bitmap.h>
#include <wx/slider.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/valnum.h>

//(*IdInit(LiquidPanel)
const long LiquidPanel::ID_CHECKBOX_TopBarrier = wxNewId();
const long LiquidPanel::ID_CHECKBOX_BottomBarrier = wxNewId();
const long LiquidPanel::ID_CHECKBOX_LeftBarrier = wxNewId();
const long LiquidPanel::ID_CHECKBOX_RightBarrier = wxNewId();
const long LiquidPanel::ID_CHECKBOX_HoldColor = wxNewId();
const long LiquidPanel::ID_CHECKBOX_MixColors = wxNewId();
const long LiquidPanel::ID_STATICTEXT7 = wxNewId();
const long LiquidPanel::ID_CHOICE_ParticleType = wxNewId();
const long LiquidPanel::ID_STATICTEXT1 = wxNewId();
const long LiquidPanel::IDD_SLIDER_LifeTime = wxNewId();
const long LiquidPanel::ID_VALUECURVE_LifeTime = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_LifeTime = wxNewId();
const long LiquidPanel::ID_STATICTEXT8 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Size = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Size = wxNewId();
const long LiquidPanel::ID_STATICTEXT9 = wxNewId();
const long LiquidPanel::IDD_SLIDER_WarmUpFrames = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_WarmUpFrames = wxNewId();
const long LiquidPanel::ID_STATICTEXT2 = wxNewId();
const long LiquidPanel::IDD_SLIDER_X1 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_X1 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_X1 = wxNewId();
const long LiquidPanel::ID_STATICTEXT3 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Y1 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Y1 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Y1 = wxNewId();
const long LiquidPanel::ID_STATICTEXT4 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Direction1 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Direction1 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Direction1 = wxNewId();
const long LiquidPanel::ID_STATICTEXT5 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Velocity1 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Velocity1 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Velocity1 = wxNewId();
const long LiquidPanel::ID_STATICTEXT6 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Flow1 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Flow1 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Flow1 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_FlowMusic1 = wxNewId();
const long LiquidPanel::ID_PANEL1 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_Enabled2 = wxNewId();
const long LiquidPanel::ID_STATICTEXT22 = wxNewId();
const long LiquidPanel::IDD_SLIDER_X2 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_X2 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_X2 = wxNewId();
const long LiquidPanel::ID_STATICTEXT23 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Y2 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Y2 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Y2 = wxNewId();
const long LiquidPanel::ID_STATICTEXT24 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Direction2 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Direction2 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Direction2 = wxNewId();
const long LiquidPanel::ID_STATICTEXT25 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Velocity2 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Velocity2 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Velocity2 = wxNewId();
const long LiquidPanel::ID_STATICTEXT26 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Flow2 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Flow2 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Flow2 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_FlowMusic2 = wxNewId();
const long LiquidPanel::ID_PANEL2 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_Enabled3 = wxNewId();
const long LiquidPanel::ID_STATICTEXT32 = wxNewId();
const long LiquidPanel::IDD_SLIDER_X3 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_X3 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_X3 = wxNewId();
const long LiquidPanel::ID_STATICTEXT33 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Y3 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Y3 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Y3 = wxNewId();
const long LiquidPanel::ID_STATICTEXT34 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Direction3 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Direction3 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Direction3 = wxNewId();
const long LiquidPanel::ID_STATICTEXT35 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Velocity3 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Velocity3 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Velocity3 = wxNewId();
const long LiquidPanel::ID_STATICTEXT36 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Flow3 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Flow3 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Flow3 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_FlowMusic3 = wxNewId();
const long LiquidPanel::ID_PANEL3 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_Enabled4 = wxNewId();
const long LiquidPanel::ID_STATICTEXT42 = wxNewId();
const long LiquidPanel::IDD_SLIDER_X4 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_X4 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_X4 = wxNewId();
const long LiquidPanel::ID_STATICTEXT43 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Y4 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Y4 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Y4 = wxNewId();
const long LiquidPanel::ID_STATICTEXT44 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Direction4 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Direction4 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Direction4 = wxNewId();
const long LiquidPanel::ID_STATICTEXT45 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Velocity4 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Velocity4 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Velocity4 = wxNewId();
const long LiquidPanel::ID_STATICTEXT46 = wxNewId();
const long LiquidPanel::IDD_SLIDER_Flow4 = wxNewId();
const long LiquidPanel::ID_VALUECURVE_Flow4 = wxNewId();
const long LiquidPanel::ID_TEXTCTRL_Flow4 = wxNewId();
const long LiquidPanel::ID_CHECKBOX_FlowMusic4 = wxNewId();
const long LiquidPanel::ID_PANEL4 = wxNewId();
const long LiquidPanel::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LiquidPanel,wxPanel)
	//(*EventTable(LiquidPanel)
	//*)
END_EVENT_TABLE()

LiquidPanel::LiquidPanel(wxWindow* parent)
{
	//(*Initialize(LiquidPanel)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer77;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer12;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer77 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer77->AddGrowableCol(0);
	FlexGridSizer77->AddGrowableRow(2);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	CheckBox_TopBarrier = new wxCheckBox(this, ID_CHECKBOX_TopBarrier, _("Top Barrier"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_TopBarrier"));
	CheckBox_TopBarrier->SetValue(false);
	FlexGridSizer1->Add(CheckBox_TopBarrier, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_BottomBarrier = new wxCheckBox(this, ID_CHECKBOX_BottomBarrier, _("Bottom Barrier"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_BottomBarrier"));
	CheckBox_BottomBarrier->SetValue(true);
	FlexGridSizer1->Add(CheckBox_BottomBarrier, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_LeftBarrier = new wxCheckBox(this, ID_CHECKBOX_LeftBarrier, _("Left Barrier"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_LeftBarrier"));
	CheckBox_LeftBarrier->SetValue(false);
	FlexGridSizer1->Add(CheckBox_LeftBarrier, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_RightBarrier = new wxCheckBox(this, ID_CHECKBOX_RightBarrier, _("Right Barrier"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_RightBarrier"));
	CheckBox_RightBarrier->SetValue(false);
	FlexGridSizer1->Add(CheckBox_RightBarrier, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer77->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
	CheckBox_HoldColor = new wxCheckBox(this, ID_CHECKBOX_HoldColor, _("Hold Particle Color"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_HoldColor"));
	CheckBox_HoldColor->SetValue(true);
	FlexGridSizer77->Add(CheckBox_HoldColor, 1, wxALL|wxEXPAND, 5);
	CheckBox_MixColors = new wxCheckBox(this, ID_CHECKBOX_MixColors, _("Mix Colors"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_MixColors"));
	CheckBox_MixColors->SetValue(false);
	FlexGridSizer77->Add(CheckBox_MixColors, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer11 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer11->AddGrowableCol(1);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer11->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice_ParticleType = new wxChoice(this, ID_CHOICE_ParticleType, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_ParticleType"));
	Choice_ParticleType->Append(_("Powder"));
	Choice_ParticleType->SetSelection( Choice_ParticleType->Append(_("Elastic")) );
	Choice_ParticleType->Append(_("Spring"));
	Choice_ParticleType->Append(_("Tensile"));
	Choice_ParticleType->Append(_("Viscous"));
	Choice_ParticleType->Append(_("Static Pressure"));
	Choice_ParticleType->Append(_("Water"));
	Choice_ParticleType->Append(_("Reactive"));
	Choice_ParticleType->Append(_("Repulsive"));
	FlexGridSizer11->Add(Choice_ParticleType, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer77->Add(FlexGridSizer11, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer2->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Lifetime"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_LifeTime = new wxSlider(this, IDD_SLIDER_LifeTime, 1000, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_LifeTime"));
	FlexGridSizer2->Add(Slider_LifeTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_LifeTime = new ValueCurveButton(this, ID_VALUECURVE_LifeTime, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_LifeTime"));
	FlexGridSizer2->Add(BitmapButton_LifeTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_LifeTime = new wxTextCtrl(this, ID_TEXTCTRL_LifeTime, _("1000"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_LifeTime"));
	TextCtrl_LifeTime->SetMaxLength(4);
	FlexGridSizer2->Add(TextCtrl_LifeTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer77->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer12 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer12->AddGrowableCol(1);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer12->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Size = new wxSlider(this, IDD_SLIDER_Size, 500, 1, 10000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Size"));
	FlexGridSizer12->Add(Slider_Size, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Size = new wxTextCtrl(this, ID_TEXTCTRL_Size, _("500"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Size"));
	TextCtrl_Size->SetMaxLength(5);
	FlexGridSizer12->Add(TextCtrl_Size, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Warm Up Frames"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer12->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider_WarmUpFrames = new wxSlider(this, IDD_SLIDER_WarmUpFrames, 0, 0, 500, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_WarmUpFrames"));
	FlexGridSizer12->Add(Slider_WarmUpFrames, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_WarmUpFrames = new wxTextCtrl(this, ID_TEXTCTRL_WarmUpFrames, _("0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_WarmUpFrames"));
	TextCtrl_WarmUpFrames->SetMaxLength(5);
	FlexGridSizer12->Add(TextCtrl_WarmUpFrames, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer77->Add(FlexGridSizer12, 1, wxALL|wxEXPAND, 5);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxPoint(115,49), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer6->AddGrowableCol(0);
	FlexGridSizer7 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer7->AddGrowableCol(1);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer7->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_X1 = new wxSlider(Panel1, IDD_SLIDER_X1, 50, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_X1"));
	FlexGridSizer7->Add(Slider_X1, 1, wxALL|wxEXPAND, 5);
	BitmapButton_X1 = new ValueCurveButton(Panel1, ID_VALUECURVE_X1, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_X1"));
	FlexGridSizer7->Add(BitmapButton_X1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_X1 = new wxTextCtrl(Panel1, ID_TEXTCTRL_X1, _("50"), wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_X1"));
	TextCtrl_X1->SetMaxLength(4);
	FlexGridSizer7->Add(TextCtrl_X1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer7->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Y1 = new wxSlider(Panel1, IDD_SLIDER_Y1, 100, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Y1"));
	FlexGridSizer7->Add(Slider_Y1, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Y1 = new ValueCurveButton(Panel1, ID_VALUECURVE_Y1, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Y1"));
	FlexGridSizer7->Add(BitmapButton_Y1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Y1 = new wxTextCtrl(Panel1, ID_TEXTCTRL_Y1, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Y1"));
	TextCtrl_Y1->SetMaxLength(4);
	FlexGridSizer7->Add(TextCtrl_Y1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Direction"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer7->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Direction1 = new wxSlider(Panel1, IDD_SLIDER_Direction1, 270, 0, 360, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Direction1"));
	FlexGridSizer7->Add(Slider_Direction1, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Direction1 = new ValueCurveButton(Panel1, ID_VALUECURVE_Direction1, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Direction1"));
	FlexGridSizer7->Add(BitmapButton_Direction1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Direction1 = new wxTextCtrl(Panel1, ID_TEXTCTRL_Direction1, _("270"), wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Direction1"));
	TextCtrl_Direction1->SetMaxLength(4);
	FlexGridSizer7->Add(TextCtrl_Direction1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Velocity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer7->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Velocity1 = new wxSlider(Panel1, IDD_SLIDER_Velocity1, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Velocity1"));
	FlexGridSizer7->Add(Slider_Velocity1, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Velocity1 = new ValueCurveButton(Panel1, ID_VALUECURVE_Velocity1, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Velocity1"));
	FlexGridSizer7->Add(BitmapButton_Velocity1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Velocity1 = new wxTextCtrl(Panel1, ID_TEXTCTRL_Velocity1, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Velocity1"));
	TextCtrl_Velocity1->SetMaxLength(4);
	FlexGridSizer7->Add(TextCtrl_Velocity1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Flow"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer7->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Flow1 = new wxSlider(Panel1, IDD_SLIDER_Flow1, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Flow1"));
	FlexGridSizer7->Add(Slider_Flow1, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Flow1 = new ValueCurveButton(Panel1, ID_VALUECURVE_Flow1, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Flow1"));
	FlexGridSizer7->Add(BitmapButton_Flow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Flow1 = new wxTextCtrl(Panel1, ID_TEXTCTRL_Flow1, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Flow1"));
	TextCtrl_Flow1->SetMaxLength(4);
	FlexGridSizer7->Add(TextCtrl_Flow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_FlowMusic1 = new wxCheckBox(Panel1, ID_CHECKBOX_FlowMusic1, _("Flow Matches Music"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_FlowMusic1"));
	CheckBox_FlowMusic1->SetValue(false);
	FlexGridSizer7->Add(CheckBox_FlowMusic1, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer7, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(FlexGridSizer6);
	FlexGridSizer6->Fit(Panel1);
	FlexGridSizer6->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(34,17), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	CheckBox_Enabled2 = new wxCheckBox(Panel2, ID_CHECKBOX_Enabled2, _("Enabled"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Enabled2"));
	CheckBox_Enabled2->SetValue(false);
	FlexGridSizer3->Add(CheckBox_Enabled2, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer8 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer8->AddGrowableCol(1);
	StaticText22 = new wxStaticText(Panel2, ID_STATICTEXT22, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	FlexGridSizer8->Add(StaticText22, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_X2 = new wxSlider(Panel2, IDD_SLIDER_X2, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_X2"));
	FlexGridSizer8->Add(Slider_X2, 1, wxALL|wxEXPAND, 5);
	BitmapButton_X2 = new ValueCurveButton(Panel2, ID_VALUECURVE_X2, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_X2"));
	FlexGridSizer8->Add(BitmapButton_X2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_X2 = new wxTextCtrl(Panel2, ID_TEXTCTRL_X2, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_X2"));
	TextCtrl_X2->SetMaxLength(4);
	FlexGridSizer8->Add(TextCtrl_X2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText23 = new wxStaticText(Panel2, ID_STATICTEXT23, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	FlexGridSizer8->Add(StaticText23, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Y2 = new wxSlider(Panel2, IDD_SLIDER_Y2, 50, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Y2"));
	FlexGridSizer8->Add(Slider_Y2, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Y2 = new ValueCurveButton(Panel2, ID_VALUECURVE_Y2, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Y2"));
	FlexGridSizer8->Add(BitmapButton_Y2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Y2 = new wxTextCtrl(Panel2, ID_TEXTCTRL_Y2, _("50"), wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Y2"));
	TextCtrl_Y2->SetMaxLength(4);
	FlexGridSizer8->Add(TextCtrl_Y2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText24 = new wxStaticText(Panel2, ID_STATICTEXT24, _("Direction"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	FlexGridSizer8->Add(StaticText24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Direction2 = new wxSlider(Panel2, IDD_SLIDER_Direction2, 0, 0, 360, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Direction2"));
	FlexGridSizer8->Add(Slider_Direction2, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Direction2 = new ValueCurveButton(Panel2, ID_VALUECURVE_Direction2, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Direction2"));
	FlexGridSizer8->Add(BitmapButton_Direction2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Direction2 = new wxTextCtrl(Panel2, ID_TEXTCTRL_Direction2, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Direction2"));
	TextCtrl_Direction2->SetMaxLength(4);
	FlexGridSizer8->Add(TextCtrl_Direction2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText25 = new wxStaticText(Panel2, ID_STATICTEXT25, _("Velocity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	FlexGridSizer8->Add(StaticText25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Velocity2 = new wxSlider(Panel2, IDD_SLIDER_Velocity2, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Velocity2"));
	FlexGridSizer8->Add(Slider_Velocity2, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Velocity2 = new ValueCurveButton(Panel2, ID_VALUECURVE_Velocity2, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Velocity2"));
	FlexGridSizer8->Add(BitmapButton_Velocity2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Velocity2 = new wxTextCtrl(Panel2, ID_TEXTCTRL_Velocity2, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Velocity2"));
	TextCtrl_Velocity2->SetMaxLength(4);
	FlexGridSizer8->Add(TextCtrl_Velocity2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(Panel2, ID_STATICTEXT26, _("Flow"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	FlexGridSizer8->Add(StaticText26, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Flow2 = new wxSlider(Panel2, IDD_SLIDER_Flow2, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Flow2"));
	FlexGridSizer8->Add(Slider_Flow2, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Flow2 = new ValueCurveButton(Panel2, ID_VALUECURVE_Flow2, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Flow2"));
	FlexGridSizer8->Add(BitmapButton_Flow2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Flow2 = new wxTextCtrl(Panel2, ID_TEXTCTRL_Flow2, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Flow2"));
	TextCtrl_Flow2->SetMaxLength(4);
	FlexGridSizer8->Add(TextCtrl_Flow2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_FlowMusic2 = new wxCheckBox(Panel2, ID_CHECKBOX_FlowMusic2, _("Flow Matches Music"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_FlowMusic2"));
	CheckBox_FlowMusic2->SetValue(false);
	FlexGridSizer8->Add(CheckBox_FlowMusic2, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer8, 1, wxALL|wxEXPAND, 5);
	Panel2->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel2);
	FlexGridSizer3->SetSizeHints(Panel2);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(89,6), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	CheckBox_Enabled3 = new wxCheckBox(Panel3, ID_CHECKBOX_Enabled3, _("Enabled"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Enabled3"));
	CheckBox_Enabled3->SetValue(false);
	FlexGridSizer4->Add(CheckBox_Enabled3, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer9 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText32 = new wxStaticText(Panel3, ID_STATICTEXT32, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
	FlexGridSizer9->Add(StaticText32, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_X3 = new wxSlider(Panel3, IDD_SLIDER_X3, 50, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_X3"));
	FlexGridSizer9->Add(Slider_X3, 1, wxALL|wxEXPAND, 5);
	BitmapButton_X3 = new ValueCurveButton(Panel3, ID_VALUECURVE_X3, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_X3"));
	FlexGridSizer9->Add(BitmapButton_X3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_X3 = new wxTextCtrl(Panel3, ID_TEXTCTRL_X3, _("50"), wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_X3"));
	TextCtrl_X3->SetMaxLength(4);
	FlexGridSizer9->Add(TextCtrl_X3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText33 = new wxStaticText(Panel3, ID_STATICTEXT33, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
	FlexGridSizer9->Add(StaticText33, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Y3 = new wxSlider(Panel3, IDD_SLIDER_Y3, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Y3"));
	FlexGridSizer9->Add(Slider_Y3, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Y3 = new ValueCurveButton(Panel3, ID_VALUECURVE_Y3, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Y3"));
	FlexGridSizer9->Add(BitmapButton_Y3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Y3 = new wxTextCtrl(Panel3, ID_TEXTCTRL_Y3, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Y3"));
	TextCtrl_Y3->SetMaxLength(4);
	FlexGridSizer9->Add(TextCtrl_Y3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText34 = new wxStaticText(Panel3, ID_STATICTEXT34, _("Direction"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
	FlexGridSizer9->Add(StaticText34, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Direction3 = new wxSlider(Panel3, IDD_SLIDER_Direction3, 90, 0, 360, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Direction3"));
	FlexGridSizer9->Add(Slider_Direction3, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Direction3 = new ValueCurveButton(Panel3, ID_VALUECURVE_Direction3, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Direction3"));
	FlexGridSizer9->Add(BitmapButton_Direction3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Direction3 = new wxTextCtrl(Panel3, ID_TEXTCTRL_Direction3, _("90"), wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Direction3"));
	TextCtrl_Direction3->SetMaxLength(4);
	FlexGridSizer9->Add(TextCtrl_Direction3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText35 = new wxStaticText(Panel3, ID_STATICTEXT35, _("Velocity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
	FlexGridSizer9->Add(StaticText35, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Velocity3 = new wxSlider(Panel3, IDD_SLIDER_Velocity3, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Velocity3"));
	FlexGridSizer9->Add(Slider_Velocity3, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Velocity3 = new ValueCurveButton(Panel3, ID_VALUECURVE_Velocity3, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Velocity3"));
	FlexGridSizer9->Add(BitmapButton_Velocity3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Velocity3 = new wxTextCtrl(Panel3, ID_TEXTCTRL_Velocity3, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Velocity3"));
	TextCtrl_Velocity3->SetMaxLength(4);
	FlexGridSizer9->Add(TextCtrl_Velocity3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText36 = new wxStaticText(Panel3, ID_STATICTEXT36, _("Flow"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
	FlexGridSizer9->Add(StaticText36, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Flow3 = new wxSlider(Panel3, IDD_SLIDER_Flow3, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Flow3"));
	FlexGridSizer9->Add(Slider_Flow3, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Flow3 = new ValueCurveButton(Panel3, ID_VALUECURVE_Flow3, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Flow3"));
	FlexGridSizer9->Add(BitmapButton_Flow3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Flow3 = new wxTextCtrl(Panel3, ID_TEXTCTRL_Flow3, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Flow3"));
	TextCtrl_Flow3->SetMaxLength(4);
	FlexGridSizer9->Add(TextCtrl_Flow3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_FlowMusic3 = new wxCheckBox(Panel3, ID_CHECKBOX_FlowMusic3, _("Flow Matches Music"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_FlowMusic3"));
	CheckBox_FlowMusic3->SetValue(false);
	FlexGridSizer9->Add(CheckBox_FlowMusic3, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer9->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer9, 1, wxALL|wxEXPAND, 5);
	Panel3->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(Panel3);
	FlexGridSizer4->SetSizeHints(Panel3);
	Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxPoint(141,20), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5->AddGrowableCol(0);
	CheckBox_Enabled4 = new wxCheckBox(Panel4, ID_CHECKBOX_Enabled4, _("Enabled"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Enabled4"));
	CheckBox_Enabled4->SetValue(false);
	FlexGridSizer5->Add(CheckBox_Enabled4, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer10 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText42 = new wxStaticText(Panel4, ID_STATICTEXT42, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
	FlexGridSizer10->Add(StaticText42, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_X4 = new wxSlider(Panel4, IDD_SLIDER_X4, 100, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_X4"));
	FlexGridSizer10->Add(Slider_X4, 1, wxALL|wxEXPAND, 5);
	BitmapButton_X4 = new ValueCurveButton(Panel4, ID_VALUECURVE_X4, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_X4"));
	FlexGridSizer10->Add(BitmapButton_X4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_X4 = new wxTextCtrl(Panel4, ID_TEXTCTRL_X4, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_X4"));
	TextCtrl_X4->SetMaxLength(4);
	FlexGridSizer10->Add(TextCtrl_X4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText43 = new wxStaticText(Panel4, ID_STATICTEXT43, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
	FlexGridSizer10->Add(StaticText43, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Y4 = new wxSlider(Panel4, IDD_SLIDER_Y4, 50, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Y4"));
	FlexGridSizer10->Add(Slider_Y4, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Y4 = new ValueCurveButton(Panel4, ID_VALUECURVE_Y4, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Y4"));
	FlexGridSizer10->Add(BitmapButton_Y4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Y4 = new wxTextCtrl(Panel4, ID_TEXTCTRL_Y4, _("50"), wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Y4"));
	TextCtrl_Y4->SetMaxLength(4);
	FlexGridSizer10->Add(TextCtrl_Y4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText44 = new wxStaticText(Panel4, ID_STATICTEXT44, _("Direction"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
	FlexGridSizer10->Add(StaticText44, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Direction4 = new wxSlider(Panel4, IDD_SLIDER_Direction4, 180, 0, 360, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Direction4"));
	FlexGridSizer10->Add(Slider_Direction4, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Direction4 = new ValueCurveButton(Panel4, ID_VALUECURVE_Direction4, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Direction4"));
	FlexGridSizer10->Add(BitmapButton_Direction4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Direction4 = new wxTextCtrl(Panel4, ID_TEXTCTRL_Direction4, _("180"), wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Direction4"));
	TextCtrl_Direction4->SetMaxLength(4);
	FlexGridSizer10->Add(TextCtrl_Direction4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText45 = new wxStaticText(Panel4, ID_STATICTEXT45, _("Velocity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
	FlexGridSizer10->Add(StaticText45, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Velocity4 = new wxSlider(Panel4, IDD_SLIDER_Velocity4, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Velocity4"));
	FlexGridSizer10->Add(Slider_Velocity4, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Velocity4 = new ValueCurveButton(Panel4, ID_VALUECURVE_Velocity4, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Velocity4"));
	FlexGridSizer10->Add(BitmapButton_Velocity4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Velocity4 = new wxTextCtrl(Panel4, ID_TEXTCTRL_Velocity4, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Velocity4"));
	TextCtrl_Velocity4->SetMaxLength(4);
	FlexGridSizer10->Add(TextCtrl_Velocity4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText46 = new wxStaticText(Panel4, ID_STATICTEXT46, _("Flow"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
	FlexGridSizer10->Add(StaticText46, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Flow4 = new wxSlider(Panel4, IDD_SLIDER_Flow4, 100, 0, 1000, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Flow4"));
	FlexGridSizer10->Add(Slider_Flow4, 1, wxALL|wxEXPAND, 5);
	BitmapButton_Flow4 = new ValueCurveButton(Panel4, ID_VALUECURVE_Flow4, valuecurvenotselected_24, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_VALUECURVE_Flow4"));
	FlexGridSizer10->Add(BitmapButton_Flow4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Flow4 = new wxTextCtrl(Panel4, ID_TEXTCTRL_Flow4, _("100"), wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(25,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Flow4"));
	TextCtrl_Flow4->SetMaxLength(4);
	FlexGridSizer10->Add(TextCtrl_Flow4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_FlowMusic4 = new wxCheckBox(Panel4, ID_CHECKBOX_FlowMusic4, _("Flow Matches Music"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_FlowMusic4"));
	CheckBox_FlowMusic4->SetValue(false);
	FlexGridSizer10->Add(CheckBox_FlowMusic4, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer10, 1, wxALL|wxEXPAND, 5);
	Panel4->SetSizer(FlexGridSizer5);
	FlexGridSizer5->Fit(Panel4);
	FlexGridSizer5->SetSizeHints(Panel4);
	Notebook1->AddPage(Panel1, _("1"), false);
	Notebook1->AddPage(Panel2, _("2"), false);
	Notebook1->AddPage(Panel3, _("3"), false);
	Notebook1->AddPage(Panel4, _("4"), false);
	FlexGridSizer77->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer77);
	FlexGridSizer77->Fit(this);
	FlexGridSizer77->SetSizeHints(this);

	Connect(IDD_SLIDER_LifeTime,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_LifeTime,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_LifeTime,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Size,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrl);
	Connect(ID_TEXTCTRL_Size,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_WarmUpFrames,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrl);
	Connect(ID_TEXTCTRL_WarmUpFrames,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_X1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_X1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_X1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Y1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Y1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Y1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Direction1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Direction1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Direction1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Velocity1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Velocity1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Velocity1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Flow1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Flow1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Flow1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(ID_CHECKBOX_Enabled2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnCheckBox_EnabledClick);
	Connect(IDD_SLIDER_X2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_X2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_X2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Y2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Y2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Y2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Direction2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Direction2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Direction2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Velocity2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Velocity2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Velocity2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Flow2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Flow2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Flow2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(ID_CHECKBOX_Enabled3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnCheckBox_EnabledClick);
	Connect(IDD_SLIDER_X3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_X3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_X3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Y3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Y3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Y3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Direction3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Direction3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Direction3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Velocity3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Velocity3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Velocity3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Flow3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Flow3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Flow3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(ID_CHECKBOX_Enabled4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnCheckBox_EnabledClick);
	Connect(IDD_SLIDER_X4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_X4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_X4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Y4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Y4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Y4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Direction4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Direction4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Direction4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Velocity4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Velocity4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Velocity4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	Connect(IDD_SLIDER_Flow4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedTextCtrlVC);
	Connect(ID_VALUECURVE_Flow4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LiquidPanel::OnVCButtonClick);
	Connect(ID_TEXTCTRL_Flow4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LiquidPanel::UpdateLinkedSlider);
	//*)

    Connect(wxID_ANY, EVT_VC_CHANGED, (wxObjectEventFunction)&LiquidPanel::OnVCChanged, 0, this);

    BitmapButton_LifeTime->GetValue()->SetLimits(0, 1000);

    BitmapButton_Direction1->GetValue()->SetLimits(0, 360);
    BitmapButton_Flow1->GetValue()->SetLimits(0, 1000);
    BitmapButton_Velocity1->GetValue()->SetLimits(0, 1000);
    BitmapButton_X1->GetValue()->SetLimits(0, 100);
    BitmapButton_Y1->GetValue()->SetLimits(0, 100);

    BitmapButton_Direction2->GetValue()->SetLimits(0, 360);
    BitmapButton_Flow2->GetValue()->SetLimits(0, 1000);
    BitmapButton_Velocity2->GetValue()->SetLimits(0, 1000);
    BitmapButton_X2->GetValue()->SetLimits(0, 100);
    BitmapButton_Y2->GetValue()->SetLimits(0, 100);

    BitmapButton_Direction3->GetValue()->SetLimits(0, 360);
    BitmapButton_Flow3->GetValue()->SetLimits(0, 1000);
    BitmapButton_Velocity3->GetValue()->SetLimits(0, 1000);
    BitmapButton_X3->GetValue()->SetLimits(0, 100);
    BitmapButton_Y3->GetValue()->SetLimits(0, 100);

    BitmapButton_Direction4->GetValue()->SetLimits(0, 360);
    BitmapButton_Flow4->GetValue()->SetLimits(0, 1000);
    BitmapButton_Velocity4->GetValue()->SetLimits(0, 1000);
    BitmapButton_X4->GetValue()->SetLimits(0, 100);
    BitmapButton_Y4->GetValue()->SetLimits(0, 100);

    ValidateWindow();

    SetName("ID_PANEL_LIQUID");
}

LiquidPanel::~LiquidPanel()
{
	//(*Destroy(LiquidPanel)
	//*)
}

PANEL_EVENT_HANDLERS(LiquidPanel)

void LiquidPanel::OnCheckBox_EnabledClick(wxCommandEvent& event)
{
    ValidateWindow();
}

void LiquidPanel::ValidateWindow()
{
    if (CheckBox_Enabled2->GetValue())
    {
        Slider_Direction2->Enable();
        Slider_Flow2->Enable();
        Slider_X2->Enable();
        Slider_Y2->Enable();
        Slider_Velocity2->Enable();

        TextCtrl_Direction2->Enable();
        TextCtrl_Flow2->Enable();
        TextCtrl_X2->Enable();
        TextCtrl_Y2->Enable();
        TextCtrl_Velocity2->Enable();

        BitmapButton_Direction2->Enable();
        BitmapButton_Flow2->Enable();
        BitmapButton_X2->Enable();
        BitmapButton_Y2->Enable();
        BitmapButton_Velocity2->Enable();
        CheckBox_FlowMusic2->Enable();
    }
    else
    {
        Slider_Direction2->Enable(false);
        Slider_Flow2->Enable(false);
        Slider_X2->Enable(false);
        Slider_Y2->Enable(false);
        Slider_Velocity2->Enable(false);

        TextCtrl_Direction2->Enable(false);
        TextCtrl_Flow2->Enable(false);
        TextCtrl_X2->Enable(false);
        TextCtrl_Y2->Enable(false);
        TextCtrl_Velocity2->Enable(false);

        BitmapButton_Direction2->Enable(false);
        BitmapButton_Flow2->Enable(false);
        BitmapButton_X2->Enable(false);
        BitmapButton_Y2->Enable(false);
        BitmapButton_Velocity2->Enable(false);
        CheckBox_FlowMusic2->Enable(false);
    }

    if (CheckBox_Enabled3->GetValue())
    {
        Slider_Direction3->Enable();
        Slider_Flow3->Enable();
        Slider_X3->Enable();
        Slider_Y3->Enable();
        Slider_Velocity3->Enable();

        TextCtrl_Direction3->Enable();
        TextCtrl_Flow3->Enable();
        TextCtrl_X3->Enable();
        TextCtrl_Y3->Enable();
        TextCtrl_Velocity3->Enable();

        BitmapButton_Direction3->Enable();
        BitmapButton_Flow3->Enable();
        BitmapButton_X3->Enable();
        BitmapButton_Y3->Enable();
        BitmapButton_Velocity3->Enable();
        CheckBox_FlowMusic3->Enable();
    }
    else
    {
        Slider_Direction3->Enable(false);
        Slider_Flow3->Enable(false);
        Slider_X3->Enable(false);
        Slider_Y3->Enable(false);
        Slider_Velocity3->Enable(false);

        TextCtrl_Direction3->Enable(false);
        TextCtrl_Flow3->Enable(false);
        TextCtrl_X3->Enable(false);
        TextCtrl_Y3->Enable(false);
        TextCtrl_Velocity3->Enable(false);

        BitmapButton_Direction3->Enable(false);
        BitmapButton_Flow3->Enable(false);
        BitmapButton_X3->Enable(false);
        BitmapButton_Y3->Enable(false);
        BitmapButton_Velocity3->Enable(false);
        CheckBox_FlowMusic3->Enable(false);
    }

    if (CheckBox_Enabled4->GetValue())
    {
        Slider_Direction4->Enable();
        Slider_Flow4->Enable();
        Slider_X4->Enable();
        Slider_Y4->Enable();
        Slider_Velocity4->Enable();

        TextCtrl_Direction4->Enable();
        TextCtrl_Flow4->Enable();
        TextCtrl_X4->Enable();
        TextCtrl_Y4->Enable();
        TextCtrl_Velocity4->Enable();

        BitmapButton_Direction4->Enable();
        BitmapButton_Flow4->Enable();
        BitmapButton_X4->Enable();
        BitmapButton_Y4->Enable();
        BitmapButton_Velocity4->Enable();
        CheckBox_FlowMusic4->Enable();
    }
    else
    {
        Slider_Direction4->Enable(false);
        Slider_Flow4->Enable(false);
        Slider_X4->Enable(false);
        Slider_Y4->Enable(false);
        Slider_Velocity4->Enable(false);

        TextCtrl_Direction4->Enable(false);
        TextCtrl_Flow4->Enable(false);
        TextCtrl_X4->Enable(false);
        TextCtrl_Y4->Enable(false);
        TextCtrl_Velocity4->Enable(false);

        BitmapButton_Direction4->Enable(false);
        BitmapButton_Flow4->Enable(false);
        BitmapButton_X4->Enable(false);
        BitmapButton_Y4->Enable(false);
        BitmapButton_Velocity4->Enable(false);
        CheckBox_FlowMusic4->Enable(false);
    }
}
