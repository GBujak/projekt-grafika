#include <floor.hpp>

#include <consts.hpp>
#include <cmath>
#include <drawing_functions.hpp>

Floor::Floor(unsigned dimx, unsigned dimy)
    : m_matrix(dimx, dimy) {}

Floor::Floor(std::vector<Tile> vec, unsigned dimx, unsigned dimy)
    : m_matrix(vec, dimx, dimy) {}

Floor::Floor(std::vector<Tile> vec, unsigned dimx, unsigned dimy, Point2f initial_player_position, std::vector<Point2f> initial_enemy_positions)
    : m_matrix(vec, dimx, dimy), m_initial_player_position(initial_player_position), m_initial_enemy_positions(initial_enemy_positions) {
        
    m_initial_player_position.add_scalar(0.5);
    m_initial_player_position.add_scalar(-(0.5 * PERSON_WIDTH));
    
    for (auto& position : m_initial_enemy_positions) {
        position.add_scalar(0.5);
        position.add_scalar(-(0.5 * PERSON_WIDTH));
    }
}

auto Floor::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void {
    unsigned start_x, start_y, end_x, end_y;
    start_x = std::max(0, (int) std::floor(camera_pos.x));
    start_y = std::max(0, (int) std::floor(camera_pos.y));
    end_x   = std::min(m_matrix.dimx(), (unsigned) std::floor(camera_pos.x + resolution.x + 1));
    end_y   = std::min(m_matrix.dimy(), (unsigned) std::floor(camera_pos.y + resolution.y + 1));

    for (unsigned x = start_x; x < end_x; x++) {
        for (unsigned y = start_y; y < end_y; y++) {
            auto tile = m_matrix.at(x, y);
            auto tile_x = (((float) x) - camera_pos.x) * ((float) TILE_WIDTH);
            auto tile_y = (((float) y) - camera_pos.y) * ((float) TILE_WIDTH);
            draw_tile(renderer, tile, tile_x, tile_y);
        }
    }
}

auto Floor::does_collide(Point2f position, bool is_piercing, Tile** door_ptr) -> bool {
    int x = std::floor(position.x);
    int y = std::floor(position.y);
    if (x < 0 || x >= (int) m_matrix.dimx() || y < 0 || y >= (int) m_matrix.dimy()) return true;

    auto tile = m_matrix.at(x, y);
    if (is_piercing && tile.type() == Tile::Type::Window) return false;
    if (tile.type() == Tile::Type::Space) return false;
    if (tile.type() == Tile::Type::Door) {
        if (door_ptr != nullptr) *door_ptr = &tile;
        return false;
    }

    return true;
}
