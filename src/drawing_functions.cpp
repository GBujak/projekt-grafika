#include <SDL2/SDL.h>
#include <drawing_functions.hpp>
#include <tile.hpp>

void draw(SDL_Renderer* renderer, const Tile& tile, int h, int w, int x, int y) {
    SDL_Rect rect;

    rect.h = h;
    rect.w = w;
    rect.x = x;
    rect.y = y;

    switch (tile.type()) {
        case Tile::Type::Space:
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            break;
        case Tile::Type::Wall:
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            break;
        case Tile::Type::Window:
            SDL_SetRenderDrawColor(renderer, 100, 100, 200, 255);
            break;
        case Tile::Type::Door:
            SDL_SetRenderDrawColor(renderer, 200, 200, 100, 255);
            break;

        default:
            break;
    }

    SDL_RenderDrawRect(renderer, &rect);
}