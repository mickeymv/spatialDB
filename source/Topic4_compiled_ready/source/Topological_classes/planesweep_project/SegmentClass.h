//
// Created by Mickey Vellukunnel on 11/21/15.
// Class to contain the set of overlap numbers used to
// define a particular line segment.
//

#ifndef PLANESWEEP_PROJECT_SEGMENTCLASS_H
#define PLANESWEEP_PROJECT_SEGMENTCLASS_H


class SegmentClass {

    int lowerOrRight, upperOrLeft;

public:

    SegmentClass();

    SegmentClass(int lOrR, int uOrL);

    int getLowerOrRight();

    int getUpperOrLeft();

    void setLowerOrRight(int lOrR);

    void setUpperOrLeft(int uOrL);

    ~SegmentClass();
};


#endif //PLANESWEEP_PROJECT_SEGMENTCLASS_H