//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POT_POINT2DPOINT2D_H
#define PLANESWEEP_PROJECT_POT_POINT2DPOINT2D_H


#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

#include "IPOT.h"


class POT_Point2DPoint2D : public IPOT {

public:
    POT_Point2DPoint2D(Object2D &F, Object2D &G);

    virtual ~POT_Point2DPoint2D();

    virtual void select_first();

    virtual void select_next();

    virtual object getObject();

    virtual status getStatus();

    // TODO: declare required predicates for Point2D/Point2D
    // ...




    // predicates enum
    enum Predicates {
        poi_disjoint, poi_shared, PREDICATE_COUNT
    };

    // get vector array vF
    virtual bool *getVF();

    // get vector array vG
    virtual bool *getVG();

    // returns the size of vector F (or vector G, they both have the same size)
    virtual const size_t getVFGSize();

private:
    Point2D objF, objG;
    Point2D::ConstPoiIterator objFPoiIterator, objGPoiIterator;

    bool vF[PREDICATE_COUNT];
    bool vG[PREDICATE_COUNT];

};


#endif //PLANESWEEP_PROJECT_POT_POINT2DPOINT2D_H
