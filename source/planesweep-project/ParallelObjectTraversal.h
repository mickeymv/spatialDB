/******************************************************************************
* File: ParallelObjectTraversal.h
*******************************************************************************
* Purpose: Interface to the class ParallelObjectTraversal
*
* Description: Parallel Object Traversal (or POT) traverses the point or halfsegment
* sequences of both operand objects in parallel. Hence, by employing a cursor on both
* sequences, it is sufficient to check the point or halfsegment at the current cursor
* positions of both sequences and to take the lower one with respect to the point order
* or halfsegment order for further computation.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*          Group 4 (Aswini Ramesh, Djundi Tjindra, Kyuseo Park, Michael Kemerer, Natasha Mandal)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
#define PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H

#include <memory>

#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic1/RobustGeometricPrimitives2D.h"
#include "Topic2/Implementation/Region2D.h"

#include "Object2D.h"
#include "Topic2/Implementation/Line2DImpl.h"
#include "Topic2/Implementation/Region2DImpl.h"


class ParallelObjectTraversal {

public:
    typedef enum {
        none, first, second, both
    } object;

    typedef enum {
        end_of_none,
        end_of_first, end_of_second, end_of_both
    } status;

    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++
    // Default constructor. It represents the empty ParallelObjectTraversal object
    ParallelObjectTraversal(const Object2D &, const Object2D &);

    // Destructor
    ~ParallelObjectTraversal();

    // Method that selects the next smallest point (or halfsegment) according to the
    // lexicographical (or halfsegment) order
    void selectNext();

    object getObject();

    status getStatus();

    // Method which returns the Point2D iterator based on the value of the object variable
    Point2D::ConstPoiIterator *getPoiObjIterator(object);

    // Method which returns the Line2D iterator based on the value of the object variable
    Line2DImpl::ConstHalfSegIterator *getHalfSegIterator(object);

    // Method which returns the Region2D iterator based on the value of the object variable
    Region2DImpl::ConstAttributedHalfSegmentIterator *getAttrHalfSegIterator(object);

    // Method that compares the current point of one iterator with the next point of the
    // other, and sets the minimum of those two.
    void setNextMin();

    // Methods that return a true if the object parameter is the first or second object
    bool isObjectF(Object2D);

    bool isObjectG(Object2D);

    Object2D getObjF();

    Object2D getObjG();

    // Method that returns the simple halfsegment of 'object' that is next in the logical
    // order. Does not include the dynamic EPS
    Line2DImpl::ConstHalfSegIterator *getNextObjIterator(HalfSeg2D, object);

    // Method that returns the simple attributed halfsegment of 'object' that is next in
    // the logical order. Does not include the dynamic EPS
    Region2DImpl::ConstAttributedHalfSegmentIterator *getNextObjIterator(AttrHalfSeg2D, object);

    // Method that checks whether the given segments are within an object
    bool isInObjF(Seg2D &);

    bool isInObjG(Seg2D &);

    Poi2D getPoiEvent(object objectEnumVal);

    HalfSeg2D getHalfSegEvent(object objectEnumVal);

    AttrHalfSeg2D getAttrHalfSegEvent(object objectEnumVal);

    // Methods that return the next minimum point (or (attributed) halfsegment) iterator
    Poi2D *getNextPoi2DMin();

    HalfSeg2D *getNextHalfSeg2DMin();

    AttrHalfSeg2D *getNextAttrHalfSeg2DMin();

    // Getter methods for minimum point, halfsegment and attributed halfsegment
    Poi2D *getMinPoi2DF();

    Poi2D *getMinPoi2DG();

    HalfSeg2D *getMinHalfSeg2DF();

    HalfSeg2D *getMinHalfSeg2DG();

    AttrHalfSeg2D *getMinAttrHalfSeg2DF();

    AttrHalfSeg2D *getMinAttrHalfSeg2DG();

    // Setter methods
    void setObject(const object &object_value);

    void setStatus(const status &status_value);

    // below are inline codes to get the current simple object from the iterator
    // Dtj. Dec 12, 2015
    inline Poi2D currentFPoi() { return (Poi2D) (**objFpoiIterator); }

    inline Poi2D currentGPoi() { return (Poi2D) (**objGpoiIterator); }

    inline HalfSeg2D currentFSeg() { return (HalfSeg2D) (**objFsegIterator); }

    inline HalfSeg2D currentGSeg() { return (HalfSeg2D) (**objGsegIterator); }

    inline AttrHalfSeg2D currentFASeg() { return (AttrHalfSeg2D) (**objFregionIterator); }

    inline AttrHalfSeg2D currentGASeg() { return (AttrHalfSeg2D) (**objGregionIterator); }

private:
    // Method that selects first point or halfsegment of each of the operand objects
    // and positions a logical pointer on both of them
    void selectFirst();

    ParallelObjectTraversal *pot;

    // Both object and status are initialized with initial value
    object object_value = none;
    status status_value = end_of_both;

    const Object2D *objF, *objG;

    Point2D::ConstPoiIterator *objFpoiIterator = nullptr, *objGpoiIterator = nullptr; // DTj Dec 5, 2015
    Line2DImpl::ConstHalfSegIterator *objFsegIterator = nullptr, *objGsegIterator = nullptr;
    Region2DImpl::ConstAttributedHalfSegmentIterator *objFregionIterator = nullptr, *objGregionIterator = nullptr;

    inline Poi2D nextFPoi() {
        Point2D::ConstPoiIterator nextobjFpoiIterator = ++(*objFpoiIterator);
        return (Poi2D) (*nextobjFpoiIterator);
    }

    inline Poi2D nextGPoi() {
        Point2D::ConstPoiIterator nextobjGpoiIterator = ++(*objGpoiIterator);
        return (Poi2D) (*nextobjGpoiIterator);
    }

    inline HalfSeg2D nextFSeg() {
        if (*objFsegIterator == ((Line2DImpl *) objF)->hTail()) {
            return (HalfSeg2D) *((Line2DImpl *) objF)->hTail();
        }
        Line2DImpl::ConstHalfSegIterator nextobjFsegIterator = ++(*objFsegIterator);
        return (HalfSeg2D) (*nextobjFsegIterator);
    }

    inline HalfSeg2D nextGSeg() {
        if (*objGsegIterator == ((Line2DImpl *) objG)->hTail()) {
            return (HalfSeg2D) *((Line2DImpl *) objG)->hTail();
        }
        Line2DImpl::ConstHalfSegIterator nextobjGsegIterator = ++(*objGsegIterator);
        return (HalfSeg2D) (*nextobjGsegIterator);
    }

    inline AttrHalfSeg2D nextFASeg() {
        if (*objFregionIterator == ((Region2DImpl *) objF)->ctail()) {
            return (AttrHalfSeg2D) *((Region2DImpl *) objF)->ctail();
        }
        Region2DImpl::ConstAttributedHalfSegmentIterator nextobjFregionIterator = ++(*objFregionIterator);
        return (AttrHalfSeg2D) (*nextobjFregionIterator);
    }

    inline AttrHalfSeg2D nextGASeg() {
        if (*objGregionIterator == ((Region2DImpl *) objG)->ctail()) {
            return (AttrHalfSeg2D) *((Region2DImpl *) objG)->ctail();
        }
        Region2DImpl::ConstAttributedHalfSegmentIterator nextobjGregionIterator = ++(*objGregionIterator);
        return (AttrHalfSeg2D) (*nextobjGregionIterator);
    }

    Poi2D *minPoi2DF = nullptr, *minPoi2DG = nullptr;
    HalfSeg2D *minHalfSeg2DF = nullptr, *minHalfSeg2DG = nullptr;
    AttrHalfSeg2D *minAttrHalfSeg2DF = nullptr, *minAttrHalfSeg2DG = nullptr;

};


#endif //PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
