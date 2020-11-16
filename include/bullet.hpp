#pragma once

#include <geometry.hpp>
#include <SDL2/SDL.h>

class Bullet {
    Point2f position, velocity;

    public:
    Bullet(Point2f position, Point2f velocity);
    auto update(unsigned tick) -> void;
    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f screen_resolution) -> void;
};