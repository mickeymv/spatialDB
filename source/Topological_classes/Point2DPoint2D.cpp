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
* Authors:Group 4. Dtj.
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

    //topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_equal_m2;
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


// explore topological predicate method
void Point2DPoint2D::exploreTopoPred() {

    // this Explore algorithm below will set the vF and vG flag, but the function itself will return nothing (void).
    // the flag vF and vG set in the implementation below will be used by the "evaluateVerificationTopoPred" and "evaluateDeterminationTopoPred" function.
    while ((pot->getStatus() != ParallelObjectTraversal::end_of_both) &&
           !(vF[vF_Predicates::poi_disjoint] && vG[vG_Predicates::poi_disjoint_g] && vF[vF_Predicates::poi_shared])) {

        if (pot->getObject() == ParallelObjectTraversal::first) vF[vF_Predicates::poi_disjoint] = true;
        else if (pot->getObject() == ParallelObjectTraversal::second) vG[vG_Predicates::poi_disjoint_g] = true;
        else /* object both */
            vF[vF_Predicates::poi_shared] = true;

        pot->selectNext();
    }

    if (pot->getStatus() == ParallelObjectTraversal::end_of_first) vG[vG_Predicates::poi_disjoint_g] = true;
    else if (pot->getStatus() == ParallelObjectTraversal::end_of_second) vF[vF_Predicates::poi_disjoint] = true;

    // missing in the paper:
    if (pot->getObject() == ParallelObjectTraversal::both) vF[vF_Predicates::poi_shared] = true;
}

// evaluate topological predicate method
void Point2DPoint2D::evaluateTopoPred() {

    // IMC 3x3 matrix array
    int IMC[3][3];

    // set all values to 0
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            IMC[i][j] = 0;
        }
    }

    //set the respective element with the vF and vG results from exploreTopoPred()
    if (vF[poi_shared]) IMC[0][0] = 1;
    if (vF[poi_disjoint]) IMC[0][2] = 1;
    if (vG[poi_disjoint_g]) IMC[2][0] = 1;

    IMC[2][2] = 1; // always true


    // test for pp_disjoint_m1
    if (!IMC[0][0] && !IMC[0][1] && IMC[0][2]
        && !IMC[1][0] && !IMC[1][1] && !IMC[1][2]
        && IMC[2][0] && !IMC[2][1] && IMC[2][2]) {
        topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_disjoint_m1;
        isPredSet = true;
    } else
    // test for pp_equal_m2
    if (IMC[0][0] && !IMC[0][1] && !IMC[0][2]
        && !IMC[1][0] && !IMC[1][1] && !IMC[1][2]
        && !IMC[2][0] && !IMC[2][1] && IMC[2][2]) {
        topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_equal_m2;
        isPredSet = true;
    } else
    // test for pp_inside_m3
    if (IMC[0][0] && !IMC[0][1] && !IMC[0][2]
        && !IMC[1][0] && !IMC[1][1] && !IMC[1][2]
        && IMC[2][0] && !IMC[2][1] && IMC[2][2]) {
        topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_inside_m3;
        isPredSet = true;
    } else
        // test for pp_contains_m4
    if (IMC[0][0] && !IMC[0][1] && IMC[0][2]
        && !IMC[1][0] && !IMC[1][1] && !IMC[1][2]
        && !IMC[2][0] && !IMC[2][1] && IMC[2][2]) {
        topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_contains_m4;
        isPredSet = true;
    } else
        // test for pp_overlap_m5
    if (IMC[0][0] && !IMC[0][1] && IMC[0][2]
        && !IMC[1][0] && !IMC[1][1] && !IMC[1][2]
        && IMC[2][0] && !IMC[2][1] && IMC[2][2]) {
        topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_overlap_m5;
        isPredSet = true;
    }
}

bool Point2DPoint2D::overlap() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DPoint2D == TopPredNumberPoint2DPoint2D::pp_overlap_m5;
}


bool Point2DPoint2D::disjoint() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DPoint2D == TopPredNumberPoint2DPoint2D::pp_disjoint_m1;
}


bool Point2DPoint2D::meet() {
    return false;
}

bool Point2DPoint2D::equal() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DPoint2D == TopPredNumberPoint2DPoint2D::pp_equal_m2;
}

bool Point2DPoint2D::contains() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DPoint2D == TopPredNumberPoint2DPoint2D::pp_contains_m4;
}

bool Point2DPoint2D::covers() {
    return false;
}

bool Point2DPoint2D::coveredBy() {
    return false;
}

bool Point2DPoint2D::inside() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DPoint2D == TopPredNumberPoint2DPoint2D::pp_inside_m3;
}

bool Point2DPoint2D::touch() {
    return false;
}
