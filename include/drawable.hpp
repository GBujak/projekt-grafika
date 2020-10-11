#include <allegro5/allegro5.h>

namespace graphics {
    class Drawable {
        public:
        virtual void draw(ALLEGRO_DISPLAY* const display) const;
        virtual ~Drawable();
    };
}