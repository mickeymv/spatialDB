#include "spatialoperations.h"  

int main()
	{  

	Point2D point;
 	Line2D line;
	Region2D region;

	point = getSpatialIntersection(point, point);
	line = getSpatialUnion(line, line);
	region = getSpatialDifference(region, region);


	return 0;
	}