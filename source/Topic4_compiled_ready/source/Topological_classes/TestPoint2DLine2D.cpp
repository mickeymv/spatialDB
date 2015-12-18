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
    delete apl;
    delete bpl;
    result = false;



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

    delete apl;
    delete bpl;
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

    delete apl;
    delete bpl;
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

    delete apl;
    delete bpl;


    cout << "Test succesfully ended." << endl;


}
