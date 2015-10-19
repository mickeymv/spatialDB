#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"
#ifndef _SpatialOperations_h
#define _SpatialOperations_h

Point2D intersection(Point2D point1, Point2D point2);
Point2D spatialUnion(Point2D point1, Point2D point2);
Point2D difference(Point2D point1, Point2D point2);
Line2D intersection(Line2D line1, Line2D line2);
Line2D spatialUnion(Line2D line1, Line2D line2);
Line2D difference(Line2D line1, Line2D line2);
Region2D intersection(Region2D region1, Region2D region2); 
Region2D spatialUnion(Region2D region1, Region2D region2);
Region2D difference(Region2D region1, Region2D region2);

#endif