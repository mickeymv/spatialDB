//
// Created by Djundi on 11/3/15.
//

#ifndef PLANESWEEP_PROJECT_PLANESWEEP_H
#define PLANESWEEP_PROJECT_PLANESWEEP_H


#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic2/Implementation/RobustGeometricPrimitives2D.h"
#include "Topic2/Implementation/Number.h"
#include "Region2D.h"

#include "Object2D.h"
#include "ParallelObjectTraversal.h"
#include "Obj2D.h"
#include "AVL.h"
#include "Attribute.h"
#include "PlaneSweepLineStatusObject.h"


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
     */
    void select_next();
    
    //Return the values of the object or status variables from the ParallelObjectTraversal Class
    ParallelObjectTraversal::object getObject();
    ParallelObjectTraversal::status getStatus();
    
    //Returns the value of the current "event" on the "sweep line status" datastructure
    //Object2D getEvent();
    Poi2D getEventPoi(int object);
    HalfSeg2D getEventHalfSeg(int object);
    AttrHalfSeg2D getEventAttrHalfSeg(int object);

    //Returns a new sweep line as an AVL Tree
    void new_sweep();

    /*
     * The addLeft function would enter a new segment into the sweepLineStatus
     * data structure.
     * It should call calculateIntersection() and calculateOverlap() within it.
     */
    void addLeft(Seg2D&);
    void delRight(Seg2D&);
    Attribute getAttr(Seg2D&);
    void setAttr(Seg2D&,Attribute);
    bool predExists(Seg2D&);
    Attribute getPredAttr(Seg2D&);
    Seg2D& predOfP(Poi2D&);
    bool lookAhead(HalfSeg2D&,Line2D&);//Look at region-region case for additional return type
    bool lookAhead(AttrHalfSeg2D&,Region2D&);//Look at region-region case for additional return type

private:
    // only one instance of ParallelObjectTraversal exist!
    ParallelObjectTraversal * pot;

    /* The state of the intersection of the sweep line with the geometric structure
     * being swept at the current sweep line position is recorded in vertical order
     * in a data structure called sweep line status.
     */
    AVL<Number, PlaneSweepLineStatusObject&> *sweepLineStatus;

    //Should increment the object pointers within either/both of the two objects.
    void selectFirst();

    /* A vertical sweep line traversing the plane from left to right stops at special
     * event points which are stored in a queue called event point schedule. The event
     * point schedule must allow one to insert new event points discovered during
     * processing; these are normally the initially unknown intersections of line segments.
     * Below are the DYNAMIC eventPointSchedules corresponding to each object.
     */
    AVL<Number, HalfSeg2D&> *dynamicEPSObjF;
    AVL<Number, HalfSeg2D&> *dynamicEPSObjG;

    /*
     *  This function would be called from within the selectNext() function.
     *  What this would do is find the least poi2D for the PlaneSweepLineStatus
     *  to stop next.
     *  If the next point is from the static Event Point schedule (EPS) (which
     *  is either of the two objects (objF/objG) ), we update the iterator of the
     *  corresponding object ( POT.selectNext() ) . If it is from the dynamic
     *  EPS of the min-heap, we update the current of that particular object's min-heap
     *  ( objFMinHeap.selectNext() / objGMinHeap.selectNext() )
     *  Why we need this is to obtain the next x-coordinate point to stop at for the
     *  PlaneSweepLineStatus.
     */
    Poi2D findLeast();

    /*
     *  Checks whether a Seg2D has intersections with any of the predecessor and successor already
     *  in the sweepLineStatus. If it does, it calls the functions
     *  splitLines().
     */
    void calculateRelation(Seg2D);


    /*
     *  This function which is called from within the calculateRelation functions,
     *  it would split the two passed segments into more segments based on the relation between them and
     *  call the functions updateSweepLineStatus and the insertIntoDynamicEPS().
     *  The insertIntoDynamicEPS() function is just the insert() function for the
     *  two different min-heaps for the objects under consideration.
     */
    void splitLines(Seg2D firstSegment, Seg2D secondSegment);

    /*
     * This function is called within the splitLines function and would update the
     * sweepLineStatus data structure with the new updated split segment.
     */
    void updateSweepLineStatus(Seg2D segmentToBeReplaced, Seg2D segmentToReplaceWith);

};


#endif //PLANESWEEP_PROJECT_PLANESWEEP_H
