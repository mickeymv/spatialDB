/******************************************************************************
* File: SpatialOperations.cpp
*******************************************************************************
* Purpose: Interface to the Spatial operations union, intersection, and
*   difference between two complex objects of the spatial data types Poi2D,
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
#include "SpatialOperations.h"

/******************************************************************************
* Spatial operations union, intersection, and difference applied to two
* Poi2D objects and yielding a Poi2D object.
*******************************************************************************
* The spatial intersection operation returns those single points in a Poi2D
* object that belong to both argument Poi2D objects. 
* The spatial union operation merges two Poi2D objects into a single Poi2D 
* object. Duplicate single points are eliminated. 
* The spatial difference operation subtracts any single point of the second 
* argument Poi2D object from the first argument Poi2D object.
*
* Parameters : const Poi2D& lhs and const Poi2D& rhs
* Returns    : Poi2D 
******************************************************************************/

#include "planesweep project/ParallelObjectTraversal.h"

Point2D spatialIntersection(const Point2D &pointLhs, const Point2D &pointRhs) {
    Point2D emptyPointObject;
    if (pointLhs == NULL || pointRhs == NULL || pointLhs.isEmptyPoint2D() || pointRhs.isEmptyPoint2D()) {
        //TODO: ask group2 to make isEmpty const.
        return emptyPointObject;
    }

    vector<Poi2D> intersectionPointsVector;
    ParallelObjectTraversal parallelObjectTraversal(pointLhs, pointRhs);
    //pot.selectFirst would be called implicitly in the pot constructor.
    while (parallelObjectTraversal.getObject() != ParallelObjectTraversal::none &&
           parallelObjectTraversal.getStatus() == ParallelObjectTraversal::end_of_none) {
        if (parallelObjectTraversal.getObject() != ParallelObjectTraversal::both) {
            intersectionPointsVector.push_back(parallelObjectTraversal.getEvent(ParallelObjectTraversal::first));
            //The argument could be ParallelObjectTraversal::second as well since they're the same.
        }
        parallelObjectTraversal.selectNext();
    }

    Point2D intersectionPoint(intersectionPointsVector);
    return intersectionPoint;
}

Point2D spatialUnion(const Point2D &pointLhs, const Point2D &pointRhs) {
    Point2D emptyPointObject;
    if (pointLhs == NULL && pointRhs == NULL || pointLhs.isEmptyPoint2D() && pointRhs.isEmptyPoint2D()) {
        //TODO: ask group2 to make isEmpty const.
        return emptyPointObject;
    }

    vector<Poi2D> unionPointsVector;
    ParallelObjectTraversal parallelObjectTraversal(pointLhs, pointRhs);
    //pot.selectFirst would be called implicitly in the pot constructor.
    while (parallelObjectTraversal.getObject() != ParallelObjectTraversal::none &&
           parallelObjectTraversal.getStatus() == ParallelObjectTraversal::end_of_none) {
        if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::both) {
            unionPointsVector.push_back(parallelObjectTraversal.getEvent(ParallelObjectTraversal::first));
            //The argument could be ParallelObjectTraversal::second as well since they're the same.
        } else if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::first) {
            unionPointsVector.push_back(parallelObjectTraversal.getEvent(ParallelObjectTraversal::first));
        } else if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::second) {
            unionPointsVector.push_back(parallelObjectTraversal.getEvent(ParallelObjectTraversal::second));
        }
        parallelObjectTraversal.selectNext();
    }


    Point2D unionPoint(unionPointsVector);
    return unionPoint;
}

Point2D spatialDifference(const Point2D &pointLhs, const Point2D &pointRhs) {
    Point2D emptyPointObject;
    if (pointLhs == NULL || pointLhs.isEmptyPoint2D()) {
        //TODO: ask group2 to make isEmpty const.
        return emptyPointObject;
    }

    vector<Poi2D> differencePointsVector;
    ParallelObjectTraversal parallelObjectTraversal(pointLhs, pointRhs);
    //pot.selectFirst would be called implicitly in the pot constructor.
    while (parallelObjectTraversal.getObject() != ParallelObjectTraversal::none &&
           parallelObjectTraversal.getStatus() == ParallelObjectTraversal::end_of_none) {
        if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::first) {
            differencePointsVector.push_back(parallelObjectTraversal.getEvent(ParallelObjectTraversal::first));
        }
        parallelObjectTraversal.selectNext();
    }


    Point2D differencePoint(differencePointsVector);
    return differencePoint;
}

/******************************************************************************
* Spatial operations union, intersection, and difference applied to two
* Line2D objects and yielding a Line2D object
*******************************************************************************
* The spatial intersection operation returns those lines in a Line2D object 
* that belong to both argument Line2D objects. 
* The spatial union operation merges two Line2D objects into a single Line2D 
* object which contains all lines from either of the argument Line2D objects. 
* The spatial difference operation subtracts any single line of the second 
* argument Line2D object from the first argument Line2D object.
*
* Parameters : const Line2D& lineLhs and const Line2D& lineRhs
* Returns    : Line2D
******************************************************************************/
Line2D spatialIntersection(const Line2D &lineLhs, const Line2D &lineRhs) {
    Line2D line;
    //implementation
    return line;
}

Line2D spatialUnion(const Line2D &lineLhs, const Line2D &lineRhs) {
    Line2D line;
    //implementation
    return line;
}

Line2D spatialDifference(const Line2D &lineLhs, const Line2D &lineRhs) {
    Line2D line;
    //implementation
    return line;
}

/******************************************************************************
* Spatial operations union, intersection, and difference applied to two
* Region2D objects and yielding a Region2D object
*******************************************************************************
* The spatial intersection operation returns those regions in a Region2D object 
* that belong to both argument Region2D objects. 
* The spatial union operation merges two Region2D objects into a single 
* Region2D object which contains all regions from either of the argument
* Region2D objects. 
* The spatial difference operation subtracts region of the second argument
* Region2D object from the first argument Region2D object.
*
* Parameters : const Region2D& regionLhs and const Region2D& regionRhs
* Returns    : Region2D
******************************************************************************/
Region2D spatialIntersection(const Region2D &regionLhs,
                             const Region2D &regionRhs) {
    Region2D region;
    //implementation
    return region;
}

Region2D spatialUnion(const Region2D &regionLhs, const Region2D &regionRhs) {
    Region2D region;
    //implementation
    return region;
}

Region2D spatialDifference(const Region2D &regionLhs,
                           const Region2D &regionRhs) {
    Region2D region;
    //implementation
    return region;
}
