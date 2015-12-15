/******************************************************************************
* File: PlaneSweepLineStatusObject.h
*******************************************************************************
* Purpose: Interface to the class PlaneSweepLineStatusObject
*
* Description: This class holds each node in the PlaneSweepLineStatus data structure.
* It contains overloaded operators to compare two segment2D objects.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
#define PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H


#include "SegmentClass.h"
#include "Topic2/Implementation/Point2D.h"
#include "ParallelObjectTraversal.h"

class PlaneSweepLineStatusObject {

    SegmentClass segmentClass;
    Seg2D segment2D;
    bool insideAbove;

    //To determine which object this segment is from. Only have first/second (NOT none/both)
    ParallelObjectTraversal::object objectValue;

public:

    /**
     * Default constructor. Its default behavior is to initialize the segmentClass object
     * to (0,0) and the insideAbove flag to false.
     */
    PlaneSweepLineStatusObject() {
        // default behaviour
        setInsideAbove(false);
        setSegmentClass(0,0);
    }

    /**
     * Parameterized constructor. It uses a segment2D parameter to initialize the
     * segment component of the plane sweep status object. The initialization of the
     * segment class and the insideAbove flag follows the default behavior.
     */
    PlaneSweepLineStatusObject(Seg2D& seg2D) {
        setSegment2D(seg2D);
        //default behaviour for ia and segmentClass
        setInsideAbove(false);
        setSegmentClass(0,0);
    }

    /**
    * Method:      operator<
    * Description: Compares two segments and returns true if the segment on the
    *              left side of the operator is smaller than the one on the right
    *              side of the operator.
    * Parameters:  PlaneSweepLineStatusObject
    * Returns:     bool
    */
    bool operator<(PlaneSweepLineStatusObject &operand);

    /**
    * Method:      operator>
    * Description: Compares two segments and returns true if the segment on the
    *              left side of the operator is larger than the one on the right
    *              side of the operator.
    * Parameters:  PlaneSweepLineStatusObject
    * Returns:     bool
    */
    bool operator>(PlaneSweepLineStatusObject &operand);

    /**
    * Method:      operator==
    * Description: Compares two segments and returns true if the segment on the
    *              left side of the operator is equal to the one on the right
    *              side of the operator.
    * Parameters:  PlaneSweepLineStatusObject
    * Returns:     bool
    */
    bool operator==(PlaneSweepLineStatusObject &operand);

    /**
    * Method:      operator>=
    * Description: Compares two segments and returns true if the segment on the
    *              left side of the operator is larger than or equal to the one
    *              on the right side of the operator.
    * Parameters:  PlaneSweepLineStatusObject
    * Returns:     bool
    */
    bool operator>=(PlaneSweepLineStatusObject &operand);

    /**
    * Method:      operator<=
    * Description: Compares two segments and returns true if the segment on the
    *              left side of the operator is smaller than or equal to the one
    *              on the right side of the operator.
    * Parameters:  PlaneSweepLineStatusObject
    * Returns:     bool
    */
    bool operator<=(PlaneSweepLineStatusObject &operand);

    /**
    * Method:      operator =
    * Description: Assignment operator, overloaded to assign the object value,
    *              segment class, insideAbove flag and the segment.
    * Parameters:  PlaneSweepLineStatusObject
    * Returns:     PlaneSweepLineStatusObject
    */
    PlaneSweepLineStatusObject operator=(PlaneSweepLineStatusObject &operand);

    // Getter method for segmentClass
    SegmentClass getSegmentClass() {
        return segmentClass;
    }

    // Setter method for segmentClass
    void setSegmentClass(int lOrR, int uOrL) {
        segmentClass.setLowerOrRight(lOrR);
        segmentClass.setUpperOrLeft(uOrL);
    }

    // Getter method for segment2D object
    Seg2D getSegment2D() {
        return segment2D;
    }

    // Setter method for segment2D object
    void setSegment2D(Seg2D line) {
        segment2D = line;
    }

    // Getter method for insideAbove flag
    bool getInsideAbove() {
        return insideAbove;
    }

    // Setter method for insideAbove flag
    void setInsideAbove(bool ia) {
        insideAbove = ia;
    }

    // Setter method for POT object
    void setObject(ParallelObjectTraversal::object object) {
        objectValue = object;
    }

    // Getter method for POT object
    ParallelObjectTraversal::object getObject() {
        return objectValue;
    }
};


#endif //PLANESWEEP_PROJECT_PLANESWEEPSTATUSOBJECT_H
