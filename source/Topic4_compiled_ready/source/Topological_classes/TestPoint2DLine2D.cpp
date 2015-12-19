//
// Created by Djundi on 12/18/15.
//

#include "TestPoint2DLine2D.h"

void TestPoint2DLine2D::start() {

    // *****************************
    // Case 2: Point2DLine2D
    // *****************************

    Point2D *apl;
    Line2D *bpl;
    TopPredNumberPoint2DLine2D tplred;
    bool result = false;

    cout << "Test begins..." << endl << endl;


    // 1. Test pl_disjoint, F and G same number of elements
    apl = new Point2D("((0,1),(2,2),(3,3))");
    bpl = new Line2D("(((4,4),(5,5)),((5,5),(6,6)),((6,6),(7,7)))");


    cout << "*****************************" << endl;
    cout << "Case 1: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pl_disjoint, F and G same number of elements." << endl;
    cout << "Point2D a(\"((0,1),(2,2),(3,3))\");" << endl;
    cout << "Line2D b(\"(((4,4),(5,5)),((5,5),(6,6)),((6,6),(7,7)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);
    printPredicate(tplred);


    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_disjoint_m2);
    cout << "   isTopologicalRelationship(a, b, pl_disjoint_m2) ==> " << printBool(result) << endl;
    cout << "   disjoint() ==> " << printBool(disjoint(*apl, *bpl)) << endl;
    cout << "   overlap() ==> " << printBool(overlap(*apl, *bpl)) << endl;
    cout << endl;

    // don't forget to cleanup
    delete apl;
    delete bpl;


    // 2. Test pl_meet, F and G same number of elements
    //Sort out
    apl = new Point2D("((1,1),(2,2),(3,3))");
    bpl = new Line2D("(((3,3),(5,5)),((5,5),(6,6)),((6,6),(7,7)))");


    //result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);
    cout << "*****************************" << endl;
    cout << "Case 2: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "2. Test pl_meet, F and G same number of elements." << endl;
    cout << "Point2D a(\"((1,1),(2,2),(3,3))\");" << endl;
    cout << "Line2D b(\"(((3,3),(5,5)),((5,5),(6,6)),((6,6),(7,7)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);
    printPredicate(tplred);

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_meet_m4);
    cout << "   isTopologicalRelationship(a, b, pl_meet_m4) ==> " << printBool(result) << endl;

    cout << "   meet() ==> " << printBool(touch(*apl, *bpl)) << endl;
    cout << "   overlap() ==> " << printBool(overlap(*apl, *bpl)) << endl;
    cout << endl;

    delete apl;
    delete bpl;

//         3. Test pl_inside, F and G same number of elements
    apl = new Point2D("((2,2),(5,5))");
    bpl = new Line2D("(((1,1),(4,4)),((4,4),(6,6)))");

    cout << "*****************************" << endl;
    cout << "Case 3: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pl_inside, F and G same number of elements." << endl;
    cout << "Point2D a(\"((2,2),(5,5))\");" << endl;
    cout << "Line2D b(\"(((1,1),(4,4)),((4,4),(6,6)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);
    printPredicate(tplred);

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_inside_m8);
    cout << "   isTopologicalRelationship(a, b, pl_inside_m8) ==> " << printBool(result) << endl;

    cout << "   inside() ==> " << printBool(inside(*apl, *bpl)) << endl;
    cout << "   overlap() ==> " << printBool(overlap(*apl, *bpl)) << endl;
    cout << endl;

    delete apl;
    delete bpl;

    // 4. Test pl_overlap, F and G same number of elements
    apl = new Point2D("((1,1),(2,2),(3,3))");
    bpl = new Line2D("(((2,2),(4,4)),((4,4),(5,5)),((5,5),(6,6)))");


    cout << "*****************************" << endl;
    cout << "Case 4: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pl_overlap, F and G same number of elements." << endl;
    cout << "Point2D a(\"((1,1),(2,2),(3,3))\");" << endl;
    cout << "Line2D b(\"(((2,2),(4,4)),((4,4),(5,5)),((5,5),(6,6)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);
    printPredicate(tplred);

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_overlap_m10);
    cout << "   isTopologicalRelationship(a, b, pl_overlap_m10) ==> " << printBool(result) << endl;

    cout << "   overlap() ==> " << printBool(overlap(*apl, *bpl)) << endl;
    cout << "   disjoint() ==> " << printBool(inside(*apl, *bpl)) << endl;
    cout << endl;

    delete apl;
    delete bpl;


    cout << "Test succesfully ended." << endl;


}
