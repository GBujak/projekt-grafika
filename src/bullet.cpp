#include <bullet.hpp>
#include <consts.hpp>
#include <iostream>

Bullet::Bullet(Point2f position, Point2f velocity, unsigned tick)
    : m_position(position), m_velocity(velocity), last_tick(tick) {
        this->m_position.x += PERSON_WIDTH / 2;
        this->m_position.y += PERSON_WIDTH / 2;
    }

auto Bullet::update(unsigned tick) -> void {
    auto tick_diff = tick - last_tick;
    m_position.x += (m_velocity.x / ACCELERATION_UNIT) * tick_diff;
    m_position.y += (m_velocity.y / ACCELERATION_UNIT) * tick_diff;
    last_tick = tick;
}

auto Bullet::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f screen_resolution) -> void {
    auto rect = SDL_Rect {};
    rect.x = (m_position.x - camera_pos.x) * TILE_WIDTH;
    rect.y = (m_position.y - camera_pos.y) * TILE_WIDTH;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}