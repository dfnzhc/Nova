/**
 * @File Matrix3x3.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/14
 * @Brief This file is part of Nova.
 */

#pragma once

#include "../Math.hpp"
#include "../Vector.hpp"
#include "./MatrixType.hpp"
#include "./MatrixCommon.hpp"

namespace nova {
template<typename T> struct mat<3, 3, T>
{
    using col_type       = vec3_t<T>;
    using row_type       = vec3_t<T>;
    using mat_type       = mat<3, 3, T>;
    using transpose_type = mat<3, 3, T>;
    using value_type     = T;

private:
    col_type value[3];

public:
    NOVA_FUNC_DECL constexpr mat() = default;

    NOVA_FUNC_DECL constexpr explicit mat(T scalar);
    NOVA_FUNC_DECL constexpr mat(T x0, T y0, T z0, T x1, T y1, T z1, T x2, T y2, T z2);
    NOVA_FUNC_DECL constexpr mat(const col_type& v0, const col_type& v1, const col_type& v2);

    // clang-format off
    template<typename X1, typename Y1, typename Z1,
             typename X2, typename Y2, typename Z2,
             typename X3, typename Y3, typename Z3>
    NOVA_FUNC_DECL constexpr mat(X1 x1, Y1 y1, Z1 z1, X2 x2, Y2 y2, Z2 z2, X3 x3, Y3 y3, Z3 z3);
    // clang-format on

    template<typename V1, typename V2, typename V3>
    NOVA_FUNC_DECL constexpr mat(const vec3_t<V1>& v1, const vec3_t<V2>& v2, const vec3_t<V3>& v3);

    template<typename U> NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 3, U>& m);

    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 3, T>& m);

    // clang-format off
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator=(const mat<3, 3, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator+=(const mat<3, 3, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator-=(const mat<3, 3, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator*=(const mat<3, 3, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator/=(const mat<3, 3, U>& m);

    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator+=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator-=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator*=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator/=(U s);
    // clang-format on

    NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator++();
    NOVA_FUNC_DECL constexpr mat<3, 3, T>& operator--();
    NOVA_FUNC_DECL constexpr mat<3, 3, T> operator++(i32);
    NOVA_FUNC_DECL constexpr mat<3, 3, T> operator--(i32);

    // clang-format off
    NOVA_FUNC constexpr       value_type& data(i32 r, i32 c)       noexcept { return this->value[c][r]; }
    NOVA_FUNC constexpr const value_type& data(i32 r, i32 c) const noexcept { return this->value[c][r]; }

    NOVA_FUNC constexpr       col_type& operator[](i32 index)       noexcept { return this->value[index]; }
    NOVA_FUNC constexpr const col_type& operator[](i32 index) const noexcept { return this->value[index]; }

    NOVA_FUNC static constexpr i32 row() { return 3; }
    NOVA_FUNC static constexpr i32 col() { return 3; }

    // clang-format on
};

// clang-format off
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator+(const mat<3, 3, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator-(const mat<3, 3, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator+(const mat<3, 3, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator+(T scalar, const mat<3, 3, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator+(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator-(const mat<3, 3, T>& m, T scalar);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator-(T scalar, const mat<3, 3, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator-(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator*(const mat<3, 3, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator*(T scalar, const mat<3, 3, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<3, 3, T>::col_type operator*(const mat<3, 3, T>& m, const typename mat<3, 3, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<3, 3, T>::row_type operator*(const typename mat<3, 3, T>::col_type& v, const mat<3, 3, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator*(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 3, T> operator*(const mat<3, 3, T>& m1, const mat<2, 3, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 3, T> operator*(const mat<3, 3, T>& m1, const mat<4, 3, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator/(const mat<3, 3, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator/(T scalar, const mat<3, 3, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 3, T> operator/(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<3, 3, T>::col_type operator/(const mat<3, 3, T>& m, const typename mat<3, 3, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<3, 3, T>::row_type operator/(const typename mat<3, 3, T>::col_type& v, const mat<3, 3, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr bool operator==(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr bool operator!=(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2);
// clang-format on
} //namespace nova

namespace nova {

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(T s) : value{col_type(s, 0, 0), col_type(0, s, 0), col_type(0, 0, s)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(T x0, T y0, T z0, T x1, T y1, T z1, T x2, T y2, T z2)
: value{col_type(x0, y0, z0), col_type(x1, y1, z1), col_type(x2, y2, z2)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const col_type& v0, const col_type& v1, const col_type& v2)
: value{col_type(v0), col_type(v1), col_type(v2)}
{
}

// clang-format off
template<typename T>
template<typename X1, typename Y1, typename Z1,
       typename X2, typename Y2, typename Z2,
       typename X3, typename Y3, typename Z3>
NOVA_FUNC constexpr mat<3, 3, T>::mat(X1 x1, Y1 y1, Z1 z1, X2 x2, Y2 y2, Z2 z2, X3 x3, Y3 y3, Z3 z3)
: value{col_type(x1, y1, z1), col_type(x2, y2, z2), col_type(x3, y3, z3)}
{
}

// clang-format on

template<typename T>
template<typename V1, typename V2, typename V3>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const vec3_t<V1>& v1, const vec3_t<V2>& v2, const vec3_t<V3>& v3)
: value{col_type(v1), col_type(v2), col_type(v3)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<3, 3, U>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<2, 2, T>& m)
: value{col_type(m[0], 0), col_type(m[1], 0), col_type(0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<4, 4, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<2, 3, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<3, 2, T>& m)
: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<2, 4, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<4, 2, T>& m)
: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<3, 4, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<3, 3, T>::mat(const mat<4, 3, T>& m) : value{col_type(m[0]), col_type(m[1]), col_type(m[2])}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator=(const mat<3, 3, U>& m)
{
    this->value[0] = m[0];
    this->value[1] = m[1];
    this->value[2] = m[2];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator+=(U s)
{
    this->value[0] += s;
    this->value[1] += s;
    this->value[2] += s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator+=(const mat<3, 3, U>& m)
{
    this->value[0] += m[0];
    this->value[1] += m[1];
    this->value[2] += m[2];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator-=(U s)
{
    this->value[0] -= s;
    this->value[1] -= s;
    this->value[2] -= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator-=(const mat<3, 3, U>& m)
{
    this->value[0] -= m[0];
    this->value[1] -= m[1];
    this->value[2] -= m[2];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator*=(U s)
{
    col_type sv(s);
    this->value[0] *= sv;
    this->value[1] *= sv;
    this->value[2] *= sv;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator*=(const mat<3, 3, U>& m)
{
    return (*this = *this * m);
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator/=(U s)
{
    this->value[0] /= s;
    this->value[1] /= s;
    this->value[2] /= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator/=(const mat<3, 3, U>& m)
{
    return *this *= Inverse(m);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator++()
{
    ++this->value[0];
    ++this->value[1];
    ++this->value[2];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T>& mat<3, 3, T>::operator--()
{
    --this->value[0];
    --this->value[1];
    --this->value[2];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> mat<3, 3, T>::operator++(i32)
{
    mat<3, 3, T> res(*this);
    ++*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> mat<3, 3, T>::operator--(i32)
{
    mat<3, 3, T> res(*this);
    --*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator+(const mat<3, 3, T>& m)
{
    return m;
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator-(const mat<3, 3, T>& m)
{
    return mat<3, 3, T>(-m[0], -m[1], -m[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator+(const mat<3, 3, T>& m, T scalar)
{
    return mat<3, 3, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator+(T scalar, const mat<3, 3, T>& m)
{
    return mat<3, 3, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator+(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    return mat<3, 3, T>(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator-(const mat<3, 3, T>& m, T scalar)
{
    return mat<3, 3, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator-(T scalar, const mat<3, 3, T>& m)
{
    return mat<3, 3, T>(scalar - m[0], scalar - m[1], scalar - m[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator-(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    return mat<3, 3, T>(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator*(const mat<3, 3, T>& m, T scalar)
{
    return mat<3, 3, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator*(T scalar, const mat<3, 3, T>& m)
{
    return mat<3, 3, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar);
}

template<typename T>
NOVA_FUNC constexpr typename mat<3, 3, T>::col_type operator*(const mat<3, 3, T>& m,
                                                              const typename mat<3, 3, T>::row_type& v)
{
    return typename mat<3, 3, T>::col_type(m[0] * ReduceX(v) + m[1] * ReduceY(v) + m[2] * ReduceZ(v));
}

template<typename T>
NOVA_FUNC constexpr typename mat<3, 3, T>::row_type operator*(const typename mat<3, 3, T>::col_type& v,
                                                              const mat<3, 3, T>& m)
{
    return typename mat<3, 3, T>::row_type(nova::Dot(m[0], v), nova::Dot(m[1], v), nova::Dot(m[2], v));
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator*(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    const auto& a0 = m1[0];
    const auto& a1 = m1[1];
    const auto& a2 = m1[2];

    const auto& b0 = m2[0];
    const auto& b1 = m2[1];
    const auto& b2 = m2[2];

    mat<3, 3, T> res;
    typename mat<3, 3, T>::col_type tmp;
    tmp     = a0 * b0.x;
    tmp    += a1 * b0.y;
    tmp    += a2 * b0.z;
    res[0]  = tmp;
    tmp     = a0 * b1.x;
    tmp    += a1 * b1.y;
    tmp    += a2 * b1.z;
    res[1]  = tmp;
    tmp     = a0 * b2.x;
    tmp    += a1 * b2.y;
    tmp    += a2 * b2.z;
    res[2]  = tmp;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<2, 3, T> operator*(const mat<3, 3, T>& m1, const mat<2, 3, T>& m2)
{
    return mat<2, 3, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2],
                        m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2],
                        m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 3, T> operator*(const mat<3, 3, T>& m1, const mat<4, 3, T>& m2)
{
    return mat<4, 3, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2],
                        m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2],
                        m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2],
                        m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2],
                        m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2],
                        m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2],
                        m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1] + m1[2][2] * m2[3][2]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator/(const mat<3, 3, T>& m, T scalar)
{
    return mat<3, 3, T>(m[0] / scalar, m[1] / scalar, m[2] / scalar);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator/(T scalar, const mat<3, 3, T>& m)
{
    return mat<3, 3, T>(scalar / m[0], scalar / m[1], scalar / m[2]);
}

template<typename T>
NOVA_FUNC constexpr typename mat<3, 3, T>::col_type operator/(const mat<3, 3, T>& m,
                                                              const typename mat<3, 3, T>::row_type& v)
{
    return Inverse(m) * v;
}

template<typename T>
NOVA_FUNC constexpr typename mat<3, 3, T>::row_type operator/(const typename mat<3, 3, T>::col_type& v,
                                                              const mat<3, 3, T>& m)
{
    return v * Inverse(m);
}

template<typename T> NOVA_FUNC constexpr mat<3, 3, T> operator/(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    mat<3, 3, T> m1_copy(m1);
    return m1_copy /= m2;
}

template<typename T> NOVA_FUNC constexpr bool operator==(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]);
}
} //namespace nova
