#include <display.hpp>

using namespace graphics;

Display::Display(int width, int height) {
    this->display = al_create_display(width, height);
}

void Display::draw(const Drawable* drawable) {
    drawable->draw(this->display);
}