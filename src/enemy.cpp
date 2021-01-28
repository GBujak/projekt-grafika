#include <enemy.hpp>
#include <consts.hpp>

Enemy::Enemy(Weapon weapon, Point2f position):
    m_weapon(weapon), m_position(position) {}

bool Enemy::can_see(Point2f target, Floor& floor) {
    target.add_scalar(0.5f * PERSON_WIDTH);

    if ((m_position - target).length() > 8.0f) return false;

    auto point = m_position;
    auto step = (target - m_position).normalized();
    step.mul_scalar(0.5f);
    point.add_point2f(step);

    while ((m_position - point).length() < (m_position - target).length()) {
        if (floor.does_collide(point, true)) return false;
        point.add_point2f(step);
    }

    return true;
}

void Enemy::shoot_if_visible(Point2f target, Floor& floor, unsigned tick) {
    if (can_see(target, floor))
        m_weapon.try_shoot(m_position, target - m_position, tick);
}

void Enemy::update(unsigned tick, Point2f player_position, Floor& floor) {
    this->shoot_if_visible(player_position, floor, tick);
}