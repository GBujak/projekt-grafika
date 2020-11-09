#include <camera_functions.hpp>

auto camera_position(Point2f player_position, Point2f cursor_position) -> Point2f {
    return {
        (player_position.x * 1.5 + cursor_position.x) / 2,
        (player_position.y * 1.5 + cursor_position.y) / 2,
    };
}