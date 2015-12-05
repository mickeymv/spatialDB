//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"
#include "Topic2/Implementation/Line2DImpl.h"
#include "Topic2/Interfaces/Region2D.h"
#include "Topic2/Interfaces/Region2DImpl.h"

using namespace std;


//TODO: make constructors for Point2D(Object2D) etc
ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
        objF = static_cast<Point2D *>(F);
        Point2D::ConstPoiIterator pointIterator;
        pointIterator = static_cast<Point2D *>(F)->cbegin();
        objFIterator = &pointIterator;

        if (G.isPoint2D()) {
            objG = static_cast<Point2D *>(G);
            Point2D::ConstPoiIterator pointIterator;
            pointIterator = static_cast<Point2D *>(G)->cbegin();
            objGIterator = &pointIterator;


        } else if (G.isLine2D()) {
            objG = static_cast<Line2D *>(G);
            Line2DImpl::ConstSegIterator lineIterator;
            lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            objGIterator = &lineIterator;

        } else if (G.isRegion2D()) {
            objG = static_cast<Region2D *>(G);
            Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            objGIterator = &regionIterator;

        }
    } else if (F.isLine2D()) {
        objF = static_cast<Line2D *>(F);
        Line2DImpl::ConstSegIterator lineIterator;
        lineIterator = static_cast<Line2DImpl *>(F)->cbegin();
        objFIterator = &lineIterator;

        if (G.isPoint2D()) {
            objG = static_cast<Point2D *>(G);
            Point2D::ConstPoiIterator pointIterator;
            pointIterator = static_cast<Point2D *>(G)->cbegin();
            objGIterator = &pointIterator;

        } else if (G.isLine2D()) {
            objG = static_cast<Line2D *>(G);
            Line2DImpl::ConstSegIterator lineIterator;
            lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            objGIterator = &lineIterator;


        } else if (G.isRegion2D()) {
            objG = static_cast<Region2D *>(G);
            Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            objGIterator = &regionIterator;
        }
    } else if (F.isRegion2D()) {
        objF = static_cast<Region2D *>(F);
        Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
        regionIterator = static_cast<Region2DImpl *>(F)->cbegin();
        objGIterator = &regionIterator;


        if (G.isPoint2D()) {
            objG = static_cast<Point2D *>(G);
            Point2D::ConstPoiIterator pointIterator;
            pointIterator = static_cast<Point2D *>(G)->cbegin();
            objGIterator = &pointIterator;

        } else if (G.isLine2D()) {
            objG = static_cast<Line2D *>(G);
            Line2DImpl::ConstSegIterator lineIterator;
            lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            objGIterator = &lineIterator;


        } else if (G.isRegion2D()) {
            objG = static_cast<Region2D *>(G);
            Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            objGIterator = &regionIterator;

        }
    }

    /* Call the selectFirst function to set the
    *  object and status variables. This should not be called anywhere else.
     */
    selectFirst();

}

ParallelObjectTraversal::~ParallelObjectTraversal() {

}

object ParallelObjectTraversal::getObject() {
    return object_value;
}

status ParallelObjectTraversal::getStatus() {
    return status_value;
}

//TODO selectFirst() and selectNext() should use the next min element based on setNextMin().Right now it is comparing just ObjectIterators. Where are we getting the nextMin value based on setMin()?

void ParallelObjectTraversal::selectFirst() {
    if (!(objFIterator->isEmpty())) {
        *objFIterator = objF->cbegin();
    }
    if (!(objGIterator->isEmpty())) {
        *objGIterator = objG->cbegin();
    }

    if (objFIterator->isEmpty() && objGIterator->isEmpty()) {
        object_value = none;
        status_value = end_of_both;
    }
    else {
        if (objGIterator->isEmpty())
            object_value = first;
        else if (objFIterator->isEmpty())
            object_value = second;
        else
            object_value = both;

        if (objFIterator->getCurrent() == objF->cend()
            && objGIterator->getCurrent() == objG->cend())
            status_value = end_of_both;
        else if (objFIterator->getCurrent() == objF->cend())
            status_value = end_of_first;
        else if (objGIterator->getCurrent() == objG->cend())
            status_value = end_of_second;
        else
            status_value = end_of_none;
    }
}

//TODO - see if the return type should be AttrHalfSeg2D or check what it should be
void ParallelObjectTraversal::setNextMin() {
    //Line2D::ConstSegIterator *valF = dynamic_cast<Line2D::ConstSegIterator *>(objFIterator);

    if(objF->isPoint2D())
    {
        Poi2D obj11 = static_cast<Poi2D>(objFIterator->getCurrent());
        Poi2D obj12 = static_cast<Poi2D>(objFIterator->getNext());
        minPoi2DF=new Poi2D();
        if(objG->isPoint2D())
        {
            Poi2D obj21 = static_cast<Poi2D>(objGIterator->getCurrent());
            Poi2D obj22 = static_cast<Poi2D>(objGIterator->getNext());
            minPoi2DG= new Poi2D();
            if (object_value == first)
                (obj12 < obj21 ? *minPoi2DF=obj12 : *minPoi2DG=obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minPoi2DF=obj11 : *minPoi2DG=obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minPoi2DF=obj12 : *minPoi2DG=obj22);
            return;
        }
        if(objG->isLine2D())
        {
            minHalfSeg2DG = new HalfSeg2D();
            HalfSeg2D obj21 = static_cast<HalfSeg2D>(objGIterator->getCurrent());
            HalfSeg2D obj22 = static_cast<HalfSeg2D>(objGIterator->getNext());
            if (object_value == first)
                (obj12 < obj21 ? *minPoi2DF=obj12 : *minHalfSeg2DG=obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minPoi2DF=obj11 : *minHalfSeg2DG=obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minPoi2DF=obj12 : *minHalfSeg2DG=obj22);
            return;
        }
        if(objG->isRegion2D())
        {
            AttrHalfSeg2D obj21 = static_cast<AttrHalfSeg2D>(objGIterator->getCurrent());
            AttrHalfSeg2D obj22 = static_cast<AttrHalfSeg2D>(objGIterator->getNext());
            minAttrHalfSeg2DG = new AttrHalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minPoi2DF=obj12 : *minAttrHalfSeg2DG=obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minPoi2DF=obj11 : *minAttrHalfSeg2DG=obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minPoi2DF=obj12 : *minAttrHalfSeg2DG=obj22);
            return;
        }
    }
    if(objF->isLine2D())
    {
        HalfSeg2D obj11 = static_cast<HalfSeg2D>(objFIterator->getCurrent());
        HalfSeg2D obj12 = static_cast<HalfSeg2D>(objFIterator->getNext());
        minHalfSeg2DF = new HalfSeg2D();
        if(objG->isLine2D())
        {
            HalfSeg2D obj21 = static_cast<HalfSeg2D>(objGIterator->getCurrent());
            HalfSeg2D obj22 = static_cast<HalfSeg2D>(objGIterator->getNext());
            minHalfSeg2DG = new HalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minHalfSeg2DF=obj12 : *minHalfSeg2DG=obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minHalfSeg2DF=obj11 : *minHalfSeg2DG=obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minHalfSeg2DF=obj12 : *minHalfSeg2DG=obj22);
            return;
        }
        if(objG->isRegion2D())
        {
            AttrHalfSeg2D obj21 = static_cast<AttrHalfSeg2D>(objGIterator->getCurrent());
            AttrHalfSeg2D obj22 = static_cast<AttrHalfSeg2D>(objGIterator->getNext());
            minAttrHalfSeg2DG = new AttrHalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minHalfSeg2DF=obj12 : *minAttrHalfSeg2DG=obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minHalfSeg2DF=obj11 : *minAttrHalfSeg2DG=obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minHalfSeg2DF=obj12 : *minAttrHalfSeg2DG=obj22);
            return;
        }
    }
    if(objF->isRegion2D())
    {
        AttrHalfSeg2D obj11 = static_cast<AttrHalfSeg2D>(objFIterator->getCurrent());
        AttrHalfSeg2D obj12 = static_cast<AttrHalfSeg2D>(objFIterator->getNext());
        minAttrHalfSeg2DF = new AttrHalfSeg2D();
        if(objG->isRegion2D())
        {
            AttrHalfSeg2D obj21 = static_cast<AttrHalfSeg2D>(objGIterator->getCurrent());
            AttrHalfSeg2D obj22 = static_cast<AttrHalfSeg2D>(objGIterator->getNext());
            minAttrHalfSeg2DG = new AttrHalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minAttrHalfSeg2DF=obj12 : *minAttrHalfSeg2DG=obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minAttrHalfSeg2DF=obj11 : *minAttrHalfSeg2DG=obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minAttrHalfSeg2DF=obj12 : *minAttrHalfSeg2DG=obj22);
            return;
        }
    }

//    obj11 = objFIterator->getCurrent();
//    obj21 = objGIterator->getCurrent();
//    obj12 = objFIterator->getNext();
//    obj22 = objGIterator->getNext();
//    if (object_value == first)
//        return (obj12 < obj21 ? obj12 : obj21);
//    if (object_value == second)
//        return (obj11 < obj22 ? obj11 : obj22);
//    if (object_value == both)
//        return (obj12 < obj22 ? obj12 : obj22);
//    return nullptr;

}

void ParallelObjectTraversal::selectNext() {
    // increments the iterators for objects F and G
    // depending on the value of 'object' variable

    if (object_value == both) {
        objFIterator++;
        objGIterator++;
    } else if (object_value == first) {
        objFIterator++;
    } else if (object_value == second) {
        objGIterator++;
    } else if (object_value == none) {
        // Because if both objects elements are over, don't update object and
        // status variables or object pointers.
        return;
    }

//TODO define getCurrent() and getNext() for ObjectIterators
    if (objFIterator->getCurrent() == objF->cend()) {
        if (objGIterator->getCurrent() == objG->cend()) {
            status_value = end_of_both;
        }
        else {
            status_value = end_of_first;
        }
    } else if (objGIterator->getCurrent() == objG->cend()) {
        status_value = end_of_second;
    } else {
        status_value = end_of_none;
    }


    if (objFIterator->getCurrent() == objF->ctail() && objGIterator->getCurrent() == objG->ctail()) {
        object_value = none;
    } else if (objFIterator->getCurrent() == objGIterator->getCurrent()) {
        object_value = both;
    } else if (objFIterator->getCurrent() < objGIterator->getCurrent()) {
        object_value = first;
    } else if (objFIterator->getCurrent() > objGIterator->getCurrent()) {
        object_value = second;
    }
}

Poi2D* ParallelObjectTraversal::getNextPoi2DMin()
{
    if(minPoi2DF!= nullptr)
    {
        return minPoi2DF;
    }
    else if(minPoi2DG!= nullptr)
    {
        return minPoi2DG;
    }
    return nullptr;
}

HalfSeg2D* ParallelObjectTraversal::getNextHalfSeg2DMin()
{
    if(minHalfSeg2DF!= nullptr)
    {
        return minHalfSeg2DF;
    }
    else if(minHalfSeg2DG!= nullptr)
    {
        return minHalfSeg2DG;
    }
    return nullptr;
}

AttrHalfSeg2D* ParallelObjectTraversal::getNextAttrHalfSeg2DMin()
{
    if(minHalfSeg2DF!= nullptr)
    {
        return minAttrHalfSeg2DF;
    }
    else if(minHalfSeg2DG!= nullptr)
    {
        return minAttrHalfSeg2DG;
    }
    return nullptr;
}

Poi2D ParallelObjectTraversal::getPoiEvent(object objectEnumVal) {
    if (objectEnumVal == object::first) {

        Poi2D poi2D = static_cast<Poi2D>(*(objFIterator));
        return poi2D;
    } else if (objectEnumVal == object::second) {
        Poi2D poi2D = static_cast<Poi2D>(*(objGIterator));
        return poi2D;
    }
}

HalfSeg2D ParallelObjectTraversal::getHalfSegEvent(object objectEnumVal) {
    if (objectEnumVal == object::first) {

        HalfSeg2D halfSeg2D = static_cast<HalfSeg2D>(*(objFIterator));
        return halfSeg2D;
    } else if (objectEnumVal == object::second) {
        HalfSeg2D halfSeg2D = static_cast<HalfSeg2D>(*(objGIterator));
        return halfSeg2D;
    }
}

AttrHalfSeg2D ParallelObjectTraversal::getAttrHalfSegEvent(object objectEnumVal) {
    if (objectEnumVal == object::first) {

        AttrHalfSeg2D attrhalfSeg2D = static_cast<AttrHalfSeg2D>(*(objFIterator));
        return attrhalfSeg2D;
    } else if (objectEnumVal == object::second) {
        AttrHalfSeg2D attrhalfSeg2D = static_cast<AttrHalfSeg2D>(*(objGIterator));
        return attrhalfSeg2D;
    }
}

ObjectIterator *ParallelObjectTraversal::getObjIterator(object objectparam) {
    if (objectparam == first) {
        return objFIterator;
    }
    else if (objectparam == second) {
        return objGIterator;
    }
    return nullptr;
}

//TODO: for next 6 functions- get ideal iterators
////TODO obji does not work with simple ++ for next 6 functions

bool ParallelObjectTraversal::isInObjF(Seg2D &seg2D) {
    ObjectIterator obji;
    if(objF->isLine2D()) {
        for (obji = objF->cbegin(); obji <= objF->cend(); obji.++) {

            Line2DImpl::ConstSegIterator val = dynamic_cast<Line2DImpl::ConstSegIterator>(obji);
            HalfSeg2D iter = *(val);
            if (seg2D == iter.seg) {
                return true;
            }
        }
    }
        else if(objF->isRegion2D())
        {
            for (obji = objF->cbegin(); obji <= objF->cend(); obji.++) {
                Region2DImpl::ConstAttributedHalfSegmentIterator val = dynamic_cast<Region2DImpl::ConstAttributedHalfSegmentIterator>(obji);
                AttrHalfSeg2D iter = *(val);
                if (seg2D==iter.hseg.seg) {
                    return true;
                }
            }

        }

    return false;
}

bool ParallelObjectTraversal::isInObjG(Seg2D &seg2D) {
    ObjectIterator obji;
    if(objG->isLine2D())
    {
    for (obji = objG->cbegin(); obji <= objG->cend(); obji.++) {

            Line2DImpl::ConstSegIterator val = dynamic_cast<Line2DImpl::ConstSegIterator>(obji);
            HalfSeg2D iter = *(val);
            if (seg2D==iter.seg) {
                return true;
            }
        }
    }
    else if(objG->isRegion2D())
    {
        for (obji = objG->cbegin(); obji <= objG->cend(); obji.++) {
            Region2DImpl::ConstAttributedHalfSegmentIterator val = dynamic_cast<Region2DImpl::ConstAttributedHalfSegmentIterator>(obji);
            AttrHalfSeg2D iter = *(val);
            if (seg2D==iter.hseg.seg) {
                return true;
            }
        }

    }
    return false;
}

ObjectIterator* ParallelObjectTraversal::getNextObjIterator(HalfSeg2D halfSeg2D, object objectparam) {
    ObjectIterator* obji;
    if (objectparam == first) {
        if(objF->isLine2D()) {
        for (*obji = objF->cbegin(); *obji <= objF->cend(); (*obji).++) {
                Line2DImpl::ConstSegIterator val = dynamic_cast<Line2DImpl::ConstSegIterator >(*obji);
                HalfSeg2D iter = *(val);
                if (halfSeg2D==iter) {
                    if ((status_value != end_of_first) && (status_value != end_of_both)) {
                        ObjectIterator* result = (*obji).++;
                        return result;
                    }
                }

        }
        }
        return nullptr;
    }
    if (objectparam == second) {
        if(objG->isLine2D()) {
        for (*obji = objG->cbegin(); *obji <= objG->cend(); (*obji).++) {

                Line2DImpl::ConstSegIterator val = dynamic_cast<Line2DImpl::ConstSegIterator >(*obji);
                HalfSeg2D iter = *(val);
                if (halfSeg2D==iter) {
                    if ((status_value != end_of_second) && (status_value != end_of_both)) {
                        ObjectIterator *result = (*obji).++;
                        return result;
                    }
                }
        }
        }
        return nullptr;
    }
}

ObjectIterator* ParallelObjectTraversal::getNextObjIterator(AttrHalfSeg2D attrhalfSeg2D, object objectparam) {
    ObjectIterator* obji;
    if (objectparam == first) {
        if(objF->isRegion2D()) {
        for (*obji = objF->cbegin(); *obji <= objF->cend(); (*obji).++) {

                Region2DImpl::ConstAttributedHalfSegmentIterator val = dynamic_cast<Region2DImpl::ConstAttributedHalfSegmentIterator>(*obji);
                AttrHalfSeg2D iter = *(val);
                if (attrhalfSeg2D==iter) {
                    if ((status_value != end_of_first) && (status_value != end_of_both)) {
                        ObjectIterator *result = (*obji).++;
                        return result;
                    }
                }
        }
        }
        return nullptr;
    }
    if (objectparam == second) {
        if(objG->isRegion2D()) {
        for (*obji = objG->cbegin(); *obji <= objG->cend(); (*obji).++) {

            Region2DImpl::ConstAttributedHalfSegmentIterator val = dynamic_cast<Region2DImpl::ConstAttributedHalfSegmentIterator>(*obji);
            AttrHalfSeg2D iter = *(val);
                if (attrhalfSeg2D==iter) {
                    if ((status_value != end_of_second) && (status_value != end_of_both)) {
                        ObjectIterator *result = (*obji).++;
                        return result;
                    }
                }
        }
        }
        return nullptr;
    }
}

bool ParallelObjectTraversal::isObjectF(Object2D object2D) {
    if (object2D==(*objF)) {
        return true;
    }
    else {
        return false;
    }
}

bool ParallelObjectTraversal::isObjectG(Object2D object2D) {
    if (object2D==(*objG)) {
        return true;
    }
    else {
        return false;
    }
}

Object2D ParallelObjectTraversal::getObjF()
{
    return *objF;
}

Object2D ParallelObjectTraversal::getObjG()
{
    return *objG;
}


