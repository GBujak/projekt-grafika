#include <renderer.hpp>
#include <physics_entity.hpp>
#include <consts.hpp>
#include <drawing_functions.hpp>
#include <cmath>

Renderer::Renderer(SDL_Renderer* renderer, Point2f raw_screen_size)
    : m_renderer(renderer), m_camera(raw_screen_size) {}

auto Renderer::update(InputState& input_state, Point2f player_position) -> void {
    m_camera.update(input_state, player_position);
}

auto Renderer::clear() -> void {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

auto Renderer::present() -> void {
    SDL_RenderPresent(m_renderer);
}

auto Renderer::draw_physics_entity(PhysicsEntity& entity, SDL_Color color) -> void {
    auto rect = SDL_Rect{};
    Point2f position = entity.position();
    position.sub_point2f(m_camera.position());
    position.mul_scalar(TILE_WIDTH);
    rect.x = position.x;
    rect.y = position.y;
    rect.w = entity.width() * TILE_WIDTH;
    rect.h = entity.width() * TILE_WIDTH;
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(m_renderer, &rect);
}

auto Renderer::draw_player(Player& player) -> void {
    SDL_Color color{};
    color.r = 20;
    color.g = 20;
    color.b = 200;
    color.a = 255;
    PhysicsEntity entity{player.position(), {}, PERSON_WIDTH};
    draw_physics_entity(entity, color);
}

auto Renderer::draw_enemy(Enemy& enemy) -> void {
    SDL_Color color{};
    color.r = 200;
    color.g = 20;
    color.b = 20;
    color.a = 255;
    PhysicsEntity entity{enemy.position(), {}, PERSON_WIDTH};
    draw_physics_entity(entity, color);
}

auto Renderer::draw_world(World& world) -> void {
    draw_floor(*world.current_room());
    for (auto& bullet : world.get_bullets())
        draw_bullet(bullet);
}

auto Renderer::draw_floor(Floor& floor) -> void {
    unsigned start_x, start_y, end_x, end_y;
    auto& tile_matrix = floor.tile_matrix();
    auto camera_pos = m_camera.position();
    auto resolution = m_camera.screen_size();

    start_x = std::max(0, (int) std::floor(camera_pos.x));
    start_y = std::max(0, (int) std::floor(camera_pos.y));
    end_x   = std::min(tile_matrix.dimx(), (unsigned) std::floor(camera_pos.x + resolution.x + 1));
    end_y   = std::min(tile_matrix.dimy(), (unsigned) std::floor(camera_pos.y + resolution.y + 1));
    
    for (unsigned x = start_x; x < end_x; x++) {
        for (unsigned y = start_y; y < end_y; y++) {
            auto tile = tile_matrix.at(x, y);
            auto tile_x = (((float) x) - camera_pos.x) * ((float) TILE_WIDTH);
            auto tile_y = (((float) y) - camera_pos.y) * ((float) TILE_WIDTH);
            draw_tile(m_renderer, tile, tile_x, tile_y);
        }
    }
}

auto Renderer::draw_bullet(Bullet& bullet) -> void {
    auto position = bullet.position();

    SDL_Color color;
    color.r = 200;
    color.g = 0;
    color.b = 0;
    color.a = 255;

    PhysicsEntity entity{position, {}, 0.1};
    draw_physics_entity(entity, color);
}
