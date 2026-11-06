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
Exceptions exists for certain values like `e` for epsilon.

## Included operations

### Addition

`add(a, b)`
Addition adds the vectors `a` and `b`, operations `+` and `+=` can also be used.

### Subtraction

`sub(a, b)`
Subtracts vector `b` from vector `a`, operations `-` and `-=` can also be used.

### Scale

`scale(a, s)`
Scales `a` by the factor `s`, operations `*` and `*=` can also be used.
Please note that `*` between two vectors calculates the dot product, see more under heading `dot product`.

### Component-wise multiplication

`cmul(a, b)`
Multiplies the corresponding vector components with each other. I.e. `a.x * b.x` and so on.

### Division

`div(a, s)`
Divides `a` by `s`, operations `/` and `/=` can also be used.

### Component-wise Division

`cdiv(a, b)`
Divides the `a` vector component with the corresponding `b` vector component. I.e. `a.x / b.x` and so on.

### Modulo

`mod(v, s)`
Computes the remainder of each component after division by `s`. Operations `%` and `%=` can also be used.

### Component-wise modulo

`cmod(a, b)`
Computes the component-wise remainder after division of components, i.e. `a.x % b.x`. Operations `%` and `%=` can also be used.
