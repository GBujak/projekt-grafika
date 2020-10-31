#pragma once

#include <SDL2/SDL.h>

namespace graphics {
    class Drawable {
        public:
        virtual void draw(double* const display) const;
        virtual ~Drawable();
    };
}