#pragma once

class Tile {
    public:
    enum class Type {
        Space,
        Wall,
        Door,
        Window,
    };

    private:
    unsigned m_door_room_id = 0;
    Type m_type = Type::Wall;

    public:
    Tile(Type type, unsigned door_room_id = 0)
        : m_type(type), m_door_room_id(door_room_id) {}

    Type type() const { return m_type; }
    unsigned leads_to() const { return m_door_room_id; }
};
