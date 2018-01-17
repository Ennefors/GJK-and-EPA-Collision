//
// Created by bill on 20/12/17.
//

#include "GraphicsNode.h"
#include "Collision.h"

double rate(double x, double y)
{
    return x * sqrt(y);
}

double rk4(double(*f)(double, double), double dx, double x, double y)
{
    double  k1 = dx * f(x, y),
            k2 = dx * f(x + dx / 2, y + k1 / 2),
            k3 = dx * f(x + dx / 2, y + k2 / 2),
            k4 = dx * f(x + dx, y + k3);
    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

double euler(double(*f)(double, double), double end_time, double step_time, double acc)
{
    double *y;
    y = new double[(int)(end_time*step_time) + 1];
    y[0] = acc;
    y[1] = y[0] + step_time * f(step_time, y[0]);

    for(int step = 2; step <= end_time*step_time; step++)
    {
        y[step] = y[step - 1] + step*step_time*f(step*step_time, y[step - 1]);
    }

    return y[(int)(end_time*step_time)];

}

void collRespo(GraphicsNode &oA, GraphicsNode &oB, fdVector colPoint, fdVector colNorm, float colDepth, float dt) {
    //Object A vars
    colNorm = colNorm.normalize();
    fdVector oAVel = oA.getMesh()->direction;
    fdVector oAAngVel = oA.getMesh()->angMomentum;
    fdVector oACoM = oA.getMesh()->CoM;
    float oAM = oA.getMesh()->mass;
    fdVector oASpi = oA.getMesh()->spinVec;
    fdMatrix oAI;
    if(oAM != 0.0f) {
        oAI = oA.getMesh()->invInertiaTensor;
    } else {
        oAI = fdMatrix(0,0,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0);
    }

    //Object B vars
    fdVector oBVel = oB.getMesh()->direction;
    fdVector oBAngVel = oB.getMesh()->angMomentum;
    fdVector oBCoM = oB.getMesh()->CoM;
    float oBM = oB.getMesh()->mass;
    fdVector oBSpi = oB.getMesh()->spinVec;
    fdMatrix oBI;

    if(oBM != 0.0f) {
        oBI = oB.getMesh()->invInertiaTensor;
    } else {
        oBI = fdMatrix(0,0,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0);
    }
    //calculated Vars


    fdVector PA = oAVel + oASpi.Cross(colPoint - oACoM);
    fdVector PB = oBVel + oBSpi.Cross(colPoint - oBCoM);

    fdVector difVel = PA - PB;
    float velRelative =  colNorm*difVel;
    if (velRelative < 0.f){
        float J = (-(1 + 0.75) * velRelative) /
                  (-oAM + -oBM + (colNorm * (oAI.trans_tdVector(oAAngVel.Cross(colNorm)).Cross(oAAngVel))) +
                   (colNorm * (oBI.trans_tdVector(oBAngVel.Cross(colNorm)).Cross(oBAngVel))));
        fdVector JA = (colNorm * J);
        fdVector JB = (colNorm * -J);

        fdVector aImp = (colPoint - oACoM).Cross(JA);
        fdVector bImp = (colPoint - oBCoM).Cross(JB);



        if(oAM != 0.f)
        {
            oA.getMesh()->direction = oA.getMesh()->direction + JA* rk4(rate, dt, oA.getMesh()->vel, fabs(J/(oAM)));
            //oA.getMesh()->direction = oA.getMesh()->direction + (JA.normalize() * euler(rate, dt, dt/10.f, (fabs(JA.length()/(oAM)))));
            oA.getMesh()->angMomentum = oA.getMesh()->angMomentum + aImp;
        }
        oA.getMesh()->spinVec = oAI.trans_tdVector(aImp);





        if(oBM != 0.f)
        {
            oB.getMesh()->direction = oB.getMesh()->direction + JB* rk4(rate, dt, oB.getMesh()->vel, fabs(J/(oBM)));
            //oB.getMesh()->direction = oB.getMesh()->direction + (JB.normalize() * euler(rate, dt, dt/10.f, (fabs(JB.length() / (oBM)))));
            oB.getMesh()->angMomentum = oB.getMesh()->angMomentum + bImp;
        }

        oB.getMesh()->spinVec = oBI.trans_tdVector(bImp);
    }
};