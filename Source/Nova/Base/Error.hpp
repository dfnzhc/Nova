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
    AssertionError() noexcept { }

    AssertionError(std::string_view what) : Exception(what) { }

    AssertionError(const AssertionError& other) noexcept { _pWhat = other._pWhat; }

    virtual ~AssertionError() override { }
};

[[noreturn]] NOVA_API void ThrowException(const std::source_location& loc, std::string_view msg)
{
    std::string fullMsg  = std::format("{}\n\n{}:{} ({})", msg, loc.file_name(), loc.line(), loc.function_name());
    fullMsg             += std::format(
        "\n\nStacktrace:\nFile{}({}{}) '{}'", loc.file_name(), loc.line(), loc.column(), loc.function_name());

    throw RuntimeError(fullMsg);
}

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

#define NOVA_THROW(...) ::nova::internal::ThrowException(fstd::source_location::current(), __VA_ARGS__)

namespace nova {

template<typename CallbackT, typename ResultT = int>
int CatchAndReportAllExceptions(CallbackT callback, ResultT errorResult = 1)
{
    ResultT result = errorResult;
    try {
        result = callback();
    } catch (const std::exception& e) {
        LogError(std::string("发生异常:\n\n") + e.what());
    } catch (...) {
        LogError("未知异常发生");
    }
    return result;
}

} // namespace nova