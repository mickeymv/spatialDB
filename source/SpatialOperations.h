/******************************************************************************
* File: SpatialOperations.h
*******************************************************************************
* Purpose: Interface to the Spatial operations union, intersection, and
*   difference between two complex objects of the spatial data types Point2D,
*   Line2D, or Region2D
* Description: Any of the Spatial operations takes two objects of the
*   same spatial data type as operands, computes their Spatial union,
*   Spatial intersection, or Spatial difference, and returns an object of
*   the same spatial data type as a result. This means that the Spatial
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

#include "planesweep project/Topic1/RobustGeometricPrimitives2D.h"
#include "planesweep project/Topic2/Implementation/Line2D.h"
#include "planesweep project/Topic2/Interfaces/Region2D.h"
#include "planesweep project/Topic2/Implementation/Point2D.h"

/******************************************************************************
* Spatial operations union, intersection, and difference applied to two
* Point2D objects and yielding a Point2D object
*******************************************************************************
* The spatial intersection operation returns those single points in a Point2D
* object that belong to both argument Point2D objects.
*
* The spatial intersection operation returns a Point2D object that is the
*  intersection  of two Point2D objects. 
* The spatial union operation returns a Point2D object that is the 
* union  of two Point2D objects.
* The spatial Difference operation returns a Point2D object that is the
*  difference  of two Point2D objects.
*
* Parameters : const Point2D& pointLhs and const Point2D& pointRhs
* Returns    : Point2D 
******************************************************************************/
Point2D spatialIntersection (const Point2D& pointLhs, const Point2D& pointRhs);
Point2D spatialUnion (const Point2D& pointLhs, const Point2D& pointRhs);
Point2D spatialDifference (const Point2D& pointLhs, const Point2D& pointRhs);

/******************************************************************************
* Spatial operations union, intersection, and difference applied to two
* Line2D objects and yielding a Line2D object
*******************************************************************************
*
* The spatial intersection operation returns a Line2D object that is the
*  intersection  of two Line2D objects. 
* The spatial union operation returns a Line2D object that is the 
* union  of two Line2D objects.
* The spatial Difference operation returns a Line2D object that is the
*  difference  of two Line2D objects.
*
* Parameters : const Line2D& lineLhs and const Line2D& lineRhs
* Returns    : Line2D
******************************************************************************/
Line2D spatialIntersection (const Line2D& lineLhs, const Line2D& lineRhs);
Line2D spatialUnion (const Line2D& lineLhs, const Line2D& lineRhs);
Line2D spatialDifference (const Line2D& lineLhs, const Line2D& lineRhs);

/******************************************************************************
* Spatial operations union, intersection, and difference applied to two
* Region2D objects and yielding a Region2D object
*******************************************************************************
*
* The spatial intersection operation returns a Region2D object that is the
*  intersection  of two Region2D objects. 
* The spatial union operation returns a Region2D object that is the 
* union  of two Region2D objects.
* The spatial Difference operation returns a Region2D object that is the
*  difference  of two Region2D objects.
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
