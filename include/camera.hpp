#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <player.hpp>
#include <world.hpp>
#include <input_state.hpp>

class Camera {
    Point2f m_screen_size;
    Point2f m_position;
    Point2f m_aim_vector;

    public:
    Camera(Point2f raw_screen_size);

    auto screen_size() -> Point2f { return m_screen_size; }
    auto position() -> Point2f { return m_position; }
    auto aim_vector() -> Point2f { return m_aim_vector; }

    auto update(InputState& input_state, Point2f player_position) -> void;

    auto translate_point(Point2f) -> Point2f;

    auto resize_screen(Point2f raw_screen_size);
    auto draw(SDL_Renderer* renderer, World world, InputState input_state) -> void;
};