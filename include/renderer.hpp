#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <camera.hpp>

class Renderer {
    SDL_Renderer* m_renderer;
    Camera m_camera;

    public:
    auto camera() -> Camera& { return m_camera; }

    Renderer(SDL_Renderer* renderer);
    auto draw_rect(Line rect_params, SDL_Color color);
};