#include "PlayListItemPJLink.h"
#include "wx/xml/xml.h"
#include <wx/notebook.h>
#include "PlayListItemPJLinkPanel.h"
#include "../../xLights/AudioManager.h"
#include "../xScheduleMain.h"
#include "../ScheduleManager.h"
#include "../ScheduleOptions.h"
#include <wx/sckaddr.h>
#include <wx/socket.h>
#include "../md5.h"
#include <log4cpp/Category.hh>

PlayListItemPJLink::PlayListItemPJLink(wxXmlNode* node) : PlayListItem(node)
{
    _command = "";
    _parameter = "1";
    _projector = "";
    _started = false;
    PlayListItemPJLink::Load(node);
}

void PlayListItemPJLink::Load(wxXmlNode* node)
{
    PlayListItem::Load(node);
    _command = node->GetAttribute("Command", "");
    _parameter = node->GetAttribute("Parameter", "1");
    _projector = node->GetAttribute("Projector", "1");
}

PlayListItemPJLink::PlayListItemPJLink() : PlayListItem()
{
    _command = "";
    _parameter = "1";
    _projector = "";
    _started = false;
}

PlayListItem* PlayListItemPJLink::Copy() const
{
    PlayListItemPJLink* res = new PlayListItemPJLink();
    res->_command = _command;
    res->_parameter = _parameter;
    res->_projector = _projector;
    PlayListItem::Copy(res);

    return res;
}

wxXmlNode* PlayListItemPJLink::Save()
{
    wxXmlNode * node = new wxXmlNode(nullptr, wxXML_ELEMENT_NODE, "PLIPJLink");

    node->AddAttribute("Projector", _projector);
    node->AddAttribute("Command", _command);
    node->AddAttribute("Parameter", _parameter);
    PlayListItem::Save(node);

    return node;
}

void PlayListItemPJLink::Configure(wxNotebook* notebook)
{
    notebook->AddPage(new PlayListItemPJLinkPanel(notebook, this), "PJLink", true);
}

std::string PlayListItemPJLink::GetName() const
{
    if (_command == "")
    {
        return "PJLink";
    }
    else
    {
        return _command;
    }
}

void PlayListItemPJLink::Frame(wxByte* buffer, size_t size, size_t ms, size_t framems)
{
    if (ms >= _delay && !_started)
    {
        _started = true;
        ExecutePJLinkCommand();
    }
}

void PlayListItemPJLink::Start()
{
    _started = false;
}

void PlayListItemPJLink::ExecutePJLinkCommand()
{
    Login();
    if (_command == "Power On")
    {
        SendCommand("%1POWER 1\r");
    }
    else if (_command == "Power Off")
    {
        SendCommand("%1POWER 0\r");
    }
    else if (_command == "Change Input to RGB")
    {
        SendCommand("%1INPUT 1"+_parameter+"\r");
    }
    else if (_command == "Change Input to VIDEO")
    {
        SendCommand("%1INPUT 2" + _parameter + "\r");
    }
    else if (_command == "Change Input to DIGITAL")
    {
        SendCommand("%1INPUT 3" + _parameter + "\r");
    }
    else if (_command == "Change Input to STORAGE")
    {
        SendCommand("%1INPUT 4" + _parameter + "\r");
    }
    else if (_command == "Change Input to NETWORK")
    {
        SendCommand("%1INPUT 5" + _parameter + "\r");
    }
    else if (_command == "Video Mute On")
    {
        SendCommand("%1AVMT 11\r");
    }
    else if (_command == "Video Mute Off")
    {
        SendCommand("%1AVMT 10\r");
    }
    else if (_command == "Audio Mute On")
    {
        SendCommand("%1AVMT 21\r");
    }
    else if (_command == "Audio Mute Off")
    {
        SendCommand("%1AVMT 20\r");
    }
    Logout();
}

std::list<std::string> PlayListItemPJLink::GetProjectors()
{
    return xScheduleFrame::GetScheduleManager()->GetOptions()->GetProjectors();
}

bool PlayListItemPJLink::Login()
{
    Logout();

    _hash = "";

    ScheduleOptions* options = xScheduleFrame::GetScheduleManager()->GetOptions();

    std::string ip = options->GetProjectorIpAddress(_projector);
    std::string password = options->GetProjectorPassword(_projector);

    if (ip == "") return false;

    static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    logger_base.info("PJLink logging into %s.", (const char*)ip.c_str());

    wxIPV4address address;
    address.Hostname(ip);
    address.Service(4352);
    _socket = new wxSocketClient();
    if (_socket != nullptr)
    {
        if (_socket->Connect(address, false))
        {
            logger_base.info("PJLink connected.");

            _socket->WaitForRead(2);
            if (_socket->IsData())
            {
                wxCharBuffer buffer(100);
                _socket->ReadMsg(buffer.data(), buffer.length());

                wxString response(buffer);
                logger_base.info("PJLink response %s.", (const char*)response.c_str());

                if  (response.Left(8) == "PJLINK 0")
                {
                    // no security
                    logger_base.info("PJLink No Security.");
                    return true;
                }
                else if (response.Left(8) == "PJLINK 1")
                {
                    wxString random = response.SubString(9, response.size());
                    if (random.Right(1) == '\r') random = random.Left(random.size() - 1);

                    logger_base.info("PJLink random %s.", (const char*)random.c_str());

                    random = random + " " + password;

                    _hash = md5(random.ToStdString());

                    logger_base.info("PJLink session hash %s.", (const char*)_hash.c_str());
                }
            }
            else
            {
                // timeout
                logger_base.error("PJLink no response.");
                _socket->Close();
                delete _socket;
                _socket = nullptr;
            }
        }
        else
        {
            logger_base.error("PJLink refused connection.");
            delete _socket;
            _socket = nullptr;
        }
    }

    return _socket != nullptr;
}

bool PlayListItemPJLink::SendCommand(const std::string& command)
{
    if (_socket == nullptr) return false;

    std::string cmd = _hash + command;

    static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    logger_base.info("PJLink sending command %s.", (const char*)cmd.c_str());

    _socket->Write(cmd.c_str(), cmd.size());

    _socket->WaitForRead(2);
    while (_socket->IsData())
    {
        wxCharBuffer buffer(100);
        _socket->ReadMsg(buffer.data(), buffer.length());
        wxString response(buffer);
        logger_base.info("PJLink response %s.", (const char*)response.c_str());
    }
}

void PlayListItemPJLink::Logout()
{
    if (_socket == nullptr) return;

    static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    logger_base.info("PJLink logging out.");

    _socket->Close();
    delete _socket;
    _socket = nullptr;
    _hash = "";
}
