#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "ConvexHull.h"
#include "Point2D.h"
#include "Region2D.h"
#include "vector"

/* provides static class ConvexHull with overloaded methods compute convex hull */



class ConvexHull {
	public:
		static Region2D computeJarvis(const vector<Poi2D> &unordered_points);

		static Region2D computeGraham(const vector<Poi2D> &unordered_points);

		static Region2D computeQuick(const vector<Poi2D> &unordered_points);

		static Region2D computeDivideConquer(const vector<Poi2D> &unordered_points);

		static Region2D computeNewAlgo(const vector<Poi2D> &unordered_points);

		//to be implemented later:
		//Region 2D computeHull(const Point2D &complex_point);
};



#endif
