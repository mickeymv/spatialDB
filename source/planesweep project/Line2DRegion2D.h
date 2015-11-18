//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_LINE2DREGION2D_H
#define PLANESWEEP_PROJECT_LINE2DREGION2D_H

#include "Object2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Region2D.h"



class Line2DRegion2D{

public:
    Line2DRegion2D(Object2D &, Object2D &);
    ~Line2DRegion2D();

    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();

    //Exploration function
    bool Explore();

    // predicates enum
    enum class vF_Line2DRegion2D_Predicates{
        seg_inside,seg_shared,seg_outside,poi_shared,bound_inside,bound_shared,bound_disjoint
    };

    enum class vG_Line2DRegion2D_Predicates{
        seg_unshared
    };

private:
    Line2D objF;
    Region2D objG;
    static const int vF_size=7;
    static const int vG_size=1;

    bool vF[vF_size];
    bool vG[vG_size];
};

#endif //PLANESWEEP_PROJECT_LINE2DREGION2D_H
