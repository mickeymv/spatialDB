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
#include "POT.h"

class ParallelObjectTraversal {

public:
    ParallelObjectTraversal(Object2D &, Object2D &);
    virtual ~ParallelObjectTraversal() { }

};


#endif //SPATIAL_PREDICATES_PARALLELOBJECTTRAVERSAL_H
