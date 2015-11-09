//
// Created by Djundi on 11/3/15.
//

#ifndef SPATIAL_PREDICATES_POT_H
#define SPATIAL_PREDICATES_POT_H

#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"



// since we do not have any base class for the spatial objects, we use template class
// class spatial2DObj is the base template class for the F and G objects


// class IPOT is the base class for the POT implementation
// it should contain all the basic stuffs for POT, but each of the spatial object combination can overide or add any needed methods
class IPOT {

public:
    IPOT() {
        // create vF and vG and initialize them with false ???
    }
//    IPOT(Object2D &F, Object2D &G) {
//        // create vF and vG and initialize them with false.
//    };


    virtual ~IPOT(){};

    virtual void select_first() { };

    virtual void select_next() { };



    // here we declare all enums we need that can be shared for all spatial object combinations,
    // we declare specific enums only within the respective child classes
    typedef enum  {
        none, first, second, both
    } object;

    typedef enum  {
        end_of_none, end_of_first, end_of_second, end_of_both
    } status;

    virtual object getObject();
    virtual status getStatus();

    // get vector array vF
    virtual bool *getVF() = 0;

//    // get vector array vG
    virtual bool *getVG() = 0;

    // returns the size of vector F (or vector G, they both have the same size)
    virtual const size_t getVFGSize() = 0;
};




#endif //SPATIAL_PREDICATES_POT_H
