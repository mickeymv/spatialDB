//
// Created by Djundi on 12/18/15.
//

#include "TestLine2DLine2D.h"

void TestLine2DLine2D::start() {


    // *****************************
    // Case 4: Line2DLine2D
    // *****************************

    //   1. Test ll_disjoint_m4

    Line2D *all, *bll;
    bool result;
    TopPredNumberLine2DLine2D tpredll;

    all = new Line2D("(((1,1),(2,2)),((2,1),(2,3)))");
    bll = new Line2D("(((4,0),(4,2)),((5,6),(7,8)))");

    cout << "*****************************" << endl;
    cout << "Case 4: Line2DLine2D" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "1. Test ll_disjoint_m4" << endl;
    cout << "Line2D(\"(((1,1),(2,2)),((2,1),(2,3)))\")" << endl;
    cout << "Line2D(\"((((4,0),(4,2)),((5,6),(7,8)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_disjoint_m4);

    cout << "   isTopologicalRelationship(a, b, ll_disjoint_m4) ==> " << printBool(result) << endl;

    cout << "   disjoint() ==> " << printBool(disjoint(*all, *bll)) << endl << endl;

    delete all;
    delete bll;


    // 2. Test ll_inside_m39
    all = new Line2D("(((1,2),(3,4)),((3,1),(4,4)))");
    bll = new Line2D("(((2,2),(2,3)),((3,2),(3,3)))");

    cout << "2. Test ll_inside_m39" << endl;
    cout << "Line2D(\"((1,2),(3,4)),((3,1),(4,4)))\")" << endl;
    cout << "Line2D(\"((((2,2),(2,3)),((3,2),(3,3)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_inside_m39);

    cout << "   isTopologicalRelationship(a, b, ll_inside_m39) ==> " << printBool(result) << endl;

    cout << "   inside() ==> " << printBool(inside(*all, *bll)) << endl << endl;

    delete all;
    delete bll;



    // 3. Test ll_overlap_m44
    all = new Line2D("(((1,1),(3,4)),((5,6),(7,8)))");
    bll = new Line2D("(((1,3),(3,1)),((5,5),(7,7)))");

    cout << "3. Test ll_overlap_m44" << endl;
    cout << "Line2D(\"(((1,1),(3,4)),((5,6),(7,8)))\")" << endl;
    cout << "Line2D(\"(((1,3),(3,1)),((5,5),(7,7)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_overlap_m44);
    cout << "   isTopologicalRelationship(a, b, ll_overlap_m44) ==> " << printBool(result) << endl;

    cout << "   overlap() ==> " << printBool(overlap(*all, *bll)) << endl << endl;


    delete all;
    delete bll;

    // 4. Test ll_covers_m49
    all = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");
    bll = new Line2D("(((1,1),(1,2)),((1,1),(1,3)))");

    cout << "4. Test ll_covers_m49" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;
    cout << "Line2D(\"(((1,1),(1,2)),((1,1),(1,3)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_covers_m49);
    cout << "   isTopologicalRelationship(a, b, ll_covers_m49) ==> " << printBool(result) << endl;

    cout << "   covers() ==> " << printBool(covers(*all, *bll))  << endl << endl;

    delete all;
    delete bll;


    // 5. Test ll_coveredby_m37
    all = new Line2D("(((1,1),(1,2)),((1,1),(1,3)))");
    bll = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");

    cout << "5. Test ll_coveredby_m37" << endl;
    cout << "Line2D(\"(((1,1),(1,2)),((1,1),(1,3)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_coveredby_m37);
    cout << "   isTopologicalRelationship(a, b, ll_coveredby_m37) ==> " << printBool(result) << endl;

    cout << "   coveredby() ==> " << printBool(coveredBy(*all, *bll))  << endl << endl;

    delete all;
    delete bll;

    // 6. Test ll_equal_m33
    all = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");
    bll = new Line2D("(((1,2),(3,4)),((5,6),(7,8)))");

    cout << "6. Test ll_equal_m33." << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_equal_m33);
    cout << "   isTopologicalRelationship(a, b, ll_equal_m33) ==> " << printBool(result) << endl;
    cout << endl;

    delete all;
    delete bll;

    // 7. Test ll_contains_m46
    all = new Line2D("(((2,2),(2,3)),((3,2),(3,3)))");
    bll = new Line2D("(((1,2),(3,4)),((3,1),(4,4)))");

    cout << "7. Test ll_contains_m46" << endl;
    cout << "Line2D(\"(((2,2),(2,3)),((3,2),(3,3)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((3,1),(4,4)))\")" << endl;

    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_contains_m46);
    cout << "   isTopologicalRelationship(a, b, ll_contains_m46) ==> " << printBool(result) << endl;

    cout << "   contains() ==> " << printBool(contains(*all, *bll)) << endl;
    cout << endl;

    delete all;
    delete bll;


    // 8. Test ll_meet_m13
    all = new Line2D("(((1,2),(3,4)),((1,1),(2,2)))");
    bll = new Line2D("(((1,2),(4,4)),((5,6),(7,8)))");

    cout << "8. Test ll_meet_m13" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((1,1),(2,2)))\")" << endl;
    cout << "Line2D(\"(((1,2),(3,4)),((5,6),(7,8)))\")" << endl;


    tpredll = getTopologicalRelationship(*all, *bll);
    printPredicate(tpredll);

    result = isTopologicalRelationship(*all, *bll, TopPredNumberLine2DLine2D::ll_meet_m13);
    cout << "   isTopologicalRelationship(a, b, ll_meet_m13) ==> " << printBool(result) << endl;

    cout << "   touch() ==> " << printBool(touch(*all, *bll)) << endl;
    cout << endl;

    delete all;
    delete bll;

    cout << "Test succesfully ended." << endl;
}
