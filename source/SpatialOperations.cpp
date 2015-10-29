/******************************************************************************
* File: SpatialOperations.cpp
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
#include "SpatialOperations.h"

/******************************************************************************
* Geometric set operations union, intersection, and difference applied to two
* Point2D objects and yielding a Point2D object
*******************************************************************************
* The spatial intersection operation returns those single points in a Point2D
* object that both argument Point2D objects have in common. 
* The spatial union operation merges two Point2D objects into a single Point2D 
* object. Duplicate single points are eliminated. 
* The spatial difference operation subtracts any single point of the second 
* argument Point2D object from the first argument Point2D object.
*
* Parameters : const Point2D& lhs and const Point2D& rhs
* Returns    : Point2D 
******************************************************************************/

Point2D spatialIntersection(const Point2D& pointLhs, const Point2D& pointRhs) 
{
  Point2D point;
  //implementation
  return point;
}

Point2D spatialUnion(const Point2D& pointLhs, const Point2D& pointRhs) 
{
  Point2D point;
  //implementation
  return point;
}

Point2D spatialDifference(const Point2D& pointLhs, const Point2D& pointRhs) 
{
  Point2D point;
  //implementation
  return point;
}

/******************************************************************************
* Geometric set operations union, intersection, and difference applied to two
* Line2D objects and yielding a Line2D object
*******************************************************************************
* The spatial intersection operation returns those lines in a Line2D object 
* that both argument Line2D objects have in common. 
* The spatial union operation merges two Line2D objects into a single Line2D 
* object which contains all lines from either of the argument Line2D objects. 
* The spatial difference operation subtracts any single line of the second 
* argument Line2D object from the first argument Line2D object.
*
* Parameters : const Line2D& lineLhs and const Line2D& lineRhs
* Returns    : Line2D
******************************************************************************/
Line2D spatialIntersection(const Line2D& lineLhs, const Line2D& lineRhs) 
{
  Line2D line;
  //implementation
  return line;
}

Line2D spatialUnion(const Line2D& lineLhs, const Line2D& lineRhs) 
{
 Line2D line;
 //implementation
 return line;
}

Line2D spatialDifference(const Line2D& lineLhs, const Line2D& lineRhs) 
{
 Line2D line;
 //implementation
 return line;
}

/******************************************************************************
* Geometric set operations union, intersection, and difference applied to two
* Region2D objects and yielding a Region2D object
*******************************************************************************
* The spatial intersection operation returns those regions in a Region2D object 
* that both argument Region2D objects have in common. 
* The spatial union operation merges two Region2D objects into a single 
* Region2D object which contains all regions from either of the argument
* Region2D objects. 
* The spatial difference operation subtracts region of the second argument
* Region2D object from the first argument Region2D object.
*
* Parameters : const Region2D& regionLhs and const Region2D& regionRhs
* Returns    : Region2D
******************************************************************************/
Region2D spatialIntersection(const Region2D& regionLhs,
                             const Region2D& regionRhs)  
{
  Region2D region;
  //implementation
  return region;
}

Region2D spatialUnion(const Region2D& regionLhs, const Region2D& regionRhs) 
{
  Region2D region;
  //implementation
  return region;
}

Region2D spatialDifference(const Region2D& regionLhs,
                           const Region2D& regionRhs)
{
  Region2D region;
  //implementation
  return region;
}
