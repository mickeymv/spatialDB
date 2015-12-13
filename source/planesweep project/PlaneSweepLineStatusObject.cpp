//
// Created by Mickey Vellukunnel on 11/21/15.
//

#include "PlaneSweepLineStatusObject.h"


bool PlaneSweepLineStatusObject::operator<(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D < operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

bool PlaneSweepLineStatusObject::operator>(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D > operand.segment2D) {
        return true;
    } else {
        return false;
    }
}


bool PlaneSweepLineStatusObject::operator==(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D == operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

bool PlaneSweepLineStatusObject::operator>=(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D >= operand.segment2D) {
        return true;
    } else {
        return false;
    }
}

bool PlaneSweepLineStatusObject::operator<=(PlaneSweepLineStatusObject &operand) {
    if (this->segment2D <= operand.segment2D) {
        return true;
    } else {
        return false;
    }
}


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