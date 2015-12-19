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

#include <bitset>

#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "TopPredNumberEnums.h"

class Point2DLine2D {
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

    // DTj: Defining the IMC matrix
    // Refer to paper Topological Relationships Between
    // Complex Spatial Objects p. 69
    //
    typedef std::bitset<6> imctype;

    const string matrixStr[TopPredNumberPoint2DLine2DEnumSize] = {
            //  DTj: Since the entire row 2 of the 3x3 matrix above is not used, we simplify it as below,
            // so instead of the first row and the last row are used for comparison
            //
            "001101", "001111", "010101", "010111", "011101",  //  1-5
            "011111", "100101", "100111", "101101", "101111",  //  5-10
            "110101", "110111", "111101", "111111"  //  11-14

    };

    imctype matrix[TopPredNumberPoint2DLine2DEnumSize];

};

#endif //PLANESWEEP_PROJECT_POINT2DLINE2D_H
