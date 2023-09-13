#include <wx/wx.h>

#include "cube.h"
#include "openglcanvas.h"

class MyApp : public wxApp
{
public:
    MyApp() {}
    bool OnInit() wxOVERRIDE;
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title);

private:
    OpenGLCanvas *openGLCanvas{nullptr};
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    MyFrame *frame = new MyFrame("Hello OpenGL");
    frame->Show(true);

    return true;
}

MyFrame::MyFrame(const wxString &title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    wxGLAttributes vAttrs;
    vAttrs.PlatformDefaults().Defaults().EndList();

    if (wxGLCanvas::IsDisplaySupported(vAttrs))
    {
        auto sizer = new wxBoxSizer(wxHORIZONTAL);

        openGLCanvas = new OpenGLCanvas(this, vAttrs);
        openGLCanvas->SetMinSize(FromDIP(wxSize(600, 600)));
        openGLCanvas->SetFocus();

        sizer->Add(openGLCanvas, 1, wxEXPAND);

        SetSizerAndFit(sizer);
    }
}
