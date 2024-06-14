/**
 * @File vec4.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/30
 * @Brief 
 */

#pragma once

#include "./VectorType.hpp"

namespace nova {
template<typename T> struct vec<4, T>
{
    using value_type = T;
    using vec_type   = vec4_t<T>;
    using bool_type  = vec4_t<bool>;

    // clang-format off
    union
    {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        struct { T s, t, p, q; };
    };

    // clang-format on

    NOVA_FUNC constexpr vec()                   = default;
    NOVA_FUNC constexpr vec(const vec4_t<T>& v) = default;

    NOVA_FUNC constexpr explicit vec(T scalar);
    NOVA_FUNC constexpr vec(T x, T y, T z, T w);

    template<typename U> NOVA_FUNC constexpr explicit vec(const vec1_t<U>& v);

    // clang-format off
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, Y y, Z z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, Y y, Z z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, const vec1_t<Y>& y, Z z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, const vec1_t<Y>& y, Z z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, Y y, const vec1_t<Z>& z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, Y y, const vec1_t<Z>& z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, const vec1_t<Y>& y, const vec1_t<Z>& z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, const vec1_t<Y>& y, const vec1_t<Z>& z, W w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, Y y, Z z, const vec1_t<W>& w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, const vec1_t<Y>& y, Z z, const vec1_t<W>& w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, const vec1_t<Y>& y, Z z, const vec1_t<W>& w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, Y y, const vec1_t<Z>& z, const vec1_t<W>& w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, Y y, const vec1_t<Z>& z, const vec1_t<W>& w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(X x, const vec1_t<Y>& y, const vec1_t<Z>& z, const vec1_t<W>& w);
    template <typename X, typename Y, typename Z, typename W>
    NOVA_FUNC constexpr vec(const vec1_t<X>& x, const vec1_t<Y>& y, const vec1_t<Z>& z, const vec1_t<W>& w);

    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec2_t<A>& xy, B z, C w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec2_t<A>& xy, const vec1_t<B>& z, C w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec2_t<A>& xy, B z, const vec1_t<C>& w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec2_t<A>& xy, const vec1_t<B>& z, const vec1_t<C>& w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(A x, const vec2_t<B>& yz, C w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec1_t<A>& x, const vec2_t<B>& yz, C w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(A x, const vec2_t<B>& yz, const vec1_t<C>& w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec1_t<A>& x, const vec2_t<B>& yz, const vec1_t<C>& w);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(A x, B y, const vec2_t<C>& zw);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(A x, const vec1_t<B>& y, const vec2_t<C>& zw);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec1_t<A>& x, B y, const vec2_t<C>& zw);
    template <typename A, typename B, typename C> NOVA_FUNC constexpr vec(const vec1_t<A>& x, const vec1_t<B>& y, const vec2_t<C>& zw);
    template <typename A, typename B> NOVA_FUNC constexpr vec(const vec3_t<A>& xyz, B w);
    template <typename A, typename B> NOVA_FUNC constexpr vec(const vec3_t<A>& xyz, const vec1_t<B>& w);
    template <typename A, typename B> NOVA_FUNC constexpr vec(A x, const vec3_t<B>& yzw);
    template <typename A, typename B> NOVA_FUNC constexpr vec(const vec1_t<A>& x, const vec3_t<B>& yzw);
    template <typename A, typename B> NOVA_FUNC constexpr vec(const vec2_t<A>& xy, const vec2_t<B>& zw);
    template <typename U> NOVA_FUNC constexpr explicit vec(const vec4_t<U>& v);
    // clang-format on

    // -- Unary arithmetic operators --
    NOVA_FUNC constexpr vec4_t<T>& operator=(const vec4_t<T>& v) = default;

    NOVA_FUNC constexpr vec4_t<T>& operator++();
    NOVA_FUNC constexpr vec4_t<T>& operator--();
    NOVA_FUNC constexpr vec4_t<T> operator++(int);
    NOVA_FUNC constexpr vec4_t<T> operator--(int);

    // clang-format off
    NOVA_FUNC constexpr auto operator<=>(const vec_type& v) const noexcept;

    template<typename U> NOVA_FUNC constexpr auto operator<=>(const vec4_t<U>& v) const noexcept requires Convertible<T, U>;
    template<typename U> NOVA_FUNC constexpr bool  operator==(const vec4_t<U>& v) const noexcept requires Convertible<T, U>;
    // clang-format on

    // clang-format off
    template<typename U> NOVA_FUNC constexpr vec4_t<T>&  operator=(const vec4_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator+=(const vec1_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator+=(const vec4_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator-=(const vec1_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator-=(const vec4_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator*=(const vec1_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator*=(const vec4_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator/=(const vec1_t<U>& v);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator/=(const vec4_t<U>& v);

    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator+=(U scalar);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator-=(U scalar);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator*=(U scalar);
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator/=(U scalar);
    // clang-format on

    // clang-format off
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator %=(const vec1_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator %=(const vec4_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator &=(const vec1_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator &=(const vec4_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator |=(const vec1_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator |=(const vec4_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator ^=(const vec1_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator ^=(const vec4_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator<<=(const vec1_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator<<=(const vec4_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator>>=(const vec1_t<U>& v) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator>>=(const vec4_t<U>& v) requires BothIntegral<T, U>;

    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator %=(U scalar) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator &=(U scalar) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator |=(U scalar) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator ^=(U scalar) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator<<=(U scalar) requires BothIntegral<T, U>;
    template<typename U> NOVA_FUNC constexpr vec4_t<T>& operator>>=(U scalar) requires BothIntegral<T, U>;
    // clang-format on

    // clang-format off
    NOVA_FUNC constexpr       T& operator[](int index)       noexcept { return (&x)[index]; }
    NOVA_FUNC constexpr const T& operator[](int index) const noexcept { return (&x)[index]; }

    NOVA_FUNC static constexpr int dim() noexcept { return 4; }
    
#pragma region swizzle
    NOVA_FUNC constexpr auto xx() const noexcept { return vec2_t<T>(x, x); }
    NOVA_FUNC constexpr auto xy() const noexcept { return vec2_t<T>(x, y); }
    NOVA_FUNC constexpr auto xz() const noexcept { return vec2_t<T>(x, z); }
    NOVA_FUNC constexpr auto xw() const noexcept { return vec2_t<T>(x, w); }
    NOVA_FUNC constexpr auto yx() const noexcept { return vec2_t<T>(y, x); }
    NOVA_FUNC constexpr auto yy() const noexcept { return vec2_t<T>(y, y); }
    NOVA_FUNC constexpr auto yz() const noexcept { return vec2_t<T>(y, z); }
    NOVA_FUNC constexpr auto yw() const noexcept { return vec2_t<T>(y, w); }
    NOVA_FUNC constexpr auto zx() const noexcept { return vec2_t<T>(z, x); }
    NOVA_FUNC constexpr auto zy() const noexcept { return vec2_t<T>(z, y); }
    NOVA_FUNC constexpr auto zz() const noexcept { return vec2_t<T>(z, z); }
    NOVA_FUNC constexpr auto zw() const noexcept { return vec2_t<T>(z, w); }
    NOVA_FUNC constexpr auto wx() const noexcept { return vec2_t<T>(w, x); }
    NOVA_FUNC constexpr auto wy() const noexcept { return vec2_t<T>(w, y); }
    NOVA_FUNC constexpr auto wz() const noexcept { return vec2_t<T>(w, z); }
    NOVA_FUNC constexpr auto ww() const noexcept { return vec2_t<T>(w, w); }
    NOVA_FUNC constexpr auto xxx() const noexcept { return vec3_t<T>(x, x, x); }
    NOVA_FUNC constexpr auto xxy() const noexcept { return vec3_t<T>(x, x, y); }
    NOVA_FUNC constexpr auto xxz() const noexcept { return vec3_t<T>(x, x, z); }
    NOVA_FUNC constexpr auto xxw() const noexcept { return vec3_t<T>(x, x, w); }
    NOVA_FUNC constexpr auto xyx() const noexcept { return vec3_t<T>(x, y, x); }
    NOVA_FUNC constexpr auto xyy() const noexcept { return vec3_t<T>(x, y, y); }
    NOVA_FUNC constexpr auto xyz() const noexcept { return vec3_t<T>(x, y, z); }
    NOVA_FUNC constexpr auto xyw() const noexcept { return vec3_t<T>(x, y, w); }
    NOVA_FUNC constexpr auto xzx() const noexcept { return vec3_t<T>(x, z, x); }
    NOVA_FUNC constexpr auto xzy() const noexcept { return vec3_t<T>(x, z, y); }
    NOVA_FUNC constexpr auto xzz() const noexcept { return vec3_t<T>(x, z, z); }
    NOVA_FUNC constexpr auto xzw() const noexcept { return vec3_t<T>(x, z, w); }
    NOVA_FUNC constexpr auto xwx() const noexcept { return vec3_t<T>(x, w, x); }
    NOVA_FUNC constexpr auto xwy() const noexcept { return vec3_t<T>(x, w, y); }
    NOVA_FUNC constexpr auto xwz() const noexcept { return vec3_t<T>(x, w, z); }
    NOVA_FUNC constexpr auto xww() const noexcept { return vec3_t<T>(x, w, w); }
    NOVA_FUNC constexpr auto yxx() const noexcept { return vec3_t<T>(y, x, x); }
    NOVA_FUNC constexpr auto yxy() const noexcept { return vec3_t<T>(y, x, y); }
    NOVA_FUNC constexpr auto yxz() const noexcept { return vec3_t<T>(y, x, z); }
    NOVA_FUNC constexpr auto yxw() const noexcept { return vec3_t<T>(y, x, w); }
    NOVA_FUNC constexpr auto yyx() const noexcept { return vec3_t<T>(y, y, x); }
    NOVA_FUNC constexpr auto yyy() const noexcept { return vec3_t<T>(y, y, y); }
    NOVA_FUNC constexpr auto yyz() const noexcept { return vec3_t<T>(y, y, z); }
    NOVA_FUNC constexpr auto yyw() const noexcept { return vec3_t<T>(y, y, w); }
    NOVA_FUNC constexpr auto yzx() const noexcept { return vec3_t<T>(y, z, x); }
    NOVA_FUNC constexpr auto yzy() const noexcept { return vec3_t<T>(y, z, y); }
    NOVA_FUNC constexpr auto yzz() const noexcept { return vec3_t<T>(y, z, z); }
    NOVA_FUNC constexpr auto yzw() const noexcept { return vec3_t<T>(y, z, w); }
    NOVA_FUNC constexpr auto ywx() const noexcept { return vec3_t<T>(y, w, x); }
    NOVA_FUNC constexpr auto ywy() const noexcept { return vec3_t<T>(y, w, y); }
    NOVA_FUNC constexpr auto ywz() const noexcept { return vec3_t<T>(y, w, z); }
    NOVA_FUNC constexpr auto yww() const noexcept { return vec3_t<T>(y, w, w); }
    NOVA_FUNC constexpr auto zxx() const noexcept { return vec3_t<T>(z, x, x); }
    NOVA_FUNC constexpr auto zxy() const noexcept { return vec3_t<T>(z, x, y); }
    NOVA_FUNC constexpr auto zxz() const noexcept { return vec3_t<T>(z, x, z); }
    NOVA_FUNC constexpr auto zxw() const noexcept { return vec3_t<T>(z, x, w); }
    NOVA_FUNC constexpr auto zyx() const noexcept { return vec3_t<T>(z, y, x); }
    NOVA_FUNC constexpr auto zyy() const noexcept { return vec3_t<T>(z, y, y); }
    NOVA_FUNC constexpr auto zyz() const noexcept { return vec3_t<T>(z, y, z); }
    NOVA_FUNC constexpr auto zyw() const noexcept { return vec3_t<T>(z, y, w); }
    NOVA_FUNC constexpr auto zzx() const noexcept { return vec3_t<T>(z, z, x); }
    NOVA_FUNC constexpr auto zzy() const noexcept { return vec3_t<T>(z, z, y); }
    NOVA_FUNC constexpr auto zzz() const noexcept { return vec3_t<T>(z, z, z); }
    NOVA_FUNC constexpr auto zzw() const noexcept { return vec3_t<T>(z, z, w); }
    NOVA_FUNC constexpr auto zwx() const noexcept { return vec3_t<T>(z, w, x); }
    NOVA_FUNC constexpr auto zwy() const noexcept { return vec3_t<T>(z, w, y); }
    NOVA_FUNC constexpr auto zwz() const noexcept { return vec3_t<T>(z, w, z); }
    NOVA_FUNC constexpr auto zww() const noexcept { return vec3_t<T>(z, w, w); }
    NOVA_FUNC constexpr auto wxx() const noexcept { return vec3_t<T>(w, x, x); }
    NOVA_FUNC constexpr auto wxy() const noexcept { return vec3_t<T>(w, x, y); }
    NOVA_FUNC constexpr auto wxz() const noexcept { return vec3_t<T>(w, x, z); }
    NOVA_FUNC constexpr auto wxw() const noexcept { return vec3_t<T>(w, x, w); }
    NOVA_FUNC constexpr auto wyx() const noexcept { return vec3_t<T>(w, y, x); }
    NOVA_FUNC constexpr auto wyy() const noexcept { return vec3_t<T>(w, y, y); }
    NOVA_FUNC constexpr auto wyz() const noexcept { return vec3_t<T>(w, y, z); }
    NOVA_FUNC constexpr auto wyw() const noexcept { return vec3_t<T>(w, y, w); }
    NOVA_FUNC constexpr auto wzx() const noexcept { return vec3_t<T>(w, z, x); }
    NOVA_FUNC constexpr auto wzy() const noexcept { return vec3_t<T>(w, z, y); }
    NOVA_FUNC constexpr auto wzz() const noexcept { return vec3_t<T>(w, z, z); }
    NOVA_FUNC constexpr auto wzw() const noexcept { return vec3_t<T>(w, z, w); }
    NOVA_FUNC constexpr auto wwx() const noexcept { return vec3_t<T>(w, w, x); }
    NOVA_FUNC constexpr auto wwy() const noexcept { return vec3_t<T>(w, w, y); }
    NOVA_FUNC constexpr auto wwz() const noexcept { return vec3_t<T>(w, w, z); }
    NOVA_FUNC constexpr auto www() const noexcept { return vec3_t<T>(w, w, w); }
    NOVA_FUNC constexpr auto xxxx() const noexcept { return vec_type(x, x, x, x); }
    NOVA_FUNC constexpr auto xxxy() const noexcept { return vec_type(x, x, x, y); }
    NOVA_FUNC constexpr auto xxxz() const noexcept { return vec_type(x, x, x, z); }
    NOVA_FUNC constexpr auto xxxw() const noexcept { return vec_type(x, x, x, w); }
    NOVA_FUNC constexpr auto xxyx() const noexcept { return vec_type(x, x, y, x); }
    NOVA_FUNC constexpr auto xxyy() const noexcept { return vec_type(x, x, y, y); }
    NOVA_FUNC constexpr auto xxyz() const noexcept { return vec_type(x, x, y, z); }
    NOVA_FUNC constexpr auto xxyw() const noexcept { return vec_type(x, x, y, w); }
    NOVA_FUNC constexpr auto xxzx() const noexcept { return vec_type(x, x, z, x); }
    NOVA_FUNC constexpr auto xxzy() const noexcept { return vec_type(x, x, z, y); }
    NOVA_FUNC constexpr auto xxzz() const noexcept { return vec_type(x, x, z, z); }
    NOVA_FUNC constexpr auto xxzw() const noexcept { return vec_type(x, x, z, w); }
    NOVA_FUNC constexpr auto xxwx() const noexcept { return vec_type(x, x, w, x); }
    NOVA_FUNC constexpr auto xxwy() const noexcept { return vec_type(x, x, w, y); }
    NOVA_FUNC constexpr auto xxwz() const noexcept { return vec_type(x, x, w, z); }
    NOVA_FUNC constexpr auto xxww() const noexcept { return vec_type(x, x, w, w); }
    NOVA_FUNC constexpr auto xyxx() const noexcept { return vec_type(x, y, x, x); }
    NOVA_FUNC constexpr auto xyxy() const noexcept { return vec_type(x, y, x, y); }
    NOVA_FUNC constexpr auto xyxz() const noexcept { return vec_type(x, y, x, z); }
    NOVA_FUNC constexpr auto xyxw() const noexcept { return vec_type(x, y, x, w); }
    NOVA_FUNC constexpr auto xyyx() const noexcept { return vec_type(x, y, y, x); }
    NOVA_FUNC constexpr auto xyyy() const noexcept { return vec_type(x, y, y, y); }
    NOVA_FUNC constexpr auto xyyz() const noexcept { return vec_type(x, y, y, z); }
    NOVA_FUNC constexpr auto xyyw() const noexcept { return vec_type(x, y, y, w); }
    NOVA_FUNC constexpr auto xyzx() const noexcept { return vec_type(x, y, z, x); }
    NOVA_FUNC constexpr auto xyzy() const noexcept { return vec_type(x, y, z, y); }
    NOVA_FUNC constexpr auto xyzz() const noexcept { return vec_type(x, y, z, z); }
    NOVA_FUNC constexpr auto xyzw() const noexcept { return vec_type(x, y, z, w); }
    NOVA_FUNC constexpr auto xywx() const noexcept { return vec_type(x, y, w, x); }
    NOVA_FUNC constexpr auto xywy() const noexcept { return vec_type(x, y, w, y); }
    NOVA_FUNC constexpr auto xywz() const noexcept { return vec_type(x, y, w, z); }
    NOVA_FUNC constexpr auto xyww() const noexcept { return vec_type(x, y, w, w); }
    NOVA_FUNC constexpr auto xzxx() const noexcept { return vec_type(x, z, x, x); }
    NOVA_FUNC constexpr auto xzxy() const noexcept { return vec_type(x, z, x, y); }
    NOVA_FUNC constexpr auto xzxz() const noexcept { return vec_type(x, z, x, z); }
    NOVA_FUNC constexpr auto xzxw() const noexcept { return vec_type(x, z, x, w); }
    NOVA_FUNC constexpr auto xzyx() const noexcept { return vec_type(x, z, y, x); }
    NOVA_FUNC constexpr auto xzyy() const noexcept { return vec_type(x, z, y, y); }
    NOVA_FUNC constexpr auto xzyz() const noexcept { return vec_type(x, z, y, z); }
    NOVA_FUNC constexpr auto xzyw() const noexcept { return vec_type(x, z, y, w); }
    NOVA_FUNC constexpr auto xzzx() const noexcept { return vec_type(x, z, z, x); }
    NOVA_FUNC constexpr auto xzzy() const noexcept { return vec_type(x, z, z, y); }
    NOVA_FUNC constexpr auto xzzz() const noexcept { return vec_type(x, z, z, z); }
    NOVA_FUNC constexpr auto xzzw() const noexcept { return vec_type(x, z, z, w); }
    NOVA_FUNC constexpr auto xzwx() const noexcept { return vec_type(x, z, w, x); }
    NOVA_FUNC constexpr auto xzwy() const noexcept { return vec_type(x, z, w, y); }
    NOVA_FUNC constexpr auto xzwz() const noexcept { return vec_type(x, z, w, z); }
    NOVA_FUNC constexpr auto xzww() const noexcept { return vec_type(x, z, w, w); }
    NOVA_FUNC constexpr auto xwxx() const noexcept { return vec_type(x, w, x, x); }
    NOVA_FUNC constexpr auto xwxy() const noexcept { return vec_type(x, w, x, y); }
    NOVA_FUNC constexpr auto xwxz() const noexcept { return vec_type(x, w, x, z); }
    NOVA_FUNC constexpr auto xwxw() const noexcept { return vec_type(x, w, x, w); }
    NOVA_FUNC constexpr auto xwyx() const noexcept { return vec_type(x, w, y, x); }
    NOVA_FUNC constexpr auto xwyy() const noexcept { return vec_type(x, w, y, y); }
    NOVA_FUNC constexpr auto xwyz() const noexcept { return vec_type(x, w, y, z); }
    NOVA_FUNC constexpr auto xwyw() const noexcept { return vec_type(x, w, y, w); }
    NOVA_FUNC constexpr auto xwzx() const noexcept { return vec_type(x, w, z, x); }
    NOVA_FUNC constexpr auto xwzy() const noexcept { return vec_type(x, w, z, y); }
    NOVA_FUNC constexpr auto xwzz() const noexcept { return vec_type(x, w, z, z); }
    NOVA_FUNC constexpr auto xwzw() const noexcept { return vec_type(x, w, z, w); }
    NOVA_FUNC constexpr auto xwwx() const noexcept { return vec_type(x, w, w, x); }
    NOVA_FUNC constexpr auto xwwy() const noexcept { return vec_type(x, w, w, y); }
    NOVA_FUNC constexpr auto xwwz() const noexcept { return vec_type(x, w, w, z); }
    NOVA_FUNC constexpr auto xwww() const noexcept { return vec_type(x, w, w, w); }
    NOVA_FUNC constexpr auto yxxx() const noexcept { return vec_type(y, x, x, x); }
    NOVA_FUNC constexpr auto yxxy() const noexcept { return vec_type(y, x, x, y); }
    NOVA_FUNC constexpr auto yxxz() const noexcept { return vec_type(y, x, x, z); }
    NOVA_FUNC constexpr auto yxxw() const noexcept { return vec_type(y, x, x, w); }
    NOVA_FUNC constexpr auto yxyx() const noexcept { return vec_type(y, x, y, x); }
    NOVA_FUNC constexpr auto yxyy() const noexcept { return vec_type(y, x, y, y); }
    NOVA_FUNC constexpr auto yxyz() const noexcept { return vec_type(y, x, y, z); }
    NOVA_FUNC constexpr auto yxyw() const noexcept { return vec_type(y, x, y, w); }
    NOVA_FUNC constexpr auto yxzx() const noexcept { return vec_type(y, x, z, x); }
    NOVA_FUNC constexpr auto yxzy() const noexcept { return vec_type(y, x, z, y); }
    NOVA_FUNC constexpr auto yxzz() const noexcept { return vec_type(y, x, z, z); }
    NOVA_FUNC constexpr auto yxzw() const noexcept { return vec_type(y, x, z, w); }
    NOVA_FUNC constexpr auto yxwx() const noexcept { return vec_type(y, x, w, x); }
    NOVA_FUNC constexpr auto yxwy() const noexcept { return vec_type(y, x, w, y); }
    NOVA_FUNC constexpr auto yxwz() const noexcept { return vec_type(y, x, w, z); }
    NOVA_FUNC constexpr auto yxww() const noexcept { return vec_type(y, x, w, w); }
    NOVA_FUNC constexpr auto yyxx() const noexcept { return vec_type(y, y, x, x); }
    NOVA_FUNC constexpr auto yyxy() const noexcept { return vec_type(y, y, x, y); }
    NOVA_FUNC constexpr auto yyxz() const noexcept { return vec_type(y, y, x, z); }
    NOVA_FUNC constexpr auto yyxw() const noexcept { return vec_type(y, y, x, w); }
    NOVA_FUNC constexpr auto yyyx() const noexcept { return vec_type(y, y, y, x); }
    NOVA_FUNC constexpr auto yyyy() const noexcept { return vec_type(y, y, y, y); }
    NOVA_FUNC constexpr auto yyyz() const noexcept { return vec_type(y, y, y, z); }
    NOVA_FUNC constexpr auto yyyw() const noexcept { return vec_type(y, y, y, w); }
    NOVA_FUNC constexpr auto yyzx() const noexcept { return vec_type(y, y, z, x); }
    NOVA_FUNC constexpr auto yyzy() const noexcept { return vec_type(y, y, z, y); }
    NOVA_FUNC constexpr auto yyzz() const noexcept { return vec_type(y, y, z, z); }
    NOVA_FUNC constexpr auto yyzw() const noexcept { return vec_type(y, y, z, w); }
    NOVA_FUNC constexpr auto yywx() const noexcept { return vec_type(y, y, w, x); }
    NOVA_FUNC constexpr auto yywy() const noexcept { return vec_type(y, y, w, y); }
    NOVA_FUNC constexpr auto yywz() const noexcept { return vec_type(y, y, w, z); }
    NOVA_FUNC constexpr auto yyww() const noexcept { return vec_type(y, y, w, w); }
    NOVA_FUNC constexpr auto yzxx() const noexcept { return vec_type(y, z, x, x); }
    NOVA_FUNC constexpr auto yzxy() const noexcept { return vec_type(y, z, x, y); }
    NOVA_FUNC constexpr auto yzxz() const noexcept { return vec_type(y, z, x, z); }
    NOVA_FUNC constexpr auto yzxw() const noexcept { return vec_type(y, z, x, w); }
    NOVA_FUNC constexpr auto yzyx() const noexcept { return vec_type(y, z, y, x); }
    NOVA_FUNC constexpr auto yzyy() const noexcept { return vec_type(y, z, y, y); }
    NOVA_FUNC constexpr auto yzyz() const noexcept { return vec_type(y, z, y, z); }
    NOVA_FUNC constexpr auto yzyw() const noexcept { return vec_type(y, z, y, w); }
    NOVA_FUNC constexpr auto yzzx() const noexcept { return vec_type(y, z, z, x); }
    NOVA_FUNC constexpr auto yzzy() const noexcept { return vec_type(y, z, z, y); }
    NOVA_FUNC constexpr auto yzzz() const noexcept { return vec_type(y, z, z, z); }
    NOVA_FUNC constexpr auto yzzw() const noexcept { return vec_type(y, z, z, w); }
    NOVA_FUNC constexpr auto yzwx() const noexcept { return vec_type(y, z, w, x); }
    NOVA_FUNC constexpr auto yzwy() const noexcept { return vec_type(y, z, w, y); }
    NOVA_FUNC constexpr auto yzwz() const noexcept { return vec_type(y, z, w, z); }
    NOVA_FUNC constexpr auto yzww() const noexcept { return vec_type(y, z, w, w); }
    NOVA_FUNC constexpr auto ywxx() const noexcept { return vec_type(y, w, x, x); }
    NOVA_FUNC constexpr auto ywxy() const noexcept { return vec_type(y, w, x, y); }
    NOVA_FUNC constexpr auto ywxz() const noexcept { return vec_type(y, w, x, z); }
    NOVA_FUNC constexpr auto ywxw() const noexcept { return vec_type(y, w, x, w); }
    NOVA_FUNC constexpr auto ywyx() const noexcept { return vec_type(y, w, y, x); }
    NOVA_FUNC constexpr auto ywyy() const noexcept { return vec_type(y, w, y, y); }
    NOVA_FUNC constexpr auto ywyz() const noexcept { return vec_type(y, w, y, z); }
    NOVA_FUNC constexpr auto ywyw() const noexcept { return vec_type(y, w, y, w); }
    NOVA_FUNC constexpr auto ywzx() const noexcept { return vec_type(y, w, z, x); }
    NOVA_FUNC constexpr auto ywzy() const noexcept { return vec_type(y, w, z, y); }
    NOVA_FUNC constexpr auto ywzz() const noexcept { return vec_type(y, w, z, z); }
    NOVA_FUNC constexpr auto ywzw() const noexcept { return vec_type(y, w, z, w); }
    NOVA_FUNC constexpr auto ywwx() const noexcept { return vec_type(y, w, w, x); }
    NOVA_FUNC constexpr auto ywwy() const noexcept { return vec_type(y, w, w, y); }
    NOVA_FUNC constexpr auto ywwz() const noexcept { return vec_type(y, w, w, z); }
    NOVA_FUNC constexpr auto ywww() const noexcept { return vec_type(y, w, w, w); }
    NOVA_FUNC constexpr auto zxxx() const noexcept { return vec_type(z, x, x, x); }
    NOVA_FUNC constexpr auto zxxy() const noexcept { return vec_type(z, x, x, y); }
    NOVA_FUNC constexpr auto zxxz() const noexcept { return vec_type(z, x, x, z); }
    NOVA_FUNC constexpr auto zxxw() const noexcept { return vec_type(z, x, x, w); }
    NOVA_FUNC constexpr auto zxyx() const noexcept { return vec_type(z, x, y, x); }
    NOVA_FUNC constexpr auto zxyy() const noexcept { return vec_type(z, x, y, y); }
    NOVA_FUNC constexpr auto zxyz() const noexcept { return vec_type(z, x, y, z); }
    NOVA_FUNC constexpr auto zxyw() const noexcept { return vec_type(z, x, y, w); }
    NOVA_FUNC constexpr auto zxzx() const noexcept { return vec_type(z, x, z, x); }
    NOVA_FUNC constexpr auto zxzy() const noexcept { return vec_type(z, x, z, y); }
    NOVA_FUNC constexpr auto zxzz() const noexcept { return vec_type(z, x, z, z); }
    NOVA_FUNC constexpr auto zxzw() const noexcept { return vec_type(z, x, z, w); }
    NOVA_FUNC constexpr auto zxwx() const noexcept { return vec_type(z, x, w, x); }
    NOVA_FUNC constexpr auto zxwy() const noexcept { return vec_type(z, x, w, y); }
    NOVA_FUNC constexpr auto zxwz() const noexcept { return vec_type(z, x, w, z); }
    NOVA_FUNC constexpr auto zxww() const noexcept { return vec_type(z, x, w, w); }
    NOVA_FUNC constexpr auto zyxx() const noexcept { return vec_type(z, y, x, x); }
    NOVA_FUNC constexpr auto zyxy() const noexcept { return vec_type(z, y, x, y); }
    NOVA_FUNC constexpr auto zyxz() const noexcept { return vec_type(z, y, x, z); }
    NOVA_FUNC constexpr auto zyxw() const noexcept { return vec_type(z, y, x, w); }
    NOVA_FUNC constexpr auto zyyx() const noexcept { return vec_type(z, y, y, x); }
    NOVA_FUNC constexpr auto zyyy() const noexcept { return vec_type(z, y, y, y); }
    NOVA_FUNC constexpr auto zyyz() const noexcept { return vec_type(z, y, y, z); }
    NOVA_FUNC constexpr auto zyyw() const noexcept { return vec_type(z, y, y, w); }
    NOVA_FUNC constexpr auto zyzx() const noexcept { return vec_type(z, y, z, x); }
    NOVA_FUNC constexpr auto zyzy() const noexcept { return vec_type(z, y, z, y); }
    NOVA_FUNC constexpr auto zyzz() const noexcept { return vec_type(z, y, z, z); }
    NOVA_FUNC constexpr auto zyzw() const noexcept { return vec_type(z, y, z, w); }
    NOVA_FUNC constexpr auto zywx() const noexcept { return vec_type(z, y, w, x); }
    NOVA_FUNC constexpr auto zywy() const noexcept { return vec_type(z, y, w, y); }
    NOVA_FUNC constexpr auto zywz() const noexcept { return vec_type(z, y, w, z); }
    NOVA_FUNC constexpr auto zyww() const noexcept { return vec_type(z, y, w, w); }
    NOVA_FUNC constexpr auto zzxx() const noexcept { return vec_type(z, z, x, x); }
    NOVA_FUNC constexpr auto zzxy() const noexcept { return vec_type(z, z, x, y); }
    NOVA_FUNC constexpr auto zzxz() const noexcept { return vec_type(z, z, x, z); }
    NOVA_FUNC constexpr auto zzxw() const noexcept { return vec_type(z, z, x, w); }
    NOVA_FUNC constexpr auto zzyx() const noexcept { return vec_type(z, z, y, x); }
    NOVA_FUNC constexpr auto zzyy() const noexcept { return vec_type(z, z, y, y); }
    NOVA_FUNC constexpr auto zzyz() const noexcept { return vec_type(z, z, y, z); }
    NOVA_FUNC constexpr auto zzyw() const noexcept { return vec_type(z, z, y, w); }
    NOVA_FUNC constexpr auto zzzx() const noexcept { return vec_type(z, z, z, x); }
    NOVA_FUNC constexpr auto zzzy() const noexcept { return vec_type(z, z, z, y); }
    NOVA_FUNC constexpr auto zzzz() const noexcept { return vec_type(z, z, z, z); }
    NOVA_FUNC constexpr auto zzzw() const noexcept { return vec_type(z, z, z, w); }
    NOVA_FUNC constexpr auto zzwx() const noexcept { return vec_type(z, z, w, x); }
    NOVA_FUNC constexpr auto zzwy() const noexcept { return vec_type(z, z, w, y); }
    NOVA_FUNC constexpr auto zzwz() const noexcept { return vec_type(z, z, w, z); }
    NOVA_FUNC constexpr auto zzww() const noexcept { return vec_type(z, z, w, w); }
    NOVA_FUNC constexpr auto zwxx() const noexcept { return vec_type(z, w, x, x); }
    NOVA_FUNC constexpr auto zwxy() const noexcept { return vec_type(z, w, x, y); }
    NOVA_FUNC constexpr auto zwxz() const noexcept { return vec_type(z, w, x, z); }
    NOVA_FUNC constexpr auto zwxw() const noexcept { return vec_type(z, w, x, w); }
    NOVA_FUNC constexpr auto zwyx() const noexcept { return vec_type(z, w, y, x); }
    NOVA_FUNC constexpr auto zwyy() const noexcept { return vec_type(z, w, y, y); }
    NOVA_FUNC constexpr auto zwyz() const noexcept { return vec_type(z, w, y, z); }
    NOVA_FUNC constexpr auto zwyw() const noexcept { return vec_type(z, w, y, w); }
    NOVA_FUNC constexpr auto zwzx() const noexcept { return vec_type(z, w, z, x); }
    NOVA_FUNC constexpr auto zwzy() const noexcept { return vec_type(z, w, z, y); }
    NOVA_FUNC constexpr auto zwzz() const noexcept { return vec_type(z, w, z, z); }
    NOVA_FUNC constexpr auto zwzw() const noexcept { return vec_type(z, w, z, w); }
    NOVA_FUNC constexpr auto zwwx() const noexcept { return vec_type(z, w, w, x); }
    NOVA_FUNC constexpr auto zwwy() const noexcept { return vec_type(z, w, w, y); }
    NOVA_FUNC constexpr auto zwwz() const noexcept { return vec_type(z, w, w, z); }
    NOVA_FUNC constexpr auto zwww() const noexcept { return vec_type(z, w, w, w); }
    NOVA_FUNC constexpr auto wxxx() const noexcept { return vec_type(w, x, x, x); }
    NOVA_FUNC constexpr auto wxxy() const noexcept { return vec_type(w, x, x, y); }
    NOVA_FUNC constexpr auto wxxz() const noexcept { return vec_type(w, x, x, z); }
    NOVA_FUNC constexpr auto wxxw() const noexcept { return vec_type(w, x, x, w); }
    NOVA_FUNC constexpr auto wxyx() const noexcept { return vec_type(w, x, y, x); }
    NOVA_FUNC constexpr auto wxyy() const noexcept { return vec_type(w, x, y, y); }
    NOVA_FUNC constexpr auto wxyz() const noexcept { return vec_type(w, x, y, z); }
    NOVA_FUNC constexpr auto wxyw() const noexcept { return vec_type(w, x, y, w); }
    NOVA_FUNC constexpr auto wxzx() const noexcept { return vec_type(w, x, z, x); }
    NOVA_FUNC constexpr auto wxzy() const noexcept { return vec_type(w, x, z, y); }
    NOVA_FUNC constexpr auto wxzz() const noexcept { return vec_type(w, x, z, z); }
    NOVA_FUNC constexpr auto wxzw() const noexcept { return vec_type(w, x, z, w); }
    NOVA_FUNC constexpr auto wxwx() const noexcept { return vec_type(w, x, w, x); }
    NOVA_FUNC constexpr auto wxwy() const noexcept { return vec_type(w, x, w, y); }
    NOVA_FUNC constexpr auto wxwz() const noexcept { return vec_type(w, x, w, z); }
    NOVA_FUNC constexpr auto wxww() const noexcept { return vec_type(w, x, w, w); }
    NOVA_FUNC constexpr auto wyxx() const noexcept { return vec_type(w, y, x, x); }
    NOVA_FUNC constexpr auto wyxy() const noexcept { return vec_type(w, y, x, y); }
    NOVA_FUNC constexpr auto wyxz() const noexcept { return vec_type(w, y, x, z); }
    NOVA_FUNC constexpr auto wyxw() const noexcept { return vec_type(w, y, x, w); }
    NOVA_FUNC constexpr auto wyyx() const noexcept { return vec_type(w, y, y, x); }
    NOVA_FUNC constexpr auto wyyy() const noexcept { return vec_type(w, y, y, y); }
    NOVA_FUNC constexpr auto wyyz() const noexcept { return vec_type(w, y, y, z); }
    NOVA_FUNC constexpr auto wyyw() const noexcept { return vec_type(w, y, y, w); }
    NOVA_FUNC constexpr auto wyzx() const noexcept { return vec_type(w, y, z, x); }
    NOVA_FUNC constexpr auto wyzy() const noexcept { return vec_type(w, y, z, y); }
    NOVA_FUNC constexpr auto wyzz() const noexcept { return vec_type(w, y, z, z); }
    NOVA_FUNC constexpr auto wyzw() const noexcept { return vec_type(w, y, z, w); }
    NOVA_FUNC constexpr auto wywx() const noexcept { return vec_type(w, y, w, x); }
    NOVA_FUNC constexpr auto wywy() const noexcept { return vec_type(w, y, w, y); }
    NOVA_FUNC constexpr auto wywz() const noexcept { return vec_type(w, y, w, z); }
    NOVA_FUNC constexpr auto wyww() const noexcept { return vec_type(w, y, w, w); }
    NOVA_FUNC constexpr auto wzxx() const noexcept { return vec_type(w, z, x, x); }
    NOVA_FUNC constexpr auto wzxy() const noexcept { return vec_type(w, z, x, y); }
    NOVA_FUNC constexpr auto wzxz() const noexcept { return vec_type(w, z, x, z); }
    NOVA_FUNC constexpr auto wzxw() const noexcept { return vec_type(w, z, x, w); }
    NOVA_FUNC constexpr auto wzyx() const noexcept { return vec_type(w, z, y, x); }
    NOVA_FUNC constexpr auto wzyy() const noexcept { return vec_type(w, z, y, y); }
    NOVA_FUNC constexpr auto wzyz() const noexcept { return vec_type(w, z, y, z); }
    NOVA_FUNC constexpr auto wzyw() const noexcept { return vec_type(w, z, y, w); }
    NOVA_FUNC constexpr auto wzzx() const noexcept { return vec_type(w, z, z, x); }
    NOVA_FUNC constexpr auto wzzy() const noexcept { return vec_type(w, z, z, y); }
    NOVA_FUNC constexpr auto wzzz() const noexcept { return vec_type(w, z, z, z); }
    NOVA_FUNC constexpr auto wzzw() const noexcept { return vec_type(w, z, z, w); }
    NOVA_FUNC constexpr auto wzwx() const noexcept { return vec_type(w, z, w, x); }
    NOVA_FUNC constexpr auto wzwy() const noexcept { return vec_type(w, z, w, y); }
    NOVA_FUNC constexpr auto wzwz() const noexcept { return vec_type(w, z, w, z); }
    NOVA_FUNC constexpr auto wzww() const noexcept { return vec_type(w, z, w, w); }
    NOVA_FUNC constexpr auto wwxx() const noexcept { return vec_type(w, w, x, x); }
    NOVA_FUNC constexpr auto wwxy() const noexcept { return vec_type(w, w, x, y); }
    NOVA_FUNC constexpr auto wwxz() const noexcept { return vec_type(w, w, x, z); }
    NOVA_FUNC constexpr auto wwxw() const noexcept { return vec_type(w, w, x, w); }
    NOVA_FUNC constexpr auto wwyx() const noexcept { return vec_type(w, w, y, x); }
    NOVA_FUNC constexpr auto wwyy() const noexcept { return vec_type(w, w, y, y); }
    NOVA_FUNC constexpr auto wwyz() const noexcept { return vec_type(w, w, y, z); }
    NOVA_FUNC constexpr auto wwyw() const noexcept { return vec_type(w, w, y, w); }
    NOVA_FUNC constexpr auto wwzx() const noexcept { return vec_type(w, w, z, x); }
    NOVA_FUNC constexpr auto wwzy() const noexcept { return vec_type(w, w, z, y); }
    NOVA_FUNC constexpr auto wwzz() const noexcept { return vec_type(w, w, z, z); }
    NOVA_FUNC constexpr auto wwzw() const noexcept { return vec_type(w, w, z, w); }
    NOVA_FUNC constexpr auto wwwx() const noexcept { return vec_type(w, w, w, x); }
    NOVA_FUNC constexpr auto wwwy() const noexcept { return vec_type(w, w, w, y); }
    NOVA_FUNC constexpr auto wwwz() const noexcept { return vec_type(w, w, w, z); }
    NOVA_FUNC constexpr auto wwww() const noexcept { return vec_type(w, w, w, w); }
#pragma endregion
    // clang-format on
};
} //namespace nova

namespace nova {

template<typename T> NOVA_FUNC constexpr vec4_t<T>::vec(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar)
{
}

template<typename T> NOVA_FUNC constexpr vec4_t<T>::vec(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w)
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<U>& v)
: x(cast_to<T>(v.x)), y(cast_to<T>(v.x)), z(cast_to<T>(v.x)), w(cast_to<T>(v.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, Y _y, Z _z, W _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y)), z(cast_to<T>(_z)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, Y _y, Z _z, W _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y)), z(cast_to<T>(_z)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, const vec1_t<Y>& _y, Z _z, W _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, const vec1_t<Y>& _y, Z _z, W _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, Y _y, const vec1_t<Z>& _z, W _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, Y _y, const vec1_t<Z>& _z, W _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, const vec1_t<Y>& _y, const vec1_t<Z>& _z, W _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, const vec1_t<Y>& _y, const vec1_t<Z>& _z, W _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, Y _y, Z _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y)), z(cast_to<T>(_z)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, const vec1_t<Y>& _y, Z _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, const vec1_t<Y>& _y, Z _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, Y _y, const vec1_t<Z>& _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, Y _y, const vec1_t<Z>& _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(X _x, const vec1_t<Y>& _y, const vec1_t<Z>& _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename X, typename Y, typename Z, typename W>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<X>& _x, const vec1_t<Y>& _y, const vec1_t<Z>& _z, const vec1_t<W>& _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec2_t<A>& _xy, B _z, C _w)
: x(cast_to<T>(_xy.x)), y(cast_to<T>(_xy.y)), z(cast_to<T>(_z)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec2_t<A>& _xy, const vec1_t<B>& _z, C _w)
: x(cast_to<T>(_xy.x)), y(cast_to<T>(_xy.y)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec2_t<A>& _xy, B _z, const vec1_t<C>& _w)
: x(cast_to<T>(_xy.x)), y(cast_to<T>(_xy.y)), z(cast_to<T>(_z)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec2_t<A>& _xy, const vec1_t<B>& _z, const vec1_t<C>& _w)
: x(cast_to<T>(_xy.x)), y(cast_to<T>(_xy.y)), z(cast_to<T>(_z.x)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(A _x, const vec2_t<B>& _yz, C _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_yz.x)), z(cast_to<T>(_yz.y)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<A>& _x, const vec2_t<B>& _yz, C _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_yz.x)), z(cast_to<T>(_yz.y)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(A _x, const vec2_t<B>& _yz, const vec1_t<C>& _w)
: x(cast_to<T>(_x)), y(cast_to<T>(_yz.x)), z(cast_to<T>(_yz.y)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<A>& _x, const vec2_t<B>& _yz, const vec1_t<C>& _w)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_yz.x)), z(cast_to<T>(_yz.y)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(A _x, B _y, const vec2_t<C>& _zw)
: x(cast_to<T>(_x)), y(cast_to<T>(_y)), z(cast_to<T>(_zw.x)), w(cast_to<T>(_zw.y))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<A>& _x, B _y, const vec2_t<C>& _zw)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y)), z(cast_to<T>(_zw.x)), w(cast_to<T>(_zw.y))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(A _x, const vec1_t<B>& _y, const vec2_t<C>& _zw)
: x(cast_to<T>(_x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_zw.x)), w(cast_to<T>(_zw.y))
{
}

template<typename T>
template<typename A, typename B, typename C>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<A>& _x, const vec1_t<B>& _y, const vec2_t<C>& _zw)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_y.x)), z(cast_to<T>(_zw.x)), w(cast_to<T>(_zw.y))
{
}

template<typename T>
template<typename A, typename B>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec3_t<A>& _xyz, B _w)
: x(cast_to<T>(_xyz.x)), y(cast_to<T>(_xyz.y)), z(cast_to<T>(_xyz.z)), w(cast_to<T>(_w))
{
}

template<typename T>
template<typename A, typename B>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec3_t<A>& _xyz, const vec1_t<B>& _w)
: x(cast_to<T>(_xyz.x)), y(cast_to<T>(_xyz.y)), z(cast_to<T>(_xyz.z)), w(cast_to<T>(_w.x))
{
}

template<typename T>
template<typename A, typename B>
NOVA_FUNC constexpr vec4_t<T>::vec(A _x, const vec3_t<B>& _yzw)
: x(cast_to<T>(_x)), y(cast_to<T>(_yzw.x)), z(cast_to<T>(_yzw.y)), w(cast_to<T>(_yzw.z))
{
}

template<typename T>
template<typename A, typename B>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec1_t<A>& _x, const vec3_t<B>& _yzw)
: x(cast_to<T>(_x.x)), y(cast_to<T>(_yzw.x)), z(cast_to<T>(_yzw.y)), w(cast_to<T>(_yzw.z))
{
}

template<typename T>
template<typename A, typename B>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec2_t<A>& _xy, const vec2_t<B>& _zw)
: x(cast_to<T>(_xy.x)), y(cast_to<T>(_xy.y)), z(cast_to<T>(_zw.x)), w(cast_to<T>(_zw.y))
{
}

template<typename T>
template<typename U>
NOVA_FUNC constexpr vec4_t<T>::vec(const vec4_t<U>& v)
: x(cast_to<T>(v.x)), y(cast_to<T>(v.y)), z(cast_to<T>(v.z)), w(cast_to<T>(v.w))
{
}

template<typename T> template<typename U> NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator=(const vec4_t<U>& v)
{
    this->x = cast_to<T>(v.x);
    this->y = cast_to<T>(v.y);
    this->z = cast_to<T>(v.z);
    this->w = cast_to<T>(v.w);
    return *this;
}

template<typename T> NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator++()
{
    ++this->x;
    ++this->y;
    ++this->z;
    ++this->w;
    return *this;
}

template<typename T> NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator--()
{
    --this->x;
    --this->y;
    --this->z;
    --this->w;
    return *this;
}

template<typename T> NOVA_FUNC constexpr vec4_t<T> vec4_t<T>::operator++(int)
{
    vec4_t<T> res(*this);
    ++*this;
    return res;
}

template<typename T> NOVA_FUNC constexpr vec4_t<T> vec4_t<T>::operator--(int)
{
    vec4_t<T> res(*this);
    --*this;
    return res;
}

template<typename T> constexpr auto vec4_t<T>::operator<=>(const vec4_t<T>& v) const noexcept
{
    if (auto cmp = x <=> v.x; cmp)
        return cmp;
    if (auto cmp = y <=> v.y; cmp)
        return cmp;
    if (auto cmp = z <=> v.z; cmp)
        return cmp;
    return w <=> v.w;
}

template<typename T>
template<typename U>
constexpr auto vec4_t<T>::operator<=>(const vec4_t<U>& v) const noexcept
    requires Convertible<T, U>
{
    return this <=> vec_type{cast_to<T>(v.x), cast_to<T>(v.y), cast_to<T>(v.z), cast_to<T>(v.w)};
}

template<typename T>
template<typename U>
constexpr bool vec4_t<T>::operator==(const vec4_t<U>& v) const noexcept
    requires Convertible<T, U>
{
    return x == cast_to<T>(v.x) && y == cast_to<T>(v.y) && z == cast_to<T>(v.z) && w == cast_to<T>(v.w);
}

#define DEFINE_VECTOR4_ARITHMETIC_OP(op)                                                                               \
    template<typename T> template<typename U> NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator op(U scalar)          \
    {                                                                                                                  \
        this->x op cast_to<T>(scalar);                                                                                 \
        this->y op cast_to<T>(scalar);                                                                                 \
        this->z op cast_to<T>(scalar);                                                                                 \
        this->w op cast_to<T>(scalar);                                                                                 \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    template<typename T>                                                                                               \
    template<typename U>                                                                                               \
    NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator op(const vec1_t<U>& v)                                          \
    {                                                                                                                  \
        this->x op cast_to<T>(v.x);                                                                                    \
        this->y op cast_to<T>(v.x);                                                                                    \
        this->z op cast_to<T>(v.x);                                                                                    \
        this->w op cast_to<T>(v.x);                                                                                    \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    template<typename T>                                                                                               \
    template<typename U>                                                                                               \
    NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator op(const vec4_t<U>& v)                                          \
    {                                                                                                                  \
        this->x op cast_to<T>(v.x);                                                                                    \
        this->y op cast_to<T>(v.y);                                                                                    \
        this->z op cast_to<T>(v.z);                                                                                    \
        this->w op cast_to<T>(v.w);                                                                                    \
        return *this;                                                                                                  \
    }

DEFINE_VECTOR4_ARITHMETIC_OP(+=)
DEFINE_VECTOR4_ARITHMETIC_OP(-=)
DEFINE_VECTOR4_ARITHMETIC_OP(*=)
DEFINE_VECTOR4_ARITHMETIC_OP(/=)
#undef DEFINE_VECTOR4_ARITHMETIC_OP

#define DEFINE_VECTOR4_BIT_OP(op)                                                                                      \
    template<typename T>                                                                                               \
    template<typename U>                                                                                               \
    NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator op(U scalar)                                                    \
        requires BothIntegral<T, U>                                                                                    \
    {                                                                                                                  \
        this->x op cast_to<T>(scalar);                                                                                 \
        this->y op cast_to<T>(scalar);                                                                                 \
        this->z op cast_to<T>(scalar);                                                                                 \
        this->w op cast_to<T>(scalar);                                                                                 \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    template<typename T>                                                                                               \
    template<typename U>                                                                                               \
    NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator op(const vec1_t<U>& v)                                          \
        requires BothIntegral<T, U>                                                                                    \
    {                                                                                                                  \
        this->x op cast_to<T>(v.x);                                                                                    \
        this->y op cast_to<T>(v.x);                                                                                    \
        this->z op cast_to<T>(v.x);                                                                                    \
        this->w op cast_to<T>(v.x);                                                                                    \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    template<typename T>                                                                                               \
    template<typename U>                                                                                               \
    NOVA_FUNC constexpr vec4_t<T>& vec4_t<T>::operator op(const vec4_t<U>& v)                                          \
        requires BothIntegral<T, U>                                                                                    \
    {                                                                                                                  \
        this->x op cast_to<T>(v.x);                                                                                    \
        this->y op cast_to<T>(v.y);                                                                                    \
        this->z op cast_to<T>(v.y);                                                                                    \
        this->w op cast_to<T>(v.y);                                                                                    \
        return *this;                                                                                                  \
    }

DEFINE_VECTOR4_BIT_OP(%=)
DEFINE_VECTOR4_BIT_OP(&=)
DEFINE_VECTOR4_BIT_OP(|=)
DEFINE_VECTOR4_BIT_OP(^=)
DEFINE_VECTOR4_BIT_OP(<<=)
DEFINE_VECTOR4_BIT_OP(>>=)
#undef DEFINE_VECTOR4_BIT_OP

template<typename T> NOVA_FUNC constexpr vec4_t<T> operator+(const vec4_t<T>& v)
{
    return v;
}

template<typename T> NOVA_FUNC constexpr vec4_t<T> operator-(const vec4_t<T>& v)
{
    return vec4_t<T>(0) -= v;
}

template<IntegralType T> NOVA_FUNC constexpr vec4_t<T> operator~(const vec4_t<T>& v)
{
    return vec4_t<T>{~v.x, ~v.y, ~v.z, ~v.w};
}

template<typename T> NOVA_FUNC constexpr bool operator==(const vec4_t<T>& v1, const vec4_t<T>& v2)
{
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w;
}

template<typename T> NOVA_FUNC constexpr bool operator!=(const vec4_t<T>& v1, const vec4_t<T>& v2)
{
    return !(v1 == v2);
}

#define DEFINE_VECTOR4_BINARY_OP(ValType, opName, op)                                                                  \
    template<ValType T> NOVA_FUNC constexpr vec4_t<T> operator opName(const vec4_t<T>& v, T scalar)                    \
    {                                                                                                                  \
        return vec4_t<T>(v) op scalar;                                                                                 \
    }                                                                                                                  \
                                                                                                                       \
    template<ValType T> NOVA_FUNC constexpr vec4_t<T> operator opName(const vec4_t<T>& v1, const vec1_t<T>& v2)        \
    {                                                                                                                  \
        return vec4_t<T>(v1) op v2;                                                                                    \
    }                                                                                                                  \
                                                                                                                       \
    template<ValType T> NOVA_FUNC constexpr vec4_t<T> operator opName(T scalar, const vec4_t<T>& v)                    \
    {                                                                                                                  \
        return vec4_t<T>(v) op scalar;                                                                                 \
    }                                                                                                                  \
                                                                                                                       \
    template<ValType T> NOVA_FUNC constexpr vec4_t<T> operator opName(const vec1_t<T>& v1, const vec4_t<T>& v2)        \
    {                                                                                                                  \
        return vec4_t<T>(v2) op v1;                                                                                    \
    }                                                                                                                  \
                                                                                                                       \
    template<ValType T> NOVA_FUNC constexpr vec4_t<T> operator opName(const vec4_t<T>& v1, const vec4_t<T>& v2)        \
    {                                                                                                                  \
        return vec4_t<T>(v1) op v2;                                                                                    \
    }

DEFINE_VECTOR4_BINARY_OP(ArithmeticType, +, +=)
DEFINE_VECTOR4_BINARY_OP(ArithmeticType, -, -=)
DEFINE_VECTOR4_BINARY_OP(ArithmeticType, *, *=)
DEFINE_VECTOR4_BINARY_OP(ArithmeticType, /, /=)

DEFINE_VECTOR4_BINARY_OP(IntegralType, %, %=)
DEFINE_VECTOR4_BINARY_OP(IntegralType, &, &=)
DEFINE_VECTOR4_BINARY_OP(IntegralType, |, |=)
DEFINE_VECTOR4_BINARY_OP(IntegralType, ^, ^=)
DEFINE_VECTOR4_BINARY_OP(IntegralType, <<, <<=)
DEFINE_VECTOR4_BINARY_OP(IntegralType, >>, >>=)
#undef DEFINE_VECTOR4_BINARY_OP

NOVA_FUNC constexpr vec4_t<bool> operator&&(const vec4_t<bool>& v1, const vec4_t<bool>& v2)
{
    return {v1.x && v2.x, v1.y && v2.y, v1.z && v2.z, v1.w && v2.w};
}

NOVA_FUNC constexpr vec4_t<bool> operator||(const vec4_t<bool>& v1, const vec4_t<bool>& v2)
{
    return {v1.x || v2.x, v1.y || v2.y, v1.z || v2.z, v1.w || v2.w};
}

} //namespace nova