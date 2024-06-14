/**
 * @File Math.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/27
 * @Brief 
 */

#pragma once

#include "../Base/Defines.hpp"

#include <cmath>
#include <climits>
#include <cfloat>
#include <limits>
#include <cstdint>
#include <cstddef>
#include <type_traits>

namespace nova {

// concepts
// clang-format off
template<typename T> concept BoolType = std::is_same_v<bool, T>;
template<typename T> concept U32Type  = std::is_same_v<u32, T>;
template<typename T> concept U64Type  = std::is_same_v<u64, T>;
template<typename T> concept F32Type  = std::is_same_v<f32, T>;
template<typename T> concept F64Type  = std::is_same_v<f64, T>;

template<typename T> concept SignedType     = std::is_signed_v<T>;
template<typename T> concept UnsignedType   = std::is_unsigned_v<T>;
template<typename T> concept IntegralType   = std::is_integral_v<T>;
template<typename T> concept FloatType      = std::is_floating_point_v<T>;
template<typename T> concept ArithmeticType = std::is_arithmetic_v<T>;
// clang-format on

template<typename T, typename U>
concept Convertible = (not std::is_same_v<T, U>)and std::is_convertible_v<T, U> and std::is_convertible_v<U, T>;

template<typename T, typename U>
concept BothIntegral = IntegralType<T> and IntegralType<U>;

template<ArithmeticType T>
NOVA_FUNC constexpr T cast_to(ArithmeticType auto f) noexcept
    requires std::is_nothrow_convertible_v<decltype(f), T>
{
    return static_cast<T>(f);
}

} // namespace nova