#include <world.hpp>
#include <weapon.hpp>

auto World::current_room() -> Floor* {
    return &m_rooms.at(m_current_room);
}

World::World() : m_player({0, 0}) {
}

World::World(WorldConfig& config) : m_rooms({config.floor}), m_current_room(0), m_player(config.player_start) {
    auto weapon = Weapon {1, 1, 1, 1, 1, &bullets};
    m_player.give_weapon(weapon);
}

auto World::update(unsigned tick) -> void {
    for (auto& bullet : bullets) bullet.update(tick);
}

auto World::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void {
    for (auto& bullet: bullets) bullet.draw(
        renderer, camera_pos, resolution
    );
}