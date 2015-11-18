//
// Created by Djundi on 11/8/15.
//

#include "Line2DRegion2D.h"

Line2DRegion2D::Line2DRegion2D(Object2D &F, Object2D &G) {
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

Line2DRegion2D::~Line2DRegion2D() { };


bool *Line2DRegion2D::getVF() {
    return vF;
}

bool *Line2DRegion2D::getVG() {
    return vG;
}

bool Line2DRegion2D::Explore() {
    return true; // return true if no error, else false
}
