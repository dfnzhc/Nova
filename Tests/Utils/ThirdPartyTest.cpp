/**
 * @File AssertTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/12
 * @Brief 
 */

#include <gtest/gtest.h>
#include "Nova/Nova.hpp"

//namespace libassert {
//
//void libassert_default_failure_handler(const assertion_info& info)
//{
//    libassert::enable_virtual_terminal_processing_if_needed(); // for terminal colors on windows
//    std::string message = info.to_string(libassert::terminal_width(libassert::stderr_fileno),
//                                         libassert::isatty(libassert::stderr_fileno) ? libassert::get_color_scheme()
//                                                                                     : libassert::color_scheme::blank);
//    std::cerr << "123abc321" << message << std::endl;
//    switch (info.type) {
//    case libassert::assert_type::assertion :
//    case libassert::assert_type::debug_assertion :
//    case libassert::assert_type::assumption :
//    case libassert::assert_type::panic :
//    case libassert::assert_type::unreachable :
//        (void)fflush(stderr);
//        // Breaking here as debug CRT allows aborts to be ignored, if someone wants to make a
//        // debug build of this library
//        break;
//    default : std::cerr << "Critical error: Unknown libassert::assert_type" << std::endl;
//    }
//}
//
//} // namespace libassert
//
//TEST(Assert, CustomHandle) {
// libassert::set_failure_handler(libassert::libassert_default_failure_handler);
// }

TEST(Assert, AssertTest1)
{
    std::map<std::string, int> map;
    map.emplace("hello", 1);
    DEBUG_ASSERT(map.contains("foo"), "expected key not found", map);
}

TEST(Assert, AssertTest2)
{
    std::optional<float> get_param{};
    ASSERT(get_param);
}

TEST(Assert, Assume)
{
    std::optional<float> get_param{4.2f};
    ASSUME(get_param);
}

TEST(Taskflow, Basic)
{
    tf::Executor executor;
    tf::Taskflow taskflow;

    auto [A, B, C, D] = taskflow.emplace( // create four tasks
        []() { std::cout << "TaskA\n"; },
        []() { std::cout << "TaskB\n"; },
        []() { std::cout << "TaskC\n"; },
        []() { std::cout << "TaskD\n"; });

    A.precede(B, C); // A runs before B and C
    D.succeed(B, C); // D runs after  B and C

    executor.run(taskflow).wait();
}

//TEST(Assert, Panic)
//{
//    int a = 1;
//    PANIC(a != 2, "a must equal two", a);
//}
//
//TEST(Assert, Unreachable)
//{
//    int a = 1;
//    UNREACHABLE("You shall not pass");
//}
