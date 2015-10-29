#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "ConvexHull.h"
#include "Point2D.h"
#include "Region2D.h"
#include "vector"

/* provides static class ConvexHull with overloaded methods compute convex hull */



class ConvexHull {
	public:
		static Region2D computeJarvis(vector<Poi2D> unordered_points);

		static Region2D computeGraham(vector<Poi2D> unordered_points);

		static Region2D computeQuick(vector<Poi2D> unordered_points);

		static Region2D computeDivideConquer(vector<Poi2D> unordered_points);

		static Region2D computeNewAlgo(vector<Poi2D> unordered_points);
};

#endif
