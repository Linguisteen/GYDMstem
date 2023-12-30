#pragma once

#include <vector>

namespace GYDM {
    typedef std::vector<std::pair<float, float>> polygon_vertices;

    GYDM::polygon_vertices regular_polygon_vertices(size_t n, float radius, float rotation);
}
