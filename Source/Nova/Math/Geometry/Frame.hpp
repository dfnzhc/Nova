/**
 * @File Frame.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/11
 * @Brief 
 */

#pragma once

#include "../Vector.hpp"

namespace nova {

// TODO：2d frame

template<typename T> class Frame
{
public:
    using vec_type = vec<3, T>;

    NOVA_FUNC Frame() : x(1, 0, 0), y(0, 1, 0), z(0, 0, 1) { }

    NOVA_FUNC Frame(vec_type vx, vec_type vy, vec_type vz) : x(vx), y(vy), z(vz)
    {
        NOVA_CHECK_LT(Abs(LengthSqr(vx) - 1), 1e-4);
        NOVA_CHECK_LT(Abs(LengthSqr(vy) - 1), 1e-4);
        NOVA_CHECK_LT(Abs(LengthSqr(vz) - 1), 1e-4);
        NOVA_CHECK_LT(Abs(Dot(vx, vy)), 1e-4);
        NOVA_CHECK_LT(Abs(Dot(vy, vz)), 1e-4);
        NOVA_CHECK_LT(Abs(Dot(vz, vx)), 1e-4);
    }

    NOVA_FUNC static Frame FromXZ(vec_type x, vec_type z) { return Frame(x, Cross(z, x), z); }

    NOVA_FUNC static Frame FromXY(vec_type x, vec_type y) { return Frame(x, y, Cross(x, y)); }

    NOVA_FUNC static Frame FromZ(vec_type z)
    {
        vec_type x, y;
        CoordinateSystem(z, x, y);
        return Frame(x, y, z);
    }

    NOVA_FUNC static Frame FromX(vec_type x)
    {
        vec_type y, z;
        CoordinateSystem(x, y, z);
        return Frame(x, y, z);
    }

    NOVA_FUNC static Frame FromY(vec_type y)
    {
        vec_type x, z;
        CoordinateSystem(y, &z, &x);
        return Frame(x, y, z);
    }

    NOVA_FUNC vec_type toLocal(vec_type v) const { return vec_type(Dot(v, x), Dot(v, y), Dot(v, z)); }

    NOVA_FUNC vec_type fromLocal(vec_type v) const { return v.x * x + v.y * y + v.z * z; }

    vec_type x, y, z;
};

} // namespace nova