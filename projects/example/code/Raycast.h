//
// Created by bill on 06/11/17.
//

#ifndef GSCEPT_LAB_ENV_RAYCAST_H
#define GSCEPT_LAB_ENV_RAYCAST_H



#include "AABB.h"

class Raycast {
public:
    fdVector start;
    fdVector direction;
    fdVector checkIntersect(Plane P);
    fdVector checkIntersect(AABB ab);

};


#endif //GSCEPT_LAB_ENV_RAYCAST_H
