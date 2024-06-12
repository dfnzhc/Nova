/**
 * @File Assert.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/12
 * @Brief 
 */

#pragma once

#include <libassert/assert.hpp>
#include <libassert/expression-decomposition.hpp>
#include <libassert/platform.hpp>
#include <libassert/stringification.hpp>
#include <libassert/utilities.hpp>
#include <libassert/assert-gtest.hpp>

//template<> struct libassert::stringifier<MyObject> {
//    std::string stringify(const MyObject& type) {
//        return ...;
//    }
//};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
namespace libassert {
[[noreturn]] void set_failure_handler(const assertion_info& info)
{
    libassert::enable_virtual_terminal_processing_if_needed(); // for terminal colors on windows
    std::string message = info.to_string(libassert::terminal_width(libassert::stderr_fileno),
                                         libassert::isatty(libassert::stderr_fileno) ? libassert::get_color_scheme()
                                                                                     : libassert::color_scheme::blank);
    std::cerr << "123" << message << std::endl;
    switch (info.type) {
    case libassert::assert_type::assertion :
    case libassert::assert_type::debug_assertion :
    case libassert::assert_type::assumption :
    case libassert::assert_type::panic :
    case libassert::assert_type::unreachable :
        (void)fflush(stderr);
        std::abort();
        // Breaking here as debug CRT allows aborts to be ignored, if someone wants to make a
        // debug build of this library
        break;
    default : std::cerr << "Critical error: Unknown libassert::assert_type" << std::endl; std::abort();
    }
}

} // namespace libassert

#pragma clang diagnostic pop