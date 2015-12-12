//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"
#include "Topic2/Implementation/Line2DImpl.h"
#include "Topic2/Implementation/Region2D.h"
#include "Topic2/Implementation/Region2DImpl.h"

using namespace std;


//TODO: make constructors for Point2D(Object2D) etc
ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
        objF = dynamic_cast<Point2D *>(&F);  // to access objF use it like this:  (Point2D *) objF
        objFpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objF)->cbegin());


        if (G.isPoint2D()) {
            objG = dynamic_cast<Point2D *>(&G);

            // assign objG Poi Iterator
            objGpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objG)->cbegin());
        }
        
        if (G.isPoint2D()) {
            objG = dynamic_cast<Point2D *>(&G);
            objGpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objG)->cbegin());

        } else if (G.isLine2D()) {
            // to be deleted:
            // objG = static_cast<Line2D *>(G);
            // Line2DImpl::ConstSegIterator lineIterator;
            // lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            // objGIterator = &lineIterator;
            
            // Dtj Dec 10, 2015
            objG = dynamic_cast<Line2D *>(&G);
            objGsegIterator  = new Line2DImpl::ConstHalfSegIterator (((Line2DImpl *) objG)->hBegin());
            

        } else if (G.isRegion2D()) {
            // to be deleted:
            // objG = static_cast<Region2D *>(G);
            // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            // regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            // objGIterator = &regionIterator;
            
             // Dtj Dec 10, 2015
            objG = dynamic_cast<Region2D *>(&G);
            objGregionIterator  = new Region2DImpl::ConstAttributedHalfSegmentIterator (((Region2DImpl *) objG)->cbegin());
            
        }
    } else if (F.isLine2D()) {
        // to be deleted:
        // objF = static_cast<Line2D *>(F);
        // Line2DImpl::ConstSegIterator lineIterator;
        // lineIterator = static_cast<Line2DImpl *>(F)->cbegin();
        // objFIterator = &lineIterator;
        
        // Dtj Dec 10, 2015
        objF = dynamic_cast<Line2D *>(&F);
        objFsegIterator  = new Line2DImpl::ConstHalfSegIterator (((Line2DImpl *) objF)->hBegin());

        if (G.isPoint2D()) {
            // to be deleted:
            // objG = static_cast<Point2D *>(G);
            // Point2D::ConstPoiIterator pointIterator;
            // pointIterator = static_cast<Point2D *>(G)->cbegin();
            // objGIterator = &pointIterator;
            
             // Dtj Dec 10, 2015
            objG = dynamic_cast<Point2D *>(&G);
            objGpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objG)->cbegin());

        } else if (G.isLine2D()) {
            // to be deleted:
            // objG = static_cast<Line2D *>(G);
            // Line2DImpl::ConstSegIterator lineIterator;
            // lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            // objGIterator = &lineIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Line2D *>(&G);
            objGsegIterator  = new Line2DImpl::ConstHalfSegIterator (((Line2DImpl *) objG)->hBegin());

        } else if (G.isRegion2D()) {
            // to be deleted:
            // objG = static_cast<Region2D *>(G);
            // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            // regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            // objGIterator = &regionIterator;
            
            // Dtj Dec 10, 2015
            objG = dynamic_cast<Region2D *>(&G);
            objGregionIterator  = new Region2DImpl::ConstAttributedHalfSegmentIterator (((Region2DImpl *) objG)->cbegin());
        }
    } else if (F.isRegion2D()) {
        // to be deleted:
        // objF = static_cast<Region2D *>(F);
        // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
        // regionIterator = static_cast<Region2DImpl *>(F)->cbegin();
        // objGIterator = &regionIterator;

        // Dtj Dec 10, 2015
        objF = dynamic_cast<Region2D *>(&F);
        objFregionIterator  = new Region2DImpl::ConstAttributedHalfSegmentIterator (((Region2DImpl *) objF)->cbegin());

        if (G.isPoint2D()) {
            // to be deleted:
            // objG = static_cast<Point2D *>(G);
            // Point2D::ConstPoiIterator pointIterator;
            // pointIterator = static_cast<Point2D *>(G)->cbegin();
            // objGIterator = &pointIterator;
            
            // Dtj Dec 10, 2015
            objG = dynamic_cast<Point2D *>(&G);
            objGpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objG)->cbegin());

        } else if (G.isLine2D()) {
            // to be deleted:
            // objG = static_cast<Line2D *>(G);
            // Line2DImpl::ConstSegIterator lineIterator;
            // lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            // objGIterator = &lineIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Line2D *>(&G);
            objGsegIterator  = new Line2DImpl::ConstHalfSegIterator (((Line2DImpl *) objG)->hBegin());


        } else if (G.isRegion2D()) {
            // to be deleted:
            // objG = static_cast<Region2D *>(G);
            // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            // regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            // objGIterator = &regionIterator;
            
            // Dtj Dec 10, 2015
            objG = dynamic_cast<Region2D *>(&G);
            objGregionIterator  = new Region2DImpl::ConstAttributedHalfSegmentIterator (((Region2DImpl *) objG)->cbegin());

        }
    }

    /* Call the selectFirst function to set the
    *  object and status variables. This should not be called anywhere else.
     */
    selectFirst();

}

ParallelObjectTraversal::~ParallelObjectTraversal() {

}

ParallelObjectTraversal::object ParallelObjectTraversal::getObject() {
    return object_value;
}

ParallelObjectTraversal::status ParallelObjectTraversal::getStatus() {
    return status_value;
}

//TODO selectFirst() and selectNext() should use the next min element based on setNextMin().Right now it is comparing just ObjectIterators. Where are we getting the nextMin value based on setMin()?

void ParallelObjectTraversal::selectFirst() {
    // to be deleted
    // if (!(objFIterator->isEmpty())) {
    //     *objFIterator = objF->cbegin();
    // }
    // if (!(objGIterator->isEmpty())) {
    //     *objGIterator = objG->cbegin();
    // }


    // Dtj Dec 10, 2015
    if (objF->isPoint2D()) {
	if (!objFpoiIterator)
    		objFpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objF)->cbegin());
    }
    if (objG->isPoint2D()) {
        if (!objGpoiIterator)
            objGpoiIterator  = new Point2D::ConstPoiIterator (((Point2D *) objG)->cbegin());
    }

    if (objF->isLine2D()) {
	if (!objFsegIterator)
    		objFsegIterator  = new Line2DImpl::ConstHalfSegIterator (((Line2DImpl *) objF)->hBegin());
    }
    if (objG->isLine2D()) {
        if (!objGsegIterator)
            objGsegIterator  = new Line2DImpl::ConstHalfSegIterator (((Line2DImpl *) objG)->hBegin());
    }
    
    if (objF->isRegion2D()) {
	if (!objFregionIterator)
    		objFregionIterator  = new Region2DImpl::ConstAttributedHalfSegmentIterator (((Region2DImpl *) objF)->cbegin());
    }
    if (objG->isRegion2D()) {
        if (!objGregionIterator)
           objGregionIterator  = new Region2DImpl::ConstAttributedHalfSegmentIterator (((Region2DImpl *) objG)->cbegin());
    }

    // Dtj Dec 10, 2015
//     TODO:
//     I have not changed this part yet. This oart need to be changed,
//     so please look at the old codes and adjust them to the new changes:

     if (objFpoiIterator->isEmpty() && objGpoiIterator->isEmpty()&&objFsegIterator->isEmpty()&&objGsegIterator->isEmpty()&&objFregionIterator->isEmpty()&&objGregionIterator->isEmpty()) {
         object_value = none;
         status_value = end_of_both;
     }
     else {
         if (objGpoiIterator->isEmpty()&&objGsegIterator->isEmpty()&&objGregionIterator->isEmpty())
             object_value = first;
         else if (objFpoiIterator->isEmpty()&&objFsegIterator->isEmpty()&&objFregionIterator->isEmpty())
             object_value = second;
         else
             object_value = both;

         if ((objFpoiIterator->getCurrent() == ((Point2D *) objF)->cend()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hEnd()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->cend())
             && ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())))
             status_value = end_of_both;
         else if (objFpoiIterator->getCurrent() == ((Point2D *) objF)->cend()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hEnd()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->cend())
             status_value = end_of_first;
         else if (objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())
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
        Poi2D obj11 = static_cast<Poi2D>(objFpoiIterator->getCurrent());
        Poi2D obj12 = static_cast<Poi2D>(objFpoiIterator->getNext());
        minPoi2DF=new Poi2D();
        if(objG->isPoint2D())
        {
            Poi2D obj21 = static_cast<Poi2D>(objGpoiIterator->getCurrent());
            Poi2D obj22 = static_cast<Poi2D>(objGpoiIterator->getNext());
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
            HalfSeg2D obj21 = static_cast<HalfSeg2D>(objGsegIterator->getCurrent());
            HalfSeg2D obj22 = static_cast<HalfSeg2D>(objGsegIterator->getNext());
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
            AttrHalfSeg2D obj21 = static_cast<AttrHalfSeg2D>(objGregionIterator->getCurrent());
            AttrHalfSeg2D obj22 = static_cast<AttrHalfSeg2D>(objGregionIterator->getNext());
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
        HalfSeg2D obj11 = static_cast<HalfSeg2D>(objFsegIterator->getCurrent());
        HalfSeg2D obj12 = static_cast<HalfSeg2D>(objFsegIterator->getNext());
        minHalfSeg2DF = new HalfSeg2D();
        if(objG->isLine2D())
        {
            HalfSeg2D obj21 = static_cast<HalfSeg2D>(objGsegIterator->getCurrent());
            HalfSeg2D obj22 = static_cast<HalfSeg2D>(objGsegIterator->getNext());
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
            AttrHalfSeg2D obj21 = static_cast<AttrHalfSeg2D>(objGregionIterator->getCurrent());
            AttrHalfSeg2D obj22 = static_cast<AttrHalfSeg2D>(objGregionIterator->getNext());
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
        AttrHalfSeg2D obj11 = static_cast<AttrHalfSeg2D>(objFregionIterator->getCurrent());
        AttrHalfSeg2D obj12 = static_cast<AttrHalfSeg2D>(objFregionIterator->getNext());
        minAttrHalfSeg2DF = new AttrHalfSeg2D();
        if(objG->isRegion2D())
        {
            AttrHalfSeg2D obj21 = static_cast<AttrHalfSeg2D>(objGregionIterator->getCurrent());
            AttrHalfSeg2D obj22 = static_cast<AttrHalfSeg2D>(objGregionIterator->getNext());
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
        if(objF->isPoint2D())
        {
            objFpoiIterator++;
        }
        else if(objF->isLine2D())
        {
            objFsegIterator++;
        }
        else if(objF->isRegion2D())
        {
            objFregionIterator++;
        }
        if(objG->isPoint2D())
        {
            objGpoiIterator++;
        }
        else if(objG->isLine2D())
        {
            objGsegIterator++;
        }
        else if(objG->isRegion2D())
        {
            objGregionIterator++;
        }
//        objFIterator++;
//        objGIterator++;
    } else if (object_value == first) {
        if(objF->isPoint2D())
        {
            objFpoiIterator++;
        }
        else if(objF->isLine2D())
        {
            objFsegIterator++;
        }
        else if(objF->isRegion2D())
        {
            objFregionIterator++;
        }
       // objFIterator++;
    } else if (object_value == second) {
        if(objG->isPoint2D())
        {
            objGpoiIterator++;
        }
        else if(objG->isLine2D())
        {
            objGsegIterator++;
        }
        else if(objG->isRegion2D())
        {
            objGregionIterator++;
        }
       // objGIterator++;
    } else if (object_value == none) {
        // Because if both objects elements are over, don't update object and
        // status variables or object pointers.
        return;
    }

//TODO define getCurrent() and getNext() for ObjectIterators
    if ((objFpoiIterator->getCurrent() == ((Point2D *) objF)->cend()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hEnd()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->cend())) {
        if ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())) {
            status_value = end_of_both;
        }
        else {
            status_value = end_of_first;
        }
    } else if ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())) {
        status_value = end_of_second;
    } else {
        status_value = end_of_none;
    }


    if ((objFpoiIterator->getCurrent() == ((Point2D *) objF)->ctail()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hTail()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->ctail()) && ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->ctail()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hTail()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->ctail()))) {
        object_value = none;
    } else if ((objFpoiIterator->getCurrent() == objGpoiIterator->getCurrent())||(objFsegIterator->getCurrent()==objGsegIterator->getCurrent())||(objFregionIterator->getCurrent()==objGregionIterator->getCurrent())) {
        object_value = both;
    } else if ((objFpoiIterator->getCurrent() < objGpoiIterator->getCurrent())||(objFsegIterator->getCurrent()<objGsegIterator->getCurrent())||(objFregionIterator->getCurrent()<objGregionIterator->getCurrent())) {
        object_value = first;
    } else if ((objFpoiIterator->getCurrent() > objGpoiIterator->getCurrent())||(objFsegIterator->getCurrent()>objGsegIterator->getCurrent())||(objFregionIterator->getCurrent()>objGregionIterator->getCurrent())) {
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

        Poi2D poi2D = *(*objFpoiIterator);
        return poi2D;
    } else if (objectEnumVal == object::second) {
        Poi2D poi2D = *(*objGpoiIterator);
        return poi2D;
    }
}

HalfSeg2D ParallelObjectTraversal::getHalfSegEvent(object objectEnumVal) {
    if (objectEnumVal == object::first) {

        HalfSeg2D halfSeg2D = *(*objFsegIterator);
        return halfSeg2D;
    } else if (objectEnumVal == object::second) {
        HalfSeg2D halfSeg2D = *(*objGsegIterator);
        return halfSeg2D;
    }
}

AttrHalfSeg2D ParallelObjectTraversal::getAttrHalfSegEvent(object objectEnumVal) {
    if (objectEnumVal == object::first) {

        AttrHalfSeg2D attrhalfSeg2D = *(*objFregionIterator);
        return attrhalfSeg2D;
    } else if (objectEnumVal == object::second) {
        AttrHalfSeg2D attrhalfSeg2D = *(*objGregionIterator);
        return attrhalfSeg2D;
    }
}

Point2D::ConstPoiIterator * ParallelObjectTraversal::getPoiObjIterator(object objectparam)
{
    if(objectparam==first)
    {
        return objFpoiIterator;
    }
    else if(objectparam==second)
    {
        return objGpoiIterator;
    }
    return nullptr;
}

Line2DImpl::ConstHalfSegIterator * ParallelObjectTraversal::getHalfSegIterator(object objectparam)
{
    if(objectparam==first)
    {
        return objFsegIterator;
    }
    else if(objectparam==second)
    {
        return objGsegIterator;
    }
    return nullptr;
}

Region2DImpl::ConstAttributedHalfSegmentIterator * ParallelObjectTraversal::getAttrHalfSegIterator(object objectparam)
{
    if(objectparam==first)
    {
        return objFregionIterator;
    }
    else if(objectparam==second)
    {
        return objGregionIterator;
    }
    return nullptr;
}


//TODO: for next 6 functions- get ideal iterators
////TODO obji does not work with simple ++ for next 6 functions

bool ParallelObjectTraversal::isInObjF(Seg2D &seg2D) {
    //ObjectIterator obji;
    if(objF->isLine2D()) {
        Line2DImpl::ConstHalfSegIterator obji;
        for (obji = ((Line2DImpl *)objF)->hBegin(); obji <= ((Line2DImpl *)objF)->hEnd(); obji++) {

            //Line2DImpl::ConstSegIterator val = dynamic_cast<Line2DImpl::ConstSegIterator>(obji);
            HalfSeg2D iter = *(obji);
            if (seg2D == iter.seg) {
                return true;
            }
        }
    }
        else if(objF->isRegion2D())
        {
            Region2DImpl::ConstAttributedHalfSegmentIterator obji;
            for (obji = ((Region2DImpl *)objF)->cbegin(); obji <= ((Region2DImpl *)objF)->cend(); obji++) {
                AttrHalfSeg2D iter = *(obji);
                if (seg2D==iter.hseg.seg) {
                    return true;
                }
            }

        }

    return false;
}

bool ParallelObjectTraversal::isInObjG(Seg2D &seg2D) {
    //ObjectIterator obji;
    if(objG->isLine2D())
    {
        Line2DImpl::ConstHalfSegIterator obji;
    for (obji = ((Line2DImpl *)objG)->hBegin(); obji <= ((Line2DImpl *)objG)->hEnd(); obji++) {

            HalfSeg2D iter = *(obji);
            if (seg2D==iter.seg) {
                return true;
            }
        }
    }
    else if(objG->isRegion2D())
    {
        Region2DImpl::ConstAttributedHalfSegmentIterator obji;
        for (obji =((Region2DImpl *) objG)->cbegin(); obji <= ((Region2DImpl *)objG)->cend(); obji++) {
            AttrHalfSeg2D iter = *(obji);
            if (seg2D==iter.hseg.seg) {
                return true;
            }
        }

    }
    return false;
}

Line2DImpl::ConstHalfSegIterator * ParallelObjectTraversal::getNextObjIterator(HalfSeg2D halfSeg2D, object objectparam) {
    Line2DImpl::ConstHalfSegIterator * obji;
    if (objectparam == first) {
        if(objF->isLine2D()) {
        for (*obji = ((Line2DImpl*)objF)->hBegin(); *obji <= ((Line2DImpl *)objF)->hEnd(); (*obji)++) {
                HalfSeg2D iter = *(*obji);
                if (halfSeg2D==iter) {
                    if ((status_value != end_of_first) && (status_value != end_of_both)) {
                        (*obji)++;
                        Line2DImpl::ConstHalfSegIterator* result = obji;
                        return result;
                    }
                }

        }
        }
        return nullptr;
    }
    if (objectparam == second) {
        if(objG->isLine2D()) {
        for (*obji = ((Line2DImpl *)objG)->hBegin(); *obji <= ((Line2DImpl *)objG)->hEnd(); (*obji)++) {

                HalfSeg2D iter = *(*obji);
                if (halfSeg2D==iter) {
                    if ((status_value != end_of_second) && (status_value != end_of_both)) {
                        (*obji)++;
                        Line2DImpl::ConstHalfSegIterator* result = obji;
                        return result;
                    }
                }
        }
        }
        return nullptr;
    }
}

Region2DImpl::ConstAttributedHalfSegmentIterator* ParallelObjectTraversal::getNextObjIterator(AttrHalfSeg2D attrhalfSeg2D, object objectparam) {
    Region2DImpl::ConstAttributedHalfSegmentIterator* obji;
    if (objectparam == first) {
        if(objF->isRegion2D()) {
        for (*obji = ((Region2DImpl *)objF)->cbegin(); *obji <= ((Region2DImpl*)objF)->cend(); (*obji)++) {

                AttrHalfSeg2D iter = *(*obji);
                if (attrhalfSeg2D==iter) {
                    if ((status_value != end_of_first) && (status_value != end_of_both)) {
                        (*obji)++;
                        Region2DImpl::ConstAttributedHalfSegmentIterator *result = obji;
                        return result;
                    }
                }
        }
        }
        return nullptr;
    }
    if (objectparam == second) {
        if(objG->isRegion2D()) {
        for (*obji = ((Region2DImpl*)objG)->cbegin(); *obji <= ((Region2DImpl*)objG)->cend(); (*obji)++) {

            AttrHalfSeg2D iter = *(*obji);
                if (attrhalfSeg2D==iter) {
                    if ((status_value != end_of_second) && (status_value != end_of_both)) {
                        (*obji)++;
                        Region2DImpl::ConstAttributedHalfSegmentIterator *result = obji;
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


