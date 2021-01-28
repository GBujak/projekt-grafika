#pragma once

#include <weapon.hpp>

class Enemy {
    Weapon m_weapon;
    Point2f m_position;

    public:
    Enemy(Weapon weapon, Point2f position);

    bool can_see(Point2f target);
    void shoot_if_visible(Point2f target, unsigned tick);

    Point2f position() { return m_position; }
};
