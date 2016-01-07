#ifndef SHOCKWAVEEFFECT_H
#define SHOCKWAVEEFFECT_H

#include "RenderableEffect.h"


class ShockwaveEffect : public RenderableEffect
{
    public:
        ShockwaveEffect(int id);
        virtual ~ShockwaveEffect();
    
        virtual void Render(Effect *effect, const SettingsMap &settings, RenderBuffer &buffer);
        virtual int DrawEffectBackground(const Effect *e, int x1, int y1, int x2, int y2);

    protected:
        virtual wxPanel *CreatePanel(wxWindow *parent);
    private:
};

#endif // SHOCKWAVEEFFECT_H
