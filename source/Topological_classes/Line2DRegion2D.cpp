//
// Created by Djundi on 11/8/15.
//

#include "Line2DRegion2D.h"

Line2DRegion2D::Line2DRegion2D(Line2D &F, Region2D &G) {
    // set obj1 and obj2
    objF = F;
    objG = G;

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

};

Line2DRegion2D::~Line2DRegion2D() { };


bool *Line2DRegion2D::getVF() {
    return vF;
}

bool *Line2DRegion2D::getVG() {
    return vG;
}

void Line2DRegion2D::exploreTopoPred() {

}

void Line2DRegion2D::evaluateTopoPred() {

}

bool Line2DRegion2D::isTopologicalRelationship(TopPredNumberLine2DRegion2D predicate) {
    return false;
}

TopPredNumberLine2DRegion2D Line2DRegion2D::getTopologicalRelationship() {
    return lr_overlap_m34;
}

bool Line2DRegion2D::overlap() {
    return false;
}

bool Line2DRegion2D::disjoint() {
    return false;
}

bool Line2DRegion2D::meet() {
    return false;
}

bool Line2DRegion2D::equal() {
    return false;
}

bool Line2DRegion2D::contains() {
    return false;
}

bool Line2DRegion2D::covers() {
    return false;
}

bool Line2DRegion2D::coveredBy() {
    return false;
}

bool Line2DRegion2D::inside() {
    return false;
}
