#include "SpatialOperations.h" 
#include <stdio.h>
#include "planesweep-project/Topic1/RobustGeometricPrimitives2D.h"
#include "planesweep-project/Topic2/Implementation/Line2D.h"
#include "planesweep-project/Topic2/Interfaces/Region2D.h"

int main()
{ 

  Poi2D point;
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