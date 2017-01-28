#include "PlayListItemFSEQVideo.h"
#include "wx/xml/xml.h"
#include <wx/notebook.h>
#include "PlayListItemFSEQVideoPanel.h"
#include "../../xLights/AudioManager.h"
#include <log4cpp/Category.hh>
#include "../../xLights/VideoReader.h"
#include "PlayerWindow.h"

PlayListItemFSEQVideo::PlayListItemFSEQVideo(wxXmlNode* node) : PlayListItem(node)
{
    _window = nullptr;
    _videoFile = "";
    _origin.x = 0;
    _origin.y = 0;
    _size.SetWidth(300);
    _size.SetHeight(300);
    _videoReader = nullptr;    _channels = 0;
    _startChannel = 1;
    _controlsTimingCache = false;
    _applyMethod = APPLYMETHOD::METHOD_OVERWRITE;
    _fseqFileName = "";
    _overrideAudio = false;
    _audioFile = "";
    _durationMS = 0;
    _fseqFile = nullptr;
    _audioManager = nullptr;
    PlayListItemFSEQVideo::Load(node);
}

void PlayListItemFSEQVideo::Load(wxXmlNode* node)
{
    PlayListItem::Load(node);
    _fseqFileName = node->GetAttribute("FSEQFile", "");
    _audioFile = node->GetAttribute("AudioFile", "");
    _overrideAudio = (_audioFile != "");
    _applyMethod = (APPLYMETHOD)wxAtoi(node->GetAttribute("ApplyMethod", ""));
    _fastStartAudio = (node->GetAttribute("FastStartAudio", "FALSE") == "TRUE");
    _videoFile = node->GetAttribute("VideoFile", "");
    _origin = wxPoint(wxAtoi(node->GetAttribute("X", "0")), wxAtoi(node->GetAttribute("Y", "0")));
    _size = wxSize(wxAtoi(node->GetAttribute("W", "100")), wxAtoi(node->GetAttribute("H", "100")));
	
    if (_fastStartAudio)
    {
        LoadAudio();
    }
    else
    {
        FastSetDuration();
    }
}

std::string PlayListItemFSEQVideo::GetAudioFilename() const
{
    if (_overrideAudio)
    {
        return _audioFile;
    }
    else
    {
        if (_fseqFile != nullptr)
        {
            return _fseqFile->GetAudioFileName();
        }
    }

    return "";
}

void PlayListItemFSEQVideo::LoadAudio()
{
    static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    auto af = GetAudioFilename();

    if (_audioManager != nullptr)
    {
        if (_audioManager->FileName() == af)
        {
            // already open
            return;
        }
        else
        {
            delete _audioManager;
            _audioManager = nullptr;
        }
    }

    if (wxFile::Exists(af))
    {
        _audioManager = new AudioManager(af);

        if (!_audioManager->IsOk())
        {
            logger_base.error("FSEQ: Audio file '%s' has a problem opening.", (const char *)af.c_str());
        }

        if (_volume != -1)
            _audioManager->SetVolume(_volume);
        _durationMS = _audioManager->LengthMS();
        _controlsTimingCache = true;
    }
    else
    {
        if (af != "")
        {
            logger_base.error("FSEQ: Audio file '%s' cannot be opened because it does not exist.", (const char *)af.c_str());
        }
    }
}

void PlayListItemFSEQVideo::LoadFiles()
{
    CloseFiles();

    if (wxFile::Exists(_fseqFileName))
    {
        _fseqFile = new FSEQFile();
        _fseqFile->Load(_fseqFileName);
        _msPerFrame = _fseqFile->GetFrameMS();
        _durationMS = _fseqFile->GetLengthMS();
    }

	_videoReader = new VideoReader(_videoFile, _size.GetWidth(), _size.GetHeight(), false);
		
    LoadAudio();
}

PlayListItemFSEQVideo::PlayListItemFSEQVideo() : PlayListItem()
{
    _fastStartAudio = false;
    _channels = 0;
    _startChannel = 1;
    _controlsTimingCache = false;
    _applyMethod = APPLYMETHOD::METHOD_OVERWRITE;
    _fseqFileName = "";
    _overrideAudio = false;
    _audioFile = "";
    _durationMS = 0;
    _audioManager = nullptr;
    _fseqFile = nullptr;
    _window = nullptr;
    _videoFile = "";
    _origin.x = 0;
    _origin.y = 0;
    _size.SetWidth(300);
    _size.SetHeight(300);
    _videoReader = nullptr;}

PlayListItem* PlayListItemFSEQVideo::Copy() const
{
    PlayListItemFSEQVideo* res = new PlayListItemFSEQVideo();
    res->_fseqFileName = _fseqFileName;
    res->_applyMethod = _applyMethod;
    res->_overrideAudio = _overrideAudio;
    res->_durationMS = _durationMS;
    res->_controlsTimingCache = _controlsTimingCache;
    res->_channels = _channels;
    res->_startChannel = _startChannel;
    res->_fastStartAudio = _fastStartAudio;
    res->_origin = _origin;
    res->_size = _size;
    res->_videoFile = _videoFile;
    res->SetAudioFile(_audioFile); // this will trigger file loading
    PlayListItem::Copy(res);

    return res;
}

wxXmlNode* PlayListItemFSEQVideo::Save()
{
    wxXmlNode * node = new wxXmlNode(nullptr, wxXML_ELEMENT_NODE, "PLIFSEQVideo");

    node->AddAttribute("FSEQFile", _fseqFileName);
    node->AddAttribute("ApplyMethod", wxString::Format(wxT("%i"), (int)_applyMethod));
    node->AddAttribute("VideoFile", _videoFile);
    node->AddAttribute("X", wxString::Format(wxT("%i"), _origin.x));
    node->AddAttribute("Y", wxString::Format(wxT("%i"), _origin.y));
    node->AddAttribute("W", wxString::Format(wxT("%i"), _size.GetWidth()));
    node->AddAttribute("H", wxString::Format(wxT("%i"), _size.GetHeight()));
	
    if (_fastStartAudio)
    {
        node->AddAttribute("FastStartAudio", "TRUE");
    }

    if (_overrideAudio)
    {
        node->AddAttribute("AudioFile", _audioFile);
    }

    PlayListItem::Save(node);

    return node;
}

std::string PlayListItemFSEQVideo::GetTitle() const
{
    return "FSEQ & Video";
}

void PlayListItemFSEQVideo::Configure(wxNotebook* notebook)
{
    notebook->AddPage(new PlayListItemFSEQVideoPanel(notebook, this), GetTitle(), true);
}

std::string PlayListItemFSEQVideo::GetNameNoTime() const
{
    wxFileName fn(_fseqFileName);
    if (fn.GetName() == "")
    {
        return "FSEQ & Video";
    }
    else
    {
        return fn.GetName().ToStdString();
    }
}

void PlayListItemFSEQVideo::SetFSEQFileName(const std::string& fseqFileName)
{
    if (_fseqFileName != fseqFileName)
    {
        _fseqFileName = fseqFileName;
        if (_fastStartAudio)
        {
            LoadAudio();
        }
        else
        {
            FastSetDuration();
        }
        _changeCount++;
    }
}

void PlayListItemFSEQVideo::SetVideoFile(const std::string& videoFile) 
{ 
    if (_videoFile != videoFile)
    {
        _videoFile = videoFile;
        _changeCount++;
    }
}

void PlayListItemFSEQVideo::SetAudioFile(const std::string& audioFile)
{
    if (_audioFile != audioFile)
    {
        _audioFile = audioFile;
        _changeCount++;
        if (_fastStartAudio)
        {
            LoadAudio();
        }
        else
        {
            FastSetDuration();
        }
    }
}

void PlayListItemFSEQVideo::SetOverrideAudio(bool overrideAudio)
{
    if (_overrideAudio != overrideAudio)
    {
        _overrideAudio = overrideAudio;
        _changeCount++;
        if (_fastStartAudio)
        {
            LoadAudio();
        }
        else
        {
            FastSetDuration();
        }
    }
}

void PlayListItemFSEQVideo::SetFastStartAudio(bool fastStartAudio)
{
    if (_fastStartAudio != fastStartAudio)
    {
        _fastStartAudio = fastStartAudio;
        _changeCount++;
        if (_fastStartAudio)
        {
            LoadAudio();
        }
        else
        {
            if (_audioManager != nullptr)
            {
                delete _audioManager;
                _audioManager = nullptr;
            }
        }
    }
}

void PlayListItemFSEQVideo::FastSetDuration()
{
    _controlsTimingCache = false;
    std::string af = GetAudioFile();
    if (af == "")
    {
        FSEQFile fseq(_fseqFileName);

        af = fseq.GetAudioFileName();

        if (!_overrideAudio && af != "" && wxFile::Exists(af))
        {
            _durationMS = AudioManager::GetAudioFileLength(fseq.GetAudioFileName());
            _controlsTimingCache = true;
        }
        else
        {
            _durationMS = fseq.GetLengthMS();
        }
    }
    else
    {
        _durationMS = AudioManager::GetAudioFileLength(GetAudioFilename());
        _controlsTimingCache = true;
    }
}

size_t PlayListItemFSEQVideo::GetPositionMS() const
{
    if (ControlsTiming() && _audioManager != nullptr)
    {
        return _audioManager->Tell();
    }

    return 0;
}

wxImage PlayListItemFSEQVideo::CreateImageFromFrame(AVFrame* frame)
{
    if (frame != NULL)
    {
        wxImage img(frame->width, frame->height, (unsigned char *)frame->data[0], true);
        img.SetType(wxBitmapType::wxBITMAP_TYPE_BMP);
        return img;
    }
    else
    {
        wxImage img(_size.x, _size.y, true);
        return img;
    }
}

void PlayListItemFSEQVideo::Frame(wxByte* buffer, size_t size, size_t ms, size_t framems, bool outputframe)
{
    if (outputframe)
    {
        if (_channels > 0)
        {
            wxASSERT(_startChannel > 0);
            _fseqFile->ReadData(buffer, size, ms / framems, _applyMethod, _startChannel - 1, _channels);
        }
        else
        {
            _fseqFile->ReadData(buffer, size, ms / framems, _applyMethod, 0, 0);
        }
    }
	
    AVFrame* img = _videoReader->GetNextFrame(ms, framems);
    _window->SetImage(CreateImageFromFrame(img));
}

void PlayListItemFSEQVideo::Restart()
{
    if (ControlsTiming() && _audioManager != nullptr)
    {
        _audioManager->Stop();
        _audioManager->Play(0, _audioManager->LengthMS());
    }
}

void PlayListItemFSEQVideo::Start()
{
    // load the FSEQ
    // load the audio
    LoadFiles();

    if (ControlsTiming() && _audioManager != nullptr)
    {
        _audioManager->Play(0, _audioManager->LengthMS());
    }

    // create the window
    if (_window == nullptr)
    {
        _window = new PlayerWindow(nullptr, wxID_ANY, _origin, _size);
    }
    else
    {
        _window->Move(_origin);
        _window->SetSize(_size);
    }
}

void PlayListItemFSEQVideo::Suspend(bool suspend)
{
    Pause(suspend);

    if (suspend)
    {
        if (_window != nullptr) _window->Hide();
    }
    else
    {
        if (_window != nullptr) _window->Show();
    }
}

void PlayListItemFSEQVideo::Pause(bool pause)
{
    if (ControlsTiming() && _audioManager != nullptr)
    {
        if (pause)
        {
            _audioManager->Pause();
        }
        else
        {
            _audioManager->Play();
        }
    }
}

void PlayListItemFSEQVideo::Stop()
{
    if (_audioManager != nullptr)
    {
        _audioManager->Stop();
    }
    CloseFiles();

    // destroy the window
    if (_window != nullptr)
    {
        delete _window;
        _window = nullptr;
    }
}

void PlayListItemFSEQVideo::CloseFiles()
{
    if (_fseqFile != nullptr)
    {
        _fseqFile->Close();
        delete _fseqFile;
        _fseqFile = nullptr;
    }

    if (_audioManager != nullptr)
    {
        delete _audioManager;
        _audioManager = nullptr;
    }

	if (_videoReader != nullptr)
    {
        delete _videoReader;
        _videoReader = nullptr;
    }
}

PlayListItemFSEQVideo::~PlayListItemFSEQVideo()
{
    CloseFiles();
	
    if (_window != nullptr)
    {
        delete _window;
        _window = nullptr;
    }
}
