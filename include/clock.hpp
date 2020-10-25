#pragma once

#include <chrono>
#include <thread>

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
using Duration = std::chrono::duration<int, std::milli>;

class Clock {
    TimePoint time_point;
    bool fps_limit;
    Duration min_frame_time;

    public:
    Clock(int fps_limit); 

    const TimePoint& next(); 
};