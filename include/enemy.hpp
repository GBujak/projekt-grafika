#pragma once

#include <weapon.hpp>
#include <floor.hpp>

class Enemy {
    Weapon m_weapon;
    Point2f m_position;

    public:
    Enemy(Weapon weapon, Point2f position);

    bool can_see(Point2f target, Floor& floor);
    void shoot_if_visible(Point2f target, Floor& floor, unsigned tick);
    void update(unsigned tick, Point2f player_position, Floor& floor);

    Point2f position() { return m_position; }
};
