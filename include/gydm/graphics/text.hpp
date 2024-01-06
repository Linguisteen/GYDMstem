#pragma once

#include <SDL2/SDL_ttf.h>

#include <string>
#include <cstdint>

#include "font.hpp"

#include "../physics/color/rgba.hpp"

namespace GYDM {
    enum TextRenderMode { Solid, Shaded, Blender, LCD };

    /*********************************************************************************************/
    void game_disable_font_selection(bool yes);

    /*********************************************************************************************/
    SDL_Surface* game_text_surface(const std::string& text, const shared_font_t& font, GYDM::TextRenderMode mode, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, int wrap = 0);
    SDL_Texture* game_text_texture(SDL_Renderer* renderer, const std::string& text, const shared_font_t& font, GYDM::TextRenderMode mode, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, int wrap = 0);

    SDL_Texture* game_solid_text_texture(SDL_Renderer* renderer, const std::string& text, const shared_font_t& font, const GYDM::RGBA& fgc, int wrap = 0);
    SDL_Texture* game_shaded_text_texture(SDL_Renderer* renderer, const std::string& text, const shared_font_t& font, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, int wrap = 0);
    SDL_Texture* game_lcd_text_texture(SDL_Renderer* renderer, const std::string& text, const shared_font_t& font, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, int wrap = 0);
    SDL_Texture* game_blended_text_texture(SDL_Renderer* renderer, const std::string& text, const shared_font_t& font, const GYDM::RGBA& fgc, int wrap = 0);

    class Pen {
    public:
        static void draw_solid_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& rgb, int x, int y, const std::string& text, int wrap = 0);
        static void draw_shaded_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, int x, int y, const std::string& text, int wrap = 0);
        static void draw_lcd_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, int x, int y, const std::string& text, int wrap = 0);
        static void draw_blended_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& rgb, int x, int y, const std::string& text, int wrap = 0);

        static void draw_solid_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& rgb, float x, float y, const std::string& text, int wrap = 0);
        static void draw_shaded_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, float x, float y, const std::string& text, int wrap = 0);
        static void draw_lcd_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& fgc, const GYDM::RGBA& bgc, float x, float y, const std::string& text, int wrap = 0);
        static void draw_blended_text(const shared_font_t& font, SDL_Renderer* renderer, const GYDM::RGBA& rgb, float x, float y, const std::string& text, int wrap = 0);
    };
}