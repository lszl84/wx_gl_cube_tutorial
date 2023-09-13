#pragma once

#include <array>

struct Cube
{
    static constexpr auto xyzArray = std::array{
        // front
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // 0
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  // 1
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,   // 2
        -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  // 3

        // top
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // 4
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // 5
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,   // 6
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,  // 7

    };

    static constexpr auto triangleVertexIndices = std::array{
        // front
        0, 1, 2, // first triangle
        2, 3, 0, // second triangle

        // top
        4, 5, 6, // first triangle
        6, 7, 4, // second triangle
    };
};