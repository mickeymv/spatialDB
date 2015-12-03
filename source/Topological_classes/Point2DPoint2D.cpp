//
// Created by Djundi on 11/8/15.
//


#include "Point2DPoint2D.h"


Point2DPoint2D::Point2DPoint2D(const Point2D &F, const Point2D &G) {
    setObjF(objF);
    setObjG(objG);

    // initialize vF and vG with false
    for (int i = 0; i < vF_size; i++) {
        vF[i] = false;
    }

    for (int i = 0; i < vG_size; i++) {
        vG[i] = false;
    }

};

Point2DPoint2D::~Point2DPoint2D() {
    // do garbage clean up here if necessary...

};


bool *Point2DPoint2D::getVF() {
    return vF;
}

bool *Point2DPoint2D::getVG() {
    return vG;
}


void Point2DPoint2D::exploreTopoPred() {

    // this Explore algorithm below will set the vF and vG flag, but the function itself will return nothing (void).
    // the flag vF and vG set in the implementation below will be used by the "evaluateVerificationTopoPred" and "evaluateDeterminationTopoPred" function.

    // implementation...
    // ... do some work here
    //


}


void Point2DPoint2D::evaluateTopoPred() {

}


TopPredNumberPoint2DPoint2D Point2DPoint2D::getTopologicalRelationship() {

//    if (topPredNumberPoint2DPoint2D == nullptr) {
//        exploreTopoPred();
//        evaluateTopoPred();
//    }

    exploreTopoPred();
    evaluateTopoPred();

    topPredNumberPoint2DPoint2D = TopPredNumberPoint2DPoint2D::pp_equal_m2;
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






