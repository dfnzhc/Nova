/**
 * @File TransformTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/11
 * @Brief 
 */

#include <gtest/gtest.h>

#include <Nova/Nova.hpp>
using namespace nova;

// 测试 transform 类的默认构造函数
TEST(TransformTest, DefaultConstructor)
{
    transform<3, double> t;
    mat<3, 3, double> identity(1);
    EXPECT_TRUE(Equal(t.mat, identity, 1e-7));
    EXPECT_TRUE(Equal(t.inv, identity, 1e-7));
}

// 测试 transform 类的矩阵和逆矩阵构造函数
TEST(TransformTest, MatrixAndInverseConstructor)
{
    mat<3, 3, double> m = {
      {1, 2, 3},
      {0, 1, 4},
      {5, 6, 0}
    };

    EXPECT_TRUE(Determinant(m) > 0);

    mat<3, 3, double> inv = Inverse(m); // 假设已经实现了 Inverse 函数
    transform<3, double> t(m, inv);
    EXPECT_TRUE(Equal(t.mat, m, 1e-7));
    EXPECT_TRUE(Equal(t.inv, inv, 1e-7));
}

// 测试 transform 类的四元数构造函数
TEST(TransformTest, QuaternionConstructor)
{
    quat<double> q;                                  // 假设 q 是单位四元数
    transform<3, double> t(q);
    mat<3, 3, double> expected_matrix = Mat3Cast(q); // 假设已经实现了 Mat4Cast 函数
    EXPECT_TRUE(Equal(t.mat, expected_matrix));
    // 四元数构造的 transform 应该具有自身的逆矩阵
    mat<3, 3, double> expected_inverse_matrix = Inverse(expected_matrix); // 假设已经实现了 Inverse 函数
    EXPECT_TRUE(Equal(t.inv, expected_inverse_matrix, 1e-7));
}

// 测试 transform 类的向量变换方法
TEST(TransformTest, XformVector)
{
    transform<3, double> t;
    vec<2, double> v           = {1, 2};
    vec<2, double> transformed = t.xformVector(v);
    // 假设 t 是恒等变换，变换后的向量应该与原始向量相同
    EXPECT_TRUE(Equal(transformed, v, 1e-7));
}
