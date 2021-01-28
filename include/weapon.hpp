#pragma once

#include <vector>

#include <geometry.hpp>
#include <bullet.hpp>
#include <bullet_system.hpp>

class Weapon {
    unsigned bullet_per_shot;
    unsigned bullet_velocity;
    unsigned recovery_time;
    unsigned inaccuracy_time;
    unsigned base_spread;
    unsigned last_shot;

    BulletSystem& m_bullet_system;

    public: 
    Weapon(unsigned bullet_per_shot, unsigned bullet_velocity,
           unsigned recovery_time,   unsigned innacuracy_time,
           unsigned base_spread,     BulletSystem& bullet_system);
        
    Weapon& operator=(const Weapon& other) {
        bullet_per_shot = other.bullet_per_shot;
        bullet_velocity = other.bullet_velocity;
        recovery_time = other.recovery_time;
        inaccuracy_time = other.inaccuracy_time;
        base_spread = other.base_spread;
        last_shot = other.last_shot;

        return *this;
    }
    
    auto try_shoot(Point2f position, Point2f aim_vector, unsigned tick) -> void;
};