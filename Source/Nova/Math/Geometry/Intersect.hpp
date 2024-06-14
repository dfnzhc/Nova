/**
 * @File intersect.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/2
 * @Brief 
 */

#pragma once

#include "../Vector.hpp"

namespace nova {

template<typename genType>
NOVA_FUNC bool IntersectRayPlane(const genType& orig,
                                 const genType& dir,
                                 const genType& planeOrig,
                                 const genType& planeNormal,
                                 typename genType::value_type& intersectionDistance)
{
    typename genType::value_type d       = Dot(dir, planeNormal);
    typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

    if (Abs(d) > Epsilon) // if dir and planeNormal are not perpendicular
    {
        const typename genType::value_type tmp_intersectionDistance = Dot(planeOrig - orig, planeNormal) / d;
        if (tmp_intersectionDistance > cast_to<typename genType::value_type>(0)) { // allow only intersections
            intersectionDistance = tmp_intersectionDistance;
            return true;
        }
    }

    return false;
}

template<typename T>
NOVA_FUNC bool IntersectRayTriangle(const vec3_t<T>& orig,
                                    const vec3_t<T>& dir,
                                    const vec3_t<T>& vert0,
                                    const vec3_t<T>& vert1,
                                    const vec3_t<T>& vert2,
                                    vec2_t<T>& baryPosition,
                                    T& distance)
{
    // find vectors for two edges sharing vert0
    const vec3_t<T> edge1 = vert1 - vert0;
    const vec3_t<T> edge2 = vert2 - vert0;

    // begin calculating Determinant - also used to calculate U parameter
    const vec3_t<T> p = Cross(dir, edge2);

    // if Determinant is near zero, ray lies in plane of triangle
    const T det = Dot(edge1, p);

    vec3_t<T> Perpendicular(0);

    if (det > cast_to<T>(0)) {
        // calculate Distance from vert0 to ray origin
        const vec3_t<T> dist = orig - vert0;

        // calculate U parameter and test bounds
        baryPosition.x = Dot(dist, p);
        if (baryPosition.x < cast_to<T>(0) || baryPosition.x > det)
            return false;

        // prepare to test V parameter
        Perpendicular = Cross(dist, edge1);

        // calculate V parameter and test bounds
        baryPosition.y = Dot(dir, Perpendicular);
        if ((baryPosition.y < cast_to<T>(0)) || ((baryPosition.x + baryPosition.y) > det))
            return false;
    }
    else if (det < cast_to<T>(0)) {
        // calculate Distance from vert0 to ray origin
        const vec3_t<T> dist = orig - vert0;

        // calculate U parameter and test bounds
        baryPosition.x = Dot(dist, p);
        if ((baryPosition.x > cast_to<T>(0)) || (baryPosition.x < det))
            return false;

        // prepare to test V parameter
        Perpendicular = Cross(dist, edge1);

        // calculate V parameter and test bounds
        baryPosition.y = Dot(dir, Perpendicular);
        if ((baryPosition.y > cast_to<T>(0)) || (baryPosition.x + baryPosition.y < det))
            return false;
    }
    else
        return false; // ray is parallel to the plane of the triangle

    T inv_det = cast_to<T>(1) / det;

    // calculate Distance, ray intersects triangle
    distance      = Dot(edge2, Perpendicular) * inv_det;
    baryPosition *= inv_det;

    return true;
}

template<typename genType>
NOVA_FUNC bool IntersectLineTriangle(const genType& orig,
                                     const genType& dir,
                                     const genType& vert0,
                                     const genType& vert1,
                                     const genType& vert2,
                                     genType& position)
{
    typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

    genType edge1 = vert1 - vert0;
    genType edge2 = vert2 - vert0;

    genType Perpendicular = Cross(dir, edge2);

    typename genType::value_type det = Dot(edge1, Perpendicular);

    if (det > -Epsilon && det < Epsilon)
        return false;
    typename genType::value_type inv_det = typename genType::value_type(1) / det;

    genType Tangent = orig - vert0;

    position.y = Dot(Tangent, Perpendicular) * inv_det;
    if (position.y < typename genType::value_type(0) || position.y > typename genType::value_type(1))
        return false;

    genType Cotangent = Cross(Tangent, edge1);

    position.z = Dot(dir, Cotangent) * inv_det;
    if (position.z < typename genType::value_type(0) || position.y + position.z > typename genType::value_type(1))
        return false;

    position.x = Dot(edge2, Cotangent) * inv_det;

    return true;
}

template<typename genType>
NOVA_FUNC bool IntersectRaySphere(const genType& rayStarting,
                                  const genType& rayNormalizedDirection,
                                  const genType& sphereCenter,
                                  const typename genType::value_type sphereRadiusSquared,
                                  typename genType::value_type& intersectionDistance)
{
    typename genType::value_type Epsilon  = std::numeric_limits<typename genType::value_type>::epsilon();
    genType diff                          = sphereCenter - rayStarting;
    typename genType::value_type t0       = Dot(diff, rayNormalizedDirection);
    typename genType::value_type dSquared = Dot(diff, diff) - t0 * t0;
    if (dSquared > sphereRadiusSquared) {
        return false;
    }
    typename genType::value_type t1 = Sqrt(sphereRadiusSquared - dSquared);
    intersectionDistance            = t0 > t1 + Epsilon ? t0 - t1 : t0 + t1;
    return intersectionDistance > Epsilon;
}

template<typename genType>
NOVA_FUNC bool IntersectRaySphere(const genType& rayStarting,
                                  const genType& rayNormalizedDirection,
                                  const genType& sphereCenter,
                                  const typename genType::value_type sphereRadius,
                                  genType& intersectionPosition,
                                  genType& intersectionNormal)
{
    typename genType::value_type distance;
    if (IntersectRaySphere(rayStarting, rayNormalizedDirection, sphereCenter, sphereRadius * sphereRadius, distance)) {
        intersectionPosition = rayStarting + rayNormalizedDirection * distance;
        intersectionNormal   = (intersectionPosition - sphereCenter) / sphereRadius;
        return true;
    }
    return false;
}

template<typename genType>
NOVA_FUNC bool IntersectLineSphere(const genType& point0,
                                   const genType& point1,
                                   const genType& sphereCenter,
                                   typename genType::value_type sphereRadius,
                                   genType& intersectionPoint1,
                                   genType& intersectionNormal1,
                                   genType& intersectionPoint2,
                                   genType& intersectionNormal2)
{
    typename genType::value_type Epsilon  = std::numeric_limits<typename genType::value_type>::epsilon();
    genType dir                           = Normalize(point1 - point0);
    genType diff                          = sphereCenter - point0;
    typename genType::value_type t0       = Dot(diff, dir);
    typename genType::value_type dSquared = Dot(diff, diff) - t0 * t0;
    if (dSquared > sphereRadius * sphereRadius) {
        return false;
    }
    typename genType::value_type t1 = Sqrt(sphereRadius * sphereRadius - dSquared);
    if (t0 < t1 + Epsilon)
        t1 = -t1;
    intersectionPoint1  = point0 + dir * (t0 - t1);
    intersectionNormal1 = (intersectionPoint1 - sphereCenter) / sphereRadius;
    intersectionPoint2  = point0 + dir * (t0 + t1);
    intersectionNormal2 = (intersectionPoint2 - sphereCenter) / sphereRadius;
    return true;
}

} // namespace nova