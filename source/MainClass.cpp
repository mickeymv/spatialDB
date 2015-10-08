#include "spatialoperations.h"  
#include <stdio.h>



int main()
	{  

	Point2D point;
 	Line2D line;
	Region2D region;

	point = getSpatialIntersection(point, point);
	line = getSpatialUnion(line, line);
	region = getSpatialDifference(region, region);

	printf("\nSuccessfully run!\n");

	return 0;
	}