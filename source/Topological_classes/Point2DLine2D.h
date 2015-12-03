//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POINT2DLINE2D_H
#define PLANESWEEP_PROJECT_POINT2DLINE2D_H

#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "TopologicalRelationships.h"



class Point2DLine2D{

public:
    Point2DLine2D(Point2D &F, Line2D &G);
    ~Point2DLine2D();

    bool isTopologicalRelationship(TopPredNumberPoint2DLine2D predicate);
    TopPredNumberPoint2DLine2D getTopologicalRelationship();

    bool overlap();
    bool disjoint();
    bool meet();
    bool equal();
    bool contains();
    bool covers();
    bool coveredBy();
    bool inside();



private:

    // predicates enum

    typedef enum {
        poi_disjoint,poi_on_interior,poi_on_bound
    }vFPoint2DLine2DPredicates;

    typedef enum {
        bound_poi_disjoint
    }vGPoint2DLine2DPredicates;

    Point2D objF;
    Line2D objG;
    static const int vF_size=3;
    static const int vG_size=1;
    TopPredNumberPoint2DLine2D *topPredNumberPoint2DLine2D = nullptr;
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

#endif //PLANESWEEP_PROJECT_POINT2DLINE2D_H
