#include <iostream>
#include <test.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
    std::cout << "Hello world!" << std::endl;
    test();

    al_init();
    auto display = al_create_display(840, 480);
    
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(100, 100, 200, 200, al_map_rgb(0, 0, 0));
    al_flip_display();

    std::cin.get();

    al_destroy_display(display);
    return 0;
}