/******************************************************************************
* File: Point2DPoint2D.cpp
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

    // assigning the the matrix value
    for (int i=0; i< TopPredNumberPoint2DPoint2DEnumSize; i++)
        matrix[i] = imctype (std::string(matrixStr[i]));

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
    while ((pot->getStatus() == ParallelObjectTraversal::end_of_none) &&
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
    if (!vF[poi_shared] && vF[poi_disjoint] && !vG[poi_disjoint_g]) vG[vG_Predicates::poi_disjoint_g] = true;
    if (!vF[poi_shared] && !vF[poi_disjoint] && vG[poi_disjoint_g]) vF[vF_Predicates::poi_shared] = true;

    // test
//    cout << "vF[poi_shared] = " << vF[poi_shared]  << endl;
//    cout << "vF[poi_disjoint] = " << vF[poi_disjoint]   << endl;
//    cout << "vG[poi_disjoint_g] = " << vG[poi_disjoint_g]  << endl<< endl;

}

// evaluate topological predicate method
void Point2DPoint2D::evaluateTopoPred() {

    // Dtj. Dec 16.
    // matrix index 2,2 always true
    // Since the second row of the IMC 3x3 matrix is never evaluated,
    // here we only use six array member to represent the first row and third row of the 3x3 Matrix.
    imctype IMC = imctype (std::string("000001"));

    // populating the ICM with the value of vF and vG
    if (vF[poi_shared])
     IMC.set(5); // setting only one bit of a time: (100000);

    if (vF[poi_disjoint])
     IMC.set(3);  // (001000);

    if (vG[poi_disjoint_g])
     IMC.set(2);  // (000100);


    // compare/match the right one
    // loop exit if the top Pred number found
    for (int i = 0; i < TopPredNumberPoint2DPoint2DEnumSize && !isPredSet; i++) {

        // Dtj. we do bitwise comparison for faster execution:
         if (IMC == matrix[i]) {isPredSet = true; topPredNumberPoint2DPoint2D = (TopPredNumberPoint2DPoint2D) i;}
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
