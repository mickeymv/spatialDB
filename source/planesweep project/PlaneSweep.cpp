//
// Created by Djundi on 11/3/15.
//

#include "PlaneSweep.h"

PlaneSweep::PlaneSweep(Object2D objF, Object2D objG) {
   pot = new ParallelObjectTraversal(objF, objG);

}
