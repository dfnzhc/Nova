/**
 * @File Matrix2x2.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/31
 * @Brief 
 */

#pragma once

#include "../Math.hpp"
#include "../Vector/Vector2.hpp"
#include "./MatrixType.hpp"
#include "./MatrixCommon.hpp"

namespace nova {

template<typename T> struct mat<2, 2, T>
{
    using col_type       = vec2_t<T>;
    using row_type       = vec2_t<T>;
    using mat_type       = mat<2, 2, T>;
    using transpose_type = mat<2, 2, T>;
    using value_type     = T;

private:
    col_type value[2];

public:
    NOVA_FUNC_DECL constexpr mat() = default;

    NOVA_FUNC_DECL constexpr explicit mat(T scalar);
    NOVA_FUNC_DECL constexpr mat(const T& x0, const T& y0, const T& x1, const T& y1);
    NOVA_FUNC_DECL constexpr mat(const col_type& v0, const col_type& v1);

    template<typename U, typename V, typename M, typename N>
    NOVA_FUNC_DECL constexpr mat(const U& x1, const V& y1, const M& x2, const N& y2);

    template<typename U, typename V> NOVA_FUNC_DECL constexpr mat(const vec2_t<U>& v1, const vec2_t<V>& v2);

    template<typename U> NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 2, U>& m);

    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<2, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<3, 4, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 2, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 3, T>& m);
    NOVA_FUNC_DECL constexpr explicit mat(const mat<4, 4, T>& m);

    // clang-format off
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator=(const mat<2, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator+=(const mat<2, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator-=(const mat<2, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator*=(const mat<2, 2, U>& m);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator/=(const mat<2, 2, U>& m);

    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator+=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator-=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator*=(U s);
    template<typename U> NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator/=(U s);
    // clang-format on

    NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator++();
    NOVA_FUNC_DECL constexpr mat<2, 2, T>& operator--();
    NOVA_FUNC_DECL constexpr mat<2, 2, T> operator++(i32);
    NOVA_FUNC_DECL constexpr mat<2, 2, T> operator--(i32);

    // clang-format off
    NOVA_FUNC constexpr       value_type& data(i32 r, i32 c)       noexcept { return this->value[c][r]; }
    NOVA_FUNC constexpr const value_type& data(i32 r, i32 c) const noexcept { return this->value[c][r]; }

    NOVA_FUNC constexpr       col_type& operator[](i32 index)       noexcept { return this->value[index]; }
    NOVA_FUNC constexpr const col_type& operator[](i32 index) const noexcept { return this->value[index]; }

    NOVA_FUNC static constexpr i32 row() { return 2; }
    NOVA_FUNC static constexpr i32 col() { return 2; }

    // clang-format on
};

// clang-format off
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator+(const mat<2, 2, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator-(const mat<2, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator+(const mat<2, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator+(T scalar, const mat<2, 2, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator+(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator-(const mat<2, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator-(T scalar, const mat<2, 2, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator-(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator*(const mat<2, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator*(T scalar, const mat<2, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<2, 2, T>::col_type operator*(const mat<2, 2, T>& m, const typename mat<2, 2, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<2, 2, T>::row_type operator*(const typename mat<2, 2, T>::col_type& v, const mat<2, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator*(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<3, 2, T> operator*(const mat<2, 2, T>& m1, const mat<3, 2, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr mat<4, 2, T> operator*(const mat<2, 2, T>& m1, const mat<4, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator/(const mat<2, 2, T>& m, T scalar);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator/(T scalar, const mat<2, 2, T>& m);
template<typename T> NOVA_FUNC_DECL constexpr mat<2, 2, T> operator/(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2);

template<typename T> NOVA_FUNC_DECL constexpr typename mat<2, 2, T>::col_type operator/(const mat<2, 2, T>& m, const typename mat<2, 2, T>::row_type& v);
template<typename T> NOVA_FUNC_DECL constexpr typename mat<2, 2, T>::row_type operator/(const typename mat<2, 2, T>::col_type& v, const mat<2, 2, T>& m);

template<typename T> NOVA_FUNC_DECL constexpr bool operator==(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2);
template<typename T> NOVA_FUNC_DECL constexpr bool operator!=(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2);
// clang-format on

} //namespace nova

namespace nova {

template<typename T> NOVA_FUNC constexpr mat<2, 2, T>::mat(T scalar) : value{col_type(scalar, 0), col_type(0, scalar)}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const T& x0, const T& y0, const T& x1, const T& y1)
: value{col_type(x0, y0), col_type(x1, y1)}
{
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T>::mat(const col_type& v0, const col_type& v1) : value{v0, v1}
{
}

template<typename T>
template<typename X1, typename Y1, typename X2, typename Y2>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const X1& x1, const Y1& y1, const X2& x2, const Y2& y2)
: value{col_type(cast_to<T>(x1), value_type(y1)), col_type(cast_to<T>(x2), value_type(y2))}
{
}

template<typename T>
template<typename V1, typename V2>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const vec2_t<V1>& v1, const vec2_t<V2>& v2) : value{col_type(v1), col_type(v2)}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<2, 2, U>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<3, 3, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<4, 4, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<2, 3, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<3, 2, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<2, 4, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<4, 2, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<3, 4, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
NOVA_FUNC constexpr mat<2, 2, T>::mat(const mat<4, 3, T>& m) : value{col_type(m[0]), col_type(m[1])}
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator=(const mat<2, 2, U>& m)
{
    this->value[0] = m[0];
    this->value[1] = m[1];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator+=(U scalar)
{
    this->value[0] += scalar;
    this->value[1] += scalar;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator+=(const mat<2, 2, U>& m)
{
    this->value[0] += m[0];
    this->value[1] += m[1];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator-=(U scalar)
{
    this->value[0] -= scalar;
    this->value[1] -= scalar;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator-=(const mat<2, 2, U>& m)
{
    this->value[0] -= m[0];
    this->value[1] -= m[1];
    return *this;
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator*=(U scalar)
{
    this->value[0] *= scalar;
    this->value[1] *= scalar;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator*=(const mat<2, 2, U>& m)
{
    return (*this = *this * m);
}

template<typename T> template<typename U> NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator/=(U scalar)
{
    this->value[0] /= scalar;
    this->value[1] /= scalar;
    return *this;
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator/=(const mat<2, 2, U>& m)
{
    return *this *= Inverse(m);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator++()
{
    ++this->value[0];
    ++this->value[1];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T>& mat<2, 2, T>::operator--()
{
    --this->value[0];
    --this->value[1];
    return *this;
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> mat<2, 2, T>::operator++(i32)
{
    mat<2, 2, T> res(*this);
    ++*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> mat<2, 2, T>::operator--(i32)
{
    mat<2, 2, T> res(*this);
    --*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator+(const mat<2, 2, T>& m)
{
    return m;
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator-(const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(-m[0], -m[1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator+(const mat<2, 2, T>& m, T scalar)
{
    return mat<2, 2, T>(m[0] + scalar, m[1] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator+(T scalar, const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(m[0] + scalar, m[1] + scalar);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator+(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2)
{
    return mat<2, 2, T>(m1[0] + m2[0], m1[1] + m2[1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator-(const mat<2, 2, T>& m, T scalar)
{
    return mat<2, 2, T>(m[0] - scalar, m[1] - scalar);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator-(T scalar, const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(scalar - m[0], scalar - m[1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator-(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2)
{
    return mat<2, 2, T>(m1[0] - m2[0], m1[1] - m2[1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator*(const mat<2, 2, T>& m, T scalar)
{
    return mat<2, 2, T>(m[0] * scalar, m[1] * scalar);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator*(T scalar, const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(m[0] * scalar, m[1] * scalar);
}

template<typename T>
NOVA_FUNC constexpr typename mat<2, 2, T>::col_type operator*(const mat<2, 2, T>& m,
                                                              const typename mat<2, 2, T>::row_type& v)
{
    return vec2_t<T>(m[0][0] * v.x + m[1][0] * v.y, m[0][1] * v.x + m[1][1] * v.y);
}

template<typename T>
NOVA_FUNC constexpr typename mat<2, 2, T>::row_type operator*(const typename mat<2, 2, T>::col_type& v,
                                                              const mat<2, 2, T>& m)
{
    return vec2_t<T>(v.x * m[0][0] + v.y * m[0][1], v.x * m[1][0] + v.y * m[1][1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator*(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2)
{
    return mat<2, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1]);
}

template<typename T> NOVA_FUNC constexpr mat<3, 2, T> operator*(const mat<2, 2, T>& m1, const mat<3, 2, T>& m2)
{
    return mat<3, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1]);
}

template<typename T> NOVA_FUNC constexpr mat<4, 2, T> operator*(const mat<2, 2, T>& m1, const mat<4, 2, T>& m2)
{
    return mat<4, 2, T>(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
                        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
                        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
                        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
                        m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
                        m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1],
                        m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1],
                        m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1]);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator/(const mat<2, 2, T>& m, T scalar)
{
    return mat<2, 2, T>(m[0] / scalar, m[1] / scalar);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator/(T scalar, const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(scalar / m[0], scalar / m[1]);
}

template<typename T>
NOVA_FUNC constexpr typename mat<2, 2, T>::col_type operator/(const mat<2, 2, T>& m,
                                                              const typename mat<2, 2, T>::row_type& v)
{
    return Inverse(m) * v;
}

template<typename T>
NOVA_FUNC constexpr typename mat<2, 2, T>::row_type operator/(const typename mat<2, 2, T>::col_type& v,
                                                              const mat<2, 2, T>& m)
{
    return v * Inverse(m);
}

template<typename T> NOVA_FUNC constexpr mat<2, 2, T> operator/(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2)
{
    mat<2, 2, T> m1_copy(m1);
    return m1_copy /= m2;
}

template<typename T> NOVA_FUNC constexpr bool operator==(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2)
{
    return (m1[0] == m2[0]) && (m1[1] == m2[1]);
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2)
{
    return (m1[0] != m2[0]) || (m1[1] != m2[1]);
}
} //namespace nova
