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

#include "Object2D.h"

#include "Region2D.h"


class Region2DRegion2D{

public:
    Region2DRegion2D(Object2D &, Object2D &);
    ~Region2DRegion2D();

    // get vector array vF
    bool *getVF();

    //Exploration function
    bool Explore();

    // enum predicates
    enum class vF_Region2DRegion2D_Predicates{
        zero_one,one_zero,one_two,two_one,zero_two,two_zero,one_one,bound_poi_shared
    };

private:
    Region2D objF, objG;
    static const int vF_size=8;

    bool vF[vF_size];
};


#endif //PLANESWEEP_PROJECT_REGION2DREGION2D_H
