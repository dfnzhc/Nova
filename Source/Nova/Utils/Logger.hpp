/**
 * @File Logger.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/13
 * @Brief 
 */
#pragma once

#include <functional>
#include <string>
#include <format>
#include <source_location>
#include <mutex>

#include "Nova/Base/Defines.hpp"

namespace nova {
using LogNotifyType = std::function<void(const std::string&)>;

class NOVA_API Logger
{
public:
    /// 日志等级
    enum class Level
    {
        Fatal,
        Error,
        Warning,
        Info,
    };

    static Logger& inst()
    {
        static Logger logger;
        return logger;
    }

    void log(Level level, std::string_view msg);

    void setLevel(Level level);
    Level level();

    void subscribe(std::string_view name, LogNotifyType&& notify);
    void unsubscribe(std::string_view name);

private:
    Logger()  = default;
    ~Logger() = default;

    std::mutex _mutex;

    Logger::Level _level = Logger::Level::Info;
    std::unordered_map<std::string_view, LogNotifyType> _subscribers;
};

inline auto operator<=>(Logger::Level lhs, Logger::Level rhs)
{
    return static_cast<std::underlying_type_t<Logger::Level>>(lhs) <=>
           static_cast<std::underlying_type_t<Logger::Level>>(rhs);
}

// @formatter:off

inline void logInfo(std::string_view msg) { Logger::inst().log(Logger::Level::Info, msg); }

template<typename... Args> inline void logInfo(std::format_string<Args...> format, Args&&... args)
{
    Logger::inst().log(Logger::Level::Info, std::format(format, std::forward<Args>(args)...));
}

inline void logWarn(std::string_view msg) { Logger::inst().log(Logger::Level::Warning, msg); }

template<typename... Args> inline void logWarn(std::format_string<Args...> format, Args&&... args)
{
    Logger::inst().log(Logger::Level::Warning, std::format(format, std::forward<Args>(args)...));
}

void NOVA_API logError(std::string_view msg, std::source_location sl = std::source_location::current());

void NOVA_API logFatal(std::string_view msg, std::source_location sl = std::source_location::current());

#define logE(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        auto loc = std::source_location::current();                                                                    \
        logError(std::format(fmt, __VA_ARGS__), loc);                                                                  \
    } while (0)

#define logF(fmt, ...)                                                                                                 \
    do {                                                                                                               \
        auto loc = std::source_location::current();                                                                    \
        logFatal(std::format(fmt, __VA_ARGS__), loc);                                                                  \
    } while (0)

// @formatter:on
} // namespace nova

#define NOVA_PRINT(x)                                                                                                  \
    do {                                                                                                               \
        ::nova::logInfo("{} = {}", #x, x);                                                                             \
    } while (0)
