/**
 * @File ConstantTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/10
 * @Brief 
 */

#include <gtest/gtest.h>

#include "Nova/Nova.hpp"
using namespace nova;

TEST(PowTest, PositiveExponent)
{
    double base  = 2.0;
    int exponent = 3;
    EXPECT_DOUBLE_EQ(std::pow(base, exponent), Pow<3>(base));
}

TEST(PowTest, ZeroExponent)
{
    double base = 5.0;
    EXPECT_DOUBLE_EQ(1.0, Pow<0>(base)); // Any number to the power of 0 is 1
}

TEST(PowTest, OneExponent)
{
    double base = 7.0;
    EXPECT_DOUBLE_EQ(base, Pow<1>(base)); // Any number to the power of 1 is itself
}

TEST(PowTest, NegativeExponent)
{
    double base  = 5.0;
    int exponent = -2;
    EXPECT_DOUBLE_EQ(1 / (base * base), Pow<-2>(base)); // Reciprocal of the square
}
