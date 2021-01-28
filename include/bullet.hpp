#pragma once

#include <geometry.hpp>
#include <consts.hpp>
#include <SDL2/SDL.h>

class Bullet {
    Point2f m_position, m_velocity;
    unsigned last_tick;

    public:
    Bullet(Point2f position, Point2f velocity, unsigned tick);

    auto position() -> Point2f { return m_position; }
    auto velocity() -> Point2f { return m_velocity; }

    auto update(unsigned tick) -> void;
    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f screen_resolution) -> void;
    auto person_collision(Point2f person_position) -> bool;
};