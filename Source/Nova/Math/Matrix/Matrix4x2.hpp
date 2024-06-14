/**
 * @File Matrix4x2.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/14
 * @Brief This file is part of Nova.
 */

#pragma once

#include "../Math.hpp"
#include "../Vector.hpp"
#include "./MatrixType.hpp"

namespace nova {
template<typename T> struct mat<4, 2, T>
{
    using col_type       = vec2_t<T>;
    using row_type       = vec4_t<T>;
    using mat_type       = mat<4, 2, T>;
    using transpose_type = mat<2, 4, T>;
    using value_type     = T;

private:
    col_type value[4];

public:
    NOVA_FUNC_DECL constexpr mat() = default;

    NOVA_FUNC_DECL constexpr mat(T scalar);
    NOVA_FUNC_DECL constexpr mat(T x0, T y0, T x1, T y1, T x2, T y2, T x3, T y3);
    NOVA_FUNC_DECL constexpr mat(const col_type& v0, const col_type& v1, const col_type& v2, const col_type& v3);

    template<typename X0, typename Y0, typename X1, typename Y1, typename X2, typename Y2, typename X3, typename Y3>
    NOVA_FUNC_DECL constexpr mat(X0 x0, Y0 y0, X1 x1, Y1 y1, X2 x2, Y2 y2, X3 x3, Y3 y3);

    template<typename V1, typename V2, typename V3, typename V4>
    NOVA_FUNC_DECL constexpr mat(const vec2_t<V1>& v1,
                                 const vec2_t<V2>& v2,
                                 const vec2_t<V3>& v3,
                                 const vec2_t<V4>& v4);

    template<typename U> NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 2, U>& m);

    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 4, T>& m);

    // clang-format off
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator=(const mat<4, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator+=(const mat<4, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator-=(const mat<4, 2, U>& m);

    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator+=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator-=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator*=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator/=(U s);
    // clang-format on

    NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator++();
    NOVA_FUNC_DECL constexpr mat<4, 2, T>& operator--();
    NOVA_FUNC_DECL constexpr mat<4, 2, T> operator++(i32);
    NOVA_FUNC_DECL constexpr mat<4, 2, T> operator--(i32);

    // clang-format off
    NOVA_FUNC constexpr       value_type& data(i32 r, i32 c)       noexcept { return this->value[c][r]; }
    NOVA_FUNC constexpr const value_type& data(i32 r, i32 c) const noexcept { return this->value[c][r]; }

    NOVA_FUNC constexpr       col_type& operator[](i32 index)       noexcept { return this->value[index]; }
    NOVA_FUNC constexpr const col_type& operator[](i32 index) const noexcept { return this->value[index]; }

    NOVA_FUNC static constexpr i32 row() { return 2; }
    NOVA_FUNC static constexpr i32 col() { return 4; }

    // clang-format on
};

// clang-format off
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator+(const mat<4, 2, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator-(const mat<4, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator+(const mat<4, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator+(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator-(const mat<4, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator-(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator*(const mat<4, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator*(T scalar, const mat<4, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<4, 2, T>::col_type operator*(const mat<4, 2, T>& m, const typename mat<4, 2, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<4, 2, T>::row_type operator*(const typename mat<4, 2, T>::col_type& v, const mat<4, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator*(const mat<4, 2, T>& m1, const mat<2, 4, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator*(const mat<4, 2, T>& m1, const mat<3, 4, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator*(const mat<4, 2, T>& m1, const mat<4, 4, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator/(const mat<4, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator/(T scalar, const mat<4, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr bool operator==(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr bool operator!=(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2);
// clang-format on
} //namespace nova

namespace nova {

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(T s) : value{col_type(s, 0), col_type(0, s), col_type(0, 0), col_type(0, 0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(T x0, T y0, T x1, T y1, T x2, T y2, T x3, T y3)
: value{col_type(x0, y0), col_type(x1, y1), col_type(x2, y2), col_type(x3, y3)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const col_type& v0, const col_type& v1, const col_type& v2, const col_type& v3)
: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
{
}

template<typename T>
template<typename X0, typename Y0, typename X1, typename Y1, typename X2, typename Y2, typename X3, typename Y3>
NOVA_FUNC constexpr mat<4, 2, T>::mat(X0 x0, Y0 y0, X1 x1, Y1 y1, X2 x2, Y2 y2, X3 x3, Y3 y3)
: value{col_type(x0, y0), col_type(x1, y1), col_type(x2, y2), col_type(x3, y3)}
{
}

template<typename T>
template<typename V0, typename V1, typename V2, typename V3>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const vec2_t<V0>& v0,
                                      const vec2_t<V1>& v1,
                                      const vec2_t<V2>& v2,
                                      const vec2_t<V3>& v3)
: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<4, 2, U>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<2, 2, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<3, 3, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<4, 4, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<2, 3, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<3, 2, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<2, 4, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<4, 3, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 2, T>::mat(const mat<3, 4, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator=(const mat<4, 2, U>& m)
{
    this->value[0] = m[0];
    this->value[1] = m[1];
    this->value[2] = m[2];
    this->value[3] = m[3];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator+=(U s)
{
    this->value[0] += s;
    this->value[1] += s;
    this->value[2] += s;
    this->value[3] += s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator+=(const mat<4, 2, U>& m)
{
    this->value[0] += m[0];
    this->value[1] += m[1];
    this->value[2] += m[2];
    this->value[3] += m[3];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator-=(U s)
{
    this->value[0] -= s;
    this->value[1] -= s;
    this->value[2] -= s;
    this->value[3] -= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator-=(const mat<4, 2, U>& m)
{
    this->value[0] -= m[0];
    this->value[1] -= m[1];
    this->value[2] -= m[2];
    this->value[3] -= m[3];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator*=(U s)
{
    this->value[0] *= s;
    this->value[1] *= s;
    this->value[2] *= s;
    this->value[3] *= s;
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator/=(U s)
{
    this->value[0] /= s;
    this->value[1] /= s;
    this->value[2] /= s;
    this->value[3] /= s;
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator++()
{
    ++this->value[0];
    ++this->value[1];
    ++this->value[2];
    ++this->value[3];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T>& mat<4, 2, T>::operator--()
{
    --this->value[0];
    --this->value[1];
    --this->value[2];
    --this->value[3];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> mat<4, 2, T>::operator++(i32)
{
    mat<4, 2, T> res(*this);
    ++*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> mat<4, 2, T>::operator--(i32)
{
    mat<4, 2, T> res(*this);
    --*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator+(const mat<4, 2, T>& m)
{
    return m;
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator-(const mat<4, 2, T>& m)
{
    return mat<4, 2, T>(-m[0], -m[1], -m[2], -m[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator+(const mat<4, 2, T>& m, T scalar)
{
    return mat<4, 2, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar, m[3] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator+(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2)
{
    return mat<4, 2, T>(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2], m1[3] + m2[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator-(const mat<4, 2, T>& m, T scalar)
{
    return mat<4, 2, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar, m[3] - scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator-(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2)
{
    return mat<4, 2, T>(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2], m1[3] - m2[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator*(const mat<4, 2, T>& m, T scalar)
{
    return mat<4, 2, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator*(T scalar, const mat<4, 2, T>& m)
{
    return mat<4, 2, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
}

template<typename T>
NOVA_FUNC constexpr typename mat<4, 2, T>::col_type operator*(const mat<4, 2, T>& m,
                                                              const typename mat<4, 2, T>::row_type& v)
{
    return typename mat<4, 2, T>::col_type(m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w,
                                           m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w);
}

template<typename T>
NOVA_FUNC constexpr typename mat<4, 2, T>::row_type operator*(const typename mat<4, 2, T>::col_type& v,
                                                              const mat<4, 2, T>& m)
{
    return typename mat<4, 2, T>::row_type(v.x * m[0][0] + v.y * m[0][1],
                                           v.x * m[1][0] + v.y * m[1][1],
                                           v.x * m[2][0] + v.y * m[2][1],
                                           v.x * m[3][0] + v.y * m[3][1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator*(const mat<4, 2, T>& m1, const mat<2, 4, T>& m2)
{
    const T a00 = m1[0][0];
    const T a01 = m1[0][1];
    const T a10 = m1[1][0];
    const T a11 = m1[1][1];
    const T a20 = m1[2][0];
    const T a21 = m1[2][1];
    const T a30 = m1[3][0];
    const T a31 = m1[3][1];

    const T b00 = m2[0][0];
    const T b01 = m2[0][1];
    const T b02 = m2[0][2];
    const T b03 = m2[0][3];
    const T b10 = m2[1][0];
    const T b11 = m2[1][1];
    const T b12 = m2[1][2];
    const T b13 = m2[1][3];

    mat<2, 2, T> res;
    res[0][0] = a00 * b00 + a10 * b01 + a20 * b02 + a30 * b03;
    res[0][1] = a01 * b00 + a11 * b01 + a21 * b02 + a31 * b03;
    res[1][0] = a00 * b10 + a10 * b11 + a20 * b12 + a30 * b13;
    res[1][1] = a01 * b10 + a11 * b11 + a21 * b12 + a31 * b13;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator*(const mat<4, 2, T>& m1, const mat<3, 4, T>& m2)
{
    return mat<3, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator*(const mat<4, 2, T>& m1, const mat<4, 4, T>& m2)
{
    return mat<4, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
                        m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
                        m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator/(const mat<4, 2, T>& m, T scalar)
{
    return mat<4, 2, T>(m[0] / scalar, m[1] / scalar, m[2] / scalar, m[3] / scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator/(T scalar, const mat<4, 2, T>& m)
{
    return mat<4, 2, T>(scalar / m[0], scalar / m[1], scalar / m[2], scalar / m[3]);
}

template<typename T> NOVA_FUNC constexpr bool operator==(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2)
{
    return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2)
{
    return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
}
} //namespace nova
