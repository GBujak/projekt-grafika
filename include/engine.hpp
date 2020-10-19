#pragma once

#include <logger.hpp>
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
    std::optional<Logger> m_logger;

    public:
    const Logger& logger() const;
};