#pragma once

#include <SDL2/SDL.h>
#include <geometry.hpp>

// Oblicz pozycję kamery - powinna być pomiędzy graczem, a kursorem
auto camera_position(Point2f player_position, Point2f cursor_position) -> Point2f;
