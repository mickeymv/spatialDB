//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_LINE2DLINE2D_H
#define PLANESWEEP_PROJECT_LINE2DLINE2D_H


#include "Object2D.h"
#include "Topic2/Implementation/Line2D.h"


class Line2DLine2D{

public:
    Line2DLine2D(Object2D &F, Object2D &G);
    ~Line2DLine2D();

    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();

    //Exploration function
    bool Explore();

    // predicates enum
    enum class vF_Line2DLine2D_Predicates{
        seg_shared,interior_poi_shared,seg_unshared,bound_on_interior,bound_shared,bound_disjoint
    };

    enum class vG_Line2DLine2D_Predicates{
        seg_unshared,bound_on_interior,bound_disjoint
    };


private:
    Line2D objF, objG;
    static const int vF_size=6;
    static const int vG_size=3;

    bool vF[vF_size];
    bool vG[vG_size];

};


#endif //PLANESWEEP_PROJECT_LINE2DLINE2D_H
