#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>

class Renderer {
    SDL_Renderer* m_renderer;

    public:
    Renderer(SDL_Renderer* renderer);
    auto draw_rect(Line rect_params, SDL_Color color);
};