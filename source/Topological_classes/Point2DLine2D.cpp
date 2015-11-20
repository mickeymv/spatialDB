//
// Created by Djundi on 11/8/15.
//

#include "Point2DLine2D.h"


Point2DLine2D::Point2DLine2D(Object2D &F, Object2D &G) {
    // set obj1 and obj2
    F.set(objF);
    G.set(objG);

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

};

Point2DLine2D::~Point2DLine2D() { };


bool *Point2DLine2D::getVF() {
    return vF;
}

bool *Point2DLine2D::getVG() {
    return vG;
}

bool Point2DLine2D::Explore() {
    return true; // return true if no error, else false
}