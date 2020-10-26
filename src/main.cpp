#include <iostream>
#include <test.hpp>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include <clock.hpp>
#include <time.h>

int main() {
    Clock clock = {60};
    long current_time = time(nullptr);
    int same_time_count = 0;
    while (true) {
        clock.tick();
        if (time(nullptr) == current_time) same_time_count++;
        else {
            std::cout << same_time_count << std::endl;
            current_time = time(nullptr);
            same_time_count = 0;
        }
    }

    return 0;
}