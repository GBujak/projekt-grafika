#pragma once

#include <chrono>
#include <thread>

using TimePoint = std::chrono::system_clock::time_point;
using Duration = std::chrono::duration<long, std::milli>;

class Clock {
    TimePoint time_point;
    bool fps_limit;
    long min_frame_time;

    public:
    Clock(int fps_limit); 

    const TimePoint& next(); 
};