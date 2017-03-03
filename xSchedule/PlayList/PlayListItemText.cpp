#include "PlayListItemText.h"
#include <wx/xml/xml.h>
#include <wx/notebook.h>
#include "PlayListItemTextPanel.h"
#include <log4cpp/Category.hh>
#include <wx/font.h>
#include "../FSEQFile.h"
#include "../MatrixMapper.h"
#include "../xScheduleMain.h"
#include "../ScheduleManager.h"
#include "../ScheduleOptions.h"

PlayListItemText::PlayListItemText(wxXmlNode* node) : PlayListItem(node)
{
    _font = nullptr;
    _blendMode = APPLYMETHOD::METHOD_OVERWRITEIFBLACK;
    _colour = *wxWHITE;
    _durationMS = 50;
    _font = new wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL , wxFONTWEIGHT_NORMAL);
    _format = "";
    _text = "";
    _matrix = "";
    _movement = "None";
    _orientation = "Normal";
    _speed = 10;
    _type = "Normal";
    _x = 0;
    _y = 0;
    _maxSize = wxSize(0,0);

    PlayListItemText::Load(node);
}

PlayListItemText::~PlayListItemText()
{
    if (_font != nullptr)
    {
        delete _font;
        _font = nullptr;
    }
}

void PlayListItemText::Load(wxXmlNode* node)
{
    PlayListItem::Load(node);
    _blendMode = (APPLYMETHOD)wxAtoi(node->GetAttribute("ApplyMethod", "1"));
    _colour = wxColour(node->GetAttribute("Colour", "WHITE"));
    _durationMS = wxAtol(node->GetAttribute("Duration", "50"));
    auto font = wxFont(node->GetAttribute("Font", ""));
    if (_font != nullptr)
    {
        delete _font;
        _font = nullptr;
    }
    _font = new wxFont(font.GetPointSize(), font.GetFamily(), font.GetStyle(), font.GetWeight(), font.GetUnderlined(), font.GetFaceName(), font.GetEncoding());
    wxASSERT(_font->IsOk());
    _format = node->GetAttribute("Format", "").ToStdString();
    _text = node->GetAttribute("Text", "").ToStdString();
    _matrix = node->GetAttribute("Matrix", "").ToStdString();
    _movement = node->GetAttribute("Movement", "None").ToStdString();
    _orientation = node->GetAttribute("Orientation", "Normal").ToStdString();
    _type = node->GetAttribute("Type", "Normal").ToStdString();
    _speed = wxAtoi(node->GetAttribute("Speed", "10"));
    _x = wxAtoi(node->GetAttribute("X", "0"));
    _y = wxAtoi(node->GetAttribute("Y", "0"));
}

void PlayListItemText::SetFont(wxFont* font)
{
    if (_font->GetPointSize() != font->GetPointSize() ||
        _font->GetFamily() != font->GetFamily() ||
        _font->GetStyle() != font->GetStyle() ||
        _font->GetWeight() != font->GetWeight() ||
        _font->GetUnderlined() != font->GetUnderlined() ||
        _font->GetFaceName() != font->GetFaceName() ||
        _font->GetEncoding() != font->GetEncoding()
        )
    {
        if (_font != nullptr)
        {
            delete _font;
            _font = nullptr;
        }
        _font = new wxFont(font->GetPointSize(), font->GetFamily(), font->GetStyle(), font->GetWeight(),
            font->GetUnderlined(), font->GetFaceName(), font->GetEncoding());
        wxASSERT(_font->IsOk());

        _changeCount++; 
    }
}

PlayListItemText::PlayListItemText() : PlayListItem()
{
    _font = nullptr;
    _matrixMapper = nullptr;
    _blendMode = APPLYMETHOD::METHOD_OVERWRITEIFBLACK;
    _colour = *wxWHITE;
    _durationMS = 50;
    _font = new wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    _format = "";
    _text = "";
    _matrix = "";
    _movement = "None";
    _orientation = "Normal";
    _speed = 10;
    _type = "Normal";
    _x = 0;
    _y = 0;
    _maxSize = wxSize(0, 0);
}

PlayListItem* PlayListItemText::Copy() const
{
    PlayListItemText* res = new PlayListItemText();
    res->_matrix = _matrix;
    res->_movement = _movement;
    res->_orientation = _orientation;
    res->_speed = _speed;
    res->_durationMS = _durationMS;
    res->_type = _type;
    res->_x = _x;
    res->_y = _y;
    res->_blendMode = _blendMode;
    res->_colour = _colour;
    res->_font = new wxFont(_font->GetPointSize(), _font->GetFamily(), _font->GetStyle(), _font->GetWeight(),
        _font->GetUnderlined(), _font->GetFaceName(), _font->GetEncoding());
    res->_format = _format;
    res->_text = _text;
    PlayListItem::Copy(res);

    return res;
}

wxXmlNode* PlayListItemText::Save()
{
    wxXmlNode * node = new wxXmlNode(nullptr, wxXML_ELEMENT_NODE, "PLIText");

    node->AddAttribute("ApplyMethod", wxString::Format(wxT("%i"), (int)_blendMode));
    node->AddAttribute("Colour", _colour.GetAsString());
    node->AddAttribute("Duration", wxString::Format(wxT("%i"), (long)_durationMS));
    node->AddAttribute("Font", _font->GetNativeFontInfoDesc());
    node->AddAttribute("Format", _format);
    node->AddAttribute("Text", _text);
    node->AddAttribute("Matrix", _matrix);
    node->AddAttribute("Movement", _movement);
    node->AddAttribute("Orientation", _orientation);
    node->AddAttribute("Type", _type);
    node->AddAttribute("Speed", wxString::Format(wxT("%i"), _speed));
    node->AddAttribute("X", wxString::Format(wxT("%i"), _y));
    node->AddAttribute("Y", wxString::Format(wxT("%i"), _x));

    PlayListItem::Save(node);

    return node;
}

void PlayListItemText::Configure(wxNotebook* notebook)
{
    notebook->AddPage(new PlayListItemTextPanel(notebook, this), GetTitle(), true);
}

std::string PlayListItemText::GetTitle() const
{
    return "Text";
}

std::string PlayListItemText::GetNameNoTime() const
{
    if (_name != "")
    {
        return _name;
    }
    if (_format != "")
    {
        return _format;
    }
    else if (_text != "")
    {
        return _text;
    }
    else
    {
        return _type;
    }
}

size_t PlayListItemText::GetDurationMS() const
{
    return _delay + _durationMS;
}

void PlayListItemText::Start()
{
    _maxSize = wxSize(0, 0);
    auto m = xScheduleFrame::GetScheduleManager()->GetOptions()->GetMatrices();
    for (auto it = m->begin(); it != m->end(); ++it)
    {
        if (wxString((*it)->GetName()).Lower() == wxString(_matrix).Lower())
        {
            _matrixMapper = *it;
            break;
        }
    }
}

void PlayListItemText::Stop()
{
}

std::string PlayListItemText::GetText(size_t ms)
{
    wxString working = wxString(_format);

    wxTimeSpan plicountdown = wxTimeSpan::Milliseconds(_durationMS - ms);
    wxTimeSpan plicountup = wxTimeSpan::Milliseconds(ms);
    wxDateTime now = wxDateTime::Now();
    wxTimeSpan countdown;

    if (_type == "Normal")
    {
        // nothing to do
    }
    else if (_type == "Countdown")
    {
        wxDateTime targetDate;
        targetDate.ParseDateTime(_text);
        if (!targetDate.IsValid())
        {
            targetDate.ParseDate(_text);
        }
        if (!targetDate.IsValid())
        {
            targetDate.ParseTime(_text);
            targetDate.SetDay(wxDateTime::Now().GetDay());
            targetDate.SetMonth(wxDateTime::Now().GetMonth());
            targetDate.SetYear(wxDateTime::Now().GetYear());
            if (targetDate.IsValid() && targetDate < wxDateTime::Now())
            {
                targetDate.Add(wxTimeSpan(24, 0, 0, 0));
            }
        }

        if (targetDate.IsValid())
        {
            countdown = targetDate - now;
        }
        else
        {
            countdown = wxTimeSpan(0);
        }
    }

    working.Replace("%TEXT%", _text);

    // countdown to date
    working.Replace("%CDD_DAYS%", wxString::Format(wxT("%i"), countdown.GetDays()));
    working.Replace("%CDD_HOURS%", wxString::Format(wxT("%02i"), abs(countdown.GetHours()) % 24));
    working.Replace("%CDD_MINS%", wxString::Format(wxT("%02i"), abs(countdown.GetMinutes()) % 60));
    working.Replace("%CDD_SECS%", wxString::Format(wxT("%02i"), abs((countdown.GetSeconds() % 60).ToLong())));
    working.Replace("%CDD_TSECS%", wxString::Format(wxT("%i"), abs((countdown.GetMilliseconds() / 1000).ToLong())));
    working.Replace("%CDD_MS%", wxString::Format(wxT("%03i"), abs((countdown.GetMilliseconds() % 1000).ToLong())));

    // countdown to to item end
    working.Replace("%CD_DAYS%", wxString::Format(wxT("%i"), plicountdown.GetDays()));
    working.Replace("%CD_HOURS%", wxString::Format(wxT("%02i"), plicountdown.GetHours() % 24));
    working.Replace("%CD_MINS%", wxString::Format(wxT("%02i"), plicountdown.GetMinutes() % 60));
    working.Replace("%CD_SECS%", wxString::Format(wxT("%02i"), (plicountdown.GetSeconds() % 60).ToLong()));
    working.Replace("%CD_TSECS%", wxString::Format(wxT("%i"), (plicountdown.GetMilliseconds() / 1000).ToLong()));
    working.Replace("%CD_MS%", wxString::Format(wxT("%03i"), (plicountdown.GetMilliseconds() % 1000).ToLong()));

    // countup from item start
    working.Replace("%CU_DAYS%", wxString::Format(wxT("%i"), plicountup.GetDays()));
    working.Replace("%CU_HOURS%", wxString::Format(wxT("%02i"), plicountup.GetHours() % 24));
    working.Replace("%CU_MINS%", wxString::Format(wxT("%02i"), plicountup.GetMinutes() % 60));
    working.Replace("%CU_SECS%", wxString::Format(wxT("%02i"), (plicountup.GetSeconds() % 60).ToLong()));
    working.Replace("%CU_TSECS%", wxString::Format(wxT("%i"), (plicountup.GetMilliseconds() / 1000).ToLong()));
    working.Replace("%CU_MS%", wxString::Format(wxT("%03i"), (plicountup.GetMilliseconds() % 1000).ToLong()));

    // current date time
    working.Replace("%DAY%", wxString::Format(wxT("%02i"), now.GetDay()));
    working.Replace("%MONTH%", wxString::Format(wxT("%02i"), now.GetMonth()+1));
    working.Replace("%YEAR4%", wxString::Format(wxT("%04i"), now.GetYear()));
    working.Replace("%YEAR2%", wxString::Format(wxT("%02i"), now.GetYear() % 100));
    working.Replace("%HOUR24%", wxString::Format(wxT("%02i"), now.GetHour()));
    working.Replace("%HOUR12%", wxString::Format(wxT("%02i"), now.GetHour() % 12));
    working.Replace("%MIN%", wxString::Format(wxT("%02i"), now.GetMinute()));
    working.Replace("%SEC%", wxString::Format(wxT("%02i"), now.GetSecond()));
    working.Replace("%MS%", wxString::Format(wxT("%03i"), now.GetMillisecond()));
    working.Replace("%AMPM%", now.GetHour() > 12 ? "PM" : "AM");

    return working.ToStdString();
}

wxPoint PlayListItemText::GetLocation(size_t ms, wxSize size)
{
    wxPoint res(_x + _matrixMapper->GetWidth() / 2 - size.x / 2, _matrixMapper->GetHeight() + (-1 * _y) - 1 - _matrixMapper->GetHeight() / 2 - size.y/2);

    if (_movement == "None")
    {

    }
    else if (_movement == "Right to Left")
    {
        res.x -= ms * _speed / 1000;

        while (res.x < -1 * size.x)
        {
            // off the left of the screen
            res.x += _matrixMapper->GetWidth() + size.x;
        }
    }
    else if (_movement == "Left to Right")
    {
        res.x += ms * _speed / 1000;

        while (res.x > _matrixMapper->GetWidth())
        {
            res.x -= _matrixMapper->GetWidth() + size.x;
        }
    }
    else if (_movement == "Bottom to Top")
    {
        res.y -= size.y;
        res.y -= ms * _speed / 1000;
        res.y = res.y % (_matrixMapper->GetHeight() + 2 * size.y) + size.y;
        if (res.y < -1 * size.y)
        {
            res.y += _matrixMapper->GetHeight() + 2 * size.y;
        }
    }
    else if (_movement == "Top to Bottom")
    {
        res.y += size.y;
        res.y += ms * _speed / 1000;
        res.y = res.y % (_matrixMapper->GetHeight() + 2 * size.y) - size.y;
    }

    return res;
}

void PlayListItemText::Frame(wxByte* buffer, size_t size, size_t ms, size_t framems, bool outputframe)
{
    static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));

    if (_matrixMapper == nullptr) return;

    if (outputframe && ms > _delay)
    {
        size_t effms = ms - _delay;

        // work out our Text
        std::string text = GetText(effms);

        wxBitmap bitmap(_matrixMapper->GetWidth(), _matrixMapper->GetHeight());
        wxMemoryDC dc(bitmap);

        // draw the text into our DC
        dc.SetTextForeground(_colour);
        dc.SetFont(*_font);
        wxSize sz = dc.GetTextExtent(text);
        if (sz.x > _maxSize.x) _maxSize.x = sz.x;
        if (sz.y > _maxSize.y) _maxSize.y = sz.y;

        if (_orientation == "Normal")
        {
            // work out where to draw it
            wxPoint loc = GetLocation(effms, _maxSize);
            dc.DrawText(text, loc);
        }
        else if (_orientation == "Vertical Up" || _orientation == "Vertical Down")
        {
            // work out where to draw it
            wxSize sz1(_maxSize.GetHeight(), dc.GetCharHeight() * text.size());
            wxPoint loc = GetLocation(effms, sz1);
            int y = loc.y;
            for (auto c = text.begin(); c != text.end(); ++c)
            {
                wxSize cSize = dc.GetTextExtent(*c);
                int xoffset = cSize.GetWidth() / 2;
                dc.DrawText(wxString(*c), loc.x - xoffset, y);
                if (_orientation == "Vertical Down")
                {
                    y += dc.GetCharHeight();
                }
                else
                {
                    y -= dc.GetCharHeight();
                }
            }
        }
        else if (_orientation == "Rotate Up 90")
        {
            wxSize sz1(_maxSize.GetHeight(), _maxSize.GetWidth());
            wxPoint loc = GetLocation(effms, sz1);
            dc.DrawRotatedText(text, loc, 90);
        }
        else if (_orientation == "Rotate Down 90")
        {
            wxSize sz1(_maxSize.GetHeight(), _maxSize.GetWidth());
            wxPoint loc = GetLocation(effms, sz1);
            dc.DrawRotatedText(text, loc, -90);
        }

        // write out the bitmap
        dc.SelectObject(wxNullBitmap);
        wxImage image = bitmap.ConvertToImage();
        for (int x = 0; x < _matrixMapper->GetWidth(); ++x)
        {
            for (int y = 0; y < _matrixMapper->GetHeight(); ++y)
            {
                size_t bl = _matrixMapper->Map(x, _matrixMapper->GetHeight() - y - 1) - 1;

                if (bl < size)
                {
                    wxByte* p = buffer + bl;

                    SetPixel(p, image.GetRed(x, y), image.GetGreen(x, y), image.GetBlue(x, y), _blendMode);
                }
                else
                {
                    wxASSERT(false);
                }
            }
        }
    }
}

void PlayListItemText::SetPixel(wxByte* p, wxByte r, wxByte g, wxByte b, APPLYMETHOD blendMode)
{
    switch (blendMode)
    {
    case APPLYMETHOD::METHOD_OVERWRITE:
        *p = r;
        *(p + 1) = g;
        *(p + 2) = b;
        break;
    case APPLYMETHOD::METHOD_AVERAGE:
        *p = ((int)*p + (int)r) / 2;
        *(p + 1) = ((int)*(p + 1) + (int)g) / 2;
        *(p + 2) = ((int)*(p + 2) + (int)b) / 2;
        break;
    case APPLYMETHOD::METHOD_MASK:
        if (r > 0 || g > 0 || b > 0)
        {
            *p = 0x00;
            *(p + 1) = 0x00;
            *(p + 2) = 0x00;
        }
        break;
    case APPLYMETHOD::METHOD_UNMASK:
        if (r == 0 && g == 0 && b == 0)
        {
            *p = 0x00;
            *(p + 1) = 0x00;
            *(p + 2) = 0x00;
        }
        break;
    case APPLYMETHOD::METHOD_MAX:
        *p = std::max(*p, r);
        *(p + 1) = std::max(*(p + 1), g);
        *(p + 2) = std::max(*(p + 2), b);
        break;
    case APPLYMETHOD::METHOD_OVERWRITEIFBLACK:
        if (*p == 0 && *(p + 1) == 0 && *(p + 2) == 0)
        {
            *p = r;
            *(p+1) = g;
            *(p+2) = b;
        }
        break;
    }
}
