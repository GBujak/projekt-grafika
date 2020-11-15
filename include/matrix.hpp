#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Matrix {
    std::vector<T> inner;
    unsigned m_dimx, m_dimy;

    public:
    Matrix(unsigned dimx, unsigned dimy)
            : m_dimx(dimx), m_dimy(dimy) {
        inner.resize(m_dimx * m_dimy);
    }

    Matrix(std::vector<T> vector, unsigned dimx, unsigned dimy)
            : inner(vector), m_dimx(dimx), m_dimy(dimy) {
        if (inner.size() != m_dimx * m_dimy) {
            std::cerr << "Bad matrix dimensions" << std::endl;
            abort();
        }
    }

    unsigned dimx() const { return m_dimx; }
    unsigned dimy() const { return m_dimy; }

    T& at(unsigned int x, unsigned int y) {
        return inner[m_dimx * y + x];
    }
};
