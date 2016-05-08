#ifndef MUSICEFFECT_H
#define MUSICEFFECT_H

#include "RenderableEffect.h"
#include "../RenderBuffer.h"
#include <string>
#include <list>
#include <vector>

class MusicEvent;

class MusicEffect : public RenderableEffect
{
    public:
        MusicEffect(int id);
        virtual ~MusicEffect();
        virtual void Render(Effect *effect, const SettingsMap &settings, RenderBuffer &buffer) override;
        void Render(RenderBuffer &buffer,
                    int bars, const std::string& type, int sensitivity, bool scale, const std::string& scalenotes, int offsetx, int startnote, int endnote, const std::string& colourtreatment, bool fade);
	protected:
        void CreateEvents(RenderBuffer& buffer, std::vector<std::list<MusicEvent*>*>& events, int startNote, int endNote, int bars, int scalenotes, int sensitivity);
        virtual wxPanel *CreatePanel(wxWindow *parent) override;
		int DecodeType(const std::string& type);
        int DecodeColourTreatment(const std::string& colourtreatment);
        void RenderMorph(RenderBuffer &buffer, int x, int bars, int startNote, int endNote, std::list<MusicEvent*>& events, int colourTreatment, bool bounce, bool fade);
        void RenderCollide(RenderBuffer &buffer, int x, int bars, int startNote, int endNote, bool in, std::list<MusicEvent*>& events, int colourTreatment, bool fade);
        void RenderOn(RenderBuffer &buffer, int x, int bars, int startNote, int endNote, std::list<MusicEvent*>& events, int colourTreatment, bool fade);
        int DecodeScaleNotes(const std::string& scalenotes);
        virtual bool needToAdjustSettings(const std::string& version) override;
        virtual void adjustSettings(const std::string &version, Effect *effect) override;
};

#endif // MUSICEFFECT_H
