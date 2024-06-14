/**
 * @File Matrix4x4.hpp
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
template<typename T> struct mat<4, 4, T>
{
    using col_type       = vec4_t<T>;
    using row_type       = vec4_t<T>;
    using mat_type       = mat<4, 4, T>;
    using transpose_type = mat<4, 4, T>;
    using value_type     = T;

private:
    col_type value[4];

public:
    NOVA_FUNC_DECL constexpr mat() = default;

    NOVA_FUNC_DECL constexpr explicit mat(T s);

    // clang-format off
    NOVA_FUNC_DECL constexpr mat(const T& x0, const T& y0, const T& z0, const T& w0,
                                const T& x1, const T& y1, const T& z1, const T& w1,
                                const T& x2, const T& y2, const T& z2, const T& w2,
                                const T& x3, const T& y3, const T& z3, const T& w3);
    NOVA_FUNC_DECL constexpr mat(const col_type& v0, const col_type& v1, const col_type& v2, const col_type& v3);
    
    template<typename X1, typename Y1, typename Z1, typename W1,
             typename X2, typename Y2, typename Z2, typename W2,
             typename X3, typename Y3, typename Z3, typename W3,
             typename X4, typename Y4, typename Z4, typename W4>
    NOVA_FUNC_DECL constexpr mat(const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
                                const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
                                const X3& x3, const Y3& y3, const Z3& z3, const W3& w3,
                                const X4& x4, const Y4& y4, const Z4& z4, const W4& w4);
    // clang-format on

    template<typename V1, typename V2, typename V3, typename V4>
    NOVA_FUNC_DECL constexpr mat(const vec4_t<V1>& v1,
                                 const vec4_t<V2>& v2,
                                 const vec4_t<V3>& v3,
                                 const vec4_t<V4>& v4);

    template<typename U> NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 4, U>& m);

    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 3, T>& m);

    // clang-format off
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator=(const mat<4, 4, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator+=(const mat<4, 4, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator-=(const mat<4, 4, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator*=(const mat<4, 4, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator/=(const mat<4, 4, U>& m);

    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator+=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator-=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator*=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator/=(U s);
    // clang-format on

    NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator++();
    NOVA_FUNC_DECL constexpr mat<4, 4, T>& operator--();
    NOVA_FUNC_DECL constexpr mat<4, 4, T> operator++(i32);
    NOVA_FUNC_DECL constexpr mat<4, 4, T> operator--(i32);

    // clang-format off
    NOVA_FUNC constexpr       value_type& data(i32 r, i32 c)       noexcept { return this->value[c][r]; }
    NOVA_FUNC constexpr const value_type& data(i32 r, i32 c) const noexcept { return this->value[c][r]; }

    NOVA_FUNC constexpr       col_type& operator[](i32 index)       noexcept { return this->value[index]; }
    NOVA_FUNC constexpr const col_type& operator[](i32 index) const noexcept { return this->value[index]; }

    NOVA_FUNC static constexpr i32 row() { return 4; }
    NOVA_FUNC static constexpr i32 col() { return 4; }

    // clang-format on
};

// clang-format off
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator+(const mat<4, 4, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator-(const mat<4, 4, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator+(const mat<4, 4, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator+(T scalar, const mat<4, 4, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator+(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator-(const mat<4, 4, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator-(T scalar, const mat<4, 4, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator-(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator*(const mat<4, 4, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator*(T scalar, const mat<4, 4, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<4, 4, T>::col_type operator*(const mat<4, 4, T>& m, const typename mat<4, 4, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<4, 4, T>::row_type operator*(const typename mat<4, 4, T>::col_type& v, const mat<4, 4, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 4, T> operator*(const mat<4, 4, T>& m1, const mat<2, 4, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 4, T> operator*(const mat<4, 4, T>& m1, const mat<3, 4, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator*(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator/(const mat<4, 4, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator/(T scalar, const mat<4, 4, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 4, T> operator/(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<4, 4, T>::col_type operator/(const mat<4, 4, T>& m, const typename mat<4, 4, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<4, 4, T>::row_type operator/(const typename mat<4, 4, T>::col_type& v, const mat<4, 4, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr bool operator==(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr bool operator!=(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2);
// clang-format on
} //namespace nova

namespace nova {

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(T s)
: value{col_type(s, 0, 0, 0), col_type(0, s, 0, 0), col_type(0, 0, s, 0), col_type(0, 0, 0, s)}
{
}

// clang-format off
template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const T& x0, const T& y0, const T& z0, const T& w0,
                                  const T& x1, const T& y1, const T& z1, const T& w1,
                                  const T& x2, const T& y2, const T& z2, const T& w2,
                                  const T& x3, const T& y3, const T& z3, const T& w3)
: value{col_type(x0, y0, z0, w0), col_type(x1, y1, z1, w1), col_type(x2, y2, z2, w2), col_type(x3, y3, z3, w3)}
{
}

// clang-format on

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const col_type& v0, const col_type& v1, const col_type& v2, const col_type& v3)
: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<4, 4, U>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
{
}

// clang-format off
template<typename T>
template<typename X1, typename Y1, typename Z1, typename W1,
       typename X2, typename Y2, typename Z2, typename W2,
       typename X3, typename Y3, typename Z3, typename W3,
       typename X4, typename Y4, typename Z4, typename W4>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
                                  const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
                                  const X3& x3, const Y3& y3, const Z3& z3, const W3& w3,
                                  const X4& x4, const Y4& y4, const Z4& z4, const W4& w4)
: value{col_type(x1, y1, z1, w1), col_type(x2, y2, z2, w2), col_type(x3, y3, z3, w3), col_type(x4, y4, z4, w4)}
{
}

// clang-format on

template<typename T>
template<typename V1, typename V2, typename V3, typename V4>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const vec4_t<V1>& v1,
                                      const vec4_t<V2>& v2,
                                      const vec4_t<V3>& v3,
                                      const vec4_t<V4>& v4)
: value{col_type(v1), col_type(v2), col_type(v3), col_type(v4)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<2, 2, T>& m)
: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<3, 3, T>& m)
: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 0), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<2, 3, T>& m)
: value{col_type(m[0], 0), col_type(m[1], 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<3, 2, T>& m)
: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(m[2], 1, 0), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<2, 4, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<4, 2, T>& m)
: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<3, 4, T>& m)
: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0, 0, 0, 1)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<4, 4, T>::mat(const mat<4, 3, T>& m)
: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 0), col_type(m[3], 1)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator=(const mat<4, 4, U>& m)
{
    this->value[0] = m[0];
    this->value[1] = m[1];
    this->value[2] = m[2];
    this->value[3] = m[3];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator+=(U s)
{
    this->value[0] += s;
    this->value[1] += s;
    this->value[2] += s;
    this->value[3] += s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator+=(const mat<4, 4, U>& m)
{
    this->value[0] += m[0];
    this->value[1] += m[1];
    this->value[2] += m[2];
    this->value[3] += m[3];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator-=(U s)
{
    this->value[0] -= s;
    this->value[1] -= s;
    this->value[2] -= s;
    this->value[3] -= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator-=(const mat<4, 4, U>& m)
{
    this->value[0] -= m[0];
    this->value[1] -= m[1];
    this->value[2] -= m[2];
    this->value[3] -= m[3];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator*=(U s)
{
    this->value[0] *= s;
    this->value[1] *= s;
    this->value[2] *= s;
    this->value[3] *= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator*=(const mat<4, 4, U>& m)
{
    return (*this = *this * m);
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator/=(U s)
{
    this->value[0] /= s;
    this->value[1] /= s;
    this->value[2] /= s;
    this->value[3] /= s;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator/=(const mat<4, 4, U>& m)
{
    return *this *= Inverse(m);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator++()
{
    ++this->value[0];
    ++this->value[1];
    ++this->value[2];
    ++this->value[3];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T>& mat<4, 4, T>::operator--()
{
    --this->value[0];
    --this->value[1];
    --this->value[2];
    --this->value[3];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> mat<4, 4, T>::operator++(i32)
{
    mat<4, 4, T> res(*this);
    ++*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> mat<4, 4, T>::operator--(i32)
{
    mat<4, 4, T> res(*this);
    --*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator+(const mat<4, 4, T>& m)
{
    return m;
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator-(const mat<4, 4, T>& m)
{
    return mat<4, 4, T>(-m[0], -m[1], -m[2], -m[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator+(const mat<4, 4, T>& m, T scalar)
{
    return mat<4, 4, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar, m[3] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator+(T scalar, const mat<4, 4, T>& m)
{
    return mat<4, 4, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar, m[3] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator+(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    return mat<4, 4, T>(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2], m1[3] + m2[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator-(const mat<4, 4, T>& m, T scalar)
{
    return mat<4, 4, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar, m[3] - scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator-(T scalar, const mat<4, 4, T>& m)
{
    return mat<4, 4, T>(scalar - m[0], scalar - m[1], scalar - m[2], scalar - m[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator-(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    return mat<4, 4, T>(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2], m1[3] - m2[3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator*(const mat<4, 4, T>& m, T scalar)
{
    return mat<4, 4, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator*(T scalar, const mat<4, 4, T>& m)
{
    return mat<4, 4, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
}

template<typename T>
NOVA_FUNC constexpr typename mat<4, 4, T>::col_type operator*(const mat<4, 4, T>& m,
                                                              const typename mat<4, 4, T>::row_type& v)
{
    const auto& Mov0(v[0]);
    const auto& Mov1(v[1]);
    const auto& Mul0 = m[0] * Mov0;
    const auto& Mul1 = m[1] * Mov1;
    const auto& Add0 = Mul0 + Mul1;
    const auto& Mov2(v[2]);
    const auto& Mov3(v[3]);
    const auto& Mul2 = m[2] * Mov2;
    const auto& Mul3 = m[3] * Mov3;
    const auto& Add1 = Mul2 + Mul3;
    const auto& Add2 = Add0 + Add1;

    return Add2;
}

template<typename T>
NOVA_FUNC constexpr typename mat<4, 4, T>::row_type operator*(const typename mat<4, 4, T>::col_type& v,
                                                              const mat<4, 4, T>& m)
{
    return
        typename mat<4, 4, T>::row_type(nova::Dot(m[0], v), nova::Dot(m[1], v), nova::Dot(m[2], v), nova::Dot(m[3], v));
}

template<typename T> NOVA_FUNC constexpr mat<2, 4, T> operator*(const mat<4, 4, T>& m1, const mat<2, 4, T>& m2)
{
    return mat<2, 4, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
                        m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
                        m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
                        m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
                        m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 4, T> operator*(const mat<4, 4, T>& m1, const mat<3, 4, T>& m2)
{
    return mat<3, 4, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
                        m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
                        m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
                        m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
                        m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
                        m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
                        m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator*(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    const auto& a0 = m1[0];
    const auto& a1 = m1[1];
    const auto& a2 = m1[2];
    const auto& a3 = m1[3];

    const auto& b0 = m2[0];
    const auto& b1 = m2[1];
    const auto& b2 = m2[2];
    const auto& b3 = m2[3];

    mat<4, 4, T> res;

    typename mat<4, 4, T>::col_type tmp;
    tmp     = a0 * b0.x;
    tmp    += a1 * b0.y;
    tmp    += a2 * b0.z;
    tmp    += a3 * b0.w;
    res[0]  = tmp;
    tmp     = a0 * b1.x;
    tmp    += a1 * b1.y;
    tmp    += a2 * b1.z;
    tmp    += a3 * b1.w;
    res[1]  = tmp;
    tmp     = a0 * b2.x;
    tmp    += a1 * b2.y;
    tmp    += a2 * b2.z;
    tmp    += a3 * b2.w;
    res[2]  = tmp;
    tmp     = a0 * b3.x;
    tmp    += a1 * b3.y;
    tmp    += a2 * b3.z;
    tmp    += a3 * b3.w;
    res[3]  = tmp;

    return res;
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator/(const mat<4, 4, T>& m, T scalar)
{
    return mat<4, 4, T>(m[0] / scalar, m[1] / scalar, m[2] / scalar, m[3] / scalar);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator/(T scalar, const mat<4, 4, T>& m)
{
    return mat<4, 4, T>(scalar / m[0], scalar / m[1], scalar / m[2], scalar / m[3]);
}

template<typename T>
NOVA_FUNC constexpr typename mat<4, 4, T>::col_type operator/(const mat<4, 4, T>& m,
                                                              const typename mat<4, 4, T>::row_type& v)
{
    return Inverse(m) * v;
}

template<typename T>
NOVA_FUNC constexpr typename mat<4, 4, T>::row_type operator/(const typename mat<4, 4, T>::col_type& v,
                                                              const mat<4, 4, T>& m)
{
    return v * Inverse(m);
}

template<typename T> NOVA_FUNC constexpr mat<4, 4, T> operator/(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    mat<4, 4, T> m1_copy(m1);
    return m1_copy /= m2;
}

template<typename T> NOVA_FUNC constexpr bool operator==(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
}
} //namespace nova
