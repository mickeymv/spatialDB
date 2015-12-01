//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"

// *** begin test temp
using namespace std;
#include <iostream>
// *** end test temp



//TODO: make constructors for Point2D(Object2D) etc
ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
        //objF=Point2D(F);
        *objF=(F);
        //objFIterator = Point2D::ConstPoiIterator(F);

        if (G.isPoint2D()) {
            //objG=Point2D(G);
            *objG=(G);
            //objGIterator = Point2D::ConstPoiIterator(G);


        } else if (G.isLine2D()) {
            //objG = Line2D(G);
            *objG=(G);
            //objGIterator = Line2D::ConstSegIterator(G);

        } else if (G.isRegion2D()) {
            //objG = Region2D(G);
            *objG=(G);
            //objGIterator = Region2D::ConstRegionIterator(G);

        }
    } else
    if (F.isLine2D()) {
        //objF = Line2D(F);
        *objF=(F);
        //objFIterator = Line2D::ConstSegIterator(F);

        if (G.isPoint2D()) {
            //objG = Point2D(G);
            *objG=(G);
            //objGIterator = Point2D::ConstPoiIterator(G);

        } else if (G.isLine2D()) {
            //objG = Line2D(G);
            *objG=(G);
            //objGIterator = Line2D::ConstSegIterator(G);


        } else if (G.isRegion2D()) {
            //objG = Region2D(G);
            *objG=(G);
            //objGIterator = Region2D::ConstRegionIterator(G);
        }
    } else
    if (F.isRegion2D()) {
        //objF = Region2D(F);
        *objF=(F);
        //objFIterator = Region2D::ConstRegionIterator(F);


        if (G.isPoint2D()) {
            //objG = Point2D(G);
            *objG=(G);
            //objGIterator = Point2D::ConstPoiIterator(G);

        } else if (G.isLine2D()) {
            //objG = Line2D(G);
            *objG=(G);
            //objGIterator = Line2D::ConstSegIterator(G);


        } else if (G.isRegion2D()) {
            //objG = Region2D(G);
            *objG=(G);
            //objGIterator = Region2D::ConstRegionIterator(G);

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

void ParallelObjectTraversal::selectFirst() {
    if (!(objFIterator->isEmpty()))
    {
        *objFIterator = objF->cbegin();
    }
    if (!(objGIterator->isEmpty()))
    {
        *objGIterator = objG->cbegin();
    }

    if (objFIterator->isEmpty() && objGIterator->isEmpty())
    {
        object_value = none;
        status_value = end_of_both;
    }
    else
    {
        if (objGIterator->isEmpty())
            object_value = first;
        else if (objFIterator->isEmpty())
            object_value = second;
        else
            object_value = both;

        if(objFIterator->getCurrent() == objFIterator->cend()
           && objGIterator->getCurrent() == objGIterator->cend())
            status_value = end_of_both;
        else if(objFIterator->getCurrent() == objFIterator->cend())
            status_value = end_of_first;
        else if (objGIterator->getCurrent() == objGIterator->cend())
            status_value = end_of_second;
        else
            status_value = end_of_none;
    }
}

AttrHalfSeg2D getNextMin() {
	obj11 = objFIterator->getCurrent();
	obj21 = objGIterator->getCurrent();
	obj12 = objFIterator->getNext();
	obj22 = objGIterator->getNext();
	if(object_value == first)
		return (obj12<obj21? obj12: obj21);
	if(object_value == second)
		return (obj11<obj22? obj11: obj22);
	if(object_value == both)
		return (obj12<obj22? obj12: obj22);
	return NULL;

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


    if (objFIterator->getCurrent() == objF->cend()) {
        if (objGIterator->getCurrent() == objG->cend())
        {
            status_value = end_of_both;
        }
        else {
            status_value = end_of_first;
        }
    } else if (objGIterator->getCurrent() == objG->cend()) {
        status_value = end_of_second;
    } else
    {
        status_value = end_of_none;
    }


    if (objFIterator->.getCurrent() == objF->ctail() && objGIterator->getCurrent() == objG->ctail())
    {
        object_value = none;
    } else if (objFIterator->getCurrent() == objGIterator->getCurrent())
    {
        object_value = both;
    } else if (objFIterator->getCurrent() < objGIterator->getCurrent())
    {
        object_value = first;
    } else if (objFIterator->getCurrent() > objGIterator->getCurrent())
    {
        object_value = second;
    }
}

Poi2D ParallelObjectTraversal::getEvent(object objectEnumVal) {
    if (objectEnumVal == object::first) {
        Poi2D poi2D = objFIterator->operator->();
        return poi2D;
    } else if (objectEnumVal == object::second) {
        Poi2D poi2D = objGIterator->operator->();
        return poi2D;
    }
}

ObjectIterator * ParallelObjectTraversal::getObjIterator(object objectparam)
{
    if(objectparam==first)
    {
        return objFIterator;
    }
    else if(objectparam==second)
    {
        return objGIterator;
    }
    return nullptr;
}

//TODO: for next 6 functions- get ideal iterators

bool ParallelObjectTraversal::isInObjF(Seg2D & seg2D)
{
    ObjectIterator obji;

    for(obji=objF->cbegin();obji<=objF->cend();obji++ )
    {
        Line2D::ConstSegIterator val = dynamic_cast<Line2D::ConstSegIterator>(obji);
        Seg2D iter = *(val);
        if(seg2D.operator==(iter))
        {
            return true;
        }
    }
    return false;
}

bool ParallelObjectTraversal::isInObjG(Seg2D & seg2D)
{
    ObjectIterator obji;

    for(obji=objG->cbegin();obji<=objG->cend();obji++ )
    {
        Line2D::ConstSegIterator val = dynamic_cast<Line2D::ConstSegIterator>(obji);
        Seg2D iter = *(val);
        if(seg2D.operator==(iter))
        {
            return true;
        }
    }
    return false;
}

ObjectIterator * ParallelObjectTraversal::getNextObjIterator(HalfSeg2D halfSeg2D,object objectparam)
{
    ObjectIterator* obji;
    if(objectparam==first)
    {
       for(*obji=objF->cbegin();*obji<=objF->cend();obji++ )
       {
           Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator*>(obji);
           HalfSeg2D iter = *(*val);
           if(halfSeg2D.operator==(iter))
           {
               return ++obji;
           }
       }
        return nullptr;
    }
    if(objectparam==second)
    {
        for(*obji=objG->cbegin();*obji<=objG->cend();obji++ )
        {
            Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator*>(obji);
            HalfSeg2D iter = *(*val);
            if(halfSeg2D.operator==(iter))
            {
                return ++obji;
            }
        }
        return nullptr;
    }
}

ObjectIterator * ParallelObjectTraversal::getNextObjIterator(AttrHalfSeg2D attrhalfSeg2D,object objectparam)
{
    ObjectIterator * obji;
    if(objectparam==first)
    {
        for(*obji=(objF->cbegin());*obji<=(objF->cend());obji++ )
        {
            Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator*>(obji);
            AttrHalfSeg2D iter = *(*val);
            if(attrhalfSeg2D.operator==(iter))
            {
                return ++obji;
            }
        }
        return nullptr;
    }
    if(objectparam==second)
    {
        for(*obji=(objG->cbegin());obji<=(objG->cend());obji++ )
        {
            Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator*>(obji);
            AttrHalfSeg2D iter = *(*val);
            if(attrhalfSeg2D.operator==(iter))
            {
                return ++obji;
            }
        }
        return nullptr;
    }
}

bool ParallelObjectTraversal::isObjectF(Object2D object2D)
{
    if(object2D.operator==(*objF))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ParallelObjectTraversal::isObjectG(Object2D object2D)
{
    if(object2D.operator==(*objG))
    {
        return true;
    }
    else
    {
        return false;
    }
}


