#include "EffectPanelUtils.h"


#include <wx/scrolwin.h>
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/fontpicker.h>
#include <wx/choicebk.h>

#include "../BitmapCache.h"
#include "../ValueCurveButton.h"
#include "../ValueCurveDialog.h"
#include <wx/valnum.h>

std::map<std::string, bool> EffectPanelUtils::buttonStates;

void EffectPanelUtils::OnLockButtonClick(wxCommandEvent& event) {
    wxButton * button = (wxButton*)event.GetEventObject();
    SetLock(button);
}

void EffectPanelUtils::SetLock(wxButton *button) {
    wxString parent = button->GetName();
    if (parent.StartsWith("ID_BITMAPBUTTON_")) parent = "ID_" + parent.substr(16);
    bool islocked = buttonStates[std::string(parent)];
    if (islocked) {
        buttonStates[std::string(parent)] = false;
        button->SetBitmapLabel(BitmapCache::GetLockIcon(false));
    } else {
        buttonStates[std::string(parent)] = true;
        button->SetBitmapLabel(BitmapCache::GetLockIcon(true));
    }
}

bool EffectPanelUtils::IsLocked(std::string name) {
    return buttonStates[name];
}


//generic routines that can replace the above and be completely implemented in the codeblocks
//gui based on the ID names of the two controls.  No need for "member" variables
void EffectPanelUtils::UpdateLinkedSlider(wxCommandEvent& event)
{
    wxTextCtrl * txt = (wxTextCtrl*)event.GetEventObject();
    wxString name = txt->GetName();
    if (name.Contains("IDD_")) {
        name.Replace("IDD_TEXTCTRL_", "ID_SLIDER_");
    } else {
        name.Replace("ID_TEXTCTRL_", "IDD_SLIDER_");
    }
    wxSlider *slider = (wxSlider*)txt->GetParent()->FindWindowByName(name);
    if (slider == nullptr) {
        return;
    }
    int value = wxAtoi(txt->GetValue());

    if (value < slider->GetMin()) {
        value = slider->GetMin();
        wxString val_str;
        val_str << value;
        txt->ChangeValue(val_str);
    }
    else if (value > slider->GetMax()) {
        value = slider->GetMax();
        wxString val_str;
        val_str << value;
        txt->ChangeValue(val_str);
    }
    slider->SetValue(value);
}

void EffectPanelUtils::UpdateLinkedTextCtrl(wxScrollEvent& event)
{
    wxSlider * slider = (wxSlider*)event.GetEventObject();
    wxString name = slider->GetName();
    if (name.Contains("ID_")) {
        name.Replace("ID_SLIDER_", "IDD_TEXTCTRL_");
    } else {
        name.Replace("IDD_SLIDER_", "ID_TEXTCTRL_");
    }
    wxTextCtrl *txt = (wxTextCtrl*)slider->GetParent()->FindWindowByName(name);
    txt->ChangeValue(wxString::Format("%d",slider->GetValue()));
}

void EffectPanelUtils::UpdateLinkedTextCtrlVC(wxScrollEvent& event)
{
    UpdateLinkedTextCtrl(event);
    wxSlider * slider = (wxSlider*)event.GetEventObject();
    wxString name = slider->GetName();
    if (name.Contains("ID_")) {
        name.Replace("ID_SLIDER_", "ID_VALUECURVE_");
    }
    else {
        name.Replace("IDD_SLIDER_", "ID_VALUECURVE_");
    }
    ValueCurveButton* vc = (ValueCurveButton*)slider->GetParent()->FindWindowByName(name);
    
    if (vc != NULL)
    {
        if (vc->GetValue()->GetType() == "Flat")
        {
            vc->GetValue()->SetUnscaledParameter1(slider->GetValue());
        }
    }
    else
    {
        wxASSERT("Value curve button not found: " + name);
    }
}

void EffectPanelUtils::UpdateLinkedSlider360(wxCommandEvent& event)
{
    wxTextCtrl * txt = (wxTextCtrl*)event.GetEventObject();
    wxString name = txt->GetName();
    if (name.Contains("IDD_")) {
        name.Replace("IDD_TEXTCTRL_", "ID_SLIDER_");
    } else {
        name.Replace("ID_TEXTCTRL_", "IDD_SLIDER_");
    }
    wxSlider *slider = (wxSlider*)txt->GetParent()->FindWindowByName(name);
    if (slider == nullptr) {
        return;
    }
    double val;
    txt->GetValue().ToDouble(&val);
    int value = (int)(val * 360.0);

    if (value < slider->GetMin()) {
        value = slider->GetMin();
        txt->ChangeValue(wxString::Format("%0.2f",(double)value/360.0));
    } else if (value > slider->GetMax()) {
        value = slider->GetMax();
        wxString val_str;
        val_str << value;
        txt->ChangeValue(wxString::Format("%0.2f",(double)value/360.0));
    }
    slider->SetValue(value);
}
void EffectPanelUtils::UpdateLinkedTextCtrl360(wxScrollEvent& event)
{
    wxSlider * slider = (wxSlider*)event.GetEventObject();
    wxString name = slider->GetName();
    if (name.Contains("ID_")) {
        name.Replace("ID_SLIDER_", "IDD_TEXTCTRL_");
    } else {
        name.Replace("IDD_SLIDER_", "ID_TEXTCTRL_");
    }
    wxTextCtrl *txt = (wxTextCtrl*)slider->GetParent()->FindWindowByName(name);
    txt->ChangeValue(wxString::Format("%0.2f",slider->GetValue()/360.0));
}

void EffectPanelUtils::UpdateLinkedTextCtrlFloat(wxScrollEvent& event)
{
    wxSlider * slider = (wxSlider*)event.GetEventObject();
    wxString name = slider->GetName();
    if (name.Contains("ID_")) {
        name.Replace("ID_SLIDER_", "IDD_TEXTCTRL_");
    } else {
        name.Replace("IDD_SLIDER_", "ID_TEXTCTRL_");
    }
    wxTextCtrl *txt = (wxTextCtrl*)slider->GetParent()->FindWindowByName(name);
    txt->ChangeValue(wxString::Format("%0.1f",slider->GetValue()/10.0));
}

void EffectPanelUtils::UpdateLinkedTextCtrlFloatVC(wxScrollEvent& event)
{
    UpdateLinkedTextCtrlFloat(event);
    wxSlider * slider = (wxSlider*)event.GetEventObject();
    wxString name = slider->GetName();
    if (name.Contains("ID_")) {
        name.Replace("ID_SLIDER_", "ID_VALUECURVE_");
    }
    else {
        name.Replace("IDD_SLIDER_", "ID_VALUECURVE_");
    }
    ValueCurveButton* vc = (ValueCurveButton*)slider->GetParent()->FindWindowByName(name);

    if (vc != NULL)
    {
        if (vc->GetValue()->GetType() == "Flat")
        {
            vc->GetValue()->SetUnscaledParameter1(slider->GetValue());
        }
    }
    else
    {
        wxASSERT("Value curve button not found: " + name);
    }
}

void EffectPanelUtils::UpdateLinkedSliderFloat(wxCommandEvent& event)
{
    wxTextCtrl * txt = (wxTextCtrl*)event.GetEventObject();
    wxString name = txt->GetName();
    if (name.Contains("IDD_")) {
        name.Replace("IDD_TEXTCTRL_", "ID_SLIDER_");
    } else {
        name.Replace("ID_TEXTCTRL_", "IDD_SLIDER_");
    }
    wxSlider *slider = (wxSlider*)txt->GetParent()->FindWindowByName(name);
    if (slider == nullptr) {
        return;
    }

    double val;
    txt->GetValue().ToDouble(&val);
    int value = (int)(val * 10.0);

    if (value < slider->GetMin()) {
        value = slider->GetMin();
        txt->ChangeValue(wxString::Format("%0.1f",(double)value/10.0));
    } else if (value > slider->GetMax()) {
        value = slider->GetMax();
        wxString val_str;
        val_str << value;
        txt->ChangeValue(wxString::Format("%0.1f",(double)value/10.0));
    }
    slider->SetValue(value);
}


void EffectPanelUtils::enableControlsByName(wxWindow *window, const wxString &name, bool enable) {
    wxWindow *w = window->FindWindowByName(name);
    if (w != nullptr) {
        w->Enable(enable);
    }
    wxString n2 = "IDD_" + name.SubString(3, name.size());
    w = window->FindWindowByName(name);
    if (w != nullptr) {
        w->Enable(enable);
    }
}

void EffectPanelUtils::OnVCButtonClick(wxCommandEvent& event)
{
    ValueCurveButton * vc = (ValueCurveButton*)event.GetEventObject();

    wxString name = vc->GetName();
    name.Replace("IDD_VALUECURVE_", "ID_SLIDER_");
    name.Replace("ID_VALUECURVE_", "ID_SLIDER_");
    wxSlider *slider = (wxSlider*)vc->GetParent()->FindWindowByName(name);
    if (slider == NULL || (void*)slider == (void*)vc)
    {
        name = vc->GetName();
        name.Replace("IDD_VALUECURVE_", "IDD_SLIDER_");
        name.Replace("ID_VALUECURVE_", "IDD_SLIDER_");
        slider = (wxSlider*)vc->GetParent()->FindWindowByName(name);
    }

    name = vc->GetName();
    name.Replace("IDD_VALUECURVE_", "ID_TEXTCTRL_");
    name.Replace("ID_VALUECURVE_", "ID_TEXTCTRL_");
    wxTextCtrl *txt = (wxTextCtrl*)vc->GetParent()->FindWindowByName(name);
    if (txt == NULL || (void*)txt == (void*)vc)
    {
        name = vc->GetName();
        name.Replace("IDD_VALUECURVE_", "IDD_TEXTCTRL_");
        name.Replace("ID_VALUECURVE_", "IDD_TEXTCTRL_");
        txt = (wxTextCtrl*)vc->GetParent()->FindWindowByName(name);
    }

    vc->ToggleActive();
    if (vc->GetValue()->IsActive())
    {
        ValueCurveDialog vcd(vc->GetParent(), vc->GetValue());
        if (vcd.ShowModal() == wxOK)
        {
            if (slider != NULL)
            {
                slider->Disable();
            }
            if (txt != NULL)
            {
                txt->Disable();
            }
        }
        else
        {
            if (slider != NULL)
            {
                slider->Enable();
            }
            if (txt != NULL)
            {
                txt->Enable();
            }
            vc->SetActive(false);
        }
        vc->UpdateState();
    }
    else
    {
        if (slider != NULL)
        {
            slider->Enable();
        }
        if (txt != NULL)
        {
            txt->Enable();
        }
    }
}
