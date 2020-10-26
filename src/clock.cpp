#include <clock.hpp>

void Clock::tick() {
    if (this->fps_limit) {
        this->time_point += std::chrono::milliseconds(min_frame_time);
        std::this_thread::sleep_until(this->time_point);
    } else {
        this->time_point = std::chrono::system_clock::now();
    }
}

Clock::Clock(int fps_limit = 0) {
    if (fps_limit != 0) {
        this->fps_limit = true;
        this->min_frame_time = 1000 / fps_limit;
    }
    this->time_point = std::chrono::system_clock::now();
}

unsigned Clock::elapsed_animation_ticks(const TimePoint& start, unsigned animation_frequency) {
    // cast duration to milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->time_point - start);
    // divide by the time a single tick of animation takes
    return duration.count() / animation_frequency;
}