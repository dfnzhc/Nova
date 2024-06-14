/**
 * @File Float.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/27
 * @Brief 
 */

#pragma once

#include <concepts>
#include <numbers>
#include <numeric>
#include <cmath>
#include "./Common.hpp"

namespace nova {

NOVA_FUNC bool IsNaN(std::floating_point auto v)
{
    return std::isnan(v);
}

NOVA_FUNC bool IsNaN(auto)
{
    return false;
}

NOVA_FUNC bool IsInf(std::floating_point auto v)
{
    return std::isinf(v);
}

NOVA_FUNC bool IsInf(auto)
{
    return false;
}

NOVA_FUNC bool IsFinite(std::floating_point auto v)
{
    return std::isfinite(v);
}

NOVA_FUNC bool IsFinite(auto)
{
    return true;
}

NOVA_FUNC auto Fma(f32 a, f32 b, f32 c)
{
    return std::fmaf(a, b, c);
}

NOVA_FUNC auto Fma(f64 a, f64 b, f64 c)
{
    return std::fma(a, b, c);
}

NOVA_FUNC auto FloatToBits(std::floating_point auto f)
{
    if constexpr (std::is_same_v<decltype(f), f32>) {
        return BitCast<u32>(f);
    }
    else {
        return BitCast<u64>(f);
    }
}

NOVA_FUNC auto BitsToFloat(std::unsigned_integral auto ui)
{
    if constexpr (std::is_same_v<decltype(ui), u32>) {
        return BitCast<f32>(ui);
    }
    else {
        return BitCast<f64>(ui);
    }
}

NOVA_FUNC i32 Exponent(std::floating_point auto v)
{
    if constexpr (std::is_same_v<decltype(v), f32>) {
        return cast_to<i32>(FloatToBits(v) >> 23) - 127;
    }
    else {
        return cast_to<i32>(FloatToBits(v) >> 52) - 1'023;
    }
}

NOVA_FUNC u32 Significand(f32 v)
{
    return cast_to<u32>(FloatToBits(v)) & u32((1 << 23) - 1);
}

NOVA_FUNC u64 Significand(f64 v)
{
    return cast_to<u64>(FloatToBits(v)) & u64((1ull << 52) - 1);
}

NOVA_FUNC u32 SignBit(f32 v)
{
    return FloatToBits(v) & (u32)0x80000000;
}

NOVA_FUNC u64 SignBit(f64 v)
{
    return FloatToBits(v) & (u64)0x8000000000000000;
}

NOVA_FUNC auto NextFloatUp(std::floating_point auto v)
{
    if (IsInf(v) && v > 0)
        return v;

    if (v == -0.)
        v = 0.f;

    auto ui = FloatToBits(v);
    return BitsToFloat(v >= 0 ? ++ui : --ui);
}

NOVA_FUNC auto NextFloatDown(std::floating_point auto v)
{
    if (IsInf(v) && v < 0)
        return v;
    if (v == 0.f)
        v = -0.f;

    auto ui = FloatToBits(v);
    return BitsToFloat(v >= 0 ? --ui : ++ui);
}

NOVA_FUNC Float AddRoundUp(Float a, Float b)
{
    return NextFloatUp(a + b);
}

NOVA_FUNC Float AddRoundDown(Float a, Float b)
{
    return NextFloatDown(a + b);
}

NOVA_FUNC Float SubRoundUp(Float a, Float b)
{
    return AddRoundUp(a, -b);
}

NOVA_FUNC Float SubRoundDown(Float a, Float b)
{
    return AddRoundDown(a, -b);
}

NOVA_FUNC Float MulRoundUp(Float a, Float b)
{
    return NextFloatUp(a * b);
}

NOVA_FUNC Float MulRoundDown(Float a, Float b)
{
    return NextFloatDown(a * b);
}

NOVA_FUNC Float DivRoundUp(Float a, Float b)
{
    return NextFloatUp(a / b);
}

NOVA_FUNC Float DivRoundDown(Float a, Float b)
{
    return NextFloatDown(a / b);
}

NOVA_FUNC Float RcpRoundUp(Float a)
{
    return NextFloatUp(Float(1) / a);
}

NOVA_FUNC Float RcpRoundDown(Float a)
{
    return NextFloatDown(Float(1) / a);
}

NOVA_FUNC Float SqrtRoundUp(Float a)
{
    return NextFloatUp(Sqrt(a));
}

NOVA_FUNC Float SqrtRoundDown(Float a)
{
    return std::max<Float>(0, NextFloatDown(Sqrt(a)));
}

NOVA_FUNC Float FmaRoundUp(Float a, Float b, Float c)
{
    return NextFloatUp(Fma(a, b, c));
}

NOVA_FUNC Float FmaRoundDown(Float a, Float b, Float c)
{
    return NextFloatDown(Fma(a, b, c));
}

} // namespace nova