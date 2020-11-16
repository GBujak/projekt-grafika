#pragma once

#include <geometry.hpp>

class Weapon {
    unsigned bullet_per_shot;
    unsigned bullet_velocity;
    unsigned recovery_time;
    unsigned inaccuracy_time;
    unsigned base_spread;
    unsigned last_shot;

    public: 
    Weapon(unsigned bullet_per_shot, unsigned bullet_velocity,
           unsigned recovery_time,   unsigned innacuracy_time, unsigned base_spread);
    
    auto try_shoot(Point2f aim_vector) -> void;
};