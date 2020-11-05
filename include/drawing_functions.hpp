#pragma once
#include <SDL2/SDL.h>
#include <tile.hpp>

void draw(SDL_Renderer* renderer, const Tile& tile, int h, int w, int x, int y);
