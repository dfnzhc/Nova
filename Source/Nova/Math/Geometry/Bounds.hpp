/**
 * @File bounds.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/2
 * @Brief 
 */

#pragma once

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "../Constants.hpp"
#include "./Ray.hpp"

namespace nova {

template<i32 N> struct bounds
{
    static_assert(N == 2 or N == 3, "界限的维度仅有二维与三维");

    static constexpr i32 dimension = N;
    using point_type               = vec<N, Float>;

    point_type minPoint{-kInfinity};
    point_type maxPoint{kInfinity};

    // -------------------------
    // 构造函数
    // -------------------------

    // @formatter:off
    NOVA_FUNC bounds() = default;

    NOVA_FUNC bounds(const point_type& p) : minPoint(p), maxPoint(p) { }

    NOVA_FUNC bounds(const point_type& pMin, const point_type& pMax) : minPoint(pMin), maxPoint(pMax) { }

    // @formatter:on

    // -------------------------
    // 设置与访问
    // -------------------------

    // @formatter:off
    NOVA_FUNC void set(const point_type& p) noexcept { minPoint = maxPoint = p; }

    NOVA_FUNC void set(const point_type& pMin, const point_type& pMax) noexcept
    {
        minPoint = pMin;
        maxPoint = pMax;
    }

    NOVA_FUNC bool valid() const { return all_le(minPoint, maxPoint); }

    NOVA_FUNC bool isPoint() const { return minPoint == maxPoint; }

    NOVA_FUNC bool isFlat() const { return any_eq(minPoint, maxPoint); }

    NOVA_FUNC point_type center() const { return (minPoint + maxPoint) * 0.5f; }

    NOVA_FUNC point_type extent() const { return maxPoint - minPoint; }

    NOVA_FUNC f32 radius() const { return 0.5f * Length(extent()); }

    NOVA_FUNC i32 shortestAxis() const { return minIndex(extent()); }

    NOVA_FUNC i32 longestAxis() const { return maxIndex(extent()); }

    // @formatter:on

    NOVA_FUNC void invalidate()
    {
        minPoint = point_type(-kInfinity);
        maxPoint = point_type(kInfinity);
    }

    NOVA_FUNC f32 area() const
    {
        auto e = extent();
        if constexpr (N == 2)
            return e.x * e.y;
        else
            return (e.x * e.y + e.x * e.z + e.y * e.z) * 2.f;
    }

    NOVA_FUNC f32 maxExtent() const { return extent()[longestAxis()]; }

    NOVA_FUNC point_type corner(i32 index) const
    {
        NOVA_CHECK(index >= 0 && index < (1 << dimension));

        point_type ret;
        for (i32 i = 0; i < dimension; ++i)
            ret[i] = (index & (1 << i)) ? maxPoint[i] : minPoint[i];
        return ret;
    }

    // -------------------------
    // 扩张与重叠判断
    // -------------------------

    auto operator<=>(const bounds& b) const          = default;
    NOVA_FUNC bool operator==(const bounds& b) const = default;
    NOVA_FUNC bool operator!=(const bounds& b) const = default;

    NOVA_FUNC bounds& include(const point_type& p)
    {
        minPoint = Min(minPoint, p);
        maxPoint = Max(maxPoint, p);
        return *this;
    }

    NOVA_FUNC bounds& include(const bounds& b)
    {
        minPoint = Min(minPoint, b.minPoint);
        maxPoint = Max(maxPoint, b.maxPoint);
        return *this;
    }

    NOVA_FUNC bounds& enlarge(f32 amount)
    {
        minPoint -= point_type(amount);
        maxPoint += point_type(amount);
        return *this;
    }

    NOVA_FUNC bounds& intersect(const bounds& b)
    {
        minPoint = Max(minPoint, b.minPoint);
        maxPoint = Min(maxPoint, b.maxPoint);
        return *this;
    }

    NOVA_FUNC bool contains(const point_type& p, bool strict = false) const
    {
        if (strict)
            return all_lt(minPoint, p) and all_lt(p, maxPoint);

        return all_le(minPoint, p) and all_le(p, maxPoint);
    }

    NOVA_FUNC bool contains(const bounds& b, bool strict = false) const
    {
        if (strict)
            return all_lt(minPoint, b.minPoint) and all_lt(b.maxPoint, maxPoint);

        return all_le(minPoint, b.minPoint) and all_le(b.maxPoint, maxPoint);
    }

    NOVA_FUNC bool overlaps(const bounds& b, bool strict = false) const
    {
        if (strict)
            return all_gt(maxPoint, b.minPoint) and all_gt(b.maxPoint, minPoint);

        return all_ge(maxPoint, b.minPoint) and all_ge(b.maxPoint, minPoint);
    }

    NOVA_FUNC bounds& operator|=(const bounds& b) { return include(b); }

    NOVA_FUNC bounds operator|(const bounds& b) const
    {
        bounds ret  = *this;
        return ret |= b;
    }

    NOVA_FUNC bounds& operator&=(const bounds& b) { return intersect(b); }

    NOVA_FUNC bounds operator&(const bounds& b) const
    {
        bounds ret  = *this;
        return ret &= b;
    }
};

using rect = bounds<2>;
using aabb = bounds<3>;

template<i32 N> NOVA_FUNC f32 DistanceSqr(const bounds<N>& b, const vec<N, f32>& p)
{
    f32 res = 0.f;

    for (i32 i = 0; i < N; ++i) {
        f32 val = 0.f;
        if (p[i] < b.b.minPoint[i])
            val = f32(b.b.minPoint[i] - p[i]);
        else if (p[i] > b.b.maxPoint[i])
            val = f32(p[i] - b.b.maxPoint[i]);

        res += val * val;
    }

    return res;
}

template<i32 N> NOVA_FUNC f32 DistanceSqr(const vec<N, f32>& p, const bounds<N>& b)
{
    return DistanceSqr(b, p);
}

template<i32 N> NOVA_FUNC f32 Distance(const bounds<N>& b, const vec<N, f32>& p)
{
    return Sqrt(DistanceSqr(b, p));
}

template<i32 N> NOVA_FUNC f32 Distance(const vec<N, f32>& p, const bounds<N>& b)
{
    return Sqrt(DistanceSqr(b, p));
}

template<i32 N> NOVA_FUNC f32 DistanceSqr(const bounds<N>& b1, const bounds<N>& b2)
{
    f32 res = 0.f;

    for (i32 i = 0; i < N; ++i) {
        f32 val = 0.f;
        if (b2.b.maxPoint[i] < b1.b.minPoint[i])
            val = f32(b1.b.minPoint[i] - b2.b.maxPoint[i]);
        else if (b2.b.minPoint[i] > b1.b.maxPoint[i])
            val = f32(b2.b.minPoint[i] - b2.b.maxPoint[i]);

        res += val * val;
    }

    return res;
}

template<i32 N> NOVA_FUNC f32 Distance(const bounds<N>& b1, const bounds<N>& b2)
{
    return Sqrt(DistanceSqr(b1, b2));
}

// -------------------------
// 三维 bounds(aabb) 函数
// -------------------------

NOVA_FUNC f32 Volume(const aabb& b)
{
    auto e = b.extent();
    return e.x * e.y * e.z;
}

NOVA_FUNC aabb TransformAABB(const mat4x4_t<Float>& m, const aabb& b)
{
    if (!b.valid())
        return {};

    float3 xa   = GetColumn(m, 0).xyz() * b.minPoint.x;
    float3 xb   = GetColumn(m, 0).xyz() * b.maxPoint.x;
    float3 xMin = Min(xa, xb);
    float3 xMax = Max(xa, xb);

    float3 ya   = GetColumn(m, 1).xyz() * b.minPoint.y;
    float3 yb   = GetColumn(m, 1).xyz() * b.maxPoint.y;
    float3 yMin = Min(ya, yb);
    float3 yMax = Max(ya, yb);

    float3 za   = GetColumn(m, 2).xyz() * b.minPoint.z;
    float3 zb   = GetColumn(m, 2).xyz() * b.maxPoint.z;
    float3 zMin = Min(za, zb);
    float3 zMax = Max(za, zb);

    float3 newMin = xMin + yMin + zMin + GetColumn(m, 3).xyz();
    float3 newMax = xMax + yMax + zMax + GetColumn(m, 3).xyz();

    return aabb(newMin, newMax);
}

NOVA_FUNC bool RayIntersect(const aabb& b, const Ray& r)
{
    auto nearT = -std::numeric_limits<Float>::infinity();
    auto farT  = std::numeric_limits<Float>::infinity();

    auto inv_d = Float(1) / r.dir;

    for (i32 i = 0; i < aabb::dimension; ++i) {
        auto origin  = Float(r.origin[i]);
        Float minVal = b.minPoint[i], maxVal = b.maxPoint[i];

        if (r.dir[i] == 0) {
            if (origin < minVal || origin > maxVal)
                return false;
        }
        else {
            auto t1 = (minVal - origin) * inv_d[i];
            auto t2 = (maxVal - origin) * inv_d[i];

            if (t1 > t2)
                Swap(t1, t2);

            nearT = Max(t1, nearT);
            farT  = Min(t2, farT);

            if (nearT > farT)
                return false;
        }
    }

    return r.tMin <= farT && nearT <= r.tMax;
}

NOVA_FUNC bool RayIntersect(const aabb& b, const Ray& r, Float& nearT, Float& farT)
{
    nearT = -std::numeric_limits<Float>::infinity();
    farT  = std::numeric_limits<Float>::infinity();

    auto inv_d = Float(1) / r.dir;

    for (i32 i = 0; i < aabb::dimension; ++i) {
        auto origin  = Float(r.origin[i]);
        Float minVal = b.minPoint[i], maxVal = b.maxPoint[i];

        if (r.dir[i] == 0) {
            if (origin < minVal || origin > maxVal)
                return false;
        }
        else {
            auto t1 = (minVal - origin) * inv_d[i];
            auto t2 = (maxVal - origin) * inv_d[i];

            if (t1 > t2)
                Swap(t1, t2);

            nearT = Max(t1, nearT);
            farT  = Min(t2, farT);

            if (nearT > farT)
                return false;
        }
    }

    return r.tMin <= farT && nearT <= r.tMax;
}

} // namespace nova