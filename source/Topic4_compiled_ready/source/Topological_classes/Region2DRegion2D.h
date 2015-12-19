/******************************************************************************
* File: Region2DRegion2D.h
*******************************************************************************
* Purpose: Interface to exploration functions and evaluation functions for
*   the topological relationships between two Region2D objects.This also contains
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

#ifndef PLANESWEEP_PROJECT_REGION2DREGION2D_H
#define PLANESWEEP_PROJECT_REGION2DREGION2D_H

#include <bitset>

#include "planesweep_project/Object2D.h"
#include "TopPredNumberEnums.h"
#include "planesweep_project/PlaneSweep.h"
#include "planesweep_project/Topic2/Implementation/Region2D.h"


class Region2DRegion2D {

public:
    Region2DRegion2D(const Region2D &F, const Region2D &G);
    ~Region2DRegion2D();

    bool isTopologicalRelationship(TopPredNumberRegion2DRegion2D predicate);
    TopPredNumberRegion2DRegion2D getTopologicalRelationship();

    bool overlap();
    bool disjoint();
    bool meet();
    bool equal();
    bool contains();
    bool covers();
    bool coveredBy();
    bool inside();

private:
    Region2D objF, objG;
    static const int vF_size=8;
    static const int vG_size=4;

    bool vF[vF_size];
    bool vG[vG_size];

    // enum predicates
    enum vF_Predicates{
        zero_one,one_zero,one_two,two_one,zero_two,two_zero,one_one,bound_poi_shared
    };

    enum vG_Predicates{
        zero_one_g,one_zero_g,one_two_g,two_one_g
    };

    TopPredNumberRegion2DRegion2D topPredNumberRegion2DRegion2D;
    bool isPredSet = false;

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
    // Complex Spatial Objects p. 66
    //
    typedef std::bitset<9> imctype;

    const string matrixStr[TopPredNumberRegion2DRegion2DEnumSize] = {
            "001001111", "001010111", "001011101", "001011111", "100010001",  //  1-5
            "100010111", "100100111", "100110101", "100110111", "101010111",  //  5-10
            "101011001", "101011101", "101011111", "101101111", "101110101",  //  11-15
            "101110111", "101111101", "101111111", "111001001", "111001111",  //  16-20
            "111010001", "111010101", "111010111", "111011001", "111011101",  //  21-25
            "111011111", "111100111", "111101101", "111101111", "111110101",  //  26-30
            "111110111", "111111101", "111111111"  //  31-33
    };

    imctype matrix[TopPredNumberRegion2DRegion2DEnumSize];
};


#endif //PLANESWEEP_PROJECT_REGION2DREGION2D_H
