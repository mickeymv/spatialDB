/******************************************************************************
* File: Region2DRegion2D.cpp
*******************************************************************************
* Purpose: Implementation of exploration functions and evaluation functions for
*   the topological relationships between two Region2D object.This also contains
 *  clustered predicate verification functions
 *
* Description: Implementation of Exploration and Evaluation algorithms and functions
 * for Topological Predicate Verification and Determination
 *
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors:Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/

#include "Region2DRegion2D.h"


Region2DRegion2D::Region2DRegion2D(Object2D &F, Object2D &G) {
    // set obj1 and obj2
    F.set(objF);
    G.set(objG);

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

};

Region2DRegion2D::~Region2DRegion2D() { };


bool *Region2DRegion2D::getVF() {
    return vF;
}

bool Region2DRegion2D::Explore() {
    return true; // return true if no error, else false
}