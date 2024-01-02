#pragma once

#include "tuple.hpp"
#include "point.hpp"

namespace GYDM {
    template<typename T>
    class EuclideanVector : public GYDM::Tuple<GYDM::EuclideanVector, T> {
    public:
        static const GYDM::EuclideanVector<T> O;

    public:
        EuclideanVector() = default;
        EuclideanVector(T x, T y) : Tuple<GYDM::EuclideanVector, T>(x, y) {}
        EuclideanVector(const GYDM::Point<T>& pt) : Tuple<GYDM::EuclideanVector, T>(pt.x, pt.y) {}
        EuclideanVector(const GYDM::Point<T>& sp, const GYDM::Point<T>& ep)
            : Tuple<GYDM::EuclideanVector, T>(ep.x - sp.x, ep.y - sp.y) {}

        template <typename U>
        explicit EuclideanVector(const GYDM::EuclideanVector<U>& v)
            : GYDM::Tuple<GYDM::EuclideanVector, U>(T(v.x), T(v.y)) {}

        template<typename U>
        explicit EuclideanVector(const GYDM::EuclideanVector<U>& v, T sx, T sy)
            : GYDM::Tuple<GYDM::EuclideanVector, T>(T(v.x * sx), T(v.y * sy)) {}

        ~EuclideanVector() noexcept {}
    };

    typedef GYDM::EuclideanVector<float> Vector;

    template<typename T> const GYDM::EuclideanVector<T> GYDM::EuclideanVector<T>::O = {};
}
