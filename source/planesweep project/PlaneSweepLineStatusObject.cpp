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

PlaneSweepLineStatusObject::PlaneSweepLineStatusObject() {
    //default behaviour
    setInsideAbove(false);
    setSegmentClass(0,0);
}

PlaneSweepLineStatusObject::PlaneSweepLineStatusObject(Seg2D& seg2D) {
setSegment2D(seg2D);
//default behaviour for ia and segmentClass
setInsideAbove(false);
setSegmentClass(0,0);
}


SegmentClass PlaneSweepLineStatusObject::getSegmentClass() {
    return segmentClass;
}

void PlaneSweepLineStatusObject::setSegmentClass(int lOrR, int uOrL) {
    segmentClass.setLowerOrRight(lOrR);
    segmentClass.setUpperOrLeft(uOrL);
}

Seg2D PlaneSweepLineStatusObject::getSegment2D() {
    return segment2D;
}

void PlaneSweepLineStatusObject::setSegment2D(Seg2D line) {
    segment2D = line;
}

bool PlaneSweepLineStatusObject::getInsideAbove() {
    return insideAbove;
}

void PlaneSweepLineStatusObject::setInsideAbove(bool ia) {
    insideAbove = ia;
}

void PlaneSweepLineStatusObject::setObject(ParallelObjectTraversal::object object) {
    objectValue = object;
}

ParallelObjectTraversal::object PlaneSweepLineStatusObject::getObject() {
    return objectValue;
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