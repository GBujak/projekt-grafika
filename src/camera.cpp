#include <camera.hpp>
#include <camera_utils.hpp>
#include <consts.hpp>

Camera::Camera(Point2f raw_screen_size) : m_screen_size(raw_screen_size) {
    m_screen_size.div_scalar(TILE_WIDTH);
}

auto Camera::resize_screen(Point2f raw_screen_size) {
    m_screen_size = raw_screen_size;
    m_screen_size.div_scalar(TILE_WIDTH);
}

auto Camera::update(InputState& input_state, Point2f player_position) -> void {
    m_aim_vector = get_aim_vector(input_state.mouse_position, m_screen_size);
    m_position = camera_position(player_position, m_screen_size, m_aim_vector);
}

auto Camera::translate_point(Point2f point) -> Point2f {
    return {};
}