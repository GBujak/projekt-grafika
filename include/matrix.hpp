#pragma once

template <typename T>
class Matrix {
    std::vector<T> inner;
    unsigned dimx, dimy;

    public:
    Matrix(unsigned dimx, unsigned dimy)
        : dimx(dimx), dimy(dimy) {
        inner.resize(dimx * dimy);
    }

    unsigned dimx() const { return dimx; }
    unsigned dimy() const { return dimy; }

    T& at(unsigned int x, unsigned int y) {
        return inner[dimx * y + x];
    }
};