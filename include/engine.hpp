#pragma once

#include <logger.hpp>
#include <clock.hpp>

#include <allegro5/allegro.h>
#include <iostream>
#include <optional>

class Engine {
    Engine();
    ~Engine();

    public:
    /// Disable copy constructor
    Engine(const Engine&) = delete;

    /// Singleton pattern
    static Engine& instance() {
        static Engine engine;
        return engine;
    }

    // End of singleton implementation

    private:
    bool should_exit;
    std::optional<Logger> m_logger;
    std::optional<Clock> m_clock;
    ALLEGRO_KEYBOARD_STATE m_keyboard_state;

    public:
    void main_loop();
    const Logger& logger() const { return *m_logger; };
    const Clock& clock() const { return *m_clock; };
    void set_clock_fps_limit(int limit);
    const ALLEGRO_KEYBOARD_STATE& keyboard_state() const { return m_keyboard_state; }
};