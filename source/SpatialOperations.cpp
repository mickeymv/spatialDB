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

#include "planesweep-project/ParallelObjectTraversal.h"
#include "planesweep-project/PlaneSweep.h"

Point2D spatialIntersection(const Point2D &pointLhs, const Point2D &pointRhs) {
    Point2D emptyPointObject;
    if (pointLhs.isEmptyPoint2D() || pointRhs.isEmptyPoint2D()) {
        return emptyPointObject;
    }

    vector<Poi2D> intersectionPointsVector;
    ParallelObjectTraversal parallelObjectTraversal(pointLhs, pointRhs);
    //pot.selectFirst would be called implicitly in the pot constructor.
    while (parallelObjectTraversal.getObject() != ParallelObjectTraversal::none &&
           parallelObjectTraversal.getStatus() == ParallelObjectTraversal::end_of_none &&
           parallelObjectTraversal.getStatus() != ParallelObjectTraversal::end_of_first &&
           parallelObjectTraversal.getStatus() != ParallelObjectTraversal::end_of_second) {
        if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::both) {
            intersectionPointsVector.push_back(parallelObjectTraversal.getPoiEvent(ParallelObjectTraversal::first));
            //The argument could be ParallelObjectTraversal::second as well since they're the same.
        }
        parallelObjectTraversal.selectNext();
    }

    Point2D intersectionPoint(intersectionPointsVector);
    return intersectionPoint;
}

Point2D spatialUnion(const Point2D &pointLhs, const Point2D &pointRhs) {
    Point2D emptyPointObject;
    if (pointLhs.isEmptyPoint2D() && pointRhs.isEmptyPoint2D()) {
        return emptyPointObject;
    } else if (pointLhs.isEmptyPoint2D()) {
        return pointRhs;
    } else if (pointRhs.isEmptyPoint2D()) {
        return pointLhs;
    }

    vector<Poi2D> unionPointsVector;
    ParallelObjectTraversal parallelObjectTraversal(pointLhs, pointRhs);
    //pot.selectFirst would be called implicitly in the pot constructor.
    while (parallelObjectTraversal.getObject() != ParallelObjectTraversal::none &&
           parallelObjectTraversal.getStatus() != ParallelObjectTraversal::end_of_both) {
        if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::both) {
            unionPointsVector.push_back(parallelObjectTraversal.getPoiEvent(ParallelObjectTraversal::first));
            //The argument could be ParallelObjectTraversal::second as well since they're the same.
        } else if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::first) {
            unionPointsVector.push_back(parallelObjectTraversal.getPoiEvent(ParallelObjectTraversal::first));
        } else if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::second) {
            unionPointsVector.push_back(parallelObjectTraversal.getPoiEvent(ParallelObjectTraversal::second));
        }
        parallelObjectTraversal.selectNext();
    }


    Point2D unionPoint(unionPointsVector);
    return unionPoint;
}

Point2D spatialDifference(const Point2D &pointLhs, const Point2D &pointRhs) {
    Point2D emptyPointObject;
    if (pointLhs.isEmptyPoint2D()) {
        return emptyPointObject;
    } else if (pointRhs.isEmptyPoint2D()) {
        return pointLhs;
    }

    vector<Poi2D> differencePointsVector;
    ParallelObjectTraversal parallelObjectTraversal(pointLhs, pointRhs);
    //pot.selectFirst would be called implicitly in the pot constructor.
    while (parallelObjectTraversal.getObject() != ParallelObjectTraversal::none &&
           parallelObjectTraversal.getStatus() == ParallelObjectTraversal::end_of_none &&
           parallelObjectTraversal.getStatus() != ParallelObjectTraversal::end_of_first) {
        if (parallelObjectTraversal.getObject() == ParallelObjectTraversal::first) {
            differencePointsVector.push_back(parallelObjectTraversal.getPoiEvent(ParallelObjectTraversal::first));
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


/*
 * As a helper function for the Line operations, we have the updateSweepLineForLine()
 * function. This function would update the sweepLineStatus data structure (AVL tree)
 * (add left half-segments to the sweepLine when encountered and remove right-half
 * segments from the sweepLine when encountered).
 */

void updateSweepLineForLine(PlaneSweep &planeSweep);

void printLineDetails(Line2D line) {
    cout << "The Line object is: " << line;
    if (line.isEmptyLine2D())
        cout << "Line structure is empty!" << endl;
    else
        cout << "Line structure is non-empty!" << endl;
    cout << "Line's number of segments is " << line.getNumberOfSegments() << endl;
}

Line2D spatialIntersection(const Line2D &lineLhs, const Line2D &lineRhs) {
    Line2D emptyLineObject;
    if (lineLhs.isEmptyLine2D() || lineRhs.isEmptyLine2D()) {
        printLineDetails(emptyLineObject);
        return emptyLineObject;
    }

    vector<Seg2D> intersectionLinesVector;
    PlaneSweep planeSweep(lineLhs, lineRhs);

    //To decide whether the segment's previous point belonged to the intersection.
    ParallelObjectTraversal::object previousObjectHistory = planeSweep.getObject();

    //planesweep.selectFirst would be called implicitly in the planesweep constructor.
    while (planeSweep.getObject() != ParallelObjectTraversal::none &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_both &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_first &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_second) {
        updateSweepLineForLine(planeSweep);
        /*
         * Start of intersection implementation.
         */
        if (planeSweep.getObject() == ParallelObjectTraversal::both &&
            previousObjectHistory == ParallelObjectTraversal::both) {
            HalfSeg2D firstHalfSeg2D = planeSweep.getHalfSegEvent(ParallelObjectTraversal::first);
            HalfSeg2D secondHalfSeg2D = planeSweep.getHalfSegEvent(ParallelObjectTraversal::second);
            if (firstHalfSeg2D.isLeft == secondHalfSeg2D.isLeft) {
                /*  Only if the left and right end points of the segments
                 * match should it be added to the intersection.
                */
                Seg2D seg2D = firstHalfSeg2D.seg;
                if (find(intersectionLinesVector.begin(), intersectionLinesVector.end(), seg2D) ==
                    intersectionLinesVector.end()) {
                    //If the segment is not already in the intersection, add it.
                    intersectionLinesVector.push_back(seg2D);
                }
                //The argument could be ParallelObjectTraversal::second as well since they're the same.
                previousObjectHistory = ParallelObjectTraversal::both;

            } else {
                previousObjectHistory = ParallelObjectTraversal::none;
            }
        } else if (planeSweep.getObject() == ParallelObjectTraversal::both) {
            //update previous event's object with this event
            HalfSeg2D firstHalfSeg2D = planeSweep.getHalfSegEvent(ParallelObjectTraversal::first);
            HalfSeg2D secondHalfSeg2D = planeSweep.getHalfSegEvent(ParallelObjectTraversal::second);
            if (firstHalfSeg2D.isLeft == secondHalfSeg2D.isLeft) {
                previousObjectHistory = ParallelObjectTraversal::both;
            }
        } else if (planeSweep.getObject() != ParallelObjectTraversal::both) {
            previousObjectHistory = ParallelObjectTraversal::none;
        }
        planeSweep.selectNext();
    }

    Line2D intersectionLineObject(intersectionLinesVector);
    printLineDetails(intersectionLineObject);
    return intersectionLineObject;
}

Line2D spatialUnion(const Line2D &lineLhs, const Line2D &lineRhs) {
    Line2D emptyLineObject;
    if (lineLhs.isEmptyLine2D() && lineRhs.isEmptyLine2D()) {
        printLineDetails(emptyLineObject);
        return emptyLineObject;
    } else if (lineLhs.isEmptyLine2D()) {
        printLineDetails(lineRhs);
        return lineRhs;
    } else if (lineRhs.isEmptyLine2D()) {
        printLineDetails(lineLhs);
        return lineLhs;
    }

    vector<Seg2D> unionLinesVector;
    PlaneSweep planeSweep(lineLhs, lineRhs);

    //planesweep.selectFirst would be called implicitly in the planesweep constructor.
    while (planeSweep.getObject() != ParallelObjectTraversal::none &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_both) {
        updateSweepLineForLine(planeSweep);
        ParallelObjectTraversal::object objectValue = planeSweep.getObject();
        if (objectValue == ParallelObjectTraversal::both) {
            objectValue = ParallelObjectTraversal::first;
        }
        HalfSeg2D halfSeg2D = planeSweep.getHalfSegEvent(objectValue);
        if (halfSeg2D.isLeft == false) {
            Seg2D seg2D = halfSeg2D.seg;
            if (find(unionLinesVector.begin(), unionLinesVector.end(), seg2D) ==
                    unionLinesVector.end()) {
                //If the segment is not already in the union, add it.
                unionLinesVector.push_back(seg2D);
            }
        }

        planeSweep.selectNext();
    }

    Line2D unionLineObject(unionLinesVector);
    printLineDetails(unionLineObject);
    return unionLineObject;
}

Line2D spatialDifference(const Line2D &lineLhs, const Line2D &lineRhs) {
    Line2D emptyLineObject;
    if (lineLhs.isEmptyLine2D()) {
        printLineDetails(emptyLineObject);
        return emptyLineObject;
    } else if (lineRhs.isEmptyLine2D()) {
        printLineDetails(lineLhs);
        return lineLhs;
    }

    vector<Seg2D> differenceLinesVector;
    PlaneSweep planeSweep(lineLhs, lineRhs);

    //To decide whether the segment's previous point belonged to the intersection.
    ParallelObjectTraversal::object previousObjectHistory = planeSweep.getObject();

    //planesweep.selectFirst would be called implicitly in the planesweep constructor.
    while (planeSweep.getObject() != ParallelObjectTraversal::none &&
           planeSweep.getStatus() == ParallelObjectTraversal::end_of_none &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_first) {
        updateSweepLineForLine(planeSweep);
        if (
                ((planeSweep.getObject() == ParallelObjectTraversal::first ||
                  planeSweep.getObject() == ParallelObjectTraversal::both) &&
                 previousObjectHistory == ParallelObjectTraversal::first)
                ||
                (planeSweep.getObject() == ParallelObjectTraversal::first &&
                 (previousObjectHistory == ParallelObjectTraversal::first ||
                  previousObjectHistory == ParallelObjectTraversal::both))
                ) {
            HalfSeg2D halfSeg2D = planeSweep.getHalfSegEvent(ParallelObjectTraversal::first);
            Seg2D seg2D = halfSeg2D.seg;
            if (find(differenceLinesVector.begin(), differenceLinesVector.end(), seg2D) ==
                    differenceLinesVector.end()) {
                //If the segment is not already in the union, add it.
                differenceLinesVector.push_back(seg2D);
            }
//The argument could be ParallelObjectTraversal::second as well since they're the same.
        } else if (planeSweep.getObject() == ParallelObjectTraversal::first ||
                   planeSweep.getObject() == ParallelObjectTraversal::both) {
//update previous event's object with this event
            previousObjectHistory = planeSweep.getObject();

        } else if (planeSweep.getObject() != ParallelObjectTraversal::second ||
                   planeSweep.getObject() != ParallelObjectTraversal::none) {
            previousObjectHistory = ParallelObjectTraversal::none;
        }
        planeSweep.selectNext();
    }

    Line2D differenceLineObject(differenceLinesVector);
    printLineDetails(differenceLineObject);
    return differenceLineObject;
}


void updateSweepLineForLine(PlaneSweep &planeSweep) {
    /*
         * Start of adding/removing segments from the sweepLine
         */
    Seg2D segmentForSweepLine;
    HalfSeg2D halfsegment;
    PlaneSweepLineStatusObject sweepLineStatusObject;
    if (planeSweep.getObject() == ParallelObjectTraversal::both) {

        //when object==both, which line object is this halfSeg from?
        /*
         * is it from the first line2D object or the second?
         * why this is important is because when we add a segment to the
         * sweepLine, we need to tell which object it belongs to.
         * We can't add the segment saying 'both' since both only implies the
         * dominating point is the same, not the other x/y coordinate in the segment.
         */
        HalfSeg2D halfsegmentFirst = planeSweep.getHalfSegEvent(ParallelObjectTraversal::first);
        HalfSeg2D halfsegmentSecond = planeSweep.getHalfSegEvent(ParallelObjectTraversal::second);
        if (halfsegmentFirst < halfsegmentSecond) {
            halfsegment = halfsegmentFirst;
            sweepLineStatusObject.setObject(ParallelObjectTraversal::first);
        } else if (halfsegmentFirst > halfsegmentSecond) {
            halfsegment = halfsegmentSecond;
            sweepLineStatusObject.setObject(ParallelObjectTraversal::second);
        }
    } else if (planeSweep.getObject() == ParallelObjectTraversal::first) {
        halfsegment = planeSweep.getHalfSegEvent(ParallelObjectTraversal::first);
        sweepLineStatusObject.setObject(ParallelObjectTraversal::first);
    } else if (planeSweep.getObject() == ParallelObjectTraversal::second) {
        halfsegment = planeSweep.getHalfSegEvent(ParallelObjectTraversal::second);
        sweepLineStatusObject.setObject(ParallelObjectTraversal::second);
    }
    segmentForSweepLine = halfsegment.seg;
    sweepLineStatusObject.setSegment2D(segmentForSweepLine);
    if (halfsegment.isLeft) { //add left half-segments to sweepline
        planeSweep.addLeft(sweepLineStatusObject);
    } else if (!halfsegment.isLeft) { //remove right half-segments from sweepline
        planeSweep.delRight(sweepLineStatusObject);
    }
    /*
     * End of adding/removing segments from the sweepLine
     */

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

void updateSweepLineForRegion(PlaneSweep &planeSweep);

Region2D spatialIntersection(const Region2D &regionLhs,
                             const Region2D &regionRhs) {
    //Region2D region;
    Region2D emptyRegionObject;
    if (regionLhs.isEmptyRegion2D() || regionRhs.isEmptyRegion2D()) {
        return emptyRegionObject;
    }

    vector<Seg2D> intersectionRegionVector;
    PlaneSweep planeSweep(regionLhs, regionRhs);

    while (planeSweep.getObject() != ParallelObjectTraversal::none &&
           planeSweep.getStatus() == ParallelObjectTraversal::end_of_none &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_first &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_second) {
        updateSweepLineForRegion(planeSweep);
        AttrHalfSeg2D attHsegCurr;
        int lorCurr = 0, uolCurr = 0;

        if (planeSweep.getObject() == ParallelObjectTraversal::first) {
            attHsegCurr = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::first);
        } else if (planeSweep.getObject() == ParallelObjectTraversal::second) {
            attHsegCurr = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::second);
        }

        lorCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getLowerOrRight();
        uolCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getUpperOrLeft();
        /*
         * the intersection region object adds the segments with segClass values
         * not having 2 in either lor or uol
         */

        if (lorCurr == 2 || uolCurr == 2) {
            intersectionRegionVector.push_back(attHsegCurr.hseg.seg);
        }

        planeSweep.selectNext();
    }

    Region2D intersectionRegionObject(intersectionRegionVector);
    return intersectionRegionObject;
}

Region2D spatialUnion(const Region2D &regionLhs, const Region2D &regionRhs) {
    Region2D emptyRegionObject;
    if (regionLhs.isEmptyRegion2D() && regionRhs.isEmptyRegion2D()) {
        return emptyRegionObject;
    } else if (regionLhs.isEmptyRegion2D()) {
        return Region2D(regionRhs);
    } else if (regionRhs.isEmptyRegion2D()) {
        return Region2D(regionLhs);
    }

    vector<Seg2D> unionRegionVector;
    PlaneSweep planeSweep(regionLhs, regionRhs);

    while (planeSweep.getObject() != ParallelObjectTraversal::none &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_both) {
        updateSweepLineForRegion(planeSweep);
        AttrHalfSeg2D attHsegCurr;
        int lorCurr = 0, uolCurr = 0;

        if (planeSweep.getObject() == ParallelObjectTraversal::first) {
            attHsegCurr = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::first);
        } else if (planeSweep.getObject() == ParallelObjectTraversal::second) {
            attHsegCurr = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::second);
        }

        lorCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getLowerOrRight();
        uolCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getUpperOrLeft();
        /*
         * the union region object adds the segments with segClass values 1/0, 0/1,
         * 2/0 and 0/2
         * Not 2/1 or 1/2
         */

        if (lorCurr == 2 || uolCurr == 2) {
            planeSweep.selectNext();
            continue;
        }
        unionRegionVector.push_back(attHsegCurr.hseg.seg);
        planeSweep.selectNext();
    }

    Region2D unionRegionObject(unionRegionVector);
    return unionRegionObject;
}

Region2D spatialDifference(const Region2D &regionLhs,
                           const Region2D &regionRhs) {
    Region2D emptyRegionObject;
    if (regionLhs.isEmptyRegion2D()) {
        return emptyRegionObject;
    } else if (regionRhs.isEmptyRegion2D()) {
        return Region2D(regionLhs);
    }

    vector<Seg2D> diffRegionVector;
    PlaneSweep planeSweep(regionLhs, regionRhs);

    while (planeSweep.getObject() != ParallelObjectTraversal::none &&
           planeSweep.getStatus() == ParallelObjectTraversal::end_of_none &&
           planeSweep.getStatus() != ParallelObjectTraversal::end_of_first) {
        updateSweepLineForRegion(planeSweep);
        AttrHalfSeg2D attHsegCurr;
        int lorCurr = 0, uolCurr = 0;
        /*
         * the diff region object adds the segments with segClass values
         * 1/0, 0/1 : if it belongs to the first region object
         * 2/1, 1/2 : if it belongs to the second region object
         */

        if (planeSweep.getObject() == ParallelObjectTraversal::first) {
            attHsegCurr = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::first);
            lorCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getLowerOrRight();
            uolCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getUpperOrLeft();
            if ((lorCurr == 0 && uolCurr == 1) || (lorCurr == 1 && uolCurr == 0))
                diffRegionVector.push_back(attHsegCurr.hseg.seg);

        } else if (planeSweep.getObject() == ParallelObjectTraversal::second) {
            attHsegCurr = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            lorCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getLowerOrRight();
            uolCurr = planeSweep.getSegClass(attHsegCurr.hseg.seg).getUpperOrLeft();
            if ((lorCurr == 2 && uolCurr == 1) || (lorCurr == 1 && uolCurr == 2))
                diffRegionVector.push_back(attHsegCurr.hseg.seg);
        }
        planeSweep.selectNext();
    }

    Region2D diffRegionObject(diffRegionVector);
    return diffRegionObject;
}

/*
 * As a helper function for the Region operations, we have the updateSweepLineForLine()
 * function. This function would update the sweepLineStatus data structure (AVL tree)
 * (add left half-segments to the sweepLine when encountered and remove right-half
 * segments from the sweepLine when encountered).
 */

void updateSweepLineForRegion(PlaneSweep &planeSweep) {
    /*
         * Start of adding/removing segments from the sweepLine
         */
    Seg2D segmentForSweepLine;
    AttrHalfSeg2D attrHalfSeg2D;
    PlaneSweepLineStatusObject sweepLineStatusObject;
    if (planeSweep.getObject() == ParallelObjectTraversal::both) {

        //when object==both, which line object is this halfSeg from?
        /*
         * is it from the first line2D object or the second?
         * why this is important is because when we add a segment to the
         * sweepLine, we need to tell which object it belongs to.
         * We can't add the segment saying 'both' since both only implies the
         * dominating point is the same, not the other x/y coordinate in the segment.
         */
        AttrHalfSeg2D attrHalfSegmentFirst = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::first);
        AttrHalfSeg2D attrHalfSegmentSecond = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::second);
        if (attrHalfSegmentFirst < attrHalfSegmentSecond) {
            attrHalfSeg2D = attrHalfSegmentFirst;
            sweepLineStatusObject.setObject(ParallelObjectTraversal::first);
        } else if (attrHalfSegmentFirst > attrHalfSegmentSecond) {
            attrHalfSeg2D = attrHalfSegmentSecond;
            sweepLineStatusObject.setObject(ParallelObjectTraversal::second);
        }
    } else if (planeSweep.getObject() == ParallelObjectTraversal::first) {
        attrHalfSeg2D = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::first);
        sweepLineStatusObject.setObject(ParallelObjectTraversal::first);
    } else if (planeSweep.getObject() == ParallelObjectTraversal::second) {
        attrHalfSeg2D = planeSweep.getAttrHalfSegEvent(ParallelObjectTraversal::second);
        sweepLineStatusObject.setObject(ParallelObjectTraversal::second);
    }
    segmentForSweepLine = attrHalfSeg2D.hseg.seg;
    sweepLineStatusObject.setSegment2D(segmentForSweepLine);
    if (attrHalfSeg2D.hseg.isLeft) { //add left half-segments to sweepline
        planeSweep.addLeft(sweepLineStatusObject);
    } else if (!attrHalfSeg2D.hseg.isLeft) { //remove right half-segments from sweepline
        planeSweep.delRight(sweepLineStatusObject);
    }
    /*
     * End of adding/removing segments from the sweepLine
     */

}
