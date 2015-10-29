/******************************************************************************
* File: SpatialOperations.h
*******************************************************************************
* Purpose: Interface to the geometric set operations union, intersection, and
*   difference between two complex objects of the spatial data types Point2D,
*   Line2D, or Region2D
* Description: Any of the geometric set operations takes two objects of the
*   same spatial data type as operands, computes their geometric union,
*   geometric intersection, or geometric difference, and returns an object of
*   the same spatial data type as a result. This means that the geometric set
*   operations satisfy closure properties.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel,
                    Sarath Francis)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef SPATIALOPERATIONS_h
#define SPATIALOPERATIONS_h

#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

/******************************************************************************
* Geometric set operations union, intersection, and difference applied to two
* Point2D objects and yielding a Point2D object
*******************************************************************************
* The spatial intersection operation returns those single points in a Point2D
* object that both argument Point2D objects have in common.
*
* The spatial intersection operation returns a Point2D object that is the
* topological intersection (AND operation) of two Point2D objects. 
* The spatial union operation returns a Point2D object that is the topological
* union (OR operation) of two Point2D objects.
* The spatial Difference operation returns a Point2D object that is the
* topological difference (MINUS operation) of two Point2D objects.
*
* Parameters : const Point2D& lhs and const Point2D& rhs
* Returns    : Point2D 
******************************************************************************/
Point2D spatialIntersection (const Point2D& pointLhs, const Point2D& pointRhs);
Point2D spatialUnion (const Point2D& pointLhs, const Point2D& pointRhs);
Point2D spatialDifference (const Point2D& pointLhs, const Point2D& pointRhs);

/******************************************************************************
* Geometric set operations union, intersection, and difference applied to two
* Line2D objects and yielding a Line2D object
*******************************************************************************
*
* The spatial intersection operation returns a Line2D object that is the
* topological intersection (AND operation) of two Line2D objects. 
* The spatial union operation returns a Line2D object that is the topological
* union (OR operation) of two Line2D objects.
* The spatial Difference operation returns a Line2D object that is the
* topological difference (MINUS operation) of two Line2D objects.
*
* Parameters : const Line2D& lineLhs and const Line2D& lineRhs
* Returns    : Line2D
******************************************************************************/
Line2D spatialIntersection (const Line2D& lineLhs, const Line2D& lineRhs);
Line2D spatialUnion (const Line2D& lineLhs, const Line2D& lineRhs);
Line2D spatialDifference (const Line2D& lineLhs, const Line2D& lineRhs);

/******************************************************************************
* Geometric set operations union, intersection, and difference applied to two
* Region2D objects and yielding a Region2D object
*******************************************************************************
*
* The spatial intersection operation returns a Region2D object that is the
* topological intersection (AND operation) of two Region2D objects. 
* The spatial union operation returns a Region2D object that is the topological
* union (OR operation) of two Region2D objects.
* The spatial Difference operation returns a Region2D object that is the
* topological difference (MINUS operation) of two Region2D objects.
*
* Parameters : const Region2D& regionLhs and const Region2D& regionRhs
* Returns    : Region2D
******************************************************************************/
Region2D spatialIntersection (const Region2D& regionLhs,
                              const Region2D& regionRhs);
Region2D spatialUnion (const Region2D& regionLhs, const Region2D& regionRhs);
Region2D spatialDifference (const Region2D& regionLhs,
                            const Region2D& regionRhs);

#endif // SPATIALOPERATIONS_H
