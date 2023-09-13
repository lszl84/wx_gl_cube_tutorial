#pragma once

#include <array>

struct Cube
{
    static constexpr auto xyzArray = std::array{
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f};

    static constexpr auto triangleVertexIndices = std::array{
        0, 1, 2, // first triangle
        2, 3, 0, // second triangle
    };
};