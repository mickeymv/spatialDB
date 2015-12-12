/******************************************************************************
* File: Point2DLine2D.h
*******************************************************************************
* Purpose: Interface to exploration functions and evaluation functions for
*   the topological relationships between a Point2D and a Line2D object.This also contains
 *  clustered predicate verification functions
 *
* Description: Interface for Exploration and Evaluation algorithms and functions
 * for Topological Predicate Verification and Determination
 *
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors:Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/
#ifndef PLANESWEEP_PROJECT_POINT2DLINE2D_H
#define PLANESWEEP_PROJECT_POINT2DLINE2D_H

#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"

#include "TopPredNumberEnums.h"


class Point2DLine2D{

public:
    Point2DLine2D(const Point2D &F, const Line2D &G);
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

    // Dtj comment:
    // this enum class needs to be deleted, for now I am commenting these out. 
    // To replace this, I have included "TopPredNumberEnums.h" 
    //
    // // predicates enum
    // enum class TopPredNumberPoint2DLine2D
    // {
    //     pl_disjoint_m1, pl_disjoint_m2, pl_meet_m3, pl_meet_m4, pl_meet_m5,
    //     pl_meet_m6, pl_inside_m7, pl_inside_m8, pl_overlap_m9, pl_overlap_m10,
    //     pl_inside_m11, pl_inside_m12, pl_overlap_m13, pl_overlap_m14
    // };

//    typedef enum {
//        poi_disjoint,poi_on_interior,poi_on_bound
//    }vFPoint2DLine2DPredicates;
//
//    typedef enum {
//        bound_poi_disjoint
//    }vGPoint2DLine2DPredicates;

    enum vF_Predicates
    {
        poi_disjoint,poi_on_interior,poi_on_bound
    };

    enum vG_Predicates
    {
        bound_poi_disjoint
    };

    Point2D objF;
    Line2D objG;
    static const int vF_size=3;
    static const int vG_size=1;
    TopPredNumberPoint2DLine2D topPredNumberPoint2DLine2D;
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
