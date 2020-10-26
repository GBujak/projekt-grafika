#include <clock.hpp>

const TimePoint& Clock::next() {
    if (this->fps_limit) {
        this->time_point += std::chrono::milliseconds(min_frame_time);
        std::this_thread::sleep_until(this->time_point);
    } else {
        this->time_point = std::chrono::system_clock::now();
    }
    return time_point;
}

Clock::Clock(int fps_limit = 0) {
    if (fps_limit != 0) {
        this->fps_limit = true;
        this->min_frame_time = 1000 / fps_limit;
    }
    this->time_point = std::chrono::system_clock::now();
}