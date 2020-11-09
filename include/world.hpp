#pragma once

#include <vector>

#include <matrix.hpp>
#include <tile.hpp>

class World {
    std::vector<Matrix<Tile>> m_rooms;
    int m_current_room = -1;

    public:
    World();
    auto current_room() -> Matrix<Tile>*;
};
