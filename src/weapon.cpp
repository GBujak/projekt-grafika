#include <weapon.hpp>
#include <SDL2/SDL.h>

#include <iostream>

Weapon::Weapon(unsigned bullet_per_shot, unsigned bullet_velocity,
    unsigned recovery_time, unsigned innacuracy_time, unsigned base_spread,
    std::vector<Bullet>* bullet_store)
    : bullet_per_shot(bullet_per_shot), bullet_velocity(bullet_velocity),
    recovery_time(recovery_time), inaccuracy_time(innacuracy_time),
    base_spread(base_spread), last_shot(SDL_GetTicks()), bullet_store(bullet_store) {}

auto Weapon::try_shoot(Point2f position, Point2f aim_vector, unsigned tick) -> void {
    aim_vector.normalize();
    for (unsigned i = 0; i < bullet_per_shot; i++) {
        auto velocity_vector = aim_vector;
        velocity_vector.mul_scalar(bullet_velocity);
        auto bullet = Bullet {position, velocity_vector, tick};
        bullet_store->push_back(bullet);
    }
}