//
// Created by Djundi on 11/3/15.
//

#ifndef PLANESWEEP_PROJECT_PLANESWEEP_H
#define PLANESWEEP_PROJECT_PLANESWEEP_H


#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic1/RobustGeometricPrimitives2D.h"
#include "Topic2/Implementation/Number.h"
#include "Region2D.h"

#include "Object2D.h"
#include "ParallelObjectTraversal.h"
#include "AVLTree.h"
#include "Attribute.h"
#include "PlaneSweepLineStatusObject.h"
#include "MinHeap.h"


class PlaneSweep {


public:
    PlaneSweep(Object2D, Object2D);

    ~PlaneSweep();


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

    //Return the values of the object or status variables from the ParallelObjectTraversal Class
    ParallelObjectTraversal::object getObject();

    ParallelObjectTraversal::status getStatus();

    void newSweep();

    /*
     * getEvent() functions would return the Poi, HalfSeg or
     * AttrHalfSeg events from either of the two objects based on the
     * 'object' variable's value. If object=first (second), it would return the
     *  next event in the first (second) object.
     */
    Poi2D getPoiEvent(ParallelObjectTraversal::object objectValue);

    HalfSeg2D getHalfSegEvent(ParallelObjectTraversal::object objectValue);

    AttrHalfSeg2D getAttrHalfSegEvent(ParallelObjectTraversal::object objectValue);

    /*
     * The addLeft function would enter a new segment into the sweepLineStatus
     * data structure.
     * It should call calculateIntersection() and calculateOverlap() within it.
     */
    void addLeft(Seg2D &);

    void delRight(Seg2D &);

	bool getInsideAbove(Seg2D seg);
	SegmentClass getSegClass(Seg2D seg);
	void setInsideAbove(Seg2D seg, bool ia);
	void setSegClass(Seg2D seg, int lOrR, int uOrL);

    bool predExists(Seg2D &);

    SegmentClass getPredSegmentClass(Seg2D);
    bool getPredInsideAbove(Seg2D);

    Seg2D &predOfP(Poi2D &);

    bool lookAhead(HalfSeg2D &, Line2D &);

    //Look at region-region case for additional return type
    bool lookAhead(AttrHalfSeg2D &, Region2D &);//Look at region-region case for additional return type

    bool coincident(Seg2D &);

    bool currentExists(Poi2D &); // Adding Poi2D to make our life easier

    bool poiOnSeg(Poi2D &);

    bool poiInSeg(Poi2D &);

private:
    // only one instance of ParallelObjectTraversal exist!
    ParallelObjectTraversal *pot;

    /* The state of the intersection of the sweep line with the geometric structure
     * being swept at the current sweep line position is recorded in vertical order
     * in a data structure called sweep line status.
     */
    AVLTree<PlaneSweepLineStatusObject &> *sweepLineStatus;

    //Should increment the object pointers within either/both of the two objects.
    void selectFirst();

    /* A vertical sweep line traversing the plane from left to right stops at special
     * event points which are stored in a queue called event point schedule. The event
     * point schedule must allow one to insert new event points discovered during
     * processing; these are normally the initially unknown intersections of line segments.
     * Below are the DYNAMIC eventPointSchedules corresponding to each object.
     */
    MinHeap dynamicEPSObjF;
    MinHeap dynamicEPSObjG;


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
     *  Checks whether a Seg2D has intersections with any of the predecessor and successor already
     *  in the sweepLineStatus. If it does, it calls the functions
     *  splitLines().
     */
    bool calculateRelation(Seg2D&);


    /*
     *  This function which is called from within the calculateRelation functions,
     *  it would split the two passed segments into more segments based on the relation between them and
     *  call the functions updateSweepLineStatus and the insertIntoDynamicEPS().
     *  The insertIntoDynamicEPS() function is just the insert() function for the
     *  two different min-heaps for the objects under consideration.
     */
    void splitLines(Seg2D& firstSegment, Seg2D& secondSegment);

    /*
     * This function is called within the splitLines function and would update the
     * sweepLineStatus data structure with the new updated split segment.
     */
    void updateSweepLineStatus(Seg2D& segmentToBeReplaced, Seg2D& segmentToReplaceWith);


    /*
     * Functions for getting predecessor and getting successor
     */
    Seg2D& getPredecessor(Seg2D&);
    Seg2D& getSuccessor(Seg2D&);

    /*
     * Function for checking if a relation exists between two segments
     */
    bool isRelation(Seg2D&, Seg2D&);
};


#endif //PLANESWEEP_PROJECT_PLANESWEEP_H
