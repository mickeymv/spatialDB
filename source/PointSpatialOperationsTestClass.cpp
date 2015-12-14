//#include "SpatialOperations.h"
//#include "planesweep-project/Topic2/Implementation/Point2D.h"
//
//int main()
//{
//
//  /*
//   * We need three types of test cases.
//   *  1. a) Point-Point intersection.
//   *     b) Point-Point union.
//   *     c) Point-Point difference.
//   */
//
//  /* 1.  Computation of spatial operations (intersection/union/difference) between two spatial points.
//          I) No common points.
//            I.x) Both point objects are null.
//            I.y) One point object is null.
//            I.z) Both point objects are non empty but no common points.
//          II) Some points in common.
//
//          III)  All points in common.
//*/
//
//  //---------------------------------------
//  //Case 1.I.x): Point Operations Case where the two point objects (1&2) are null.
//
//  Point2D point1, point2, pointIntersection12, pointUnion12, pointDifference12;
//  cout<<"---------------------------------------" << endl;
//  cout<<"Point Operations Case where the two point objects (1&2) are null." << endl;
//
//  cout<<"point1 info is: " << point1;
//  if(point1.isEmptyPoint2D())
//    cout<<"empty point1 structure"<<endl;
//  else
//    cout<<"nonempty point1 structure"<<endl;
//  cout<<"point1 number of points is " << point1.numPoints()<<endl;
//  cout<<endl;
//
//  cout<<"point2 info is: " << point2;
//  if(point2.isEmptyPoint2D())
//    cout<<"empty point2 structure"<<endl;
//  else
//    cout<<"nonempty point2 structure"<<endl;
//  cout<<"point2 number of points is " << point2.numPoints()<<endl;
//  cout<<endl;
//
//  pointIntersection12 = spatialIntersection(point1, point2);
//  cout<<"pointIntersection12 info is: " << pointIntersection12;
//  if(pointIntersection12.isEmptyPoint2D())
//    cout<<"empty pointIntersection12 structure"<<endl;
//  else
//    cout<<"nonempty pointIntersection12 structure"<<endl;
//  cout<<"pointIntersection12 number of points is " << pointIntersection12.numPoints()<<endl;
//  cout<<endl;
//
//  pointUnion12 = spatialUnion(point1, point2);
//  cout<<"pointUnion12 info is: " << pointUnion12;
//  if(pointUnion12.isEmptyPoint2D())
//    cout<<"empty pointUnion12 structure"<<endl;
//  else
//    cout<<"nonempty pointUnion12 structure"<<endl;
//  cout<<"pointUnion12 number of points is " << pointUnion12.numPoints()<<endl;
//  cout<<endl;
//
//  pointDifference12 = spatialDifference(point1, point2);
//  cout<<"pointDifference12 info is: " << pointDifference12;
//  if(pointDifference12.isEmptyPoint2D())
//    cout<<"empty pointDifference12 structure"<<endl;
//  else
//    cout<<"nonempty pointDifference12 structure"<<endl;
//  cout<<"pointDifference12 number of points is " << pointDifference12.numPoints()<<endl;
//  cout<<endl;
//
//  //---------------------------------------
//  //Case 1.I.y): Point Operations Case where one point object (3) is null.
//
//  Point2D point3("((1,1),(2,2),(3,3))"), point4, pointIntersection34, pointUnion34, pointDifference34;
//
//  cout<<"---------------------------------------" << endl;
//
//  cout<<"Point Operations Case where one point object (3) is null." << endl;
//
//  cout<<"point3 info is: " << point3;
//  if(point3.isEmptyPoint2D())
//    cout<<"empty point3 structure"<<endl;
//  else
//    cout<<"nonempty point3 structure"<<endl;
//  cout<<"point3 number of points is " << point3.numPoints()<<endl;
//  cout<<endl;
//
//  cout<<"point4 info is: " << point4;
//  if(point4.isEmptyPoint2D())
//    cout<<"empty point4 structure"<<endl;
//  else
//    cout<<"nonempty point4 structure"<<endl;
//  cout<<"point4 number of points is " << point4.numPoints()<<endl;
//  cout<<endl;
//
//  pointIntersection34 = spatialIntersection(point3, point4);
//
//  cout<<"pointIntersection34 info is: " << pointIntersection34;
//  if(pointIntersection34.isEmptyPoint2D())
//    cout<<"empty pointIntersection34 structure"<<endl;
//  else
//    cout<<"nonempty pointIntersection34 structure"<<endl;
//  cout<<"pointIntersection34 number of points is " << pointIntersection34.numPoints()<<endl;
//  cout<<endl;
//
//  pointUnion34 = spatialUnion(point3, point4);
//  cout<<"pointUnion34 info is: " << pointUnion34;
//  if(pointUnion34.isEmptyPoint2D())
//    cout<<"empty pointUnion34 structure"<<endl;
//  else
//    cout<<"nonempty pointUnion34 structure"<<endl;
//  cout<<"pointUnion34 number of points is " << pointUnion34.numPoints()<<endl;
//  cout<<endl;
//
////  pointDifference34 = spatialDifference(point3, point4);
////  cout<<"pointDifference34 info is: " << pointDifference34;
////  if(pointDifference34.isEmptyPoint2D())
////    cout<<"empty pointDifference34 structure"<<endl;
////  else
////    cout<<"nonempty pointDifference34 structure"<<endl;
////  cout<<"pointDifference34 number of points is " << pointDifference34.numPoints()<<endl;
////  cout<<endl;
//
//  //---------------------------------------
//  //Case 1.I.z): Point Operations Case where both point object (5&6)
//  // are non-empty with no common points.
//
////  Point2D point5("((1,2),(2,3),(3,4))"), point6("((1,1),(2,2),(3,3))"), pointIntersection56, pointUnion56, pointDifference56;
////
//  cout<<"---------------------------------------" << endl;
////
////  cout<<"Point Operations Case where both point object (5&6) are non-empty with no common points." << endl;
////
////  cout<<"point5 info is: " << point5;
////  if(point5.isEmptyPoint2D())
////    cout<<"empty point5 structure"<<endl;
////  else
////    cout<<"nonempty point5 structure"<<endl;
////  cout<<"point5 number of points is " << point5.numPoints()<<endl;
////  cout<<endl;
////
////  cout<<"point6 info is: " << point6;
////  if(point6.isEmptyPoint2D())
////    cout<<"empty point6 structure"<<endl;
////  else
////    cout<<"nonempty point6 structure"<<endl;
////  cout<<"point6 number of points is " << point6.numPoints()<<endl;
////  cout<<endl;
////
////  pointIntersection56 = spatialIntersection(point5, point6);
////
////  cout<<"pointIntersection56 info is: " << pointIntersection56;
////  if(pointIntersection56.isEmptyPoint2D())
////    cout<<"empty pointIntersection56 structure"<<endl;
////  else
////    cout<<"nonempty pointIntersection56 structure"<<endl;
////  cout<<"pointIntersection56 number of points is " << pointIntersection56.numPoints()<<endl;
////  cout<<endl;
////
////  pointUnion56 = spatialUnion(point5, point6);
////  cout<<"pointUnion56 info is: " << pointUnion56;
////  if(pointUnion56.isEmptyPoint2D())
////    cout<<"empty pointUnion56 structure"<<endl;
////  else
////    cout<<"nonempty pointUnion56 structure"<<endl;
////  cout<<"pointUnion56 number of points is " << pointUnion56.numPoints()<<endl;
////  cout<<endl;
////
////  pointDifference56 = spatialDifference(point5, point6);
////  cout<<"pointDifference56 info is: " << pointDifference56;
////  if(pointDifference56.isEmptyPoint2D())
////    cout<<"empty pointDifference56 structure"<<endl;
////  else
////    cout<<"nonempty pointDifference56 structure"<<endl;
////  cout<<"pointDifference56 number of points is " << pointDifference56.numPoints()<<endl;
////  cout<<endl;
////
////  //---------------------------------------
////  //Case 1.II): Point Operations Case where both point object (7&8)
////  // are non-empty with some common points.
////
////  Point2D point7("((1,2),(8,9),(2,3))"), point8("((8,9),(1,1),(2,2),(3,3),(3,4))"), pointIntersection78, pointUnion78, pointDifference78;
////
////  cout<<"---------------------------------------" << endl;
////
////  cout<<"Point Operations Case where both point object (7&8) are non-empty with some common points." << endl;
////
////  cout<<"point7 info is: " << point7;
////  if(point7.isEmptyPoint2D())
////    cout<<"empty point7 structure"<<endl;
////  else
////    cout<<"nonempty point7 structure"<<endl;
////  cout<<"point7 number of points is " << point7.numPoints()<<endl;
////  cout<<endl;
////
////  cout<<"point8 info is: " << point8;
////  if(point8.isEmptyPoint2D())
////    cout<<"empty point8 structure"<<endl;
////  else
////    cout<<"nonempty point8 structure"<<endl;
////  cout<<"point8 number of points is " << point8.numPoints()<<endl;
////  cout<<endl;
////
////  pointIntersection78 = spatialIntersection(point7, point8);
////
////  cout<<"pointIntersection78 info is: " << pointIntersection78;
////  if(pointIntersection78.isEmptyPoint2D())
////    cout<<"empty pointIntersection78 structure"<<endl;
////  else
////    cout<<"nonempty pointIntersection78 structure"<<endl;
////  cout<<"pointIntersection78 number of points is " << pointIntersection78.numPoints()<<endl;
////  cout<<endl;
////
////  pointUnion78 = spatialUnion(point7, point8);
////  cout<<"pointUnion78 info is: " << pointUnion78;
////  if(pointUnion78.isEmptyPoint2D())
////    cout<<"empty pointUnion78 structure"<<endl;
////  else
////    cout<<"nonempty pointUnion78 structure"<<endl;
////  cout<<"pointUnion78 number of points is " << pointUnion78.numPoints()<<endl;
////  cout<<endl;
////
////  pointDifference78 = spatialDifference(point7, point8);
////  cout<<"pointDifference78 info is: " << pointDifference78;
////  if(pointDifference78.isEmptyPoint2D())
////    cout<<"empty pointDifference78 structure"<<endl;
////  else
////    cout<<"nonempty pointDifference78 structure"<<endl;
////  cout<<"pointDifference78 number of points is " << pointDifference78.numPoints()<<endl;
////  cout<<endl;
////
////  //---------------------------------------
////  //Case 1.III): Point Operations Case where both point object (9&10)
////  // are non-empty with all common points.
////
////  Point2D point9("((1,2),(8,9),(2,3),(3,4),(5,6))"), point10("((1,2),(8,9),(2,3),(3,4),(5,6))"), pointIntersection910, pointUnion910, pointDifference910;
////
////  cout<<"---------------------------------------" << endl;
////
////  cout<<"Point Operations Case where both point object (9&10) are non-empty with all common points." << endl;
////
////  cout<<"point9 info is: " << point9;
////  if(point9.isEmptyPoint2D())
////    cout<<"empty point9 structure"<<endl;
////  else
////    cout<<"nonempty point9 structure"<<endl;
////  cout<<"point9 number of points is " << point9.numPoints()<<endl;
////  cout<<endl;
////
////  cout<<"point10 info is: " << point10;
////  if(point10.isEmptyPoint2D())
////    cout<<"empty point10 structure"<<endl;
////  else
////    cout<<"nonempty point10 structure"<<endl;
////  cout<<"point10 number of points is " << point10.numPoints()<<endl;
////  cout<<endl;
////
////  pointIntersection910 = spatialIntersection(point9, point10);
////
////  cout<<"pointIntersection910 info is: " << pointIntersection910;
////  if(pointIntersection910.isEmptyPoint2D())
////    cout<<"empty pointIntersection910 structure"<<endl;
////  else
////    cout<<"nonempty pointIntersection910 structure"<<endl;
////  cout<<"pointIntersection910 number of points is " << pointIntersection910.numPoints()<<endl;
////  cout<<endl;
////
////  pointUnion910 = spatialUnion(point9, point10);
////  cout<<"pointUnion910 info is: " << pointUnion910;
////  if(pointUnion910.isEmptyPoint2D())
////    cout<<"empty pointUnion910 structure"<<endl;
////  else
////    cout<<"nonempty pointUnion910 structure"<<endl;
////  cout<<"pointUnion910 number of points is " << pointUnion910.numPoints()<<endl;
////  cout<<endl;
////
////  pointDifference910 = spatialDifference(point9, point10);
////  cout<<"pointDifference910 info is: " << pointDifference910;
////  if(pointDifference910.isEmptyPoint2D())
////    cout<<"empty pointDifference910 structure"<<endl;
////  else
////    cout<<"nonempty pointDifference910 structure"<<endl;
////  cout<<"pointDifference910 number of points is " << pointDifference910.numPoints()<<endl;
////  cout<<endl;
////  cout<<"---------------------------------------" << endl;
////  printf("\nSuccessfully ran Group 3's Point Spatial Operations Test Program!\n\n");
////  cout<<"---------------------------------------" << endl;
////  return 0;
//}