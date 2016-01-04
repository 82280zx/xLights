#include "ShimmerPanel.h"
#include "../../include/padlock16x16-blue.xpm"
#include "EffectPanelUtils.h"

//(*InternalHeaders(ShimmerPanel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/bitmap.h>
#include <wx/slider.h>
#include <wx/settings.h>
#include <wx/bmpbuttn.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(ShimmerPanel)
const long ShimmerPanel::ID_STATICTEXT68 = wxNewId();
const long ShimmerPanel::ID_SLIDER_Shimmer_Duty_Factor = wxNewId();
const long ShimmerPanel::IDD_TEXTCTRL_Shimmer_Duty_Factor = wxNewId();
const long ShimmerPanel::ID_BITMAPBUTTON_DutyFactor = wxNewId();
const long ShimmerPanel::ID_STATICTEXT9 = wxNewId();
const long ShimmerPanel::IDD_SLIDER_Shimmer_Cycles = wxNewId();
const long ShimmerPanel::ID_TEXTCTRL_Shimmer_Cycles = wxNewId();
const long ShimmerPanel::ID_BITMAPBUTTON24 = wxNewId();
const long ShimmerPanel::ID_STATICTEXT69 = wxNewId();
const long ShimmerPanel::ID_CHECKBOX_Shimmer_Use_All_Colors = wxNewId();
const long ShimmerPanel::ID_BITMAPBUTTON_ShimmerUseAllColors = wxNewId();
//*)

BEGIN_EVENT_TABLE(ShimmerPanel,wxPanel)
	//(*EventTable(ShimmerPanel)
	//*)
END_EVENT_TABLE()

ShimmerPanel::ShimmerPanel(wxWindow* parent)
{
	//(*Initialize(ShimmerPanel)
	wxSlider* Slider17;
	wxFlexGridSizer* FlexGridSizer56;
	wxSlider* Slider_Shimmer_Duty_Factor;
	wxTextCtrl* TextCtrl47;
	wxTextCtrl* TextCtrl46;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer56 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer56->AddGrowableCol(1);
	StaticText66 = new wxStaticText(this, ID_STATICTEXT68, _("Duty Factor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT68"));
	FlexGridSizer56->Add(StaticText66, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Shimmer_Duty_Factor = new wxSlider(this, ID_SLIDER_Shimmer_Duty_Factor, 50, 1, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Shimmer_Duty_Factor"));
	FlexGridSizer56->Add(Slider_Shimmer_Duty_Factor, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl46 = new wxTextCtrl(this, IDD_TEXTCTRL_Shimmer_Duty_Factor, _("50"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), 0, wxDefaultValidator, _T("IDD_TEXTCTRL_Shimmer_Duty_Factor"));
	TextCtrl46->SetMaxLength(3);
	FlexGridSizer56->Add(TextCtrl46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_Shimmer_Duty_Factor = new wxBitmapButton(this, ID_BITMAPBUTTON_DutyFactor, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON_DutyFactor"));
	BitmapButton_Shimmer_Duty_Factor->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer56->Add(BitmapButton_Shimmer_Duty_Factor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText65 = new wxStaticText(this, ID_STATICTEXT9, _("Cycle Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer56->Add(StaticText65, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider17 = new wxSlider(this, IDD_SLIDER_Shimmer_Cycles, 10, 0, 300, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Shimmer_Cycles"));
	FlexGridSizer56->Add(Slider17, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl47 = new wxTextCtrl(this, ID_TEXTCTRL_Shimmer_Cycles, _("1.0"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Shimmer_Cycles"));
	TextCtrl47->SetMaxLength(4);
	FlexGridSizer56->Add(TextCtrl47, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton5 = new wxBitmapButton(this, ID_BITMAPBUTTON24, padlock16x16_blue_xpm, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON24"));
	BitmapButton5->SetMinSize(wxSize(13,13));
	BitmapButton5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer56->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText67 = new wxStaticText(this, ID_STATICTEXT69, _("Use All Colors"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT69"));
	FlexGridSizer56->Add(StaticText67, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox_Shimmer_Use_All_Colors = new wxCheckBox(this, ID_CHECKBOX_Shimmer_Use_All_Colors, _("Yes"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Shimmer_Use_All_Colors"));
	CheckBox_Shimmer_Use_All_Colors->SetValue(false);
	FlexGridSizer56->Add(CheckBox_Shimmer_Use_All_Colors, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer56->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton_Shimmer_Use_All_Colors = new wxBitmapButton(this, ID_BITMAPBUTTON_ShimmerUseAllColors, padlock16x16_blue_xpm, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON_ShimmerUseAllColors"));
	BitmapButton_Shimmer_Use_All_Colors->SetMinSize(wxSize(13,13));
	BitmapButton_Shimmer_Use_All_Colors->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer56->Add(BitmapButton_Shimmer_Use_All_Colors, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer56);
	FlexGridSizer56->Fit(this);
	FlexGridSizer56->SetSizeHints(this);

	Connect(ID_SLIDER_Shimmer_Duty_Factor,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&ShimmerPanel::UpdateLinkedTextCtrl);
	Connect(IDD_TEXTCTRL_Shimmer_Duty_Factor,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ShimmerPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON_DutyFactor,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShimmerPanel::OnLockButtonClick);
	Connect(IDD_SLIDER_Shimmer_Cycles,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&ShimmerPanel::UpdateLinkedTextCtrlFloat);
	Connect(ID_TEXTCTRL_Shimmer_Cycles,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ShimmerPanel::UpdateLinkedSliderFloat);
	Connect(ID_BITMAPBUTTON24,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShimmerPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON_ShimmerUseAllColors,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShimmerPanel::OnLockButtonClick);
	//*)
    SetName("ID_PANEL_SHIMMER");
}

ShimmerPanel::~ShimmerPanel()
{
	//(*Destroy(ShimmerPanel)
	//*)
}

PANEL_EVENT_HANDLERS(ShimmerPanel)