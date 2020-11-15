#pragma once

struct Point2f {
    float x, y;
    Point2f() : x(0.0), y(0.0) {}
    Point2f(float x, float y) : x(x), y(y) {}
};

struct Line {
    Point2f a, b;
};