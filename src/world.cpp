#include <world.hpp>

auto World::current_room() -> Floor* {
    return &m_rooms.at(m_current_room);
}

World::World() : m_player({0, 0}) {
}

World::World(WorldConfig& config) : m_rooms({config.floor}), m_current_room(0), m_player(config.player_start) {}