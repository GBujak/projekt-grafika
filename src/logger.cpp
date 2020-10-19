#include <logger.hpp>
#include <iostream>
#include <allegro5/allegro_native_dialog.h>

Logger::Logger() {
    if (!al_is_native_dialog_addon_initialized())
        al_init_native_dialog_addon();
}

Logger::~Logger() {
    if (al_is_native_dialog_addon_initialized())
        al_shutdown_native_dialog_addon();
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
            al_show_native_message_box(
                al_get_current_display(),
                "Fatal Error",
                "Fatal Error",
                message,
                "Ok",
                0
            );
            break;
    }
}
