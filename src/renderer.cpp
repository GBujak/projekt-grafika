#include <renderer.hpp>

Renderer::Renderer(SDL_Renderer* renderer, Point2f raw_screen_size)
    : m_renderer(renderer), m_camera(raw_screen_size) {}

auto Renderer::draw_rect(Line rect_params, SDL_Color color) -> void {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    auto position = rect_params.a;
    // TODO: dokończ to -> camera musi mieć position
}