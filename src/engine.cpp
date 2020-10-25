#include <engine.hpp>
#include <logger.hpp>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>

Engine::Engine() {
    al_init();
    al_install_keyboard();
    m_logger.emplace();
}

Engine::~Engine() {
    al_uninstall_keyboard();
    m_logger.reset();
}

void Engine::main_loop() {
    while (!should_exit) {

    }
}

const Logger& Engine::logger() const {
    return *m_logger;
}