#include "DimmingCurvePanel.h"
#include "DrawGLUtils.h"


BEGIN_EVENT_TABLE(DimmingCurvePanel, xlGLCanvas)
EVT_PAINT(DimmingCurvePanel::render)
END_EVENT_TABLE()

DimmingCurvePanel::DimmingCurvePanel(wxWindow* parent,
                                     wxWindowID id,
                                     const wxPoint& pos,
                                     const wxSize& size,
                                     long style,
                                     const wxString& name,
                                     int glFlags[])
    : xlGLCanvas(parent, id, pos, size, style, "DimmingCurve-" + name, true), curve(nullptr), channel(0)
{
}

DimmingCurvePanel::~DimmingCurvePanel()
{
    if (curve != nullptr) {
        delete curve;
    }
}

void DimmingCurvePanel::SetDimmingCurve(DimmingCurve *c, int ch) {
    if (curve != nullptr) {
        delete curve;
    }
    curve = c;
    channel = ch;
    Refresh();
    Update();
}

void DimmingCurvePanel::InitializeGLCanvas() {
    if(!IsShownOnScreen()) return;
    SetCurrentGLContext();

    LOG_GL_ERRORV(glClearColor(0.0f, 0.0f, 0.0f, 0.0f)); // Black Background
    LOG_GL_ERRORV(glEnable(GL_BLEND));
    LOG_GL_ERRORV(glDisable(GL_DEPTH_TEST));
    LOG_GL_ERRORV(glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA));
    LOG_GL_ERRORV(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    prepare2DViewport(0,0,mWindowWidth, mWindowHeight);
    mIsInitialized = true;
}
void DimmingCurvePanel::render(wxPaintEvent& event) {
    if(!mIsInitialized) { InitializeGLCanvas(); }
    if(!IsShownOnScreen()) return;
    wxPaintDC(this);
    SetCurrentGLContext();

    LOG_GL_ERRORV(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    if( mWindowResized )
    {
        prepare2DViewport(0,0,mWindowWidth, mWindowHeight);
    }

    DrawGLUtils::xlVertexAccumulator va;
    va.PreAlloc(16);
    va.AddVertex(2,2);
    va.AddVertex(mWindowWidth-2,2);

    va.AddVertex(2,2);
    va.AddVertex(2,mWindowWidth-2);
    va.AddVertex(mWindowWidth-2,2);
    va.AddVertex(mWindowWidth-2,mWindowHeight-2);
    va.AddVertex(2,mWindowHeight-2);
    va.AddVertex(mWindowWidth-2,mWindowHeight-2);

    va.AddVertex(mWindowWidth-2,2);
    va.AddVertex(2,mWindowHeight-2);
    LOG_GL_ERRORV(glLineWidth(0.5));
    DrawGLUtils::Draw(va, xlLIGHT_GREY, GL_LINES);


    va.Reset();
    if (curve != nullptr) {
        va.PreAlloc(256);

        for (int x = 0; x < 255; x++) {
            xlColor c(x,x,x);
            curve->apply(c);

            float xpos = float(x) * float(mWindowWidth - 4.0) / 255.0 + 2.0;
            float ypos = c.Red();
            switch (channel) {
                case 0:
                    ypos = c.Red();
                    break;
                case 1:
                    ypos = c.Green();
                    break;
                case 2:
                    ypos = c.Blue();
                    break;
            }

            ypos = mWindowHeight - 2 - ypos * float(mWindowHeight - 4.0) / 255.0;
            va.AddVertex(xpos, ypos);
        }
        
        DrawGLUtils::Draw(va, xlYELLOW, GL_LINE_STRIP);
    }
    SwapBuffers();
}
