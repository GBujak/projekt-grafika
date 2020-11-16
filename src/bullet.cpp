#include <bullet.hpp>

Bullet::Bullet(Point2f position, Point2f velocity)
    : position(position), velocity(velocity) {}

auto Bullet::update(unsigned tick) -> void {
}

auto Bullet::draw(SDL_Renderer* renderer, Point2f camera_pos, Point2f screen_resolution) -> void {

}