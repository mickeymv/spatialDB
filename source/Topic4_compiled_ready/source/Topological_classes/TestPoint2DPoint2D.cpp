//
// Created by Djundi on 12/18/15.
//

#include "TestPoint2DPoint2D.h"

void TestPoint2DPoint2D::start() {
    Point2D *a, *b;
    TopPredNumberPoint2DPoint2D tpred;
    bool result = false;


    cout << "Test begins..." << endl << endl;

    // *****************************
    // Case 1: Point2DPoint2D
    // *****************************

    // 1. Test pp_disjoint_m1, F and G same number of elements
    a = new Point2D("((0,0),(3,3),(6,6))");
    b = new Point2D("((1,1),(2,2),(4,3))");


    cout << "*****************************" << endl;
    cout << "Case 1: Point2DPoint2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pp_disjoint_m1, F and G same number of elements." << endl;
    cout << "Point2D a(\"((0,0),(3,3),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);

      printPoint2DPoint2DPredicate(tpred);

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) ==> " << printResult(result) << endl;

    cout << "   disjoint() ==> " << printResult(disjoint(*a, *b)) << endl;
    cout << "   overlap() ==> " << printResult(overlap(*a, *b)) << endl;
    cout << endl;

    // don't forget to cleanup
    delete a;
    delete b;


    // 2. Test pp_overlap_m5, F and G same number of elements
    a = new Point2D("((0,0),(1,1),(6,6))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    cout << "2. Test pp_overlap_m5" << endl;
    cout << "Point2D a(\"((0,0),(1,1),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);
    printPoint2DPoint2DPredicate(tpred);

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_disjoint_m1);

    cout << "   isTopologicalRelationship(a, b, pp_disjoint_m1) ==> " << printResult(result) << endl;

    cout << "   disjoint() ==> " << printResult(disjoint(*a, *b)) << endl;
    cout << "   overlap() ==> " << printResult(overlap(*a, *b)) << endl;
    cout << endl;

    delete a;
    delete b;


    // 3. Test pp_inside_m3, F and G uneven number of elements
    a = new Point2D("((2,2))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    cout << "3. Test pp_inside_m3" << endl;
    cout << "Point2D a(\"((2,2))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);
    printPoint2DPoint2DPredicate(tpred);

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) ==> " << printResult(result) << endl;

    cout << "   inside() ==> " << printResult(inside(*a, *b)) << endl << endl;

    delete a;
    delete b;

    // 4. Test pp_equal_m2
    a = new Point2D("((1,1),(2,2))");
    b = new Point2D("((1,1),(2,2))");

    cout << "4. Test pp_equal_m2" << endl;
    cout << "Point2D a(\"((1,1),(2,2))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);
    printPoint2DPoint2DPredicate(tpred);

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) ==> " << printResult(result) << endl;

    cout << "   disjoint() ==> " << printResult(disjoint(*a, *b)) << endl;
    cout << "   equal() ==> " << printResult(equal(*a, *b)) << endl;
    cout << endl;


    delete a;
    delete b;

    // 5. Test pp_inside_m3
    a = new Point2D("((1,1))");
    b = new Point2D("((1,1),(2,2))");

    cout << "5. Test pp_inside_m3" << endl;
    cout << "Point2D a(\"((1,1))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);
    printPoint2DPoint2DPredicate(tpred);

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) ==> " << printResult(result) << endl;

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_disjoint_m1);
    cout << "   isTopologicalRelationship(a, b, pp_disjoint_m1) ==> " << printResult(result) << endl;

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_contains_m4);
    cout << "   isTopologicalRelationship(a, b, pp_contains_m4) ==> " << printResult(result) << endl;

    cout << "   contains() ==> " << printResult(contains(*a, *b)) << endl;
    cout << "   overlap() ==> " << printResult(overlap(*a, *b)) << endl;
    cout << endl;

    delete a;
    delete b;


    // 6. Test pp_disjoint_m1, F and G uneven number of elements
    a = new Point2D("((0,0),(3,3),(6,6))");
    b = new Point2D("((1,1))");

    cout << "6. Test pp_disjoint_m1, F and G uneven number of elements." << endl;
    cout << "Point2D a(\"((0,0),(3,3),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);
    printPoint2DPoint2DPredicate(tpred);


    delete a;
    delete b;

    // 7. Test pp_contains_m4
    a = new Point2D("((2,2),(3,3))");
    b = new Point2D("((2,2))");

    cout << "7. Test pp_contains_m4" << endl;
    cout << "Point2D a(\"((2,2),(3,3))\");" << endl;
    cout << "Point2D b(\"((2,2))\");" << endl;

    tpred = getTopologicalRelationship(*a, *b);
    printPoint2DPoint2DPredicate(tpred);

    cout << "   contains() ==> " << printResult(contains(*a, *b)) << endl;
    cout << "   inside() ==> " << printResult(inside(*a, *b)) << endl;
    cout << endl;


    delete a;
    delete b;

    cout << "Test succesfully ended." << endl;


}
