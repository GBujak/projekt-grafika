#include <engine.hpp>
#include <logger.hpp>

Engine::Engine() {
    // al_init();
    // al_install_keyboard();
    m_logger.emplace();

    // Don't limit fps by default
    m_clock.emplace(0);
}

Engine::~Engine() {
    // al_uninstall_keyboard();
    m_logger.reset();
}

void Engine::main_loop() {
    // al_get_keyboard_state(&this->m_keyboard_state);
    this->m_clock->tick();
    while (!should_exit) {

    }
}

// Replace clock with a clock that limits fps
void Engine::set_clock_fps_limit(int limit) {
    m_clock.reset();
    m_clock.emplace(limit);
}