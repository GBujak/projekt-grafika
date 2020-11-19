#include <bullet.hpp>
#include <consts.hpp>
#include <iostream>

Bullet::Bullet(Point2f position, Point2f velocity, unsigned tick)
    : position(position), velocity(velocity), last_tick(tick) {
        this->position.x += (float)PERSON_WIDTH / (TILE_WIDTH*2);
        this->position.y += (float)PERSON_WIDTH / (TILE_WIDTH*2);
    }

auto Bullet::update(unsigned tick) -> void {
    auto tick_diff = tick - last_tick;
    position.x += (velocity.x / ACCELERATION_UNIT) * tick_diff;
    position.y += (velocity.y / ACCELERATION_UNIT) * tick_diff;
    last_tick = tick;
}

auto Bullet::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f screen_resolution) -> void {
    auto rect = SDL_Rect {};
    rect.x = (position.x - camera_pos.x) * TILE_WIDTH;
    rect.y = (position.y - camera_pos.y) * TILE_WIDTH;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}