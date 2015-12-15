#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "poi2D.h"

#include <vector>

/* provides static class ConvexHull with overloaded methods compute convex hull */



vector<poi2D> computeJarvis(const vector<poi2D> &point_list);

vector<poi2D> computeGraham(const vector<poi2D> &point_list);

vector<poi2D> computeQuick(const vector<poi2D> &point_list);

vector<poi2D> computeDivideConquer(vector<poi2D> &point_list);

vector<poi2D> computeNewAlgo(const vector<poi2D> &point_list);

//to be implemented later:
//Region 2D computeHull(const Point2D &complex_point);




#endif
