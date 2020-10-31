#pragma once

#include <SDL2/SDL.h>
#include <drawable.hpp>

namespace graphics {
    class Display {
        SDL_Window* window;
        SDL_Renderer* renderer;

        public:
        Display(); 
        void draw(const Drawable* drawable);
    };
}