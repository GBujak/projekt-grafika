#pragma once

#include <optional>
#include <SDL2/SDL.h>

#include <error.hpp>

std::optional<Error> main_loop(SDL_Window* window);
