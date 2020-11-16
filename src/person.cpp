#include <person.hpp>
#include <consts.hpp>
#include <iostream>

Person::Person(Point2f position)
    : m_position(position), m_last_acceleration_tick(SDL_GetTicks()) {}

auto Person::update(const InputState* input_state, Uint32 tick) -> void {
    auto tick_diff = tick - m_last_acceleration_tick;
    if (tick_diff == 0) return;

    float x_movement = 0, y_movement = 0.0;
    if (input_state->keyboard_state[SDL_SCANCODE_D]) x_movement += 1.0;
    if (input_state->keyboard_state[SDL_SCANCODE_A]) x_movement -= 1.0;
    if (input_state->keyboard_state[SDL_SCANCODE_S]) y_movement += 1.0;
    if (input_state->keyboard_state[SDL_SCANCODE_W]) y_movement -= 1.0;

    // Ruszanie się po przekątnej nie powinno być szybsze, niż w linii prostej
    if (x_movement != 0.0 && y_movement != 0.0) {
        x_movement /= sqrtf(2.0);
        y_movement /= sqrtf(2.0);
    }

    float x_delta_v = (x_movement * (float) PERSON_ACCELERATION) / (float) (ACCELERATION_UNIT * tick_diff);
    float y_delta_v = (y_movement * (float) PERSON_ACCELERATION) / (float) (ACCELERATION_UNIT * tick_diff);

    m_position.x += x_delta_v;
    m_position.y += y_delta_v;

    m_last_acceleration_tick = tick;
}

void Person::draw(SDL_Renderer* renderer, Point2f camera_pos) {
    auto rect = SDL_Rect{};
    rect.x = (m_position.x - camera_pos.x) * TILE_WIDTH;
    rect.y = (m_position.y - camera_pos.y) * TILE_WIDTH;
    rect.w = PERSON_WIDTH;
    rect.h = PERSON_WIDTH;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderFillRect(renderer, &rect);
}

auto Person::position() -> Point2f {
    return m_position;
}