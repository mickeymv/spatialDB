/******************************************************************************
* File: Point2DPoint2D.h
*******************************************************************************
* Purpose: Interface to exploration functions and evaluation functions for
*   the topological relationships between two Point2D objects.This also contains
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


#ifndef POINT2DPONT2D_POINT2DPOINT2D_H
#define POINT2DPONT2D_POINT2DPOINT2D_H

#include "planesweep_project/ParallelObjectTraversal.h"
#include "TopPredNumberEnums.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"


#include <bitset>

static const int matrixSize = 5;


class Point2DPoint2D {
public:
    Point2DPoint2D(const Point2D &F, const Point2D &G);

    ~Point2DPoint2D();

    bool isTopologicalRelationship(TopPredNumberPoint2DPoint2D predicate);

    TopPredNumberPoint2DPoint2D getTopologicalRelationship();

    bool overlap();

    bool disjoint();

    bool meet();

    bool equal();

    bool contains();

    bool covers();

    bool coveredBy();

    bool inside();

    bool touch();

private:

    // predicates enum
    enum vF_Predicates {
        poi_shared, poi_disjoint
    };

    enum vG_Predicates {
        // the same as 'poi_disjoint", but we named it differently so it has no conflict with the same enum in vF_Predicates
                poi_disjoint_g
    };

    Point2D objF, objG;

    static const int vF_size = 2;
    static const int vG_size = 1;

    TopPredNumberPoint2DPoint2D topPredNumberPoint2DPoint2D;
    bool isPredSet = false;

    bool vF[vF_size];
    bool vG[vG_size];

    // getter functions
    bool *getVF();
    bool *getVG();


    // Exploration function
    void exploreTopoPred();

    // Evaluation function
    void evaluateTopoPred();

    // properties
    ParallelObjectTraversal *pot;

    typedef std::bitset<6> imctype;


    const string matrixStr[matrixSize] = {
            // "001000101", "100000001", "100000101", "101000001", "101000101",  //  Since the entire row 2 of the 3x3 matrix is not used, we simplify it as below
            //
            //  DTj: Since the entire row 2 of the 3x3 matrix above is not used, we simplify it as below,
            // so instead of the first row and the last row are used for comparison
            //
            "001101", "100001", "100101", "101001", "101101",  //  1-5
    };

    imctype matrix[matrixSize];

};


#endif //POINT2DPONT2D_POINT2DPOINT2D_H
