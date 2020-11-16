#pragma once

#include <vector>

#include <matrix.hpp>
#include <tile.hpp>
#include <person.hpp>
#include <world_config.hpp>
#include <floor.hpp>

class World {
    std::vector<Floor> m_rooms;
    int m_current_room = -1;

    Person m_player;

    std::vector<Bullet> bullets;

    public:
    World();
    World(WorldConfig& config);
    auto current_room() -> Floor*;

    auto player() -> Person& { return m_player; }

    auto update(unsigned tick) -> void;
    auto draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f resolution) -> void;
};
