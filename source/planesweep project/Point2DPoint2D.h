//
// Created by Natasha on 11/12/2015.
//

#ifndef PLANESWEEP_PROJECT_POINT2DPOINT2D_H
#define PLANESWEEP_PROJECT_POINT2DPOINT2D_H

#include "Topic2/Implementation/Point2D.h"
#include "Object2D.h"

class Point2DPoint2D
{
  public:
    Point2DPoint2D(Object2D &F, Object2D &G);
    ~Point2DPoint2D();

    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();

    //Exploration function
    bool Explore();

    // predicates enum
    enum class vF_Point2DPoint2D_Predicates {
        poi_shared,poi_disjoint
    };

    enum class vG_Point2DPoint2D_Predicates{
        poi_disjoint
    };

private:

    Point2D objF,objG;
    static const int vF_size=2;
    static const int vG_size=1;

    bool vF[vF_size];
    bool vG[vG_size];

};

#endif //PLANESWEEP_PROJECT_POINT2DPOINT2D_H
