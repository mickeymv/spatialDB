/******************************************************************************
* File: main.cpp
*******************************************************************************
* Purpose:  main.cpp tests all the test cases for the avilable six topological predicate combinations.
*
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors :Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/


#include <iostream>

using namespace std;

#include "TestPoint2DPoint2D.h"
#include "TestPoint2DLine2D.h"
#include "TestPoint2DRegion2D.h"
#include "TestRegion2DRegion2D.h"
#include "TestLine2DLine2D.h"
#include "TestLine2DRegion2D.h"


// Group 4: Topological Predicates test cases
//
// Test cases for Point2DPoint2D, Point2DLine2D, Point2DRegion2D,
//            Line2DLine2D, Line2DRegion2D, Region2DRegion2D
//

int main() {

    // 1. Point2DPoint2D test cases
    TestPoint2DPoint2D testPoint2DPoint2D;
    testPoint2DPoint2D.start();

    // 2. Point2DLine2D test cases
    TestPoint2DLine2D testPoint2DLine2D;
    testPoint2DLine2D.start();

    // 3. Line2DLine2D test cases
    TestLine2DLine2D testLine2DLine2D;
    testLine2DLine2D.start();

    // 4. Point2DRegion2D test cases
    TestPoint2DRegion2D testPoint2DRegion2D;
    testPoint2DRegion2D.start();

    // 5. Region2DRegion2D test cases
    TestRegion2DRegion2D testRegion2DRegion2D;
    testRegion2DRegion2D.start();

    // 6. Line2DRegion2D test cases
    TestLine2DRegion2D testLine2DRegion2D;
    testLine2DRegion2D.start();

    return 0;
}









