#include <weapon.hpp>
#include <SDL/SDL.h>

Weapon::Weapon(unsigned bullet_per_shot, unsigned bullet_velocity,
    unsigned recovery_time, unsigned innacuracy_time, unsigned base_spread)
    : bullet_per_shot(bullet_per_shot), bullet_velocity(bullet_velocity),
    recovery_time(recovery_time), inaccuracy_time(innacuracy_time),
    base_spread(base_spread), last_shot(SDL_GetTicks()) {}

