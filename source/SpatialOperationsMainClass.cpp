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

  point = spatialIntersection(point, point);
  line = spatialUnion(line, line);
  region = spatialDifference(region, region);

  printf("\nSuccessfully ran Group 3's Spatial Operations Program!\n\n");

  return 0;
}