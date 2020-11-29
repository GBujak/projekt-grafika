#pragma once

#include <vector>

#include <SDL2/SDL.h>
#include <matrix.hpp>
#include <tile.hpp>
#include <geometry.hpp>
#include <camera_utils.hpp>

class Floor {
    Matrix<Tile> m_matrix;

    public:
    Floor(unsigned dimx, unsigned dimy);
    Floor(std::vector<Tile> vec, unsigned dimx, unsigned dimy);

    auto tile_matrix() -> Matrix<Tile>& { return m_matrix; }
    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void;
    auto does_collide(Point2f position, bool is_piercing) -> bool;
};