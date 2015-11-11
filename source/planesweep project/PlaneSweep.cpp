//
// Created by Djundi on 11/3/15.
//

//test edit


#include "PlaneSweep.h"

PlaneSweep::PlaneSweep(Object2D objF, Object2D objG) {
   pot = new ParallelObjectTraversal(objF, objG);

}

PlaneSweep::~PlaneSweep() {
    delete pot;
}


const bool *PlaneSweep::getVF() {
    return pot->getVF();
}

// get vector array vG
const bool *PlaneSweep::getVG() {
    return pot->getVG();
}

// returns the size of vector F (or vector G, they both have the same size)
const size_t PlaneSweep::getVFGSize() {
    return pot->getVFGSize();
}

void selectNext() { 
    //needs implementation based on object types
    return getPOT().selectNext();
    };

object getObject() {
  // temporary, to be replaced
    return getPot().getObject();

};

status getStatus()
{
  // temporary, to be replaced
    return getPot().getStatus();
};
