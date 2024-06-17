/**
 * @File Error.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/15
 * @Brief This file is part of Nova.
 */

#pragma once

#include <format>
#include <exception>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include <source_location>
#include <stacktrace>
#include "./Enums.hpp"
#include "./Utils/Logger.hpp"

namespace nova {

#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable:4'275) // allow dllexport on classes dervied from STL
#endif

class NOVA_API Exception : public std::exception
{
public:
    Exception() noexcept = default;

    explicit Exception(std::string_view what) : _pWhat(std::make_shared<std::string>(what)) { }

    Exception(const Exception& other) noexcept : exception(other) { _pWhat = other._pWhat; }

    ~Exception() override = default;

    Exception& operator=(const Exception&) = delete;

    const char* what() const noexcept override { return _pWhat ? _pWhat->c_str() : ""; }

protected:
    std::shared_ptr<std::string> _pWhat;
};

#ifdef _MSC_VER
#  pragma warning(pop)
#endif

class NOVA_API RuntimeError : public Exception
{
public:
    RuntimeError() noexcept = default;

    explicit RuntimeError(std::string_view what) : Exception(what) { }

    RuntimeError(const RuntimeError& other) noexcept : Exception(other) { _pWhat = other._pWhat; }

    ~RuntimeError() override = default;
};

class NOVA_API AssertionError : public Exception
{
public:
    AssertionError() noexcept = default;

    explicit AssertionError(std::string_view what) : Exception(what) { }

    AssertionError(const AssertionError& other) noexcept : Exception(other) { _pWhat = other._pWhat; }

    ~AssertionError() override = default;
};

[[noreturn]] NOVA_API void ThrowException(const std::source_location& loc, std::string_view msg);

namespace internal {

[[noreturn]] inline void ThrowException(const std::source_location& loc, std::string_view msg)
{
    ::nova::ThrowException(loc, msg);
}

template<typename... Args>
[[noreturn]] inline void
ThrowException(const std::source_location& loc, std::format_string<Args...> fmt, Args&&... args)
{
    ::nova::ThrowException(loc, std::format(fmt, std::forward<Args>(args)...));
}
} // namespace internal
} // namespace nova

#define NOVA_THROW(...) ::nova::internal::ThrowException(std::source_location::current(), __VA_ARGS__)

#define NOVA_CONFIRM(cond, ...)                                                                                        \
    do {                                                                                                               \
        if (!(cond))                                                                                                   \
            NOVA_THROW(__VA_ARGS__);                                                                                   \
    } while (0)

#define NOVA_UNIMPLEMENTED() NOVA_THROW("还未实现的部分")

#define NOVA_UNREACHABLE() NOVA_THROW("You shall not PASS!!!")

namespace nova {

[[noreturn]] NOVA_API void
ReportAssertion(const std::source_location& loc, std::string_view cond, std::string_view msg = {});

namespace internal {

[[noreturn]] inline void ReportAssertion(const std::source_location& loc, std::string_view cond)
{
    ::nova::ReportAssertion(loc, cond);
}

[[noreturn]] inline void ReportAssertion(const std::source_location& loc, std::string_view cond, std::string_view msg)
{
    ::nova::ReportAssertion(loc, cond, msg);
}

template<typename... Args>
[[noreturn]] inline void
ReportAssertion(const std::source_location& loc, std::string_view cond, std::format_string<Args...> fmt, Args&&... args)
{
    ::nova::ReportAssertion(loc, cond, std::format(fmt, std::forward<Args>(args)...));
}
} // namespace internal
} // namespace nova

#ifdef NOVA_ENABLE_ASSERTS

#  define NOVA_ASSERT(cond, ...)                                                                                       \
      do {                                                                                                             \
          if (!(cond)) {                                                                                               \
              ::nova::internal::ReportAssertion(std::source_location::current(), #cond, __VA_ARGS__);                \
          }                                                                                                            \
      } while (0)

#  define NOVA_ASSERT_OP(a, b, OP)                                                                                     \
      do {                                                                                                             \
          if (!(a OP b)) {                                                                                             \
              ::nova::internal::ReportAssertion(std::source_location::current(),                                       \
                                                std::format("{} {} {} ({} {} {})", #a, #OP, #b, a, #OP, b));           \
          }                                                                                                            \
      } while (0)

#  define NOVA_ASSERT_EQ(a, b) NOVA_ASSERT_OP(a, b, ==)
#  define NOVA_ASSERT_NE(a, b) NOVA_ASSERT_OP(a, b, !=)
#  define NOVA_ASSERT_GE(a, b) NOVA_ASSERT_OP(a, b, >=)
#  define NOVA_ASSERT_GT(a, b) NOVA_ASSERT_OP(a, b, >)
#  define NOVA_ASSERT_LE(a, b) NOVA_ASSERT_OP(a, b, <=)
#  define NOVA_ASSERT_LT(a, b) NOVA_ASSERT_OP(a, b, <)

#else // NOVA_ENABLE_ASSERTS

#  define NOVA_ASSERT(cond, ...)                                                                                       \
      do {                                                                                                             \
          {                                                                                                            \
          }                                                                                                            \
      } while (0)
#  define NOVA_ASSERT_OP(a, b, OP)                                                                                     \
      do {                                                                                                             \
          {                                                                                                            \
          }                                                                                                            \
      } while (0)
#  define NOVA_ASSERT_EQ(a, b) NOVA_ASSERT_OP(a, b, ==)
#  define NOVA_ASSERT_NE(a, b) NOVA_ASSERT_OP(a, b, !=)
#  define NOVA_ASSERT_GE(a, b) NOVA_ASSERT_OP(a, b, >=)
#  define NOVA_ASSERT_GT(a, b) NOVA_ASSERT_OP(a, b, >)
#  define NOVA_ASSERT_LE(a, b) NOVA_ASSERT_OP(a, b, <=)
#  define NOVA_ASSERT_LT(a, b) NOVA_ASSERT_OP(a, b, <)

#endif // NOVA_ENABLE_ASSERTS

namespace nova {

template<typename CallbackT, typename ResultT = int>
inline int CatchAndReportAllExceptions(CallbackT callback, ResultT errorResult = 1)
{
    ResultT result = errorResult;
    try {
        result = callback();
    } catch (const AssertionError& e) {
        LogError(std::string("断言错误:\n\n") + e.what());
    } catch (const std::exception& e) {
        LogFatal(std::string("发生异常:\n\n") + e.what());
    } catch (...) {
        LogFatal("未知异常发生");
    }
    return result;
}

} // namespace nova