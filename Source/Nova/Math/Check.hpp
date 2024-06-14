/**
 * @File Check.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/27
 * @Brief 
 */

#pragma once

#include "./Math.hpp"
#include "../Utils/Assert.hpp"

namespace nova {

#ifdef NOVA_DEBUG_BUILD
#  include <cassert>
#  define NOVA_CHECK_IMPL(x)      DEBUG_ASSERT(x)
#  define NOVA_CHECK_OP(a, b, op) DEBUG_ASSERT((a)op(b))
#else
#  define NOVA_CHECK_IMPL(x)      /* ignore */
#  define NOVA_CHECK_OP(a, b, op) /* ignore */
#endif

#define NOVA_CHECK(x)       NOVA_CHECK_IMPL(x)
#define NOVA_CHECK_EQ(a, b) NOVA_CHECK_OP(a, b, ==)
#define NOVA_CHECK_NE(a, b) NOVA_CHECK_OP(a, b, !=)
#define NOVA_CHECK_GE(a, b) NOVA_CHECK_OP(a, b, >=)
#define NOVA_CHECK_GT(a, b) NOVA_CHECK_OP(a, b, >)
#define NOVA_CHECK_LE(a, b) NOVA_CHECK_OP(a, b, <=)
#define NOVA_CHECK_LT(a, b) NOVA_CHECK_OP(a, b, <)

} // namespace nova