
import os

env = Environment(
    CPPPATH=["include"],
)

# Resolve the actual compiler command
compiler = os.path.basename(env.subst("$CXX")).lower()

if compiler in ("cl", "cl.exe"):
    # Microsoft MSVC
    env.Append(CXXFLAGS=["/std:c++17", "/W4"])
else:
    # GCC / Clang
    env.Append(CXXFLAGS=["-std=c++17", "-Wall", "-Wextra"])

# Build tests
test = env.Program(
    target="build/test_vectors",
    source="tests/test_vectors.cpp"
)

Default(test)
