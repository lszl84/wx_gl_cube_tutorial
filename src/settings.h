#pragma once

struct Settings
{
    enum class ZBufferOrder
    {
        Less,
        Greater
    };

    bool zBufferEnabled{true};

    ZBufferOrder zBufferOrder{ZBufferOrder::Less};
};