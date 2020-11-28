#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <input_state.hpp>
#include <weapon.hpp>

class Player {
    Point2f m_position;
    Point2f m_speed;
    Point2f m_acceleration;
    Uint32  m_last_acceleration_tick;

    Weapon* weapon;

    public:
    Player(Point2f position);
    auto update(const InputState* input_state, Point2f aim_vector, Uint32 tick) -> void;
    auto position() -> Point2f;
    auto give_weapon(Weapon* weapon) -> void;
};