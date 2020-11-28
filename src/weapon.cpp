#include <weapon.hpp>
#include <SDL2/SDL.h>

#include <iostream>

Weapon::Weapon(unsigned bullet_per_shot, unsigned bullet_velocity,
    unsigned recovery_time, unsigned innacuracy_time, unsigned base_spread,
    World& world)
    : bullet_per_shot(bullet_per_shot), bullet_velocity(bullet_velocity),
    recovery_time(recovery_time), inaccuracy_time(innacuracy_time),
    base_spread(base_spread), last_shot(0), world(world) {}

auto Weapon::try_shoot(Point2f position, Point2f aim_vector, unsigned tick) -> void {
    aim_vector.normalize();
    auto tick_diff = tick - last_shot;
    if (tick_diff < recovery_time) return;

    for (unsigned i = 0; i < bullet_per_shot; i++) {
        auto velocity_vector = aim_vector;
        velocity_vector.mul_scalar(bullet_velocity);
        auto bullet = Bullet {position, velocity_vector, tick};
        world.add_bullet(bullet);
    }

    last_shot = tick;
}