#include <world.hpp>
#include <weapon.hpp>
#include <consts.hpp>

auto World::current_room() -> Floor* {
    return &m_rooms.at(m_current_room);
}

World::World() {
}

World::World(WorldConfig& config) : m_rooms(config.floors), m_current_room(0) {
    reload_floor();
}

auto World::update(unsigned tick, Point2f player_position) -> bool {
    bool player_died = false;

    for (unsigned i = 0; i < m_bullet_system.bullets().size(); i++) {
        auto& bullets = m_bullet_system.bullets();
        auto& bullet = bullets.at(i);
        bullet.update(tick);

        if (simple_collision(bullet.position(), 10 / TILE_WIDTH, true)) {
            bullet = bullets.back();
            bullets.pop_back();
            i--;
        }

        if (bullet.person_collision(player_position)) {
            bullet = bullets.back();
            bullets.pop_back();
            i--;
            player_died = true;
        }
    }

    for (unsigned i = 0; i < m_enemies.size(); i++) {
        auto& enemy = m_enemies.at(i);
        enemy.update(tick, player_position, *current_room());
        for (auto& bullet : m_bullet_system.bullets()) {
            if (bullet.person_collision(enemy.position())) {
                enemy = m_enemies.back();
                m_enemies.pop_back();
                i--;
            }
        }
    }

    return player_died;
}

auto World::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void {
}

auto World::simple_collision(Point2f position, float width, bool is_piercing, Tile** door_ptr) -> bool {
    auto& room = *current_room();

    bool crosses_x = std::floor(position.x) != std::floor(position.x + width);
    bool crosses_y = std::floor(position.y) != std::floor(position.y + width);

    bool result = false;

    for (int x = 0; x < 1 + (int) crosses_x; x++)
        for (int y = 0; y < 1 + (int) crosses_y; y++)
            result |= room.does_collide({position.x + x, position.y + y}, is_piercing, door_ptr);
    
    return result;
}

auto World::vector_collision(Point2f position, Point2f next_position, float width, bool is_piercing, Tile** door_ptr) -> Point2f {
    Point2f result;
    
    if (simple_collision({next_position.x, position.y}, width, is_piercing, door_ptr))
        result.x = position.x;
    else result.x = next_position.x;

    if (simple_collision({position.x, next_position.y}, width, is_piercing, door_ptr))
        result.y = position.y;
    else result.y = next_position.y;

    return result;
}

auto World::reload_floor() -> Point2f {

    m_bullet_system.bullets().clear();
    m_enemies.clear();

    for (auto position : current_room()->initial_enemy_positions()) {
        auto enemy = Enemy{ Weapon{1, 10, 50, 0, 0, bullet_system()}, position };
        m_enemies.push_back(enemy);
    }

    return current_room()->initial_player_position();
}