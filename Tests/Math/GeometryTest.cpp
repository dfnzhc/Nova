/**
 * @File GeometryTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/11
 * @Brief 
 */

#include <gtest/gtest.h>

#include "Nova/nova.hpp"
using namespace nova;

class FrameTest : public ::testing::Test
{
protected:
    using vec_type = typename Frame<float>::vec_type; // 使用float类型作为示例
    Frame<float> frame;
    vec_type vec_x = {1.0f, 0.0f, 0.0f};
    vec_type vec_y = {0.0f, 1.0f, 0.0f};
    vec_type vec_z = {0.0f, 0.0f, 1.0f};

    vec_type vec_global = {1.0f, 2.0f, 3.0f};
    vec_type vec_local  = {1.0f, 2.0f, 3.0f};

    void SetUp() override { frame = Frame<float>(vec_x, vec_y, vec_z); }
};

// 测试Frame构造函数是否正确初始化
TEST_F(FrameTest, ConstructorInitialization)
{
    EXPECT_TRUE(Equal(frame.x, vec_x, 1e-7f));
    EXPECT_TRUE(Equal(frame.y, vec_y, 1e-7f));
    EXPECT_TRUE(Equal(frame.z, vec_z, 1e-7f));
}

// 测试toLocal方法是否正确转换坐标
TEST_F(FrameTest, toLocalConversion)
{
    vec_type vec_global = {1.0f, 1.0f, 1.0f}; // 任意全局坐标
    vec_type vec_local  = frame.toLocal(vec_global);
    // 预期结果是vec_global，因为frame是单位正交坐标系
    EXPECT_TRUE(Equal(vec_local, vec_global, 1e-7f));
}

// 测试fromLocal方法是否正确转换坐标
TEST_F(FrameTest, fromLocalConversion)
{
    vec_type vec_local  = {1.0f, 1.0f, 1.0f}; // 任意局部坐标
    vec_type vec_global = frame.fromLocal(vec_local);
    // 预期结果是vec_local，因为frame是单位正交坐标系
    EXPECT_TRUE(Equal(vec_global, vec_local, 1e-7f));
}

// 测试toLocal和fromLocal方法的一致性
TEST_F(FrameTest, ConversionConsistency)
{
    vec_type vec_original           = {2.0f, 3.0f, -1.0f};
    vec_type vec_converted_to_local = frame.toLocal(vec_original);
    vec_type vec_converted_back     = frame.fromLocal(vec_converted_to_local);
    EXPECT_TRUE(Equal(vec_original, vec_converted_back, 1e-7f));
}

// 测试边界条件，例如向量的分量接近0
TEST_F(FrameTest, BoundaryConditions)
{
    vec_type vec_near_zero = {1e-8f, 0.0f, 1e-8f};
    vec_type vec_local     = frame.toLocal(vec_near_zero);
    // 检查转换后的向量是否保持了正确的分量比例
    EXPECT_NEAR(vec_local.x / vec_near_zero.x, 1.0f, 1e-6);
    EXPECT_NEAR(vec_local.z / vec_near_zero.z, 1.0f, 1e-6);
}
