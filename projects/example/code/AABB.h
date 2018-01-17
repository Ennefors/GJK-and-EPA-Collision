//
// Created by bill on 15/11/17.
//

#ifndef GSCEPT_LAB_ENV_AABB_H
#define GSCEPT_LAB_ENV_AABB_H
#include "Plane.h"
#include <vector>
#include "core/app.h"

class AABB
{
public:

    fdVector max;
    fdVector min;
    fdVector pos;

    int owner;

    void drawAABB()
    {
        glLineWidth(2.5);

        glBegin(GL_LINES);
        glVertex3f(max[0] , max[1], max[2]);
        glVertex3f(max[0] , min[1], max[2]);

        glVertex3f(max[0] , min[1], max[2]);
        glVertex3f(min[0] , min[1], max[2]);

        glVertex3f(max[0] , min[1], max[2]);
        glVertex3f(max[0] , min[1], min[2]);

        glVertex3f(min[0] , min[1], max[2]);
        glVertex3f(min[0] , max[1], max[2]);

        glVertex3f(min[0] , min[1], max[2]);
        glVertex3f(min[0] , min[1], min[2]);

        glVertex3f(min[0] , max[1], max[2]);
        glVertex3f(max[0] , max[1], max[2]);

        glVertex3f(min[0] , max[1], max[2]);
        glVertex3f(min[0] , max[1], min[2]);

        glVertex3f(min[0] , max[1], min[2]);
        glVertex3f(max[0] , max[1], min[2]);

        glVertex3f(max[0] , max[1], max[2]);
        glVertex3f(max[0] , max[1], min[2]);

        glVertex3f(max[0] , max[1], min[2]);
        glVertex3f(max[0] , max[1], min[2]);

        glVertex3f(max[0] , max[1], min[2]);
        glVertex3f(max[0] , min[1], min[2]);

        glVertex3f(max[0] , min[1], min[2]);
        glVertex3f(min[0] , min[1], min[2]);

        glVertex3f(min[0] , min[1] , min[2]);
        glVertex3f(min[0] , max[1] , min[2]);

        glEnd();
    }

    inline void setupAABB(int o)
    {
        max = max + pos;
        min = min + pos;
        owner = o;
    };

};


#endif //GSCEPT_LAB_ENV_AABB_H
