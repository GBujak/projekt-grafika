#pragma once

#include <vector>
#include <matrix.hpp>
#include <tile.hpp>
#include <world_config.hpp>
#include <floor.hpp>
#include <bullet.hpp>
#include <physics_entity.hpp>

class World {
    std::vector<Floor> m_rooms;
    int m_current_room = -1;

    std::vector<Bullet> bullets;

    public:
    World();
    World(WorldConfig& config);
    auto current_room() -> Floor*;

    auto add_bullet(Bullet b) -> void {
        bullets.push_back(b);
    }

    auto get_bullets() -> std::vector<Bullet>& { return bullets; }

    auto update(unsigned tick) -> void;
    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void;
    
    // Czy position jest w ścianie?
    // gdy is_piercing jest ustawione na true, ignoruj kolizję z oknami
    auto simple_collision(Point2f position, float width, bool is_piercing) -> bool;
    // Zwróć punkt pomiędzy position, a next_position taki, żeby nie był w ścianie.
    auto vector_collision(Point2f position, Point2f next_position, float width, bool is_piercing) -> Point2f;
};
