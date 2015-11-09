//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POT_REGION2DREGION2D_H
#define PLANESWEEP_PROJECT_POT_REGION2DREGION2D_H

#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

#include "IPOT.h"

class POT_Region2DRegion2D : public IPOT {

public:
    POT_Region2DRegion2D(Object2D &, Object2D &) { }

    virtual ~POT_Region2DRegion2D() { }

    virtual void select_first() { }

    virtual void select_next() { }

    // declare required predicates for Line2DLine2D
    // ...

    // TODO: replace below for predicates enum e.g. enum { ... ,  ... , PREDICATE_COUNT };
    enum {
        PREDICATE_COUNT
    };

    // get vector array vF
    virtual bool *getVF() { }

    // get vector array vG
    virtual bool *getVG() { }

    // returns the size of vector F (or vector G, they both have the same size)
    virtual const size_t getVFGSize() { }


private:
    Region2D objF, objG;

    bool vF[PREDICATE_COUNT];
    bool vG[PREDICATE_COUNT];
};


#endif //PLANESWEEP_PROJECT_POT_REGION2DREGION2D_H
