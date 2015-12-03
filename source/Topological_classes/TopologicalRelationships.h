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
* Authors: Group 4 [(GROUP MEMBERS)]
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
#include "Region2D.h"

// Enum class defining names for the numbers of topological predicates
// between two Point2D objects
enum class TopPredNumberPoint2DPoint2D
{
  pp_disjoint_m1, pp_equal_m2, pp_inside_m3, pp_contains_m4, pp_overlap_m5
};

// Enum class defining names for the numbers of topological predicates
// between a Point2D object and a Line2D object
enum class TopPredNumberPoint2DLine2D
{
  pl_disjoint_m1, pl_disjoint_m2, pl_meet_m3, pl_meet_m4, pl_meet_m5,
  pl_meet_m6, pl_inside_m7, pl_inside_m8, pl_overlap_m9, pl_overlap_m10,
  pl_inside_m11, pl_inside_m12, pl_overlap_m13, pl_overlap_m14
};

// Enum class defining names for the numbers of topological predicates
// between a Point2D object and a Region2D object
enum class TopPredNumberPoint2DRegion2D
{
  pr_disjoint_m1, pr_meet_m2, pr_meet_m3, pr_inside_m4, pr_overlap_m5,
  pr_inside_m6, pr_overlap_m7
};

// Enum class defining names for the numbers of topological predicates
// between two Line2D objects
enum class TopPredNumberLine2DLine2D
{
  ll_disjoint_m1, ll_disjoint_m2, ll_disjoint_m3, ll_disjoint_m4, ll_meet_m5,
  ll_meet_m6, ll_meet_m7, ll_meet_m8, ll_meet_m9, ll_meet_m10, ll_meet_m11,
  ll_meet_m12, ll_meet_m13, ll_meet_m14, ll_meet_m15, ll_meet_m16, ll_meet_m17,
  ll_meet_m18, ll_meet_m19, ll_meet_m20, ll_meet_m21, ll_meet_m22, ll_meet_m23,
  ll_meet_m24, ll_meet_m25, ll_meet_m26, ll_meet_m27, ll_meet_m28, ll_meet_m29,
  ll_meet_m30, ll_meet_m31, ll_meet_m32, ll_equal_m33, ll_inside_m34,
  ll_inside_m35, ll_equal_m36, ll_coveredby_m37, ll_coveredby_m38,
  ll_inside_m39, ll_inside_m40, ll_coveredby_m41, ll_coveredby_m42,
  ll_contains_m43, ll_overlap_m44, ll_overlap_m45, ll_contains_m46,
  ll_overlap_m47, ll_overlap_m48, ll_covers_m49, ll_overlap_m50,
  ll_overlap_m51, ll_covers_m52, ll_overlap_m53, ll_overlap_m54,
  ll_overlap_m55, ll_overlap_m56, ll_overlap_m57, ll_overlap_m58,
  ll_overlap_m59, ll_overlap_m60, ll_overlap_m61, ll_overlap_m62,
  ll_contains_m63, ll_overlap_m64, ll_overlap_m65, ll_contains_m66,
  ll_overlap_m67, ll_overlap_m68, ll_covers_m69, ll_overlap_m70,
  ll_overlap_m71, ll_covers_m72, ll_overlap_m73, ll_overlap_m74,
  ll_overlap_m75, ll_overlap_m76, ll_overlap_m77, ll_overlap_m78,
  ll_overlap_m79, ll_overlap_m80, ll_overlap_m81, ll_overlap_m82
};

// Enum class defining names for the numbers of topological predicates
// between a Line2D object and a Region2D object
enum class TopPredNumberLine2DRegion2D
{
  lr_disjoint_m1, lr_disjoint_m2, lr_meet_m3, lr_meet_m4, lr_meet_m5,
  lr_meet_m6, lr_meet_m7, lr_meet_m8, lr_meet_m9, lr_meet_m10, lr_meet_m11,
  lr_meet_m12, lr_meet_m13, lr_inside_m14, lr_coveredby_m15, lr_inside_m16,
  lr_coveredby_m17, lr_overlap_m18, lr_overlap_m19, lr_overlap_m20,
  lr_overlap_m21, lr_overlap_m22, lr_overlap_m23, lr_overlap_m24,
  lr_overlap_m25, lr_inside_m26, lr_inside_m27, lr_coveredby_m28,
  lr_inside_m29, lr_inside_m30, lr_coveredby_m31, lr_overlap_m32,
  lr_overlap_m33, lr_overlap_m34, lr_overlap_m35, lr_overlap_m36,
  lr_overlap_m37, lr_overlap_m38, lr_overlap_m39, lr_overlap_m40,
  lr_overlap_m41, lr_overlap_m42, lr_overlap_m43
};

// Enum class defining names for the numbers of topological predicates
// between two Region2D objects
enum class TopPredNumberRegion2DRegion2D
{
  rr_disjoint_m1, rr_meet_m2, rr_meet_m3, rr_meet_m4, rr_equal_m5,
  rr_coveredby_m6, rr_inside_m7, rr_coveredby_m8, rr_coveredby_m9,
  rr_overlap_m10, rr_covers_m11, rr_overlap_m12, rr_overlap_m13,
  rr_overlap_m14, rr_overlap_m15, rr_overlap_m16, rr_overlap_m17,
  rr_overlap_m18, rr_contains_m19, rr_overlap_m20, rr_covers_m21,
  rr_overlap_m22, rr_overlap_m23, rr_covers_m24, rr_overlap_m25,
  rr_overlap_m26, rr_overlap_m27, rr_overlap_m28, rr_overlap_m29,
  rr_overlap_m30, rr_overlap_m31, rr_overlap_m32, rr_overlap_m33
};

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

// Topological cluster predicates for a Point2D object and a Line2D object
bool overlap(const Point2D& lhs, const Line2D& rhs);
bool disjoint(const Point2D& lhs, const Line2D& rhs);
bool meet(const Point2D& lhs, const Line2D& rhs);
bool equal(const Point2D& lhs, const Line2D& rhs);
bool contains(const Point2D& lhs, const Line2D& rhs);
bool covers(const Point2D& lhs, const Line2D& rhs);
bool coveredBy(const Point2D& lhs, const Line2D& rhs);
bool inside(const Point2D& lhs, const Line2D& rhs);

// Topological cluster predicates for a Point2D object and a Region2D object
bool overlap(const Point2D& lhs, const Region2D& rhs);
bool disjoint(const Point2D& lhs, const Region2D& rhs);
bool meet(const Point2D& lhs, const Region2D& rhs);
bool equal(const Point2D& lhs, const Region2D& rhs);
bool contains(const Point2D& lhs, const Region2D& rhs);
bool covers(const Point2D& lhs, const Region2D& rhs);
bool coveredBy(const Point2D& lhs, const Region2D& rhs);
bool inside(const Point2D& lhs, const Region2D& rhs);

// Topological cluster predicates for two Line2D objects
bool overlap(const Line2D& lhs, const Line2D& rhs);
bool disjoint(const Line2D& lhs, const Line2D& rhs);
bool meet(const Line2D& lhs, const Line2D& rhs);
bool equal(const Line2D& lhs, const Line2D& rhs);
bool contains(const Line2D& lhs, const Line2D& rhs);
bool covers(const Line2D& lhs, const Line2D& rhs);
bool coveredBy(const Line2D& lhs, const Line2D& rhs);
bool inside(const Line2D& lhs, const Line2D& rhs);

// Topological cluster predicates for a Line2D object and a Region2D object
bool overlap(const Line2D& lhs, const Region2D& rhs);
bool disjoint(const Line2D& lhs, const Region2D& rhs);
bool meet(const Line2D& lhs, const Region2D& rhs);
bool equal(const Line2D& lhs, const Region2D& rhs);
bool contains(const Line2D& lhs, const Region2D& rhs);
bool covers(const Line2D& lhs, const Region2D& rhs);
bool coveredBy(const Line2D& lhs, const Region2D& rhs);
bool inside(const Line2D& lhs, const Region2D& rhs);

// Topological cluster predicates for two Region2D objects
bool overlap(const Region2D& lhs, const Region2D& rhs);
bool disjoint(const Region2D& lhs, const Region2D& rhs);
bool meet(const Region2D& lhs, const Region2D& rhs);
bool equal(const Region2D& lhs, const Region2D& rhs);
bool contains(const Region2D& lhs, const Region2D& rhs);
bool covers(const Region2D& lhs, const Region2D& rhs);
bool coveredBy(const Region2D& lhs, const Region2D& rhs);
bool inside(const Region2D& lhs, const Region2D& rhs);

#endif // TOPOLOGICALRELATIONSHIPS_H
