//
// Created by Djundi on 11/8/15.
//

#include "POT_Line2DLine2D.h"

POT_Line2DLine2D::POT_Line2DLine2D(Object2D &F, Object2D &G) {
    // set obj1 and obj2
    F.set(objF);
    G.set(objG);

    // initialize vF and vG with false
    for (int i = 0; i < getVFGSize(); i++) {
        vF[i] = false;
        vG[i] = false;
    }

}

bool *POT_Line2DLine2D::getVF() {
    return vF;
}

bool *POT_Line2DLine2D::getVG() {
    return vG;
}


const size_t POT_Line2DLine2D::getVFGSize() {
    return PREDICATE_COUNT;
}
