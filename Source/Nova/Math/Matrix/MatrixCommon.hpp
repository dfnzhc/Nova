/**
 * @File MatrixCommon.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/14
 * @Brief This file is part of Nova.
 */

#pragma once

#include "../Bit.hpp"
#include "../Vector.hpp"
#include "./Matrix2x2.hpp"
#include "./Matrix2x3.hpp"
#include "./Matrix2x4.hpp"
#include "./Matrix3x2.hpp"
#include "./Matrix3x3.hpp"
#include "./Matrix3x4.hpp"
#include "./Matrix4x2.hpp"
#include "./Matrix4x3.hpp"
#include "./Matrix4x4.hpp"

namespace nova {

// -------------------------
// 元素比较
// -------------------------
template<i32 C, i32 R, typename T> NOVA_FUNC constexpr bool4 cwEqual(const mat<C, R, T>& a, const mat<C, R, T>& b)
{
    bool4 res(true);
    for (i32 i = 0; i < C; ++i)
        res[i] = Equal(a[i], b[i]);

    return res;
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool4 cwEqual(const mat<C, R, T>& a, const mat<C, R, T>& b, T epsilon)
{
    bool4 res(true);
    for (i32 i = 0; i < C; ++i)
        res[i] = Equal(a[i], b[i], epsilon);

    return res;
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool4 cwEqual(const mat<C, R, T>& a, const mat<C, R, T>& b, const vec<C, T>& epsilon)
{
    bool4 res(true);
    for (i32 i = 0; i < C; ++i)
        res[i] = Equal(a[i], b[i], epsilon[i]);

    return res;
}

template<i32 C, i32 R, typename T> NOVA_FUNC constexpr bool4 cwNotEqual(const mat<C, R, T>& a, const mat<C, R, T>& b)
{
    return not cwEqual(a, b);
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool4 cwNotEqual(const mat<C, R, T>& a, const mat<C, R, T>& b, T epsilon)
{
    return not cwEqual(a, b, epsilon);
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool4 cwNotEqual(const mat<C, R, T>& a, const mat<C, R, T>& b, const vec<C, T>& epsilon)
{
    return not Equal(a, b, epsilon);
}

template<i32 C, i32 R, typename T> NOVA_FUNC constexpr bool Equal(const mat<C, R, T>& a, const mat<C, R, T>& b)
{
    return all(cwEqual(a, b));
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool Equal(const mat<C, R, T>& a, const mat<C, R, T>& b, T epsilon)
{
    return all(cwEqual(a, b, epsilon));
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool Equal(const mat<C, R, T>& a, const mat<C, R, T>& b, const vec<C, T>& epsilon)
{
    return all(cwEqual(a, b, epsilon));
}

template<i32 C, i32 R, typename T> NOVA_FUNC constexpr bool NotEqual(const mat<C, R, T>& a, const mat<C, R, T>& b)
{
    return not Equal(a, b);
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool NotEqual(const mat<C, R, T>& a, const mat<C, R, T>& b, T epsilon)
{
    return not Equal(a, b, epsilon);
}

template<i32 C, i32 R, typename T>
NOVA_FUNC constexpr bool NotEqual(const mat<C, R, T>& a, const mat<C, R, T>& b, const vec<C, T>& epsilon)
{
    return not Equal(a, b, epsilon);
}

// -------------------------
// 元素访问
// -------------------------

template<typename M> NOVA_FUNC typename M::row_type GetRow(const M& m, i32 index)
{
    NOVA_CHECK(index >= 0 && index < m[0].dim());

    typename M::row_type res(0);
    for (i32 i = 0; i < m.col(); ++i)
        res[i] = m[i][index];
    return res;
}

template<typename M> NOVA_FUNC M GetRow(const M& m, i32 index, const typename M::row_type& x)
{
    NOVA_CHECK(index >= 0 && index < m[0].dim());

    M res = m;
    for (i32 i = 0; i < m.col(); ++i)
        res[i][index] = x[i];
    return res;
}

template<typename M> NOVA_FUNC typename M::col_type GetColumn(const M& m, i32 index)
{
    NOVA_CHECK(index >= 0 && index < m.col());

    return m[index];
}

template<typename M> NOVA_FUNC M GetColumn(const M& m, i32 index, const typename M::col_type& x)
{
    NOVA_CHECK(index >= 0 && index < m.col());

    M res      = m;
    res[index] = x;
    return res;
}

template<i32 N, typename T> NOVA_FUNC T Trace(const mat<N, N, T>& m)
{
    auto res = Zero<T>();

    for (int i = 0; i < m.col(); ++i)
        res += m.data(i, i);

    return res;
}

// -------------------------
// 逐元素操作
// -------------------------

template<i32 C, i32 R, typename T> NOVA_FUNC mat<C, R, T> CompMult(const mat<C, R, T>& x, const mat<C, R, T>& y)
{
    mat<C, R, T> res(1);
    for (i32 i = 0; i < res.col(); ++i)
        res[i] = x[i] * y[i];
    return res;
}

// -------------------------
// 向量外积
// -------------------------

namespace internal {

template<i32 C, i32 R, typename T> struct OuterProduct
{ };

template<typename T> struct OuterProduct<2, 2, T>
{
    using type = mat<2, 2, T>;
};

template<typename T> struct OuterProduct<2, 3, T>
{
    using type = mat<3, 2, T>;
};

template<typename T> struct OuterProduct<2, 4, T>
{
    using type = mat<4, 2, T>;
};

template<typename T> struct OuterProduct<3, 2, T>
{
    using type = mat<2, 3, T>;
};

template<typename T> struct OuterProduct<3, 3, T>
{
    using type = mat<3, 3, T>;
};

template<typename T> struct OuterProduct<3, 4, T>
{
    using type = mat<4, 3, T>;
};

template<typename T> struct OuterProduct<4, 2, T>
{
    using type = mat<2, 4, T>;
};

template<typename T> struct OuterProduct<4, 3, T>
{
    using type = mat<3, 4, T>;
};

template<typename T> struct OuterProduct<4, 4, T>
{
    using type = mat<4, 4, T>;
};

} //namespace internal

template<i32 C, i32 R, typename T> using OuterProduct_t = internal::OuterProduct<C, R, T>::type;

template<i32 C, i32 R, typename T>
NOVA_FUNC OuterProduct_t<C, R, T> OuterProduct(const vec<C, T>& c, const vec<R, T>& r)
{
    OuterProduct_t<C, R, T> m(0);
    for (i32 i = 0; i < m.col(); ++i)
        m[i] = c * r[i];
    return m;
}

// -------------------------
// 矩阵操作
// -------------------------

namespace internal {

template<i32 C, i32 R, typename T> struct ComputeTranspose
{ };

template<typename T> struct ComputeTranspose<2, 2, T>
{
    NOVA_FUNC static mat<2, 2, T> call(const mat<2, 2, T>& m)
    {
        mat<2, 2, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        return res;
    }
};

template<typename T> struct ComputeTranspose<2, 3, T>
{
    NOVA_FUNC static mat<3, 2, T> call(const mat<2, 3, T>& m)
    {
        mat<3, 2, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[2][0] = m[0][2];
        res[2][1] = m[1][2];
        return res;
    }
};

template<typename T> struct ComputeTranspose<2, 4, T>
{
    NOVA_FUNC static mat<4, 2, T> call(const mat<2, 4, T>& m)
    {
        mat<4, 2, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[2][0] = m[0][2];
        res[2][1] = m[1][2];
        res[3][0] = m[0][3];
        res[3][1] = m[1][3];
        return res;
    }
};

template<typename T> struct ComputeTranspose<3, 2, T>
{
    NOVA_FUNC static mat<2, 3, T> call(const mat<3, 2, T>& m)
    {
        mat<2, 3, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[0][2] = m[2][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[1][2] = m[2][1];
        return res;
    }
};

template<typename T> struct ComputeTranspose<3, 3, T>
{
    NOVA_FUNC static mat<3, 3, T> call(const mat<3, 3, T>& m)
    {
        mat<3, 3, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[0][2] = m[2][0];

        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[1][2] = m[2][1];

        res[2][0] = m[0][2];
        res[2][1] = m[1][2];
        res[2][2] = m[2][2];
        return res;
    }
};

template<typename T> struct ComputeTranspose<3, 4, T>
{
    NOVA_FUNC static mat<4, 3, T> call(const mat<3, 4, T>& m)
    {
        mat<4, 3, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[0][2] = m[2][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[1][2] = m[2][1];
        res[2][0] = m[0][2];
        res[2][1] = m[1][2];
        res[2][2] = m[2][2];
        res[3][0] = m[0][3];
        res[3][1] = m[1][3];
        res[3][2] = m[2][3];
        return res;
    }
};

template<typename T> struct ComputeTranspose<4, 2, T>
{
    NOVA_FUNC static mat<2, 4, T> call(const mat<4, 2, T>& m)
    {
        mat<2, 4, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[0][2] = m[2][0];
        res[0][3] = m[3][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[1][2] = m[2][1];
        res[1][3] = m[3][1];
        return res;
    }
};

template<typename T> struct ComputeTranspose<4, 3, T>
{
    NOVA_FUNC static mat<3, 4, T> call(const mat<4, 3, T>& m)
    {
        mat<3, 4, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[0][2] = m[2][0];
        res[0][3] = m[3][0];
        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[1][2] = m[2][1];
        res[1][3] = m[3][1];
        res[2][0] = m[0][2];
        res[2][1] = m[1][2];
        res[2][2] = m[2][2];
        res[2][3] = m[3][2];
        return res;
    }
};

template<typename T> struct ComputeTranspose<4, 4, T>
{
    NOVA_FUNC static mat<4, 4, T> call(const mat<4, 4, T>& m)
    {
        mat<4, 4, T> res(1);
        res[0][0] = m[0][0];
        res[0][1] = m[1][0];
        res[0][2] = m[2][0];
        res[0][3] = m[3][0];

        res[1][0] = m[0][1];
        res[1][1] = m[1][1];
        res[1][2] = m[2][1];
        res[1][3] = m[3][1];

        res[2][0] = m[0][2];
        res[2][1] = m[1][2];
        res[2][2] = m[2][2];
        res[2][3] = m[3][2];

        res[3][0] = m[0][3];
        res[3][1] = m[1][3];
        res[3][2] = m[2][3];
        res[3][3] = m[3][3];
        return res;
    }
};

template<i32 C, i32 R, typename T> struct ComputeDeterminant
{ };

template<typename T> struct ComputeDeterminant<2, 2, T>
{
    NOVA_FUNC static T call(const mat<2, 2, T>& m) { return m[0][0] * m[1][1] - m[1][0] * m[0][1]; }
};

template<typename T> struct ComputeDeterminant<3, 3, T>
{
    NOVA_FUNC static T call(const mat<3, 3, T>& m)
    {
        return +m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) +
               m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    }
};

template<typename T> struct ComputeDeterminant<4, 4, T>
{
    NOVA_FUNC static T call(const mat<4, 4, T>& m)
    {
        T factor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
        T factor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
        T factor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
        T factor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
        T factor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
        T factor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

        vec4_t<T> coef(+(m[1][1] * factor00 - m[1][2] * factor01 + m[1][3] * factor02),
                       -(m[1][0] * factor00 - m[1][2] * factor03 + m[1][3] * factor04),
                       +(m[1][0] * factor01 - m[1][1] * factor03 + m[1][3] * factor05),
                       -(m[1][0] * factor02 - m[1][1] * factor04 + m[1][2] * factor05));

        return m[0][0] * coef[0] + m[0][1] * coef[1] + m[0][2] * coef[2] + m[0][3] * coef[3];
    }
};

template<i32 C, i32 R, typename T> struct ComputeInverse
{ };

template<typename T> struct ComputeInverse<2, 2, T>
{
    NOVA_FUNC static mat<2, 2, T> call(const mat<2, 2, T>& m)
    {
        T one_over_det = One<T>() / (+m[0][0] * m[1][1] - m[1][0] * m[0][1]);

        mat<2, 2, T> inv(
            +m[1][1] * one_over_det, -m[0][1] * one_over_det, -m[1][0] * one_over_det, +m[0][0] * one_over_det);

        return inv;
    }
};

template<typename T> struct ComputeInverse<3, 3, T>
{
    NOVA_FUNC static mat<3, 3, T> call(const mat<3, 3, T>& m)
    {
        T one_over_det = One<T>() / (+m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
                                     m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) +
                                     m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]));

        mat<3, 3, T> inv;
        inv[0][0] = +(m[1][1] * m[2][2] - m[2][1] * m[1][2]);
        inv[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
        inv[2][0] = +(m[1][0] * m[2][1] - m[2][0] * m[1][1]);
        inv[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
        inv[1][1] = +(m[0][0] * m[2][2] - m[2][0] * m[0][2]);
        inv[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
        inv[0][2] = +(m[0][1] * m[1][2] - m[1][1] * m[0][2]);
        inv[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
        inv[2][2] = +(m[0][0] * m[1][1] - m[1][0] * m[0][1]);

        inv *= one_over_det;
        return inv;
    }
};

template<typename T> struct ComputeInverse<4, 4, T>
{
    NOVA_FUNC static mat<4, 4, T> call(const mat<4, 4, T>& m)
    {
        T coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
        T coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
        T coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

        T coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
        T coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
        T coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

        T coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
        T coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
        T coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

        T coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
        T coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
        T coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

        T coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
        T coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
        T coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

        T coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
        T coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
        T coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

        vec4_t<T> fac0(coef00, coef00, coef02, coef03);
        vec4_t<T> fac1(coef04, coef04, coef06, coef07);
        vec4_t<T> fac2(coef08, coef08, coef10, coef11);
        vec4_t<T> fac3(coef12, coef12, coef14, coef15);
        vec4_t<T> fac4(coef16, coef16, coef18, coef19);
        vec4_t<T> fac5(coef20, coef20, coef22, coef23);

        vec4_t<T> v0(m[1][0], m[0][0], m[0][0], m[0][0]);
        vec4_t<T> v1(m[1][1], m[0][1], m[0][1], m[0][1]);
        vec4_t<T> v2(m[1][2], m[0][2], m[0][2], m[0][2]);
        vec4_t<T> v3(m[1][3], m[0][3], m[0][3], m[0][3]);

        vec4_t<T> inv0(v1 * fac0 - v2 * fac1 + v3 * fac2);
        vec4_t<T> inv1(v0 * fac0 - v2 * fac3 + v3 * fac4);
        vec4_t<T> inv2(v0 * fac1 - v1 * fac3 + v3 * fac5);
        vec4_t<T> inv3(v0 * fac2 - v1 * fac4 + v2 * fac5);

        vec4_t<T> signA(+1, -1, +1, -1);
        vec4_t<T> signB(-1, +1, -1, +1);
        mat<4, 4, T> inv(inv0 * signA, inv1 * signB, inv2 * signA, inv3 * signB);

        vec4_t<T> row0(inv[0][0], inv[1][0], inv[2][0], inv[3][0]);

        vec4_t<T> dot0(m[0] * row0);
        T dot1 = (dot0.x + dot0.y) + (dot0.z + dot0.w);

        T one_over_det = One<T>() / dot1;

        return inv * one_over_det;
    }
};

// clang-format off
template<template<i32 C, i32 R, typename T> class mat, i32 C, i32 R, typename Ret, typename T>
struct MatrixFuncUni
{
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 2, 2, Ret, T>
{
  NOVA_FUNC constexpr static mat<2, 2, T> call(Ret (*Func)(T x), const mat<2, 2, T>& x)
  {
      return mat<2, 2, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[1][0]), Func(x[1][1]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 2, 3, Ret, T>
{
  NOVA_FUNC constexpr static mat<2, 3, T> call(Ret (*Func)(T x), const mat<2, 3, T>& x)
  {
      return mat<2, 3, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[0][2]), Func(x[1][0]), Func(x[1][1]), Func(x[1][2]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 2, 4, Ret, T>
{
  NOVA_FUNC constexpr static mat<2, 4, T> call(Ret (*Func)(T x), const mat<2, 4, T>& x)
  {
      return mat<2, 4, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[0][2]), Func(x[0][3]),
                           Func(x[1][0]), Func(x[1][1]), Func(x[1][2]), Func(x[1][3]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 3, 2, Ret, T>
{
  NOVA_FUNC constexpr static mat<3, 2, T> call(Ret (*Func)(T x), const mat<3, 2, T>& x)
  {
      return mat<3, 2, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[1][0]), Func(x[1][1]), Func(x[2][0]), Func(x[2][1]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 3, 3, Ret, T>
{
  NOVA_FUNC constexpr static mat<3, 3, T> call(Ret (*Func)(T x), const mat<3, 3, T>& x)
  {
      return mat<3, 3, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[0][2]),
                           Func(x[1][0]), Func(x[1][1]), Func(x[1][2]),
                           Func(x[2][0]), Func(x[2][1]), Func(x[2][2]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 3, 4, Ret, T>
{
  NOVA_FUNC constexpr static mat<3, 4, T> call(Ret (*Func)(T x), const mat<3, 4, T>& x)
  {
      return mat<3, 4, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[0][2]), Func(x[0][3]),
                           Func(x[1][0]), Func(x[1][1]), Func(x[1][2]), Func(x[1][3]),
                           Func(x[2][0]), Func(x[2][1]), Func(x[2][2]), Func(x[2][3]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 4, 2, Ret, T>
{
  NOVA_FUNC constexpr static mat<4, 2, T> call(Ret (*Func)(T x), const mat<4, 2, T>& x)
  {
      return mat<4, 2, Ret>(Func(x[0][0]), Func(x[0][1]),
                           Func(x[1][0]), Func(x[1][1]),
                           Func(x[2][0]), Func(x[2][1]),
                           Func(x[3][0]), Func(x[3][1]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 4, 3, Ret, T>
{
  NOVA_FUNC constexpr static mat<4, 3, T> call(Ret (*Func)(T x), const mat<4, 3, T>& x)
  {
      return mat<4, 3, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[0][2]),
                           Func(x[1][0]), Func(x[1][1]), Func(x[1][2]),
                           Func(x[2][0]), Func(x[2][1]), Func(x[2][2]),
                           Func(x[3][0]), Func(x[3][1]), Func(x[3][2]));
  }
};

template<template<i32 C, i32 R, typename T> class mat, typename Ret, typename T>
struct MatrixFuncUni<mat, 4, 4, Ret, T>
{
  NOVA_FUNC constexpr static mat<4, 4, T> call(Ret (*Func)(T x), const mat<4, 4, T>& x)
  {
      return mat<4, 4, Ret>(Func(x[0][0]), Func(x[0][1]), Func(x[0][2]), Func(x[0][3]),
                           Func(x[1][0]), Func(x[1][1]), Func(x[1][2]), Func(x[1][3]),
                           Func(x[2][0]), Func(x[2][1]), Func(x[2][2]), Func(x[2][3]),
                           Func(x[3][0]), Func(x[3][1]), Func(x[3][2]), Func(x[3][3]));
  }
};

// clang-format on

} //namespace internal

template<i32 C, i32 R, typename T> NOVA_FUNC mat<2, 2, T> Transpose(const mat<C, R, T>& m)
{
    return internal::ComputeTranspose<C, R, T>::call(m);
}

template<i32 C, i32 R, typename T> NOVA_FUNC T Determinant(const mat<C, R, T>& m)
{
    return internal::ComputeDeterminant<C, R, T>::call(m);
}

template<i32 C, i32 R, typename T> NOVA_FUNC mat<C, R, T> Inverse(const mat<C, R, T>& m)
{
    return internal::ComputeInverse<C, R, T>::call(m);
}

template<i32 C, i32 R, typename T, typename U>
NOVA_FUNC mat<C, R, T> Mix(const mat<C, R, T>& x, const mat<C, R, T>& y, const mat<C, R, U>& a)
{
    return mat<C, R, U>(x) * (cast_to<U>(1) - a) + mat<C, R, U>(y) * a;
}

template<i32 C, i32 R, typename T, typename U>
NOVA_FUNC mat<C, R, T> Mix(const mat<C, R, T>& x, const mat<C, R, T>& y, U a)
{
    return CompMult(mat<C, R, U>(x), cast_to<U>(1) - a) + CompMult(mat<C, R, U>(y), a);
}

template<i32 C, i32 R, typename T> NOVA_FUNC constexpr mat<C, R, T> Abs(const mat<C, R, T>& x)
{
    return internal::MatrixFuncUni<mat, C, R, T, T>::call(Abs, x);
}

template<typename T> NOVA_FUNC mat<3, 3, T> AffineInverse(const mat<3, 3, T>& m)
{
    const mat<2, 2, T> inv = Inverse(mat<2, 2, T>(m));
    return mat<3, 3, T>(
        vec3_t<T>(inv[0], Zero<T>()), vec3_t<T>(inv[1], Zero<T>()), vec3_t<T>(-inv * vec2_t<T>(m[2]), One<T>()));
}

template<typename T> NOVA_FUNC mat<4, 4, T> AffineInverse(const mat<4, 4, T>& m)
{
    const mat<3, 3, T> inv = Inverse(mat<3, 3, T>(m));

    return mat<4, 4, T>(vec4_t<T>(inv[0], Zero<T>()),
                        vec4_t<T>(inv[1], Zero<T>()),
                        vec4_t<T>(inv[2], Zero<T>()),
                        vec4_t<T>(-inv * vec3_t<T>(m[3]), One<T>()));
}

template<i32 C, i32 R, typename T> NOVA_FUNC mat<C, R, T> InverseTranspose(const mat<C, R, T>& m)
{
    return internal::ComputeInverse<C, R, T>::call(internal::ComputeTranspose<C, R, T>::call(m));
}

template<typename T> NOVA_FUNC mat<3, 3, T> Orthonormalize(const mat<3, 3, T>& m)
{
    mat<3, 3, T> r = m;

    r[0] = Normalize(r[0]);

    T d0  = Dot(r[0], r[1]);
    r[1] -= r[0] * d0;
    r[1]  = Normalize(r[1]);

    T d1  = Dot(r[1], r[2]);
    d0    = Dot(r[0], r[2]);
    r[2] -= r[0] * d0 + r[1] * d1;
    r[2]  = Normalize(r[2]);

    return r;
}

template<typename T> NOVA_FUNC vec3_t<T> Orthonormalize(const vec3_t<T>& x, const vec3_t<T>& y)
{
    return Normalize(x - y * Dot(y, x));
}

template<typename T> NOVA_FUNC mat<2, 2, T> RowMajor2(const vec2_t<T>& v1, const vec2_t<T>& v2)
{
    mat<2, 2, T> res;
    res[0][0] = v1.x;
    res[1][0] = v1.y;

    res[0][1] = v2.x;
    res[1][1] = v2.y;
    return res;
}

template<typename T> NOVA_FUNC mat<2, 2, T> RowMajor2(const mat<2, 2, T>& m)
{
    mat<2, 2, T> res;
    res[0][0] = m[0][0];
    res[0][1] = m[1][0];

    res[1][0] = m[0][1];
    res[1][1] = m[1][1];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> RowMajor3(const vec3_t<T>& v1, const vec3_t<T>& v2, const vec3_t<T>& v3)
{
    mat<3, 3, T> res;
    res[0][0] = v1.x;
    res[1][0] = v1.y;
    res[2][0] = v1.z;

    res[0][1] = v2.x;
    res[1][1] = v2.y;
    res[2][1] = v2.z;

    res[0][2] = v3.x;
    res[1][2] = v3.y;
    res[2][2] = v3.z;
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> RowMajor3(const mat<3, 3, T>& m)
{
    mat<3, 3, T> res;
    res[0][0] = m[0][0];
    res[0][1] = m[1][0];
    res[0][2] = m[2][0];

    res[1][0] = m[0][1];
    res[1][1] = m[1][1];
    res[1][2] = m[2][1];

    res[2][0] = m[0][2];
    res[2][1] = m[1][2];
    res[2][2] = m[2][2];
    return res;
}

template<typename T>
NOVA_FUNC mat<4, 4, T> RowMajor4(const vec4_t<T>& v1, const vec4_t<T>& v2, const vec4_t<T>& v3, const vec4_t<T>& v4)
{
    mat<4, 4, T> res;
    res[0][0] = v1.x;
    res[1][0] = v1.y;
    res[2][0] = v1.z;
    res[3][0] = v1.w;

    res[0][1] = v2.x;
    res[1][1] = v2.y;
    res[2][1] = v2.z;
    res[3][1] = v2.w;

    res[0][2] = v3.x;
    res[1][2] = v3.y;
    res[2][2] = v3.z;
    res[3][2] = v3.w;

    res[0][3] = v4.x;
    res[1][3] = v4.y;
    res[2][3] = v4.z;
    res[3][3] = v4.w;
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> RowMajor4(const mat<4, 4, T>& m)
{
    mat<4, 4, T> res;
    res[0][0] = m[0][0];
    res[0][1] = m[1][0];
    res[0][2] = m[2][0];
    res[0][3] = m[3][0];
    res[1][0] = m[0][1];
    res[1][1] = m[1][1];
    res[1][2] = m[2][1];
    res[1][3] = m[3][1];
    res[2][0] = m[0][2];
    res[2][1] = m[1][2];
    res[2][2] = m[2][2];
    res[2][3] = m[3][2];
    res[3][0] = m[0][3];
    res[3][1] = m[1][3];
    res[3][2] = m[2][3];
    res[3][3] = m[3][3];
    return res;
}

template<typename T> NOVA_FUNC mat<2, 2, T> ColMajor2(const vec2_t<T>& v1, const vec2_t<T>& v2)
{
    return mat<2, 2, T>(v1, v2);
}

template<typename T> NOVA_FUNC mat<2, 2, T> ColMajor2(const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(m);
}

template<typename T> NOVA_FUNC mat<3, 3, T> ColMajor3(const vec3_t<T>& v1, const vec3_t<T>& v2, const vec3_t<T>& v3)
{
    return mat<3, 3, T>(v1, v2, v3);
}

template<typename T> NOVA_FUNC mat<3, 3, T> ColMajor3(const mat<3, 3, T>& m)
{
    return mat<3, 3, T>(m);
}

template<typename T>
NOVA_FUNC mat<4, 4, T> ColMajor4(const vec4_t<T>& v1, const vec4_t<T>& v2, const vec4_t<T>& v3, const vec4_t<T>& v4)
{
    return mat<4, 4, T>(v1, v2, v3, v4);
}

template<typename T> NOVA_FUNC mat<4, 4, T> ColMajor4(const mat<4, 4, T>& m)
{
    return mat<4, 4, T>(m);
}

template<typename T> NOVA_FUNC mat<2, 2, T> Diagonal2x2(const vec2_t<T>& v)
{
    mat<2, 2, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    return res;
}

template<typename T> NOVA_FUNC mat<2, 3, T> Diagonal2x3(const vec2_t<T>& v)
{
    mat<2, 3, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    return res;
}

template<typename T> NOVA_FUNC mat<2, 4, T> Diagonal2x4(const vec2_t<T>& v)
{
    mat<2, 4, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 2, T> Diagonal3x2(const vec2_t<T>& v)
{
    mat<3, 2, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 3, T> Diagonal3x3(const vec3_t<T>& v)
{
    mat<3, 3, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    res[2][2] = v[2];
    return res;
}

template<typename T> NOVA_FUNC mat<3, 4, T> Diagonal3x4(const vec3_t<T>& v)
{
    mat<3, 4, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    res[2][2] = v[2];
    return res;
}

template<typename T> NOVA_FUNC mat<4, 4, T> Diagonal4x4(const vec4_t<T>& v)
{
    mat<4, 4, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    res[2][2] = v[2];
    res[3][3] = v[3];
    return res;
}

template<typename T> NOVA_FUNC mat<4, 3, T> Diagonal4x3(const vec3_t<T>& v)
{
    mat<4, 3, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    res[2][2] = v[2];
    return res;
}

template<typename T> NOVA_FUNC mat<4, 2, T> Diagonal4x2(const vec2_t<T>& v)
{
    mat<4, 2, T> res(One<T>());
    res[0][0] = v[0];
    res[1][1] = v[1];
    return res;
}

template<typename T> NOVA_FUNC mat<2, 2, T> Adjugate(const mat<2, 2, T>& m)
{
    return mat<2, 2, T>(+m[1][1], -m[0][1], -m[1][0], +m[0][0]);
}

template<typename T> NOVA_FUNC mat<3, 3, T> Adjugate(const mat<3, 3, T>& m)
{
    const T m00 = Determinant(mat<2, 2, T>(m[1][1], m[2][1], m[1][2], m[2][2]));
    const T m01 = Determinant(mat<2, 2, T>(m[0][1], m[2][1], m[0][2], m[2][2]));
    const T m02 = Determinant(mat<2, 2, T>(m[0][1], m[1][1], m[0][2], m[1][2]));

    const T m10 = Determinant(mat<2, 2, T>(m[1][0], m[2][0], m[1][2], m[2][2]));
    const T m11 = Determinant(mat<2, 2, T>(m[0][0], m[2][0], m[0][2], m[2][2]));
    const T m12 = Determinant(mat<2, 2, T>(m[0][0], m[1][0], m[0][2], m[1][2]));

    const T m20 = Determinant(mat<2, 2, T>(m[1][0], m[2][0], m[1][1], m[2][1]));
    const T m21 = Determinant(mat<2, 2, T>(m[0][0], m[2][0], m[0][1], m[2][1]));
    const T m22 = Determinant(mat<2, 2, T>(m[0][0], m[1][0], m[0][1], m[1][1]));

    return mat<3, 3, T>(+m00, -m01, +m02, -m10, +m11, -m12, +m20, -m21, +m22);
}

template<typename T> NOVA_FUNC mat<4, 4, T> Adjugate(const mat<4, 4, T>& m)
{
    // clang-format off
  const T m00 = Determinant(mat<3, 3, T>(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]));
  const T m01 = Determinant(mat<3, 3, T>(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]));
  const T m02 = Determinant(mat<3, 3, T>(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]));
  const T m03 = Determinant(mat<3, 3, T>(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]));

  const T m10 = Determinant(mat<3, 3, T>(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]));
  const T m11 = Determinant(mat<3, 3, T>(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]));
  const T m12 = Determinant(mat<3, 3, T>(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]));
  const T m13 = Determinant(mat<3, 3, T>(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]));

  const T m20 = Determinant(mat<3, 3, T>(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]));
  const T m21 = Determinant(mat<3, 3, T>(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]));
  const T m22 = Determinant(mat<3, 3, T>(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]));
  const T m23 = Determinant(mat<3, 3, T>(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]));

  const T m30 = Determinant(mat<3, 3, T>(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]));
  const T m31 = Determinant(mat<3, 3, T>(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]));
  const T m32 = Determinant(mat<3, 3, T>(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]));
  const T m33 = Determinant(mat<3, 3, T>(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]));
    // clang-format on

    return mat<4, 4, T>(+m00, -m10, +m20, -m30, -m01, +m11, -m21, +m31, +m02, -m12, +m22, -m32, -m03, +m13, -m23, +m33);
}

template<i32 C, i32 R, typename T> NOVA_FUNC bool isIdentity(const mat<C, R, T>& m, const T& epsilon = Epsilon<T>())
{
    bool res = true;
    for (i32 i = 0; res && i < m.length(); ++i) {
        for (i32 j = 0; res && j < Min(i, m[0].Length()); ++j)
            res = Abs(m[i][j]) <= epsilon;
        if (res && i < m[0].Length())
            res = Abs(m[i][i] - 1) <= epsilon;
        for (i32 j = i + 1; res && j < m[0].Length(); ++j)
            res = Abs(m[i][j]) <= epsilon;
    }
    return res;
}

template<typename T> NOVA_FUNC bool isNormalized(const mat<2, 2, T>& m, const T& epsilon = Epsilon<T>())
{
    bool res(true);
    for (i32 i = 0; res && i < m.length(); ++i)
        res = isNormalized(m[i], epsilon);
    for (i32 i = 0; res && i < m.length(); ++i) {
        typename mat<2, 2, T>::col_type v;
        for (i32 j = 0; j < m.length(); ++j)
            v[j] = m[j][i];
        res = isNormalized(v, epsilon);
    }
    return res;
}

template<typename T> NOVA_FUNC bool isNormalized(const mat<3, 3, T>& m, const T& epsilon = Epsilon<T>())
{
    bool res(true);
    for (i32 i = 0; res && i < m.length(); ++i)
        res = isNormalized(m[i], epsilon);
    for (i32 i = 0; res && i < m.length(); ++i) {
        typename mat<3, 3, T>::col_type v;
        for (i32 j = 0; j < m.length(); ++j)
            v[j] = m[j][i];
        res = isNormalized(v, epsilon);
    }
    return res;
}

template<typename T> NOVA_FUNC bool isNormalized(const mat<4, 4, T>& m, const T& epsilon = Epsilon<T>())
{
    bool res(true);
    for (i32 i = 0; res && i < m.length(); ++i)
        res = isNormalized(m[i], epsilon);
    for (i32 i = 0; res && i < m.length(); ++i) {
        typename mat<4, 4, T>::col_type v;
        for (i32 j = 0; j < m.length(); ++j)
            v[j] = m[j][i];
        res = isNormalized(v, epsilon);
    }
    return res;
}

template<i32 C, i32 R, typename T> NOVA_FUNC bool isOrthogonal(const mat<C, R, T>& m, const T& epsilon = Epsilon<T>())
{
    bool res = true;
    for (i32 i(0); res && i < m.length(); ++i) {
        res = isNormalized(m[i], epsilon);
        for (i32 j(i + 1); res && j < m.length(); ++j)
            res = Abs(Dot(m[i], m[j])) <= epsilon;
    }

    if (res) {
        mat<C, R, T> tmp = Transpose(m);
        for (i32 i(0); res && i < m.length(); ++i) {
            res = isNormalized(tmp[i], epsilon);
            for (i32 j(i + 1); res && j < m.length(); ++j)
                res = Abs(Dot(tmp[i], tmp[j])) <= epsilon;
        }
    }
    return res;
}

} // namespace nova
