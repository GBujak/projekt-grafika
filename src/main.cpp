#include "SDL_video.h"
#include <cstdlib>
#include <iostream>

#include <SDL2/SDL.h>

#include <core_functions.hpp>
#include <consts.hpp>

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Failed to initialize sdl: " << SDL_GetError() << std::endl;
        exit(1);
    }

    auto window = SDL_CreateWindow(
            WINDOW_TITLE,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_OPENGL
    );

    std::optional<Error> result = main_loop(window, 60);

    if (result.has_value()) {
        std::cerr << "Error in main loop" << std::endl;
    }

    SDL_Quit();
    return 0;
}
