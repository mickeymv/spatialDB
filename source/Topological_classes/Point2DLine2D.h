//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POINT2DLINE2D_H
#define PLANESWEEP_PROJECT_POINT2DLINE2D_H

#include "Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"



class Point2DLine2D{

public:
    Point2DLine2D(Object2D &F, Object2D &G);
    ~Point2DLine2D();


    // Enum class defining names for the numbers of topological predicates
// between a Point2D object and a Line2D object
    typedef enum
    {
        pl_disjoint_m1, pl_disjoint_m2, pl_meet_m3, pl_meet_m4, pl_meet_m5,
        pl_meet_m6, pl_inside_m7, pl_inside_m8, pl_overlap_m9, pl_overlap_m10,
        pl_inside_m11, pl_inside_m12, pl_overlap_m13, pl_overlap_m14
    }TopPredNumberPoint2DLine2D;

    TopPredNumberPoint2DLine2D getTopologicalRelationship();
    bool isTopologicalRelationship(TopPredNumberPoint2DLine2D predicate);


private:
    Point2D objF;
    Line2D objG;
    static const int vF_size=3;
    static const int vG_size=1;
    TopPredNumberPoint2DLine2D topPredNumberPoint2DLine2D;

    //Exploration function
    void Explore();

    //Evaluation function
    void Evaluate();


    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();

    // predicates enum
    enum vF_Point2DLine2D_Predicates {
        poi_disjoint,poi_on_interior,poi_on_bound
    };

    enum vG_Point2DLine2D_Predicates{
        bound_poi_disjoint
    };

    bool vF[vF_size];
    bool vG[vG_size];

};

#endif //PLANESWEEP_PROJECT_POINT2DLINE2D_H
