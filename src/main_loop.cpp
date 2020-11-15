#include <SDL2/SDL.h>
#include <core_functions.hpp>
#include <input_state.hpp>
#include <error.hpp>

auto delay_at_fps(Uint32 last_tick, int fps) -> Uint32 {
    auto new_tick = SDL_GetTicks();
    if (fps < 0) return new_tick;

    auto max_frame_time = (Uint32) 1000 / fps;
    auto last_frame_time = new_tick - last_tick;
    if (last_frame_time > max_frame_time) SDL_Delay(max_frame_time - last_frame_time);
    return new_tick;
}

auto main_loop(SDL_Window* window, int fps_limit) -> std::optional<Error> {
    bool should_exit = false;
    SDL_Event event;
    auto last_tick = SDL_GetTicks();

    auto input_state = InputState::next();

    while (!should_exit) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) should_exit = true;
        }

        input_state = InputState::next();

        // Limit fps
        last_tick = delay_at_fps(last_tick, fps_limit);
    }

    return {};
}
