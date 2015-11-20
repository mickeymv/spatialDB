//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POINT2DREGION2D_H
#define PLANESWEEP_PROJECT_POINT2DREGION2D_H

#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Region2D.h"



class Point2DRegion2D{

public:
    Point2DRegion2D(Object2D &, Object2D &);
    ~Point2DRegion2D();

    // get vector array vF
    bool *getVF();

    //Exploration function
    bool Explore();

    // predicates enum
    enum class vF_Point2DRegion2D_Predicates{
        poi_inside, poi_outside, poi_on_bound
    };




private:
    Point2D objF;
    Region2D objG;
    static const int vF_size=3;

    bool vF[vF_size];

};


#endif //PLANESWEEP_PROJECT_POINT2DREGION2D_H
