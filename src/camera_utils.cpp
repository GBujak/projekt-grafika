#include <camera_utils.hpp>
#include <consts.hpp>

#include <cmath>

auto camera_position(Point2f player_position, Point2f screen_resolution, Point2f aim_vector) -> Point2f {
    auto camera_pos = player_position;
    camera_pos.add_scalar(PERSON_WIDTH / 2);
    screen_resolution.div_scalar(2);
    camera_pos.sub_point2f(screen_resolution);
    aim_vector.mul_scalar(0.5);
    camera_pos.add_point2f(aim_vector);
    return camera_pos;
}

auto get_aim_vector(Point2f raw_mouse_position, Point2f screen_resolution) -> Point2f {
    auto vec = raw_mouse_position;
    vec.x -= screen_resolution.x * (float) TILE_WIDTH / 2;
    vec.y -= screen_resolution.y * (float) TILE_WIDTH / 2;
    vec.div_scalar(TILE_WIDTH);
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