//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"

// *** begin test temp
using namespace std;
#include <iostream>
// *** end test temp




ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
        objF=Point2D(F);
        objFIterator = ConstPoiIterator(F);
        if (G.isPoint2D()) {
            objG=Point2D(G);
            objGIterator = ConstPoiIterator(G);

        } else if (G.isLine2D()) {
            objG = Line2D(G);
            objGIterator = ConstLineIterator(G);

        } else if (G.isRegion2D()) {
            objG = Region2D(G);
            objGIterator = ConstRegionIterator(G);
        }
    } else
    if (F.isLine2D()) {
        objF = Line2D(F);
        objFIterator = ConstLineIterator(F);

        if (G.isPoint2D()) {
            objG = Point2D(G);
            objGIterator = ConstPoiIterator(G);

        } else if (G.isLine2D()) {
            objG = Line2D(G);
            objGIterator = ConstLine2DIterator(G);

        } else if (G.isRegion2D()) {
            objG = Region2D(G);
            objGIterator = ConstRegionIterator(G);          }
    } else
    if (F.isRegion2D()) {
        objF = Region2D(F);
        objFIterator = ConstRegionIterator(F);

        if (G.isPoint2D()) {
            objG = Point2D(G);
            objGIterator = ConstPoiIterator(G);

        } else if (G.isLine2D()) {
            objG = Line2D(G);
            objGIterator = ConstLine2DIterator(G);

        } else if (G.isRegion2D()) {
            objG = Region2D(G);
            objGIterator = ConstRegionIterator(G);

        }
    }


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
        objFIterator = objF->cbegin();
    }
    if (!(objGIterator->isEmpty()))
    {
        objGIterator = objG->cbegin();
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

ObjectIterator* ParallelObjectTraversal::getObjIterator(Object2D object2D)
{
    if(object2D==objF)
    {
        return objFIterator;
    }
    else if(object2D==objG)
    {
        return objGIterator;
    }
    return nullptr;
}
