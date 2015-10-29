#include "SpatialOperations.h" 
#include <stdio.h>
#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

int main()
{ 

  Point2D point;
  Line2D line;
  Region2D region;

//Computation of spatial intersection between two spatial points.
  point = spatialIntersection(point, point);
  
//Computation of spatial union between two spatial lines.  
  line = spatialUnion(line, line);
  
//Computation of spatial difference between two spatial regions.  
  region = spatialDifference(region, region);

  printf("\nSuccessfully ran Group 3's Spatial Operations Program!\n\n");

  return 0;
}