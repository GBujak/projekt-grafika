#include <camera_utils.hpp>
#include <consts.hpp>

#include <cmath>

auto camera_position(Point2f player_position, Point2f cursor_position) -> Point2f {
    return {
        player_position.x + PERSON_WIDTH / 2,
        player_position.y + PERSON_WIDTH / 2,
    }; // Todo: kamera pomiędzy graczem a kursorem
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