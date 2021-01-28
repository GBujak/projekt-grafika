#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>
#include <camera.hpp>

#include <world.hpp>
#include <player.hpp>
#include <enemy.hpp>
#include <physics_entity.hpp>

class Renderer {
    SDL_Renderer* m_renderer;
    Camera m_camera;

    public:
    auto camera() -> Camera& { return m_camera; }

    Renderer(SDL_Renderer* renderer, Point2f raw_screen_size);

    auto update(InputState& input_state, Point2f player_position) -> void;

    auto clear() -> void;
    auto present() -> void;

    auto draw_physics_entity(PhysicsEntity& entity, SDL_Color color) -> void;
    auto draw_world(World& world) -> void;
    auto draw_floor(Floor& floor) -> void;
    auto draw_bullet(Bullet& bullet) -> void;
    auto draw_player(Player& player) -> void;
    auto draw_enemy(Enemy& enemy) -> void;
};
