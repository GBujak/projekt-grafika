#pragma once

#include <geometry.hpp>

// Oblicz pozycję kamery - powinna być pomiędzy graczem, a kursorem
auto camera_position(Point2f player_position, Point2f cursor_position) -> Point2f;

// Konwersja punktów pomiędzy pikselami, a indeksem w macierzy
auto matrix_to_absolute(Point2f matrix_pos) -> Point2f;
auto absolute_to_relative(Point2f point, Point2f root) -> Point2f;
auto matrix_to_relative(Point2f matrix_pos, Point2f root) -> Point2f;
auto absolute_to_matrix(Point2f point) -> Point2f;