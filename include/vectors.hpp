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
    Multiplies corresponding components of two vectors using cmul(a, b).
    The vector expression a * b computes the dot product instead.
    */
    template<typename T>
    constexpr Vec2<T> cmul(const Vec2<T>& a, const Vec2<T>& b) { return {a.x * b.x, a.y * b.y}; }
    template<typename T>
    constexpr Vec3<T> cmul(const Vec3<T>& a, const Vec3<T>& b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
    template<typename T>
    constexpr Vec4<T> cmul(const Vec4<T>& a, const Vec4<T>& b) { return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }

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
                COMPONENT-WISE DIVISION
    ---------------------------------
    Computes the component-wise division of two vectors.
    Integer components use integer division, truncating toward zero.
    The result retains the vector's component type.
    */
    template<typename T>
    constexpr Vec2<T> cdiv(const Vec2<T>& a, const Vec2<T>& b) { return {a.x / b.x, a.y / b.y}; }
    template<typename T>
    constexpr Vec3<T> cdiv(const Vec3<T>& a, const Vec3<T>& b) { return {a.x / b.x, a.y / b.y, a.z / b.z}; }
    template<typename T>
    constexpr Vec4<T> cdiv(const Vec4<T>& a, const Vec4<T>& b) { return {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w}; }

    /*
    ---------------------------------
                  MODULO
    ---------------------------------
    Computes the remainder of each component after division by a scalar.
    Supports v % s and v %= s.

    Uses % for integer components and std::fmod for floating-point components.
    The scalar must match the vector's component type.
    Negative components can produce negative remainders.
    Divisor components must be non-zero.
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
                Component-wise modulo
    ---------------------------------
    Computes the remainder of each component after division by the corresponding component of another vector.
    Supports v % u and v %= u.

    Uses % for integer components and std::fmod for floating-point components.
    The vectors must have the same component type.
    Negative components can produce negative remainders.
    Divisor components must be non-zero.
    */
    template<typename T>
    inline Vec2<T> cmod(const Vec2<T>& v, const Vec2<T>& u) {
        if constexpr (std::is_integral_v<T>) {
            return {v.x % u.x, v.y % u.y};
        }
        else {
            return {std::fmod(v.x, u.x), std::fmod(v.y, u.y)};
        }
    }
    template<typename T>
    inline Vec2<T> operator%(const Vec2<T>& v, const Vec2<T>& u) { return cmod(v, u); }
    template<typename T>
    inline Vec2<T>& operator%=(Vec2<T>& v, const Vec2<T>& u) {
        v = cmod(v, u);
        return v;
    }

    template<typename T>
    inline Vec3<T> cmod(const Vec3<T>& v, const Vec3<T>& u) {
        if constexpr (std::is_integral_v<T>) {
            return {v.x % u.x, v.y % u.y, v.z % u.z};
        }
        else {
            return {std::fmod(v.x, u.x), std::fmod(v.y, u.y), std::fmod(v.z, u.z)};
        }
    }
    template<typename T>
    inline Vec3<T> operator%(const Vec3<T>& v, const Vec3<T>& u) { return cmod(v, u); }
    template<typename T>
    inline Vec3<T>& operator%=(Vec3<T>& v, const Vec3<T>& u) {
        v = cmod(v, u);
        return v;
    }

    template<typename T>
    inline Vec4<T> cmod(const Vec4<T>& v, const Vec4<T>& u) {
        if constexpr (std::is_integral_v<T>) {
            return {v.x % u.x, v.y % u.y, v.z % u.z, v.w % u.w};
        }
        else {
            return {std::fmod(v.x, u.x), std::fmod(v.y, u.y), std::fmod(v.z, u.z), std::fmod(v.w, u.w)};
        }
    }
    template<typename T>
    inline Vec4<T> operator%(const Vec4<T>& v, const Vec4<T>& u) { return cmod(v, u); }
    template<typename T>
    inline Vec4<T>& operator%=(Vec4<T>& v, const Vec4<T>& u) {
        v = cmod(v, u);
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
          IS ZERO
    ---------------------------------
    Checks if a vector has zero length (all components are zero).
    */
    template<typename T>
    constexpr bool is_zero(const Vec2<T>& v) {
        return v.x == T(0) && v.y == T(0);
    }
    template<typename T>
    constexpr bool is_zero(const Vec3<T>& v) {
        return v.x == T(0) && v.y == T(0) && v.z == T(0);
    }
    template<typename T>
    constexpr bool is_zero(const Vec4<T>& v) {
        return v.x == T(0) && v.y == T(0) && v.z == T(0) && v.w == T(0);
    }


    /*
    ---------------------------------
               DOT PRODUCT
    ---------------------------------
    Computes the scalar dot product of two vectors.
    Vector multiplication a * b is deliberately defined as dot(a, b).
    Use cmul(a, b) for component-wise multiplication.

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
              COMPONENT-WISE MIN/MAX
    ---------------------------------
    Computes the component-wise minimum and maximum of two vectors.
    The result retains the vector's component type.
    */
    template<typename T>
    constexpr Vec2<T> cmin(const Vec2<T>& a, const Vec2<T>& b) {
        return {
            b.x < a.x ? b.x : a.x,
            b.y < a.y ? b.y : a.y
        }; 
    }
    template<typename T>
    constexpr Vec3<T> cmin(const Vec3<T>& a, const Vec3<T>& b) {
        return {
            b.x < a.x ? b.x : a.x,
            b.y < a.y ? b.y : a.y,
            b.z < a.z ? b.z : a.z
        };
    }
    template<typename T>
    constexpr Vec4<T> cmin(const Vec4<T>& a, const Vec4<T>& b) {
        return {
            b.x < a.x ? b.x : a.x,
            b.y < a.y ? b.y : a.y,
            b.z < a.z ? b.z : a.z,
            b.w < a.w ? b.w : a.w
        };
    }

    template<typename T>
    constexpr Vec2<T> cmax(const Vec2<T>& a, const Vec2<T>& b) {
        return {
            b.x > a.x ? b.x : a.x,
            b.y > a.y ? b.y : a.y
        };
    }
    template<typename T>
    constexpr Vec3<T> cmax(const Vec3<T>& a, const Vec3<T>& b) {
        return {
            b.x > a.x ? b.x : a.x,
            b.y > a.y ? b.y : a.y,
            b.z > a.z ? b.z : a.z
        };
    }
    template<typename T>
    constexpr Vec4<T> cmax(const Vec4<T>& a, const Vec4<T>& b) {
        return {
            b.x > a.x ? b.x : a.x,
            b.y > a.y ? b.y : a.y,
            b.z > a.z ? b.z : a.z,
            b.w > a.w ? b.w : a.w
        };
    }

    /*
    -------------------------------
                COMPONENT-WISE ABS
    ---------------------------------
    Computes the component-wise absolute value of a vector.
    The result retains the vector's component type.
    */
    template<typename T>
    constexpr Vec2<T> cabs(const Vec2<T>& v) { 
        return {
            v.x < T{0} ? -v.x : v.x, 
            v.y < T{0} ? -v.y : v.y
        }; 
    }
    template<typename T>
    constexpr Vec3<T> cabs(const Vec3<T>& v) {
        return {
            v.x < T{0} ? -v.x : v.x,
            v.y < T{0} ? -v.y : v.y,
            v.z < T{0} ? -v.z : v.z
        };
    }
    template<typename T>
    constexpr Vec4<T> cabs(const Vec4<T>& v) { 
        return {
            v.x < T{0} ? -v.x : v.x,
            v.y < T{0} ? -v.y : v.y,
            v.z < T{0} ? -v.z : v.z,
            v.w < T{0} ? -v.w : v.w
        };
    }


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
              CLAMP LENGTH
    ---------------------------------
    Clamps the length of a vector to a specified maximum.
    If the vector's length exceeds the maximum, it is scaled down to the maximum length.
    Otherwise, the vector remains unchanged.

    Integer components are converted to double before calculation, and the result has double components.
    Floating-point vectors retain their component type.
    */
    template<typename T>
    constexpr Vec2<std::conditional_t<std::is_integral_v<T>, double, T>>  
    clamp_length(const Vec2<T>& v, T max_length) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        assert(max_length >= T{0});

        Vec2<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y)
        };

        R max_len = static_cast<R>(max_length);
        R len_sq = length_squared(n);

        if (len_sq > max_len * max_len) {
            R len = std::sqrt(len_sq);
            return n * (max_len / len);
        }
        return n;
    }

    template<typename T>
    constexpr Vec3<std::conditional_t<std::is_integral_v<T>, double, T>> 
    clamp_length(const Vec3<T>& v, T max_length) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        assert(max_length >= T{0});

        R max_len = static_cast<R>(max_length);
        Vec3<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z)
        };

        R len_sq = length_squared(n);

        if (len_sq > max_len * max_len) {
            R len = std::sqrt(len_sq);
            return n * (max_len / len);
        }
        return n;
    }

    template<typename T>
    constexpr Vec4<std::conditional_t<std::is_integral_v<T>, double, T>> 
    clamp_length(const Vec4<T>& v, T max_length) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        assert(max_length >= T{0});

        R max_len = static_cast<R>(max_length);
        Vec4<R> n{
            static_cast<R>(v.x),
            static_cast<R>(v.y),
            static_cast<R>(v.z),
            static_cast<R>(v.w)
        };

        R len_sq = length_squared(n);

        if (len_sq > max_len * max_len) {
            R len = std::sqrt(len_sq);
            return n * (max_len / len);
        }
        return n;
    }

    /* 
    ---------------------------------
              COMPONENT REDUCTION
    ---------------------------------
    csum() returns the sum of all components of a vector.
    Returns the sum as the same type as the vector components.

    cmin() returns the minimum scalar component of a vector.
    Return value has same type as the vector components.

    cmax() returns the maximum scalar component of a vector.
    Return value has same type as the vector components.
    */
    template<typename T>
    constexpr T csum(const Vec2<T>& v) {
        return v.x + v.y;
    }

    template<typename T>
    constexpr T csum(const Vec3<T>& v) {
        return v.x + v.y + v.z;
    }

    template<typename T>
    constexpr T csum(const Vec4<T>& v) {
        return v.x + v.y + v.z + v.w;
    }

    template<typename T>
    constexpr T cmin(const Vec2<T>& v) {
        return v.x < v.y ? v.x : v.y;
    }

    template<typename T>
    constexpr T cmin(const Vec3<T>& v) {
        T m = v.x < v.y ? v.x : v.y;
        return m < v.z ? m : v.z;
    }

    template<typename T>
    constexpr T cmin(const Vec4<T>& v) {
        T m = v.x < v.y ? v.x : v.y;
        m = m < v.z ? m : v.z;
        return m < v.w ? m : v.w;
    }

    template<typename T>
    constexpr T cmax(const Vec2<T>& v) {
        return v.x > v.y ? v.x : v.y;
    }

    template<typename T>
    constexpr T cmax(const Vec3<T>& v) {
        T m = v.x > v.y ? v.x : v.y;
        return m > v.z ? m : v.z;
    }

    template<typename T>
    constexpr T cmax(const Vec4<T>& v) {
        T m = v.x > v.y ? v.x : v.y;
        m = m > v.z ? m : v.z;
        return m > v.w ? m : v.w;
    }

    /*
    ---------------------------------
              COMPONENT MIN/MAX INDEX
    ---------------------------------
    cmin_index() returns the index of the minimum component of a vector.
    cmax_index() returns the index of the maximum component of a vector.
    If multiple components share the minimum or maximum value,
    the index of the first occurrence is returned.
    The return type is std::size_t.
    */
    template<typename T>
    constexpr std::size_t cmin_index(const Vec2<T>& v) {
        return v.x <= v.y ? 0 : 1;
    }

    template<typename T>
    constexpr std::size_t cmin_index(const Vec3<T>& v) {
        std::size_t idx = v.x <= v.y ? 0 : 1;
        if (v.z < (idx == 0 ? v.x : v.y))
            idx = 2;
        return idx;
    }

    template<typename T>
    constexpr std::size_t cmin_index(const Vec4<T>& v) {
        std::size_t idx = v.x <= v.y ? 0 : 1;
        if (v.z < (idx == 0 ? v.x : v.y))
            idx = 2;
        if (v.w < (idx == 0 ? v.x : (idx == 1 ? v.y : v.z)))
            idx = 3;
        return idx;
    }

    template<typename T>
    constexpr std::size_t cmax_index(const Vec2<T>& v) {
        return v.x >= v.y ? 0 : 1;
    }

    template<typename T>
    constexpr std::size_t cmax_index(const Vec3<T>& v) {
        std::size_t idx = v.x >= v.y ? 0 : 1;
        if (v.z > (idx == 0 ? v.x : v.y))
            idx = 2;
        return idx;
    }

    template<typename T>
    constexpr std::size_t cmax_index(const Vec4<T>& v) {
        std::size_t idx = v.x >= v.y ? 0 : 1;
        if (v.z > (idx == 0 ? v.x : v.y))
            idx = 2;
        if (v.w > (idx == 0 ? v.x : (idx == 1 ? v.y : v.z)))
            idx = 3;
        return idx;
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

    /*
    ---------------------------------
            VECTOR CLAMPING
    ---------------------------------
    Clamps each component of a vector between the corresponding components of the minimum and maximum vectors.
    If scalar minimum and maximum values are provided, all components are clamped between these values.
    Each minimum bound must be <= its corresponding maximum bound.
    */
    template<typename T>
    constexpr Vec2<T> clamp(const Vec2<T>& v, const Vec2<T>& minVec, const Vec2<T>& maxVec) {
        return cmin(cmax(v, minVec), maxVec);
    }
    template<typename T>
    constexpr Vec2<T> clamp(const Vec2<T>& v, T minScal, T maxScal) {
        return clamp(v, Vec2<T>{minScal, minScal}, Vec2<T>{maxScal, maxScal});
    }

    template<typename T>
    constexpr Vec3<T> clamp(const Vec3<T>& v, const Vec3<T>& minVec, const Vec3<T>& maxVec) {
        return cmin(cmax(v, minVec), maxVec);
    }
    template<typename T>
    constexpr Vec3<T> clamp(const Vec3<T>& v, T minScal, T maxScal) {
        return clamp(v, Vec3<T>{minScal, minScal, minScal}, Vec3<T>{maxScal, maxScal, maxScal});
    }

    template<typename T>
    constexpr Vec4<T> clamp(const Vec4<T>& v, const Vec4<T>& minVec, const Vec4<T>& maxVec) {
        return cmin(cmax(v, minVec), maxVec);
    }
    template<typename T>
    constexpr Vec4<T> clamp(const Vec4<T>& v, T minScal, T maxScal) {
        return clamp(v, Vec4<T>{minScal, minScal, minScal, minScal}, Vec4<T>{maxScal, maxScal, maxScal, maxScal});
    }

    /*
    ---------------------------------
            VECTOR ANGLE
    ---------------------------------
    Computes the angle between two vectors in radians.
    If one of the vectors is zero, the angle is defined as 0.
    */
    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T>
    angle(const Vec2<T>& a, const Vec2<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(a) || is_zero(b)) return static_cast<R>(0);

        R dot_product =
            static_cast<R>(a.x) * static_cast<R>(b.x) +
            static_cast<R>(a.y) * static_cast<R>(b.y);
        R len_a = length(a);
        R len_b = length(b);

        R cosine = dot_product / (len_a * len_b);
        cosine = cosine < R{-1} ? R{-1} : cosine > R{1} ? R{1} : cosine;

        return std::acos(cosine);
    }

    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T>
    angle(const Vec3<T>& a, const Vec3<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(a) || is_zero(b)) 
            return static_cast<R>(0);

        R dot_product =
            static_cast<R>(a.x) * static_cast<R>(b.x) +
            static_cast<R>(a.y) * static_cast<R>(b.y) +
            static_cast<R>(a.z) * static_cast<R>(b.z);
        R len_a = length(a);
        R len_b = length(b);

        R cosine = dot_product / (len_a * len_b);
        cosine = cosine < R{-1} ? R{-1} : cosine > R{1} ? R{1} : cosine;

        return std::acos(cosine);
    }

    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T>
    angle(const Vec4<T>& a, const Vec4<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(a) || is_zero(b)) return static_cast<R>(0);

        R dot_product =
            static_cast<R>(a.x) * static_cast<R>(b.x) +
            static_cast<R>(a.y) * static_cast<R>(b.y) +
            static_cast<R>(a.z) * static_cast<R>(b.z) +
            static_cast<R>(a.w) * static_cast<R>(b.w);
        R len_a = length(a);
        R len_b = length(b);

        R cosine = dot_product / (len_a * len_b);
        cosine = cosine < R{-1} ? R{-1} : cosine > R{1} ? R{1} : cosine;

        return std::acos(cosine);
    }

    /*
    ---------------------------------
            2D VECTOR ANGLE
    ---------------------------------
    Computes the angle of a 2D vector in radians relative to the positive x-axis.
    If the vector is zero, the angle is defined as 0.
    */
    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T>
    angle(const Vec2<T>& v) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(v)) return static_cast<R>(0);

        return std::atan2(static_cast<R>(v.y), static_cast<R>(v.x));
    }

    /*
    ---------------------------------
            VECTOR PROJECTION
    ---------------------------------
    Computes the projection of vector a onto vector b.
    If vector b is zero, the projection is defined as the zero vector.
    */
    template<typename T>
    inline Vec2<std::conditional_t<std::is_integral_v<T>, double, T>>  
    project(const Vec2<T>& a, const Vec2<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(b)) return Vec2<R>{0, 0};

        Vec2<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y)
        };
        Vec2<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y)
        };
    
        R scale = dot(ar, br) / dot(br, br);

        return br * scale;
    }
    
    template<typename T>
    inline Vec3<std::conditional_t<std::is_integral_v<T>, double, T>> 
    project(const Vec3<T>& a, const Vec3<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(b)) return Vec3<R>{0, 0, 0};

        Vec3<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y),
            static_cast<R>(a.z)
        };
        Vec3<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y),
            static_cast<R>(b.z)
        };

        R scale = dot(ar, br) / dot(br, br);

        return br * scale;
    }
    
    template<typename T>
    inline Vec4<std::conditional_t<std::is_integral_v<T>, double, T>> 
    project(const Vec4<T>& a, const Vec4<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(b)) return Vec4<R>{0, 0, 0, 0};

        Vec4<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y),
            static_cast<R>(a.z),
            static_cast<R>(a.w)
        };
        Vec4<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y),
            static_cast<R>(b.z),
            static_cast<R>(b.w)
        };

        R scale = dot(ar, br) / dot(br, br);

        return br * scale;
    }

    /*
    ---------------------------------
            SCALAR VECTOR PROJECTION
    ---------------------------------
    Computes the scalar projection of vector a onto vector b.
    If vector b is zero, the scalar projection is defined as 0.
    */
    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T> 
    scalar_project(const Vec2<T>& a, const Vec2<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(b)) return static_cast<R>(0);

        Vec2<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y)
        };
        Vec2<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y)
        };

        return dot(ar, br) / length(br);
    }

    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T> 
    scalar_project(const Vec3<T>& a, const Vec3<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(b)) return static_cast<R>(0);

        Vec3<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y),
            static_cast<R>(a.z)
        };
        Vec3<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y),
            static_cast<R>(b.z)
        };

        return dot(ar, br) / length(br);
    }

    template<typename T>
    inline std::conditional_t<std::is_integral_v<T>, double, T> 
    scalar_project(const Vec4<T>& a, const Vec4<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        if (is_zero(b)) return static_cast<R>(0);

        Vec4<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y),
            static_cast<R>(a.z),
            static_cast<R>(a.w)
        };
        Vec4<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y),
            static_cast<R>(b.z),
            static_cast<R>(b.w)
        };

        return dot(ar, br) / length(br);
    }

    /*
    ---------------------------------
            VECTOR REJECTION
    ---------------------------------
    Computes the vector rejection of vector a from vector b.
    If vector b is zero, the rejection is defined as a.
    */
    template<typename T>
    inline Vec2<std::conditional_t<std::is_integral_v<T>, double, T>> 
    reject(const Vec2<T>& a, const Vec2<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec2<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y)
        };
        Vec2<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y)
        };

        if (is_zero(b)) return ar;

        return ar - project(ar, br);
    }

    template<typename T>
    inline Vec3<std::conditional_t<std::is_integral_v<T>, double, T>> 
    reject(const Vec3<T>& a, const Vec3<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec3<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y),
            static_cast<R>(a.z)
        };
        Vec3<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y),
            static_cast<R>(b.z)
        };

        if (is_zero(b)) return ar;

        return ar - project(ar, br);
    }

    template<typename T>
    inline Vec4<std::conditional_t<std::is_integral_v<T>, double, T>> 
    reject(const Vec4<T>& a, const Vec4<T>& b) {
        using R = std::conditional_t<std::is_integral_v<T>, double, T>;

        Vec4<R> ar{
            static_cast<R>(a.x),
            static_cast<R>(a.y),
            static_cast<R>(a.z),
            static_cast<R>(a.w)
        };
        Vec4<R> br{
            static_cast<R>(b.x),
            static_cast<R>(b.y),
            static_cast<R>(b.z),
            static_cast<R>(b.w)
        };

        if (is_zero(b)) return ar;

        return ar - project(ar, br);
    }

} // namespace mp::vector
