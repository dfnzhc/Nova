/**
 * @File MatrixTransform.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/14
 * @Brief This file is part of Nova.
 */

#pragma once

#include "./MatrixCommon.hpp"

namespace nova {

template<typename T> NOVA_FUNC mat<4, 4, T> Ortho(T left, T right, T bottom, T top)
{
    mat<4, 4, T> res(1);
    res[0][0] = Two<T>() / (right - left);
    res[1][1] = Two<T>() / (top - bottom);
    res[2][2] = -One<T>();
    res[3][0] = -(right + left) / (right - left);
    res[3][1] = -(top + bottom) / (top - bottom);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> OrthoLH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
{
    mat<4, 4, T> res(1);
    res[0][0] = Two<T>() / (right - left);
    res[1][1] = Two<T>() / (top - bottom);
    res[2][2] = One<T>() / (zFar - zNear);
    res[3][0] = -(right + left) / (right - left);
    res[3][1] = -(top + bottom) / (top - bottom);
    res[3][2] = -zNear / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> OrthoLH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
{
    mat<4, 4, T> res(1);
    res[0][0] = Two<T>() / (right - left);
    res[1][1] = Two<T>() / (top - bottom);
    res[2][2] = Two<T>() / (zFar - zNear);
    res[3][0] = -(right + left) / (right - left);
    res[3][1] = -(top + bottom) / (top - bottom);
    res[3][2] = -(zFar + zNear) / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> OrthoRH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
{
    mat<4, 4, T> res(1);
    res[0][0] = Two<T>() / (right - left);
    res[1][1] = Two<T>() / (top - bottom);
    res[2][2] = -One<T>() / (zFar - zNear);
    res[3][0] = -(right + left) / (right - left);
    res[3][1] = -(top + bottom) / (top - bottom);
    res[3][2] = -zNear / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> OrthoRH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
{
    mat<4, 4, T> res(1);
    res[0][0] = Two<T>() / (right - left);
    res[1][1] = Two<T>() / (top - bottom);
    res[2][2] = -Two<T>() / (zFar - zNear);
    res[3][0] = -(right + left) / (right - left);
    res[3][1] = -(top + bottom) / (top - bottom);
    res[3][2] = -(zFar + zNear) / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> PerspectiveRH_ZO(T fovy, T aspect, T zNear, T zFar)
{
    NOVA_CHECK(Abs(aspect - Epsilon<T>()) > Zero<T>());

    const T tanHalfFovy = Tan(fovy / Two<T>());

    mat<4, 4, T> res(Zero<T>());
    res[0][0] = One<T>() / (aspect * tanHalfFovy);
    res[1][1] = One<T>() / (tanHalfFovy);
    res[2][2] = zFar / (zNear - zFar);
    res[2][3] = -One<T>();
    res[3][2] = -(zFar * zNear) / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> PerspectiveRH_NO(T fovy, T aspect, T zNear, T zFar)
{
    NOVA_CHECK(Abs(aspect - Epsilon<T>()) > Zero<T>());

    const T tanHalfFovy = Tan(fovy / Two<T>());

    mat<4, 4, T> res(Zero<T>());
    res[0][0] = One<T>() / (aspect * tanHalfFovy);
    res[1][1] = One<T>() / (tanHalfFovy);
    res[2][2] = -(zFar + zNear) / (zFar - zNear);
    res[2][3] = -One<T>();
    res[3][2] = -(Two<T>() * zFar * zNear) / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> PerspectiveLH_ZO(T fovy, T aspect, T zNear, T zFar)
{
    NOVA_CHECK(Abs(aspect - Epsilon<T>()) > Zero<T>());

    const T tanHalfFovy = Tan(fovy / Two<T>());

    mat<4, 4, T> res(Zero<T>());
    res[0][0] = One<T>() / (aspect * tanHalfFovy);
    res[1][1] = One<T>() / (tanHalfFovy);
    res[2][2] = zFar / (zFar - zNear);
    res[2][3] = One<T>();
    res[3][2] = -(zFar * zNear) / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> PerspectiveLH_NO(T fovy, T aspect, T zNear, T zFar)
{
    NOVA_CHECK(Abs(aspect - Epsilon<T>()) > Zero<T>());

    const T tanHalfFovy = Tan(fovy / Two<T>());

    mat<4, 4, T> res(Zero<T>());
    res[0][0] = One<T>() / (aspect * tanHalfFovy);
    res[1][1] = One<T>() / (tanHalfFovy);
    res[2][2] = (zFar + zNear) / (zFar - zNear);
    res[2][3] = One<T>();
    res[3][2] = -(Two<T>() * zFar * zNear) / (zFar - zNear);
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> Translate(const mat<3, 3, T>& m, const vec2_t<T>& v)
{
    mat<3, 3, T> res(m);
    res[2] = m[0] * v[0] + m[1] * v[1] + m[2];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> Rotate(const mat<3, 3, T>& m, T angle)
{
    const T a = angle;
    const T c = Cos(a);
    const T s = Sin(a);

    mat<3, 3, T> res;
    res[0] = m[0] * c + m[1] * s;
    res[1] = m[0] * -s + m[1] * c;
    res[2] = m[2];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> Scale(const mat<3, 3, T>& m, const vec2_t<T>& v)
{
    mat<3, 3, T> res;
    res[0] = m[0] * v[0];
    res[1] = m[1] * v[1];
    res[2] = m[2];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> ShearX(const mat<3, 3, T>& m, T y)
{
    mat<3, 3, T> res(1);
    res[0][1] = y;
    return m * res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> ShearY(const mat<3, 3, T>& m, T x)
{
    mat<3, 3, T> res(1);
    res[1][0] = x;
    return m * res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> Translate(const vec3_t<T>& v)
{
    return Translate(mat<4, 4, T>(One<T>()), v);
}

template<typename T> NOVA_FUNC mat<4, 4, T> Rotate(T angle, const vec3_t<T>& v)
{
    return Rotate(mat<4, 4, T>(One<T>()), angle, v);
}

template<typename T> NOVA_FUNC mat<4, 4, T> Scale(const vec3_t<T>& v)
{
    return Scale(mat<4, 4, T>(One<T>()), v);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> Translate(const mat<4, 4, T>& m, const vec3_t<T>& v)
{
    mat<4, 4, T> res(m);
    res[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> Rotate(const mat<4, 4, T>& m, T angle, const vec3_t<T>& v)
{
    const T a = angle;
    const T c = Cos(a);
    const T s = Sin(a);

    vec3_t<T> axis(Normalize(v));
    vec3_t<T> temp((One<T>() - c) * axis);

    mat<4, 4, T> rot;
    rot[0][0] = c + temp[0] * axis[0];
    rot[0][1] = temp[0] * axis[1] + s * axis[2];
    rot[0][2] = temp[0] * axis[2] - s * axis[1];

    rot[1][0] = temp[1] * axis[0] - s * axis[2];
    rot[1][1] = c + temp[1] * axis[1];
    rot[1][2] = temp[1] * axis[2] + s * axis[0];

    rot[2][0] = temp[2] * axis[0] + s * axis[1];
    rot[2][1] = temp[2] * axis[1] - s * axis[0];
    rot[2][2] = c + temp[2] * axis[2];

    mat<4, 4, T> res;
    res[0] = m[0] * rot[0][0] + m[1] * rot[0][1] + m[2] * rot[0][2];
    res[1] = m[0] * rot[1][0] + m[1] * rot[1][1] + m[2] * rot[1][2];
    res[2] = m[0] * rot[2][0] + m[1] * rot[2][1] + m[2] * rot[2][2];
    res[3] = m[3];
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> Orientation(const vec3_t<T>& Normal, const vec3_t<T>& Up)
{
    if (all(Equal(Normal, Up, Epsilon<T>())))
        return mat<4, 4, T>(One<T>());

    auto rot_axis = Cross(Up, Normal);
    T angle       = aCos(Dot(Normal, Up));

    return Rotate(angle, rot_axis);
}

template<typename T> NOVA_FUNC mat<4, 4, T> Scale(const mat<4, 4, T>& m, const vec3_t<T>& v)
{
    mat<4, 4, T> res;
    res[0] = m[0] * v[0];
    res[1] = m[1] * v[1];
    res[2] = m[2] * v[2];
    res[3] = m[3];
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> LookAtRH(const vec3_t<T>& eye, const vec3_t<T>& center, const vec3_t<T>& up)
{
    const vec3_t<T> f(Normalize(center - eye));
    const vec3_t<T> s(Normalize(Cross(f, up)));
    const vec3_t<T> u(Cross(s, f));

    mat<4, 4, T> res(1);
    res[0][0] = s.x;
    res[1][0] = s.y;
    res[2][0] = s.z;
    res[0][1] = u.x;
    res[1][1] = u.y;
    res[2][1] = u.z;
    res[0][2] = -f.x;
    res[1][2] = -f.y;
    res[2][2] = -f.z;
    res[3][0] = -Dot(s, eye);
    res[3][1] = -Dot(u, eye);
    res[3][2] = Dot(f, eye);
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> LookAtLH(const vec3_t<T>& eye, const vec3_t<T>& center, const vec3_t<T>& up)
{
    const vec3_t<T> f(Normalize(center - eye));
    const vec3_t<T> s(Normalize(Cross(up, f)));
    const vec3_t<T> u(Cross(f, s));

    mat<4, 4, T> res(1);
    res[0][0] = s.x;
    res[1][0] = s.y;
    res[2][0] = s.z;
    res[0][1] = u.x;
    res[1][1] = u.y;
    res[2][1] = u.z;
    res[0][2] = f.x;
    res[1][2] = f.y;
    res[2][2] = f.z;
    res[3][0] = -Dot(s, eye);
    res[3][1] = -Dot(u, eye);
    res[3][2] = -Dot(f, eye);
    return res;
}

template<typename T, typename U>
NOVA_FUNC vec3_t<T>
ProjectZO(const vec3_t<T>& obj, const mat<4, 4, T>& model, const mat<4, 4, T>& proj, const vec4_t<U>& viewport)
{
    auto tmp = vec4_t<T>(obj, One<T>());
    tmp      = model * tmp;
    tmp      = proj * tmp;

    tmp   /= tmp.w;
    tmp.x  = tmp.x * cast_to<T>(0.5) + cast_to<T>(0.5);
    tmp.y  = tmp.y * cast_to<T>(0.5) + cast_to<T>(0.5);

    tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
    tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

    return vec3_t<T>(tmp);
}

template<typename T, typename U>
NOVA_FUNC vec3_t<T>
ProjectNO(const vec3_t<T>& obj, const mat<4, 4, T>& model, const mat<4, 4, T>& proj, const vec4_t<U>& viewport)
{
    auto tmp = vec4_t<T>(obj, One<T>());
    tmp      = model * tmp;
    tmp      = proj * tmp;

    tmp    /= tmp.w;
    tmp     = tmp * cast_to<T>(0.5) + cast_to<T>(0.5);
    tmp[0]  = tmp[0] * T(viewport[2]) + T(viewport[0]);
    tmp[1]  = tmp[1] * T(viewport[3]) + T(viewport[1]);

    return vec3_t<T>(tmp);
}

template<typename T, typename U>
NOVA_FUNC vec3_t<T>
unProjectZO(const vec3_t<T>& win, const mat<4, 4, T>& model, const mat<4, 4, T>& proj, const vec4_t<U>& viewport)
{
    auto inv = Inverse(proj * model);

    auto tmp = vec4_t<T>(win, T(1));
    tmp.x    = (tmp.x - T(viewport[0])) / T(viewport[2]);
    tmp.y    = (tmp.y - T(viewport[1])) / T(viewport[3]);
    tmp.x    = tmp.x * Two<T>() - One<T>();
    tmp.y    = tmp.y * Two<T>() - One<T>();

    auto obj  = inv * tmp;
    obj      /= obj.w;

    return vec3_t<T>(obj);
}

template<typename T, typename U>
NOVA_FUNC vec3_t<T>
unProjectNO(const vec3_t<T>& win, const mat<4, 4, T>& model, const mat<4, 4, T>& proj, const vec4_t<U>& viewport)
{
    auto inv = Inverse(proj * model);

    auto tmp = vec4_t<T>(win, T(1));
    tmp.x    = (tmp.x - T(viewport[0])) / T(viewport[2]);
    tmp.y    = (tmp.y - T(viewport[1])) / T(viewport[3]);
    tmp      = tmp * Two<T>() - One<T>();

    auto obj  = inv * tmp;
    obj      /= obj.w;

    return vec3_t<T>(obj);
}

//! Transforms a matrix with a shearing on X axis.
template<typename T> NOVA_FUNC mat<3, 3, T> ShearX2D(const mat<3, 3, T>& m, T s)
{
    mat<3, 3, T> r(1);
    r[1][0] = s;
    return m * r;
}

//! Transforms a matrix with a shearing on Y axis.
template<typename T> NOVA_FUNC mat<3, 3, T> ShearY2D(const mat<3, 3, T>& m, T s)
{
    mat<3, 3, T> r(1);
    r[0][1] = s;
    return m * r;
}

//! Transforms a matrix with a shearing on X axis
template<typename T> NOVA_FUNC mat<4, 4, T> ShearX3D(const mat<4, 4, T>& m, T s, T t)
{
    mat<4, 4, T> r(1);
    r[0][1] = s;
    r[0][2] = t;
    return m * r;
}

//! Transforms a matrix with a shearing on Y axis.
template<typename T> NOVA_FUNC mat<4, 4, T> ShearY3D(const mat<4, 4, T>& m, T s, T t)
{
    mat<4, 4, T> r(1);
    r[1][0] = s;
    r[1][2] = t;
    return m * r;
}

//! Transforms a matrix with a shearing on Z axis.
template<typename T> NOVA_FUNC mat<4, 4, T> ShearZ3D(const mat<4, 4, T>& m, T s, T t)
{
    mat<4, 4, T> r(1);
    r[2][0] = s;
    r[2][1] = t;
    return m * r;
}

//! Build planar projection matrix along normal axis.
template<typename T> NOVA_FUNC mat<3, 3, T> Reflect2D(const mat<3, 3, T>& m, const vec3_t<T>& normal)
{
    mat<3, 3, T> r(One<T>());
    r[0][0] = One<T>() - Two<T>() * normal.x * normal.x;
    r[0][1] = -Two<T>() * normal.x * normal.y;
    r[1][0] = -Two<T>() * normal.x * normal.y;
    r[1][1] = One<T>() - Two<T>() * normal.y * normal.y;
    return m * r;
}

//! Build planar projection matrix along normal axis.
template<typename T> NOVA_FUNC mat<4, 4, T> Reflect3D(const mat<4, 4, T>& m, const vec3_t<T>& normal)
{
    mat<4, 4, T> r(One<T>());
    r[0][0] = One<T>() - Two<T>() * normal.x * normal.x;
    r[0][1] = -Two<T>() * normal.x * normal.y;
    r[0][2] = -Two<T>() * normal.x * normal.z;

    r[1][0] = -Two<T>() * normal.x * normal.y;
    r[1][1] = One<T>() - Two<T>() * normal.y * normal.y;
    r[1][2] = -Two<T>() * normal.y * normal.z;

    r[2][0] = -Two<T>() * normal.x * normal.z;
    r[2][1] = -Two<T>() * normal.y * normal.z;
    r[2][2] = One<T>() - Two<T>() * normal.z * normal.z;
    return m * r;
}

//! Build a scale bias matrix.
template<typename T> NOVA_FUNC mat<3, 3, T> Proj2D(const mat<3, 3, T>& m, const vec3_t<T>& normal)
{
    mat<3, 3, T> r(One<T>());
    r[0][0] = One<T>() - normal.x * normal.x;
    r[0][1] = -normal.x * normal.y;
    r[1][0] = -normal.x * normal.y;
    r[1][1] = One<T>() - normal.y * normal.y;
    return m * r;
}

//! Build a scale bias matrix.
template<typename T> NOVA_FUNC mat<4, 4, T> Proj3D(const mat<4, 4, T>& m, const vec3_t<T>& normal)
{
    mat<4, 4, T> r(One<T>());
    r[0][0] = One<T>() - normal.x * normal.x;
    r[0][1] = -normal.x * normal.y;
    r[0][2] = -normal.x * normal.z;
    r[1][0] = -normal.x * normal.y;
    r[1][1] = One<T>() - normal.y * normal.y;
    r[1][2] = -normal.y * normal.z;
    r[2][0] = -normal.x * normal.z;
    r[2][1] = -normal.y * normal.z;
    r[2][2] = One<T>() - normal.z * normal.z;
    return m * r;
}

template<typename T> NOVA_FUNC mat<4, 4, T> ScaleBias(T scale, T bias)
{
    mat<4, 4, T> result;
    result[3]    = vec4_t<T>(vec3_t<T>(bias), One<T>());
    result[0][0] = scale;
    result[1][1] = scale;
    result[2][2] = scale;
    return result;
}

template<typename T> NOVA_FUNC mat<4, 4, T> ScaleBias(const mat<4, 4, T>& m, T scale, T bias)
{
    return m * ScaleBias<T>(scale, bias);
}

template<typename T> NOVA_FUNC void AxisAngle(const mat<4, 4, T>& m, vec3_t<T>& axis, T& angle)
{
    const T epsilon = Epsilon<T>() * cast_to<T>(1e2);

    const bool nearSymmetrical =
        Abs(m[1][0] - m[0][1]) < epsilon && Abs(m[2][0] - m[0][2]) < epsilon && Abs(m[2][1] - m[1][2]) < epsilon;

    if (nearSymmetrical) {
        const bool nearIdentity = Abs(m[1][0] + m[0][1]) < epsilon && Abs(m[2][0] + m[0][2]) < epsilon &&
                                  Abs(m[2][1] + m[1][2]) < epsilon &&
                                  Abs(m[0][0] + m[1][1] + m[2][2] - cast_to<T>(3.0)) < epsilon;
        if (nearIdentity) {
            angle = Zero<T>();
            axis  = vec3_t<T>(One<T>(), Zero<T>(), Zero<T>());
            return;
        }
        angle = Pi<T>();
        T xx  = (m[0][0] + One<T>()) * cast_to<T>(5);
        T yy  = (m[1][1] + One<T>()) * cast_to<T>(5);
        T zz  = (m[2][2] + One<T>()) * cast_to<T>(5);
        T xy  = (m[1][0] + m[0][1]) * cast_to<T>(25);
        T xz  = (m[2][0] + m[0][2]) * cast_to<T>(25);
        T yz  = (m[2][1] + m[1][2]) * cast_to<T>(25);
        if ((xx > yy) && (xx > zz)) {
            if (xx < epsilon) {
                axis.x = Zero<T>();
                axis.y = cast_to<T>(7'071);
                axis.z = cast_to<T>(7'071);
            }
            else {
                axis.x = Sqrt(xx);
                axis.y = xy / axis.x;
                axis.z = xz / axis.x;
            }
        }
        else if (yy > zz) {
            if (yy < epsilon) {
                axis.x = cast_to<T>(7'071);
                axis.y = Zero<T>();
                axis.z = cast_to<T>(7'071);
            }
            else {
                axis.y = Sqrt(yy);
                axis.x = xy / axis.y;
                axis.z = yz / axis.y;
            }
        }
        else {
            if (zz < epsilon) {
                axis.x = cast_to<T>(7'071);
                axis.y = cast_to<T>(7'071);
                axis.z = Zero<T>();
            }
            else {
                axis.z = Sqrt(zz);
                axis.x = xz / axis.z;
                axis.y = yz / axis.z;
            }
        }
        return;
    }

    const T angleCos = (m[0][0] + m[1][1] + m[2][2] - cast_to<T>(1)) * cast_to<T>(5);
    if (angleCos >= One<T>()) {
        angle = Zero<T>();
    }
    else if (angleCos <= cast_to<T>(-1.0)) {
        angle = Pi<T>();
    }
    else {
        angle = aCos(angleCos);
    }

    axis = Normalize(vec3_t<T>(m[1][2] - m[2][1], m[2][0] - m[0][2], m[0][1] - m[1][0]));
}

template<typename T> NOVA_FUNC mat<4, 4, T> AxisAngleMatrix(const vec3_t<T>& axis, const T angle)
{
    T c         = Cos(angle);
    T s         = Sin(angle);
    T t         = One<T>() - c;
    vec3_t<T> n = Normalize(axis);

    // clang-format off
  return mat<4, 4, T>(t * n.x * n.x + c, t * n.x * n.y + n.z * s, t * n.x * n.z - n.y * s, Zero<T>(),
                     t * n.x * n.y - n.z * s, t * n.y * n.y + c, t * n.y * n.z + n.x * s, Zero<T>(),
                     t * n.x * n.z + n.y * s, t * n.y * n.z - n.x * s, t * n.z * n.z + c, Zero<T>(),
                     Zero<T>(), Zero<T>(), Zero<T>(), One<T>());
    // clang-format on
}

} // namespace nova