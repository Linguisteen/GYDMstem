#pragma once

#include <vector>

#include "point.hpp"

namespace GYDM {
    typedef std::vector<GYDM::Dot> polygon_vertices;

    GYDM::polygon_vertices regular_polygon_vertices(size_t n, float radius, float rotation);
}
