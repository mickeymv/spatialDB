//
// Created by Djundi on 11/8/15.
//

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