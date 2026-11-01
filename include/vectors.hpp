#pragma once

/*
    Short and simple vector math library for 2D, 3D, and 4D vectors. Implemented to provide basic vector operations
    for my own projects and experiments. 
    If you want to use it and are in need of other vector operations, please get in touch and I will consider adding them.
*/

#include <cmath>

namespace mp::vector {

    // Basic structs and aliases for 2D, 3D, and 4D vectors
    template<typename T>
    struct Vec2 {
        T x, y;
    };

    template<typename T>
    struct Vec3 {
        T x, y, z;
    };

    template<typename T>
    struct Vec4 {
        T x, y, z, w;
    };

    // Define common vector types for convenience
    using Vec2f = Vec2<float>;
    using Vec3f = Vec3<float>;
    using Vec4f = Vec4<float>;

    using Vec2d = Vec2<double>;
    using Vec3d = Vec3<double>;
    using Vec4d = Vec4<double>;


    // Define addition functions for 2D, 3D, and 4D vectors
    template<typename T>
    constexpr Vec2<T> add(const Vec2<T>& a, const Vec2<T>& b) { return {a.x + b.x, a.y + b.y};}
    template<typename T>
    constexpr Vec2<T> operator+(const Vec2<T>& a, const Vec2<T>& b) { return add(a, b); }
    template<typename T>
    constexpr Vec2<T>& operator+=(Vec2<T>& a, const Vec2<T>& b) { a.x += b.x; a.y += b.y; return a; }

    template<typename T>
    constexpr Vec3<T> add(const Vec3<T>& a, const Vec3<T>& b) { return {a.x + b.x, a.y + b.y, a.z + b.z};}
    template<typename T>
    constexpr Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b) { return add(a, b); }
    template<typename T>
    constexpr Vec3<T>& operator+=(Vec3<T>& a, const Vec3<T>& b) { a.x += b.x; a.y += b.y; a.z += b.z; return a; }

    template<typename T>
    constexpr Vec4<T> add(const Vec4<T>& a, const Vec4<T>& b) { return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};}
    template<typename T>
    constexpr Vec4<T> operator+(const Vec4<T>& a, const Vec4<T>& b) { return add(a, b); }
    template<typename T>
    constexpr Vec4<T>& operator+=(Vec4<T>& a, const Vec4<T>& b) { a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w; return a; }

    // Define subtraction functions for 2D, 3D, and 4D vectors
    template<typename T>
    constexpr Vec2<T> sub(const Vec2<T>& a, const Vec2<T>& b) { return {a.x - b.x, a.y - b.y}; }
    template<typename T>
    constexpr Vec2<T> operator-(const Vec2<T>& a, const Vec2<T>& b) { return sub(a, b); }
    template<typename T>
    constexpr Vec2<T>& operator-=(Vec2<T>& a, const Vec2<T>& b) { a.x -= b.x; a.y -= b.y; return a; }

    template<typename T>
    constexpr Vec3<T> sub(const Vec3<T>& a, const Vec3<T>& b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
    template<typename T>
    constexpr Vec3<T> operator-(const Vec3<T>& a, const Vec3<T>& b) { return sub(a, b); }
    template<typename T>
    constexpr Vec3<T>& operator-=(Vec3<T>& a, const Vec3<T>& b) { a.x -= b.x; a.y -= b.y; a.z -= b.z; return a; }

    template<typename T>
    constexpr Vec4<T> sub(const Vec4<T>& a, const Vec4<T>& b) { return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
    template<typename T>
    constexpr Vec4<T> operator-(const Vec4<T>& a, const Vec4<T>& b) { return sub(a, b); }
    template<typename T>
    constexpr Vec4<T>& operator-=(Vec4<T>& a, const Vec4<T>& b) { a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w; return a; }

    // Define scale functions for 2D, 3D, and 4D vectors
    template<typename T>
    constexpr Vec2<T> scale(const Vec2<T>& v, T s) { return {v.x * s, v.y * s}; }
    template<typename T>
    constexpr Vec2<T> operator*(const Vec2<T>& v, T s) { return scale(v, s); }
    template<typename T>
    constexpr Vec2<T> operator*(T s, const Vec2<T>& v) { return scale(v, s); }
    template<typename T>
    constexpr Vec2<T>& operator*=(Vec2<T>& v, T s) { v.x *= s; v.y *= s; return v; }

    template<typename T>
    constexpr Vec3<T> scale(const Vec3<T>& v, T s) { return {v.x * s, v.y * s, v.z * s}; }
    template<typename T>
    constexpr Vec3<T> operator*(const Vec3<T>& v, T s) { return scale(v, s); }
    template<typename T>
    constexpr Vec3<T> operator*(T s, const Vec3<T>& v) { return scale(v, s); }
    template<typename T>
    constexpr Vec3<T>& operator*=(Vec3<T>& v, T s) { v.x *= s; v.y *= s; v.z *= s; return v; }

    template<typename T>
    constexpr Vec4<T> scale(const Vec4<T>& v, T s) { return {v.x * s, v.y * s, v.z * s, v.w * s}; }
    template<typename T>
    constexpr Vec4<T> operator*(const Vec4<T>& v, T s) { return scale(v, s); }
    template<typename T>
    constexpr Vec4<T> operator*(T s, const Vec4<T>& v) { return scale(v, s); }
    template<typename T>
    constexpr Vec4<T>& operator*=(Vec4<T>& v, T s) { v.x *= s; v.y *= s; v.z *= s; v.w *= s; return v; }

    // Define division functions for 2D, 3D, and 4D vectors
    template<typename T>
    constexpr Vec2<T> div(const Vec2<T>& v, T s) { return {v.x / s, v.y / s}; }
    template<typename T>
    constexpr Vec2<T> operator/(const Vec2<T>& v, T s) { return div(v, s); }
    template<typename T>
    constexpr Vec2<T>& operator/=(Vec2<T>& v, T s) { v.x /= s; v.y /= s; return v; }

    template<typename T>
    constexpr Vec3<T> div(const Vec3<T>& v, T s) { return {v.x / s, v.y / s, v.z / s}; }
    template<typename T>
    constexpr Vec3<T> operator/(const Vec3<T>& v, T s) { return div(v, s); }
    template<typename T>
    constexpr Vec3<T>& operator/=(Vec3<T>& v, T s) { v.x /= s; v.y /= s; v.z /= s; return v; }

    template<typename T>
    constexpr Vec4<T> div(const Vec4<T>& v, T s) { return {v.x / s, v.y / s, v.z / s, v.w / s}; }
    template<typename T>
    constexpr Vec4<T> operator/(const Vec4<T>& v, T s) { return div(v, s); }
    template<typename T>
    constexpr Vec4<T>& operator/=(Vec4<T>& v, T s) { v.x /= s; v.y /= s; v.z /= s; v.w /= s; return v; }

    // Define dot product functions for 2D, 3D, and 4D vectors
    // I have on purpose defined multiplication as the dot product for vectors
    // This means that using the * operator between two vectors will yield their dot product rather than a component-wise multiplication
    template<typename T>
    constexpr T dot(const Vec2<T>& a, const Vec2<T>& b) { return a.x * b.x + a.y * b.y; }
    template<typename T>
    constexpr T operator*(const Vec2<T>& a, const Vec2<T>& b) { return dot(a, b); }
    
    template<typename T>
    constexpr T dot(const Vec3<T>& a, const Vec3<T>& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    template<typename T>
    constexpr T operator*(const Vec3<T>& a, const Vec3<T>& b) { return dot(a, b); }

    template<typename T>
    constexpr T dot(const Vec4<T>& a, const Vec4<T>& b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
    template<typename T>
    constexpr T operator*(const Vec4<T>& a, const Vec4<T>& b) { return dot(a, b); }

    // Define cross products
    template<typename T>
    constexpr Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b) {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    // Define length functions for vectors
    template<typename T>
    constexpr T length(const Vec2<T>& v) { return std::sqrt(v.x * v.x + v.y * v.y); }
    template<typename T>
    constexpr T length(const Vec3<T>& v) { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
    template<typename T>
    constexpr T length(const Vec4<T>& v) { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }
    
    // Define squared length functions for vectors
    template<typename T>
    constexpr T length_squared(const Vec2<T>& v) { return v.x * v.x + v.y * v.y; }
    template<typename T>
    constexpr T length_squared(const Vec3<T>& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
    template<typename T>
    constexpr T length_squared(const Vec4<T>& v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }

    // Define normalization functions for vectors
    template<typename T>
    constexpr Vec2<T> normalize(const Vec2<T>& v) { 
        T len = length(v); 
        if(!(len > 0.0) || !std::isfinite(len))
            return {0, 0};
        return v / len; 
    }

    template<typename T>
    constexpr Vec3<T> normalize(const Vec3<T>& v) { 
        T len = length(v); 
        if(!(len > 0.0) || !std::isfinite(len))
            return {0, 0, 0};
        return v / len; 
    }

    template<typename T>
    constexpr Vec4<T> normalize(const Vec4<T>& v) { 
        T len = length(v); 
        if(!(len > 0.0) || !std::isfinite(len))
            return {0, 0, 0, 0};
        return v / len; 
    }

} // namespace mp::vector