/******************************************************************************
* File: PlaneSweep.h
*******************************************************************************
* Purpose: Interface to the class for Plane Sweep
*
* Description: Plane sweep scans a given configuration of two spatial objects, detects
* all topological events (like intersections), and records them in data structures.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*          Group 4 (Aswini Ramesh, Djundi Tjindra, Kyuseo Park, Michael Kemerer, Natasha Mandal)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef PLANESWEEP_PROJECT_PLANESWEEP_H
#define PLANESWEEP_PROJECT_PLANESWEEP_H


#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic1/RobustGeometricPrimitives2D.h"
#include "Topic1/Number.h"
#include "Topic2/Implementation/Region2D.h"

#include "Object2D.h"
#include "ParallelObjectTraversal.h"
#include "AVLTree.h"
#include "PlaneSweepLineStatusObject.h"
#include "MinHeap.h"

class PlaneSweep {


public:

    // Constructor with two Object2D parameters
    PlaneSweep(const Object2D &, const Object2D &);

    // Destructor
    ~PlaneSweep();

    // Getter method for the POT object
    ParallelObjectTraversal *getPot() const {
        return pot;
    }

    /*
     * Should select the next point to stop at for the sweepLineStatus.
     * Should call the findLeast function within it to check whether to
     * increment the static EPS (objects themselves) or the dynamic EPS
     * (the min-heaps for the objects).
	 * for any intersection point between 2 attrib half-segments,
	 * there are two dynamic attrib half segments associated with each of 
	 * two region objects. Even though the cardinal coordinates are same, 
	 * it takes 4 iterations of selectNext to move ahead from the intersection
	 * point, as each attrib half seg is distinct.
     */
    void selectNext();

    // Return the values of the object or status variables from the ParallelObjectTraversal Class
    ParallelObjectTraversal::object getObject();
    ParallelObjectTraversal::status getStatus();

    // Setter methods for object and status variables
    void setObject(ParallelObjectTraversal::object);
    void setStatus(ParallelObjectTraversal::status);

    /*
     * This method creates a new sweep line status object, an AVL tree that
     * maintains the state of the intersection of the sweep line with
     * the geometric structure being swept at the current sweep line position.
     */
    void newSweep();

    /*
     * getEvent() functions would return the Poi, HalfSeg or AttrHalfSeg events
     * from either of the two objects based on the 'object' variable's value.
     * If object=first (second), it would return the next event in the first
     * (second) object.
     */
    Poi2D getPoiEvent(ParallelObjectTraversal::object objectValue);
    HalfSeg2D getHalfSegEvent(ParallelObjectTraversal::object objectValue);
    AttrHalfSeg2D getAttrHalfSegEvent(ParallelObjectTraversal::object objectValue);

    /*
     * The addLeft function would enter a new segment into the sweepLineStatus
     * data structure.
     * It should call calculateIntersection() and calculateOverlap() within it.
     */
    void addLeft(PlaneSweepLineStatusObject &);

    // The delRight function would remove a segment from the sweepLineStatus
    // data structure.
    void delRight(PlaneSweepLineStatusObject &);

    // Getter methods for the insideAbove flag and the segment class of a Seg2D object.
    bool getInsideAbove(Seg2D seg);
    SegmentClass getSegClass(Seg2D seg);

    // Setter methods for the insideAbove flag and the segment class of a Seg2D object.
    void setInsideAbove(Seg2D seg, bool ia);
    void setSegClass(Seg2D seg, int lOrR, int uOrL);

    // Method to check if the predecessor to a node in the sweep line status exists or not.
    bool predExists(Seg2D &);

    // Method to obtain the segment class for the predecessor to a node in SLS.
    SegmentClass getPredSegmentClass(Seg2D);

    // Method to obtain the insideAbove flag for the predecessor to a node in SLS.
    bool getPredInsideAbove(Seg2D);

    // This method searches the nearest segment below a given point in the sweep line status.
    Seg2D predOfP(Poi2D &);

    // This method tests whether the dominating points of a given halfsegment and the next
    // halfsegment after the logical pointer of a given halfsegment sequence are equal.
    bool lookAhead(HalfSeg2D &, ParallelObjectTraversal::object objectValue);
    bool lookAhead(AttrHalfSeg2D &, ParallelObjectTraversal::object objectValue);

    bool coincident(Seg2D &);

    bool currentExists(Poi2D &); // Adding Poi2D to make our life easier

    bool poiOnSeg(Poi2D &);

    bool poiInSeg(Poi2D &);

private:
    // only one instance of ParallelObjectTraversal exist!
    ParallelObjectTraversal *pot;

    /* The state of the intersection of the sweep line with the geometric structure
     * being swept at the current sw eep line position is recorded in vertical order
     * in a data structure called sweep line status.
     */
    AVLTree<PlaneSweepLineStatusObject> *sweepLineStatus;

    /* A vertical sweep line traversing the plane from left to right stops at special
     * event points which are stored in a queue called event point schedule. The event
     * point schedule must allow one to insert new event points discovered during
     * processing; these are normally the initially unknown intersections of line segments.
     * Below are the DYNAMIC eventPointSchedules corresponding to each object.
     */
    MinHeap<AttrHalfSeg2D> dynamicEPSObjF;
    MinHeap<AttrHalfSeg2D> dynamicEPSObjG;

    Object2D objF, objG;
    const Object2D *objFpointer, *objGpointer;
    bool isFP, isGP, isFL, isGL, isFR, isGR;

    //To get types of objects
    bool isFPoint();
    bool isFLine();
    bool isFRegion();
    bool isGPoint();
    bool isGLine();
    bool isGRegion();

    /*
     *  This function would be called from within the selectNext() function.
     *  What this would do is find if the next least poi2D for the 
     *  PlaneSweepLineStatus to stop next, belongs to the static EPS of the 
	 *  dynamic EPS.
     *  If the next point is from the static Event Point schedule (EPS) (which
     *  is either of the two objects (objF/objG) ), we update the iterator of the
     *  corresponding object ( POT.selectNext() ) . If it is from the dynamic
     *  EPS of the min-heap, we update the current of that particular object's min-heap
     *  ( objFMinHeap.selectNext() / objGMinHeap.selectNext() )
     *  Why we need this is to obtain the next x-coordinate point to stop at for the
     *  PlaneSweepLineStatus.
     */
    int findLeast();


    /*
     *  This function which is called from within the calculateRelation functions,
     *  it would split the two passed segments into more segments based on the relation between them and
     *  call the functions updateSweepLineStatus and the insertIntoDynamicEPS().
     *  The insertIntoDynamicEPS() function is just the insert() function for the
     *  two different min-heaps for the objects under consideration.
     */
    void splitLines(Seg2D &firstSegment, Seg2D &secondSegment);

    /*
     * This function is called within the splitLines function and would update the
     * sweepLineStatus data structure with the new updated split segment.
     */
    void updateSweepLineStatus(Seg2D &segmentToBeReplaced, Seg2D &segmentToReplaceWith);


    /*
     * Functions for getting predecessor and getting successor
     */
    PlaneSweepLineStatusObject getPredecessor(PlaneSweepLineStatusObject &);

    PlaneSweepLineStatusObject getSuccessor(PlaneSweepLineStatusObject &);

    bool ifPredecessor(PlaneSweepLineStatusObject &);
    bool ifSuccessor(PlaneSweepLineStatusObject &);

    /*
     * Function for checking if a relation exists between two segments
     */
    bool isRelation(Seg2D &, Seg2D &);

    void updateSegmentClassWhileAddingSegment(PlaneSweepLineStatusObject &sweepLineStatusObject);

    void updateSegmentClassWhileRemovingSegment(PlaneSweepLineStatusObject &sweepLineStatusObject);
};


#endif //PLANESWEEP_PROJECT_PLANESWEEP_H
