#include <logger.hpp>
#include <iostream>
#include <allegro5/allegro_native_dialog.h>

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::log(Level level, const char* message) const {
    switch (level) {
        case Debug:
            std::cerr << "[DEBUG] " << message << std::endl;
            break;
        case Warning:
            std::cerr << "[WARNING] " << message << std::endl;
            break;
        case Fatal:
            std::cerr << "[FATAL] " << message << std::endl;
            abort();
            break;
    }
}
