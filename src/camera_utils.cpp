#include <camera_utils.hpp>
#include <consts.hpp>

#include <cmath>

auto camera_position(Point2f player_position, Point2f screen_resolution, Point2f aim_vector) -> Point2f {
    auto camera_pos = player_position;

    // Wyśrodkuj kamerę na graczu
    camera_pos.x -= screen_resolution.x / 2;
    camera_pos.y -= screen_resolution.y / 2;
    camera_pos.x += (float) PERSON_WIDTH / TILE_WIDTH / 2;
    camera_pos.y += (float) PERSON_WIDTH / TILE_WIDTH / 2;

    // Przesuń do połowy odcinka pomiędzy graczem a kursorem
    camera_pos.x = (camera_pos.x + aim_vector.x) / 2;
    camera_pos.y = (camera_pos.y + aim_vector.y) / 2;

    return camera_pos;
}

auto get_aim_vector(Point2f raw_mouse_position, Point2f player_position, Point2f screen_resolution) -> Point2f {
    auto vec = raw_mouse_position;
    vec.x = ((vec.x / TILE_WIDTH) - screen_resolution.x + (float) PERSON_WIDTH / TILE_WIDTH) + player_position.x;
    vec.y = ((vec.y / TILE_WIDTH) - screen_resolution.y + (float) PERSON_WIDTH / TILE_WIDTH) + player_position.y;
    return vec;
}

auto matrix_to_absolute(Point2f matrix_pos) -> Point2f {
    return {
        matrix_pos.x * TILE_WIDTH,
        matrix_pos.y * TILE_WIDTH,
    };
}

auto absolute_to_relative(Point2f point, Point2f root) -> Point2f {
    return {
        point.x + root.x,
        point.y + root.y,
    };
}

auto matrix_to_relative(Point2f matrix_pos, Point2f root) -> Point2f {
    return absolute_to_relative(matrix_to_absolute(matrix_pos), root);
}

auto absolute_to_matrix(Point2f point) -> Point2f {
    return {
        std::floor(point.x / TILE_WIDTH),
        std::floor(point.y / TILE_WIDTH),
    };
}