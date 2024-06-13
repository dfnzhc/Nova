/**
 * @File LoggerTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/26
 * @Brief 
 */

#include <gtest/gtest.h>

#include <Nova/Utils/Logger.hpp>

using namespace nova;

TEST(UtilsTest, Logger)
{
    int a         = 1;
    float b       = 2.f;
    std::string c = "3.0";

    LogInfo("Hello from info");
    LogInfo("Hello from info: {} {} {}", a, b, c);

    LogWarn("Hello from warn");
    LogWarn("Hello from warn: {} {} {}", a, b, c);

    LogE("Hello from error");
    LogE("Hello from error: {} {} {}", a, b, c);

    LogE("Hello from fatal");
    LogF("Hello from fatal: {} {} {}", a, b, c);
}