//
// Created by bill on 06/11/17.
//

#ifndef GSCEPT_LAB_ENV_PLANE_H
#define GSCEPT_LAB_ENV_PLANE_H

#include "tdMathLibNew.h"

struct plane
{
    fdVector point;
    fdVector upVec;
};

class Plane {
public:
    plane P;
    string id = "";
    inline fdVector getUpVec(){return P.upVec;};
    inline fdVector getPoint(){return P.point;};
    inline fdVector setUpVec(fdVector v){P.upVec = v;};
    inline fdVector setPoint(fdVector v){P.point = v;};

};


#endif //GSCEPT_LAB_ENV_PLANE_H
