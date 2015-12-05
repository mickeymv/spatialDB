//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POINT2DREGION2D_H
#define PLANESWEEP_PROJECT_POINT2DREGION2D_H

#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Region2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "TopologicalRelationships.h"



class Point2DRegion2D{

public:
    Point2DRegion2D(Point2D &F, Region2D &G);
    ~Point2DRegion2D();

  //Function to check whether the given spatial predicate holds true
    bool isTopologicalRelationship(TopPredNumberPoint2DRegion2D predicate);
    //Function to check return  spatial predicate
    TopPredNumberPoint2DRegion2D getTopologicalRelationship();


    //8 basic spatial predicates based on 9IM
    bool overlap();
    bool disjoint();
    bool meet();
    bool equal();
    bool contains();
    bool covers();
    bool coveredBy();
    bool inside();







private:

    TopPredNumberPoint2DRegion2D  topPredNumberPoint2DRegion2D;

// predicates enum
    typedef enum {
        poi_inside, poi_outside, poi_on_bound
    }vFPoint2DRegion2DPredicates;

    Point2D objF;
    Region2D objG;

    static const int vF_size=3;



    bool isPredSet=false;

    bool vF[vF_size];


    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();


    //Exploration function
    void exploreTopoPred();

    //Evaluation function
    void evaluateTopoPred();




};


#endif //PLANESWEEP_PROJECT_POINT2DREGION2D_H
