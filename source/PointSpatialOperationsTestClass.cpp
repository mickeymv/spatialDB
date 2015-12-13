#include "SpatialOperations.h"
#include "planesweep project/Topic2/Implementation/Point2D.h"

int main()
{

  /*
   * We need three types of test cases.
   *  1. a) Point-Point intersection.
   *     b) Point-Point union.
   *     c) Point-Point difference.
   */

  /* 1.  Computation of spatial intersection between two spatial points.
          I) No common points.
            I.x) Both point objects are null.
            I.y) One point object is null.
            I.z) Both point objects are non empty but no common points.
          II) Some points in common.
            II.x) Points in common are all in the start of the two objects.
            II.y) Points

          III)  All points in common.
*/

  //Case 1.I.x)

  Point2D point1, point2, pointIntersection;

  cout<<"Point Intersections Case where the two point objects are null." << endl;

  cout<<"point1 info is: " << point1;
  if(point1.isEmptyPoint2D())
    cout<<"empty point1 structure"<<endl;
  else
    cout<<"nonempty point1 structure"<<endl;
  cout<<"point1 number of points is " << point1.numPoints()<<endl;
  cout<<endl;

  cout<<"point2 info is: " << point2;
  if(point2.isEmptyPoint2D())
    cout<<"empty point2 structure"<<endl;
  else
    cout<<"nonempty point2 structure"<<endl;
  cout<<"point2 number of points is " << point2.numPoints()<<endl;
  cout<<endl;

  pointIntersection = spatialIntersection(point1, point2);

  cout<<"pointIntersection info is: " << pointIntersection;
  if(pointIntersection.isEmptyPoint2D())
    cout<<"empty pointIntersection structure"<<endl;
  else
    cout<<"nonempty pointIntersection structure"<<endl;
  cout<<"pointIntersection number of points is " << pointIntersection.numPoints()<<endl;
  cout<<endl;

  printf("\nSuccessfully ran Group 3's Point Spatial Operations Test Program!\n\n");

  return 0;
}