//////
////// Created by Sarath Francis on 12/13/15.
//////
//////
////// Created by Sarath Francis on 12/13/15.
//////
////
//#include "SpatialOperations.h"
//#include <stdio.h>
//#include <string>
//#include "planesweep-project/Topic1/RobustGeometricPrimitives2D.h"
//#include "planesweep-project/Topic2/Implementation/Line2D.h"
//#include "planesweep-project/Topic2/Implementation/Region2D.h"
//
//int main() {
//
//
////    Region2D region;
//
//    /* We need three test cases
//     *  1. a) Region-Region intersection.
//     *     b) Region-Region union.
//     *     c) Region-Region difference.
//     *
//     */
//
//    Region2D regionNull1, regionNull2, regionA, regionB, regionC, regionCD, regionEF, regionF, regionGH, regionHI;
//    /*
//     * 1. Computation of spatial operations between two spatial Regions.
//     *       I) No common Interiors.
//     *          I.x) Both Region objects are null. RegionNull1 and RegionNull2
//     *          I.y) One Regions object is null. RegionNull1 and RegionA
//     *          I.z) Both Region objects are non empty but no common interiors. RegionA and RegionB
//     *       II) Some Interiors in common.
//     *          II.x) Interiors in common are all in the start of the two objects.
//     *          II.y) Interiors in common are all in the end of the two objects
//     *          II.z) Interiors in common are all in the middle of the two objects
//     *       III)  All Interiors in common.
//     */
//
//    //Case 1.Ix
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where the two Region objects are null." << endl;
//
//    cout<<"Region1 info is: " << regionNull1;
//    if(regionNull1.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionNull1.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionNull2;
//    if(regionNull2.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionNull2.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersection1 = spatialIntersection(regionNull1, regionNull2);
//    cout<<"regionIntersection12 info is: " << regIntersection1;
//
//    if(regIntersection1.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersection1.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Union
//    Region2D regUnionNull = spatialUnion(regionNull1, regionNull2);
//    if(regUnionNull.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionNull.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiffNull = spatialDifference(regionNull1, regionNull2);
//    if(regDiffNull.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiffNull.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//
//    //Case 1.Iy
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where one Region objects are null." << endl;
//
//    cout<<"Region1 info is: " << regionA;
//    if(regionA.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionNull1;
//    if(regionNull1.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionNull1.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersection2 = spatialIntersection(regionA, regionNull1);
//    cout<<"regionIntersection12 info is: " << regIntersection2;
//
//    if(regIntersection2.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersection2.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Union
//    Region2D regUnionA = spatialUnion(regionA, regionNull1);
//    if(regUnionA.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiffA = spatialDifference(regionA, regionNull1);
//    if(regDiffA.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiffA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    //Case 1.Iz
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where common regions betwn"
//            "two non empty Region objects is null" << endl;
//
//    cout<<"Region1 info is: " << regionA;
//    if(regionA.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionB;
//    if(regionB.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionB.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersection3 = spatialIntersection(regionA, regionB);
//    cout<<"regionIntersection12 info is: " << regIntersection3;
//
//    if(regIntersection3.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersection3.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Union
//    Region2D regUnionAB = spatialUnion(regionA, regionB);
//    if(regUnionAB.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionAB.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiffAA = spatialDifference(regionA, regionB);
//    if(regDiffAA.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiffAA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    //Case 1.IIx
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where common regions betwn"
//            "two non empty Region objects is at the start of objects" << endl;
//
//    cout<<"Region1 info is: " << regionC;
//    if(regionC.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionC.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionCD;
//    if(regionCD.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionCD.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersectionC = spatialIntersection(regionC,regionCD);
//    cout<<"regionIntersection12 info is: " << regIntersectionC;
//
//    if(regIntersectionC.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersectionC.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Union
//    Region2D regUnionCD = spatialUnion(regionC, regionCD);
//    if(regUnionCD.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionCD.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiff0 = spatialDifference(regionC, regionCD);
//    if(regDiff0.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiff0.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    //Case 1.IIy
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where common regions betwn"
//            "two non empty Region objects is at the end of objects" << endl;
//
//    cout<<"Region1 info is: " << regionEF;
//    if(regionEF.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionEF.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionF;
//    if(regionF.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionF.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersectionF = spatialIntersection(regionEF,regionF);
//
//    cout<<"regionIntersection12 info is: " << regIntersectionF;
//
//    if(regIntersectionF.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersectionF.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Union
//    Region2D regUnionEF = spatialUnion(regionEF, regionF);
//    if(regUnionEF.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionEF.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiffE = spatialDifference(regionEF, regionF);
//    if(regDiffE.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiffE.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    //Case 1.IIz
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where common regions betwn"
//            "two non empty Region objects is in the mid of objects" << endl;
//
//    cout<<"Region1 info is: " << regionGH;
//    if(regionGH.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionGH.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionHI;
//    if(regionHI.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionHI.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersectionH = spatialIntersection(regionGH,regionHI);
//
//    cout<<"regionIntersection12 info is: " << regIntersectionH;
//
//    if(regIntersectionH.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersectionH.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Union
//    Region2D regUnionGHI = spatialUnion(regionGH, regionHI);
//    if(regUnionGHI.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionGHI.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiffG = spatialDifference(regionGH, regionHI);
//    if(regDiffG.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiffG.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    //Case 1.III
//    cout<<"---------------------------------------" << endl;
//    cout<<"Region Operations Case where common regions betwn"
//            "two non empty Region objects is in the mid of objects" << endl;
//
//    cout<<"Region1 info is: " << regionA;
//    if(regionA.isEmptyRegion2D())
//        cout<<"empty Region1 structure"<<endl;
//    else
//        cout<<"nonempty Region1 structure"<<endl;
//    cout<<"Region1 number of segments is " << regionA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout<<"Region2 info is: " << regionA;
//    if(regionA.isEmptyRegion2D())
//        cout<<"empty Region2 structure"<<endl;
//    else
//        cout<<"nonempty Region2 structure"<<endl;
//    cout<<"Region2 number of segments is " << regionA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Intersection
//    Region2D regIntersectionA = spatialIntersection(regionA,regionA);
//
//    cout<<"regionIntersection12 info is: " << regIntersectionA;
//
//    if(regIntersectionA.isEmptyRegion2D())
//        cout<<"empty regionIntersection12 structure"<<endl;
//    else
//        cout<<"nonempty regionIntersection12 structure"<<endl;
//    cout<<"regionIntersection12 number of segments is " <<regIntersectionA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//
//    // Union
//    Region2D regUnionAA = spatialUnion(regionA, regionA);
//    if(regUnionAA.isEmptyRegion2D())
//        cout<<"empty regionUnion12 structure"<<endl;
//    else
//        cout<<"nonempty regionUnion12 structure"<<endl;
//    cout<<"regionUnion12 number of segments is " <<regUnionAA.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    // Difference
//    Region2D regDiff00 = spatialDifference(regionA, regionA);
//    if(regDiff00.isEmptyRegion2D())
//        cout<<"empty regionDiff12 structure"<<endl;
//    else
//        cout<<"nonempty regionDiff12 structure"<<endl;
//    cout<<"regionDiff12 number of segments is " <<regDiff00.getNumberOfSegments()<<endl;
//    cout<<endl;
//
//    cout << "\n\n------------------REGION SPATIAL OPERATIONS Testing starts here ----------------------\n" <<endl;
//
//
////    printf("\nSuccessfully ran Group 3's Spatial Operations Program!\n\n");
////
////    return 0;
////}