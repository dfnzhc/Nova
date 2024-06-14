/**
 * @File Common.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/27
 * @Brief 
 */

#pragma once

#include "./Math.hpp"
#include "./Check.hpp"
#include "./Constants.hpp"

#include <cstring>

namespace nova {

template<ArithmeticType T> NOVA_FUNC constexpr T Zero()
{
    return T(0);
}

template<ArithmeticType T> NOVA_FUNC constexpr T One()
{
    return T(1);
}

template<ArithmeticType T> NOVA_FUNC constexpr T Two()
{
    return T(2);
}

template<typename T> NOVA_FUNC void Swap(T& a, T& b)
{
    return std::swap(a, b);
}

NOVA_FUNC void* Memcpy(void* dst, const void* src, size sz)
{
    return std::memcpy(dst, src, sz);
}

NOVA_FUNC int Memcmp(const void* buf1, const void* buf2, size sz)
{
    return std::memcmp(buf1, buf2, sz);
}

NOVA_FUNC void* Memset(void* dst, int val, size sz)
{
    return std::memset(dst, val, sz);
}

template<class To, class From> NOVA_FUNC auto BitCast(const From& src) noexcept
{
    return std::bit_cast<To>(src);
}

// clang-format off
template<ArithmeticType T> NOVA_FUNC constexpr bool Equal(T x, T y)      noexcept { return x == y; }
template<ArithmeticType T> NOVA_FUNC constexpr bool NotEqual(T x, T y)   noexcept { return not Equal(x, y); }

template<ArithmeticType T> NOVA_FUNC constexpr T Min(T x, T y)           noexcept { return x < y ? x : y; }
template<ArithmeticType T> NOVA_FUNC constexpr T Min(T x, T y, T z)      noexcept { return Min(x, Min(y, z)); }
template<ArithmeticType T> NOVA_FUNC constexpr T Min(T x, T y, T z, T w) noexcept { return Min(x, Min(y, Min(z, w))); }

template<ArithmeticType T> NOVA_FUNC constexpr T Max(T x, T y)           noexcept { return x > y ? x : y; }
template<ArithmeticType T> NOVA_FUNC constexpr T Max(T x, T y, T z)      noexcept { return Max(x, Max(y, z)); }
template<ArithmeticType T> NOVA_FUNC constexpr T Max(T x, T y, T z, T w) noexcept { return Max(x, Max(y, Max(z, w))); }

template<ArithmeticType T> NOVA_FUNC constexpr T Clamp(T v, T lo, T hi) noexcept { return Max(lo, Min(v, hi)); }
template<ArithmeticType T> NOVA_FUNC constexpr T Clamp(T v, T hi)       noexcept { return Max(T(0), Min(v, hi)); }

template<SignedType T>     NOVA_FUNC constexpr T Abs(T x)               noexcept { return x > 0 ? x : -x; }
template<SignedType T>     NOVA_FUNC constexpr T Sign(T x)              noexcept { return x < T(0) ? T(-1) : (x > T(0) ? T(1) : T(0)); }

// clang-format on

template<FloatType T> NOVA_FUNC constexpr T Floor(T x) noexcept
{
    return std::floor(x);
}

template<FloatType T> NOVA_FUNC constexpr T Ceil(T x) noexcept
{
    return std::ceil(x);
}

template<FloatType T> NOVA_FUNC constexpr T Trunc(T x) noexcept
{
    return std::trunc(x);
}

template<FloatType T> NOVA_FUNC constexpr T Round(T x) noexcept
{
    return std::round(x);
}

template<FloatType T> NOVA_FUNC constexpr T Sqrt(T x) noexcept
{
    return std::sqrt(x);
}

template<FloatType T> NOVA_FUNC constexpr T rSqrt(T x)
{
    return One<T>() / Sqrt(x);
}

template<FloatType T> NOVA_FUNC constexpr T Exp(T x) noexcept
{
    return std::exp(x);
}

template<FloatType T> NOVA_FUNC constexpr T Exp2(T x) noexcept
{
    return std::exp2(x);
}

template<FloatType T> NOVA_FUNC constexpr T Log(T x) noexcept
{
    return std::log(x);
}

template<FloatType T> NOVA_FUNC constexpr T Log2(T x) noexcept
{
    return std::log2(x);
}

template<FloatType T> NOVA_FUNC constexpr T Log10(T x) noexcept
{
    return std::log10(x);
}

template<FloatType T> NOVA_FUNC constexpr T Sin(T x) noexcept
{
    return std::sin(x);
}

template<FloatType T> NOVA_FUNC constexpr T Sinh(T x) noexcept
{
    return std::sinh(x);
}

template<FloatType T> NOVA_FUNC constexpr T Cos(T x) noexcept
{
    return std::cos(x);
}

template<FloatType T> NOVA_FUNC constexpr T Cosh(T x) noexcept
{
    return std::cosh(x);
}

template<FloatType T> NOVA_FUNC constexpr T Tan(T x) noexcept
{
    return std::tan(x);
}

template<FloatType T> NOVA_FUNC constexpr T Tanh(T x) noexcept
{
    return std::tanh(x);
}

template<FloatType T> NOVA_FUNC constexpr T aSin(T x) noexcept
{
    return std::asin(x);
}

template<FloatType T> NOVA_FUNC constexpr T aSinh(T x) noexcept
{
    return std::asinh(x);
}

template<FloatType T> NOVA_FUNC constexpr T aCos(T x) noexcept
{
    return std::acos(x);
}

template<FloatType T> NOVA_FUNC constexpr T aCosh(T x) noexcept
{
    return std::acosh(x);
}

template<FloatType T> NOVA_FUNC constexpr T aTan(T x) noexcept
{
    return std::atan(x);
}

template<FloatType T> NOVA_FUNC constexpr T aTanh(T x) noexcept
{
    return std::atanh(x);
}

template<FloatType T> NOVA_FUNC constexpr T aTan2(T y, T x) noexcept
{
    return std::atan2(y, x);
}

template<FloatType T> NOVA_FUNC constexpr T Erf(T x) noexcept
{
    return std::erf(x);
}

template<FloatType T> NOVA_FUNC constexpr T ErfInv(T x) noexcept
{ 
    // https://stackoverflow.com/a/49743348
    T p;
    T t = Log(Max(std::fma(x, -x, One<T>()), cast_to<T>(kFloatMin)));
    NOVA_CHECK(!std::isnan(t) && !std::isinf(t));
    if (Abs(t) > 6.125f) {                          // maximum ulp error = 2.35793
        p = 3.03697567e-10f;                        //  0x1.4deb44p-32
        p = std::fma(p, t, cast_to<T>(2.93243101e-8f));  //  0x1.f7c9aep-26
        p = std::fma(p, t, cast_to<T>(1.22150334e-6f));  //  0x1.47e512p-20
        p = std::fma(p, t, cast_to<T>(2.84108955e-5f));  //  0x1.dca7dep-16
        p = std::fma(p, t, cast_to<T>(3.93552968e-4f));  //  0x1.9cab92p-12
        p = std::fma(p, t, cast_to<T>(3.02698812e-3f));  //  0x1.8cc0dep-9
        p = std::fma(p, t, cast_to<T>(4.83185798e-3f));  //  0x1.3ca920p-8
        p = std::fma(p, t, cast_to<T>(-2.64646143e-1f)); // -0x1.0eff66p-2
        p = std::fma(p, t, cast_to<T>(8.40016484e-1f));  //  0x1.ae16a4p-1
    }
    else {                                          // maximum ulp error = 2.35456
        p = 5.43877832e-9f;                         //  0x1.75c000p-28
        p = std::fma(p, t, cast_to<T>(1.43286059e-7f));  //  0x1.33b458p-23
        p = std::fma(p, t, cast_to<T>(1.22775396e-6f));  //  0x1.49929cp-20
        p = std::fma(p, t, cast_to<T>(1.12962631e-7f));  //  0x1.e52bbap-24
        p = std::fma(p, t, cast_to<T>(-5.61531961e-5f)); // -0x1.d70c12p-15
        p = std::fma(p, t, cast_to<T>(-1.47697705e-4f)); // -0x1.35be9ap-13
        p = std::fma(p, t, cast_to<T>(2.31468701e-3f));  //  0x1.2f6402p-9
        p = std::fma(p, t, cast_to<T>(1.15392562e-2f));  //  0x1.7a1e4cp-7
        p = std::fma(p, t, cast_to<T>(-2.32015476e-1f)); // -0x1.db2aeep-3
        p = std::fma(p, t, cast_to<T>(8.86226892e-1f));  //  0x1.c5bf88p-1
    }
    return x * p;
}

template<FloatType T> NOVA_FUNC constexpr T CopySign(T num, T sign) noexcept
{
    return std::copysign(num, sign);
}

/**
 * 计算浮点数除法操作的余数。
 *
 * 这个函数计算 x 除以 y 的余数，使得结果总是在 -y/2 和 y/2 之间。
 *
 * @tparam T 浮点类型（可以是 float 或 double）。
 * @param x 被除数。
 * @param y 除数。
 * @return x / y 的浮点余数。
 */
template<FloatType T> NOVA_FUNC constexpr T fMod(T x, T y) noexcept
{
    NOVA_CHECK_NE(y, 0);
    return std::fmod(x, y);
}

/**
 * 将浮点数分解为其整数部分和小数部分。
 *
 * 这个函数将浮点数 x 的整数部分分离出来，并将其存储在由 iptr 指向的地址中。函数返回 x 的小数部分。
 *
 * @tparam T 浮点类型（可以是 float 或 double）。
 * @param x 要分离的浮点数。
 * @param iptr 指向存储 x 整数部分的指针。
 * @return \a x 的小数部分。
 */
template<FloatType T> NOVA_FUNC constexpr T Modf(T x, T* iptr) noexcept
{
    return std::modf(x, iptr);
}

template<FloatType T> NOVA_FUNC constexpr auto Radians(T x) noexcept
{
    return x * decltype(x)(0.01745329251994329576923690768489);
}

template<FloatType T> NOVA_FUNC constexpr auto Degrees(T x) noexcept
{
    return x * decltype(x)(57.295779513082320876798154814105);
}

template<FloatType T> NOVA_FUNC constexpr auto Frac(T x) noexcept
{
    if (x >= 0)
        return x - Floor(x);

    T ip;
    return Modf(x, &ip);
}

template<FloatType T> NOVA_FUNC constexpr auto Rcp(T x) noexcept
{
    NOVA_CHECK(x != Zero<T>());

    return One<T>() / x;
}

template<FloatType T> NOVA_FUNC constexpr auto Saturate(T x) noexcept
{
    return Max(Zero<T>(), Min(One<T>(), x));
}

/**
 * @brief 如果 x 小于 edge，则此函数返回 0；否则返回 1。
 */
template<FloatType T> NOVA_FUNC constexpr auto Step(T x, T edge) noexcept
{
    return edge < x ? Zero<T>() : One<T>();
}

/**
 * @brief 线性插值函数
 * 
 * 通过 s 在 x 和 y 之间进行线性插值。
 * (1 - s) * x + s * y
 */
template<FloatType T> NOVA_FUNC constexpr auto Lerp(T x, T y, T s) noexcept
{
    return (One<T>() - s) * x + s * y;
}

/**
 * @brief 双线性插值函数
 *
 * 先使用 u 插值 (v00, v01) 和 (v10, v11)，然后再使用 v 插值上一步的结果
 */
template<FloatType T> NOVA_FUNC constexpr auto BiLerp(T v00, T v01, T v10, T v11, T u, T v) noexcept
{
    return Lerp(Lerp(v00, v01, u), Lerp(v10, v11, u), v);
}

template<FloatType T> NOVA_FUNC constexpr auto SmoothStep(T v, T lo, T hi) noexcept
{
    if (lo > hi)
        Swap(lo, hi);

    v = Saturate((v - lo) / (hi - lo));
    return v * v * (T(3) - T(2) * v);
}

template<FloatType T> NOVA_FUNC constexpr T Length(T v)
{
    return Abs(v);
}

template<FloatType T> NOVA_FUNC constexpr T Distance(T p0, T p1)
{
    return Length(p1 - p0);
}

template<FloatType T> NOVA_FUNC constexpr T Dot(T x, T y)
{
    return x * y;
}

template<FloatType T> NOVA_FUNC T FaceForward(T N, T I, T refN)
{
    return Dot(refN, I) < Zero<T>() ? N : -N;
}

template<ArithmeticType T> NOVA_FUNC bool Approx(T x, T y, T epsilon = kShadowEpsilon)
{
    using Type = T;
    return Abs(Type(x) - Type(y)) < epsilon;
}

template<ArithmeticType T, ArithmeticType U>
NOVA_FUNC bool Approx(T x, U y, std::common_type_t<T, U> epsilon = kShadowEpsilon)
{
    using Type = std::common_type_t<T, U>;
    return Approx(Type(x), Type(y), Type(epsilon));
}

template<FloatType T> NOVA_FUNC T SafeSqrt(T x)
{
    NOVA_CHECK_GE(x, -1e-3); // not too negative
    return Sqrt(Max(T(0), x));
}

template<typename T> NOVA_FUNC constexpr T Sqr(T v)
{
    return v * v;
}

template<FloatType T> NOVA_FUNC T SinXOverX(T x)
{
    if (1 + x * x == 1)
        return 1;
    return Sin(x) / x;
}

template<FloatType T> NOVA_FUNC T SafeASin(T x)
{
    NOVA_CHECK(x >= -1.0001 && x <= 1.0001);
    return aSin(Clamp(x, -One<T>(), One<T>()));
}

template<FloatType T> NOVA_FUNC T SafeACos(T x)
{
    NOVA_CHECK(x >= -1.0001 && x <= 1.0001);
    return aCos(Clamp(x, -One<T>(), One<T>()));
}

// clang-format off
template<ArithmeticType T> NOVA_FUNC constexpr T Gauss(T x, T expectedValue, T standardDeviation)
{
    return Exp(-((x - expectedValue) * (x - expectedValue)) / (Two<T>() * standardDeviation * standardDeviation)) / (standardDeviation * Sqrt(cast_to<T>(kTwoPi)));
}

// clang-format on

NOVA_FUNC constexpr Float Gamma(int n)
{
    return ((Float)n * kMachineEpsilon) / (1 - (Float)n * kMachineEpsilon);
}

} // namespace nova