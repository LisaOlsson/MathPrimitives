#include "vectors.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace mp::vector;

int main() {
    constexpr Vec2f a2{0.0f, 10.0f};
    constexpr Vec2f b2{10.0f, 20.0f};

    constexpr Vec3f a3{1.0f, 2.0f, 3.0f};
    constexpr Vec3f b3{4.0f, 5.0f, 6.0f};

    constexpr Vec4f a4{1.0f, 2.0f, 3.0f, 4.0f};
    constexpr Vec4f b4{5.0f, 6.0f, 7.0f, 8.0f};
    constexpr Vec4f c4{9.0f, 10.0f, 11.0f, 13.0f};


    // Test 3D vector operations
    static_assert((a3 + b3).x == 5.0f);
    static_assert((a3 - b3).z == -3.0f);
    static_assert((a3 * 2.0f).y == 4.0f);
    static_assert((b3 / 2.0f).x == 2.0f);
    static_assert(dot(a3, b3) == 32.0f);

    // Test modulo operation
    assert(mod(a2, 3.0f).x == 0.0f);
    assert(mod(a2, 3.0f).y == 1.0f);
    assert((a2 % 3.0f).x == 0.0f);
    assert((a2 % 3.0f).y == 1.0f);

    // Unary negation
    static_assert((-a3).x == -1.0f);
    static_assert((-a3).y == -2.0f);
    static_assert((-a3).z == -3.0f);

    // Test length for 3D vectors
    Vec3f v{3.0f, 4.0f, 0.0f};
    assert(length(v) == 5.0f);

    // Squared distance for 2D vectors
    static_assert(distance_squared(a2, b2) == 200.0f);
    static_assert(distance_squared(a2, a2) == 0.0f);
    static_assert(distance_squared(a2, b2) == distance_squared(b2, a2));


    // Test normalization for 3D vectors
    auto n = normalize(v);
    assert(std::abs(length(n) - 1.0f) < 1e-6f);
    assert(std::abs(n.x - 0.6f) < 1e-6f);
    assert(std::abs(n.y - 0.8f) < 1e-6f);

    auto z = normalize(Vec3f{0.0f, 0.0f, 0.0f});
    assert(z.x == 0.0f && z.y == 0.0f && z.z == 0.0f);


    // Test linear interpolation (lerp)
    static_assert(lerp(a2, b2, 0.0f).x == 0.0f);
    static_assert(lerp(a2, b2, 0.5f).x == 5.0f);
    static_assert(lerp(a2, b2, 1.0f).y == 20.0f);
    static_assert(lerp(a2, b2, 0.5f).y == 15.0f);


    // Test cross product for 3D vectors
    constexpr auto c = cross(a3, b3);
    static_assert(c.x == -3.0f);
    static_assert(c.y == 6.0f);
    static_assert(c.z == -3.0f);


    // Test 4d cross product
    constexpr auto d4 = cross(a4, b4, c4);
    static_assert(d4.x == 4.0f);
    static_assert(d4.y == -8.0f);
    static_assert(d4.z == 4.0f);
    static_assert(d4.w == 0.0f);

    // Verify perpendicularity of tht 4D cross product result
    static_assert(dot(d4, a4) == 0.0f);
    static_assert(dot(d4, b4) == 0.0f);
    static_assert(dot(d4, c4) == 0.0f);

    return 0;
}
