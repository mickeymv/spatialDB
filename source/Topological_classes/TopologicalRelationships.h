/******************************************************************************
* File: TopologicalRelationships.h
*******************************************************************************
* Purpose: Interface to exploration functions and validation predicates for
*   the topological relationships between two complex objects of the spatial
*   data types Point2D, Line2D, and Region2D
* Description: Topological relationships characterize the relative topological
*   position between two spatial objects. [CONTINUE]
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef TOPOLOGICALRELATIONSHIPS_H
#define TOPOLOGICALRELATIONSHIPS_H

#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"
#include "Point2DLine2D.h"
#include "planesweep_project/Topic2/Implementation/Region2D.h"

#include "TopPredNumberEnums.h" 

// Exploration function and validation predicate for the topological
// relationships between two Point2D objects
TopPredNumberPoint2DPoint2D
getTopologicalRelationship(const Point2D& lhs, const Point2D& rhs);
bool isTopologicalRelationship(const Point2D& lhs, const Point2D& rhs,
                               TopPredNumberPoint2DPoint2D predicate);

// Exploration function and validation predicate for the topological
// relationships between a Point2D object and a Line2D object
TopPredNumberPoint2DLine2D
getTopologicalRelationship(const Point2D& lhs, const Line2D& rhs);
bool isTopologicalRelationship(const Point2D& lhs, const Line2D& rhs,
                               TopPredNumberPoint2DLine2D predicate);

// Exploration function and validation predicate for the topological
// relationships between a Point2D object and a Region2D object
TopPredNumberPoint2DRegion2D
getTopologicalRelationship(const Point2D& lhs, const Region2D& rhs);
bool isTopologicalRelationship(const Point2D& lhs, const Region2D& rhs,
                               TopPredNumberPoint2DRegion2D predicate);

// Exploration function and validation predicate for the topological
// relationships between two Line2D objects
TopPredNumberLine2DLine2D
getTopologicalRelationship(const Line2D& lhs, const Line2D& rhs);
bool isTopologicalRelationship(const Line2D& lhs, const Line2D& rhs,
                               TopPredNumberLine2DLine2D predicate);

// Exploration function and validation predicate for the topological
// relationships between a Line2D object and a Region2D object
TopPredNumberLine2DRegion2D
getTopologicalRelationship(const Line2D& lhs, const Region2D& rhs);
bool isTopologicalRelationship(const Line2D& lhs, const Region2D& rhs,
                               TopPredNumberLine2DRegion2D predicate);

// Exploration function and validation predicate for the topological
// relationships between two Region2D objects
TopPredNumberRegion2DRegion2D
getTopologicalRelationship(const Region2D& lhs, const Region2D& rhs);
bool isTopologicalRelationship(const Region2D& lhs, const Region2D& rhs,
                               TopPredNumberRegion2DRegion2D predicate);

// Topological cluster predicates for two Point2D objects
bool overlap(const Point2D& lhs, const Point2D& rhs);
bool disjoint(const Point2D& lhs, const Point2D& rhs);
bool meet(const Point2D& lhs, const Point2D& rhs);
bool equal(const Point2D& lhs, const Point2D& rhs);
bool contains(const Point2D& lhs, const Point2D& rhs);
bool covers(const Point2D& lhs, const Point2D& rhs);
bool coveredBy(const Point2D& lhs, const Point2D& rhs);
bool inside(const Point2D& lhs, const Point2D& rhs);
bool touch(const Point2D& lhs, const Point2D& rhs);

// Topological cluster predicates for a Point2D object and a Line2D object
bool overlap(const Point2D& lhs, const Line2D& rhs);
bool disjoint(const Point2D& lhs, const Line2D& rhs);
bool meet(const Point2D& lhs, const Line2D& rhs);
bool equal(const Point2D& lhs, const Line2D& rhs);
bool contains(const Point2D& lhs, const Line2D& rhs);
bool covers(const Point2D& lhs, const Line2D& rhs);
bool coveredBy(const Point2D& lhs, const Line2D& rhs);
bool inside(const Point2D& lhs, const Line2D& rhs);
bool touch(const Point2D& lhs, const Line2D& rhs);

// Topological cluster predicates for a Point2D object and a Region2D object
bool overlap(const Point2D& lhs, const Region2D& rhs);
bool disjoint(const Point2D& lhs, const Region2D& rhs);
bool meet(const Point2D& lhs, const Region2D& rhs);
bool equal(const Point2D& lhs, const Region2D& rhs);
bool contains(const Point2D& lhs, const Region2D& rhs);
bool covers(const Point2D& lhs, const Region2D& rhs);
bool coveredBy(const Point2D& lhs, const Region2D& rhs);
bool inside(const Point2D& lhs, const Region2D& rhs);
bool touch(const Point2D& lhs, const Region2D& rhs);

// Topological cluster predicates for two Line2D objects
bool overlap(const Line2D& lhs, const Line2D& rhs);
bool disjoint(const Line2D& lhs, const Line2D& rhs);
bool meet(const Line2D& lhs, const Line2D& rhs);
bool equal(const Line2D& lhs, const Line2D& rhs);
bool contains(const Line2D& lhs, const Line2D& rhs);
bool covers(const Line2D& lhs, const Line2D& rhs);
bool coveredBy(const Line2D& lhs, const Line2D& rhs);
bool inside(const Line2D& lhs, const Line2D& rhs);
bool touch(const Line2D& lhs, const Line2D& rhs);

// Topological cluster predicates for a Line2D object and a Region2D object
bool overlap(const Line2D& lhs, const Region2D& rhs);
bool disjoint(const Line2D& lhs, const Region2D& rhs);
bool meet(const Line2D& lhs, const Region2D& rhs);
bool equal(const Line2D& lhs, const Region2D& rhs);
bool contains(const Line2D& lhs, const Region2D& rhs);
bool covers(const Line2D& lhs, const Region2D& rhs);
bool coveredBy(const Line2D& lhs, const Region2D& rhs);
bool inside(const Line2D& lhs, const Region2D& rhs);
bool touch(const Line2D& lhs, const Region2D& rhs);

// Topological cluster predicates for two Region2D objects
bool overlap(const Region2D& lhs, const Region2D& rhs);
bool disjoint(const Region2D& lhs, const Region2D& rhs);
bool meet(const Region2D& lhs, const Region2D& rhs);
bool equal(const Region2D& lhs, const Region2D& rhs);
bool contains(const Region2D& lhs, const Region2D& rhs);
bool covers(const Region2D& lhs, const Region2D& rhs);
bool coveredBy(const Region2D& lhs, const Region2D& rhs);
bool inside(const Region2D& lhs, const Region2D& rhs);
bool touch(const Region2D& lhs, const Region2D& rhs);

#endif // TOPOLOGICALRELATIONSHIPS_H
