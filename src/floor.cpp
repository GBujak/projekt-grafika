#include <floor.hpp>

#include <consts.hpp>
#include <cmath>
#include <drawing_functions.hpp>

Floor::Floor(unsigned dimx, unsigned dimy)
    : m_matrix(dimx, dimy) {}

Floor::Floor(std::vector<Tile> vec, unsigned dimx, unsigned dimy)
    : m_matrix(vec, dimx, dimy) {}

auto Floor::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) {
    unsigned start_x, start_y, end_x, end_y;
    start_x = std::max(0u, (unsigned) std::floor(camera_pos.x));
    start_y = std::max(0u, (unsigned) std::floor(camera_pos.y));
    end_x   = std::min(m_matrix.dimx(), (unsigned) std::floor(camera_pos.x + resolution.x));
    end_y   = std::min(m_matrix.dimy(), (unsigned) std::floor(camera_pos.y + resolution.y));

    for (unsigned x = start_x; x < end_x; x++) {
        for (unsigned y = start_y; y < end_y; y++) {
            auto tile = m_matrix.at(x, y);
            auto tile_x = (((float) x) - camera_pos.x) * ((float) TILE_WIDTH);
            auto tile_y = (((float) y) - camera_pos.y) * ((float) TILE_WIDTH);
            draw_tile(renderer, tile, tile_x, tile_y);
        }
    }
}