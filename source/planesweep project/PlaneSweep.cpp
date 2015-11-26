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

void PlaneSweep::selectNext() {
    //needs implementation based on object types
    return getPot()->selectNext();
}

ParallelObjectTraversal::object  PlaneSweep::getObject() {
    // temporary, to be replaced
    return getPot()->getObject();

}

ParallelObjectTraversal::status  PlaneSweep::getStatus() {
    // temporary, to be replaced
    return getPot()->getStatus();
}

void PlaneSweep::calculateRelation(Seg2D) {

}

//Assumption - firstSegment is from object F and secondSegment is from object G
//Will add dynamic insertion after min heap class is inserted here
void PlaneSweep::splitLines(Seg2D firstSegment, Seg2D secondSegment) {
    if (Intersects(firstSegment, secondSegment)) {
        Poi2D mp = IntersectionPoint(firstSegment, secondSegment);
        Seg2D S11(firstSegment.p1, mp);
        Seg2D S21(secondSegment.p1, mp);
        Seg2D S12(mp, firstSegment.p2);
        Seg2D S22(mp, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S21);

    }
    else if (Touch(firstSegment, secondSegment)) {
        Poi2D tp = TouchingPoint(firstSegment, secondSegment);
        Seg2D S11(firstSegment.p1, tp);
        Seg2D S21(secondSegment.p1, tp);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S21);

        if (LiesOnRightEndPointOfSegment(tp, secondSegment)) {
            Seg2D S12(tp, firstSegment.p1);
        }
        else if (LiesOnRightEndPointOfSegment(tp, firstSegment)) {
            Seg2D S22(tp, secondSegment.p2);
        }
    }
    else if (IsCollinearAndMeetsLeftEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p2);
        Seg2D S12(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S11);
    }
    else if (IsCollinearAndMeetsLeftEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p2);
        Seg2D S22(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(secondSegment, S21);
        updateSweepLineStatus(firstSegment, S21);
    }
    else if (LiesOn(firstSegment, secondSegment) && IsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
             IsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);
        Seg2D S13(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);
    }
    else if (LiesOn(secondSegment, firstSegment) && IsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
             IsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);
        Seg2D S23(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S21);
        updateSweepLineStatus(secondSegment, S22);
    }
    else if (IsCollinearAndMeetsRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);
    }
    else if (IsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);
    }

}

/*
Poi2D PlaneSweep::getPoiEvent(ParallelObjectTraversal::object objectValue){
    ObjectIterator *pos = getPot()->getObjIterator(object);
    Point2D::ConstPoiIterator *val = dynamic_cast<Point2D::ConstPoiIterator *>(pos);
    Poi2D poi2D = val->operator*();
    return poi2D;
}
*/


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