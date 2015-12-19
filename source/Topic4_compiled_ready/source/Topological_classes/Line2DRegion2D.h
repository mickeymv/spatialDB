/******************************************************************************
* File: Line2DRegion2D.h
*******************************************************************************
* Purpose: Interface to exploration functions and evaluation functions for
*   the topological relationships between a Line2D and a Region2D object.This also contains
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

#ifndef PLANESWEEP_PROJECT_LINE2DREGION2D_H
#define PLANESWEEP_PROJECT_LINE2DREGION2D_H

#include "planesweep_project/Topic2/Implementation/Region2D.h"
#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "TopologicalRelationships.h"
#include "TopPredNumberEnums.h"


class Line2DRegion2D{

public:
    Line2DRegion2D(const Line2D &F, const Region2D &G);
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

//    enum vF_Predicates
//    {
//        seg_inside,seg_shared,seg_outside,poi_shared, bound_inside,bound_shared,bound_disjoint
//    };

//    enum vG_Predicates
//    {
//        seg_unshared
//    };

    Line2D objF;
    Region2D objG;
    static const int vF_size=8;
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


    // DTj: Defining the IMC matrix
    // Refer to paper Topological Relationships Between
    // Complex Spatial Objects p. 73
    //
    typedef std::bitset<9> imctype;

    static const int matrixSize = 43;

    const string matrixStr[matrixSize] = {
            "001000111", "001001111", "001010111", "001011111", "010000101",  //  1-5
            "010000111", "010010111", "011000101", "011000111", "011001101", //  6-10
            "011001111", "011010111", "011011111", "100000111", "100010111", // 11-15
            "100100111", "100110111", "101000111", "101001111", "101010111", // 16-20
            "101011111", "101100111", "101101111", "101110111", "101111111", // 21-25
            "110000101", "110000111", "110010111", "110100101", "110100111", // 26-30

            "110110111", "111000101", "111000111", "111001101", "111001111", // 31-35
            "111010111", "111011111", "111100101", "111100111", "111101101", // 36-40
            "111101111", "111110111", "111111111" // 41-43
    };

    imctype matrix[matrixSize];
};

#endif //PLANESWEEP_PROJECT_LINE2DREGION2D_H
