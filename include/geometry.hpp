#pragma once

#include <algorithm>

struct Point2f {
    float x, y;
    Point2f() : x(0.0), y(0.0) {}
    Point2f(float x, float y) : x(x), y(y) {}

    auto add_scalar(float scalar) -> void {
        x += scalar;
        y += scalar;
    }

    auto div_scalar(float scalar) -> void {
        x /= scalar;
        y /= scalar;
    }

    auto mul_scalar(float scalar) -> void {
        x *= scalar;
        y *= scalar;
    }

    auto normalize() -> void {
        if (std::abs(x) > std::abs(y)) {
            div_scalar(std::abs(x));
        } else {
            div_scalar(std::abs(y));
        }
    }

    auto mul_point2f(Point2f other) -> void {
        x *= other.x;
        y *= other.y;
    }

    auto add_point2f(Point2f other) -> void {
        x += other.x;
        y += other.y;
    }

    auto sub_point2f(Point2f other) -> void {
        x -= other.x;
        y -= other.y;
    }
};

struct Line {
    Point2f a, b;
};