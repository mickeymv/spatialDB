//
// Created by Djundi on 11/3/15.
//

#ifndef SPATIAL_PREDICATES_PLANESWEEP_H
#define SPATIAL_PREDICATES_PLANESWEEP_H


#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

#include "Object2D.h"
#include "ParallelObjectTraversal.h"



class PlaneSweep {


public:
    PlaneSweep(Object2D, Object2D);

    virtual ~PlaneSweep();


    ParallelObjectTraversal *getPot() const {
        return pot;
    }

    // get vector array vF
    const bool *getVF();

    // get vector array vG
    const bool *getVG();

    // returns the size of vector F (or vector G, they both have the same size)
    const size_t getVFGSize();

private:
    // only one instance of ParallelObjectTraversal exist!
    ParallelObjectTraversal * pot;

};


#endif //SPATIAL_PREDICATES_PLANESWEEP_H
