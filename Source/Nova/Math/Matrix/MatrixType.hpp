/**
 * @File MatrixType.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/1
 * @Brief 
 */

#pragma once

#include "../Math.hpp"

namespace nova {

/// 矩阵
template<i32 C, i32 R, typename T> struct mat;

// clang-format off
template<typename T> using mat2x2_t = mat<2, 2, T>;
template<typename T> using mat2x3_t = mat<2, 3, T>;
template<typename T> using mat2x4_t = mat<2, 4, T>;

template<typename T> using mat3x2_t = mat<3, 2, T>;
template<typename T> using mat3x3_t = mat<3, 3, T>;
template<typename T> using mat3x4_t = mat<3, 4, T>;

template<typename T> using mat4x2_t = mat<4, 2, T>;
template<typename T> using mat4x3_t = mat<4, 3, T>;
template<typename T> using mat4x4_t = mat<4, 4, T>;
// clang-format on

using float2x2 = mat2x2_t<f32>;
using float3x3 = mat3x3_t<f32>;
using float4x4 = mat4x4_t<f32>;

} // namespace nova