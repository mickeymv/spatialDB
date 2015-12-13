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