/******************************************************************************
* File: PlaneSweepLineStatusObject.cpp
*******************************************************************************
* Purpose: Implementation of PlaneSweepLineStatusObject
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

#include "PlaneSweepLineStatusObject.h"

/**
 * Method:      operator<
 * Description: Compares two segments and returns true if the segment on the
 *              left side of the operator is smaller than the one on the right
 *              side of the operator.
 * Parameters:  PlaneSweepLineStatusObject
 * Returns:     bool
 */
bool PlaneSweepLineStatusObject::operator<(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D < operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

/**
 * Method:      operator>
 * Description: Compares two segments and returns true if the segment on the
 *              left side of the operator is larger than the one on the right
 *              side of the operator.
 * Parameters:  PlaneSweepLineStatusObject
 * Returns:     bool
 */
bool PlaneSweepLineStatusObject::operator>(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D > operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

/**
 * Method:      operator==
 * Description: Compares two segments and returns true if the segment on the
 *              left side of the operator is equal to the one on the right
 *              side of the operator.
 * Parameters:  PlaneSweepLineStatusObject
 * Returns:     bool
 */
bool PlaneSweepLineStatusObject::operator==(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D == operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

/**
 * Method:      operator>=
 * Description: Compares two segments and returns true if the segment on the
 *              left side of the operator is larger than or equal to the one
 *              on the right side of the operator.
 * Parameters:  PlaneSweepLineStatusObject
 * Returns:     bool
 */
bool PlaneSweepLineStatusObject::operator>=(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D >= operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

/**
 * Method:      operator<=
 * Description: Compares two segments and returns true if the segment on the
 *              left side of the operator is smaller than or equal to the one
 *              on the right side of the operator.
 * Parameters:  PlaneSweepLineStatusObject
 * Returns:     bool
 */
bool PlaneSweepLineStatusObject::operator<=(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D <= operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

/**
 * Method:      operator =
 * Description: Assignment operator, overloaded to assign the object value,
 *              segment class, insideAbove flag and the segment.
 * Parameters:  PlaneSweepLineStatusObject
 * Returns:     PlaneSweepLineStatusObject
 */
PlaneSweepLineStatusObject PlaneSweepLineStatusObject::operator = (PlaneSweepLineStatusObject& obj)
{
    if (this != &obj)
    {
        this->objectValue = obj.getObject();
        this->segmentClass = obj.segmentClass;
        this->insideAbove = obj.insideAbove;
        this->segment2D = obj.segment2D;
    }
    return *this;
}