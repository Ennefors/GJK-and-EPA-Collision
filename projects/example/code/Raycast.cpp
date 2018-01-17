//
// Created by bill on 06/11/17.
//

#include <vector>
#include "Raycast.h"


fdVector Raycast::checkIntersect(Plane P)
{
    float d = P.P.upVec.dot(this->direction);
    if (abs(d) > 0.0001f)
    {
        float t = (P.P.point - this->start).dot(P.P.upVec)/d;
        if ( t >= 0 )
        {
            return this->start + this->direction*t;

        };
    }
    return fdVector(0,0,0 ,9999);
}



fdVector Raycast::checkIntersect(AABB aabb)
{
    float tmin, tmax;

    fdVector dir = this->direction;

    float t1 = (aabb.min[0] - this->start[0])/dir[0];
    float t2 = (aabb.max[0] - this->start[0])/dir[0];

    tmin = min(t1, t2);
    tmax = max(t1, t2);

    for (int i = 1; i < 3; ++i) {
        t1 = (aabb.min[i] - this->start[i])/dir[i];
        t2 = (aabb.max[i] - this->start[i])/dir[i];

        tmin = max(tmin, min(t1, t2));
        tmax = min(tmax, max(t1, t2));
    }

    if (tmax > max(tmin, 0.f))
        return this->start + this->direction*tmin;
    return fdVector(0,0,0,9999);

};