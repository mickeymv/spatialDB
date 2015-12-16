#include <iostream>

using namespace std;

#include "TopologicalRelationships.h"
#include "Point2DPoint2D.h"
#include "Point2DLine2D.h"
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


int main() {

    Point2D * a, * b;
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
    cout << "   disjoint() ==> " <<  disjoint(*a, *b) << endl;
    cout << "   overlap() ==> " <<  overlap(*a, *b) << endl;
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
    cout << "   disjoint() ==> " <<  disjoint(*a, *b) << endl;
    cout << "   overlap() ==> " <<  overlap(*a, *b) << endl;
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
    cout << "   inside() ==> " <<  inside(*a, *b) << endl << endl;


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
    cout << "   disjoint() ==> " <<  disjoint(*a, *b) << endl;
    cout << "   equal() ==> " <<  equal(*a, *b) << endl;
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
    cout << "   contains() ==> " <<  contains(*a, *b) << endl;
    cout << "   overlap() ==> " <<  overlap(*a, *b) << endl;
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
    cout << "   contains() ==> " <<  contains(*a, *b) << endl;
    cout << "   inside() ==> " <<  inside(*a, *b) << endl;
    cout << endl;

    // don't forget to cleanup
    delete a, b;

    cout << "----" << endl;

    // ... still many test cases to write here
    // I haven't finished yet with my own test cases...


    // *****************************
    // Case 2: Point2DLine2D
    // *****************************

    Point2D * apl;
    Line2D * bpl;
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

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D:: pl_disjoint_m2);

    cout << "   isTopologicalRelationship(a, b, pl_disjoint_m2) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   disjoint() ==> " <<  disjoint(*apl, *bpl) << endl;
    cout << "   overlap() ==> " <<  overlap(*apl, *bpl) << endl;
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

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D:: pl_meet_m4);

    cout << "   isTopologicalRelationship(a, b, pl_meet_m4) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   meet() ==> " <<  touch(*apl, *bpl) << endl;
    cout << "   overlap() ==> " <<  overlap(*apl, *bpl) << endl;
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

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D:: pl_inside_m8);

    cout << "   isTopologicalRelationship(a, b, pl_inside_m8) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   inside() ==> " <<  inside(*apl, *bpl) << endl;
    cout << "   overlap() ==> " <<  overlap(*apl, *bpl) << endl;
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

    result = isTopologicalRelationship(*apl, *bpl, TopPredNumberPoint2DLine2D:: pl_overlap_m10);

    cout << "   isTopologicalRelationship(a, b, pl_overlap_m10) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   overlap() ==> " <<  overlap(*apl, *bpl) << endl;
    cout << "   disjoint() ==> " <<  inside(*apl, *bpl) << endl;
    cout << endl;

    // don't forget to cleanup
    delete apl, bpl;
    result = false;



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
        case TopPredNumberPoint2DPoint2D::pp_disjoint_m1 : cout << "pp_disjoint_m1 <===";
            break;
        case TopPredNumberPoint2DPoint2D::pp_equal_m2 : cout << "pp_equal_m2 <===";
            break;
        case TopPredNumberPoint2DPoint2D::pp_inside_m3 : cout << "pp_inside_m3 <===";
            break;
        case TopPredNumberPoint2DPoint2D::pp_contains_m4 : cout << "pp_contains_m4 <===";
            break;
        case TopPredNumberPoint2DPoint2D::pp_overlap_m5 : cout << "pp_overlap_m5 <===";
            break;
    }
};

void printPoint2DLine2DPredicate(TopPredNumberPoint2DLine2D tpred) {

    switch(tpred) {
        case TopPredNumberPoint2DLine2D::pl_disjoint_m1 : cout << "pl_disjoint_m1 <===";
            break;
        case TopPredNumberPoint2DLine2D ::pl_disjoint_m2: cout << "pl_disjoint__m2 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_meet_m3 : cout << "pl_meet_m3 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_meet_m4 : cout<<"pl_meet_m4 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_meet_m5 : cout << "pl_meet_m5 <===";
            break;
        case TopPredNumberPoint2DLine2D ::pl_meet_m6 : cout << "pl_meet_m6 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_inside_m7 : cout << "pl_inside_m7 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_inside_m8 : cout<<"pl_inside_m8 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_overlap_m9 : cout<<"pl_overlap_m9 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_overlap_m10 : cout<<"pl_overlap_m10 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_inside_m11 : cout<<"pl_inside_m11 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_inside_m12 : cout<<"pl_inside_m12 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_overlap_m13 : cout<<"pl_overlap_m13 <===";
            break;
        case TopPredNumberPoint2DLine2D::pl_overlap_m14 : cout<<"pl_overlap_m14 <===";
            break;
    }
};
