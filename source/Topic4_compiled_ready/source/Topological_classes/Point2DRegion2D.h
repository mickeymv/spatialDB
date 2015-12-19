/******************************************************************************
* File: Point2DRegion2D.h
*******************************************************************************
* Purpose: Interface to exploration functions and evaluation functions for
*   the topological relationships between a Point2D and a Region2D object.This also contains
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
#ifndef PLANESWEEP_PROJECT_POINT2DREGION2D_H
#define PLANESWEEP_PROJECT_POINT2DREGION2D_H

#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Region2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "TopologicalRelationships.h"



class Point2DRegion2D{

public:
    Point2DRegion2D(const Point2D &F, const Region2D &G);
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
//    typedef enum {
//        poi_inside, poi_outside, poi_on_bound
//    }vFPoint2DRegion2DPredicates;

    enum vF_Predicates
    {
        poi_inside, poi_outside, poi_on_bound
    };

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


    // DTj: Defining the IMC matrix
    // Refer to paper Topological Relationships Between
    // Complex Spatial Objects p. 70
    //
    typedef std::bitset<6> imctype;

    static const int matrixSize = 7;

    const string matrixStr[matrixSize] = {
            //  DTj: Since the entire row 2 of the 3x3 matrix above is not used, we simplify it as below,
            // so instead of the first row and the last row are used for comparison
            //
            "001111", "010111", "011111", "100111", "101111",  //  1-5
            "110111", "111111"  //  6-7
    };

    imctype matrix[matrixSize];


};


#endif //PLANESWEEP_PROJECT_POINT2DREGION2D_H
