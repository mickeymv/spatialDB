//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_LINE2DREGION2D_H
#define PLANESWEEP_PROJECT_LINE2DREGION2D_H

#include "Region2D.h"
#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "TopologicalRelationships.h"
#include "TopPredNumberEnums.h"


class Line2DRegion2D{

public:
    Line2DRegion2D(Line2D &, Region2D &);
    ~Line2DRegion2D();

    bool isTopologicalRelationship(TopPredNumberLine2DRegion2D predicate);
    TopPredNumberLine2DRegion2D getTopologicalRelationship();

    bool overlap();
    bool disjoint();
    bool meet();
    bool equal();
    bool contains();
    bool covers();
    bool coveredBy();
    bool inside();


private:

    typedef enum {
        seg_inside,seg_shared,seg_outside,poi_shared,bound_inside,bound_shared,bound_disjoint,bound_outside
    }vFLine2DRegion2DPredicates;

    typedef enum {
        seg_unshared
    }vGLine2DRegion2DPredicates;


    // predicates enum
//    enum class vF_Line2DRegion2D_Predicates{
//        seg_inside,seg_shared,seg_outside,poi_shared,bound_inside,bound_shared,bound_disjoint
//    };
//
//    enum class vG_Line2DRegion2D_Predicates{
//        seg_unshared
//    };


    Line2D objF;
    Region2D objG;
    static const int vF_size=7;
    static const int vG_size=1;

    TopPredNumberLine2DRegion2D topPredNumberLine2DRegion2D;
    bool isPredSet=false;

    bool vF[vF_size];
    bool vG[vG_size];


    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();

    //Exploration function
    void exploreTopoPred();

    //Evaluation function
    void evaluateTopoPred();
};

#endif //PLANESWEEP_PROJECT_LINE2DREGION2D_H
