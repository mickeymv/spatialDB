//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POINT2DLINE2D_H
#define PLANESWEEP_PROJECT_POINT2DLINE2D_H

#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"


class Point2DLine2D{

public:
    Point2DLine2D(Object2D &F, Object2D &G);
    ~Point2DLine2D();

    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();

    //Exploration function
    bool Explore();

    // predicates enum
    enum class vF_Point2DLine2D_Predicates {
        poi_disjoint,poi_on_interior,poi_on_bound
    };

    enum class vG_Point2DLine2D_Predicates{
        bound_poi_disjoint
    };



private:
    Point2D objF;
    Line2D objG;
    static const int vF_size=3;
    static const int vG_size=1;

    bool vF[vF_size];
    bool vG[vG_size];

};

#endif //PLANESWEEP_PROJECT_POINT2DLINE2D_H
