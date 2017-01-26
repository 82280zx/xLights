#include "DimDialog.h"
#include "xScheduleMain.h"
#include "ScheduleManager.h"

//(*InternalHeaders(DimDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DimDialog)
const long DimDialog::ID_STATICTEXT1 = wxNewId();
const long DimDialog::ID_SPINCTRL1 = wxNewId();
const long DimDialog::ID_STATICTEXT2 = wxNewId();
const long DimDialog::ID_SPINCTRL2 = wxNewId();
const long DimDialog::ID_STATICTEXT3 = wxNewId();
const long DimDialog::ID_SPINCTRL3 = wxNewId();
const long DimDialog::ID_BUTTON1 = wxNewId();
const long DimDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DimDialog,wxDialog)
	//(*EventTable(DimDialog)
	//*)
END_EVENT_TABLE()

DimDialog::DimDialog(wxWindow* parent, size_t& startChannel, size_t& channels, size_t& dim,wxWindowID id,const wxPoint& pos,const wxSize& size) : _startChannel(startChannel), _channels(channels), _dim(dim)
{
	//(*Initialize(DimDialog)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Dim"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Start Channel:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_StartChannel = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1, _T("ID_SPINCTRL1"));
	SpinCtrl_StartChannel->SetValue(_T("1"));
	FlexGridSizer1->Add(SpinCtrl_StartChannel, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Channels:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Channels = new wxSpinCtrl(this, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1, _T("ID_SPINCTRL2"));
	SpinCtrl_Channels->SetValue(_T("1"));
	FlexGridSizer1->Add(SpinCtrl_Channels, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Brightness:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Brightness = new wxSpinCtrl(this, ID_SPINCTRL3, _T("100"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 100, _T("ID_SPINCTRL3"));
	SpinCtrl_Brightness->SetValue(_T("100"));
	FlexGridSizer1->Add(SpinCtrl_Brightness, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Button_Ok = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button_Ok, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Cancel = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer1->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DimDialog::OnButton_OkClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DimDialog::OnButton_CancelClick);
	//*)

    long chs = xScheduleFrame::GetScheduleManager()->GetTotalChannels();
    SpinCtrl_StartChannel->SetRange(1, chs);
    SpinCtrl_Channels->SetRange(1, chs);

    SpinCtrl_StartChannel->SetValue(_startChannel);
    SpinCtrl_Channels->SetValue(_channels);
    SpinCtrl_Brightness->SetValue(_dim);
}

DimDialog::~DimDialog()
{
	//(*Destroy(DimDialog)
	//*)
}

void DimDialog::OnButton_OkClick(wxCommandEvent& event)
{
    _startChannel = SpinCtrl_StartChannel->GetValue();
    _channels = SpinCtrl_Channels->GetValue();
    _dim = SpinCtrl_Brightness->GetValue();
    EndDialog(wxID_OK);
}

void DimDialog::OnButton_CancelClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}
