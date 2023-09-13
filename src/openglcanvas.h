#pragma once

#include <wx/wx.h>
#include <GL/glew.h> // must be included before glcanvas.h
#include <wx/glcanvas.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "cube.h"

class OpenGLCanvas : public wxGLCanvas
{
public:
    OpenGLCanvas(wxWindow *parent, const wxGLAttributes &canvasAttrs);
    ~OpenGLCanvas();

    bool InitializeOpenGLFunctions();
    bool InitializeOpenGL();

    void OnPaint(wxPaintEvent &event);
    void OnSize(wxSizeEvent &event);

    void OnKeyDown(wxKeyEvent &event);

private:
    wxGLContext *openGLContext;
    bool isOpenGLInitialized{false};

    float angley{0.0f};
    float anglex{0.0f};

    Cube s{};

    unsigned int VAO, VBO, EBO, shaderProgram;
};