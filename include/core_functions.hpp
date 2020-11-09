#pragma once

#include <optional>
#include <SDL2/SDL.h>

#include <error.hpp>

auto main_loop(SDL_Window* window, int fps_limit) -> std::optional<Error>;
auto delay_at_fps(Uint32 last_tick, int fps) -> Uint32;