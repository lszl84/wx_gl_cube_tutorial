#include <wx/wx.h>

#include "cube.h"
#include "settings.h"
#include "settingspanel.h"
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
    SettingsPanel *settingsPanel{nullptr};
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

        settingsPanel = new SettingsPanel(this);
        settingsPanel->SetMinSize(FromDIP(wxSize(200, 600)));

        openGLCanvas = new OpenGLCanvas(this, vAttrs, settingsPanel->GetSettings());
        openGLCanvas->SetMinSize(FromDIP(wxSize(600, 600)));
        openGLCanvas->SetFocus();

        sizer->Add(openGLCanvas, 1, wxEXPAND);
        sizer->Add(settingsPanel, 0, wxEXPAND);

        SetSizerAndFit(sizer);

        settingsPanel->Bind(SETTINGS_CHANGED_EVENT, [this](wxCommandEvent &event)
                            {
                                openGLCanvas->SetSettings(settingsPanel->GetSettings());
                                openGLCanvas->Refresh(); });

        openGLCanvas->Bind(wxEVT_ENTER_WINDOW, [this](wxMouseEvent &event)
                           { openGLCanvas->SetFocus(); });
    }
}
