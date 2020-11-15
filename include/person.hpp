#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <input_state.hpp>

class Person {
    Point2f m_position;
    Point2f m_acceleration;

    public:
    auto update(const InputState* input_state, Uint32 tick);
    auto position() -> Point2f;
};