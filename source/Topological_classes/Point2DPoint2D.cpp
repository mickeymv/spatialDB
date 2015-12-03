//
// Created by Djundi on 11/8/15.
//


#include "Point2DPoint2D.h"


Point2DPoint2D::Point2DPoint2D(const Point2D &F, const Point2D &G) {
//Point2DPoint2D::Point2DPoint2D(Object2D &F, Object2D &G) {
    // set obj1 and obj2
    setObjF(objF);
    setObjG(objG);

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
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

void Point2DPoint2D::setObjF(const Point2D &objF) {
    Point2DPoint2D::objF = objF;
}

void Point2DPoint2D::setObjG(const Point2D &objG) {
    Point2DPoint2D::objG = objG;
}


bool Point2DPoint2D::isTopologicalRelationship(TopPredNumberPoint2DPoint2D predicate) {
    bool isPredicate = false;

    exploreTopoPred();

    isPredicate = evaluateVerificationTopoPred();

    return isPredicate;
}


TopPredNumberPoint2DPoint2D Point2DPoint2D::getTopologicalRelationship() {
    TopPredNumberPoint2DPoint2D predicate;

    // here call explore function
    exploreTopoPred();

    // here call evaluation function
    predicate = evaluateDeterminationTopoPred();



    return predicate;
}



void Point2DPoint2D::exploreTopoPred() {

    // this Explore algorithm below will set the vF and vG flag, but the function itself will return nothing (void).
    // the flag vF and vG set in the implementation below will be used by the "evaluateVerificationTopoPred" and "evaluateDeterminationTopoPred" function.

    // implementation...
    // ... do some work here
    //


}



bool Point2DPoint2D::evaluateVerificationTopoPred() {

    bool result = false;

    // implementation...
    // get vF and vG and evaluate them with 9IMC method
    // ... do some work here

    // followed by Matrix Thinning
    // ... do some work here

    //result:     result = ...


    return result;
}

TopPredNumberPoint2DPoint2D Point2DPoint2D::evaluateDeterminationTopoPred() {
    TopPredNumberPoint2DPoint2D predicate;

    // predicate is temporary set to "pp_overlap_m5", until this method is fully implemented
    predicate = TopPredNumberPoint2DPoint2D::pp_overlap_m5;


    // implementation...
    // get vF and vG and evaluate them with 9IMC method
    // ... do some work here

    // followed by MCDT
    // ... do some work here

    //result:     predicate = ...

    return predicate;
}

