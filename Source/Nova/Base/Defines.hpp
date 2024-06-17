/**
 * @File Defines.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/26
 * @Brief 
 */

#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#  define NOVA_IN_WINDOWS
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
#  define NOVA_IN_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#  define NOVA_IN_MAC
#else
#  error Unsupport Platform
#endif

#if defined(_MSC_VER)
#  define NOVA_CPLUSPLUS _MSVC_LANG
#else
#  define NOVA_CPLUSPLUS __cplusplus
#endif

static_assert(NOVA_CPLUSPLUS >= 202'002L, "__cplusplus >= 202002L: C++20 at least");

// noinline
#ifdef _MSC_VER
#  define NOVA_NOINLINE __declspec(noinline)
#elif defined(__GNUC__)
#  define NOVA_NOINLINE __attribute__((__noinline__))
#else
#  define NOVA_NOINLINE
#endif

// always inline
#ifdef _MSC_VER
#  define NOVA_ALWAYS_INLINE __forceinline
#elif defined(__GNUC__)
#  define NOVA_ALWAYS_INLINE inline __attribute__((__always_inline__))
#else
#  define NOVA_ALWAYS_INLINE inline
#endif

#define NOVA_NODISCARD       [[nodiscard]]
#define NOVA_DEPRECATED(...) [[deprecated(__VA_ARGS__)]]

// Debug & Release
namespace nova {
#ifdef NDEBUG
constexpr auto kIsDebug   = false;
constexpr auto kIsRelease = true;
#  define NOVA_RELEASE_BUILD
#else
constexpr auto kIsDebug   = true;
constexpr auto kIsRelease = false;
#  define NOVA_DEBUG_BUILD
#  define NOVA_ENABLE_ASSERTS
#endif
} // namespace nova

#include <cstdint>
#include <cstddef>

// -------------------------
//关于平台、编译器、语言的宏定义

#if defined(_MSC_VER)
#  define NOVA_API_EXPORT __declspec(dllexport)
#  define NOVA_API_IMPORT __declspec(dllimport)
#elif defined(__clang__) || defined(__GNUC__)
#  define NOVA_API_EXPORT __attribute__((visibility("default")))
#  define NOVA_API_IMPORT __attribute__((visibility("default")))
#else
#  define NOVA_API_EXPORT
#  define NOVA_API_IMPORT
#endif

#ifdef NOVA_DLL
#  define NOVA_API NOVA_API_EXPORT
#else  // NOVA_DLL
#  define NOVA_API NOVA_API_IMPORT
#endif // NOVA_DLL

// -------------------------
// 关于 Cuda、Optix 的宏定义

#if defined(__CUDA_ARCH__) || defined(__CUDACC__)
#  ifndef NOVA_NOINLINE
#    define NOVA_NOINLINE __attribute__((noinline))
#  endif
#  ifndef NOVA_GPU_CODE
#    define NOVA_GPU_CODE
#  endif
#  define NOVA_GPU               __device__
#  define NOVA_CPU               __host__
#  define NOVA_INLINE            __forceinline__
#  define NOVA_CONST             __device__ const
#  define CONST_STATIC_INIT(...) /* ignore */
#else
#  ifndef NOVA_HOST_CODE
#    define NOVA_HOST_CODE
#  endif
#  define NOVA_GPU               /* ignore */
#  define NOVA_CPU               /* ignore */
#  define NOVA_CONST             const
#  define NOVA_INLINE            inline
#  define CONST_STATIC_INIT(...) = __VA_ARGS__
#endif

#define NOVA_CPU_GPU NOVA_CPU NOVA_GPU
#define NOVA_FUNC    NOVA_INLINE
#define NOVA_FUNC_DECL

namespace nova {
// -------------------------
// 内置类型、常量别名

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8   = uint8_t;
using u16  = uint16_t;
using u32  = uint32_t;
using u64  = uint64_t;
using uint = unsigned int;

using f32 = float;
using f64 = double;

using size = std::size_t;

static constexpr i8 i8_min   = INT8_MIN;
static constexpr i16 i16_min = INT16_MIN;
static constexpr i32 i32_min = INT32_MIN;
static constexpr i64 i64_min = INT64_MIN;

static constexpr i8 i8_max   = INT8_MAX;
static constexpr i16 i16_max = INT16_MAX;
static constexpr i32 i32_max = INT32_MAX;
static constexpr i64 i64_max = INT64_MAX;

static constexpr u8 u8_max   = UINT8_MAX;
static constexpr u16 u16_max = UINT16_MAX;
static constexpr u32 u32_max = UINT32_MAX;
static constexpr u64 u64_max = UINT64_MAX;

#ifdef NOVA_FLOAT_AS_DOUBLE
using Float     = f64;
using FloatBits = u64;
#else
using Float     = f32;
using FloatBits = u32;
#endif

static_assert(sizeof(Float) == sizeof(FloatBits));

} // namespace nova
