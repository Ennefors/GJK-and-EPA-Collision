//
// Created by bill on 06/12/17.
//

#ifndef GSCEPT_LAB_ENV_PLANESWEEP_H
#define GSCEPT_LAB_ENV_PLANESWEEP_H

#endif //GSCEPT_LAB_ENV_PLANESWEEP_H

#include "tdMathLibNew.h"
#include "GraphicsNode.h"
#include "map"


struct triangle
{
    fdVector points[3];
    fdVector norm;
    triangle(fdVector pa, fdVector pb, fdVector pc)
    {
        points[0] = pa;
        points[1] = pb;
        points[2] = pc;
        norm = (pb - pa).Cross(pc - pa).normalize();
    }
};

struct edge
{
    fdVector points[2];

    edge(fdVector pa, fdVector pb)
    {
        points[0] = pa;
        points[1] = pb;
    }
};

struct collision
{
    int ID1;
    int ID2;
    collision(int i, int j)
    {
        ID1 = i;
        ID2 = j;
    }
};

struct floatP
{
    float point;
    int ID;
    bool check; //Min = False, Max = True//
    floatP(float p, int i, bool c)
    {
        point = p;
        ID = i;
        check = c;
    }
    void operator= (floatP p)
    {
        this->point = p.point;
        this->ID = p.ID;
        this->check = p.check;
    }
};

struct potCol
{
    int low;
    int high;

    potCol(int a, int b)
    {
        if (a < b)
        {
            this->low = a;
            this->high = b;
        }
        else
        {
            this->low = b;
            this->high = a;
        }
    }
};

struct ComparePColl
{
    bool operator() (const potCol &x, const potCol &y) const {
        return x.low < y.low || (x.low == y.low && x.high < y.high);
    }
};

struct ComparefPColl
{
    bool operator() (const floatP &x, const floatP &y) const {
        return x.point < y.point;
    }
};

vector<collision> LinearSweep(vector<AABB*> aabbList);
bool GJK(GraphicsNode& shape1, GraphicsNode& shape2, fdVector& colNormal, fdVector& colPos, float& colDepth);