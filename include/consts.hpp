#pragma once

#include <SDL2/SDL.h>

constexpr const char* WINDOW_TITLE = "Gra";

constexpr float TILE_WIDTH = 64;
constexpr float PERSON_WIDTH = 0.5;

constexpr float ACCELERATION_UNIT = 1000; // W ile milisekund prędkość wyniesie prędkość + przyspieszenie

constexpr float PERSON_ACCELERATION = 0.5;
constexpr float PERSON_MAX_VELOCITY = 0.0075;