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

    PlaneSweepLineStatusObject();

    PlaneSweepLineStatusObject(Seg2D& seg2D);

    bool operator<(PlaneSweepLineStatusObject &operand);

    bool operator>(PlaneSweepLineStatusObject &operand);

    bool operator==(PlaneSweepLineStatusObject &operand);

    SegmentClass getSegmentClass();

    void setSegmentClass(int lOrR, int uOrL);

    Seg2D getSegment2D();

    void setSegment2D(Seg2D line);

    bool getInsideAbove();

    void setInsideAbove(bool ia);

    void setObject(ParallelObjectTraversal::object object);

    ParallelObjectTraversal::object getObject();
};


#endif //PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
