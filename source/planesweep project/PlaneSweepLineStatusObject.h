//
// Created by Mickey Vellukunnel on 11/21/15.
// Class to hold each node in the PlaneSweepLineStatus data structure (AVL tree).

#ifndef PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
#define PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H


#include "SegmentClass.h"
#include "Topic2/Implementation/Point2D.h"
#include "ParallelObjectTraversal.h"

class PlaneSweepLineStatusObject {

    SegmentClass segmentClass;
    Seg2D segment2D;
    bool insideAbove;

    //To determine which object this segment is from.
    ParallelObjectTraversal::object objectValue;

public:

    PlaneSweepLineStatusObject() {
        //default behaviour
        setInsideAbove(false);
        setSegmentClass(0,0);
    }

    PlaneSweepLineStatusObject(Seg2D& seg2D) {
        setSegment2D(seg2D);
        //default behaviour for ia and segmentClass
        setInsideAbove(false);
        setSegmentClass(0,0);
    }

    bool operator<(PlaneSweepLineStatusObject &operand);

    bool operator>(PlaneSweepLineStatusObject &operand);

    bool operator==(PlaneSweepLineStatusObject &operand);

    SegmentClass getSegmentClass() {
        return segmentClass;
    }

    void setSegmentClass(int lOrR, int uOrL) {
        segmentClass.setLowerOrRight(lOrR);
        segmentClass.setUpperOrLeft(uOrL);
    }

    Seg2D getSegment2D() {
        return segment2D;
    }

    void setSegment2D(Seg2D line) {
        segment2D = line;
    }

    bool getInsideAbove() {
        return insideAbove;
    }

    void setInsideAbove(bool ia) {
        insideAbove = ia;
    }

    void setObject(ParallelObjectTraversal::object object) {
        objectValue = object;
    }

    ParallelObjectTraversal::object getObject() {
        return objectValue;
    }
};


#endif //PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
