//
// Created by Sarath Francis on 12/13/15.
//

#include "SpatialOperations.h"
#include "planesweep-project/Topic2/Implementation/Line2D.h"

int main() {

    Line2D line;

    /* We need three test cases
     *  1. a) Line-Line intersection.
     *     b) Line-Line union.
     *     c) Line-Line difference.
     *
     */

    /* 1. a) Computation of spatial intersection between two spatial Lines.
          I) No common segments.
            I.x) Both Line objects are null.
            I.y) One Line object is null.
            I.z) Both Line objects are non empty but no common segments.
          II) Some segments in common.

          III)  All segments in common.

          */

    cout << "\n\n------------------LINE  SPATIAL OPERATIONS Testing starts here ----------------------\n" <<endl;

    //---------------------------------------
    //Case 1.I.x): Line Operations Case where the two Line objects (1&2) are null.

    Line2D line1, line2, lineIntersection12, lineUnion12, lineDifference12;
    cout<<"---------------------------------------" << endl;
    cout<<"Line Operations Case where the two Line objects (1&2) are null." << endl;

    cout<<"line1 info is: " << line1;
    if(line1.isEmptyLine2D())
        cout<<"empty line1 structure"<<endl;
    else
        cout<<"nonempty line1 structure"<<endl;
    cout<<"line1 number of segments is " << line1.getNumberOfSegments()<<endl;
    cout<<endl;

    cout<<"line2 info is: " << line2;
    if(line2.isEmptyLine2D())
        cout<<"empty line2 structure"<<endl;
    else
        cout<<"nonempty line2 structure"<<endl;
    cout<<"line2 number of segments is " << line2.getNumberOfSegments()<<endl;
    cout<<endl;

    lineIntersection12 = spatialIntersection(line1, line2);
    cout<<"lineIntersection12 info is: " << lineIntersection12;
    if(lineIntersection12.isEmptyLine2D())
        cout<<"empty lineIntersection12 structure"<<endl;
    else
        cout<<"nonempty lineIntersection12 structure"<<endl;
    cout<<"lineIntersection12 number of segments is " <<lineIntersection12.getNumberOfSegments()<<endl;
    cout<<endl;

    lineUnion12 = spatialUnion(line1, line2);
    cout<<"lineUnion12 info is: " << lineUnion12;
    if(lineUnion12.isEmptyLine2D())
        cout<<"empty LineUnion12 structure"<<endl;
    else
        cout<<"nonempty LineUnion12 structure"<<endl;
    cout<<"LineUnion12 number of segments is " << lineUnion12.getNumberOfSegments()<<endl;
    cout<<endl;

    lineDifference12 = spatialDifference(line1,line2);
    cout<<"lineDifference12 info is: " << lineDifference12;
    if(lineDifference12.isEmptyLine2D())
        cout<<"empty lineDifference12 structure"<<endl;
    else
        cout<<"nonempty lineDifference12 structure"<<endl;
    cout<<"lineDifference12 number of segments is " <<lineDifference12.getNumberOfSegments()<<endl;
    cout<<endl;


    //---------------------------------------
    //Case 1.I.y): Line Operations Case where one line object ( Line 4) is Null.

    Line2D line3("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)))"), line4, lineIntersection34, lineUnion34, lineDifference34;
    cout<<"---------------------------------------" << endl;
    cout<<"Line Operations Case where one line object ( line 4) is null." << endl;

    cout<<"line3 info is: " << line3;
    if(line3.isEmptyLine2D())
        cout<<"empty line3 structure"<<endl;
    else
        cout<<"nonempty line3 structure"<<endl;
    cout<<"line3 number of segments is " << line3.getNumberOfSegments()<<endl;
    cout<<endl;

    cout<<"line4 info is: " << line4;
    if(line4.isEmptyLine2D())
        cout<<"empty line4 structure"<<endl;
    else
        cout<<"nonempty line4 structure"<<endl;
    cout<<"line4 number of segments is " << line4.getNumberOfSegments()<<endl;
    cout<<endl;

    lineIntersection34 = spatialIntersection(line3, line4);
    cout<<"lineIntersection34 info is: " << lineIntersection34;
    if(lineIntersection34.isEmptyLine2D())
        cout<<"empty lineIntersection34 structure"<<endl;
    else
        cout<<"nonempty lineIntersection34 structure"<<endl;
    cout<<"lineIntersection34 number of segments is " <<lineIntersection34.getNumberOfSegments()<<endl;
    cout<<endl;

    lineUnion34 = spatialUnion(line3, line4);
    cout<<"lineUnion34 info is: " << lineUnion34;
    if(lineUnion34.isEmptyLine2D())
        cout<<"empty lineUnion34 structure"<<endl;
    else
        cout<<"nonempty lineUnion34 structure"<<endl;
    cout<<"lineUnion34 number of segments is " << lineUnion34.getNumberOfSegments()<<endl;
    cout<<endl;

    lineDifference34 = spatialDifference(line3,line4);
    cout<<"lineDifference34 info is: " << lineDifference34;
    if(lineDifference34.isEmptyLine2D())
        cout<<"empty lineDifference34 structure"<<endl;
    else
        cout<<"nonempty lineDifference34 structure"<<endl;
    cout<<"lineDifference34 number of segments is " <<lineDifference34.getNumberOfSegments()<<endl;
    cout<<endl;

    //---------------------------------------
    //Case 1.I.z): Line Operations Case where both the line objects are not null with no common segments.

    Line2D line5("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)))"), line6("(((0,1),(1,2)),((1,2),(2,3)),((2,3),(3,4)),((3,4),(4,5)))"), lineIntersection56, lineUnion56, lineDifference56;
    cout<<"---------------------------------------" << endl;
    cout<<"Line Operations Case both the line objects are not null with no common segments" << endl;

    cout<<"line5 info is: " << line5;
    if(line5.isEmptyLine2D())
        cout<<"empty line5 structure"<<endl;
    else
        cout<<"nonempty line5 structure"<<endl;
    cout<<"line5 number of segments is " << line5.getNumberOfSegments()<<endl;
    cout<<endl;

    cout<<"line6 info is: " << line6;
    if(line6.isEmptyLine2D())
        cout<<"empty line6 structure"<<endl;
    else
        cout<<"nonempty line6 structure"<<endl;
    cout<<"line6 number of segments is " << line6.getNumberOfSegments()<<endl;
    cout<<endl;

    lineIntersection56 = spatialIntersection(line5, line6);

    cout<<"lineIntersection56 info is: " << lineIntersection56;
    if(lineIntersection56.isEmptyLine2D())
        cout<<"empty lineIntersection56 structure"<<endl;
    else
        cout<<"nonempty lineIntersection56 structure"<<endl;
    cout<<"lineIntersection56 number of segments is " <<lineIntersection56.getNumberOfSegments()<<endl;
    cout<<endl;

    lineUnion56 = spatialUnion(line5, line6);
    cout<<"lineUnion56 info is: " << lineUnion56;
    if(lineUnion56.isEmptyLine2D())
        cout<<"empty lineUnion56 structure"<<endl;
    else
        cout<<"nonempty lineUnion56 structure"<<endl;
    cout<<"lineUnion56 number of segments is " << lineUnion56.getNumberOfSegments()<<endl;
    cout<<endl;

    lineDifference56 = spatialDifference(line5,line6);
    cout<<"lineDifference56 info is: " << lineDifference56;
    if(lineDifference56.isEmptyLine2D())
        cout<<"empty lineDifference56 structure"<<endl;
    else
        cout<<"nonempty lineDifference56 structure"<<endl;
    cout<<"lineDifference56 number of segments is " <<lineDifference56.getNumberOfSegments()<<endl;
    cout<<endl;
    //---------------------------------------
    //Case 1.II): Line Operations Case where both the line objects are not null with some common segments

    Line2D line7("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)))"), line8("(((0,0),(1,1)),((1,1),(2,3)),((2,3),(3,3)),((3,3),(4,4)))"), lineIntersection78, lineUnion78, lineDifference78;
    cout<<"---------------------------------------" << endl;
    cout<<"Line Operations Case both the line objects are not null with some common segments" << endl;

    cout<<"line7 info is: " << line7;
    if(line7.isEmptyLine2D())
        cout<<"empty line7 structure"<<endl;
    else
        cout<<"nonempty line7 structure"<<endl;
    cout<<"line7 number of segments is " << line7.getNumberOfSegments()<<endl;
    cout<<endl;

    cout<<"line8 info is: " << line8;
    if(line8.isEmptyLine2D())
        cout<<"empty line8 structure"<<endl;
    else
        cout<<"nonempty line8 structure"<<endl;
    cout<<"line8 number of segments is " << line8.getNumberOfSegments()<<endl;
    cout<<endl;

    lineIntersection78 = spatialIntersection(line7, line8);
    cout<<"lineIntersection78 info is: " << lineIntersection78;
    if(lineIntersection78.isEmptyLine2D())
        cout<<"empty lineIntersection78 structure"<<endl;
    else
        cout<<"nonempty lineIntersection78 structure"<<endl;
    cout<<"lineIntersection78 number of segments is " <<lineIntersection78.getNumberOfSegments()<<endl;
    cout<<endl;

    lineUnion78 = spatialUnion(line7, line8);
    cout<<"lineUnion78 info is: " << lineUnion78;
    if(lineUnion78.isEmptyLine2D())
        cout<<"empty lineUnion78 structure"<<endl;
    else
        cout<<"nonempty lineUnion78 structure"<<endl;
    cout<<"lineUnion78 number of segments is " << lineUnion78.getNumberOfSegments()<<endl;
    cout<<endl;

    lineDifference78 = spatialDifference(line7,line8);
    cout<<"lineDifference78 info is: " << lineDifference78;
    if(lineDifference78.isEmptyLine2D())
        cout<<"empty lineDifference78 structure"<<endl;
    else
        cout<<"nonempty lineDifference78 structure"<<endl;
    cout<<"lineDifference78 number of segments is " <<lineDifference78.getNumberOfSegments()<<endl;
    cout<<endl;

    //---------------------------------------
    //Case 1.III): Line Operations Case where both the line objects are not null with all segments common

    Line2D line9("(((0,0),(1,1)),((1,1),(2,3)),((2,3),(3,3)),((3,3),(4,4)))"), line10("(((0,0),(1,1)),((1,1),(2,3)),((2,3),(3,3)),((3,3),(4,4)))"), lineIntersection910, lineUnion910, lineDifference910;
    cout<<"---------------------------------------" << endl;
    cout<<"Line Operations Case both the line objects are not null with some common segments" << endl;

    cout<<"line9 info is: " << line9;
    if(line9.isEmptyLine2D())
        cout<<"empty line9 structure"<<endl;
    else
        cout<<"nonempty line9 structure"<<endl;
    cout<<"line9 number of segments is " << line9.getNumberOfSegments()<<endl;
    cout<<endl;

    cout<<"line10 info is: " << line10;
    if(line10.isEmptyLine2D())
        cout<<"empty line10 structure"<<endl;
    else
        cout<<"nonempty line10 structure"<<endl;
    cout<<"line10 number of segments is " << line10.getNumberOfSegments()<<endl;
    cout<<endl;

    lineIntersection910 = spatialIntersection(line9, line10);
    cout<<"lineIntersection910 info is: " << lineIntersection910;
    if(lineIntersection910.isEmptyLine2D())
        cout<<"empty lineIntersection910 structure"<<endl;
    else
        cout<<"nonempty lineIntersection910 structure"<<endl;
    cout<<"lineIntersection910 number of segments is " <<lineIntersection910.getNumberOfSegments()<<endl;
    cout<<endl;

    lineUnion910 = spatialUnion(line9, line10);
    cout<<"lineUnion910 info is: " << lineUnion910;
    if(lineUnion910.isEmptyLine2D())
        cout<<"empty lineUnion910 structure"<<endl;
    else
        cout<<"nonempty lineUnion910 structure"<<endl;
    cout<<"lineUnion910 number of segments is " << lineUnion910.getNumberOfSegments()<<endl;
    cout<<endl;

    lineDifference910 = spatialDifference(line9,line10);
    cout<<"lineDifference910 info is: " << lineDifference910;
    if(lineDifference910.isEmptyLine2D())
        cout<<"empty lineDifference910 structure"<<endl;
    else
        cout<<"nonempty lineDifference910 structure"<<endl;
    cout<<"lineDifference910 number of segments is " <<lineDifference910.getNumberOfSegments()<<endl;
    cout<<endl;

}