/**
 * @File Matrix3x2.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/14
 * @Brief This file is part of Nova.
 */

#pragma once

#include "../Math.hpp"
#include "../Vector.hpp"
#include "./MatrixType.hpp"

namespace nova {
template<typename T> struct mat<3, 2, T>
{
    using col_type       = vec2_t<T>;
    using row_type       = vec3_t<T>;
    using mat_type       = mat<3, 2, T>;
    using transpose_type = mat<2, 3, T>;
    using value_type     = T;

private:
    col_type value[3];

public:
    NOVA_FUNC_DECL constexpr mat() = default;

    NOVA_FUNC_DECL constexpr explicit mat(T scalar);
    NOVA_FUNC_DECL constexpr mat(T x0, T y0, T x1, T y1, T x2, T y2);
    NOVA_FUNC_DECL constexpr mat(const col_type& v0, const col_type& v1, const col_type& v2);

    template<typename X1, typename Y1, typename X2, typename Y2, typename X3, typename Y3>
    NOVA_FUNC_DECL constexpr mat(X1 x0, Y1 y0, X2 x1, Y2 y1, X3 x2, Y3 y2);

    template<typename V1, typename V2, typename V3>
    NOVA_FUNC_DECL constexpr mat(const vec2_t<V1>& v0, const vec2_t<V2>& v1, const vec2_t<V3>& v2);

    template<typename U> NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 2, U>& m);

    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 3, T>& m);

    // clang-format off
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator=(const mat<3, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator+=(const mat<3, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator-=(const mat<3, 2, U>& m);

    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator+=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator-=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator*=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator/=(U s);
    // clang-format on

    NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator++();
    NOVA_FUNC_DECL constexpr mat<3, 2, T>& operator--();
    NOVA_FUNC_DECL constexpr mat<3, 2, T> operator++(i32);
    NOVA_FUNC_DECL constexpr mat<3, 2, T> operator--(i32);

    // clang-format off
    NOVA_FUNC constexpr       value_type& data(i32 r, i32 c)       noexcept { return this->value[c][r]; }
    NOVA_FUNC constexpr const value_type& data(i32 r, i32 c) const noexcept { return this->value[c][r]; }

    NOVA_FUNC constexpr       col_type& operator[](i32 index)       noexcept { return this->value[index]; }
    NOVA_FUNC constexpr const col_type& operator[](i32 index) const noexcept { return this->value[index]; }

    NOVA_FUNC static constexpr i32 row() { return 2; }
    NOVA_FUNC static constexpr i32 col() { return 3; }

    // clang-format on
};

// clang-format off
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator+(const mat<3, 2, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator-(const mat<3, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator+(const mat<3, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator+(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator-(const mat<3, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator-(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator*(const mat<3, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator*(T scalar, const mat<3, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<3, 2, T>::col_type operator*(const mat<3, 2, T>& m, const typename mat<3, 2, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<3, 2, T>::row_type operator*(const typename mat<3, 2, T>::col_type& v, const mat<3, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator*(const mat<3, 2, T>& m1, const mat<2, 3, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator*(const mat<3, 2, T>& m1, const mat<3, 3, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator*(const mat<3, 2, T>& m1, const mat<4, 3, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator/(const mat<3, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator/(T scalar, const mat<3, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr bool operator==(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr bool operator!=(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2);
// clang-format on

} //namespace nova

namespace nova {

template<typename T> NOVA_FUNC constexpr mat<3, 2, T>::mat(T s) : value{col_type(s, 0), col_type(0, s), col_type(0, 0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(T x0, T y0, T x1, T y1, T x2, T y2)
: value{col_type(x0, y0), col_type(x1, y1), col_type(x2, y2)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const col_type& v0, const col_type& v1, const col_type& v2)
: value{col_type(v0), col_type(v1), col_type(v2)}
{
}

template<typename T>
template<typename X0, typename Y0, typename X1, typename Y1, typename X2, typename Y2>
NOVA_FUNC constexpr mat<3, 2, T>::mat(X0 x0, Y0 y0, X1 x1, Y1 y1, X2 x2, Y2 y2)
: value{col_type(x0, y0), col_type(x1, y1), col_type(x2, y2)}
{
}

template<typename T>
template<typename V0, typename V1, typename V2>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const vec2_t<V0>& v0, const vec2_t<V1>& v1, const vec2_t<V2>& v2)
: value{col_type(v0), col_type(v1), col_type(v2)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<3, 2, U>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<2, 2, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<3, 3, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<4, 4, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<2, 3, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<2, 4, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(0)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<3, 4, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<4, 2, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 2, T>::mat(const mat<4, 3, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator=(const mat<3, 2, U>& m)
{
    this->value[0] = m[0];
    this->value[1] = m[1];
    this->value[2] = m[2];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator+=(U s)
{
    this->value[0] += s;
    this->value[1] += s;
    this->value[2] += s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator+=(const mat<3, 2, U>& m)
{
    this->value[0] += m[0];
    this->value[1] += m[1];
    this->value[2] += m[2];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator-=(U s)
{
    this->value[0] -= s;
    this->value[1] -= s;
    this->value[2] -= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator-=(const mat<3, 2, U>& m)
{
    this->value[0] -= m[0];
    this->value[1] -= m[1];
    this->value[2] -= m[2];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator*=(U s)
{
    this->value[0] *= s;
    this->value[1] *= s;
    this->value[2] *= s;
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator/=(U s)
{
    this->value[0] /= s;
    this->value[1] /= s;
    this->value[2] /= s;
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator++()
{
    ++this->value[0];
    ++this->value[1];
    ++this->value[2];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T>& mat<3, 2, T>::operator--()
{
    --this->value[0];
    --this->value[1];
    --this->value[2];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> mat<3, 2, T>::operator++(i32)
{
    mat<3, 2, T> res(*this);
    ++*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> mat<3, 2, T>::operator--(i32)
{
    mat<3, 2, T> res(*this);
    --*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator+(const mat<3, 2, T>& m)
{
    return m;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator-(const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(-m[0], -m[1], -m[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator+(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator+(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2)
{
    return mat<3, 2, T>(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator-(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator-(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2)
{
    return mat<3, 2, T>(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator*(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator*(T scalar, const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar);
}

template<typename T>
NOVA_FUNC constexpr typename mat<3, 2, T>::col_type operator*(const mat<3, 2, T>& m,
                                                              const typename mat<3, 2, T>::row_type& v)
{
    return typename mat<3, 2, T>::col_type(m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z,
                                           m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z);
}

template<typename T>
NOVA_FUNC constexpr typename mat<3, 2, T>::row_type operator*(const typename mat<3, 2, T>::col_type& v,
                                                              const mat<3, 2, T>& m)
{
    return typename mat<3, 2, T>::row_type(
        v.x * m[0][0] + v.y * m[0][1], v.x * m[1][0] + v.y * m[1][1], v.x * m[2][0] + v.y * m[2][1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator*(const mat<3, 2, T>& m1, const mat<2, 3, T>& m2)
{
    const auto a00 = m1[0][0];
    const auto a01 = m1[0][1];
    const auto a10 = m1[1][0];
    const auto a11 = m1[1][1];
    const auto a20 = m1[2][0];
    const auto a21 = m1[2][1];

    const auto b00 = m2[0][0];
    const auto b01 = m2[0][1];
    const auto b02 = m2[0][2];
    const auto b10 = m2[1][0];
    const auto b11 = m2[1][1];
    const auto b12 = m2[1][2];

    mat<2, 2, T> res;
    res[0][0] = a00 * b00 + a10 * b01 + a20 * b02;
    res[0][1] = a01 * b00 + a11 * b01 + a21 * b02;
    res[1][0] = a00 * b10 + a10 * b11 + a20 * b12;
    res[1][1] = a01 * b10 + a11 * b11 + a21 * b12;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator*(const mat<3, 2, T>& m1, const mat<3, 3, T>& m2)
{
    return mat<3, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator*(const mat<3, 2, T>& m1, const mat<4, 3, T>& m2)
{
    return mat<4, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2],
                        m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2],
                        m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator/(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] / scalar, m[1] / scalar, m[2] / scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator/(T scalar, const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(scalar / m[0], scalar / m[1], scalar / m[2]);
}

template<typename T> NOVA_FUNC constexpr bool operator==(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2)
{
    return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2)
{
    return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]);
}
} //namespace nova
