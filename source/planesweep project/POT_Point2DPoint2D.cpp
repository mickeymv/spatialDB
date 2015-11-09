//
// Created by Djundi on 11/8/15.
//

#include "POT_Point2DPoint2D.h"


POT_Point2DPoint2D::POT_Point2DPoint2D(Object2D &F, Object2D &G) : IPOT() {
    // set obj1 and obj2
    F.set(objF);
    G.set(objG);

    // initialize vF and vG with false
    for (int i = 0; i <= getVFGSize(); i++) {
        vF[i] = false;
        vG[i] = false;
    }


    // *** begin test temp
    vF[poi_shared] = true;
    // *** end test temp
};

POT_Point2DPoint2D::~POT_Point2DPoint2D() { };


// the use of the iterator needs to be verified with Group 2!
void POT_Point2DPoint2D::select_first() {
    objFPoiIterator = objF.cbegin();
    objGPoiIterator = objG.cbegin();

};

void POT_Point2DPoint2D::select_next() {
    objFPoiIterator++;
    objGPoiIterator++;
};


IPOT::object POT_Point2DPoint2D::getObject() {
    object o = object::none;

    // refer to p.331 in paper "Topological feature vectors for exploring topological relationships"
    if (not (objFPoiIterator.isEmpty() || objGPoiIterator.isEmpty())) if (objFPoiIterator == objGPoiIterator)
        o = object::both;
    else if (objFPoiIterator < objGPoiIterator) o = object::first;
    else o = object::second;

    return o;
};

IPOT::status POT_Point2DPoint2D::getStatus() {
    status s = status::end_of_none;

    if (objFPoiIterator == objF.ctail()) {
        if (objGPoiIterator == objG.ctail())
            s = status::end_of_both;
        else s = status::end_of_first;
    } else {
        if (objGPoiIterator == objG.ctail())
            s = status::end_of_second;
    }

    return s;
};


bool *POT_Point2DPoint2D::getVF() {
    return vF;
}

bool *POT_Point2DPoint2D::getVG() {
    return vG;
}


const size_t POT_Point2DPoint2D::getVFGSize() {
    // return the size of enum Predicates
    return PREDICATE_COUNT;
}