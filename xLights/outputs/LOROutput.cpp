#include "LOROutput.h"

#include <wx/xml/xml.h>

#pragma region Constructors and Destructors
LOROutput::LOROutput(SerialOutput* output) : SerialOutput(output)
{
    _lastheartbeat = -1;
    memset(_data, 0, sizeof(_data));
}

LOROutput::LOROutput(wxXmlNode* node) : SerialOutput(node)
{
    _lastheartbeat = -1;
    memset(_data, 0, sizeof(_data));
}

LOROutput::LOROutput() : SerialOutput()
{
    _lastheartbeat = -1;
    memset(_data, 0, sizeof(_data));
}
#pragma endregion Constructors and Destructors

void LOROutput::SendHeartbeat() const
{
    if (!_enabled || _serial == nullptr || !_ok) return;

    wxByte d[5];
    d[0] = 0;
    d[1] = 0xFF;
    d[2] = 0x81;
    d[3] = 0x56;
    d[4] = 0;
    _serial->Write((char *)d, 5);
}

#pragma region Start and Stop
bool LOROutput::Open()
{
    _ok = SerialOutput::Open();

    for (size_t i = 0; i <= 255; i++)
    {
        int temp = (int)(100.0*(double)i / (double)255 + 0.5);
        switch (temp)
        {
        case 0:
            _data[i] = 0xF0;
            break;
        case 100:
            _data[i] = 0x01;
            break;
        default:
            _data[i] = 228 - temp * 2;
            break;
        }
    }

    return _ok;
}
#pragma endregion Start and Stop

#pragma region Frame Handling
void LOROutput::EndFrame()
{
    if (!_enabled) return;

    // send heartbeat
    if (_timer_msec > _lastheartbeat + 300 || _timer_msec < _lastheartbeat || _lastheartbeat < 0)
    {
        SendHeartbeat();
        _lastheartbeat = _timer_msec;
    }
}

void LOROutput::ResetFrame()
{
    _lastheartbeat = -1;
}
#pragma endregion Frame Handling

#pragma region Data Setting
void LOROutput::SetOneChannel(long channel, unsigned char data)
{
    if (!_enabled || _serial == nullptr || !_ok) return;

    wxByte d[6];
    d[0] = 0;
    d[1] = channel >> 4;
    if (d[1] < 0xF0) d[1]++;
    d[2] = 3;
    d[3] = _data[data];
    d[4] = 0x80 | (channel % 16);
    d[5] = 0;

    _serial->Write((char *)d, 6);
}

void LOROutput::AllOff()
{
    for (int i = 0; i < _channels; i++)
    {
        SetOneChannel(i, 0x00);
    }
    wxMilliSleep(25);
}
#pragma endregion Data Setting

#pragma region Getters and Setters
std::string LOROutput::GetSetupHelp() const
{
    return "LOR controllers attached to any LOR dongle.\nMax of 8 channels at 9600 baud.\nMax of 48 channels at 57600 baud.\nMax of 96 channels at 115200 baud.\nRun your controllers in DMX mode for higher throughput.";
}
#pragma endregion Getters and Setters
