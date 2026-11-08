#pragma once

/*
    MathPrimitives
    Copyright (c) 2026 Lisa Olsson
    http://github.com/lisaolsson/MathPrimitives
    http://www.bitsbylisa.se

    Licensed under the PolyForm Noncommercial License 1.0.0.
    See LICENSE.md for the full license terms.

*/


#pragma once

#include "vectors.hpp"

namespace mp::vector {

    /*
    ---------------------------------
            2D VECTOR CONSTANTS
    ---------------------------------
    Positive Y points up.
    */

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::ZERO{T{0}, T{0}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::ONE{T{1}, T{1}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::NEG_ONE{T{-1}, T{-1}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::X{T{1}, T{0}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::Y{T{0}, T{1}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::NEG_X{T{-1}, T{0}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::NEG_Y{T{0}, T{-1}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::RIGHT{T{1}, T{0}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::LEFT{T{-1}, T{0}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::UP{T{0}, T{1}};

    template<typename T>
    inline constexpr Vec2<T> Vec2<T>::DOWN{T{0}, T{-1}};


    /*
    ---------------------------------
            3D VECTOR CONSTANTS
    ---------------------------------
    Right-handed coordinates.
    Positive Y points up.
    Forward points along negative Z.
    */

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::ZERO{T{0}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::ONE{T{1}, T{1}, T{1}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::NEG_ONE{T{-1}, T{-1}, T{-1}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::X{T{1}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::Y{T{0}, T{1}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::Z{T{0}, T{0}, T{1}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::NEG_X{T{-1}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::NEG_Y{T{0}, T{-1}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::NEG_Z{T{0}, T{0}, T{-1}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::RIGHT{T{1}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::LEFT{T{-1}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::UP{T{0}, T{1}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::DOWN{T{0}, T{-1}, T{0}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::FORWARD{T{0}, T{0}, T{-1}};

    template<typename T>
    inline constexpr Vec3<T> Vec3<T>::BACK{T{0}, T{0}, T{1}};


    /*
    ---------------------------------
            4D VECTOR CONSTANTS
    ---------------------------------
    Mathematical coordinate axes.
    No directional coordinate convention.
    */

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::ZERO{T{0}, T{0}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::ONE{T{1}, T{1}, T{1}, T{1}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::NEG_ONE{T{-1}, T{-1}, T{-1}, T{-1}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::X{T{1}, T{0}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::Y{T{0}, T{1}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::Z{T{0}, T{0}, T{1}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::W{T{0}, T{0}, T{0}, T{1}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::NEG_X{T{-1}, T{0}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::NEG_Y{T{0}, T{-1}, T{0}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::NEG_Z{T{0}, T{0}, T{-1}, T{0}};

    template<typename T>
    inline constexpr Vec4<T> Vec4<T>::NEG_W{T{0}, T{0}, T{0}, T{-1}};

} // namespace mp::vector
