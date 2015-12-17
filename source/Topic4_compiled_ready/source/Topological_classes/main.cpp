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
void printLine2DLine2DPredicate(TopPredNumberLine2DLine2D tpred);
void printRegion2DRegion2DPredicate(TopPredNumberRegion2DRegion2D tpred);


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

    cout << "   isTopologicalRelationship(a, b, pl_disjoint_m2) :" << endl;
    cout << "   returns ==> " << result << endl;
    cout << "   equal() ==> " << equal(*arr, *brr) << endl;
    cout << "   overlap() ==> " << overlap(*arr, *brr) << endl;
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


string topPredLine2DLine2D[82] =
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

inline void printPoint2DPoint2DPredicate(TopPredNumberPoint2DPoint2D tpred) {

    cout << topPredNumberPoint2DPoint2D[(unsigned int) tpred] << " <===";
};


inline void printPoint2DLine2DPredicate(TopPredNumberPoint2DLine2D tpred) {

    cout << topPredNumberPoint2DLine2D[(unsigned int) tpred] << " <===";
};


inline void printLine2DLine2DPredicate(TopPredNumberLine2DLine2D tpred) {

    cout << topPredLine2DLine2D[(unsigned int) tpred] << " <===";

};


void printRegion2DRegion2DPredicate(TopPredNumberRegion2DRegion2D tpred) {
    switch (tpred) {
        case TopPredNumberRegion2DRegion2D::rr_disjoint_m1 :
            cout << "rr_disjoint_m1 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_meet_m2 :
            cout << "rr_meet_m2 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_meet_m3 :
            cout << "rr_meet_m3 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_meet_m4 :
            cout << "rr_meet_m4 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_equal_m5 :
            cout << "rr_equal_m5 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_coveredby_m6 :
            cout << "rr_coveredby_m6 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_inside_m7 :
            cout << "rr_inside_m7 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_coveredby_m8 :
            cout << "rr_coveredby_m8 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_coveredby_m9 :
            cout << "rr_coveredby_m9 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m10 :
            cout << "rr_overlap_m10 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_covers_m11 :
            cout << "rr_covers_m11 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m12 :
            cout << "rr_overlap_m12 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m13 :
            cout << "rr_overlap_m13 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m14 :
            cout << "rr_overlap_m14 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m15 :
            cout << "rr_overlap_m15 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m16 :
            cout << "rr_overlap_m16 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m17 :
            cout << "rr_overlap_m17 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m18 :
            cout << "rr_overlap_m18 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_contains_m19 :
            cout << "rr_contains_m19 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m20 :
            cout << "rr_overlap_m20 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_covers_m21 :
            cout << "rr_covers_m21 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m22 :
            cout << "rr_overlap_m22 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m23 :
            cout << "rr_overlap_m23 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_covers_m24 :
            cout << "rr_covers_m24 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m25 :
            cout << "rr_overlap_m25 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m26 :
            cout << "rr_overlap_m26 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m27 :
            cout << "rr_overlap_m27 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m28 :
            cout << "rr_overlap_m28 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m29 :
            cout << "rr_overlap_m29 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m30 :
            cout << "rr_overlap_m30 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m31 :
            cout << "rr_overlap_m31 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m32 :
            cout << "rr_overlap_m32 <===";
            break;
        case TopPredNumberRegion2DRegion2D::rr_overlap_m33 :
            cout << "rr_overlap_m33 <===";
            break;
    }
}
