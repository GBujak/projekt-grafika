#include <SDL2/SDL.h>
#include <core_functions.hpp>
#include <error.hpp>

std::optional<Error> main_loop(SDL_Window* window, int fps_limit) {
    bool should_exit = false;
    SDL_Event event;
    const Uint8* keyboard_state = nullptr;

    while (!should_exit) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) should_exit = true;
        }

        keyboard_state = SDL_GetKeyboardState(nullptr);
    }

    return {};
}
