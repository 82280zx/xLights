#include "OutputProcess.h"
#include <wx/xml/xml.h>
#include <wx/wxcrt.h>
#include "OutputProcessDim.h"
#include "OutputProcessDimWhite.h"
#include "OutputProcessSet.h"
#include "OutputProcessRemap.h"

OutputProcess::OutputProcess(wxXmlNode* node)
{
    _changeCount = 0;
    _lastSavedChangeCount = 0;
    _startChannel = wxAtol(node->GetAttribute("StartChannel", "1"));
    _description = node->GetAttribute("Description", "").ToStdString();
}

OutputProcess::OutputProcess(const OutputProcess& op)
{
    _description = op._description;
    _changeCount = op._changeCount;
    _lastSavedChangeCount = op._lastSavedChangeCount;
    _startChannel = op._startChannel;
}

OutputProcess::OutputProcess()
{
    _changeCount = 1;
    _lastSavedChangeCount = 0;
    _startChannel = 1;
    _description = "";
}

OutputProcess::OutputProcess(size_t startChannel, const std::string& description)
{
    _changeCount = 1;
    _lastSavedChangeCount = 0;
    _startChannel = startChannel;
    _description = description;
}

void OutputProcess::Save(wxXmlNode* node)
{
    node->AddAttribute("StartChannel", wxString::Format(wxT("%i"), _startChannel));
    node->AddAttribute("Description", _description);
}

OutputProcess* OutputProcess::CreateFromXml(wxXmlNode* node)
{
    if (node->GetName() == "OPDim")
    {
        return new OutputProcessDim(node);
    }
    else if (node->GetName() == "OPDimWhite")
    {
        return new OutputProcessDimWhite(node);
    }
    else if (node->GetName() == "OPSet")
    {
        return new OutputProcessSet(node);
    }
    else if (node->GetName() == "OPRemap")
    {
        return new OutputProcessRemap(node);
    }
    return nullptr;
}
