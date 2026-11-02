#pragma once

/*
    MathPrimitives
    Copyright (c) 2026 Lisa Olsson
    http://github.com/lisaolsson/MathPrimitives
    http://www.bitsbylisa.se

    Licensed under the PolyForm Noncommercial License 1.0.0.
    See LICENSE.md for the full license terms.

    Short and simple vector math library for 2D, 3D, and 4D vectors. Implemented to provide basic vector operations
    for my own projects and experiments. 
    If you want to use it and are in need of other vector operations, please get in touch and I will consider adding them.
*/

#include <cmath>
#include <type_traits>
#include <cassert>
#include <cstddef>
#include <stdexcept>


namespace mp::vector {

    /*
    ---------------------------------
               VECTOR TYPES
    ---------------------------------
    Plain aggregate types for 2D, 3D, and 4D vectors with directly accessible components.
    Use {} for a zero-initialized vector.
    */
    template<typename T>
    struct Vec2 {
        T x, y;

        constexpr T& operator[](std::size_t i) {
            assert(i < 2);
            return i == 0 ? x : y;
        }

        constexpr const T& operator[](std::size_t i) const {
            assert(i < 2);
            return i == 0 ? x : y;
        }

        T& at(std::size_t i) {
            switch (i) {
                case 0: return x;
                case 1: return y;
                default: throw std::out_of_range("Vec2 index out of range");
            }        
        }

        const T& at(std::size_t i) const {
            switch (i) {
                case 0: return x;
                case 1: return y;
                default: throw std::out_of_range("Vec2 index out of range");
            }        
        }
    };

    template<typename T>
    struct Vec3 {
        T x, y, z;

        constexpr T& operator[](std::size_t i) {
            assert(i < 3);

            switch (i) {
                case 0: return x;
                case 1: return y;
                default: return z;
            }
        }

        constexpr const T& operator[](std::size_t i) const {
            assert(i < 3);

            switch (i) {
                case 0: return x;
                case 1: return y;
                default: return z;
            }
        }
        
        T& at(std::size_t i) {
            switch (i) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                default: throw std::out_of_range("Vec3 index out of range");
            }        
        }

        const T& at(std::size_t i) const {
            switch (i) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                default: throw std::out_of_range("Vec3 index out of range");
            }        
        }
    };

    template<typename T>
    struct Vec4 {
        T x, y, z, w;

        constexpr T& operator[](std::size_t i) {
            assert(i < 4);

            switch (i) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                default: return w;
            }
        }

        constexpr const T& operator[](std::size_t i) const {
            assert(i < 4);

            switch (i) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                default: return w;
            }
        }
        
        T& at(std::size_t i) {
            switch (i) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                case 3: return w;
                default: throw std::out_of_range("Vec4 index out of range");
            }        
        }

        const T& at(std::size_t i) const {
            switch (i) {
                case 0: return x;
                case 1: return y;
                case 2: return z;
                case 3: return w;
                default: throw std::out_of_range("Vec4 index out of range");
            }        
        }
    };

    /*
    ---------------------------------
               TYPE ALIASES
    ---------------------------------
    Convenient aliases for float- and double-component vector types.
    */
    using Vec2f = Vec2<float>;
    using Vec3f = Vec3<float>;
    using Vec4f = Vec4<float>;

    using Vec2d = Vec2<double>;
    using Vec3d = Vec3<double>;
    using Vec4d = Vec4<double>;


    /*
    ---------------------------------
                 ADDITION
    ---------------------------------
    Adds two vectors component-wise.
    operator+ returns a new vector; operator+= updates its left operand.
    */
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

    /*
    ---------------------------------
               SUBTRACTION
    ---------------------------------
    Subtracts corresponding components of two vectors.
    operator- returns a new vector; operator-= updates its left operand.
    */
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

    /*
    ---------------------------------
                 SCALING
    ---------------------------------
    Multiplies every component by a scalar.
    Supports v * s, s * v, and v *= s.

    The scalar must match the vector's component type.
    */
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

    /*
    ---------------------------------
      COMPONENT-WISE MULTIPLICATION
    ---------------------------------
    Multiplies corresponding components of two vectors using comp_mul(a, b).
    The vector expression a * b computes the dot product instead.
    */
    template<typename T>
    constexpr Vec2<T> comp_mul(const Vec2<T>& a, const Vec2<T>& b) { return {a.x * b.x, a.y * b.y}; }
    template<typename T>
    constexpr Vec3<T> comp_mul(const Vec3<T>& a, const Vec3<T>& b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
    template<typename T>
    constexpr Vec4<T> comp_mul(const Vec4<T>& a, const Vec4<T>& b) { return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }

    /*
    ---------------------------------
                 DIVISION
    ---------------------------------
    Divides every component by a scalar.
    Supports v / s and v /= s.

    The scalar must match the vector's component type.
    Integer division truncates toward zero.
    */
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

    /*
    ---------------------------------
                  MODULO
    ---------------------------------
    Computes the remainder of each component after division by a scalar.
    Supports v % s and v %= s.

    Uses % for integer components and std::fmod for floating-point components.
    The scalar must match the vector's component type.
    Negative components can produce negative remainders.
    */
    template<typename T>
    inline  Vec2<T> mod(const Vec2<T>& v, T s) {
        if constexpr (std::is_integral_v<T>) {
            return {v.x % s, v.y % s};
        }
        else {
            return {std::fmod(v.x, s), std::fmod(v.y, s)};
        }
    }
    template<typename T>
    inline Vec2<T> operator%(const Vec2<T>& v, T s) { return mod(v, s); }
    template<typename T>
    inline Vec2<T>& operator%=(Vec2<T>& v, T s) {
        v = mod(v, s);
        return v;
    }

    template<typename T>
    inline Vec3<T> mod(const Vec3<T>& v, T s) {
        if constexpr (std::is_integral_v<T>) {
            return {v.x % s, v.y % s, v.z % s};
        }
        else {
            return {std::fmod(v.x, s), std::fmod(v.y, s), std::fmod(v.z, s)};
        }
    }
    template<typename T>
    inline Vec3<T> operator%(const Vec3<T>& v, T s) { return mod(v, s); }
    template<typename T>
    inline Vec3<T>& operator%=(Vec3<T>& v, T s) {
        v = mod(v, s);
        return v;
    }

    template<typename T>
    inline Vec4<T> mod(const Vec4<T>& v, T s) {
        if constexpr (std::is_integral_v<T>) {
            return {v.x % s, v.y % s, v.z % s, v.w % s};
        }
        else {
            return {std::fmod(v.x, s), std::fmod(v.y, s), std::fmod(v.z, s), std::fmod(v.w, s)};
        }
    }
    template<typename T>
    inline Vec4<T> operator%(const Vec4<T>& v, T s) { return mod(v, s); }
    template<typename T>
    inline Vec4<T>& operator%=(Vec4<T>& v, T s) {
        v = mod(v, s);
        return v;
    }

    /*
    ---------------------------------
               EQUALITY
    ---------------------------------
    Compares vectors for component-wise equality.
    */
    template<typename T> 
    constexpr bool operator==(const Vec2<T>& a, const Vec2<T>& b) {
        return a.x == b.x && a.y == b.y;
    }
    template<typename T> 
    constexpr bool operator==(const Vec3<T>& a, const Vec3<T>& b) {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }
    template<typename T> 
    constexpr bool operator==(const Vec4<T>& a, const Vec4<T>& b) {
        return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
    }

    /*
    ---------------------------------
               APPROXIMATE EQUALITY
    ---------------------------------
    Compares vectors for component-wise approximate equality.
    */
    template<typename T>
    inline bool approx_equal(const Vec2<T>& a, const Vec2<T>& b, T epsilon) {
        return std::abs(a.x - b.x) <= epsilon 
            && std::abs(a.y - b.y) <= epsilon;
    }
    template<typename T>
    inline bool approx_equal(const Vec3<T>& a, const Vec3<T>& b, T epsilon) {
        return std::abs(a.x - b.x) <= epsilon 
            && std::abs(a.y - b.y) <= epsilon 
            && std::abs(a.z - b.z) <= epsilon;
    }
    template<typename T>
    inline bool approx_equal(const Vec4<T>& a, const Vec4<T>& b, T epsilon) {
        return std::abs(a.x - b.x) <= epsilon 
            && std::abs(a.y - b.y) <= epsilon 
            && std::abs(a.z - b.z) <= epsilon 
            && std::abs(a.w - b.w) <= epsilon;
    }

    /*
    ---------------------------------
               INEQUALITY
    ---------------------------------
    Compares vectors for component-wise inequality.
    True if at least one component differs.
    */
    template<typename T> 
    constexpr bool operator!=(const Vec2<T>& a, const Vec2<T>& b) {
        return !(a == b);
    }
    template<typename T> 
    constexpr bool operator!=(const Vec3<T>& a, const Vec3<T>& b) {
        return !(a == b);
    }
    template<typename T> 
    constexpr bool operator!=(const Vec4<T>& a, const Vec4<T>& b) {
        return !(a == b);
    }


    /*
    ---------------------------------
               DOT PRODUCT
    ---------------------------------
    Computes the scalar dot product of two vectors.
    Vector multiplication a * b is deliberately defined as dot(a, b).
    Use comp_mul(a, b) for component-wise multiplication.

    The result has the vector's component type.
    */
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

    /*
    ---------------------------------
              CROSS PRODUCT
    ---------------------------------
    Computes dimension-specific cross products.

    2D: cross(a, b) returns the signed scalar determinant.
    3D: cross(a, b) returns a perpendicular vector following the right-hand rule.
    4D: cross(a, b, c) returns a vector orthogonal to all three inputs.

    Results retain the component type and are not normalized.
    */
    template<typename T>
    constexpr T cross(const Vec2<T>& a, const Vec2<T>& b) {
        return a.x * b.y - a.y * b.x;
    }
    template<typename T>
    constexpr Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b) {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }
        template<typename T>
    constexpr Vec4<T> cross(const Vec4<T>& a, const Vec4<T>& b, const Vec4<T>& c) {
        return {
            -a.y * (b.z * c.w - b.w * c.z)
            +a.z * (b.y * c.w - b.w * c.y)
            -a.w * (b.y * c.z - b.z * c.y),

            a.x * (b.z * c.w - b.w * c.z)
            -a.z * (b.x * c.w - b.w * c.x)
            +a.w * (b.x * c.z - b.z * c.x),

            -a.x * (b.y * c.w - b.w * c.y)
            +a.y * (b.x * c.w - b.w * c.x)
            -a.w * (b.x * c.y - b.y * c.x),

            a.x * (b.y * c.z - b.z * c.y)
            -a.y * (b.x * c.z - b.z * c.x)
            +a.z * (b.x * c.y - b.y * c.x)
        };
    }

    /*
    ---------------------------------
              UNARY NEGATION
    ---------------------------------
    Negates every component of a vector using -v.
    The result retains the vector's component type.
    */
    template<typename T>
    constexpr Vec2<T> operator-(const Vec2<T>& v) { return {-v.x, -v.y}; }
    template<typename T>
    constexpr Vec3<T> operator-(const Vec3<T>& v) { return {-v.x, -v.y, -v.z}; }
    template<typename T>
    constexpr Vec4<T> operator-(const Vec4<T>& v) { return {-v.x, -v.y, -v.z, -v.w}; }

    /*
    ---------------------------------
                  LENGTH
    ---------------------------------
    Computes the Euclidean length of a vector.
    Uses direct squaring and std::sqrt for performance; std::hypot was slower in my benchmark.

    Integer components are converted to double before calculation, and the result is double.
    Floating-point components and results retain their original type.
    */
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    length(const Vec2<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec2<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y)
        };

        return std::sqrt(n.x * n.x + n.y * n.y); 
    }
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    length(const Vec3<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec3<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z)
        };

        return std::sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
    }
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    length(const Vec4<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec4<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z),
            static_cast<R>(v.w)
        };

        return std::sqrt(n.x * n.x + n.y * n.y + n.z * n.z + n.w * n.w);
    }
    
    /*
    ---------------------------------
              LENGTH SQUARED
    ---------------------------------
    Computes the sum of the squared components of a vector.
    Useful for comparing magnitudes without taking a square root.

    Integer components are converted to double before calculation, and the result is double.
    Floating-point components and results retain their original type.
    */
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    length_squared(const Vec2<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec2<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y)
        };

        return n.x * n.x + n.y * n.y;
    }
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    length_squared(const Vec3<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec3<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z)
        };

        return n.x * n.x + n.y * n.y + n.z * n.z;
    }
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    length_squared(const Vec4<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec4<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z),
            static_cast<R>(v.w)
        };

        return n.x * n.x + n.y * n.y + n.z * n.z + n.w * n.w;
    }

    /*
    ---------------------------------
              NORMALIZATION
    ---------------------------------
    Returns a unit vector pointing in the same direction as the input.
    Returns a zero vector if the computed length is zero or non-finite.

    Integer components are converted to double before calculation, and the result has double components.
    Floating-point vectors retain their component type.
    */
    template<typename T>
    constexpr auto normalize(const Vec2<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec2<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y)
        };

        R len = length(n);
        if (!(len > R{0}) || !std::isfinite(len))
            return Vec2<R>{};

        return n / len;
    }

    template<typename T>
    constexpr auto normalize(const Vec3<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec3<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z)
        };

        R len = length(n);
        if (!(len > R{0}) || !std::isfinite(len))
            return Vec3<R>{};

        return n / len;
    }

    template<typename T>
    constexpr auto normalize(const Vec4<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec4<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z),
            static_cast<R>(v.w)
        };

        R len = length(n);
        if (!(len > R{0}) || !std::isfinite(len))
            return Vec4<R>{};

        return n / len;
    }

    /*
    ---------------------------------
           LINEAR INTERPOLATION
    ---------------------------------
    Interpolates component-wise from a to b using t.
    Returns a exactly when t == 0 and b exactly when t == 1.

    t is not clamped; values outside [0, 1] extrapolate.
    The vectors and t must have matching component types.
    */
    template<typename T>
    constexpr Vec2<T> lerp(const Vec2<T>& a, const Vec2<T>& b, T t) {
        if (t == T{0}) return a;
        if (t == T{1}) return b;

        return (T{1} - t) * a + t * b;
    }

    template<typename T>
    constexpr Vec3<T> lerp(const Vec3<T>& a, const Vec3<T>& b, T t) {
        if (t == T{0}) return a;
        if (t == T{1}) return b;

        return (T{1} - t) * a + t * b;
    }

    template<typename T>
    constexpr Vec4<T> lerp(const Vec4<T>& a, const Vec4<T>& b, T t) {
        if (t == T{0}) return a;
        if (t == T{1}) return b;

        return (T{1} - t) * a + t * b;
    }
    
    /*
    ---------------------------------
                 DISTANCE
    ---------------------------------
    Computes the Euclidean distance between two vectors.

    Integer components are converted to double before calculation, and the result is double.
    Floating-point components and results retain their original type.
    */
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    distance(const Vec2<T>& a, const Vec2<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        return length(
            Vec2<R>{
                static_cast<R>(b.x) - static_cast<R>(a.x), 
                static_cast<R>(b.y) - static_cast<R>(a.y)});
    }

    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    distance(const Vec3<T>& a, const Vec3<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;
    
        return length(
            Vec3<R>{
                static_cast<R>(b.x) - static_cast<R>(a.x), 
                static_cast<R>(b.y) - static_cast<R>(a.y), 
                static_cast<R>(b.z) - static_cast<R>(a.z)});
    }

    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    distance(const Vec4<T>& a, const Vec4<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        return length(
            Vec4<R>{
                static_cast<R>(b.x) - static_cast<R>(a.x), 
                static_cast<R>(b.y) - static_cast<R>(a.y), 
                static_cast<R>(b.z) - static_cast<R>(a.z), 
                static_cast<R>(b.w) - static_cast<R>(a.w)});
    }

    /*
    ---------------------------------
             DISTANCE SQUARED
    ---------------------------------
    Computes the squared Euclidean distance between two vectors.
    Useful for comparing distances without taking a square root.

    Integer components are converted to double before calculation, and the result is double.
    Floating-point components and results retain their original type.
    */
    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    distance_squared(const Vec2<T>& a, const Vec2<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        return length_squared(
            Vec2<R>{
                static_cast<R>(b.x) - static_cast<R>(a.x), 
                static_cast<R>(b.y) - static_cast<R>(a.y)});
    }

    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    distance_squared(const Vec3<T>& a, const Vec3<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        return length_squared(
            Vec3<R>{
                static_cast<R>(b.x) - static_cast<R>(a.x), 
                static_cast<R>(b.y) - static_cast<R>(a.y), 
                static_cast<R>(b.z) - static_cast<R>(a.z)});
    }

    template<typename T>
    constexpr std::conditional_t<std::is_integral_v<T>, double, T> 
    distance_squared(const Vec4<T>& a, const Vec4<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        return length_squared(
            Vec4<R>{
                static_cast<R>(b.x) - static_cast<R>(a.x), 
                static_cast<R>(b.y) - static_cast<R>(a.y), 
                static_cast<R>(b.z) - static_cast<R>(a.z), 
                static_cast<R>(b.w) - static_cast<R>(a.w)});
    }

} // namespace mp::vector
