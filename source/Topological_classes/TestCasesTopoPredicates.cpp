#include <iostream>

using namespace std;

#include "TopologicalRelationships.h"
//#include "Point2D.h"
#include "Point2DPoint2D.h"

//    Use this as template... to create your own Test Cases cpp file:
//    1. Copy the content and use it as template, put it as your main.cpp.
//    2. In your main.cpp, commented out the portion of test codes which do not belong to you (so you won't get errors).
//    3. Adjust the code accordingly to test your own spatial object combination you are working on.
//    4. Run your own test in your own main.cpp.
//    5. If successful, you can copy the test cases of your codes back to this CPP file --> look for the correct position in the main ().
//    6. Later when we finished all our codes, we will compile all the codes together, including this TestCasesTopoPredicates.cpp
//    7. If later this TestCasesTopoPredicates.cpp turns out to be too long, we can still decide to break it down to small test files.


// Group 4: Topological Predicates test cases
//
// Test cases for Point2DPoint2D, Point2DLine2D, Point2DRegion2D,
//            Line2DLine2D, Line2DRegion2D, Region2DRegion2D
//

void printPoint2DPoint2DPredicate(TopPredNumberPoint2DPoint2D tpred);



int main() {

    Point2D * a, * b;
    TopPredNumberPoint2DPoint2D tpred;
    bool result = false;

  cout << "Test begins..." << endl << endl;

    // *****************************
    // Case 1: Point2DPoint2D
    // *****************************

    // 1. Test no share Poi, F and G same number of elements
    a = new Point2D("((0,0),(3,3),(6,6))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "*****************************" << endl;
    cout << "Case 1: Point2DPoint2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test no share Poi, F and G same number of elements." << endl;
    cout << "Point2D a(\"((0,0),(3,3),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete a, b;

    // 2. Test share Poi, F and G same number of elements
    a = new Point2D("((0,0),(1,1),(6,6))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_disjoint_m1);

    cout << "2. Test shared Poi, F and G same number of elements." << endl;
    cout << "Point2D a(\"((0,0),(1,1),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;
    cout << "   isTopologicalRelationship(a, b, pp_disjoint_m1) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete a, b;


    // 3. Test share Poi, F and G uneven number of elements
    a = new Point2D("((2,2))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "3. Test share Poi, F and G uneven number of elements." << endl;
    cout << "Point2D a(\"((2,2))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete a, b;


    cout << "----" << endl;

    // ... still many test cases to write here
    // I haven't finished yet with my own test cases...


    // *****************************
    // Case 2: Point2DLine2D
    // *****************************



    // *****************************
    // Case 3: Point2DRegion2D
    // *****************************



    // *****************************
    // Case 4: Line2DLine2D
    // *****************************




    // *****************************
    // Case 5: Line2DRegion2D
    // *****************************




    // *****************************
    // Case 6: Region2DRegion2D
    // *****************************




    cout << "Test succesfully ended." << endl;
    return 0;
}

void printPoint2DPoint2DPredicate(TopPredNumberPoint2DPoint2D tpred) {

    switch(tpred) {
        case TopPredNumberPoint2DPoint2D::pp_disjoint_m1 : cout << "pp_disjoint_m1";
            break;
        case TopPredNumberPoint2DPoint2D::pp_equal_m2 : cout << "pp_equal_m2";
            break;
        case TopPredNumberPoint2DPoint2D::pp_inside_m3 : cout << "pp_inside_m3";
            break;
        case TopPredNumberPoint2DPoint2D::pp_contains_m4 : cout << "pp_contains_m4";
            break;
        case TopPredNumberPoint2DPoint2D::pp_overlap_m5 : cout << "pp_overlap_m5";
            break;
    }
};
