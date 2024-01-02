#pragma once

#include "tuple.hpp"

namespace GYDM {
    template<typename T>
    class Point : public GYDM::Tuple<GYDM::Point, T> {
    public:
        static const GYDM::Point<T> O;

    public:
        Point() = default;
        Point(T x, T y) : GYDM::Tuple<GYDM::Point, T>(x, y) {}

        template<typename U>
        explicit Point(const GYDM::Point<U>& v)
            : GYDM::Tuple<GYDM::Point, T>(T(v.x), T(v.y)) {}

        template<typename U>
        explicit Point(const GYDM::Point<U>& v, T sx, T sy)
            : GYDM::Tuple<GYDM::Point, T>(T(v.x * sx), T(v.y * sy)) {}

        ~Point() noexcept {}
    };

    typedef GYDM::Point<float> Dot;

    template<typename T> const GYDM::Point<T> GYDM::Point<T>::O = {};
}
