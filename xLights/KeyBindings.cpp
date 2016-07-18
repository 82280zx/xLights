//
//  KeyBindings.cpp
//  xLights

#include "wx/file.h"
#include <wx/xml/xml.h>
#include "KeyBindings.h"
#include "xLightsMain.h"

void KeyBindingMap::LoadDefaults() {
    bindings.push_back(KeyBinding('t', TIMING_ADD));
    bindings.push_back(KeyBinding('s', TIMING_SPLIT));
    bindings.push_back(KeyBinding('+', KEY_ZOOM_IN));
    bindings.push_back(KeyBinding('-', KEY_ZOOM_OUT));
    bindings.push_back(KeyBinding('R', RANDOM_EFFECT));
    bindings.push_back(KeyBinding('o', "On", "E_TEXTCTRL_Eff_On_End=100,E_TEXTCTRL_Eff_On_Start=100", xlights_version_string));
    bindings.push_back(KeyBinding('u', "On", "E_TEXTCTRL_Eff_On_End=100,E_TEXTCTRL_Eff_On_Start=0", xlights_version_string));
    bindings.push_back(KeyBinding('d', "On", "E_TEXTCTRL_Eff_On_End=0,E_TEXTCTRL_Eff_On_Start=100", xlights_version_string));
    bindings.push_back(KeyBinding('m', "Morph", "", xlights_version_string));
    bindings.push_back(KeyBinding('c', "Curtain", "", xlights_version_string));
    bindings.push_back(KeyBinding('i', "Circles", "", xlights_version_string));
    bindings.push_back(KeyBinding('b', "Bars", "", xlights_version_string));
    bindings.push_back(KeyBinding('y', "Butterfly", "", xlights_version_string));
    bindings.push_back(KeyBinding('f', "Fire", "", xlights_version_string));
    bindings.push_back(KeyBinding('g', "Garlands", "", xlights_version_string));
    bindings.push_back(KeyBinding('p', "Pinwheel", "", xlights_version_string));
    bindings.push_back(KeyBinding('r', "Ripple", "", xlights_version_string));
    bindings.push_back(KeyBinding('x', "Text", "", xlights_version_string));
    bindings.push_back(KeyBinding('S', "Spirals", "", xlights_version_string));
    bindings.push_back(KeyBinding('w', "Color Wash", "", xlights_version_string));
    bindings.push_back(KeyBinding('n', "Snowflakes", "", xlights_version_string));
	bindings.push_back(KeyBinding('O', "Off", "", xlights_version_string));
	bindings.push_back(KeyBinding('F', "Fan", "", xlights_version_string));
}

void KeyBindingMap::Load(wxFileName &fileName) {
    if (fileName.Exists()) {
        wxXmlDocument doc;
        if (doc.Load(fileName.GetFullPath())) {
            bindings.clear();
            wxXmlNode *root = doc.GetRoot();
            wxXmlNode *child = root->GetChildren();

            while (child != NULL) {
                if ("keybinding" == child->GetName()) {
                    wxString type = child->GetAttribute("type");
                    unsigned char k = child->GetAttribute("key")[0];
                    if ("TIMING_ADD" == type) {
                        bindings.push_back(KeyBinding(k, TIMING_ADD));
                    } else if ("TIMING_SPLIT" == type) {
                        bindings.push_back(KeyBinding(k, TIMING_SPLIT));
                    } else if ("ZOOM_IN" == type) {
                        bindings.push_back(KeyBinding(k, KEY_ZOOM_IN));
                    } else if ("ZOOM_OUT" == type) {
                        bindings.push_back(KeyBinding(k, KEY_ZOOM_OUT));
                    } else if ("RANDOM" == type) {
                        bindings.push_back(KeyBinding(k, RANDOM_EFFECT));
                    } else {
                        wxString effect = child->GetAttribute("effect");
                        wxString settings = "";
                        if (child->GetChildren() != NULL) {
                            settings = child->GetChildren()->GetContent();
                        }
                        bindings.push_back(KeyBinding(k, effect, settings, child->GetAttribute("xLightsVersion", "4.0")));
                    }
                }

                child = child->GetNext();
            }
        }
    }
}

void KeyBindingMap::Save(wxFileName &fileName) {
    wxXmlDocument doc;
    wxXmlNode *root = new wxXmlNode(wxXML_ELEMENT_NODE, "keybindings");
    doc.SetRoot(root);
    for(std::vector<KeyBinding>::iterator it = bindings.begin(); it != bindings.end(); it++) {
        const KeyBinding &binding = *it;
        wxXmlNode *child = new wxXmlNode(wxXML_ELEMENT_NODE, "keybinding");
        child->AddAttribute("key", wxString::Format("%c", binding.GetKey()));
        switch (binding.GetType()) {
        case TIMING_ADD:
            child->AddAttribute("type", "TIMING_ADD");
            break;
        case TIMING_SPLIT:
            child->AddAttribute("type", "TIMING_SPLIT");
            break;
        case KEY_ZOOM_IN:
            child->AddAttribute("type", "ZOOM_IN");
            break;
        case KEY_ZOOM_OUT:
            child->AddAttribute("type", "ZOOM_OUT");
            break;
        case RANDOM_EFFECT:
            child->AddAttribute("type", "RANDOM");
            break;
        default:
            child->AddAttribute("type", "EFFECT");
            child->AddAttribute("effect", binding.GetEffectName());
            child->AddAttribute("xLightsVersion", binding.GetEffectDataVersion());
            child->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", binding.GetEffectString()));
            break;
        }
        root->AddChild(child);
    }
    doc.Save(fileName.GetFullPath());
}

KeyBinding *KeyBindingMap::Find(unsigned char ch) {
    for (int x = 0; x < bindings.size(); x++) {
        if (bindings[x].GetKey() == ch) {
            return &bindings[x];
        }
    }
    return NULL;
}

