/******************************************************************************
* File: SegmentClass.cpp
*******************************************************************************
* Purpose: Implementation of the class SegmentClass
*
* Description: This class handles the segment class, which is a pair (m/n) of
* overlap numbers, a lower (or right) one m and an upper (or left) one n.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*
* Date: Fall Semester 2015
******************************************************************************/

#include "SegmentClass.h"

// Default constructor. It initializes lowerOrRight and upperOrLeft to 0.
SegmentClass::SegmentClass() {
    //default
    lowerOrRight = 0;
    upperOrLeft = 0;
}

// Constructor that sets lowerOrRight and upperOrLeft to values passed as parameter.
SegmentClass::SegmentClass(int lOrR, int uOrL) {
    lowerOrRight = lOrR;
    upperOrLeft = uOrL;
}

// Getter method for lowerOrRight value.
int SegmentClass::getLowerOrRight() {
    return lowerOrRight;
}

// Getter method for upperOrLeft value.
int SegmentClass::getUpperOrLeft() {
    return upperOrLeft;
}

// Setter method for lowerOrRight value.
void SegmentClass::setLowerOrRight(int lOrR) {
    lowerOrRight = lOrR;
}

// Setter method for upperOrLeft value.
void SegmentClass::setUpperOrLeft(int uOrL) {
    upperOrLeft = uOrL;
}

// Destructor
SegmentClass::~SegmentClass() {
}