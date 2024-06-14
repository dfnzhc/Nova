/**
 * @File Triangle.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/1
 * @Brief 
 */

#pragma once

#include "../Vector.hpp"

namespace nova {

class Triangulate
{
public:
    template<typename T>
    NOVA_FUNC vec3_t<T> ComputeNormal(const vec3_t<T>& p1, const vec3_t<T>& p2, const vec3_t<T>& p3)
    {
        return Normalize(Cross(p1 - p2, p1 - p3));
    }

    // TODO: CheckInside, ComputeArea
};

} // namespace nova
