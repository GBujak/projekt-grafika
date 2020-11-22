#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <player.hpp>
#include <world.hpp>

class Camera {
    Point2f m_screen_size;

    public:
    Camera(Point2f raw_screen_size);
    auto resize_screen(Point2f raw_screen_size);

    auto draw(SDL_Renderer* renderer, World world, InputState input_state) -> void;
};