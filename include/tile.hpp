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
    Type m_type;
    int m_door_room_id;

    public:
    Tile(Type type, int door_room_id = -1)
        : m_type(type), m_door_room_id(door_room_id) {}

    Type type() const { return m_type; }
    unsigned leads_to() const { return m_door_room_id; }
};
