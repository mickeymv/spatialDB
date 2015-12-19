//
// Created by Djundi on 12/18/15.
//

#include "TestPoint2DRegion2D.h"

void TestPoint2DRegion2D::start() {


    // *****************************
    // Case 3: Point2DRegion2D
    // *****************************


    Point2D *p1;
    Region2D *r1;
    TopPredNumberPoint2DRegion2D tpredpr;
    bool result = false;

    cout << "Test begins..." << endl << endl;


    // 1. Test pr_disjoint_m1, F and G same number of elements
    p1 = new Point2D("((0,0),(3,3),(2,2))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Point2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pr_disjoint_m1" << endl;
    cout << "Point2D(\"((0,0),(3,3),(2,2))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;

    tpredpr = getTopologicalRelationship(*p1, *r1);

    printPredicate(tpredpr);
    result = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_disjoint_m1);

    cout << "   isTopologicalRelationship(a, b, pr_disjoint_m1) ==> " << printBool(result) << endl;

    cout << "   disjoint() ==> " << printBool(disjoint(*p1, *r1)) << endl;
    cout << endl;

    // don't forget to cleanup
    delete p1;
    delete r1;


    // 2. Test pr_overlap_m7
    p1 = new Point2D("((0,0),(1,1),(2,5))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    cout << "2. pr_overlap_m7" << endl;
    cout << "Point2D(\"((0,0),(3,3),(2,5))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;
    cout << "   getTopologicalRelationship(p1, r1) :" << endl;

    tpredpr = getTopologicalRelationship(*p1, *r1);
    printPredicate(tpredpr);

    result = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_overlap_m7);
    cout << "   isTopologicalRelationship(p1, r1, pr_overlap_m7) ==> " << printBool(result) << endl;

    cout << "   overlap() ==> " << printBool(overlap(*p1, *r1)) << endl;
    cout << endl;

    delete p1;
    delete r1;


    // 3. pr_meet_m2
    p1 = new Point2D("((4,3))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    cout << "3. Test pr_meet_m2" << endl;
    cout << "Point2D(\"((4,3))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;

    tpredpr = getTopologicalRelationship(*p1, *r1);
    printPredicate(tpredpr);

    result = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_meet_m2);
    cout << "   isTopologicalRelationship(a, b, pr_meet_m2) ==> " << printBool(result) << endl;

    cout << "   meet() ==> " << printBool(touch(*p1, *r1)) << endl << endl;

    delete p1;
    delete r1;


    // 4. Test pr_inside_m4
    p1 = new Point2D("((2,5))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    cout << "4. Test pr_inside_m4" << endl;
    cout << "Point2D(\"((0,0),(3,3),(6,6))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;

    tpredpr = getTopologicalRelationship(*p1, *r1);
    printPredicate(tpredpr);

    result = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_inside_m4);
    cout << "   isTopologicalRelationship(p1, r1,pr_inside_m4) ==> " << printBool(result) << endl;

    cout << "   inside() ==> " << printBool(inside(*p1, *r1)) << endl;
    cout << endl;

    // don't forget to cleanup
    delete p1;
    delete r1;


    cout << "Test succesfully ended." << endl;

}
