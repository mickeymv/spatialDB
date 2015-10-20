#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "Dummy.h"

/* provides static class ConvexHull with overloaded methods compute convex hull */



class ConvexHull {
	public:
		static Region2D computeJarvis(Point2D complex_point);

		static Region2D computeGraham(Point2D complex_point);

		static Region2D computeQuick(Point2D complex_point);

		static Region2D computeDivideConquer(Point2D complex_point);

		static Region2D computeNewAlgo(Point2D complex_point);
};

#endif
