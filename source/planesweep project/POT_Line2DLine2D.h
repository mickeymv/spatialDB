//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POT_LINE2DLINE2D_H
#define PLANESWEEP_PROJECT_POT_LINE2DLINE2D_H


#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

#include "IPOT.h"

// *** begin test temp
using namespace std;

#include <iostream>
// *** end test temp


class POT_Line2DLine2D : public IPOT {

public:
    POT_Line2DLine2D(Object2D &F, Object2D &G);

    virtual ~POT_Line2DLine2D() { };

    virtual void select_first() { }

    virtual void select_next() { }


    // operations below are to be defined (still missing return types) and implemented
    // refer to Aswini's document dated 11/07/2015
    //
    // new_sweep();
    // get_event(F/G)
    // add_left(S,s)
    // del_right (S,s)
    // look_ahead(h,G/F)


    // predicates enum
    enum Predicates {
        seg_shared, interior_poi_shared, seg_unshared, bound_on_interior, bound_shared, bound_disjoint, PREDICATE_COUNT
    };

private:
    Line2D objF, objG;

    bool vF[PREDICATE_COUNT];
    bool vG[PREDICATE_COUNT];


public:
    // get vector array vF
    virtual bool *getVF();

    // get vector array vG
    virtual bool *getVG();

    // returns the size of vector F (or vector G, they both have the same size)
    virtual const size_t getVFGSize();
};


#endif //PLANESWEEP_PROJECT_POT_LINE2DLINE2D_H
