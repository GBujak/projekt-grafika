#include <player.hpp>
#include <consts.hpp>
#include <iostream>
#include <algorithm>

Player::Player(Point2f position)
    : m_position(position), m_last_acceleration_tick(SDL_GetTicks()) {}

auto Player::update(const InputState* input_state, Point2f aim_vector, Uint32 tick) -> void {
    auto tick_diff = tick - m_last_acceleration_tick;
    if (tick_diff == 0) return;

    float x_movement = 0, y_movement = 0.0;
    if (input_state->keyboard_state[SDL_SCANCODE_D]) x_movement += 1.0;
    if (input_state->keyboard_state[SDL_SCANCODE_A]) x_movement -= 1.0;
    if (input_state->keyboard_state[SDL_SCANCODE_S]) y_movement += 1.0;
    if (input_state->keyboard_state[SDL_SCANCODE_W]) y_movement -= 1.0;

    // Ruszanie się po przekątnej nie powinno być szybsze, niż w linii prostej
    if (x_movement != 0.0 && y_movement != 0.0) {
        x_movement /= std::sqrt(2.0);
        y_movement /= std::sqrt(2.0);
    }

    float x_delta_v = (x_movement * (float) PERSON_ACCELERATION) / (float) (ACCELERATION_UNIT * tick_diff);
    float y_delta_v = (y_movement * (float) PERSON_ACCELERATION) / (float) (ACCELERATION_UNIT * tick_diff);

    m_speed.x *= 0.9;
    m_speed.y *= 0.9;

    m_speed.x = std::clamp(m_speed.x + x_delta_v, -PERSON_MAX_VELOCITY, PERSON_MAX_VELOCITY);
    m_speed.y = std::clamp(m_speed.y + y_delta_v, -PERSON_MAX_VELOCITY, PERSON_MAX_VELOCITY);

    m_position.x += m_speed.x;
    m_position.y += m_speed.y;

    m_last_acceleration_tick = tick;

    if (input_state->mouse_state == 1 && weapon.has_value()) weapon->try_shoot(m_position, aim_vector, tick);
}

void Player::draw(SDL_Renderer* renderer, Point2f camera_pos) {
    auto rect = SDL_Rect{};
    rect.x = (m_position.x - camera_pos.x) * TILE_WIDTH;
    rect.y = (m_position.y - camera_pos.y) * TILE_WIDTH;
    rect.w = PERSON_WIDTH * TILE_WIDTH;
    rect.h = PERSON_WIDTH * TILE_WIDTH;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderFillRect(renderer, &rect);
}

auto Player::position() -> Point2f {
    return m_position;
}

auto Player::give_weapon(Weapon weapon) -> void {
    this->weapon = { weapon };
}