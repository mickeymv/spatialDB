//
// Created by Mickey Vellukunnel on 11/21/15.
//

#include "SegmentClass.h"

SegmentClass::SegmentClass()
{
    //default
    lowerOrRight = 0;
    upperOrLeft = 0;
}

SegmentClass::SegmentClass(int lOrR, int uOrL)
{
    lowerOrRight = lOrR;
    upperOrLeft = uOrL;
}

int SegmentClass::getLowerOrRight()
{
  return lowerOrRight;
}

int SegmentClass::getUpperOrLeft()
{
  return upperOrLeft;
}

void SegmentClass::setLowerOrRight(int lOrR)
{
  lowerOrRight = lOrR;
}

void SegmentClass::setUpperOrLeft(int uOrL)
{
  upperOrLeft = uOrL;
}

SegmentClass::~SegmentClass()
{
}