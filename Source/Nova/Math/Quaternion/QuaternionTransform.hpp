/**
 * @File QuaternionTransform.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/1
 * @Brief 
 */

#pragma once

#include "./Quaternion.hpp"
#include "./QuaternionCommon.hpp"

namespace nova {

template<typename T> NOVA_FUNC quat<T> Rotate(const quat<T>& q, const T& angle, const vec3_t<T>& axis)
{
    vec3_t<T> tmp = axis;

    // Axis of rotation must be normalised
    T len = Length(tmp);
    if (Abs(len - One<T>()) > cast_to<T>(0.001)) {
        T one_over_len  = One<T>() / len;
        tmp.x          *= one_over_len;
        tmp.y          *= one_over_len;
        tmp.z          *= one_over_len;
    }

    const T angle_rad(angle);
    const T sin_val = Sin(angle_rad * cast_to<T>(0.5));

    return q * quat<T>::wxyz(Cos(angle_rad * cast_to<T>(0.5)), tmp.x * sin_val, tmp.y * sin_val, tmp.z * sin_val);
}

template<typename T> NOVA_FUNC quat<T> QuatLookAtRH(const vec3_t<T>& direction, const vec3_t<T>& up)
{
    mat3x3_t<T> res;

    res[2]                 = -direction;
    const vec3_t<T>& right = Cross(up, res[2]);
    res[0]                 = right * rSqrt(Max(cast_to<T>(0.00001), Dot(right, right)));
    res[1]                 = Cross(res[2], res[0]);

    return QuatCast(res);
}

template<typename T> NOVA_FUNC quat<T> QuatLookAtLH(const vec3_t<T>& direction, const vec3_t<T>& up)
{
    mat3x3_t<T> res;

    res[2]                 = direction;
    const vec3_t<T>& right = Cross(up, res[2]);
    res[0]                 = right * rSqrt(Max(cast_to<T>(0.00001), Dot(right, right)));
    res[1]                 = Cross(res[2], res[0]);

    return QuatCast(res);
}

} // namespace nova
