/**
 * @File Quaternion.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/31
 * @Brief 
 */

#pragma once

#include "../Math.hpp"
#include "../Vector.hpp"
#include "../Matrix.hpp"

namespace nova {

template<typename T> struct quat
{
    using quat_type  = quat<T>;
    using value_type = T;

    T x = Zero<T>(), y = Zero<T>(), z = Zero<T>(), w = One<T>();

    NOVA_FUNC_DECL constexpr quat()                 = default;
    NOVA_FUNC_DECL constexpr quat(const quat<T>& q) = default;

    NOVA_FUNC_DECL constexpr quat(T s, const vec3_t<T>& v);
    NOVA_FUNC_DECL constexpr quat(T w, T x, T y, T z);

    template<typename U> NOVA_FUNC_DECL constexpr explicit quat(const quat<U>& q);

    NOVA_FUNC_DECL constexpr explicit operator mat3x3_t<T>() const;
    NOVA_FUNC_DECL constexpr explicit operator mat4x4_t<T>() const;

    NOVA_FUNC_DECL quat(const vec3_t<T>& u, const vec3_t<T>& v);

    NOVA_FUNC_DECL constexpr explicit quat(const vec3_t<T>& eulerAngles);
    NOVA_FUNC_DECL constexpr explicit quat(const mat3x3_t<T>& m);
    NOVA_FUNC_DECL constexpr explicit quat(const mat4x4_t<T>& m);

    NOVA_FUNC_DECL constexpr quat<T>& operator=(const quat<T>& q) = default;

    // clang-format off
    template<typename U> NOVA_FUNC_DECL constexpr quat<T>&  operator=(const quat<U>& q);
    template<typename U> NOVA_FUNC_DECL constexpr quat<T>& operator+=(const quat<U>& q);
    template<typename U> NOVA_FUNC_DECL constexpr quat<T>& operator-=(const quat<U>& q);
    template<typename U> NOVA_FUNC_DECL constexpr quat<T>& operator*=(const quat<U>& q);
    template<typename U> NOVA_FUNC_DECL constexpr quat<T>& operator*=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr quat<T>& operator/=(U s);
    // clang-format on

    NOVA_FUNC_DECL static constexpr quat<T> wxyz(T w, T x, T y, T z);

    // clang-format off
    NOVA_FUNC_DECL static constexpr i32 length() { return 4; }

    NOVA_FUNC constexpr       T& operator[](i32 index)       noexcept { return (&x)[index]; }
    NOVA_FUNC constexpr const T& operator[](i32 index) const noexcept { return (&x)[index]; }

    // clang-format on
};

// clang-format off
template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator+(const quat<T>& q);
template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator-(const quat<T>& q);

template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator+(const quat<T>& q, const quat<T>& p);
template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator-(const quat<T>& q, const quat<T>& p);

template<typename T> NOVA_FUNC_DECL constexpr quat<T>   operator*(const quat<T>& q, const quat<T>& p);
template<typename T> NOVA_FUNC_DECL constexpr vec3_t<T> operator*(const quat<T>& q, const vec3_t<T>& v);
template<typename T> NOVA_FUNC_DECL constexpr vec3_t<T> operator*(const vec3_t<T>& v, const quat<T>& q);
template<typename T> NOVA_FUNC_DECL constexpr vec4_t<T> operator*(const quat<T>& q, const vec4_t<T>& v);
template<typename T> NOVA_FUNC_DECL constexpr vec4_t<T> operator*(const vec4_t<T>& v, const quat<T>& q);

template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator*(const quat<T>& q, const T& s);
template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator*(const T& s, const quat<T>& q);

template<typename T> NOVA_FUNC_DECL constexpr quat<T> operator/(const quat<T>& q, const T& s);

template<typename T> NOVA_FUNC_DECL constexpr bool operator==(const quat<T>& q1, const quat<T>& q2);
template<typename T> NOVA_FUNC_DECL constexpr bool operator!=(const quat<T>& q1, const quat<T>& q2);
// clang-format on

using quatf = quat<f32>;
using quatd = quat<f64>;

} //namespace nova

#include "./QuaternionCommon.hpp"

namespace nova {

template<typename T> NOVA_FUNC constexpr quat<T>::quat(T s, const vec3_t<T>& v) : x(v.x), y(v.y), z(v.z), w(s)
{
}

template<typename T> NOVA_FUNC constexpr quat<T>::quat(T _w, T _x, T _y, T _z) : x(_x), y(_y), z(_z), w(_w)
{
}

template<typename T> constexpr quat<T> quat<T>::wxyz(T w, T x, T y, T z)
{
    return quat<T>(w, x, y, z);
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr quat<T>::quat(const quat<U>& q)
: x(cast_to<T>(q.x)), y(cast_to<T>(q.y)), z(cast_to<T>(q.z)), w(cast_to<T>(q.w))
{
}

template<typename T> NOVA_FUNC quat<T>::quat(const vec3_t<T>& u, const vec3_t<T>& v)
{
    T norm_u_norm_v = Sqrt(Dot(u, u) * Dot(v, v));
    T real_part     = norm_u_norm_v + Dot(u, v);
    vec3_t<T> t;

    if (real_part < cast_to<T>(1.e-6f) * norm_u_norm_v) {
        // If u and v are exactly opposite, rotate 180 Degrees
        // around an arbitrary orthogonal axis. Axis normalisation
        // can happen later, when we normalise the quaternion.
        real_part = Zero<T>();
        t         = Abs(u.x) > Abs(u.z) ? vec3_t<T>(-u.y, u.x, Zero<T>()) : vec3_t<T>(Zero<T>(), -u.z, u.y);
    }
    else {
        // Otherwise, build quaternion the standard way.
        t = Cross(u, v);
    }

    *this = Normalize(quat<T>::wxyz(real_part, t.x, t.y, t.z));
}

template<typename T> NOVA_FUNC constexpr quat<T>::quat(const vec3_t<T>& eulerAngle)
{
    vec3_t<T> c = nova::Cos(eulerAngle * T(0.5));
    vec3_t<T> s = nova::Sin(eulerAngle * T(0.5));

    this->w = c.x * c.y * c.z + s.x * s.y * s.z;
    this->x = s.x * c.y * c.z - c.x * s.y * s.z;
    this->y = c.x * s.y * c.z + s.x * c.y * s.z;
    this->z = c.x * c.y * s.z - s.x * s.y * c.z;
}

template<typename T> NOVA_FUNC constexpr quat<T>::quat(const mat3x3_t<T>& m)
{
    *this = QuatCast(m);
}

template<typename T> NOVA_FUNC constexpr quat<T>::quat(const mat4x4_t<T>& m)
{
    *this = QuatCast(m);
}

template<typename T> NOVA_FUNC constexpr quat<T>::operator mat3x3_t<T>() const
{
    return Mat3Cast(*this);
}

template<typename T> NOVA_FUNC constexpr quat<T>::operator mat4x4_t<T>() const
{
    return Mat4Cast(*this);
}

template<typename T> template<typename U> NOVA_FUNC constexpr quat<T>& quat<T>::operator=(const quat<U>& q)
{
    this->w = cast_to<T>(q.w);
    this->x = cast_to<T>(q.x);
    this->y = cast_to<T>(q.y);
    this->z = cast_to<T>(q.z);
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr quat<T>& quat<T>::operator+=(const quat<U>& q)
{
    w += q.w;
    x += q.x;
    y += q.y;
    z += q.z;
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr quat<T>& quat<T>::operator-=(const quat<U>& q)
{
    w -= q.w;
    x -= q.x;
    y -= q.y;
    z -= q.z;
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr quat<T>& quat<T>::operator*=(const quat<U>& q)
{
    const quat<T> p(*this);

    this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
    this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
    this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
    this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr quat<T>& quat<T>::operator*=(U s)
{
    w *= s;
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr quat<T>& quat<T>::operator/=(U s)
{
    NOVA_CHECK(s != Zero<T>());

    w /= s;
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

template<typename T> NOVA_FUNC constexpr quat<T> operator+(const quat<T>& q)
{
    return q;
}

template<typename T> NOVA_FUNC constexpr quat<T> operator-(const quat<T>& q)
{
    return quat<T>::wxyz(-q.w, -q.x, -q.y, -q.z);
}

template<typename T> NOVA_FUNC constexpr quat<T> operator+(const quat<T>& q, const quat<T>& p)
{
    return quat<T>(q) += p;
}

template<typename T> NOVA_FUNC constexpr quat<T> operator-(const quat<T>& q, const quat<T>& p)
{
    return quat<T>(q) -= p;
}

template<typename T> NOVA_FUNC constexpr quat<T> operator*(const quat<T>& q, const quat<T>& p)
{
    return quat<T>(q) *= p;
}

template<typename T> NOVA_FUNC constexpr vec3_t<T> operator*(const quat<T>& q, const vec3_t<T>& v)
{
    const vec3_t<T> quat_vec(q.x, q.y, q.z);
    const vec3_t<T> uv(Cross(quat_vec, v));
    const vec3_t<T> uuv(Cross(quat_vec, uv));

    return v + ((uv * q.w) + uuv) * cast_to<T>(2);
}

template<typename T> NOVA_FUNC constexpr vec3_t<T> operator*(const vec3_t<T>& v, const quat<T>& q)
{
    return nova::Inverse(q) * v;
}

template<typename T> NOVA_FUNC constexpr vec4_t<T> operator*(const quat<T>& q, const vec4_t<T>& v)
{
    return vec4_t<T>(q * vec3_t<T>(v), v.w);
}

template<typename T> NOVA_FUNC constexpr vec4_t<T> operator*(const vec4_t<T>& v, const quat<T>& q)
{
    return nova::Inverse(q) * v;
}

template<typename T> NOVA_FUNC constexpr quat<T> operator*(const quat<T>& q, const T& s)
{
    return quat<T>::wxyz(q.w * s, q.x * s, q.y * s, q.z * s);
}

template<typename T> NOVA_FUNC constexpr quat<T> operator*(const T& s, const quat<T>& q)
{
    return q * s;
}

template<typename T> NOVA_FUNC constexpr quat<T> operator/(const quat<T>& q, const T& s)
{
    return quat<T>::wxyz(q.w / s, q.x / s, q.y / s, q.z / s);
}

template<typename T> NOVA_FUNC constexpr bool operator==(const quat<T>& q1, const quat<T>& q2)
{
    return q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w;
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const quat<T>& q1, const quat<T>& q2)
{
    return q1.x != q2.x || q1.y != q2.y || q1.z != q2.z || q1.w != q2.w;
}
} //namespace nova