//
// Created by Djundi on 12/18/15.
//

#include "TestRegion2DRegion2D.h"

void TestRegion2DRegion2D::start() {


    // *****************************
    // Case 6: Region2DRegion2D
    // *****************************

    Region2D *arr, *brr;
    TopPredNumberRegion2DRegion2D trrred;
    bool    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");
    brr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 1: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_equal, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_equal_m5);

    cout << "   isTopologicalRelationship(a, b, rr_equal_m5) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   equal() ==> " << equal(*arr, *brr) << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete arr;
    delete brr;
    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");
    brr = new Region2D("(((10,8),(11,10)),((10,8),(11,7)),((11,7),(11,10)))");

    cout << "*****************************" << endl;
    cout << "Case 2: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_disjoint, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;
    cout << "Region2D b(\"(((10,8),(11,10)),((10,8),(11,7)),((11,7),(11,10)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_disjoint_m1);

    cout << "   isTopologicalRelationship(a, b, rr_disjoint_m1) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " << disjoint(*arr, *brr) << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;
    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((3,1),(4,3)),((3,1),(4,0)),((4,0),(4,3)))");
    brr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 3: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_meet, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((3,1),(4,3)),((3,1),(4,0)),((4,0),(4,3)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_meet_m4);

    cout << "   isTopologicalRelationship(a, b, rr_meet_m4) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   meet() ==> " << touch(*arr, *brr) << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;
    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((5,3),(6,4)),((5,3),(6,2)),((6,2),(6,4)))");
    brr = new Region2D("(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))");

    cout << "*****************************" << endl;
    cout << "Case 4: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_inside, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((5,3),(6,4)),((5,3),(6,2)),((6,2),(6,4)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_inside_m7);

    cout << "   isTopologicalRelationship(a, b, rr_inside_m7) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   inside() ==> " << inside(*arr, *brr) << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;
    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))");
    brr = new Region2D("(((5,3),(6,4)),((5,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 5: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_contains, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))\");" << endl;
    cout << "Region2D b(\"(((5,3),(6,4)),((5,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_contains_m19);

    cout << "   isTopologicalRelationship(a, b, rr_contains_m19) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   contains() ==> " << contains(*arr, *brr) << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;
    result = false;


    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((2,2),(5,5)),((2,2),(5,0)),((5,0),(5,5)))");
    brr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 6: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_overlap, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((2,2),(5,5)),((2,2),(5,0)),((5,0),(5,5)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_overlap_m14);

    cout << "   isTopologicalRelationship(a, b, rr_overlap_m14) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
    cout << "   contains() ==> " << contains(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;
    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");
    brr = new Region2D("(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))");

    cout << "*****************************" << endl;
    cout << "Case 8: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_coveredby, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_coveredby_m6);

    cout << "   isTopologicalRelationship(a, b, rr_coveredby_m6) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   covers() ==> " << coveredBy(*arr, *brr) << endl;
    cout << "   contains() ==> " << contains(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;
    result = false;

    cout << "Test begins..." << endl << endl;

    arr = new Region2D("(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))");
    brr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 7: Region2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test rr_covers, F and G same number of elements." << endl;
    cout << "Region2D a(\"(((4,3),(7,5)),((4,3),(7,1)),((7,1),(7,5)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trrred = getTopologicalRelationship(*arr, *brr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printRegion2DRegion2DPredicate(trrred);
    cout << endl;

    result = isTopologicalRelationship(*arr, *brr, TopPredNumberRegion2DRegion2D::rr_covers_m11);

    cout << "   isTopologicalRelationship(a, b, rr_covers_m11) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   covers() ==> " << covers(*arr, *brr) << endl;
    cout << "   contains() ==> " << contains(*arr, *brr) << endl;
    cout << endl;

    delete arr;
    delete brr;

    cout << "Test succesfully ended." << endl;

}
