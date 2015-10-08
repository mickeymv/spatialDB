#ifndef _topologicalrelationship_h
#define _topologicalrelationship_h

/* dependency on point2d, line2d, region2d (should we include the file as a header, or list the dependency in the make file??) */

/* Topological Relationship between a point2D object and a point2D object */
int getTopologicalRelationship(point2D point1, point2D point2);
bool isTopologicalRelationship(point2D point1, point2D point2, int predicate);

/* Topological Relationship between a point2D object and a line2D object */
int getTopologicalRelationship(point2D point1, line2D line2);
bool isTopologicalRelationship(point2D point1, line2D line2, int predicate);

/* Topological Relationship between a point2D object and a region2D object */
int getTopologicalRelationship(point2D point1, region2D region2);
bool isTopologicalRelationship(point2D point1, region2D region2, int predicate);

/* Topological Relationship between a line2D object and a line2D object */
int getTopologicalRelationship(line2D line1, line2D line2);
bool isTopologicalRelationship(line2D line1, line2D line2, int predicate);

/* Topological Relationship between a line2D object and a region2D object */
int getTopologicalRelationship(line2D line1, region2D region2);
bool isTopologicalRelationship(line2D line1, region2D region2, int predicate);

/* Topological Relationship between a region2D object and a region2D object */
int getTopologicalRelationship(region2D region1, region2D region2);
bool isTopologicalRelationship(region2D region1, region2D region2, int predicate);

#endif
