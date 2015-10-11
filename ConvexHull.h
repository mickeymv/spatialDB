#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "Dummy.h"

/* provides static class ConvexHull with overloaded methods compute convex hull */



class ConvexHull {
	public:
		static Region2D computeConvexHull(Point2D complex_point);
};

#endif
