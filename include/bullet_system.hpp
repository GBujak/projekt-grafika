#pragma once

#include <bullet.hpp>
#include <vector>

class BulletSystem {
    std::vector<Bullet> m_bullets;

    public:
    std::vector<Bullet>& bullets() { return m_bullets; }
    void add_bullet(Bullet bullet) {
        m_bullets.push_back(bullet);
    }
};