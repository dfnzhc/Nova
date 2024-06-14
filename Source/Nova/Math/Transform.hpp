/**
 * @File Transform.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/14
 * @Brief This file is part of Nova.
 */

#pragma once

#include "./Matrix.hpp"
#include "./Vector.hpp"
#include "./Quaternion.hpp"

namespace nova {

template<i32 D, typename T> class transform
{
public:
    using VectorType    = vec<D - 1, T>;
    using MatVectorType = vec<D, T>;
    using MatrixType    = mat<D, D, T>;

    MatrixType mat = MatrixType(One<T>());
    MatrixType inv = MatrixType(One<T>());

    NOVA_FUNC_DECL constexpr transform()                         = default;
    NOVA_FUNC_DECL constexpr transform(const transform<D, T>& t) = default;

    NOVA_FUNC_DECL constexpr transform(const MatrixType& m, const MatrixType& i) : mat(m), inv(i) { }

    // clang-format off
    NOVA_FUNC_DECL constexpr explicit transform(const quat<T>& q) : mat(Mat4Cast(q)) { inv = Inverse(mat); }

    NOVA_FUNC_DECL constexpr transform(const VectorType& o, const VectorType& v1, const VectorType& v2) requires(D == 3);
    NOVA_FUNC_DECL constexpr transform(const VectorType& o, const VectorType& v1, const VectorType& v2, const VectorType& v3) requires(D == 4);

    template<typename U>
    NOVA_FUNC_DECL constexpr explicit transform(const transform<D, U>& t) : mat(t.mat), inv(t.inv) {}
    
    NOVA_FUNC_DECL transform operator*(const transform& t) const { return {mat * t.mat, t.inv * inv}; }
    
    NOVA_FUNC_DECL constexpr bool operator==(const transform& t) const { return t.mat == mat; }
    NOVA_FUNC_DECL constexpr bool operator!=(const transform& t) const { return t.mat != mat; }
    NOVA_FUNC_DECL constexpr bool isIdentity() const { return nova::isIdentity(mat); }

    NOVA_FUNC_DECL VectorType xformVector(const VectorType& v) const { return FromVector(mat * MatVectorType(v, Zero<T>())); }
    NOVA_FUNC_DECL VectorType xformPoint(const VectorType& p)  const { return FromPoint(MatVectorType(mat * MatVectorType(p, One<T>()))); }
    NOVA_FUNC_DECL VectorType xformNormal(const VectorType& n) const { return Normalize(FromVector(MatVectorType(Transpose(inv) * MatVectorType(n, Zero<T>())))); }

    // clang-format on
};

template<i32 D, typename T>
constexpr transform<D, T>::transform(const transform::VectorType& o,
                                     const transform::VectorType& v1,
                                     const transform::VectorType& v2)
    requires(D == 3)
{
    mat = mat3x3_t<T>(transform::MatVectorType(v1, Zero<T>()),
                      transform::MatVectorType(v2, Zero<T>()),
                      transform::MatVectorType(o, One<T>()));

    inv = Inverse(mat);
}

template<i32 D, typename T>
constexpr transform<D, T>::transform(const transform::VectorType& o,
                                     const transform::VectorType& v1,
                                     const transform::VectorType& v2,
                                     const transform::VectorType& v3)
    requires(D == 4)
{
    mat = mat4x4_t<T>(transform::MatVectorType(v1, Zero<T>()),
                      transform::MatVectorType(v2, Zero<T>()),
                      transform::MatVectorType(v3, Zero<T>()),
                      transform::MatVectorType(o, One<T>()));

    inv = Inverse(mat);
}

} // namespace nova