//
// Created by Mickey Vellukunnel on 11/21/15.
// Class to contain the set of overlap numbers used to
// define a particular line segment.
//

#ifndef PLANESWEEP_PROJECT_SEGMENTCLASS_H
#define PLANESWEEP_PROJECT_SEGMENTCLASS_H


class SegmentClass {

    int lowerOrRight, upperOrLeft;
    SegmentClass(int lOrR, int uOrL) {
        lowerOrRight = lOrR;
        upperOrLeft = uOrL;
    }

public:
    int getLowerOrRight() {
        return lowerOrRight;
    }
    int getUpperOrLeft() {
        return upperOrLeft;
    }

    void setLowerOrRight(int lOrR) {
         lowerOrRight = lOrR;
    }

    void getUpperOrLeft(int uOrL) {
         upperOrLeft = uOrL;
    }
};


#endif //PLANESWEEP_PROJECT_SEGMENTCLASS_H
