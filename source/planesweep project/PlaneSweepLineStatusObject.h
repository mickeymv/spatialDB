//
// Created by Mickey Vellukunnel on 11/21/15.
// Class to hold each node in the PlaneSweepLineStatus data structure (AVL tree).

#ifndef PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
#define PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H


#include "SegmentClass.h"
#include "Topic2/Implementation/Point2D.h"

class PlaneSweepLineStatusObject {

    SegmentClass segmentClass;
    Seg2D segment2D;
    bool insideAbove;

public:

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
};


#endif //PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
