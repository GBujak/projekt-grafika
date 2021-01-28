#pragma once

#include <vector>

#include <SDL2/SDL.h>
#include <matrix.hpp>
#include <tile.hpp>
#include <geometry.hpp>
#include <camera_utils.hpp>
#include <vector>

class Floor {
    Matrix<Tile> m_matrix;
    Point2f m_initial_player_position;
    std::vector<Point2f> m_initial_enemy_positions;

    public:
    Floor(unsigned dimx, unsigned dimy);
    Floor(std::vector<Tile> vec, unsigned dimx, unsigned dimy);
    Floor(std::vector<Tile> vec, unsigned dimx, unsigned dimy, Point2f initial_player_position, std::vector<Point2f> initial_enemy_positions);

    auto tile_matrix() -> Matrix<Tile>& { return m_matrix; }
    auto initial_enemy_positions() -> std::vector<Point2f>& { return m_initial_enemy_positions; }
    auto initial_player_position() -> Point2f { return m_initial_player_position; }

    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void;
    auto does_collide(Point2f position, bool is_piercing, Tile** door_ptr = nullptr) -> bool;
};