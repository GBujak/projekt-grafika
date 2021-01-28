#pragma once

#include <vector>
#include <matrix.hpp>
#include <tile.hpp>
#include <geometry.hpp>
#include <floor.hpp>

struct WorldConfig {
    std::vector<Floor> floors;
};