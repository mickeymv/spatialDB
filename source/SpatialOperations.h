#ifndef _SpatialOperations_h
#define _SpatialOperations_h

#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

Point2D spatialIntersection(const Point2D& pointLhs, const Point2D& pointRhs);
Point2D spatialUnion(const Point2D& pointLhs, const Point2D& pointRhs);
Point2D spatialDifference(const Point2D& pointLhs, const Point2D& pointRhs);
Line2D spatialIntersection(const Line2D& lineLhs, const Line2D& lineRhs);
Line2D spatialUnion(const Line2D& lineLhs, const Line2D& lineRhs);
Line2D spatialDifference(const Line2D& lineLhs, const Line2D& lineRhs);
Region2D spatialIntersection(const Region2D& regionLhs, const Region2D& regionRhs); 
Region2D spatialUnion(const Region2D& regionLhs, const Region2D& regionRhs);
Region2D spatialDifference(const Region2D& regionLhs, const Region2D& regionRhs);

#endif