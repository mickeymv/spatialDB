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

	//Should increment the object pointers within either/both of the two objects.
    void select_first() { 
    //needs implementation based on object types
    };
    void select_next() { 
    //needs implementation based on object types
    };
    
    //Return the values of the object or status variables from the ParallelObjectTraversal Class
    object getObject();
    status getStatus();
    
    //Returns the value of the current "event" on the "sweep line status" datastructure
    Object2D getEvent() {
    	//Return either a poi2D or a seg2D depending on the object combination and the 
    	// sweep line status instance.
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
