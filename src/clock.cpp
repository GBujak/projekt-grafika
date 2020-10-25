#include <clock.hpp>

const TimePoint& Clock::next() {
    auto now = std::chrono::system_clock::now();
    if (fps_limit) {
        auto fps_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - time_point);
        if (fps_time < min_frame_time)
            std::this_thread::sleep_for(fps_time);
    }

    return time_point;
}

Clock::Clock(int fps_limit = 0) {
    if (fps_limit != 0) {
        this->fps_limit = true;
        this->min_frame_time = Duration(1000 / fps_limit);
    }
    this->time_point = std::chrono::system_clock::now();
}