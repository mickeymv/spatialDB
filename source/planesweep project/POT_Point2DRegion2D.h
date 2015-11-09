//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_POT_POINT2DREGION2D_H
#define PLANESWEEP_PROJECT_POT_POINT2DREGION2D_H

#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

#include "IPOT.h"


class POT_Point2DRegion2D : public IPOT {

public:
    POT_Point2DRegion2D(Object2D &, Object2D &) { }

    virtual ~POT_Point2DRegion2D() { }

    virtual void select_first() { }

    virtual void select_next() { }

    // declare required predicates for Line2DLine2D
    // ...

    // operations below are to be implemented
    // refer to Aswini's document dated 11/07/2015
    //
    // new_sweep();
    // get_event(F/G);
    // poi_on_seg(S,p)
    // pred_of_p(S,p);
    // current_exists(S);
    // add_left(S,s);
    // del_right (S,s);
    // get_attr(G);
    // set_attr(S,ia);


    // predicates enum
    enum {
        poi_inside, poi_outside, poi_on_bound, PREDICATE_COUNT
    };

    // get vector array vF
    virtual bool *getVF() { }

    // get vector array vG
    virtual bool *getVG() { }

    // returns the size of vector F (or vector G, they both have the same size)
    virtual const size_t getVFGSize() { }

private:
    Point2D objF;
    Region2D objG;

    bool vF[PREDICATE_COUNT];
    bool vG[PREDICATE_COUNT];
};


#endif //PLANESWEEP_PROJECT_POT_POINT2DREGION2D_H
