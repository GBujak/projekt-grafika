#pragma once

#include <vector>
#include <matrix.hpp>
#include <tile.hpp>
#include <world_config.hpp>
#include <floor.hpp>
#include <bullet.hpp>
#include <physics_entity.hpp>
#include <bullet_system.hpp>
#include <enemy.hpp>

class World {
    std::vector<Floor> m_rooms;
    std::vector<Enemy> m_enemies;
    int m_current_room = -1;
    BulletSystem m_bullet_system;

    public:
    World();
    World(WorldConfig& config);
    auto current_room() -> Floor*;

    auto add_bullet(Bullet b) -> void {
        m_bullet_system.add_bullet(b);
    }

    auto get_bullets() -> std::vector<Bullet>& { return m_bullet_system.bullets(); }
    auto bullet_system() -> BulletSystem& { return m_bullet_system; }
    auto enemies() -> std::vector<Enemy>& { return m_enemies; }

    auto update(unsigned tick, Point2f player_position) -> bool; // true -> gracz umarł
    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void;
    
    // Czy position jest w ścianie?
    // gdy is_piercing jest ustawione na true, ignoruj kolizję z oknami
    auto simple_collision(Point2f position, float width, bool is_piercing) -> bool;
    // Zwróć punkt pomiędzy position, a next_position taki, żeby nie był w ścianie.
    auto vector_collision(Point2f position, Point2f next_position, float width, bool is_piercing) -> Point2f;
    
    // Wywoływana, gdy gracz zgninie zwraca koordynaty gracza
    auto reload_floor() -> Point2f;
};
