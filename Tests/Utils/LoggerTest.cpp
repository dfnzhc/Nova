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

    logInfo("Hello from info");
    logInfo("Hello from info: {} {} {}", a, b, c);

    logWarn("Hello from warn");
    logWarn("Hello from warn: {} {} {}", a, b, c);

    logE("Hello from error");
    logE("Hello from error: {} {} {}", a, b, c);

    logE("Hello from fatal");
    logF("Hello from fatal: {} {} {}", a, b, c);
}