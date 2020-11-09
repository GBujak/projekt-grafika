#include <world.hpp>

auto World::current_room() -> Matrix<Tile>* {
    return &m_rooms.at(m_current_room);
}

World::World() {
}