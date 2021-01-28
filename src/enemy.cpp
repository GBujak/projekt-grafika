#include <enemy.hpp>


Enemy::Enemy(Weapon weapon, Point2f position): m_weapon(weapon), m_position(position) {}


bool Enemy::can_see(Point2f target) {
    return true;
}

void Enemy::shoot_if_visible(Point2f target, unsigned tick) {
    if (can_see(target))
        m_weapon.try_shoot(m_position, target - m_position, tick);
}
