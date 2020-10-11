#include <allegro5/allegro5.h>
#include <drawable.hpp>

namespace graphics {
    class Display {
        ALLEGRO_DISPLAY* display;

        public:
        Display(int width, int height); 
        void draw(const Drawable* drawable);
    };
}