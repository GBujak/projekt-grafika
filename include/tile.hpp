#pragma once

#include <SDL2/SDL.h>

class Tile {
    public:
    enum class Type {
        Space,
        Wall,
        Window,
        Door,
    };

    private:
    Type m_type;
    Uint8 m_door_room_id;

    public:
    Tile() : m_type(Type::Space), m_door_room_id(-1) {}
    Tile(Type type, int door_room_id = -1)
        : m_type(type), m_door_room_id(door_room_id) {}

    Type type() const { return m_type; }
    unsigned leads_to() const { return m_door_room_id; }
};
