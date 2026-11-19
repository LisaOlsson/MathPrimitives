# vectors.hpp

## Description

This is the main header containing a comprehensive implementation of vector related operations.

This document contains a list of all implemented operations, including a short description of them.

## Vector definitions

Vectors are defined in two, three and four dimensions. Vector components are overloaded and can take any integer or floating-point type. Note that short integers are not supported.
Vectors are structs named:

- Vec2(x, y)
- Vec3(x, y, z)
- Vec4(x, y, z, w)

Aliases for types float and double are defined as:

- Float: Vec2f, Vec3f and Vec4f
- Double: Vec2d, Vec3d and Vec4d

Vector components can also be accessed through the subscript operator [], with indices starting at zero (x = 0, y = 1, etc).

### Vector constants

Include `constants.hpp` to use the vector constants, i.e. `Vec3f::ZERO` or `Vec3f::UP`.
`ZERO`, `ONE` and `NEG_ONE` set all components to zero, one and minus one, respectively.
`X`, `Y`, `Z` and `W` are unit vectors along the corresponding positive axes, where those axes exist. `NEG_X`, `NEG_Y`, `NEG_Z` and `NEG_W` point along the corresponding negative axes.
Constants with negative components require a component type that can represent minus one.
In two and three dimensions, `RIGHT` and `LEFT` point along positive and negative x, and `UP` and `DOWN` point along positive and negative y.
In three dimensions, `FORWARD` points along negative z and `BACK` points along positive z.

## Definitions

Vectors are named `v` if the functions takes one vector argument, otherwise `a`, `b`, etc.
Non-vector parameters, i.e. integers or floating-point numbers are named `s`.
Exceptions exists for certain values like `epsilon` for epsilon.

## Included operations

### Bounds-checked component access

`v.at(s)`
Accesses the component at index `s`, with indices starting at zero, i.e. `x = 0`, `y = 1` and so on.
Throws `std::out_of_range` if the index is outside the vector's dimensions.
Returns a reference to the component, or a const reference if `v` is const.

### Addition

`add(a, b)`
Addition adds the vectors `a` and `b`, operations `+` and `+=` can also be used.
Returns a vector of the same type as the input-vectors.

### Subtraction

`sub(a, b)`
Subtracts vector `b` from vector `a`, operations `-` and `-=` can also be used.
Returns a vector of the same type as the input-vectors.

### Scale

`scale(v, s)`
Scales `v` by the factor `s`, operations `*` and `*=` can also be used.
Please note that `*` between two vectors calculates the dot product, see more under heading `dot product`.
Returns a vector of the same type as the input vector `v`.

### Component-wise multiplication

`cmul(a, b)`
Multiplies the corresponding vector components with each other. I.e. `a.x * b.x` and so on.
Returns a vector of the same type as the input-vectors.

### Division

`div(v, s)`
Divides `v` by `s`, operations `/` and `/=` can also be used.
Returns a vector of the same type as the input vector `v`.

### Component-wise Division

`cdiv(a, b)`
Divides the `a` vector component with the corresponding `b` vector component. I.e. `a.x / b.x` and so on.
Returns a vector of the same type as the input-vectors.

### Modulo

`mod(v, s)`
Computes the remainder of each component after division by `s`. Operations `%` and `%=` can also be used.
Returns a vector of the same type as the input vector `v`.

### Component-wise modulo

`cmod(a, b)`
Computes the component-wise remainder after division of components, i.e. `a.x % b.x`. Operations `%` and `%=` can also be used.
Returns a vector of the same type as the input-vectors.

### Equality

`a == b`
Compares the corresponding vector components for exact equality.
Returns `true` if all corresponding components are equal, otherwise `false`.

### Approximate equality

`approx_equal(a, b, epsilon)`
Compares the corresponding vector components using the absolute tolerance `epsilon`.
The tolerance must have the same type as the vector components.
Returns `true` if the absolute difference between each pair of corresponding components is less than or equal to `epsilon`, otherwise `false`.

### Inequality

`a != b`
Compares the corresponding vector components for inequality.
Returns `true` if at least one pair of corresponding components differs, otherwise `false`.

### Is zero

`is_zero(v)`
Checks if all vector components are exactly zero.
Returns `true` if all components are zero, otherwise `false`.

`is_zero(v, epsilon)`
Returns `true` if the absolute value of each vector component is less than or equal to `epsilon`, otherwise `false`.
The tolerance must have the same type as the vector components.

### Is normalized

`is_normalized(v)`
Returns `true` if the calculated length of vector `v` is exactly one, otherwise `false`.

`is_normalized(v, epsilon)`
Returns `true` if the absolute difference between the calculated length and one is less than or equal to `epsilon`, otherwise `false`.
The tolerance must have the same type as the vector components.

### Is parallel

`is_parallel(a, b)`
Checks if vectors `a` and `b` are parallel, including vectors pointing in opposite directions.
Returns `true` if the difference of products for each pair of axes is zero, i.e. `a.x * b.y - a.y * b.x` is zero for the x and y axes. A zero vector is considered parallel to any vector.

`is_parallel(a, b, epsilon)`
Returns `true` if the absolute value of each such difference is less than or equal to `epsilon`, otherwise `false`.
The tolerance must have the same type as the vector components. It applies directly to these differences, so the result depends on the lengths of the input-vectors.

### Is orthogonal

`is_orthogonal(a, b)`
Returns `true` if the dot product of vectors `a` and `b` is exactly zero, otherwise `false`. A zero vector is considered orthogonal to any vector.

`is_orthogonal(a, b, epsilon)`
Returns `true` if the absolute value of the dot product is less than or equal to `epsilon`, otherwise `false`.
The tolerance must have the same type as the vector components and applies directly to the dot product.

### Is opposite

`is_opposite(a, b)`
Returns `true` if vectors `a` and `b` are parallel and their dot product is negative, otherwise `false`.
The vectors may have different lengths.

`is_opposite(a, b, epsilon)`
Returns `true` if `is_parallel(a, b, epsilon)` is true and the dot product is less than or equal to `-epsilon`, otherwise `false`.
The tolerance must have the same type as the vector components. With `epsilon` equal to zero, this overload also accepts a zero dot product, i.e. when one of the vectors is zero.

### Conversion between dimensions

`to_vec2(v)`
Converts a three- or four-dimensional vector to two dimensions by keeping `x` and `y`.

`to_vec3(v)`
Converts a two- or four-dimensional vector to three dimensions. The new `z` component is zero for a two-dimensional input. The `w` component is discarded for a four-dimensional input.

`to_vec4(v)`
Converts a two- or three-dimensional vector to four dimensions by filling the missing components with zeros.
All three functions return a vector with the same component type as the input vector `v`.

### Dot product

`dot(a, b)`
Multiplies the corresponding vector components and adds the results, i.e. `a.x * b.x + a.y * b.y` and so on. Operation `*` between two vectors can also be used.
Returns a value of the same type as the vector components.

### Cross product

`cross(a, b)`
Computes the cross product of two vectors in two or three dimensions.
For two-dimensional vectors, returns the signed scalar determinant `a.x * b.y - a.y * b.x`.
For three-dimensional vectors, returns a vector perpendicular to both input-vectors, following the right-hand rule.
The return value has the same type as the vector components in two dimensions, or the same vector type as the input-vectors in three dimensions.

`cross(a, b, c)`
Computes the cross product of three four-dimensional vectors.
Returns a four-dimensional vector perpendicular to all three input-vectors, with the same component type.
Please note that the vectors returned by the cross product are not normalized.

### Unary negation

`-v`
Negates each vector component, i.e. `-v.x`, `-v.y` and so on.
Returns a vector of the same type as the input vector `v`.

### Component-wise minimum

`cmin(a, b)`
Selects the smaller value from each pair of corresponding vector components.
Returns a vector of the same type as the input-vectors.

### Component-wise maximum

`cmax(a, b)`
Selects the larger value from each pair of corresponding vector components.
Returns a vector of the same type as the input-vectors.

### Component-wise absolute value

`cabs(v)`
Computes the absolute value of each vector component.
Returns a vector of the same type as the input vector `v`.

### Component-wise floor

`cfloor(v)`
Rounds each vector component down to the nearest integer, i.e. `-1.25` becomes `-2`.
Returns a vector of the same type as `v`. Integer vectors are returned as they are.

### Component-wise ceiling

`cceil(v)`
Rounds each vector component up to the nearest integer, i.e. `-1.25` becomes `-1`.
Returns a vector of the same type as `v`. Integer vectors are returned as they are.

### Component-wise rounding

`cround(v)`
Rounds each vector component to the nearest integer. Values halfway between two integers are rounded away from zero, i.e. `-1.5` becomes `-2`.
Returns a vector of the same type as `v`. Integer vectors are returned as they are.

### Component-wise fractional part

`cfract(v)`
Computes the fractional part of each component by subtracting its floor, i.e. `-1.25` gives `0.75`.
Returns a vector of the same type as `v`, with all components zero for integer vectors.

### Length

`length(v)`
Computes the Euclidean length of vector `v`, i.e. the square root of the sum of its squared components.
Integer components are converted to `double` before calculation.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Length squared

`length_squared(v)`
Computes the sum of the squared vector components. Useful for comparing lengths without calculating a square root.
Integer components are converted to `double` before calculation.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Clamp length

`clamp_length(v, max_length)`
Limits the length of vector `v` to `max_length`, scaling it down if needed.

`clamp_length(v, min_length, max_length)`
Clamps the length of vector `v` between `min_length` and `max_length`, scaling it up or down if needed.
A zero vector remains zero, regardless of `min_length`.
Both overloads require non-negative bounds of the same type as the vector components. If both bounds are provided, `min_length` must be less than or equal to `max_length`.
Returns a vector of the same type as `v` for floating-point vectors, or a vector with `double` components for integer vectors.

### Component sum

`csum(v)`
Adds all vector components, i.e. `v.x + v.y` and so on.
Returns a value of the same type as the vector components.

### Minimum component

`cmin(v)`
Finds the smallest component of vector `v`.
Returns a value of the same type as the vector components.

### Maximum component

`cmax(v)`
Finds the largest component of vector `v`.
Returns a value of the same type as the vector components.

### Minimum component index

`cmin_index(v)`
Finds the index of the smallest component of vector `v`, with indices starting at zero.
If multiple components share the smallest value, the index of the first occurrence is returned.
Returns an index of type `std::size_t`.

### Maximum component index

`cmax_index(v)`
Finds the index of the largest component of vector `v`, with indices starting at zero.
If multiple components share the largest value, the index of the first occurrence is returned.
Returns an index of type `std::size_t`.

### Normalization

`normalize(v)`
Computes a unit vector pointing in the same direction as vector `v`.
If the calculated length is zero, returns a zero vector.

`normalize(v, fallback)`
Normalizes `fallback` if all components of `v` are exactly zero. Otherwise normalizes `v`.
The fallback vector must have the same type as `v`.
Returns a vector of the same type as `v` for floating-point vectors, or a vector with `double` components for integer vectors.

### Linear interpolation

`lerp(a, b, t)`
Interpolates between vectors `a` and `b` using the factor `t`, i.e. `(1 - t) * a + t * b`.
Returns `a` exactly when `t` is zero, and `b` exactly when `t` is one.
The factor `t` must have the same type as the vector components. Values outside the range zero to one extrapolate beyond the input-vectors.
Returns a vector of the same type as the input-vectors.

### Spherical interpolation

`slerp(a, b, t)`
Interpolates between vectors `a` and `b` using the factor `t`. Non-parallel vectors of equal length follow a circular arc, and non-parallel vectors of different lengths follow an elliptical arc.
If either calculated length is zero, returns `a` for any `t`.
Otherwise returns `a` exactly when `t` is zero, and `b` exactly when `t` is one. Parallel vectors use linear interpolation. Opposite vectors are undefined and zero vector is returned.
Values of `t` outside the range zero to one extrapolate beyond the input-vectors.
Use floating-point vectors of the same type. The result has the same vector type as the input-vectors, and `t` is converted to their component type.

### Distance

`distance(a, b)`
Computes the Euclidean distance between vectors `a` and `b`.
Integer components are converted to `double` before calculation.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Distance squared

`distance_squared(a, b)`
Computes the squared Euclidean distance between vectors `a` and `b`. Useful for comparing distances without calculating a square root.
Integer components are converted to `double` before calculation.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Clamp

`clamp(v, a, b)`
Clamps each component of vector `v` between the corresponding components of the minimum vector `a` and maximum vector `b`.

`clamp(v, s_min, s_max)`
Clamps all components of vector `v` between the scalar values `s_min` and `s_max`, which must have the same type as the vector components.
For both overloads, each minimum bound must be less than or equal to its corresponding maximum bound.
Returns a vector of the same type as the input vector `v`.

### Angle between vectors

`angle(a, b)`
Computes the angle between vectors `a` and `b` in radians, in the range zero to pi.
If either vector is zero, the angle is defined as zero.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Two-dimensional vector angle

`angle(v)`
Computes the angle of a two-dimensional vector relative to the positive x-axis, using `atan2(v.y, v.x)`.
The angle is returned in radians, in the range minus pi to pi.
If the vector is zero, the angle is defined as zero.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Vector projection

`project(a, b)`
Computes the part of vector `a` that lies along vector `b`, i.e. `b * (dot(a, b) / dot(b, b))`.
Vector `b` does not need to be normalized. If `b` is zero, returns a zero vector.
Returns a vector of the same type as the input-vectors for floating-point vectors, or a vector with `double` components for integer vectors.

### Scalar projection

`scalar_project(a, b)`
Computes the signed length of the projection of vector `a` onto vector `b`, i.e. `dot(a, b) / length(b)`.
If vector `b` is zero, returns zero.
Returns a value of the same type as the vector components for floating-point vectors, or `double` for integer vectors.

### Vector rejection

`reject(a, b)`
Computes the part of vector `a` perpendicular to vector `b`, i.e. `a - project(a, b)`.
If vector `b` is zero, returns vector `a`.
Returns a vector of the same type as the input-vectors for floating-point vectors, or a vector with `double` components for integer vectors.

### Vector reflection

`reflect(a, b)`
Reflects vector `a` across the line in two dimensions, or the hyperplane in higher dimensions, with normal vector `b`, i.e. `a - 2 * project(a, b)`.
Vector `b` does not need to be normalized. If `b` is zero, returns vector `a`.
Returns a vector of the same type as the input-vectors for floating-point vectors, or a vector with `double` components for integer vectors.

### Vector axis reflection

`axis_reflect(a, b)`
Reflects vector `a` across the axis defined by vector `b`, i.e. `2 * project(a, b) - a`.
Vector `b` does not need to be normalized. If `b` is zero, returns vector `a`.
Returns a vector of the same type as the input-vectors for floating-point vectors, or a vector with `double` components for integer vectors.

### Vector refraction

`refract(a, b, eta)`
Refracts vector `a` through a surface with normal vector `b`, using the refractive index ratio `eta` of the incident medium to the transmitted medium.
The ratio `eta` must be positive, with the same type as the vector components for floating-point vectors, or `double` for integer vectors.
Neither vector needs to be normalized. The normal is normalized internally and oriented against the incident vector, and the refracted vector preserves the length of `a`.
If vector `a` is zero or total internal reflection occurs, returns a zero vector. If vector `b` is zero, returns vector `a`.
Returns a vector of the same type as the input-vectors for floating-point vectors, or a vector with `double` components for integer vectors.

### Two-dimensional perpendicular vector

`perpendicular(v, clockwise)`
Rotates a two-dimensional vector by 90 degrees. If `clockwise` is `true`, the result is `(v.y, -v.x)`. If it is `false`, the result is `(-v.y, v.x)`.
The default value for `clockwise` is `true`, so `perpendicular(v)` rotates clockwise.
Returns a vector of the same type as the input vector `v`.

### Vector rotation

`rotate(v, angle)`
Rotates a two-dimensional vector by `angle` radians. Positive angles rotate counterclockwise and negative angles rotate clockwise.

`rotate(v, angle, axis)`
Rotates a three-dimensional vector by `angle` radians around `axis`, following the right-hand rule.
The axis must be a unit vector of the same type as `v`.
In both overloads, `angle` is converted to the vector's component type for floating-point vectors, or `double` for integer vectors.
Returns a vector of the same type as `v` for floating-point vectors, or a vector with `double` components for integer vectors.

### Four-dimensional plane rotation

`rotate_plane(v, angle, a, b)`
Rotates the part of a four-dimensional vector `v` in the plane defined by `a` and `b` by `angle` radians. A positive angle rotates from `a` towards `b`. The part perpendicular to the plane stays the same.
Vectors `a` and `b` must be perpendicular unit vectors of the same type as `v`, and `angle` must have the same type as the vector components.
Returns a vector of the same type as the input vector `v`. Use floating-point vectors for rotation, as the sine and cosine are stored in the component type.

### Move towards

`move_towards(a, b, dist)`
Moves from vector `a` towards target vector `b` by up to `dist`. If the calculated distance to `b` is zero or less than or equal to `dist`, returns `b`.
A negative `dist` moves away from `b` by its absolute value when the calculated distance is nonzero.
The distance `dist` is converted to the vector's component type for floating-point vectors, or `double` for integer vectors.
Returns a vector of the same type as the input-vectors for floating-point vectors, or a vector with `double` components for integer vectors.
