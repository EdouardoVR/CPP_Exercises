#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>

template <typename T, size_t largeur, size_t longueur>

struct Image
{
private:
    std::array<std::array<T, largeur>, longueur> _img;

public:
    Image() = default;

    Image(T pixel)
    {
        for (size_t j = 0; j < longueur; j++)
        {
            for (size_t i = 0; i < largeur; i++)
            {
                _img[j][i] = pixel;
            }
        }
    }

    Image(const std::function<T(const size_t, const size_t)> foo)
    {
        for (size_t j = 0; j < longueur; j++)
        {
            for (size_t i = 0; i < largeur; i++)
            {
                _img[j][i] = foo(i, j);
            }
        }
    }

    const T& operator()(const size_t i, const size_t j) const { return _img[j][i]; }

    T& operator()(const size_t i, const size_t j) { return _img[j][i]; }
};

template <typename T, size_t largeur, size_t longueur>
Image<T, largeur, longueur> operator+(Image<T, largeur, longueur> im1, Image<T, largeur, longueur> im2)
{
    Image<T, largeur, longueur> img_res;
    for (size_t j = 0; j < longueur; j++)
    {
        for (size_t i = 0; i < largeur; i++)
        {
            img_res(i, j) = im1(i, j) + im2(i, j);
        }
    }
    return img_res;
}
