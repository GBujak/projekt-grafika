#include <camera.hpp>
#include <camera_utils.hpp>
#include <consts.hpp>

Camera::Camera(Point2f raw_screen_size) : m_screen_size(raw_screen_size) {
    m_screen_size.x /= TILE_WIDTH;
    m_screen_size.y /= TILE_WIDTH;
}

auto Camera::resize_screen(Point2f raw_screen_size) {
    m_screen_size = raw_screen_size;
    m_screen_size.x /= TILE_WIDTH;
    m_screen_size.y /= TILE_WIDTH;
}

auto Camera::draw(SDL_Renderer* renderer, World world, InputState input_state) {
    
}