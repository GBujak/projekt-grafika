#pragma once

#include <vector>

template <typename T>
class Matrix {
    std::vector<T> inner;
    unsigned m_dimx, m_dimy;

    public:
    Matrix(unsigned dimx, unsigned dimy)
        : m_dimx(dimx), m_dimy(dimy) {
        inner.resize(m_dimx * m_dimy);
    }

    unsigned dimx() const { return m_dimx; }
    unsigned dimy() const { return m_dimy; }

    T& at(unsigned int x, unsigned int y) {
        return inner[m_dimx * y + x];
    }
};
