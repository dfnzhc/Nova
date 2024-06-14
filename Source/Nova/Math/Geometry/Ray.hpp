/**
 * @File Ray.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/2
 * @Brief 
 */

#pragma once

#include "../Vector.hpp"

namespace nova {

struct Ray
{
    float3 origin;
    f32 tMin;
    float3 dir;
    f32 tMax;

    Ray() = default;

    explicit Ray(float3 o, float3 d, f32 t_min = 0.f, f32 t_max = std::numeric_limits<f32>::max())
    : origin(o), tMin(t_min), dir(d), tMax(t_max)
    {
    }

    [[nodiscard]] constexpr float3 at(f32 t) const noexcept { return origin + Normalize(dir) * t; }
};

// 这些检查是为了确保 Ray 的布局与 DXR 的 RayDesc 一致
static_assert(offsetof(Ray, origin) == 0);
static_assert(offsetof(Ray, tMin) == sizeof(float3));
static_assert(offsetof(Ray, dir) == offsetof(Ray, tMin) + sizeof(f32));
static_assert(offsetof(Ray, tMax) == offsetof(Ray, dir) + sizeof(float3));
static_assert(sizeof(Ray) == 32);

} // namespace nova