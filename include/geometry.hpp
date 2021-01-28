#pragma once

#include <algorithm>
#include <cmath>

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
        auto length = std::sqrt((x*x) + (y*y));
        div_scalar(length);
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

    auto normalized() -> Point2f const {
        auto other = *this;
        other.normalize();
        return other;
    }

    auto operator-(const Point2f& other) const {
        auto result = Point2f{};
        result.x = this->x - other.x;
        result.y = this->y - other.y;
        return result;
    }

    auto length() -> float {
        return std::sqrt((x*x) + (y*y));
    }
};

struct Line {
    Point2f a, b;
};
