#pragma once

#include <geometry.hpp>
#include <SDL2/SDL.h>

class PhysicsEntity {
    Point2f m_position, m_velocity;
    float m_width;
    Uint32 m_last_update_tick;

    public:

    PhysicsEntity() = default;
    PhysicsEntity(Point2f position, Point2f velocity, float width)
        : m_position(position), m_velocity(velocity), m_width(width) {}

    auto position() -> Point2f& { return m_position; }
    auto velocity() -> Point2f& { return m_velocity; }
    auto width()    -> float&   { return m_width; }

    auto update(Uint32 current_tick) -> void;
};