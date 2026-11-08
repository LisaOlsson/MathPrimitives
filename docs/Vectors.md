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
If the calculated length is zero or non-finite, returns a zero vector.
Returns a vector of the same type as `v` for floating-point vectors, or a vector with `double` components for integer vectors.

### Linear interpolation

`lerp(a, b, t)`
Interpolates between vectors `a` and `b` using the factor `t`, i.e. `(1 - t) * a + t * b`.
Returns `a` exactly when `t` is zero, and `b` exactly when `t` is one.
The factor `t` must have the same type as the vector components. Values outside the range zero to one extrapolate beyond the input-vectors.
Returns a vector of the same type as the input-vectors.

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
