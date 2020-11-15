#pragma once

#include <vector>

#include <matrix.hpp>
#include <tile.hpp>
#include <person.hpp>

class World {
    std::vector<Matrix<Tile>> m_rooms;
    int m_current_room = -1;

    Person m_player;

    public:
    World();
    auto current_room() -> Matrix<Tile>*;

    auto player() -> Person { return m_player; }
};
