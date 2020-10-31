#include <display.hpp>
#include <engine.hpp>
#include <iostream>
#include <string>

using namespace graphics;

constexpr const char* TITLE = "Gra";

Display::Display() {
    this->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
        SDL_WINDOW_RESIZABLE & SDL_WINDOW_SHOWN);
    Engine::instance().logger().log(Logger::Fatal, (std::string{"Window failed to initialize: "} + SDL_GetError()).c_str());
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    Engine::instance().logger().log(Logger::Fatal, (std::string{"Renderer failed to initialize: "} + SDL_GetError()).c_str());
}

void Display::draw(const Drawable* drawable) {
    // drawable->draw(this->display);
}