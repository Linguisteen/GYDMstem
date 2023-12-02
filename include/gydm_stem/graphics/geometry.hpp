#pragma once

#include <SDL2/SDL.h>

#include <vector>

namespace WarGrey::STEM {
    typedef std::vector<std::pair<float, float>> polygon_vertices;

    WarGrey::STEM::polygon_vertices regular_polygon_vertices(size_t n, float radius, float rotation);

    SDL_RendererFlip game_scales_to_flip(float x_scale, float y_scale);
    void game_flip_to_signs(SDL_RendererFlip flip, float* hsgn = nullptr, float* vsgn = nullptr);
    void game_flip_to_signs(SDL_RendererFlip flip, double* hsgn = nullptr, double* vsgn = nullptr);
}
