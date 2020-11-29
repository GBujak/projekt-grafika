#include <physics_entity.hpp>

#include <consts.hpp>

auto PhysicsEntity::update(Uint32 current_tick) -> void {
    auto time_diff = current_tick - m_last_update_tick;
    auto position_diff = m_velocity;
    position_diff.mul_scalar((float) time_diff / (float) ACCELERATION_UNIT);
    m_position.add_point2f(position_diff);
    m_last_update_tick = current_tick;
}

auto PhysicsEntity::next_tick_position(Uint32 tick) -> Point2f {
    auto time_diff = tick - m_last_update_tick;
    auto position_diff = m_velocity;
    position_diff.mul_scalar((float) time_diff / (float) ACCELERATION_UNIT);
    auto next_position = Point2f{m_position};
    next_position.add_point2f(position_diff);
    return next_position;
}