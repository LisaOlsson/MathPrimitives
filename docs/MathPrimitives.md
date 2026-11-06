# MathPrimitives

## Description

MathPrimitives is a lightweight, performance-oriented C++ mathematics library built around clear, explicit implementations.
It prioritizes readable mathematical code, composable operations, predictable behavior, and measurable efficiency over abstraction for its own sake.
It aims for practical numerical correctness without the complexity and performance costs of exhaustive scientific-grade robustness.

## Design principles

### 1. Clarity over cleverness

The implementation should be understandable by reading the source code.
Mathematical operations should be expressed directly, with meaningful variable names, straightforward control flow, and comments explaining the mathematics and important assumptions.
Avoid unnecessary template metaprogramming, macros, abstraction layers, or other machinery that obscures what the code actually does.
A few lines of repetition are preferable to an abstraction that makes the mathematics harder to follow.

### 2. Performance is a fundamental design consideration

MathPrimitives is intended for performance-sensitive software, including procedural generation, graphics, simulations, and other computational applications.
Performance matters from the beginning, not merely as a later optimization.
However, performance decisions should be supported by measurements or inspection of generated code rather than assumptions.
Simple code is preferred, but not when simplicity introduces a substantial, avoidable performance penalty.

### 3. Practical correctness rather than exhaustive numerical robustness

The library should produce correct, predictable results for ordinary, realistic inputs.
It should handle common numerical issues, such as floating-point rounding in angle calculations and division by zero when normalizing vectors.
But it isn't intended to be a scientific computing library guaranteeing numerical stability for every possible floating-point value or extreme integer combination.
For example, using direct squared-component sums for vector lengths is a deliberate performance tradeoff.
Correctness is essential. Defending against every mathematically imaginable edge case is not.

### 4. Explicit, consistent mathematical semantics

Functions should have clear meanings, consistent naming, and predictable behavior across vector dimensions.
Likewise, the c prefix consistently identifies component-wise operations such as cmul, cdiv, cmin, and cmax.
Operations that naturally produce fractional results should promote integer inputs to floating-point results rather than silently truncating them.
Unusual conventions and mathematical limitations should be documented.

### 5. Small, composable building blocks

Functions should do one thing well, and more sophisticated functions should build on existing operations wherever that makes the implementation clearer.
This favors a library of reusable mathematical primitives rather than a collection of large, specialized algorithms.

### 6. Minimal overhead and dependencies

The core library should remain lightweight, header-only, and compatible with C++17.
Prefer standard C++ and standard library facilities. Avoid dependencies and runtime machinery that aren't justified by clear benefits.
Static vector dimensions and compile-time types should allow the compiler to generate efficient native code.

### 7. Readable, well-documented source is part of the product

Documentation shouldn't merely describe function signatures. It should explain the mathematical intent, assumptions, behavior, and relevant limitations.
The source should be useful to somebody trying to understand how the mathematics works, not just how to call a function.

## Current Status

Vectors are partly implemented and are my currently ongoing focus.
Tests are not up to date.
I also have a TODO-list with things that may or may not be implemented that has over 200 items and are still growing.
