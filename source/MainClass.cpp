#include "Group3SpatialOperations.h" 
#include <stdio.h>

int main()
{ 

  Point2D point;
  Line2D line;
  Region2D region;

  point = getSpatialIntersection(point, point);
  line = getSpatialUnion(line, line);
  region = getSpatialDifference(region, region);

  printf("\nSuccessfully ran Group 3's Spatial Operations Program!\n\n");

  return 0;
}