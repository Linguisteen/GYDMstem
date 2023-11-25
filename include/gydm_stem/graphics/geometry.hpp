#pragma once

#include <SDL2/SDL.h>

namespace WarGrey::STEM {
    SDL_RendererFlip game_scales_to_flip(float x_scale, float y_scale);
    void game_flip_to_signs(SDL_RendererFlip flip, float* hsgn = nullptr, float* vsgn = nullptr);
    void game_flip_to_signs(SDL_RendererFlip flip, double* hsgn = nullptr, double* vsgn = nullptr);    
}
