//
// Created by Djundi on 11/3/15.
//

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
    
    
    ParallelObjectTraversal(Object2D &, Object2D &);

    ~ParallelObjectTraversal();

    void selectNext();

    object getObject();

    status getStatus();

    Point2D::ConstPoiIterator * getPoiObjIterator(object);
    Line2DImpl::ConstHalfSegIterator * getHalfSegIterator(object);
    Region2DImpl::ConstAttributedHalfSegmentIterator * getAttrHalfSegIterator(object);
	// need to finalise the return type
	void setNextMin();

    bool isObjectF(Object2D);
    bool isObjectG(Object2D);

    Object2D getObjF();
    Object2D getObjG();

    Line2DImpl::ConstHalfSegIterator *  getNextObjIterator(HalfSeg2D,object);
    Region2DImpl::ConstAttributedHalfSegmentIterator *  getNextObjIterator(AttrHalfSeg2D,object);

    /*Checks whether the given segments are within an object
   */
    bool isInObjF(Seg2D&);
    bool isInObjG(Seg2D&);


    Poi2D getPoiEvent(object objectEnumVal);
    HalfSeg2D getHalfSegEvent(object objectEnumVal);
    AttrHalfSeg2D getAttrHalfSegEvent(object objectEnumVal);

    Poi2D* getNextPoi2DMin();
    HalfSeg2D* getNextHalfSeg2DMin();
    AttrHalfSeg2D* getNextAttrHalfSeg2DMin();
    Poi2D *minPoi2DF = nullptr,*minPoi2DG = nullptr;
    HalfSeg2D *minHalfSeg2DF = nullptr, *minHalfSeg2DG= nullptr;
    AttrHalfSeg2D *minAttrHalfSeg2DF= nullptr, *minAttrHalfSeg2DG= nullptr;


private:
    //SelectFirst should be called in the POT constructor.
    void selectFirst();

    ParallelObjectTraversal *pot;
    object object_value;
    status status_value;
    Object2D *objF, *objG;

    Point2D::ConstPoiIterator * objFpoiIterator = nullptr, * objGpoiIterator = nullptr; // DTj Dec 5, 2015
    Line2DImpl::ConstHalfSegIterator * objFsegIterator = nullptr, * objGsegIterator = nullptr;
    Region2DImpl::ConstAttributedHalfSegmentIterator * objFregionIterator = nullptr, * objGregionIterator = nullptr;

};


#endif //PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
