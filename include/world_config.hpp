#pragma once

#include <vector>
#include <matrix.hpp>
#include <tile.hpp>
#include <geometry.hpp>
#include <floor.hpp>

struct WorldConfig {
    Floor floor;
    Point2f player_start;
    WorldConfig() : floor(0, 0) {};
};