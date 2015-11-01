#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "ConvexHull.h"
#include "Point2D.h"
#include "Region2D.h"

#include <vector>

/* provides static class ConvexHull with overloaded methods compute convex hull */



Region2D computeJarvis(const vector<Poi2D> &point_list);

Region2D computeGraham(const vector<Poi2D> &point_list);

Region2D computeQuick(const vector<Poi2D> &point_list);

Region2D computeDivideConquer(const vector<Poi2D> &point_list);

Region2D computeNewAlgo(const vector<Poi2D> &point_list);

//to be implemented later:
//Region 2D computeHull(const Point2D &complex_point);




#endif
