#pragma once

#include <wx/wx.h>
#include <GL/glew.h> // must be included before glcanvas.h
#include <wx/glcanvas.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "cube.h"
#include "settings.h"

class OpenGLCanvas : public wxGLCanvas
{
public:
    OpenGLCanvas(wxWindow *parent, const wxGLAttributes &canvasAttrs, const Settings &settings);
    ~OpenGLCanvas();

    bool InitializeOpenGLFunctions();
    bool InitializeOpenGL();

    void OnPaint(wxPaintEvent &event);
    void OnSize(wxSizeEvent &event);

    void OnKeyDown(wxKeyEvent &event);

    Settings GetSettings() const
    {
        return settings;
    }

    void SetSettings(const Settings &settings)
    {
        this->settings = settings;
        UpdateOpenGLSettings();
    }

private:
    wxGLContext *openGLContext;
    bool isOpenGLInitialized{false};

    float angley{0.0f};
    float anglex{0.0f};

    Cube s{};
    Settings settings{};

    void UpdateOpenGLSettings();

    unsigned int VAO, VBO, EBO, shaderProgram;
};