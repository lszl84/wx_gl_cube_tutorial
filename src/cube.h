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

        // left
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // 8
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // 9
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,   // 10
        -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,  // 11

        // right
        0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, // 12
        0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f,  // 13
        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,   // 14
        0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f,  // 15

        // back
        -0.5f, -0.5f, 0.5f, 0.7f, 0.7f, 0.7f, // 16
        0.5f, -0.5f, 0.5f, 0.7f, 0.7f, 0.7f,  // 17
        0.5f, 0.5f, 0.5f, 0.7f, 0.7f, 0.7f,   // 18
        -0.5f, 0.5f, 0.5f, 0.7f, 0.7f, 0.7f,  // 19

        // bottom
        -0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f, // 20
        0.5f, -0.5f, 0.5f, 0.3f, 0.3f, 0.3f,  // 21
        0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f, // 22
        -0.5f, -0.5f, -0.5f, 0.3f, 0.3f, 0.3f // 23
    };

    static constexpr auto triangleVertexIndices = std::array{
        // front
        0, 1, 2, // first triangle
        2, 3, 0, // second triangle

        // top
        4, 5, 6, // first triangle
        6, 7, 4, // second triangle

        // left
        8, 9, 10,  // first triangle
        10, 11, 8, // second triangle

        // right
        12, 13, 14, // first triangle
        14, 15, 12, // second triangle

        // back
        16, 17, 18, // first triangle
        18, 19, 16, // second triangle

        // bottom
        20, 21, 22, // first triangle
        22, 23, 20  // second triangle
    };
};