#pragma once

#include <vector>
#include <matrix.hpp>
#include <tile.hpp>
#include <geometry.hpp>

struct WorldConfig {
    Matrix<Tile> floor;
    Point2f player_start;
};