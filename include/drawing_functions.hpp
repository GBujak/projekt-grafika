#pragma once
#include <SDL2/SDL.h>
#include <tile.hpp>

void draw_tile(SDL_Renderer* renderer, const Tile& tile, int x, int y);
