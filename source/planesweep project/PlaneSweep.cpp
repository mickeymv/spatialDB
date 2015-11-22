//
// Created by Djundi on 11/3/15.
//

//test edit


#include "PlaneSweep.h"
#include "ObjectIterator.h"

PlaneSweep::PlaneSweep(Object2D objF, Object2D objG) {
   pot = new ParallelObjectTraversal(objF, objG);

}

PlaneSweep::~PlaneSweep() {
    delete pot;
}

void PlaneSweep::select_next() {
    //needs implementation based on object types
    return getPot()->selectNext();
}

ParallelObjectTraversal::object  PlaneSweep::getObject() {
    // temporary, to be replaced
    return getPot()->getObject();

}

ParallelObjectTraversal::status  PlaneSweep::getStatus()
{
    // temporary, to be replaced
    return getPot()->getStatus();
}

void PlaneSweep::new_sweep()
{
    sweepLineStatus = new AVL<Number,PlaneSweepLineStatusObject&>();
    return;
}


/*
 *  Change the following functions based on our discussion on Saturday
 *  11/21/15.
 */


/*


Obj2D PlaneSweep::getEvent(Object2D obj)
{
    //Return either a poi2D or a seg2D depending on the object combination and the
    // sweep line status instance.
    ObjectIterator * pos = getPot()->getObjIterator(obj);
    return *(pos);
}


void PlaneSweep::add_left(Seg2D& seg2D)
{
    sweepLineStatus->Insert(seg2D.p1.y,seg2D);
}

void PlaneSweep::del_right(Seg2D& seg2D)
{
    //sweepLineStatus->deleteKey(Seg2D.p2.y,Seg2D);
    sweepLineStatus->Remove(seg2D.p1.y);
}

Attribute PlaneSweep::get_attr(Seg2D& seg2D)
{
    Attribute attribute;
    if(sweepLineStatus->Find(seg2D.p1.y,seg2D)) {
        // Give attribute depending on type
        // Check if group 2 can give it
//    if(seg2D.attribute.isBool())
//    {
//
//    }
//    else if(seg2D.attribute.isSegClass())
//    {
//
//
//     }
    }
}

void PlaneSweep::set_attr(Seg2D & seg2D, Attribute attribute)
{
    if(sweepLineStatus->Find(seg2D.p1.y,seg2D)) {
        // seg2D.attribute=attribute;
    }
}
 */