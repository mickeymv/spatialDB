//
// Created by Mickey Vellukunnel on 11/21/15.
// Class to hold each node in the PlaneSweepLineStatus data structure (AVL tree).

#ifndef PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
#define PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H


class PlaneSweepLineStatusObject {

    SegmentClass segmentClass;
    Point2D point2D;
    Line2D segment2D;

public:

    SegmentClass getSegmentClass() {
        return segmentClass;
    }

    void setSegmentClass(int lOrR, int uOrL) {
        segmentClass(lOrR, uOrL);
    }

    Point2D getPoint2D() {
        return point2D;
    }

    void setPoint2D(Point2D point) {
        point2D = point;
    }

    Line2D getSegment2D() {
        return segment2D;
    }

    void setSegment2D(Line2D line) {
        segment2D = line;
    }
};


#endif //PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
