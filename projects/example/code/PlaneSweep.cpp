//
// Created by bill on 06/12/17.
//

#include <set>
#include "PlaneSweep.h"



vector<collision> LinearSweep(vector<AABB*> aabbList)
{

    std::multiset<floatP, ComparefPColl> queueX = std::multiset<floatP, ComparefPColl>();
    std::multiset<floatP, ComparefPColl> queueY = std::multiset<floatP, ComparefPColl>();
    std::multiset<floatP, ComparefPColl> queueZ = std::multiset<floatP, ComparefPColl>();
    std::multiset<floatP, ComparefPColl>::iterator it;

    for (int i = 0; i < aabbList.size(); i++)
    {
        AABB aabb = *aabbList[i];

        queueX.insert(floatP(aabb.min[0], i, false));
        queueX.insert(floatP(aabb.max[0], i, true));

        queueY.insert(floatP(aabb.min[1], i, false));
        queueY.insert(floatP(aabb.max[1], i, true));

        queueZ.insert(floatP(aabb.min[2], i, false));
        queueZ.insert(floatP(aabb.max[2], i, true));
    }

    std::set<potCol, ComparePColl> collisions = std::set<potCol, ComparePColl>();
    std::set<potCol, ComparePColl> pColl = std::set<potCol, ComparePColl>();
    std::set<potCol, ComparePColl>::iterator itColl;

    std::set<int> candidates = std::set<int>();
    std::set<int>::iterator itCandid;

    for (it = queueX.begin(); it != queueX.end(); ++it)
    {
        floatP f = *it;
        if (!f.check)
        {
            for (itCandid = candidates.begin(); itCandid != candidates.end(); ++itCandid)
            {
                collisions.insert(potCol(f.ID, *itCandid));
            }
            candidates.insert(f.ID);
        }
        else
        {
            candidates.erase(f.ID);
        }
    }

    for (it = queueY.begin(); it != queueY.end(); ++it)
    {
        floatP f = *it;
        if (!f.check)
        {
            for (itCandid = candidates.begin(); itCandid != candidates.end(); ++itCandid)
            {
                potCol p = potCol(f.ID, *itCandid);
                if (collisions.find(p) != collisions.end())
                    pColl.insert(p);
            }
            candidates.insert(f.ID);
        }
        else
        {
            candidates.erase(f.ID);
        }
    }
    collisions = pColl;
    pColl.clear();

    for (it = queueZ.begin(); it != queueZ.end(); ++it)
    {
        floatP f = *it;
        if (!f.check)
        {
            for (itCandid = candidates.begin(); itCandid != candidates.end(); ++itCandid)
            {
                potCol p = potCol(f.ID, *itCandid);
                if (collisions.find(p) != collisions.end())
                    pColl.insert(p);
            }
            candidates.insert(f.ID);
        }
        else
        {
            candidates.erase(f.ID);
        }
    }
    collisions = pColl;
    std::vector<collision> result = std::vector<collision>();
    for (itColl = collisions.begin(); itColl != collisions.end(); ++itColl)
    {
        collision c = collision(itColl->low, itColl->high);
        result.push_back(c);
    }


    return result;
};




fdVector supportFunc(GraphicsNode& shape1, GraphicsNode& shape2, fdVector d)
{
    fdVector p1 = shape1.getMesh()->getFarthestPointInDirection(d);
    fdVector p2 = shape2.getMesh()->getFarthestPointInDirection(d*-1);

    fdVector p3 = p1 - p2;

    return p3;
};

bool simplex(vector<fdVector>& simplexShape, fdVector& d)
{
    fdVector AO;
    fdVector AB;
    fdVector AC;
    fdVector AD;

    fdVector ABperp;
    fdVector ACperp;

    fdVector ABCperp;
    fdVector ACDperp;
    fdVector ADBperp;

    int size = simplexShape.size();
    if (size == 2)
    {
        d = ((simplexShape[0] - simplexShape[1]).Cross(simplexShape[1] * -1)).Cross(simplexShape[0] - simplexShape[1]);
    }
    else if (size == 3)
    {
        AO = simplexShape[2] * -1;
        AB = simplexShape[1] - simplexShape[2];
        AC = simplexShape[0] - simplexShape[2];

        ABperp = AC.Cross(AB).Cross(AB);
        if (AO * ABperp > 0)
        {
            d = AB.Cross(AO).Cross(AB);
            simplexShape.erase(simplexShape.begin()+0);
        }else{
            ACperp = AB.Cross(AC).Cross(AC);
            if (AO * ACperp > 0)
            {
                d = AC.Cross(AO).Cross(AC);
                simplexShape.erase(simplexShape.begin()+1);
            }else{
                ABCperp = AC.Cross(AB);
                if (AO * ABCperp > 0)
                {
                    d = ABCperp;
                }
                else
                {
                    d = ABCperp * -1;
                    fdVector temp = simplexShape[1];
                    simplexShape[1] = simplexShape[2];
                    simplexShape[2] = temp;
                }
            }
        }
    }
    else
    {
        AO = simplexShape[3] * -1;
        AB = simplexShape[2] - simplexShape[3];
        AC = simplexShape[1] - simplexShape[3];
        AD = simplexShape[0] - simplexShape[3];

        ABCperp = AC.Cross(AB);
        if (AO * ABCperp > 0)
        {
            d = ABCperp;
            simplexShape.erase(simplexShape.begin()+0);
        }
        else
        {
            ACDperp = AD.Cross(AC);
            if (AO * ACDperp > 0)
            {
                d = ACDperp;
                simplexShape.erase(simplexShape.begin()+2);
            }
            else{
                ADBperp = AB.Cross(AD);
                if (AO * ADBperp > 0)
                {
                    d = ADBperp;
                    simplexShape.erase(simplexShape.begin()+1);
                    fdVector temp = simplexShape[1];
                    simplexShape[1] = simplexShape[2];
                    simplexShape[2] = temp;

                } else{
                    return true;
                }
            }
        }
    }
    return false;
};

void barycentric(fdVector &p,fdVector &a,fdVector &b,fdVector &c,float *x,float *y,float *z) {
    fdVector v0 = b - a;
    fdVector v1 = c - a;
    fdVector v2 = p - a;
    float d00 = v0*v0;
    float d01 = v0*v1;
    float d11 = v1*v1;
    float d20 = v2*v0;
    float d21 = v2*v1;
    float d = d00 * d11 - d01 * d01;
    *y = (d11 * d20 - d01 * d21) / d;
    *z = (d00 * d21 - d01 * d20) / d;
    *x = 1.0f - *y - *z;
}

bool EPA(GraphicsNode& shape1, GraphicsNode& shape2, vector<fdVector> simplexShape, fdVector &colNorm, fdVector& colPos, float &colDepth) {
    vector<triangle> triangles;
    vector<edge> edges;

    float thold = 0.0001f;

    triangles.push_back(triangle(simplexShape[2], simplexShape[1], simplexShape[0]));
    triangles.push_back(triangle(simplexShape[3], simplexShape[2], simplexShape[0]));
    triangles.push_back(triangle(simplexShape[3], simplexShape[1], simplexShape[2]));
    triangles.push_back(triangle(simplexShape[3], simplexShape[0], simplexShape[1]));

    auto addEdge = [&](fdVector &a, fdVector &b) -> void
    {
        for (auto it = edges.begin(); it != edges.end() ;++it) {
            edge e = *it;
            if (e.points[0] == b && e.points[1] == a)
            {
                edges.erase(it);
                return;
            }
        }

        edges.push_back(edge(a,b));
    };
    fdVector AO = simplexShape[3];
    while(true) {
        float s = 9999999;
        int triID = 0;

        for (int i = 0; i < triangles.size(); ++i) {
            float l = fabs(triangles[i].norm * triangles[i].points[0]);
            if (l < s) {
                s = l;
                triID = i;
            }
        }

        fdVector v = supportFunc(shape1, shape2, triangles[triID].norm);
        if ((triangles[triID].norm*v - s) < thold)
        {
            colNorm = triangles[triID].norm;
            colDepth = (triangles[triID].norm * triangles[triID].points[0])/2;
            fdVector shit = (triangles[triID].norm * colDepth);
            float bx, by, bz;
            barycentric(shit,  triangles[triID].points[0], triangles[triID].points[1], triangles[triID].points[2], &bx, &by, &bz);
            colPos = (triangles[triID].points[0]*bx + triangles[triID].points[1]*by + triangles[triID].points[2]*bz);
            return true;
        }

        for (auto it = triangles.begin(); it != triangles.end();)
        {
            triangle t = *it;
            if (t.norm.dot(v - t.points[0]) > 0)
            {
                addEdge(t.points[0], t.points[1]);
                addEdge(t.points[1], t.points[2]);
                addEdge(t.points[2], t.points[0]);
                it = triangles.erase(it);
                continue;
            }
            it++;
        }

        for (int j = 0; j < edges.size(); ++j)
        {
            triangles.push_back(triangle(edges[j].points[0], edges[j].points[1], v));
        }
        edges.clear();
    };
    return true;
}

bool GJK(GraphicsNode& shape1, GraphicsNode& shape2, fdVector& colNormal, fdVector& colPos, float& colDepth)
{
    vector<fdVector> simplexShape;
    fdVector A = supportFunc(shape1, shape2, fdVector(1,0,0));
    fdVector d = A*-1;

    simplexShape.push_back(A);


    while(true)
    {
        A = supportFunc(shape1, shape2, d);
        simplexShape.push_back(A);

        if(A.dot(d) <= 0)
            return false;

        if(simplex(simplexShape, d))
        {
            EPA(shape1, shape2, simplexShape, colNormal, colPos, colDepth);
            return true;
        }
    }

};