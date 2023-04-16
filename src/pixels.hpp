#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r, g, b, a;
};

struct RGB
{
    uint8_t r, g, b;
};

struct Luma
{
    uint8_t gray;
};

template <typename A, typename B>
A from(const B&);

template <>
RGB from(const RGBA& x)
{
    return RGB { x.r, x.g, x.b };
}

template <>
RGBA from(const RGB& x)
{
    return RGBA { x.r, x.g, x.b, 255 };
}

template <>
Luma from(const RGB& x)
{
    return Luma { lib::rgb_to_grayscale(x.r, x.g, x.b) };
}

RGBA operator+(const RGBA& x, const RGBA& y)
{
    auto [r, g, b, a] = lib::mix_color(x.r, x.g, x.b, x.a, y.r, y.g, y.b, y.a);
    return RGBA { r, g, b, a };
}

template <typename A, typename B, typename C>
#define BLEND(A, B, C)
A operator+(const B& x, const C& y)
{
    return from<A, RGBA>(from<RGBA, B>(x) + from<RGBA, C>(y));
}

BLEND(RGBA, RGBA, RGB)
BLEND(RGBA, RGB, RGBA)