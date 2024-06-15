/**
 * @File ClassModifier.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/15
 * @Brief This file is part of Nova.
 */

#pragma once

namespace nova {

struct NoCopy
{
    NoCopy() = default;

    NoCopy& operator=(const NoCopy&) = delete;
    NoCopy(const NoCopy&) = delete;

protected:
    ~NoCopy() = default;
};

struct NoMove
{
    NoMove() = default;

    NoMove& operator=(NoMove&&) = delete;
    NoMove(const NoMove&&) = delete;

protected:
    ~NoMove() = default;
};

} // namespace nova