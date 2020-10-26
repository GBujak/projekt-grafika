#pragma once

#include <logger.hpp>
#include <clock.hpp>

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

    public:
    void main_loop();
    const Logger& logger() const;
    const Clock& clock() const;
    void set_clock_fps_limit(int limit);
};