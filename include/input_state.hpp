#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>

struct InputState {
    public:
    const Uint8* keyboard_state;
    Point2f mouse_position;
    Uint32 mouse_state;

    static auto next() -> InputState {
        InputState state;
        state.keyboard_state = SDL_GetKeyboardState(nullptr);
        int x, y;
        state.mouse_state = SDL_GetMouseState(&x, &y);
        state.mouse_position = { (float) x, (float) y };
        return state;
    }

    private:
    InputState() = default;
};