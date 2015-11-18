//
// Created by Djundi on 11/3/15.
//

#ifndef PLANESWEEP_PROJECT_PLANESWEEP_H
#define PLANESWEEP_PROJECT_PLANESWEEP_H


#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic2/Implementation/RobustGeometricPrimitives2D.h"
#include "Topic2/Implementation/Number.h"
#include "Region2D.h"

#include "Object2D.h"
#include "ParallelObjectTraversal.h"
#include "Obj2D.h"
#include "AVL.h"
#include "Attribute.h"


class PlaneSweep {


public:
    PlaneSweep(Object2D, Object2D);

    ~PlaneSweep();


    ParallelObjectTraversal *getPot() const {
        return pot;
    }

	//Should increment the object pointers within either/both of the two objects.
    void select_first();
    void select_next();
    
    //Return the values of the object or status variables from the ParallelObjectTraversal Class
    ParallelObjectTraversal::object getObject();
    ParallelObjectTraversal::status getStatus();
    
    //Returns the value of the current "event" on the "sweep line status" datastructure
    //Object2D getEvent();
    Obj2D getEvent(Object2D);

    //Returns a new sweep line as an AVL Tree
    void new_sweep();
    void add_left(Seg2D&);
    void del_right(Seg2D&);
    Attribute get_attr(Seg2D&);
    void set_attr(Seg2D&,Attribute);

private:
    // only one instance of ParallelObjectTraversal exist!
    ParallelObjectTraversal * pot;
    AVL<Number,Seg2D&> *sweepline;

};


#endif //PLANESWEEP_PROJECT_PLANESWEEP_H
