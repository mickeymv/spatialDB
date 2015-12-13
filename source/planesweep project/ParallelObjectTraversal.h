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

    ParallelObjectTraversal(const Object2D &, const Object2D &);

    ~ParallelObjectTraversal();

    void selectNext();

    object getObject();

    status getStatus();

    Point2D::ConstPoiIterator * getPoiObjIterator(object);
    Line2DImpl::ConstHalfSegIterator * getHalfSegIterator(object);
    Region2DImpl::ConstAttributedHalfSegmentIterator * getAttrHalfSegIterator(object);
    // need to finalise the return type
    void setNextMin();

    bool isObjectF(const Object2D);
    bool isObjectG(const Object2D);

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


    Poi2D* getMinPoi2DF();
    Poi2D* getMinPoi2DG();
    HalfSeg2D* getMinHalfSeg2DF();
    HalfSeg2D* getMinHalfSeg2DG();
    AttrHalfSeg2D* getMinAttrHalfSeg2DF();
    AttrHalfSeg2D* getMinAttrHalfSeg2DG();


private:
    //SelectFirst should be called in the POT constructor.
    void selectFirst();

    ParallelObjectTraversal *pot;

    // both object and status are initialized with initial value
    object object_value = none;
    status status_value = end_of_both;

    const Object2D *objF, *objG;

    Point2D::ConstPoiIterator * objFpoiIterator = nullptr, * objGpoiIterator = nullptr; // DTj Dec 5, 2015
    Line2DImpl::ConstHalfSegIterator * objFsegIterator = nullptr, * objGsegIterator = nullptr;
    Region2DImpl::ConstAttributedHalfSegmentIterator * objFregionIterator = nullptr, * objGregionIterator = nullptr;

    // below are inline codes to get the current simple object from the iterator
    // Dtj. Dec 12, 2015
    inline Poi2D currentFPoi() {return (Poi2D)(**objFpoiIterator); }
    inline Poi2D currentGPoi() {return (Poi2D)(**objGpoiIterator); }

    inline HalfSeg2D currentFSeg() {return (HalfSeg2D)(**objFsegIterator); }
    inline HalfSeg2D currentGSeg() {return (HalfSeg2D)(**objGsegIterator); }

    inline AttrHalfSeg2D currentFASeg() {return (AttrHalfSeg2D)(**objFregionIterator); }
    inline AttrHalfSeg2D currentGASeg() {return (AttrHalfSeg2D)(**objGregionIterator); }

    inline Poi2D nextFPoi() { Point2D::ConstPoiIterator nextobjFpoiIterator = (*objFpoiIterator)++;(*objFpoiIterator)--;return (Poi2D)(*nextobjFpoiIterator); }
    inline Poi2D nextGPoi() {Point2D::ConstPoiIterator nextobjGpoiIterator = (*objGpoiIterator)++;(*objGpoiIterator)--;return (Poi2D)(*nextobjGpoiIterator); }

    inline HalfSeg2D nextFSeg() {Line2DImpl::ConstHalfSegIterator nextobjFsegIterator = (*objFsegIterator)++;(*objFsegIterator)--;return (HalfSeg2D)(*nextobjFsegIterator);  }
    inline HalfSeg2D nextGSeg() {Line2DImpl::ConstHalfSegIterator nextobjGsegIterator = (*objGsegIterator)++;(*objGsegIterator)--;return (HalfSeg2D)(*nextobjGsegIterator);  }

    inline AttrHalfSeg2D nextFASeg() {Region2DImpl::ConstAttributedHalfSegmentIterator nextobjFregionIterator = (*objFregionIterator)++;(*objFregionIterator)--;return (AttrHalfSeg2D)(*nextobjFregionIterator);  }
    inline AttrHalfSeg2D nextGASeg() {Region2DImpl::ConstAttributedHalfSegmentIterator nextobjGregionIterator = (*objGregionIterator)++;(*objGregionIterator)--;return (AttrHalfSeg2D)(*nextobjGregionIterator);  }

    Poi2D *minPoi2DF = nullptr,*minPoi2DG = nullptr;
    HalfSeg2D *minHalfSeg2DF = nullptr, *minHalfSeg2DG= nullptr;
    AttrHalfSeg2D *minAttrHalfSeg2DF= nullptr, *minAttrHalfSeg2DG= nullptr;
    // TODO
    // define the rest of the inlined currentFXXX and currentGxxx below
    ///

};


#endif //PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
