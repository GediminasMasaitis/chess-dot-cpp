#pragma once

#define AVX2 1
#if AVX2
#include <immintrin.h>
#endif

template<class TData>
class Simd
{
public:
    using data_t = TData;

#if AVX2
    static constexpr size_t width_bits = 256;
#else
    static constexpr size_t width_bits = sizeof(data_t) * 8;
#endif
    
    static constexpr size_t width_bytes = width_bits / 8;
    static constexpr size_t alignment = width_bytes;
    static constexpr size_t stride = width_bytes / sizeof(data_t);

#if AVX2
    using simd_t = __m256i;
    //static constexpr simd_t zero = simd_t{0};
#else
    using simd_t = data_t;
    static constexpr simd_t zero = 0;
#endif

    static inline simd_t* reinterpret(data_t* ptr)
    {
        return reinterpret_cast<simd_t*>(ptr);
    }

    static inline simd_t const* reinterpret_const(data_t const* ptr)
    {
        return reinterpret_cast<simd_t const*>(ptr);
    }

    static inline simd_t add(const simd_t& lhs, const simd_t& rhs)
    {
        //static_assert(false, "Unsupported SIMD add");
        return simd_t{0};
    }

    static inline simd_t subtract(const simd_t& lhs, const simd_t& rhs)
    {
        //static_assert(false, "Unsupported SIMD subtract");
        return simd_t{0};
    }

    static inline simd_t max(const simd_t& lhs, const simd_t& rhs)
    {
        //static_assert(false, "Unsupported SIMD max");
        return simd_t{0};
    }

    static inline simd_t madd16(const simd_t& lhs, const simd_t& rhs)
    {
        static_assert(std::is_same_v<data_t, int16_t>);
#if AVX2
        return _mm256_madd_epi16(lhs, rhs);
#else
        static_assert(false);
#endif
    }

    static inline int32_t sumRegisterEpi32(const simd_t& reg)
    {
        static_assert(std::is_same_v<data_t, int32_t>);
#if AVX2
        const __m256i reduced_8 = reg;
        const __m128i reduced_4 = _mm_add_epi32(_mm256_castsi256_si128(reduced_8), _mm256_extractf128_si256(reduced_8, 1));
        __m128i vsum = _mm_add_epi32(reduced_4, _mm_srli_si128(reduced_4, 8));
        vsum = _mm_add_epi32(vsum, _mm_srli_si128(vsum, 4));
        int32_t sums = _mm_cvtsi128_si32(vsum);
        return sums;
#else
        static_assert(false)
#endif
    }
};

template<>
inline Simd<int16_t>::simd_t Simd<int16_t>::add(const simd_t& lhs, const simd_t& rhs)
{
#if AVX2
    return _mm256_add_epi16(lhs, rhs);
#else
    return lhs + rhs;
#endif
}

template<>
inline Simd<int16_t>::simd_t Simd<int32_t>::add(const simd_t& lhs, const simd_t& rhs)
{
#if AVX2
    return _mm256_add_epi32(lhs, rhs);
#else
    return lhs + rhs;
#endif
}

template<>
inline Simd<int16_t>::simd_t Simd<int16_t>::subtract(const simd_t& lhs, const simd_t& rhs)
{
#if AVX2
    return _mm256_sub_epi16(lhs, rhs);
#else
    return lhs - rhs;
#endif
}

template<>
inline Simd<int16_t>::simd_t Simd<int16_t>::max(const simd_t& lhs, const simd_t& rhs)
{
#if AVX2
    return _mm256_max_epi16(lhs, rhs);
#else
    return std::max(lhs, rhs);
#endif
}
