/******************************************************************************
* File: SegmentClass.h
*******************************************************************************
* Purpose: Interface to the class SegmentClass
*
* Description: This class handles the segment class, which is a pair (m/n) of
* overlap numbers, a lower (or right) one m and an upper (or left) one n. It
* contains the set of overlap numbers used to define a particular line segment.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef PLANESWEEP_PROJECT_SEGMENTCLASS_H
#define PLANESWEEP_PROJECT_SEGMENTCLASS_H


class SegmentClass {

    int lowerOrRight, upperOrLeft;

public:

    // Default constructor. It initializes lowerOrRight and upperOrLeft to 0.
    SegmentClass();

    // Constructor that sets lowerOrRight and upperOrLeft to values passed as parameter.
    SegmentClass(int lOrR, int uOrL);

    // Getter method for lowerOrRight value.
    int getLowerOrRight();

    // Getter method for upperOrLeft value.
    int getUpperOrLeft();

    // Setter method for lowerOrRight value.
    void setLowerOrRight(int lOrR);

    // Setter method for upperOrLeft value.
    void setUpperOrLeft(int uOrL);

    // Destructor
    ~SegmentClass();
};


#endif //PLANESWEEP_PROJECT_SEGMENTCLASS_H
