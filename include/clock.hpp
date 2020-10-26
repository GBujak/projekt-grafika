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

    // Returns elapsed ticks of animation that started at 'start' and
    // has a tick frequency of 'animation_frequency' in 1/millisecond
    unsigned elapsed_animation_ticks(const TimePoint& start, unsigned animation_frequency);
};