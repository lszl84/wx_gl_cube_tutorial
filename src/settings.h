#pragma once

struct Settings
{
    enum class ZBufferOrder
    {
        Less,
        Greater
    };

    enum class FaceCulling
    {
        Front,
        Back
    };

    bool zBufferEnabled{true}, faceCullingEnabled{true};

    ZBufferOrder zBufferOrder{ZBufferOrder::Less};
    FaceCulling faceCulling{FaceCulling::Back};
};