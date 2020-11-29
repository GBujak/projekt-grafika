#include <world.hpp>
#include <weapon.hpp>
#include <consts.hpp>

auto World::current_room() -> Floor* {
    return &m_rooms.at(m_current_room);
}

World::World() {
}

World::World(WorldConfig& config) : m_rooms({config.floor}), m_current_room(0) {
}

auto World::update(unsigned tick) -> void {
    for (unsigned i = 0; i < bullets.size(); i++) {
        auto& bullet = bullets.at(i);
        bullet.update(tick);
        if (simple_collision(bullet.position(), 10 / TILE_WIDTH, true)) {
            bullet = bullets.back();
            bullets.pop_back();
            i--;
        }
    }
}

auto World::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void {
    for (auto& bullet: bullets) bullet.draw(
        renderer, camera_pos, resolution
    );
}

auto World::simple_collision(Point2f position, float width, bool is_piercing) -> bool {
    auto& room = *current_room();

    bool crosses_x = std::floor(position.x) != std::floor(position.x + width);
    bool crosses_y = std::floor(position.y) != std::floor(position.y + width);

    bool result = false;

    for (int x = 0; x < 1 + (int) crosses_x; x++)
        for (int y = 0; y < 1 + (int) crosses_y; y++)
            result |= room.does_collide({position.x + x, position.y + y}, is_piercing);
    
    return result;
}

auto World::vector_collision(Point2f position, Point2f next_position, float width, bool is_piercing) -> Point2f {
    auto& room = *current_room();
    Point2f result;

    if (room.does_collide({next_position.x, position.y}, is_piercing))
        result.x = position.x;
    else result.x = next_position.x;

    if (room.does_collide({position.x, next_position.y}, is_piercing))
        result.y = position.y;
    else result.y = next_position.y;

    return result;
}