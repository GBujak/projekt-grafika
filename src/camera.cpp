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

auto Camera::draw(SDL_Renderer* renderer, World world, InputState input_state) -> void {
    // auto camera_pos = camera_position(world.player().position(), input_state.mouse_position, m_screen_size);
    auto aim_vector = get_aim_vector(input_state.mouse_position, m_screen_size);
    // auto camera_pos = world.player().position();
    std::cout << aim_vector.x << " " << aim_vector.y << std::endl;
    auto camera_pos = camera_position(world.player().position(), m_screen_size, aim_vector);

    auto player = world.player();
    world.current_room()->draw(renderer, camera_pos, m_screen_size);
    player.draw(renderer, camera_pos);
    world.draw(renderer, camera_pos, m_screen_size);
}