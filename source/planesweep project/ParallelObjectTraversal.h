//
// Created by Djundi on 11/3/15.
//

#ifndef SPATIAL_PREDICATES_PARALLELOBJECTTRAVERSAL_H
#define SPATIAL_PREDICATES_PARALLELOBJECTTRAVERSAL_H

#include <memory>

#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

#include "Object2D.h"
#include "IPOT.h"

#include "POT_Point2DPoint2D.h"
#include "POT_Point2DLine2D.h"
#include "POT_Point2DRegion2D.h"
#include "POT_Line2DLine2D.h"
#include "POT_Line2DRegion2D.h"
#include "POT_Region2DRegion2D.h"



class ParallelObjectTraversal {

public:
    ParallelObjectTraversal(Object2D &, Object2D &);

    virtual ~ParallelObjectTraversal();


    // get vector array vF
    const bool *getVF();

    // get vector array vG
    const bool *getVG();

    // returns the size of vector F (or vector G, they both have the same size)
    const size_t getVFGSize();


    // explore methods
    // return value bool, true if no error. otherwise false
    bool ExplorePoint2DPoint2D(Object2D &F, Object2D &G);

    bool ExplorePoint2DLine2D(Object2D &F, Object2D &G);

    bool ExplorePoint2DRegion2D(Object2D &F, Object2D &G);

    bool ExploreLine2DLine2D(Object2D &F, Object2D &G);

    bool ExploreLine2DRegion2D(Object2D &F, Object2D &G);

    bool ExploreRegion2DRegion2D(Object2D &F, Object2D &G);


private:
    // spatial object combination objects
    POT_Point2DPoint2D *pp = nullptr;
    POT_Point2DLine2D *pl = nullptr;
    POT_Point2DRegion2D *pr = nullptr;
    POT_Line2DLine2D *ll = nullptr;
    POT_Line2DRegion2D *lr = nullptr;
    POT_Region2DRegion2D *rr = nullptr;

    // pointer to the vF and vG
    bool *vF;
    bool *vG;
    size_t sizeofvFG = 0;

};


#endif //SPATIAL_PREDICATES_PARALLELOBJECTTRAVERSAL_H
