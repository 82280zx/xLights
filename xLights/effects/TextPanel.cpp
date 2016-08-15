#include "TextPanel.h"
#include "../../include/padlock16x16-blue.xpm"
#include "EffectPanelUtils.h"

//(*InternalHeaders(TextPanel)
#include <wx/notebook.h>
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
#include <wx/gbsizer.h>
#include <wx/image.h>
#include <wx/fontpicker.h>
#include <wx/string.h>
//*)

//(*IdInit(TextPanel)
const long TextPanel::ID_STATICTEXT53 = wxNewId();
const long TextPanel::ID_TEXTCTRL_Text = wxNewId();
const long TextPanel::ID_FONTPICKER_Text_Font = wxNewId();
const long TextPanel::ID_BITMAPBUTTON_FONTPICKER_Text_Font = wxNewId();
const long TextPanel::ID_STATICTEXT79 = wxNewId();
const long TextPanel::ID_CHOICE_Text_Dir = wxNewId();
const long TextPanel::ID_BITMAPBUTTON_CHOICE_Text_Dir = wxNewId();
const long TextPanel::ID_CHECKBOX_TextToCenter = wxNewId();
const long TextPanel::ID_BITMAPBUTTON_TextToCenter = wxNewId();
const long TextPanel::ID_STATICTEXT28 = wxNewId();
const long TextPanel::IDD_SLIDER_Text_Speed = wxNewId();
const long TextPanel::ID_TEXTCTRL_Text_Speed = wxNewId();
const long TextPanel::ID_BITMAPBUTTON_Text_Speed = wxNewId();
const long TextPanel::ID_STATICTEXT108 = wxNewId();
const long TextPanel::ID_CHOICE_Text_Effect = wxNewId();
const long TextPanel::ID_BITMAPBUTTON_CHOICE_Text_Effect = wxNewId();
const long TextPanel::ID_STATICTEXT99 = wxNewId();
const long TextPanel::ID_CHOICE_Text_Count = wxNewId();
const long TextPanel::ID_BITMAPBUTTON_CHOICE_Text_Count = wxNewId();
const long TextPanel::ID_CHECKBOX_Text_PixelOffsets = wxNewId();
const long TextPanel::ID_SLIDER_Text_XStart = wxNewId();
const long TextPanel::IDD_TEXTCTRL_Text_XStart = wxNewId();
const long TextPanel::IDD_TEXTCTRL_Text_YStart = wxNewId();
const long TextPanel::ID_SLIDER_Text_YStart = wxNewId();
const long TextPanel::IDD_PANEL6 = wxNewId();
const long TextPanel::ID_SLIDER_Text_XEnd = wxNewId();
const long TextPanel::IDD_TEXTCTRL_Text_XEnd = wxNewId();
const long TextPanel::IDD_TEXTCTRL_Text_YEnd = wxNewId();
const long TextPanel::ID_SLIDER_Text_YEnd = wxNewId();
const long TextPanel::IDD_PANEL17 = wxNewId();
const long TextPanel::IDD_NOTEBOOK1 = wxNewId();
const long TextPanel::ID_PANEL_Text1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TextPanel,wxPanel)
	//(*EventTable(TextPanel)
	//*)
END_EVENT_TABLE()

TextPanel::TextPanel(wxWindow* parent)
{
	//(*Initialize(TextPanel)
	wxStaticText* StaticText213;
	wxTextCtrl* TextCtrl92;
	wxTextCtrl* TextCtrl91;
	wxNotebook* Notebook6;
	wxFlexGridSizer* FlexGridSizer145;
	wxFlexGridSizer* FlexGridSizer66;
	wxFlexGridSizer* FlexGridSizer69;
	wxTextCtrl* TextCtrl94;
	wxStaticText* StaticText162;
	wxTextCtrl* TextCtrl93;
	wxFlexGridSizer* FlexGridSizer143;
	wxGridBagSizer* GridBagSizer7;
	wxPanel* Panel16;
	wxStaticText* StaticText211;
	wxFlexGridSizer* FlexGridSizer144;
	wxFlexGridSizer* FlexGridSizer142;
	wxStaticText* StaticText212;
	wxFlexGridSizer* FlexGridSizer119;
	wxTextCtrl* TextCtrl72;
	wxCheckBox* CheckBox_TextToCenter;
	wxFlexGridSizer* FlexGridSizer141;
	wxFlexGridSizer* FlexGridSizer46;
	wxFlexGridSizer* FlexGridSizer48;
	wxGridBagSizer* GridBagSizer6;
	wxStaticText* StaticText214;
	wxFontPickerCtrl* FontPickerCtrl;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer46 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer46->AddGrowableCol(0);
	Panel_Text1 = new wxPanel(this, ID_PANEL_Text1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_Text1"));
	FlexGridSizer69 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer69->AddGrowableCol(0);
	FlexGridSizer119 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer119->AddGrowableCol(1);
	StaticText53 = new wxStaticText(Panel_Text1, ID_STATICTEXT53, _("Text"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
	FlexGridSizer119->Add(StaticText53, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	TextCtrl_Text = new wxTextCtrl(Panel_Text1, ID_TEXTCTRL_Text, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Text"));
	TextCtrl_Text->SetMaxLength(256);
	FlexGridSizer119->Add(TextCtrl_Text, 1, wxALL|wxEXPAND, 2);
	FlexGridSizer119->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText162 = new wxStaticText(Panel_Text1, wxID_ANY, _("Font"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer119->Add(StaticText162, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FontPickerCtrl = new wxFontPickerCtrl(Panel_Text1, ID_FONTPICKER_Text_Font, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL|wxFNTP_USEFONT_FOR_LABEL, wxDefaultValidator, _T("ID_FONTPICKER_Text_Font"));
	FlexGridSizer119->Add(FontPickerCtrl, 1, wxALL|wxEXPAND, 2);
	BitmapButton_TextFont = new wxBitmapButton(Panel_Text1, ID_BITMAPBUTTON_FONTPICKER_Text_Font, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_FONTPICKER_Text_Font"));
	BitmapButton_TextFont->SetDefault();
	BitmapButton_TextFont->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer119->Add(BitmapButton_TextFont, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText78 = new wxStaticText(Panel_Text1, ID_STATICTEXT79, _("Movement"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT79"));
	FlexGridSizer119->Add(StaticText78, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer48 = new wxFlexGridSizer(0, 3, 0, 0);
	Choice_Text_Dir = new wxChoice(Panel_Text1, ID_CHOICE_Text_Dir, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Text_Dir"));
	Choice_Text_Dir->SetSelection( Choice_Text_Dir->Append(_("none")) );
	Choice_Text_Dir->Append(_("left"));
	Choice_Text_Dir->Append(_("right"));
	Choice_Text_Dir->Append(_("up"));
	Choice_Text_Dir->Append(_("down"));
	Choice_Text_Dir->Append(_("vector"));
	Choice_Text_Dir->Append(_("up-left"));
	Choice_Text_Dir->Append(_("down-left"));
	Choice_Text_Dir->Append(_("up-right"));
	Choice_Text_Dir->Append(_("down-right"));
	Choice_Text_Dir->Append(_("wavey"));
	FlexGridSizer48->Add(Choice_Text_Dir, 1, wxALL|wxEXPAND, 2);
	BitmapButton_TextDir = new wxBitmapButton(Panel_Text1, ID_BITMAPBUTTON_CHOICE_Text_Dir, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_CHOICE_Text_Dir"));
	BitmapButton_TextDir->SetDefault();
	BitmapButton_TextDir->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer48->Add(BitmapButton_TextDir, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	CheckBox_TextToCenter = new wxCheckBox(Panel_Text1, ID_CHECKBOX_TextToCenter, _("C"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_TextToCenter"));
	CheckBox_TextToCenter->SetValue(false);
	CheckBox_TextToCenter->SetToolTip(_("Move to center and stop"));
	FlexGridSizer48->Add(CheckBox_TextToCenter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer119->Add(FlexGridSizer48, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 1);
	BitmapButton_TextToCenter = new wxBitmapButton(Panel_Text1, ID_BITMAPBUTTON_TextToCenter, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_TextToCenter"));
	BitmapButton_TextToCenter->SetDefault();
	BitmapButton_TextToCenter->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer119->Add(BitmapButton_TextToCenter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	StaticText186 = new wxStaticText(Panel_Text1, ID_STATICTEXT28, _("Speed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	FlexGridSizer119->Add(StaticText186, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer66 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer66->AddGrowableCol(0);
	Slider_Text_Speed = new wxSlider(Panel_Text1, IDD_SLIDER_Text_Speed, 10, 0, 50, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IDD_SLIDER_Text_Speed"));
	FlexGridSizer66->Add(Slider_Text_Speed, 1, wxALL|wxEXPAND, 1);
	TextCtrl72 = new wxTextCtrl(Panel_Text1, ID_TEXTCTRL_Text_Speed, _("10"), wxDefaultPosition, wxDLG_UNIT(Panel_Text1,wxSize(20,-1)), 0, wxDefaultValidator, _T("ID_TEXTCTRL_Text_Speed"));
	TextCtrl72->SetMaxLength(3);
	FlexGridSizer66->Add(TextCtrl72, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer119->Add(FlexGridSizer66, 1, wxALL|wxEXPAND, 1);
	BitmapButton_Text_Speed = new wxBitmapButton(Panel_Text1, ID_BITMAPBUTTON_Text_Speed, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_Text_Speed"));
	BitmapButton_Text_Speed->SetDefault();
	BitmapButton_Text_Speed->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer119->Add(BitmapButton_Text_Speed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText107 = new wxStaticText(Panel_Text1, ID_STATICTEXT108, _("Effect"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT108"));
	FlexGridSizer119->Add(StaticText107, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	Choice_Text_Effect = new wxChoice(Panel_Text1, ID_CHOICE_Text_Effect, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Text_Effect"));
	Choice_Text_Effect->SetSelection( Choice_Text_Effect->Append(_("normal")) );
	Choice_Text_Effect->Append(_("vert text up"));
	Choice_Text_Effect->Append(_("vert text down"));
	Choice_Text_Effect->Append(_("rotate up 45"));
	Choice_Text_Effect->Append(_("rotate up 90"));
	Choice_Text_Effect->Append(_("rotate down 45"));
	Choice_Text_Effect->Append(_("rotate down 90"));
	FlexGridSizer119->Add(Choice_Text_Effect, 1, wxALL|wxEXPAND, 2);
	BitmapButton_TextEffect = new wxBitmapButton(Panel_Text1, ID_BITMAPBUTTON_CHOICE_Text_Effect, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_CHOICE_Text_Effect"));
	BitmapButton_TextEffect->SetDefault();
	BitmapButton_TextEffect->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer119->Add(BitmapButton_TextEffect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText98 = new wxStaticText(Panel_Text1, ID_STATICTEXT99, _("Count down"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT99"));
	FlexGridSizer119->Add(StaticText98, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	Choice_Text_Count = new wxChoice(Panel_Text1, ID_CHOICE_Text_Count, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Text_Count"));
	Choice_Text_Count->SetSelection( Choice_Text_Count->Append(_("none")) );
	Choice_Text_Count->Append(_("seconds"));
	Choice_Text_Count->Append(_("to date \'d h m s\'"));
	Choice_Text_Count->Append(_("to date \'h:m:s\'"));
	Choice_Text_Count->Append(_("to date \'m\' or \'s\'"));
	Choice_Text_Count->Append(_("to date \'s\'"));
	Choice_Text_Count->Append(_("!to date!%fmt"));
	FlexGridSizer119->Add(Choice_Text_Count, 1, wxALL|wxEXPAND, 2);
	BitmapButton_TextCount = new wxBitmapButton(Panel_Text1, ID_BITMAPBUTTON_CHOICE_Text_Count, padlock16x16_blue_xpm, wxDefaultPosition, wxSize(13,13), wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON_CHOICE_Text_Count"));
	BitmapButton_TextCount->SetDefault();
	BitmapButton_TextCount->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	FlexGridSizer119->Add(BitmapButton_TextCount, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	FlexGridSizer69->Add(FlexGridSizer119, 1, wxALL|wxEXPAND, 1);
	FlexGridSizer141 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer141->AddGrowableCol(0);
	CheckBox_Text_PixelOffsets = new wxCheckBox(Panel_Text1, ID_CHECKBOX_Text_PixelOffsets, _("Offsets In Pixels"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_Text_PixelOffsets"));
	CheckBox_Text_PixelOffsets->SetValue(false);
	FlexGridSizer141->Add(CheckBox_Text_PixelOffsets, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	Notebook6 = new wxNotebook(Panel_Text1, IDD_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("IDD_NOTEBOOK1"));
	Panel16 = new wxPanel(Notebook6, IDD_PANEL6, wxPoint(15,49), wxDefaultSize, wxTAB_TRAVERSAL, _T("IDD_PANEL6"));
	FlexGridSizer142 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer142->AddGrowableCol(0);
	FlexGridSizer143 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer143->AddGrowableCol(1);
	StaticText211 = new wxStaticText(Panel16, wxID_ANY, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer143->Add(StaticText211, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Text_XStart = new wxSlider(Panel16, ID_SLIDER_Text_XStart, 0, -200, 200, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Text_XStart"));
	FlexGridSizer143->Add(Slider_Text_XStart, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer143->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl91 = new wxTextCtrl(Panel16, IDD_TEXTCTRL_Text_XStart, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel16,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Text_XStart"));
	TextCtrl91->SetMaxLength(4);
	FlexGridSizer143->Add(TextCtrl91, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer142->Add(FlexGridSizer143, 1, wxALL|wxEXPAND, 5);
	GridBagSizer6 = new wxGridBagSizer(0, 0);
	StaticText212 = new wxStaticText(Panel16, wxID_ANY, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	GridBagSizer6->Add(StaticText212, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl92 = new wxTextCtrl(Panel16, IDD_TEXTCTRL_Text_YStart, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel16,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Text_YStart"));
	TextCtrl92->SetMaxLength(4);
	GridBagSizer6->Add(TextCtrl92, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Text_YStart = new wxSlider(Panel16, ID_SLIDER_Text_YStart, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER_Text_YStart"));
	GridBagSizer6->Add(Slider_Text_YStart, wxGBPosition(0, 1), wxGBSpan(4, 1), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer142->Add(GridBagSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel16->SetSizer(FlexGridSizer142);
	FlexGridSizer142->Fit(Panel16);
	FlexGridSizer142->SetSizeHints(Panel16);
	Panel17 = new wxPanel(Notebook6, IDD_PANEL17, wxPoint(104,13), wxDefaultSize, wxTAB_TRAVERSAL, _T("IDD_PANEL17"));
	FlexGridSizer144 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer144->AddGrowableCol(0);
	FlexGridSizer145 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer145->AddGrowableCol(1);
	StaticText213 = new wxStaticText(Panel17, wxID_ANY, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer145->Add(StaticText213, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Text_XEnd = new wxSlider(Panel17, ID_SLIDER_Text_XEnd, 0, -200, 200, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Text_XEnd"));
	FlexGridSizer145->Add(Slider_Text_XEnd, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer145->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl93 = new wxTextCtrl(Panel17, IDD_TEXTCTRL_Text_XEnd, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel17,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Text_XEnd"));
	TextCtrl93->SetMaxLength(4);
	FlexGridSizer145->Add(TextCtrl93, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer144->Add(FlexGridSizer145, 1, wxALL|wxEXPAND, 5);
	GridBagSizer7 = new wxGridBagSizer(0, 0);
	StaticText214 = new wxStaticText(Panel17, wxID_ANY, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	GridBagSizer7->Add(StaticText214, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl94 = new wxTextCtrl(Panel17, IDD_TEXTCTRL_Text_YEnd, _("0"), wxDefaultPosition, wxDLG_UNIT(Panel17,wxSize(20,-1)), wxTE_CENTRE, wxDefaultValidator, _T("IDD_TEXTCTRL_Text_YEnd"));
	TextCtrl94->SetMaxLength(4);
	GridBagSizer7->Add(TextCtrl94, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Text_YEnd = new wxSlider(Panel17, ID_SLIDER_Text_YEnd, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER_Text_YEnd"));
	GridBagSizer7->Add(Slider_Text_YEnd, wxGBPosition(0, 1), wxGBSpan(4, 1), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer144->Add(GridBagSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel17->SetSizer(FlexGridSizer144);
	FlexGridSizer144->Fit(Panel17);
	FlexGridSizer144->SetSizeHints(Panel17);
	Notebook6->AddPage(Panel16, _("Start Position"), false);
	Notebook6->AddPage(Panel17, _("End Position"), false);
	FlexGridSizer141->Add(Notebook6, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer69->Add(FlexGridSizer141, 1, wxALL|wxEXPAND, 1);
	Panel_Text1->SetSizer(FlexGridSizer69);
	FlexGridSizer69->Fit(Panel_Text1);
	FlexGridSizer69->SetSizeHints(Panel_Text1);
	FlexGridSizer46->Add(Panel_Text1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer46);
	FlexGridSizer46->Fit(this);
	FlexGridSizer46->SetSizeHints(this);

	Connect(ID_BITMAPBUTTON_FONTPICKER_Text_Font,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON_CHOICE_Text_Dir,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON_TextToCenter,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextPanel::OnLockButtonClick);
	Connect(IDD_SLIDER_Text_Speed,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedTextCtrl);
	Connect(ID_TEXTCTRL_Text_Speed,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedSlider);
	Connect(ID_BITMAPBUTTON_Text_Speed,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON_CHOICE_Text_Effect,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextPanel::OnLockButtonClick);
	Connect(ID_BITMAPBUTTON_CHOICE_Text_Count,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextPanel::OnLockButtonClick);
	Connect(ID_SLIDER_Text_XStart,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedTextCtrl);
	Connect(IDD_TEXTCTRL_Text_XStart,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedSlider);
	Connect(IDD_TEXTCTRL_Text_YStart,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedSlider);
	Connect(ID_SLIDER_Text_YStart,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedTextCtrl);
	Connect(ID_SLIDER_Text_XEnd,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedTextCtrl);
	Connect(IDD_TEXTCTRL_Text_XEnd,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedSlider);
	Connect(IDD_TEXTCTRL_Text_YEnd,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedSlider);
	Connect(ID_SLIDER_Text_YEnd,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&TextPanel::UpdateLinkedTextCtrl);
	//*)
    SetName("ID_PANEL_TEXT");
}

TextPanel::~TextPanel()
{
	//(*Destroy(TextPanel)
	//*)
}

PANEL_EVENT_HANDLERS(TextPanel)
