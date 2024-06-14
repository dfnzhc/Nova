/**
 * @File type_hash.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/2
 * @Brief 
 */

#pragma once

#include "./vector.hpp"
#include "./matrix.hpp"
#include "./quaternion.hpp"
#include "./hash.hpp"

namespace std {

template<int L, typename T>
struct hash<::bee::vec<L, T>>
{
    constexpr uint32_t operator()(const ::bee::vec<L, T>& v) const
    {
        size_t result = 0;

        for (int i = 0; i < L; ++i)
            result ^= std::hash<T>()(v[i]) + 0x9e3779b9 + (result << 6) + (result >> 2);
        return static_cast<uint32_t>(result);
    }
};

template<typename T>
struct hash<::bee::quat<T>>
{
    constexpr uint32_t operator()(const ::bee::quat<T>& q) const
    {
        size_t result = 0;

        for (int i = 0; i < 4; ++i)
            result ^= std::hash<T>()(q[i]) + 0x9e3779b9 + (result << 6) + (result >> 2);
        return static_cast<uint32_t>(result);
    }
};

template<int C, int R, typename T>
struct hash<::bee::mat<C, R, T>>
{
    constexpr uint32_t operator()(const ::bee::mat<C, R, T>& m) const
    {
        size_t result = 0;

        for (int i = 0; i < C; ++i)
            result ^= std::hash<::bee::vec<C, T>>()(m[i]) + 0x9e3779b9 + (result << 6) + (result >> 2);
        return static_cast<uint32_t>(result);
    }
};

} // namespace std