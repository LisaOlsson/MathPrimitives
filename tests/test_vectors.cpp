#include "vectors.hpp"

#include <cassert>
#include <cmath>

using namespace mp::vector;

int main() {
    constexpr Vec3f a{1.0f, 2.0f, 3.0f};
    constexpr Vec3f b{4.0f, 5.0f, 6.0f};

    static_assert((a + b).x == 5.0f);
    static_assert((a - b).z == -3.0f);
    static_assert((a * 2.0f).y == 4.0f);
    static_assert((b / 2.0f).x == 2.0f);
    static_assert(dot(a, b) == 32.0f);

    constexpr auto c = cross(a, b);
    static_assert(c.x == -3.0f);
    static_assert(c.y == 6.0f);
    static_assert(c.z == -3.0f);

    Vec3f v{3.0f, 4.0f, 0.0f};

    assert(length(v) == 5.0f);

    auto n = normalize(v);
    assert(std::abs(length(n) - 1.0f) < 1e-6f);
    assert(std::abs(n.x - 0.6f) < 1e-6f);
    assert(std::abs(n.y - 0.8f) < 1e-6f);

    auto z = normalize(Vec3f{0.0f, 0.0f, 0.0f});
    assert(z.x == 0.0f && z.y == 0.0f && z.z == 0.0f);

    return 0;
}
