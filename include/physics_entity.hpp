#pragma once

#include <geometry.hpp>
#include <SDL2/SDL.h>

class PhysicsEntity {
    Point2f m_position, m_velocity, m_dimensions;
    Uint32 m_last_update_tick;

    public:

    PhysicsEntity() = default;
    PhysicsEntity(Point2f position, Point2f velocity, Point2f dimensions)
        : m_position(position), m_velocity(velocity), m_dimensions(dimensions) {}

    auto position()   -> Point2f& { return m_position; }
    auto velocity()   -> Point2f& { return m_velocity; }
    auto dimensions() -> Point2f& { return m_dimensions; }

    auto update(Uint32 current_tick) -> void;
};