//
// Created by Djundi on 11/3/15.
//

#ifndef PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
#define PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H

#include <memory>

#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic1/RobustGeometricPrimitives2D.h"
#include "Topic2/Interfaces/Region2D.h"

#include "Object2D.h"
#include "ObjectIterator.h"


class ParallelObjectTraversal {

public:
    ParallelObjectTraversal(Object2D &, Object2D &);

    ~ParallelObjectTraversal();

    void selectNext();

    object getObject();

    status getStatus();

    ObjectIterator *getObjIterator(object);
	// need to finalise the return type
	void setNextMin();

    bool isObjectF(Object2D);
    bool isObjectG(Object2D);

    Object2D getObjF();
    Object2D getObjG();

    ObjectIterator* getNextObjIterator(HalfSeg2D,object);
    ObjectIterator* getNextObjIterator(AttrHalfSeg2D,object);

    /*Checks whether the given segments are within an object
   */
    bool isInObjF(Seg2D&);
    bool isInObjG(Seg2D&);

    typedef enum {
        none, first, second, both
    } object;

    typedef enum {
        end_of_none,
        end_of_first, end_of_second, end_of_both
    } status;

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
    ObjectIterator *objFIterator, *objGIterator;


};


#endif //PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
