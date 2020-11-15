#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <input_state.hpp>

class Person {
    Point2f m_position;
    Point2f m_speed;
    Point2f m_acceleration;
    Uint32  m_last_acceleration_tick;

    public:
    Person(Point2f position);
    auto update(const InputState* input_state, Uint32 tick) -> void;
    auto position() -> Point2f;
    void draw(SDL_Renderer* renderer, Point2f camera_pos);
};