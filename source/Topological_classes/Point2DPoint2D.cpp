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
* Authors:Group 4 [Tjindra Djundi]
*
* Date: Fall Semester 2015
******************************************************************************/


#include "Point2DPoint2D.h"


/* ***  public functions  *** */
Point2DPoint2D::Point2DPoint2D(const Point2D &F, const Point2D &G) {
    objF = F;
    objG = G;


    // initialize vF and vG with false
    for (int i = 0; i < vF_size; i++) {
        vF[i] = false;
    }

    for (int i = 0; i < vG_size; i++) {
        vG[i] = false;
    }


    pot = new ParallelObjectTraversal(objF, objG);

};

Point2DPoint2D::~Point2DPoint2D() {
    // do garbage clean up here if necessary...

};

TopPredNumberPoint2DPoint2D Point2DPoint2D::getTopologicalRelationship() {


    exploreTopoPred();
    evaluateTopoPred();

    return topPredNumberPoint2DPoint2D;

}


bool Point2DPoint2D::isTopologicalRelationship(TopPredNumberPoint2DPoint2D predicate) {
    exploreTopoPred();
    evaluateTopoPred();

    if (topPredNumberPoint2DPoint2D == predicate) {
        return true;
    }
    return false;
}



/* ***  private functions  *** */

// getter function VF
bool *Point2DPoint2D::getVF() {
    return vF;
}

// getter function VG
bool *Point2DPoint2D::getVG() {
    return vG;
}


// setter function for objF
//void Point2DPoint2D::setObjF(const Point2D &objF) {
//    Point2DPoint2D::objF = objF;
//}
//
//
//// setter function for objG
//void Point2DPoint2D::setObjG(const Point2D &objG) {
//    Point2DPoint2D::objG = objG;
//}


// explore topological predicate method
void Point2DPoint2D::exploreTopoPred() {

    // this Explore algorithm below will set the vF and vG flag, but the function itself will return nothing (void).
    // the flag vF and vG set in the implementation below will be used by the "evaluateVerificationTopoPred" and "evaluateDeterminationTopoPred" function.

    // implementation...


   // I have changed the status from orginially on paper checking the end_of_none to NOT end_of_both 
   // otherwise the loop will exit early before all the Poi elements from both objects are traversed
   // while ( (pot->getStatus() == ParallelObjectTraversal::end_of_none) &&
   while ( (pot->getStatus() != ParallelObjectTraversal::end_of_both) &&
           !(vF[vF_Predicates::poi_disjoint] && vG[vG_Predicates::poi_disjoint_g] && vF[vF_Predicates::poi_shared])) {

        if (pot->getObject() == ParallelObjectTraversal::first) vF[vF_Predicates::poi_disjoint] = true;
        else if (pot->getObject() == ParallelObjectTraversal::second) vG[vG_Predicates::poi_disjoint_g] = true;
        else /* object both */
            vF[vF_Predicates::poi_shared] = true;

        pot->selectNext();

    }

    // this part is according to the paper
    if (pot->getStatus() == ParallelObjectTraversal::end_of_first) vG[vG_Predicates::poi_disjoint_g] = true;
    else if (pot->getStatus() == ParallelObjectTraversal::end_of_second) vF[vF_Predicates::poi_disjoint] = true;

    // but I have added this below, it looks like it is missing in the paper:
    if (pot->getObject()  == ParallelObjectTraversal::both) vF[vF_Predicates::poi_shared] = true;
    
    
    cout << "vF[poi_shared] =" << vF[vF_Predicates::poi_shared] << endl;
    cout << "vF[poi_disjoint] =" << vF[vF_Predicates::poi_disjoint] << endl;
    cout << "vG[poi_disjoint] =" << vG[vG_Predicates::poi_disjoint_g] << endl;

}


// evaluate topological predicate method
void Point2DPoint2D::evaluateTopoPred() {

}











