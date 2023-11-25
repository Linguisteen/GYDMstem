#pragma once

#include <SDL2/SDL_image.h>

#include <cstdint>
#include <string>

namespace WarGrey::STEM {
    SDL_Texture* game_blank_image(SDL_Renderer* renderer, int width, int height);
    SDL_Texture* game_blank_image(SDL_Renderer* renderer, float width, float height);

    SDL_Surface* game_formatted_surface(int width, int height, uint32_t format);
    SDL_Surface* game_formatted_surface(float width, float height, uint32_t format);
    
    SDL_Texture* game_load_image(SDL_Renderer* renderer, const char* file);
    SDL_Texture* game_load_image(SDL_Renderer* renderer, const std::string& file);
    void game_clear_image(SDL_Renderer* renderer, SDL_Texture* image);
    void game_unload_image(SDL_Texture* image);

    bool game_save_image(SDL_Surface* png, const std::string& pname);
    bool game_save_image(SDL_Surface* png, const char* pname);
}
