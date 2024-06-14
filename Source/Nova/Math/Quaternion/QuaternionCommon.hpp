/**
 * @File QuaternionCommon.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/1
 * @Brief 
 */

#pragma once

#include "../Bit.hpp"
#include "../Vector.hpp"
#include "./Quaternion.hpp"

namespace nova {

#define DEFINE_QUATERNION_COMPARE_OP(func_name, op, logic_op)                                                          \
    template<ArithmeticType T> NOVA_FUNC constexpr bool func_name(const quat<T>& lhs, const quat<T>& rhs)              \
    {                                                                                                                  \
        return (lhs.x op rhs.x)logic_op(lhs.y op rhs.y) logic_op(lhs.z op rhs.z) logic_op(lhs.w op rhs.w);             \
    }

DEFINE_QUATERNION_COMPARE_OP(any_gt, >, or)
DEFINE_QUATERNION_COMPARE_OP(any_ge, >=, or)
DEFINE_QUATERNION_COMPARE_OP(any_lt, <, or)
DEFINE_QUATERNION_COMPARE_OP(any_le, <=, or)
DEFINE_QUATERNION_COMPARE_OP(any_eq, ==, or)

DEFINE_QUATERNION_COMPARE_OP(all_gt, >, and)
DEFINE_QUATERNION_COMPARE_OP(all_ge, >=, and)
DEFINE_QUATERNION_COMPARE_OP(all_lt, <, and)
DEFINE_QUATERNION_COMPARE_OP(all_le, <=, and)
DEFINE_QUATERNION_COMPARE_OP(all_eq, ==, and)
#undef DEFINE_QUATERNION_COMPARE_OP

template<typename T> NOVA_FUNC constexpr bool4 cwEqual(const quat<T>& x, const quat<T>& y)
{
    return all_eq(x, y);
}

template<typename T> NOVA_FUNC constexpr bool4 cwEqual(const quat<T>& x, const quat<T>& y, T epsilon)
{
    vec4_t<T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
    return all_lt(Abs(v), vec4_t<T>(epsilon));
}

template<typename T> NOVA_FUNC constexpr bool4 cwNotEqual(const quat<T>& x, const quat<T>& y)
{
    return not Equal(x, y);
}

template<typename T> NOVA_FUNC constexpr bool4 cwNotEqual(const quat<T>& x, const quat<T>& y, T epsilon)
{
    return not equal(x, y, epsilon);
}

template<typename T> NOVA_FUNC constexpr bool Equal(const quat<T>& x, const quat<T>& y)
{
    return all(cwEqual(x, y));
}

template<typename T> NOVA_FUNC constexpr bool Equal(const quat<T>& x, const quat<T>& y, T epsilon)
{
    return all(cwEqual(x, y, epsilon));
}

template<typename T> NOVA_FUNC constexpr bool NotEqual(const quat<T>& x, const quat<T>& y)
{
    return not Equal(x, y);
}

template<typename T> NOVA_FUNC constexpr bool notEqual(const quat<T>& x, const quat<T>& y, T epsilon)
{
    return not Equal(x, y, epsilon);
}

template<typename T> NOVA_FUNC bool4 IsNaN(const quat<T>& q)
{
    return bool4(IsNaN(q.x), IsNaN(q.y), IsNaN(q.z), IsNaN(q.w));
}

template<typename T> NOVA_FUNC bool4 IsInf(const quat<T>& q)
{
    return bool4(IsInf(q.x), IsInf(q.y), IsInf(q.z), IsInf(q.w));
}

template<typename T> NOVA_FUNC T Angle(const quat<T>& x)
{
    if (Abs(x.w) > cast_to<T>(0.877582561890372716130286068203503191)) {
        const T a = aSin(Sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * cast_to<T>(2);
        if (x.w < Zero<T>())
            return Pi<T>() * cast_to<T>(2) - a;
        return a;
    }

    return aCos(x.w) * cast_to<T>(2);
}

template<typename T> NOVA_FUNC vec3_t<T> Axis(const quat<T>& x)
{
    const T tmp1 = One<T>() - x.w * x.w;
    if (tmp1 <= Zero<T>())
        return vec3_t<T>(0, 0, 1);
    const T tmp2 = One<T>() * rSqrt(tmp1);

    return vec3_t<T>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
}

template<typename T> NOVA_FUNC quat<T> AngleAxis(const T& angle, const vec3_t<T>& axis)
{
    const T a(angle);
    const T s = Sin(a * cast_to<T>(0.5));

    return quat<T>(Cos(a * cast_to<T>(0.5)), axis * s);
}

template<typename T> NOVA_FUNC vec3_t<T> EulerAngles(const quat<T>& x)
{
    return vec3_t<T>(Pitch(x), Yaw(x), Roll(x));
}

template<typename T> NOVA_FUNC T Roll(const quat<T>& q)
{
    const T y = cast_to<T>(2) * (q.x * q.y + q.w * q.z);
    const T x = q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z;

    if (all(Equal(vec2_t<T>(x, y), vec2_t<T>(0), Epsilon<T>()))) //avoid aTan2(0,0) - handle singularity - Matiis
        return Zero<T>();

    return cast_to<T>(aTan(y, x));
}

template<typename T> NOVA_FUNC T Pitch(const quat<T>& q)
{
    const T y = cast_to<T>(2) * (q.y * q.z + q.w * q.x);
    const T x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

    if (all(equal(vec2_t<T>(x, y), vec2_t<T>(0), Epsilon<T>()))) //avoid aTan2(0,0) - handle singularity - Matiis
        return cast_to<T>(cast_to<T>(2) * aTan(q.x, q.w));

    return cast_to<T>(aTan(y, x));
}

template<typename T> NOVA_FUNC T Yaw(const quat<T>& q)
{
    return aSin(Clamp(cast_to<T>(-2) * (q.x * q.z - q.w * q.y), cast_to<T>(-1), One<T>()));
}

template<typename T> NOVA_FUNC T Length(const quat<T>& q)
{
    return Sqrt(Dot(q, q));
}

template<typename T> NOVA_FUNC quat<T> Normalize(const quat<T>& q)
{
    T len = Length(q);
    if (len <= Zero<T>()) // Problem
        return quat<T>::wxyz(One<T>(), Zero<T>(), Zero<T>(), Zero<T>());

    T one_over_len = One<T>() / len;
    return quat<T>::wxyz(q.w * one_over_len, q.x * one_over_len, q.y * one_over_len, q.z * one_over_len);
}

template<typename T> NOVA_FUNC constexpr T Dot(const quat<T>& a, const quat<T>& b)
{
    vec4_t<T> tmp(a.w * b.w, a.x * b.x, a.y * b.y, a.z * b.z);
    return (tmp.x + tmp.y) + (tmp.z + tmp.w);
}

template<typename T> NOVA_FUNC constexpr quat<T> Cross(const quat<T>& q1, const quat<T>& q2)
{
    return quat<T>::wxyz(q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
                         q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
                         q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
                         q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
}

template<typename T> NOVA_FUNC quat<T> Mix(const quat<T>& x, const quat<T>& y, T a)
{
    const T cosTheta = Dot(x, y);

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of Sin(angle) becoming a zero denominator
    if (cosTheta > One<T>() - Epsilon<T>()) {
        // Linear interpolation
        return quat<T>::wxyz(mix(x.w, y.w, a), mix(x.x, y.x, a), mix(x.y, y.y, a), mix(x.z, y.z, a));
    }
    else {
        // Essential Mathematics, page 467
        T angle = aCos(cosTheta);
        return (Sin((One<T>() - a) * angle) * x + Sin(a * angle) * y) / Sin(angle);
    }
}

template<typename T> NOVA_FUNC constexpr quat<T> Lerp(const quat<T>& x, const quat<T>& y, T a)
{
    NOVA_CHECK(a >= Zero<T>());
    NOVA_CHECK(a <= One<T>());

    return x * (One<T>() - a) + (y * a);
}

template<typename T> NOVA_FUNC quat<T> Slerp(const quat<T>& x, const quat<T>& y, T a)
{
    quat<T> z = y;

    T cosTheta = Dot(x, y);

    // If cosTheta < 0, the interpolation will take the long way around the sphere.
    // To fix this, One quat must be negated.
    if (cosTheta < Zero<T>()) {
        z        = -y;
        cosTheta = -cosTheta;
    }

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of Sin(angle) becoming a zero denominator
    if (cosTheta > One<T>() - Epsilon<T>()) {
        // Linear interpolation
        return quat<T>::wxyz(Mix(x.w, z.w, a), Mix(x.x, z.x, a), Mix(x.y, z.y, a), Mix(x.z, z.z, a));
    }
    else {
        // Essential Mathematics, page 467
        T angle = aCos(cosTheta);
        return (Sin((One<T>() - a) * angle) * x + Sin(a * angle) * z) / Sin(angle);
    }
}

template<typename T, IntegralType S> NOVA_FUNC quat<T> Slerp(const quat<T>& x, const quat<T>& y, T a, S k)
{
    quat<T> z = y;

    T cosTheta = Dot(x, y);

    // If cosTheta < 0, the interpolation will take the long way around the sphere.
    // To fix this, One quat must be negated.
    if (cosTheta < Zero<T>()) {
        z        = -y;
        cosTheta = -cosTheta;
    }

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of Sin(angle) becoming a zero denominator
    if (cosTheta > One<T>() - Epsilon<T>()) {
        // Linear interpolation
        return quat<T>::wxyz(mix(x.w, z.w, a), mix(x.x, z.x, a), mix(x.y, z.y, a), mix(x.z, z.z, a));
    }
    else {
        // Graphics Gems III, page 96
        T angle = aCos(cosTheta);
        T phi   = angle + cast_to<T>(k) * Pi<1, T>();
        return (Sin(angle - a * phi) * x + Sin(a * phi) * z) / Sin(angle);
    }
}

template<typename T> NOVA_FUNC constexpr quat<T> Conjugate(const quat<T>& q)
{
    return quat<T>::wxyz(q.w, -q.x, -q.y, -q.z);
}

template<typename T> NOVA_FUNC constexpr quat<T> Inverse(const quat<T>& q)
{
    return Conjugate(q) / Dot(q, q);
}

template<typename T> NOVA_FUNC_DECL quat<T> Exp(const quat<T>& q)
{
    vec3_t<T> u(q.x, q.y, q.z);
    const T angle = Length(u);
    if (angle < Epsilon<T>())
        return quat<T>();

    const vec3_t<T> v(u / angle);
    return quat<T>(Cos(angle), Sin(angle) * v);
}

template<typename T> NOVA_FUNC_DECL quat<T> Log(const quat<T>& q)
{
    vec3_t<T> u(q.x, q.y, q.z);
    T vec_len = Length(u);

    if (vec_len < Epsilon<T>()) {
        if (q.w > Zero<T>())
            return quat<T>::wxyz(Log(q.w), Zero<T>(), Zero<T>(), Zero<T>());
        else if (q.w < Zero<T>())
            return quat<T>::wxyz(Log(-q.w), Pi<T>(), Zero<T>(), Zero<T>());
        else
            return quat<T>::wxyz(Infinity<T>(), Infinity<T>(), Infinity<T>(), Infinity<T>());
    }
    else {
        T t         = aTan(vec_len, T(q.w)) / vec_len;
        T quat_len2 = vec_len * vec_len + q.w * q.w;
        return quat<T>::wxyz(cast_to<T>(0.5) * Log(quat_len2), t * q.x, t * q.y, t * q.z);
    }
}

template<typename T> NOVA_FUNC_DECL quat<T> Pow(const quat<T>& x, T y)
{
    //Raising to the power of 0 should yield 1
    //Needed to prevent a division by 0 error later on
    if (y > -Epsilon<T>() && y < Epsilon<T>())
        return quat<T>::wxyz(1, 0, 0, 0);

    //To deal with non-unit quaternions
    T magnitude = Sqrt(x.x * x.x + x.y * x.y + x.z * x.z + x.w * x.w);

    T angle;
    if (Abs(x.w / magnitude) > cast_to<T>(0.877582561890372716130286068203503191)) {
        //Scalar component is close to 1; using it to recover angle would lose precision
        //Instead, we use the non-scalar components since Sin() is accurate around 0

        //Prevent a division by 0 error later on
        T vec_mag = x.x * x.x + x.y * x.y + x.z * x.z;
        //Despite the compiler might say, we actually want to compare
        //vec_mag to 0. here; we could use denorm_int() compiling a
        //project with unsafe maths optimizations might make the comparison
        //always false, even when vec_mag is 0.
        if (vec_mag < std::numeric_limits<T>::min()) {
            //Equivalent to raising a real number to a power
            return quat<T>::wxyz(Pow(x.w, y), 0, 0, 0);
        }

        angle = aSin(Sqrt(vec_mag) / magnitude);
    }
    else {
        //Scalar component is small, shouldn't cause loss of precision
        angle = aCos(x.w / magnitude);
    }

    T new_angle = angle * y;
    T div       = Sin(new_angle) / Sin(angle);
    T mag       = Pow(magnitude, y - One<T>());
    return quat<T>::wxyz(Cos(new_angle) * magnitude * mag, x.x * div * mag, x.y * div * mag, x.z * div * mag);
}

template<typename T> NOVA_FUNC_DECL quat<T> Sqrt(const quat<T>& q)
{
    return Pow(q, cast_to<T>(0.5));
}

template<typename T> NOVA_FUNC mat3x3_t<T> Mat3Cast(const quat<T>& q)
{
    mat3x3_t<T> res(One<T>());
    T qxx(q.x * q.x);
    T qyy(q.y * q.y);
    T qzz(q.z * q.z);
    T qxz(q.x * q.z);
    T qxy(q.x * q.y);
    T qyz(q.y * q.z);
    T qwx(q.w * q.x);
    T qwy(q.w * q.y);
    T qwz(q.w * q.z);

    res[0][0] = One<T>() - T(2) * (qyy + qzz);
    res[0][1] = T(2) * (qxy + qwz);
    res[0][2] = T(2) * (qxz - qwy);

    res[1][0] = T(2) * (qxy - qwz);
    res[1][1] = One<T>() - T(2) * (qxx + qzz);
    res[1][2] = T(2) * (qyz + qwx);

    res[2][0] = T(2) * (qxz + qwy);
    res[2][1] = T(2) * (qyz - qwx);
    res[2][2] = One<T>() - T(2) * (qxx + qyy);
    return res;
}

template<typename T> NOVA_FUNC mat4x4_t<T> Mat4Cast(const quat<T>& q)
{
    return mat4x4_t<T>(Mat3Cast(q));
}

template<typename T> NOVA_FUNC quat<T> QuatCast(const mat3x3_t<T>& m)
{
    T a = m[0][0] - m[1][1] - m[2][2];
    T b = m[1][1] - m[0][0] - m[2][2];
    T c = m[2][2] - m[0][0] - m[1][1];
    T d = m[0][0] + m[1][1] + m[2][2];

    int index = 0;
    T value   = d;
    if (a > value) {
        value = a;
        index = 1;
    }
    if (b > value) {
        value = b;
        index = 2;
    }
    if (c > value) {
        value = c;
        index = 3;
    }

    T biggest_val = Sqrt(value + One<T>()) * cast_to<T>(0.5);
    T mult        = cast_to<T>(0.25) / biggest_val;

    switch (index) {
    case 0 :
        return quat<T>::wxyz(
            biggest_val, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
    case 1 :
        return quat<T>::wxyz(
            (m[1][2] - m[2][1]) * mult, biggest_val, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
    case 2 :
        return quat<T>::wxyz(
            (m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggest_val, (m[1][2] + m[2][1]) * mult);
    case 3 :
        return quat<T>::wxyz(
            (m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggest_val);
    default : // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
        NOVA_CHECK(false);
        return quat<T>::wxyz(1, 0, 0, 0);
    }
}

template<typename T> NOVA_FUNC quat<T> QuatCast(const mat<4, 4, T>& m4)
{
    return QuatCast(mat3x3_t<T>(m4));
}

template<typename T> NOVA_FUNC constexpr quat<T> QuatIdentity()
{
    return quat<T>::wxyz(One<T>(), Zero<T>(), Zero<T>(), Zero<T>());
}

template<typename T> NOVA_FUNC constexpr vec3_t<T> Cross(const vec3_t<T>& v, const quat<T>& q)
{
    return Inverse(q) * v;
}

template<typename T> NOVA_FUNC constexpr vec3_t<T> Cross(const quat<T>& q, const vec3_t<T>& v)
{
    return q * v;
}

template<typename T>
NOVA_FUNC quat<T> Squad(const quat<T>& q1, const quat<T>& q2, const quat<T>& s1, const quat<T>& s2, const T& h)
{
    return Mix(Mix(q1, q2, h), Mix(s1, s2, h), cast_to<T>(2) * (One<T>() - h) * h);
}

template<typename T> NOVA_FUNC quat<T> Intermediate(const quat<T>& prev, const quat<T>& curr, const quat<T>& next)
{
    quat<T> invQuat = Inverse(curr);
    return Exp((Log(next * invQuat) + Log(prev * invQuat)) / cast_to<T>(-4)) * curr;
}

template<typename T> NOVA_FUNC vec3_t<T> Rotate(const quat<T>& q, const vec3_t<T>& v)
{
    return q * v;
}

template<typename T> NOVA_FUNC vec<4, T> Rotate(const quat<T>& q, const vec<4, T>& v)
{
    return q * v;
}

template<typename T> NOVA_FUNC T ExtractRealComponent(const quat<T>& q)
{
    T w = One<T>() - q.x * q.x - q.y * q.y - q.z * q.z;
    if (w < T(0))
        return T(0);
    else
        return -Sqrt(w);
}

template<typename T> NOVA_FUNC constexpr T Length2(const quat<T>& q)
{
    return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

template<typename T> NOVA_FUNC quat<T> FastMix(const quat<T>& x, const quat<T>& y, const T& a)
{
    return Normalize(x * (One<T>() - a) + (y * a));
}

template<typename T> NOVA_FUNC quat<T> Rotation(const vec3_t<T>& orig, const vec3_t<T>& dest)
{
    T cosTheta = Dot(orig, dest);
    vec3_t<T> rotationAxis;

    if (cosTheta >= One<T>() - Epsilon<T>()) {
        // orig and dest point in the same direction
        return QuatIdentity<T>();
    }

    if (cosTheta < cast_to<T>(-1) + Epsilon<T>()) {
        // special case when vectors in opposite directions :
        // there is no "ideal" rotation axis
        // So guess One; any will do as long as it's perpendicular to start
        // This implementation favors a rotation around the Up axis (Y),
        // since it's often what you want to do.
        rotationAxis = Cross(vec3_t<T>(0, 0, 1), orig);
        if (Length2(rotationAxis) < Epsilon<T>()) // bad luck, they were parallel, try again!
            rotationAxis = Cross(vec3_t<T>(1, 0, 0), orig);

        rotationAxis = normalize(rotationAxis);
        return AngleAxis(Pi<T>(), rotationAxis);
    }

    // Implementation from Stan Melax's Game Programming Gems 1 article
    rotationAxis = Cross(orig, dest);

    T s    = Sqrt((One<T>() + cosTheta) * cast_to<T>(2));
    T invs = One<T>() / s;

    return quat<T>::wxyz(s * cast_to<T>(0.5f), rotationAxis.x * invs, rotationAxis.y * invs, rotationAxis.z * invs);
}

} // namespace nova