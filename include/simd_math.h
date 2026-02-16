#include <immintrin.h> // Header for SIMD (SSE/AVX)

struct Vector4f {
    __m128 data; // This holds 4 floats at once

    // This adds four pairs of numbers in a single CPU instruction
    Vector4f operator+(const Vector4f& other) const {
        return { _mm_add_ps(this->data, other.data) };
    }
};
