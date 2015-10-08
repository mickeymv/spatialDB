#ifndef _spatialoperations_h
#define _spatialoperations_h

class Point2D {};
class Line2D {};
class Region2D {};


		 Point2D getSpatialIntersection(Point2D point1, Point2D point2);
		 Point2D getSpatialUnion(Point2D point1, Point2D point2);
		 Point2D getSpatialDifference(Point2D point1, Point2D point2);
		 Line2D getSpatialIntersection(Line2D line1, Line2D line2);
		 Line2D getSpatialUnion(Line2D line1, Line2D line2);
		 Line2D getSpatialDifference(Line2D line1, Line2D line2);
		 Region2D getSpatialIntersection(Region2D region1, Region2D region2);	
		 Region2D getSpatialUnion(Region2D region1, Region2D region2);
		 Region2D getSpatialDifference(Region2D region1, Region2D region2);

#endif