/******************************************************************************
* File: Line2DLine2D.h
*******************************************************************************
* Purpose: Interface to exploration functions and evaluation functions for
*   the topological relationships between two Line2D objects.This also contains
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

#ifndef PLANESWEEP_PROJECT_LINE2DLINE2D_H
#define PLANESWEEP_PROJECT_LINE2DLINE2D_H


//#include <bitset>
#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"

#include "TopPredNumberEnums.h"


class Line2DLine2D {

public:
    Line2DLine2D(const Line2D &F, const Line2D &G);

    ~Line2DLine2D();

    //Function to check whether the given spatial predicate holds true
    bool isTopologicalRelationship(TopPredNumberLine2DLine2D predicate);

    //Function to check return  spatial predicate
    TopPredNumberLine2DLine2D getTopologicalRelationship();

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

//    typedef enum {
//        seg_shared,interior_poi_shared,seg_unshared,bound_on_interior,bound_shared,bound_disjoint
//    }vFLine2DLine2DPredicates;
//
//    typedef enum {
//        seg_unshared_g,bound_on_interior_g,bound_disjoint_g
//    }vGLine2DLine2DPredicates;

    enum vF_Predicates {
        seg_shared, interior_poi_shared, seg_unshared, bound_on_interior, bound_shared, bound_disjoint
    };

    enum vG_Predicates {
        seg_unshared_g, bound_on_interior_g, bound_disjoint_g
    };

    Line2D objF;
    Line2D objG;
    static const int vF_size = 6;
    static const int vG_size = 3;

    TopPredNumberLine2DLine2D topPredNumberLine2DLine2D;
    bool isPredSet = false;

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


    // DTj: Refer to paper Topological Relationships Between
    // Complex Spatial Objects p. 60
    string matrix[82] = {
            "001000101", "001000111", "001001101", "001001111", "001010101",  //  1-5
            "001010111", "001011101", "001011111", "001100101", "001100111", //  6-10
            "001101101", "001101111", "001110101", "001110111", "001111101", // 11-15
            "001111111", "011000101", "011000111", "011001101", "011001111", // 16-20
            "011010101", "011010111", "011011101", "011011111", "011100101", // 21-25
            "011100111", "011101101", "011101111", "011110101", "011110111", // 26-30

            "011111101", "011111111", "100000001", "100000101", "100000111", // 31-35
            "100010001", "100010101", "100010111", "100100101", "100100111", // 36-40
            "100110101", "100110111", "101000001", "101000101", "101000111", // 41-45
            "101001001", "101001101", "101001111", "101010001", "101010101", // 46-50
            "101010111", "101011001", "101011101", "101011111", "101100101", // 51-55
            "101100111", "101101101", "101101111", "101110101", "101110111", // 56-60

            "101111101", "101111111", "111000001", "111000101", "111000111", // 61-65
            "111001001", "111001101", "111001111", "111010001", "111010101", // 66-70
            "111010111", "111011001", "111011101", "111011111", "111100101", // 71-75
            "111100111", "111101101", "111101111", "111110101", "111110111", // 76-80
            "111111101", "111111111"   // 81-82
    };

};


#endif //PLANESWEEP_PROJECT_LINE2DLINE2D_H
