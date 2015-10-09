#ifndef CONVEXHULL_H
#define CONVEXHULL_H

/* provides static class ConvexHull with overloaded methods compute convex hull */

class ConvexHull {
	public:
	static Region2D computeConvexHull(Point2D complex_point){}

	static Region2D computeConvexHull(Region2D region){}

	static Region2D computeConvexHull(Line2D complex_line){}
};
 
#endif