#include <iostream>

using namespace std;

#include "TopologicalRelationships.h"
//#include "Point2DPoint2D.h"
//#include "Point2DLine2D.h"
//#include "Line2DLine2D.h"
//#include "Point2DRegion2D.h"
#include "vector"
//#include "planesweep project/Topic2/Implementation/Point2D.h"


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
void printPoint2DLine2DPredicate(TopPredNumberPoint2DLine2D tpred);
void printLine2DLine2DPredicate(TopPredNumberLine2DLine2D tpred);
void printPoint2DRegion2DPredicate(TopPredNumberPoint2DRegion2D tpred);
void printRegion2DRegion2DPredicate(TopPredNumberRegion2DRegion2D tpred);

void printLine2DRegion2DPredicate(TopPredNumberLine2DRegion2D tpred);


int main() {

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

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "*****************************" << endl;
    cout << "Case 1: Point2DPoint2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pp_disjoint_m1, F and G same number of elements." << endl;
    cout << "Point2D a(\"((0,0),(3,3),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " << disjoint(*a, *b) << endl;
    cout << "   overlap() ==> " << overlap(*a, *b) << endl;
    cout << endl;

    // don't forget to cleanup
    delete a, b;


    // 2. Test pp_overlap_m5, F and G same number of elements
    a = new Point2D("((0,0),(1,1),(6,6))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_disjoint_m1);

    cout << "2. Test pp_overlap_m5" << endl;
    cout << "Point2D a(\"((0,0),(1,1),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;
    cout << "   disjoint() ==> " << disjoint(*a, *b) << endl;
    cout << "   overlap() ==> " << overlap(*a, *b) << endl;
    cout << endl;
    cout << "   isTopologicalRelationship(a, b, pp_disjoint_m1) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete a, b;


    // 3. Test pp_inside_m3, F and G uneven number of elements
    a = new Point2D("((2,2))");
    b = new Point2D("((1,1),(2,2),(4,3))");

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "3. Test pp_inside_m3" << endl;
    cout << "Point2D a(\"((2,2))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2),(4,3))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   inside() ==> " << inside(*a, *b) << endl << endl;


    // don't forget to cleanup
    delete a, b;

    // 4. Test pp_equal_m2
    a = new Point2D("((1,1),(2,2))");
    b = new Point2D("((1,1),(2,2))");

    tpred = getTopologicalRelationship(*a, *b);
    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "4. Test pp_equal_m2" << endl;
    cout << "Point2D a(\"((1,1),(2,2))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;
    cout << "   disjoint() ==> " << disjoint(*a, *b) << endl;
    cout << "   equal() ==> " << equal(*a, *b) << endl;
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete a, b;

    // 5. Test pp_inside_m3
    a = new Point2D("((1,1))");
    b = new Point2D("((1,1),(2,2))");

    tpred = getTopologicalRelationship(*a, *b);

    cout << "5. Test pp_inside_m3" << endl;
    cout << "Point2D a(\"((1,1))\");" << endl;
    cout << "Point2D b(\"((1,1),(2,2))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);
    cout << "   isTopologicalRelationship(a, b, pp_equal_m2) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_disjoint_m1);
    cout << "   isTopologicalRelationship(a, b, pp_disjoint_m1) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_contains_m4);
    cout << "   isTopologicalRelationship(a, b, pp_contains_m4) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   contains() ==> " << contains(*a, *b) << endl;
    cout << "   overlap() ==> " << overlap(*a, *b) << endl;
    cout << endl;

    // don't forget to cleanup
    delete a, b;


    // 6. Test pp_disjoint_m1, F and G uneven number of elements
    a = new Point2D("((0,0),(3,3),(6,6))");
    b = new Point2D("((1,1))");

//    for ( Point2D::ConstPoiIterator it = a->cbegin(); it < a->ctail(); it++ )
//        cout << " output a:  " << it << endl;
//    for ( Point2D::ConstPoiIterator it = b->cbegin(); it < b->ctail(); it++ )
//        cout << " output b:  " << it << endl;


    tpred = getTopologicalRelationship(*a, *b);

    cout << "6. Test pp_disjoint_m1, F and G uneven number of elements." << endl;
    cout << "Point2D a(\"((0,0),(3,3),(6,6))\");" << endl;
    cout << "Point2D b(\"((1,1))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl << endl;


    // don't forget to cleanup
    delete a, b;

    // 7. Test pp_contains_m4
    a = new Point2D("((2,2),(3,3))");
    b = new Point2D("((2,2))");

    tpred = getTopologicalRelationship(*a, *b);

    cout << "7. Test pp_contains_m4" << endl;
    cout << "Point2D a(\"((2,2),(3,3))\");" << endl;
    cout << "Point2D b(\"((2,2))\");" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DPoint2DPredicate(tpred);
    cout << endl;
    cout << "   contains() ==> " << contains(*a, *b) << endl;
    cout << "   inside() ==> " << inside(*a, *b) << endl;
    cout << endl;

    // don't forget to cleanup
    delete a, b;

    cout << "----" << endl;

    // ... still many test cases to write here
    // I haven't finished yet with my own test cases...


    // *****************************
    // Case 2: Point2DLine2D
    // *****************************

    Point2D *apl;
    Line2D *bpl;
    TopPredNumberPoint2DLine2D tplred;
    result = false;

    cout << "Test begins..." << endl << endl;


    // 1. Test pl_disjoint, F and G same number of elements
    apl = new Point2D("((0,1),(2,2),(3,3))");
    bpl = new Line2D("(((4,4),(5,5)),((5,5),(6,6)),((6,6),(7,7)))");

//    Number zero("0"), one("1"), two("2"), three("3"), four("4"), five("5"), six("6"), seven("7");
//
//    vector<Poi2D> aplValues;
//    aplValues.push_back(Poi2D(zero,one));
//    aplValues.push_back(Poi2D(two,two));
//    aplValues.push_back(Poi2D(three,three));
//    vector<Seg2D> bplValues;
//    bplValues.push_back(Seg2D(Poi2D(four,four), Poi2D(five,five)));
//    bplValues.push_back(Seg2D(Poi2D(five,five), Poi2D(six,six)));
//    bplValues.push_back(Seg2D(Poi2D(six,six),Poi2D(seven,seven)));
//
//    apl = new Point2D(aplValues);
//    bpl = new Line2D(bplValues);


    //result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "*****************************" << endl;
    cout << "Case 1: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pl_disjoint, F and G same number of elements." << endl;
    cout << "Point2D a(\"((0,1),(2,2),(3,3))\");" << endl;
    cout << "Line2D b(\"(((4,4),(5,5)),((5,5),(6,6)),((6,6),(7,7)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DLine2DPredicate(tplred);
    cout << endl;

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_disjoint_m2);

    cout << "   isTopologicalRelationship(a, b, pl_disjoint_m2) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " << disjoint(*apl, *bpl) << endl;
    cout << "   overlap() ==> " << overlap(*apl, *bpl) << endl;
    cout << endl;

    // don't forget to cleanup
    delete apl, bpl;
    result = false;

    cout << "Test begins..." << endl << endl;


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

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DLine2DPredicate(tplred);
    cout << endl;

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_meet_m4);

    cout << "   isTopologicalRelationship(a, b, pl_meet_m4) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   meet() ==> " << touch(*apl, *bpl) << endl;
    cout << "   overlap() ==> " << overlap(*apl, *bpl) << endl;
    cout << endl;

    // don't forget to cleanup
    delete apl, bpl;
    result = false;

//         3. Test pl_inside, F and G same number of elements
    apl = new Point2D("((2,2),(5,5))");
    bpl = new Line2D("(((1,1),(4,4)),((4,4),(6,6)))");


    //result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "*****************************" << endl;
    cout << "Case 3: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pl_inside, F and G same number of elements." << endl;
    cout << "Point2D a(\"((2,2),(5,5))\");" << endl;
    cout << "Line2D b(\"(((1,1),(4,4)),((4,4),(6,6)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DLine2DPredicate(tplred);
    cout << endl;

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_inside_m8);

    cout << "   isTopologicalRelationship(a, b, pl_inside_m8) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   inside() ==> " << inside(*apl, *bpl) << endl;
    cout << "   overlap() ==> " << overlap(*apl, *bpl) << endl;
    cout << endl;

    // don't forget to cleanup
    delete apl, bpl;
    result = false;

    // 4. Test pl_overlap, F and G same number of elements
    apl = new Point2D("((1,1),(2,2),(3,3))");
    bpl = new Line2D("(((2,2),(4,4)),((4,4),(5,5)),((5,5),(6,6)))");


    //result = isTopologicalRelationship(*a, *b, TopPredNumberPoint2DPoint2D::pp_equal_m2);

    cout << "*****************************" << endl;
    cout << "Case 4: Point2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pl_overlap, F and G same number of elements." << endl;
    cout << "Point2D a(\"((1,1),(2,2),(3,3))\");" << endl;
    cout << "Line2D b(\"(((2,2),(4,4)),((4,4),(5,5)),((5,5),(6,6)))\");" << endl;

    tplred = getTopologicalRelationship(*apl, *bpl);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DLine2DPredicate(tplred);
    cout << endl;

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D::pl_overlap_m10);

    cout << "   isTopologicalRelationship(a, b, pl_overlap_m10) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   overlap() ==> " << overlap(*apl, *bpl) << endl;
    cout << "   disjoint() ==> " << inside(*apl, *bpl) << endl;
    cout << endl;

    // don't forget to cleanup
    delete apl, bpl;
    result = false;


//
//
    // *****************************
    // Case 3: Point2DRegion2D
    // *****************************


    Point2D *p1;
    Region2D *r1;
    TopPredNumberPoint2DRegion2D tpredpr;
    bool resultpr = false;

    cout << "Test begins..." << endl << endl;


    // 1. Test pr_disjoint_m1, F and G same number of elements
    p1 = new Point2D("((0,0),(3,3),(2,2))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    tpredpr = getTopologicalRelationship(*p1, *r1);
    resultpr = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_disjoint_m1);

    cout << "*****************************" << endl;
    cout << "Point2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test pr_disjoint_m1" << endl;
    cout << "Point2D(\"((0,0),(3,3),(2,2))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;

    cout << "   getTopologicalRelationship(p1, r1) :" << endl;
    cout << "   returns ==> ";

    printPoint2DRegion2DPredicate(tpredpr);
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, pr_disjoint_m1) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " << disjoint(*p1, *r1) << endl;

    cout << endl;

    // don't forget to cleanup
    delete p1, r1;


    // 2. Test pr_overlap_m7
    p1 = new Point2D("((0,0),(1,1),(2,5))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    tpredpr = getTopologicalRelationship(*p1, *r1);
    resultpr = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_overlap_m7);

    cout << "2. pr_overlap_m7" << endl;
    cout << "Point2D(\"((0,0),(3,3),(2,5))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;
    cout << "   getTopologicalRelationship(p1, r1) :" << endl;
    cout << "   returns ==> ";

    printPoint2DRegion2DPredicate(tpredpr);
    cout << endl;

    cout << "   overlap() ==> " << overlap(*p1, *r1) << endl;
    cout << endl;
    cout << "   isTopologicalRelationship(p1, r1, pr_overlap_m7) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete p1, r1;


    // 3. pr_meet_m2
    p1 = new Point2D("((4,3))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    tpredpr = getTopologicalRelationship(*p1, *r1);
    resultpr = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_meet_m2);

    cout << "3. Test pr_meet_m2" << endl;
    cout << "Point2D(\"((4,3))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printPoint2DRegion2DPredicate(tpredpr);
    cout << endl;
    cout << "   isTopologicalRelationship(a, b, pr_meet_m2) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   meet() ==> " << touch(*p1, *r1) << endl << endl;


    // don't forget to cleanup
    delete p1, r1;

    // 4. Test pr_inside_m4
    p1 = new Point2D("((2,5))");
    r1 = new Region2D("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");

    tpredpr = getTopologicalRelationship(*p1, *r1);
    result = isTopologicalRelationship(*p1, *r1, TopPredNumberPoint2DRegion2D::pr_inside_m4);

    cout << "4. Test pr_inside_m4" << endl;
    cout << "Point2D(\"((0,0),(3,3),(6,6))\")" << endl;
    cout << "Region2D(\"(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))\")" << endl;

    cout << "   getTopologicalRelationship(p1, r1) :" << endl;
    cout << "   returns ==> ";

    printPoint2DRegion2DPredicate(tpredpr);
    cout << endl;
    cout << "   inside() ==> " << inside(*p1, *r1) << endl;
    cout << endl;

    cout << "   isTopologicalRelationship(p1, r1,pr_inside_m4) :" << endl;
    cout << "   returns ==> " << result << endl << endl;

    // don't forget to cleanup
    delete p1, r1;



    // *****************************
    // Case 4: Line2DLine2D
    // *****************************

    //   1. Test ll_disjoint_m4

    Line2D *all, *bll;

    TopPredNumberLine2DLine2D tpredll;

    all = new Line2D("(((1,1),(2,2)),((2,1),(2,3)))");
    bll = new Line2D("(((4,0),(4,2)),((5,6),(7,8)))");

    tpredll = getTopologicalRelationship(*all, *bll);
    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_disjoint_m4);

    cout << "*****************************" << endl;
    cout << "Case 4: Line2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test ll_disjoint_m4" << endl;
    cout << "Line2D(\"(((1,1),(2,2)),((2,1),(2,3)))\")" << endl;
    cout << "Line2D(\"((((4,0),(4,2)),((5,6),(7,8)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, ll_disjoint_m4) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " << disjoint(*all, *bll) << endl;

    cout << endl;


    delete all;
    delete bll;


    // 2. Test ll_inside_m39
    all = new Line2D("(((1,2),(3,4)),((3,1),(4,4)))");
    bll = new Line2D("(((2,2),(2,3)),((3,2),(3,3)))");

    tpredll = getTopologicalRelationship(*all, *bll);
    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_inside_m39);

    cout << "2. Test ll_inside_m39" << endl;
    cout << "Line2D(\"((1,2),(3,4)),((3,1),(4,4)))\")" << endl;
    cout << "Line2D(\"((((2,2),(2,3)),((3,2),(3,3)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;
    cout << "   inside() ==> " << inside(*all, *bll) << endl;

    cout << endl;
    cout << "   isTopologicalRelationship(a, b, ll_inside_m39) :" << endl;
    cout << "   returns ==> " << result << endl << endl;


    delete all;
    delete bll;



    // 3. Test ll_overlap_m44
    all = new Line2D("(((1,1),(3,4)),((5,6),(7,8)))");
    bll = new Line2D("(((1,3),(3,1)),((5,5),(7,7)))");

    tpredll = getTopologicalRelationship(*all, *bll);
    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_overlap_m44);

    cout << "3. Test ll_overlap_m44" << endl;
    cout << "Line2D(\"(((1,1),(3,4)),((5,6),(7,8)))\")" << endl;
    cout << "Line2D(\"(((1,3),(3,1)),((5,5),(7,7)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;
    cout << "   isTopologicalRelationship(a, b, ll_overlap_m44) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   overlap() ==> " << overlap(*all, *bll) << endl << endl;


    delete all;
    delete bll;

    // 4. Test ll_covers_m49
    all = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");
    bll = new Line2D("(((1,1),(1,2)),((1,1),(1,3)))");

    tpredll = getTopologicalRelationship(*all, *bll);
    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_covers_m49);

    cout << "4. Test ll_covers_m49" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;
    cout << "Line2D(\"(((1,1),(1,2)),((1,1),(1,3)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;
    cout << "   covers() ==> " << covers(*all, *bll) << endl;
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, ll_covers_m49) :" << endl;
    cout << "   returns ==> " << result << endl << endl;


    delete all;
    delete bll;

    // 5. Test ll_coveredby_m37
    all = new Line2D("(((1,1),(1,2)),((1,1),(1,3)))");
    bll = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");

    tpredll = getTopologicalRelationship(*all, *bll);
    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_coveredby_m37);

    cout << "4. Test ll_coveredby_m37" << endl;
    cout << "Line2D(\"(((1,1),(1,2)),((1,1),(1,3)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;
    cout << "   coveredby() ==> " << coveredBy(*all, *bll) << endl;
    cout << endl;

    cout << "   isTopologicalRelationship(a, b, ll_coveredby_m37) :" << endl;
    cout << "   returns ==> " << result << endl << endl;


    delete all;
    delete bll;

    // 6. Test ll_equal_m33
    all = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");
    bll = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");


    tpredll = getTopologicalRelationship(*all, *bll);

    cout << "6. Test ll_equal_m33." << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl << endl;


    delete all;
    delete bll;

    // 7. Test ll_contains_m46
    all = new Line2D("(((2,2),(2,3)),((3,2),(3,3)))");
    bll = new Line2D("(((1,2),(3,4)),((3,1),(4,4)))");


    tpredll = getTopologicalRelationship(*all, *bll);

    cout << "7. Test ll_contains_m46" << endl;
    cout << "Line2D(\"(((2,2),(2,3)),((3,2),(3,3)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((3,1),(4,4)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;
    cout << "   contains() ==> " << contains(*all, *bll) << endl;
    cout << endl;


    delete all;
    delete bll;

    // 8. Test ll_meet_m13
    all = new Line2D("(((1,2),(3,4)),((1,1),(2,2)))");
    bll = new Line2D("(((1,2),(4,4)),((5,6),(7,8)))");

    tpredll = getTopologicalRelationship(*all, *bll);

    cout << "7. Test ll_meet_m13" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((1,1),(2,2)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DLine2DPredicate(tpredll);
    cout << endl;
    cout << "   touch() ==> " << touch(*all, *bll) << endl;
    cout << endl;


    delete all;
    delete bll;


//

//     *****************************
//     Case 5: Line2DRegion2D
//     *****************************

    Line2D *alr;
    Region2D *blr;
    TopPredNumberLine2DRegion2D trlred;
    result = false;

    cout << "Test begins..." << endl << endl;

    alr = new Line2D("(((1,2),(3,4)),((1,1),(2,2)))");
    blr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 1: Line2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test lr_disjoint, F and G same number of elements." << endl;
    cout << "Line2D a(\"(((1,2),(3,4)),((1,1),(2,2)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trlred = getTopologicalRelationship(*alr, *blr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DRegion2DPredicate(trlred);
    cout << endl;

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_disjoint_m1);

    cout << "   isTopologicalRelationship(a, b, lr_disjoint_m1) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " << disjoint(*alr, *blr) << endl;
    cout << "   overlap() ==> " << overlap(*alr, *blr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr, blr;
    result = false;
//
    cout << "Test begins..." << endl << endl;

    alr = new Line2D("(((1,2),(4,3)),((1,1),(2,2)))");
    blr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 2: Line2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test lr_meet, F and G same number of elements." << endl;
    cout << "Line2D a(\"(((1,2),(4,3)),((1,1),(2,2)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trlred = getTopologicalRelationship(*alr, *blr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DRegion2DPredicate(trlred);
    cout << endl;

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_meet_m3);

    cout << "   isTopologicalRelationship(a, b, lr_meet_m3) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   touch() ==> " << touch(*alr, *blr) << endl;
    cout << "   overlap() ==> " << overlap(*alr, *blr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr, blr;
    result = false;
//
    cout << "Test begins..." << endl << endl;

    alr = new Line2D("(((1,2),(5,3)),((1,1),(2,2)))");
    blr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 3: Line2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test lr_overlap, F and G same number of elements." << endl;
    cout << "Line2D a(\"(((1,2),(5,3)),((1,1),(2,2)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trlred = getTopologicalRelationship(*alr, *blr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DRegion2DPredicate(trlred);
    cout << endl;

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_overlap_m20);

    cout << "   isTopologicalRelationship(a, b, lr_overlap_m20) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   overlap() ==> " << overlap(*alr, *blr) << endl;
    cout << "   touch() ==> " << touch(*alr, *blr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr, blr;
    result = false;
//
    cout << "Test begins..." << endl << endl;

    alr = new Line2D("(((4,3),(4,4)),((4,4),(5,4)))");
    blr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 4: Line2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test lr_coveredby, F and G same number of elements." << endl;
    cout << "Line2D a(\"(((4,3),(4,4)),((4,4),(5,4)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trlred = getTopologicalRelationship(*alr, *blr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DRegion2DPredicate(trlred);
    cout << endl;

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_coveredby_m17);

    cout << "   isTopologicalRelationship(a, b, lr_coveredby_m17) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   coveredby() ==> " << coveredBy(*alr, *blr) << endl;
    cout << "   touch() ==> " << touch(*alr, *blr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr, blr;
    result = false;

    cout << "Test begins..." << endl << endl;

    alr = new Line2D("(((1,2),(5,3)),((1,1),(2,2)))");
    blr = new Region2D("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");

    cout << "*****************************" << endl;
    cout << "Case 5: Line2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test lr_overlap, F and G same number of elements." << endl;
    cout << "Line2D a(\"(((1,2),(5,3)),((1,1),(2,2)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))\");" << endl;

    trlred = getTopologicalRelationship(*alr, *blr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DRegion2DPredicate(trlred);
    cout << endl;

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_overlap_m20);

    cout << "   isTopologicalRelationship(a, b, lr_overlap_m20) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   overlap() ==> " << overlap(*alr, *blr) << endl;
    cout << "   touch() ==> " << touch(*alr, *blr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr, blr;
    result = false;

    cout << "Test begins..." << endl << endl;

    alr = new Line2D("(((5,3),(6,3)),((6,3),(6,4)))");
    blr = new Region2D("(((4,3),(7,5)),((4,3),(7,1)),((7,5),(7,1)))");

    cout << "*****************************" << endl;
    cout << "Case 6: Line2DRegion2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test lr_inside, F and G same number of elements." << endl;
    cout << "Line2D a(\"(((5,3),(6,3)),((6,3),(6,4)))\");" << endl;
    cout << "Region2D b(\"(((4,3),(7,5)),((4,3),(7,1)),((7,5),(7,1)))\");" << endl;

    trlred = getTopologicalRelationship(*alr, *blr);

    cout << "   getTopologicalRelationship(a, b) :" << endl;
    cout << "   returns ==> ";

    printLine2DRegion2DPredicate(trlred);
    cout << endl;

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_inside_m14);

    cout << "   isTopologicalRelationship(a, b, lr_inside_m14) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   coveredby() ==> " << inside(*alr, *blr) << endl;
    cout << "   touch() ==> " << touch(*alr, *blr) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr, blr;
    result = false;


    // *****************************
    // Case 6: Region2DRegion2D
    // *****************************

    Region2D *arr, *brr;
    TopPredNumberRegion2DRegion2D trrred;
    result = false;

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
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
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

    // don't forget to cleanup
    delete arr, brr;
    result = false;

    cout << "Test succesfully ended." << endl;
    return 0;
}


string topPredNumberPoint2DPoint2D[5] =
{
    "pp_disjoint_m1", "pp_equal_m2", "pp_inside_m3", "pp_contains_m4", "pp_overlap_m5"
};


string topPredNumberPoint2DLine2D[14] =
{
        "pl_disjoint_m1", "pl_disjoint_m2", "pl_meet_m3", "pl_meet_m4", "pl_meet_m5",
        "pl_meet_m6", "pl_inside_m7", "pl_inside_m8", "pl_overlap_m9", "pl_overlap_m10",
        "pl_inside_m11", "pl_inside_m12", "pl_overlap_m13", "pl_overlap_m14"
};

string topPredNumberPoint2DRegion2D[7] =
        {
                "pr_disjoint_m1", "pr_meet_m2", "pr_meet_m3", "pr_inside_m4", "pr_overlap_m5",
                "pr_inside_m6", "pr_overlap_m7"
        };


string topPredNumberLine2DLine2D[82] =
{
        "ll_disjoint_m1", "ll_disjoint_m2", "ll_disjoint_m3", "ll_disjoint_m4",
        "ll_meet_m5", "ll_meet_m6", "ll_meet_m7", "ll_meet_m8", "ll_meet_m9",
        "ll_meet_m10", "ll_meet_m11", "ll_meet_m12", "ll_meet_m13", "ll_meet_m14",
        "ll_meet_m15", "ll_meet_m16", "ll_meet_m17", "ll_meet_m18", "ll_meet_m19",
        "ll_meet_m20", "ll_meet_m21", "ll_meet_m22", "ll_meet_m23", "ll_meet_m24",
        "ll_meet_m25", "ll_meet_m26", "ll_meet_m27", "ll_meet_m28", "ll_meet_m29",
        "ll_meet_m30","ll_meet_m31", "ll_meet_m32", "ll_equal_m33", "ll_inside_m34",
        "ll_inside_m35", "ll_equal_m36","ll_coveredby_m37", "ll_coveredby_m38",
        "ll_inside_m39", "ll_inside_m40", "ll_coveredby_m41", "ll_coveredby_m42",
        "ll_contains_m43", "ll_overlap_m44", "ll_overlap_m45", "ll_contains_m46",
        "ll_overlap_m47", "ll_overlap_m48", "ll_covers_m49", "ll_overlap_m50",
        "ll_overlap_m51", "ll_covers_m52", "ll_overlap_m53", "ll_overlap_m54",
        "ll_overlap_m55", "ll_overlap_m56", "ll_overlap_m57", "ll_overlap_m58",
        "ll_overlap_m59", "ll_overlap_m60", "ll_overlap_m61", "ll_overlap_m62",
        "ll_contains_m63", "ll_overlap_m64", "ll_overlap_m65", "ll_contains_m66",
        "ll_overlap_m67", "ll_overlap_m68", "ll_covers_m69", "ll_overlap_m70",
        "ll_overlap_m71", "ll_covers_m72", "ll_overlap_m73", "ll_overlap_m74",
        "ll_overlap_m75", "ll_overlap_m76", "ll_overlap_m77", "ll_overlap_m78",
        "ll_overlap_m79", "ll_overlap_m80", "ll_overlap_m81", "ll_overlap_m82"

};

string topPredNumberLine2DRegion2D[43] =
        {
                "lr_disjoint_m1", "lr_disjoint_m2", "lr_meet_m3", "lr_meet_m4", "lr_meet_m5",
                "lr_meet_m6", "lr_meet_m7", "lr_meet_m8", "lr_meet_m9", "lr_meet_m10", "lr_meet_m11",
                "lr_meet_m12", "lr_meet_m13", "lr_inside_m14", "lr_coveredby_m15", "lr_inside_m16",
                "lr_coveredby_m17", "lr_overlap_m18", "lr_overlap_m19", "lr_overlap_m20",
                "lr_overlap_m21", "lr_overlap_m22", "lr_overlap_m23", "lr_overlap_m24",
                "lr_overlap_m25", "lr_inside_m26", "lr_inside_m27", "lr_coveredby_m28",
                "lr_inside_m29", "lr_inside_m30", "lr_coveredby_m31", "lr_overlap_m32",
                "lr_overlap_m33", "lr_overlap_m34", "lr_overlap_m35", "lr_overlap_m36",
                "lr_overlap_m37", "lr_overlap_m38", "lr_overlap_m39", "lr_overlap_m40",
                "lr_overlap_m41", "lr_overlap_m42", "lr_overlap_m43"
        };


string topPredNumberRegion2DRegion2D[33] =
        {
                "rr_disjoint_m1", "rr_meet_m2", "rr_meet_m3", "rr_meet_m4", "rr_equal_m5",
                "rr_coveredby_m6", "rr_inside_m7", "rr_coveredby_m8", "rr_coveredby_m9",
                "rr_overlap_m10", "rr_covers_m11", "rr_overlap_m12", "rr_overlap_m13",
                "rr_overlap_m14", "rr_overlap_m15", "rr_overlap_m16", "rr_overlap_m17",
                "rr_overlap_m18", "rr_contains_m19", "rr_overlap_m20", "rr_covers_m21",
                "rr_overlap_m22", "rr_overlap_m23", "rr_covers_m24", "rr_overlap_m25",
                "rr_overlap_m26", "rr_overlap_m27", "rr_overlap_m28", "rr_overlap_m29",
                "rr_overlap_m30", "rr_overlap_m31", "rr_overlap_m32", "rr_overlap_m33"
        };

inline void printPoint2DPoint2DPredicate(TopPredNumberPoint2DPoint2D tpred) {

    cout << topPredNumberPoint2DPoint2D[(unsigned int) tpred] << " <===";
};


inline void printPoint2DLine2DPredicate(TopPredNumberPoint2DLine2D tpred) {

    cout << topPredNumberPoint2DLine2D[(unsigned int) tpred] << " <===";
};


inline void printLine2DLine2DPredicate(TopPredNumberLine2DLine2D tpred) {

    cout << topPredNumberLine2DLine2D[(unsigned int) tpred] << " <===";

};

inline void printRegion2DRegion2DPredicate(TopPredNumberRegion2DRegion2D tpred) {
    cout << topPredNumberRegion2DRegion2D[(unsigned int) tpred] << " <===";
};

inline void printPoint2DRegion2DPredicate(TopPredNumberPoint2DRegion2D tpred) {
    cout << topPredNumberPoint2DRegion2D[(unsigned int) tpred] << " <===";
};

inline void printLine2DRegion2DPredicate(TopPredNumberLine2DRegion2D tpred) {
    cout << topPredNumberLine2DRegion2D[(unsigned int) tpred] << " <===";
};

