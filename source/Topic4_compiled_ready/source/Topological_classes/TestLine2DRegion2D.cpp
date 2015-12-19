//
// Created by Djundi on 12/18/15.
//

#include "TestLine2DRegion2D.h"

void TestLine2DRegion2D::start() {

    //     *****************************
    //     Case 5: Line2DRegion2D
    //     *****************************

    Line2D *alr;
    Region2D *blr;
    TopPredNumberLine2DRegion2D trlred;
    bool result = false;

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
    printPredicate(trlred);

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_disjoint_m1);
    cout << "   isTopologicalRelationship(a, b, lr_disjoint_m1) ==> " << printBool(result) << endl;

    cout << "   disjoint() ==> " << printBool(disjoint(*alr, *blr)) << endl;
    cout << "   overlap() ==> " << printBool(overlap(*alr, *blr)) << endl;
    cout << endl;

    delete alr;
    delete blr;


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
    printPredicate(trlred);

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_meet_m3);
    cout << "   isTopologicalRelationship(a, b, lr_meet_m3) ==> " << printBool(result) << endl;

    cout << "   touch() ==> " << printBool(touch(*alr, *blr)) << endl;
    cout << "   overlap() ==> " << printBool(overlap(*alr, *blr)) << endl;
    cout << endl;

    delete alr;
    delete blr;
    result = false;


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
    printPredicate(trlred);

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_overlap_m20);
    cout << "   isTopologicalRelationship(a, b, lr_overlap_m20) ==> " << printBool(result) << endl;

    cout << "   overlap() ==> " << printBool(overlap(*alr, *blr)) << endl;
    cout << "   touch() ==> " << printBool(touch(*alr, *blr)) << endl;
    cout << endl;

    delete alr;
    delete blr;


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
    printPredicate(trlred);

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_coveredby_m17);
    cout << "   isTopologicalRelationship(a, b, lr_coveredby_m17) ==> " << printBool(result) << endl;

    cout << "   coveredby() ==> " << printBool(coveredBy(*alr, *blr)) << endl;
    cout << "   touch() ==> " << printBool(touch(*alr, *blr)) << endl;
    cout << endl;

    delete alr;
    delete blr;


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
    printPredicate(trlred);

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_overlap_m20);
    cout << "   isTopologicalRelationship(a, b, lr_overlap_m20) ==> " << printBool(result) << endl;

    cout << "   overlap() ==> " << printBool(overlap(*alr, *blr)) << endl;
    cout << "   touch() ==> " << printBool(touch(*alr, *blr)) << endl;
    cout << endl;

    // don't forget to cleanup
    delete alr;
    delete blr;


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
    printPredicate(trlred);

    result = isTopologicalRelationship(*alr, *blr, TopPredNumberLine2DRegion2D::lr_inside_m14);
    cout << "   isTopologicalRelationship(a, b, lr_inside_m14) ==> " << printBool(result) << endl;

    cout << "   coveredby() ==> " << printBool(inside(*alr, *blr)) << endl;
    cout << "   touch() ==> " << printBool(touch(*alr, *blr)) << endl;

    delete alr;
    delete blr;
    result = false;

    cout << "Test succesfully ended." << endl;

}
