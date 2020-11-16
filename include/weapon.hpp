#pragma once

#include <vector>

#include <geometry.hpp>
#include <bullet.hpp>

class Weapon {
    unsigned bullet_per_shot;
    unsigned bullet_velocity;
    unsigned recovery_time;
    unsigned inaccuracy_time;
    unsigned base_spread;
    unsigned last_shot;
    std::vector<Bullet>* bullet_store;

    public: 
    Weapon(unsigned bullet_per_shot, unsigned bullet_velocity,
           unsigned recovery_time,   unsigned innacuracy_time,
           unsigned base_spread,     std::vector<Bullet>* bullet_store);
    
    auto try_shoot(Point2f position, Point2f aim_vector, unsigned tick) -> void;
};