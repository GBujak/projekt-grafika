#include <person.hpp>
#include <consts.hpp>
#include <iostream>

Person::Person(Point2f position)
    : m_position(position), m_last_acceleration_tick(SDL_GetTicks()) {}

auto Person::update(const InputState* input_state, Uint32 tick) -> void {
    m_position.x += 0.001;
}

void Person::draw(SDL_Renderer* renderer, Point2f camera_pos) {
    auto rect = SDL_Rect{};
    rect.x = (m_position.x - camera_pos.x) * TILE_WIDTH;
    rect.y = (m_position.y - camera_pos.y) * TILE_WIDTH;
    rect.w = TILE_WIDTH;
    rect.h = TILE_WIDTH;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderDrawRect(renderer, &rect);
}

auto Person::position() -> Point2f {
    return m_position;
}