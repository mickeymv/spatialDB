//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"

using namespace std;


const ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {


    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
        objF = dynamic_cast<Point2D *>(&F);  // to access objF use it like this:  (Point2D *) objF
        objFpoiIterator = new Point2D::ConstPoiIterator(((Point2D *) objF)->cbegin());


        if (G.isPoint2D()) {
            objG = dynamic_cast<Point2D *>(&G);

            // assign objG Poi Iterator
            objGpoiIterator = new Point2D::ConstPoiIterator(((Point2D *) objG)->cbegin());
        }

        if (G.isPoint2D()) {
            objG = dynamic_cast<Point2D *>(&G);
            objGpoiIterator = new Point2D::ConstPoiIterator(((Point2D *) objG)->cbegin());

        } else if (G.isLine2D()) {
            // to be deleted:
            // objG = static_cast<Line2D *>(G);
            // Line2DImpl::ConstSegIterator lineIterator;
            // lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            // objGIterator = &lineIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Line2D *>(&G);
            objGsegIterator = new Line2DImpl::ConstHalfSegIterator(((Line2DImpl *) objG)->hBegin());


        } else if (G.isRegion2D()) {
            // to be deleted:
            // objG = static_cast<Region2D *>(G);
            // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            // regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            // objGIterator = &regionIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Region2D *>(&G);
            objGregionIterator = new Region2DImpl::ConstAttributedHalfSegmentIterator(
                    ((Region2DImpl *) objG)->cbegin());

        }
    } else if (F.isLine2D()) {
        // to be deleted:
        // objF = static_cast<Line2D *>(F);
        // Line2DImpl::ConstSegIterator lineIterator;
        // lineIterator = static_cast<Line2DImpl *>(F)->cbegin();
        // objFIterator = &lineIterator;

        // Dtj Dec 10, 2015
        objF = dynamic_cast<Line2D *>(&F);
        objFsegIterator = new Line2DImpl::ConstHalfSegIterator(((Line2DImpl *) objF)->hBegin());

        if (G.isPoint2D()) {
            // to be deleted:
            // objG = static_cast<Point2D *>(G);
            // Point2D::ConstPoiIterator pointIterator;
            // pointIterator = static_cast<Point2D *>(G)->cbegin();
            // objGIterator = &pointIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Point2D *>(&G);
            objGpoiIterator = new Point2D::ConstPoiIterator(((Point2D *) objG)->cbegin());

        } else if (G.isLine2D()) {
            // to be deleted:
            // objG = static_cast<Line2D *>(G);
            // Line2DImpl::ConstSegIterator lineIterator;
            // lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            // objGIterator = &lineIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Line2D *>(&G);
            objGsegIterator = new Line2DImpl::ConstHalfSegIterator(((Line2DImpl *) objG)->hBegin());

        } else if (G.isRegion2D()) {
            // to be deleted:
            // objG = static_cast<Region2D *>(G);
            // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            // regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            // objGIterator = &regionIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Region2D *>(&G);
            objGregionIterator = new Region2DImpl::ConstAttributedHalfSegmentIterator(
                    ((Region2DImpl *) objG)->cbegin());
        }
    } else if (F.isRegion2D()) {
        // to be deleted:
        // objF = static_cast<Region2D *>(F);
        // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
        // regionIterator = static_cast<Region2DImpl *>(F)->cbegin();
        // objGIterator = &regionIterator;

        // Dtj Dec 10, 2015
        objF = dynamic_cast<Region2D *>(&F);
        objFregionIterator = new Region2DImpl::ConstAttributedHalfSegmentIterator(((Region2DImpl *) objF)->cbegin());

        if (G.isPoint2D()) {
            // to be deleted:
            // objG = static_cast<Point2D *>(G);
            // Point2D::ConstPoiIterator pointIterator;
            // pointIterator = static_cast<Point2D *>(G)->cbegin();
            // objGIterator = &pointIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Point2D *>(&G);
            objGpoiIterator = new Point2D::ConstPoiIterator(((Point2D *) objG)->cbegin());

        } else if (G.isLine2D()) {
            // to be deleted:
            // objG = static_cast<Line2D *>(G);
            // Line2DImpl::ConstSegIterator lineIterator;
            // lineIterator = static_cast<Line2DImpl *>(G)->cbegin();
            // objGIterator = &lineIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Line2D *>(&G);
            objGsegIterator = new Line2DImpl::ConstHalfSegIterator(((Line2DImpl *) objG)->hBegin());


        } else if (G.isRegion2D()) {
            // to be deleted:
            // objG = static_cast<Region2D *>(G);
            // Region2DImpl::ConstAttributedHalfSegmentIterator regionIterator;
            // regionIterator = static_cast<Region2DImpl *>(G)->cbegin();
            // objGIterator = &regionIterator;

            // Dtj Dec 10, 2015
            objG = dynamic_cast<Region2D *>(&G);
            objGregionIterator = new Region2DImpl::ConstAttributedHalfSegmentIterator(
                    ((Region2DImpl *) objG)->cbegin());

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
    // set all the iterators to the beginning of the vector
    if (objF->isPoint2D()) {
        *objFpoiIterator = ((Point2D *) objF)->cbegin();
    }
    if (objG->isPoint2D()) {
        *objGpoiIterator = ((Point2D *) objG)->cbegin();
    }

    if (objF->isLine2D()) {
        *objFsegIterator = ((Line2DImpl *) objF)->hBegin();
    }
    if (objG->isLine2D()) {
        *objGsegIterator = ((Line2DImpl *) objG)->hBegin();
    }

    if (objF->isRegion2D()) {
        *objFregionIterator = ((Region2DImpl *) objF)->cbegin();
    }
    if (objG->isRegion2D()) {
        *objGregionIterator = ((Region2DImpl *) objG)->cbegin();
    }

    // Dtj Dec 10, 2015
//     TODO:
//     I have not changed this part yet. This oart need to be changed,
//     so please look at the old codes and adjust them to the new changes:


    // Point2DPoint2D
//    if (objF->isPoint2D()  && objG->isPoint2D()) {
//        if (objFpoiIterator->isEmpty() && objGpoiIterator->isEmpty()) {
//            object_value = none;
//            status_value = end_of_both;
//        } else {
//            if (objGpoiIterator->isEmpty())
//                object_value = first;
//            else if (objFpoiIterator->isEmpty())
//                object_value = second;
//            else {
//                if (*objFpoiIterator == *objGpoiIterator) {
//                    object_value = both;
//                }
//                status_value = end_of_none;
//            }
//        }
//
//    }



    if (objF->isPoint2D() && objG->isPoint2D()) {

        // TODO: check whether "isEmpty()" useful
        if (objFpoiIterator->isEmpty() && objGpoiIterator->isEmpty()) {
            object_value = none;
            status_value = end_of_both;
        } else {
            status_value = end_of_none;

            // Dtj. Dec 11, 2015
            // Do comparison of the object f and g and set the object value
            // set the object to the smaller Poi2D, if both equal then set object to both
            // this code lines below are the same like in 'selectNext()'.
            // We are using inline codes here for the sake of the readibility:
            // e.g. 'currentFPoi()' will be replaced with '(Poi2D)(**objFpoiIterator)' at compiling time.
            if (currentFPoi() < currentGPoi())
                object_value = first;
            else if (currentFPoi() > currentGPoi())
                object_value = second;
            else if (currentFPoi() == currentGPoi())
                object_value = both;
        }

    }

    if (objF->isPoint2D() && objG->isLine2D()) {

        // TODO: check whether "isEmpty()" useful
        if (objFpoiIterator->isEmpty() && objGsegIterator->isEmpty()) {
            object_value = none;
            status_value = end_of_both;
        } else {
            status_value = end_of_none;

            // Dtj. Dec 11, 2015
            // Do comparison of the object f and g and set the object value
            // set the object to the smaller Poi2D, if both equal then set object to both
            // this code lines below are the same like in 'selectNext()'.
            // We are using inline codes here for the sake of the readibility:
            // e.g. 'currentFPoi()' will be replaced with '(Poi2D)(**objFpoiIterator)' at compiling time.
            Poi2D firstObjectCurrentPoi = currentFPoi();
            HalfSeg2D secondObjectCurrentHalfSegment = currentGSeg();
            if (firstObjectCurrentPoi < secondObjectCurrentHalfSegment)
                object_value = first;
            else if (firstObjectCurrentPoi > secondObjectCurrentHalfSegment)
                object_value = second;
            else if (firstObjectCurrentPoi == secondObjectCurrentHalfSegment)
                object_value = both;
        }

    }

    if (objF->isPoint2D() && objG->isRegion2D()) {

        // TODO: check whether "isEmpty()" useful
        if (objFpoiIterator->isEmpty() && objGregionIterator->isEmpty()) {
            object_value = none;
            status_value = end_of_both;
        } else {
            status_value = end_of_none;

            // Dtj. Dec 11, 2015
            // Do comparison of the object f and g and set the object value
            // set the object to the smaller Poi2D, if both equal then set object to both
            // this code lines below are the same like in 'selectNext()'.
            // We are using inline codes here for the sake of the readibility:
            // e.g. 'currentFPoi()' will be replaced with '(Poi2D)(**objFpoiIterator)' at compiling time.
            Poi2D firstObjectCurrentPoi = currentFPoi();
            AttrHalfSeg2D secondObjectCurrentAttrHalfSeg2D = currentGASeg();
            if (firstObjectCurrentPoi < secondObjectCurrentAttrHalfSeg2D)
                object_value = first;
            else if (firstObjectCurrentPoi > secondObjectCurrentAttrHalfSeg2D)
                object_value = second;
            else if (firstObjectCurrentPoi == secondObjectCurrentAttrHalfSeg2D)
                object_value = both;
        }

    }

    if (objF->isLine2D() && objG->isLine2D()) {

        // TODO: check whether "isEmpty()" useful
        if (objFsegIterator->isEmpty() && objGsegIterator->isEmpty()) {
            object_value = none;
            status_value = end_of_both;
        } else {
            status_value = end_of_none;

            // Dtj. Dec 11, 2015
            // Do comparison of the object f and g and set the object value
            // set the object to the smaller Poi2D, if both equal then set object to both
            // this code lines below are the same like in 'selectNext()'.
            // We are using inline codes here for the sake of the readibility:
            // e.g. 'currentFPoi()' will be replaced with '(Poi2D)(**objFpoiIterator)' at compiling time.
            if (currentFSeg() < currentGSeg())
                object_value = first;
            else if (currentFSeg() > currentGSeg())
                object_value = second;
            else if (currentFSeg() == currentGSeg())
                object_value = both;
        }

    }

    if (objF->isLine2D() && objG->isRegion2D()) {

        // TODO: check whether "isEmpty()" useful
        if (objFsegIterator->isEmpty() && objGregionIterator->isEmpty()) {
            object_value = none;
            status_value = end_of_both;
        } else {
            status_value = end_of_none;

            // Dtj. Dec 11, 2015
            // Do comparison of the object f and g and set the object value
            // set the object to the smaller Poi2D, if both equal then set object to both
            // this code lines below are the same like in 'selectNext()'.
            // We are using inline codes here for the sake of the readibility:
            // e.g. 'currentFPoi()' will be replaced with '(Poi2D)(**objFpoiIterator)' at compiling time.
            HalfSeg2D firstObjectCurrentHalfSegment2D = currentFSeg();
            AttrHalfSeg2D secondObjectCurrentAttrHalfSeg2D = currentGASeg();
            if (firstObjectCurrentHalfSegment2D < secondObjectCurrentAttrHalfSeg2D)
                object_value = first;
            else if (firstObjectCurrentHalfSegment2D > secondObjectCurrentAttrHalfSeg2D)
                object_value = second;
            else if (firstObjectCurrentHalfSegment2D == secondObjectCurrentAttrHalfSeg2D)
                object_value = both;
        }

    }

    if (objF->isRegion2D() && objG->isRegion2D()) {

        // TODO: check whether "isEmpty()" useful
        if (objFregionIterator->isEmpty() && objGregionIterator->isEmpty()) {
            object_value = none;
            status_value = end_of_both;
        } else {
            status_value = end_of_none;

            // Dtj. Dec 11, 2015
            // Do comparison of the object f and g and set the object value
            // set the object to the smaller Poi2D, if both equal then set object to both
            // this code lines below are the same like in 'selectNext()'.
            // We are using inline codes here for the sake of the readibility:
            // e.g. 'currentFPoi()' will be replaced with '(Poi2D)(**objFpoiIterator)' at compiling time.
            if (currentFASeg() < currentGASeg())
                object_value = first;
            else if (currentFASeg() > currentGASeg())
                object_value = second;
            else if (currentFASeg() == currentGASeg())
                object_value = both;
        }

    }
    // DTj TODO: can we take out objFpoiIterator and objGpoiIterator? Like below?
    //    if (objFsegIterator->isEmpty() &&
    //        objGsegIterator->isEmpty() && objFregionIterator->isEmpty() && objGregionIterator->isEmpty()) {

//    if (objFpoiIterator->isEmpty() && objGpoiIterator->isEmpty() && objFsegIterator->isEmpty() &&
//        objGsegIterator->isEmpty() && objFregionIterator->isEmpty() && objGregionIterator->isEmpty()) {
//
//        object_value = none;
//        status_value = end_of_both;
//    }
//    else {
//        if (objGpoiIterator->isEmpty() && objGsegIterator->isEmpty() && objGregionIterator->isEmpty())
//            object_value = first;
//        else if (objFpoiIterator->isEmpty() && objFsegIterator->isEmpty() && objFregionIterator->isEmpty())
//            object_value = second;
//        else
//            object_value = both;

    //TODO: DTj. commented out
//        if ((objFpoiIterator->getCurrent() == ((Point2D *) objF)->cend()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hEnd()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->cend())
//            && ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())))
//            status_value = end_of_both;
//        else if (objFpoiIterator->getCurrent() == ((Point2D *) objF)->cend()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hEnd()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->cend())
//            status_value = end_of_first;
//        else if (objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())
//            status_value = end_of_second;
//        else
//            status_value = end_of_none;
//    }


}

//TODO - see if the return type should be AttrHalfSeg2D or check what it should be
void ParallelObjectTraversal::setNextMin() {

    // TODO: DTj. commented out
    if (objF->isPoint2D()) {
        Poi2D obj11 = currentFPoi();
        Poi2D obj12 = nextFPoi();
        minPoi2DF = new Poi2D();
        if (objG->isPoint2D()) {
            Poi2D obj21 = currentGPoi();
            Poi2D obj22 = nextGPoi();
            minPoi2DG = new Poi2D();
            if (object_value == first)
                (obj12 < obj21 ? *minPoi2DF = obj12 : *minPoi2DG = obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minPoi2DF = obj11 : *minPoi2DG = obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minPoi2DF = obj12 : *minPoi2DG = obj22);
            return;
        }
        if (objG->isLine2D()) {
            minHalfSeg2DG = new HalfSeg2D();
            HalfSeg2D obj21 = currentGSeg();
            HalfSeg2D obj22 = nextGSeg();
            if (object_value == first)
                (obj12 < obj21 ? *minPoi2DF = obj12 : *minHalfSeg2DG = obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minPoi2DF = obj11 : *minHalfSeg2DG = obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minPoi2DF = obj12 : *minHalfSeg2DG = obj22);
            return;
        }
        if (objG->isRegion2D()) {
            AttrHalfSeg2D obj21 = currentGASeg();
            AttrHalfSeg2D obj22 = nextGASeg();
            minAttrHalfSeg2DG = new AttrHalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minPoi2DF = obj12 : *minAttrHalfSeg2DG = obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minPoi2DF = obj11 : *minAttrHalfSeg2DG = obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minPoi2DF = obj12 : *minAttrHalfSeg2DG = obj22);
            return;
        }
    }
    if (objF->isLine2D()) {
        HalfSeg2D obj11 = currentFSeg();
        HalfSeg2D obj12 = nextFSeg();
        minHalfSeg2DF = new HalfSeg2D();
        if (objG->isLine2D()) {
            HalfSeg2D obj21 = currentGSeg();
            HalfSeg2D obj22 = nextGSeg();
            minHalfSeg2DG = new HalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minHalfSeg2DF = obj12 : *minHalfSeg2DG = obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minHalfSeg2DF = obj11 : *minHalfSeg2DG = obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minHalfSeg2DF = obj12 : *minHalfSeg2DG = obj22);
            return;
        }
        if (objG->isRegion2D()) {
            AttrHalfSeg2D obj21 = currentGASeg();
            AttrHalfSeg2D obj22 = nextGASeg();
            minAttrHalfSeg2DG = new AttrHalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minHalfSeg2DF = obj12 : *minAttrHalfSeg2DG = obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minHalfSeg2DF = obj11 : *minAttrHalfSeg2DG = obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minHalfSeg2DF = obj12 : *minAttrHalfSeg2DG = obj22);
            return;
        }
    }
    if (objF->isRegion2D()) {
        AttrHalfSeg2D obj11 = currentFASeg();
        AttrHalfSeg2D obj12 = nextFASeg();
        minAttrHalfSeg2DF = new AttrHalfSeg2D();
        if (objG->isRegion2D()) {
            AttrHalfSeg2D obj21 = currentGASeg();
            AttrHalfSeg2D obj22 = nextGASeg();
            minAttrHalfSeg2DG = new AttrHalfSeg2D();
            if (object_value == first)
                (obj12 < obj21 ? *minAttrHalfSeg2DF = obj12 : *minAttrHalfSeg2DG = obj21);
            if (object_value == second)
                (obj11 < obj22 ? *minAttrHalfSeg2DF = obj11 : *minAttrHalfSeg2DG = obj22);
            if (object_value == both)
                (obj12 < obj22 ? *minAttrHalfSeg2DF = obj12 : *minAttrHalfSeg2DG = obj22);
            return;
        }
    }
    // //TODO: end DTj. commented out




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


    // Dtj implementation of Point2DPoint2D
    // If before this operation object was equal to both, select_next moves forward the logical pointers of both sequences;
    // otherwise, if object was equal to first (second), it only moves forward the logical pointer of the first (second) sequence.
    if (objF->isPoint2D()) {

        // check whether the position of the iterator has not yet reached the end
        if (*objFpoiIterator != ((Point2D *) objF)->cend()) {
            // if object is equal to first or both, increment the F iterator
            if ((object_value == first) || (object_value == both))
                (*objFpoiIterator)++;
        }
        else
            // if it reaches the end, set the status accordingly
            status_value = end_of_first;
    }

    if (objG->isPoint2D()) {
        // check whether the position of the iterator has not yet reached the end
        if (*objGpoiIterator != ((Point2D *) objG)->cend()) {
            // if object is equal to second or both, increment the G iterator
            if ((object_value == second) || (object_value == both))
                (*objGpoiIterator)++;
        }
        else
            // if it reaches the end, set the status accordingly but only not end_of_first
            // otherwise, both has ended!
        if (status_value != end_of_first)
            status_value = end_of_second;
        else status_value = end_of_both;
    }
    if (objF->isLine2D()) {

        // check whether the position of the iterator has not yet reached the end
        if (*objFsegIterator != ((Line2DImpl *) objF)->hEnd()) {
            // if object is equal to first or both, increment the F iterator
            if ((object_value == first) || (object_value == both))
                (*objFsegIterator)++;
        }
        else
            // if it reaches the end, set the status accordingly
            status_value = end_of_first;
    }

    if (objG->isLine2D()) {
        // check whether the position of the iterator has not yet reached the end
        if (*objGsegIterator != ((Line2DImpl *) objG)->hEnd()) {
            // if object is equal to second or both, increment the G iterator
            if ((object_value == second) || (object_value == both))
                (*objGsegIterator)++;
        }
        else
            // if it reaches the end, set the status accordingly but only not end_of_first
            // otherwise, both has ended!
        if (status_value != end_of_first)
            status_value = end_of_second;
        else status_value = end_of_both;
    }

    if (objF->isRegion2D()) {

        // check whether the position of the iterator has not yet reached the end
        if (*objFregionIterator != ((Region2DImpl *) objF)->cend()) {
            // if object is equal to first or both, increment the F iterator
            if ((object_value == first) || (object_value == both))
                (*objFregionIterator)++;
        }
        else
            // if it reaches the end, set the status accordingly
            status_value = end_of_first;
    }

    if (objG->isRegion2D()) {
        // check whether the position of the iterator has not yet reached the end
        if (*objGregionIterator != ((Region2DImpl *) objG)->cend()) {
            // if object is equal to second or both, increment the G iterator
            if ((object_value == second) || (object_value == both))
                (*objGregionIterator)++;
        }
        else
            // if it reaches the end, set the status accordingly but only not end_of_first
            // otherwise, both has ended!
        if (status_value != end_of_first)
            status_value = end_of_second;
        else status_value = end_of_both;
    }

    // do comparison of the object f and g and set the object value
    if (status_value == end_of_none) {
        if (objF->isPoint2D() && objG->isPoint2D()) {

            // set the object to the smaller Poi2D, if both equal then set object to both
            if (currentFPoi() < (currentGPoi()))
                object_value = first;
            else if (currentFPoi() > currentGPoi())
                object_value = second;
            else if (currentFPoi() == currentGPoi())
                object_value = both;
        }
        if (objF->isPoint2D() && objG->isLine2D()) {

            // set the object to the smaller Poi2D, if both equal then set object to both
            Poi2D firstObjectCurrentPoi = currentFPoi();
            HalfSeg2D secondObjectCurrentHalfSegment = currentGSeg();

            if (firstObjectCurrentPoi < secondObjectCurrentHalfSegment)
                object_value = first;
            else if (firstObjectCurrentPoi > secondObjectCurrentHalfSegment)
                object_value = second;
            else if (firstObjectCurrentPoi == secondObjectCurrentHalfSegment)
                object_value = both;
        }
        if (objF->isPoint2D() && objG->isRegion2D()) {

            // set the object to the smaller Poi2D, if both equal then set object to both
            Poi2D firstObjectCurrentPoi = currentFPoi();
            AttrHalfSeg2D secondObjectCurrentAttrHalfSegment = currentGASeg();

            if (firstObjectCurrentPoi < secondObjectCurrentAttrHalfSegment)
                object_value = first;
            else if (firstObjectCurrentPoi > secondObjectCurrentAttrHalfSegment)
                object_value = second;
            else if (firstObjectCurrentPoi == secondObjectCurrentAttrHalfSegment)
                object_value = both;
        }
        if (objF->isLine2D() && objG->isLine2D()) {

            // set the object to the smaller Poi2D, if both equal then set object to both
            if (currentFSeg() < (currentGSeg()))
                object_value = first;
            else if (currentFSeg() > currentGSeg())
                object_value = second;
            else if (currentFSeg() == currentGSeg())
                object_value = both;
        }
        if (objF->isLine2D() && objG->isRegion2D()) {

            // set the object to the smaller Poi2D, if both equal then set object to both
            HalfSeg2D firstObjectCurrentHalfSegment2D = currentFSeg();
            AttrHalfSeg2D secondObjectCurrentAttrHalfSeg2D = currentGASeg();

            if (firstObjectCurrentHalfSegment2D < secondObjectCurrentAttrHalfSeg2D)
                object_value = first;
            else if (firstObjectCurrentHalfSegment2D > secondObjectCurrentAttrHalfSeg2D)
                object_value = second;
            else if (firstObjectCurrentHalfSegment2D == secondObjectCurrentAttrHalfSeg2D)
                object_value = both;
        }
        if (objF->isRegion2D() && objG->isRegion2D()) {

            // set the object to the smaller Poi2D, if both equal then set object to both
            if (currentFASeg() < (currentGASeg()))
                object_value = first;
            else if (currentFASeg() > currentGASeg())
                object_value = second;
            else if (currentFASeg() == currentGASeg())
                object_value = both;
        }
    }


    //TODO: DTj. commented out, to be deleted later
//    if (object_value == both) {
//        if (objF->isPoint2D()) {
//            objFpoiIterator++;
//        }
//        else if (objF->isLine2D()) {
//            objFsegIterator++;
//        }
//        else if (objF->isRegion2D()) {
//            objFregionIterator++;
//        }
//        if (objG->isPoint2D()) {
//            objGpoiIterator++;
//        }
//        else if (objG->isLine2D()) {
//            objGsegIterator++;
//        }
//        else if (objG->isRegion2D()) {
//            objGregionIterator++;
//        }
////        objFIterator++;
////        objGIterator++;
//    } else if (object_value == first) {
//        if (objF->isPoint2D()) {
//            objFpoiIterator++;
//        }
//        else if (objF->isLine2D()) {
//            objFsegIterator++;
//        }
//        else if (objF->isRegion2D()) {
//            objFregionIterator++;
//        }
//        // objFIterator++;
//    } else if (object_value == second) {
//        if (objG->isPoint2D()) {
//            objGpoiIterator++;
//        }
//        else if (objG->isLine2D()) {
//            objGsegIterator++;
//        }
//        else if (objG->isRegion2D()) {
//            objGregionIterator++;
//        }
//        // objGIterator++;
//    } else if (object_value == none) {
//        // Because if both objects elements are over, don't update object and
//        // status variables or object pointers.
//        return;
//    }

    //TODO: DTj. commented out
////TODO define getCurrent() and getNext() for ObjectIterators
//    if ((objFpoiIterator->getCurrent() == ((Point2D *) objF)->cend()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hEnd()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->cend())) {
//        if ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())) {
//            status_value = end_of_both;
//        }
//        else {
//            status_value = end_of_first;
//        }
//    } else if ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->cend()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hEnd()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->cend())) {
//        status_value = end_of_second;
//    } else {
//        status_value = end_of_none;
//    }
//
//
//    if ((objFpoiIterator->getCurrent() == ((Point2D *) objF)->ctail()||objFsegIterator->getCurrent()== ((Line2DImpl *) objF)->hTail()||objFregionIterator->getCurrent()==((Region2DImpl *)objF)->ctail()) && ((objGpoiIterator->getCurrent() == ((Point2D *)objG)->ctail()||objGsegIterator->getCurrent()== ((Line2DImpl *)objG)->hTail()||objGregionIterator->getCurrent()==((Region2DImpl *)objG)->ctail()))) {
//        object_value = none;
//    } else if ((objFpoiIterator->getCurrent() == objGpoiIterator->getCurrent())||(objFsegIterator->getCurrent()==objGsegIterator->getCurrent())||(objFregionIterator->getCurrent()==objGregionIterator->getCurrent())) {
//        object_value = both;
//    } else if ((objFpoiIterator->getCurrent() < objGpoiIterator->getCurrent())||(objFsegIterator->getCurrent()<objGsegIterator->getCurrent())||(objFregionIterator->getCurrent()<objGregionIterator->getCurrent())) {
//        object_value = first;
//    } else if ((objFpoiIterator->getCurrent() > objGpoiIterator->getCurrent())||(objFsegIterator->getCurrent()>objGsegIterator->getCurrent())||(objFregionIterator->getCurrent()>objGregionIterator->getCurrent())) {
//        object_value = second;
//    }
}

Poi2D *ParallelObjectTraversal::getNextPoi2DMin() {
    if (minPoi2DF != nullptr && minPoi2DG != nullptr) {
        if (*minPoi2DF < *minPoi2DG) {
            return minPoi2DF;
        }
        else {
            return minPoi2DG;
        }
    }
    else if (minPoi2DF != nullptr) {
        return minPoi2DF;
    }
    else if (minPoi2DG != nullptr) {
        return minPoi2DG;
    }
    return nullptr;
}

HalfSeg2D *ParallelObjectTraversal::getNextHalfSeg2DMin() {
    if (minHalfSeg2DF != nullptr && minHalfSeg2DG != nullptr) {
        if (*minHalfSeg2DF < *minHalfSeg2DG) {
            return minHalfSeg2DF;
        }
        else {
            return minHalfSeg2DG;
        }
    }
    else if (minHalfSeg2DF != nullptr) {
        return minHalfSeg2DF;
    }
    else if (minHalfSeg2DG != nullptr) {
        return minHalfSeg2DG;
    }
    return nullptr;
}

AttrHalfSeg2D *ParallelObjectTraversal::getNextAttrHalfSeg2DMin() {
    if (minAttrHalfSeg2DF != nullptr && minAttrHalfSeg2DG != nullptr) {
        if (*minAttrHalfSeg2DF < *minAttrHalfSeg2DG) {
            return minAttrHalfSeg2DF;
        }
        else {
            return minAttrHalfSeg2DG;
        }
    }
    else if (minAttrHalfSeg2DF != nullptr) {
        return minAttrHalfSeg2DF;
    }
    else if (minAttrHalfSeg2DG != nullptr) {
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

//TODO: DTj. commented out
Point2D::ConstPoiIterator *ParallelObjectTraversal::getPoiObjIterator(object objectparam) {
    if (objectparam == first) {
        return objFpoiIterator;
    }
    else if (objectparam == second) {
        return objGpoiIterator;
    }
    return nullptr;
}

//TODO: DTj. commented out
Line2DImpl::ConstHalfSegIterator *ParallelObjectTraversal::getHalfSegIterator(object objectparam) {
    if (objectparam == first) {
        return objFsegIterator;
    }
    else if (objectparam == second) {
        return objGsegIterator;
    }
    return nullptr;
}

//TODO: DTj. commented out
Region2DImpl::ConstAttributedHalfSegmentIterator *ParallelObjectTraversal::getAttrHalfSegIterator(object objectparam) {
    if (objectparam == first) {
        return objFregionIterator;
    }
    else if (objectparam == second) {
        return objGregionIterator;
    }
    return nullptr;
}


//TODO: for next 6 functions- get ideal iterators
////TODO obji does not work with simple ++ for next 6 functions

bool ParallelObjectTraversal::isInObjF(Seg2D &seg2D) {
    //ObjectIterator obji;
    if (objF->isLine2D()) {
        Line2DImpl::ConstHalfSegIterator obji;
        for (obji = ((Line2DImpl *) objF)->hBegin(); obji <= ((Line2DImpl *) objF)->hEnd(); obji++) {

            //Line2DImpl::ConstSegIterator val = dynamic_cast<Line2DImpl::ConstSegIterator>(obji);
            HalfSeg2D iter = *(obji);
            if (seg2D == iter.seg) {
                return true;
            }
        }
    }
    else if (objF->isRegion2D()) {
        Region2DImpl::ConstAttributedHalfSegmentIterator obji;
        for (obji = ((Region2DImpl *) objF)->cbegin(); obji <= ((Region2DImpl *) objF)->cend(); obji++) {
            AttrHalfSeg2D iter = *(obji);
            if (seg2D == iter.hseg.seg) {
                return true;
            }
        }

    }

    return false;
}

bool ParallelObjectTraversal::isInObjG(Seg2D &seg2D) {
    //ObjectIterator obji;
    if (objG->isLine2D()) {
        Line2DImpl::ConstHalfSegIterator obji;
        for (obji = ((Line2DImpl *) objG)->hBegin(); obji <= ((Line2DImpl *) objG)->hEnd(); obji++) {

            HalfSeg2D iter = *(obji);
            if (seg2D == iter.seg) {
                return true;
            }
        }
    }
    else if (objG->isRegion2D()) {
        Region2DImpl::ConstAttributedHalfSegmentIterator obji;
        for (obji = ((Region2DImpl *) objG)->cbegin(); obji <= ((Region2DImpl *) objG)->cend(); obji++) {
            AttrHalfSeg2D iter = *(obji);
            if (seg2D == iter.hseg.seg) {
                return true;
            }
        }

    }
    return false;
}


//TODO: DTj. commented out
Line2DImpl::ConstHalfSegIterator *ParallelObjectTraversal::getNextObjIterator(HalfSeg2D halfSeg2D, object objectparam) {
    Line2DImpl::ConstHalfSegIterator *obji;
    if (objectparam == first) {
        if (objF->isLine2D()) {
            for (*obji = ((Line2DImpl *) objF)->hBegin(); *obji <= ((Line2DImpl *) objF)->hEnd(); (*obji)++) {
                HalfSeg2D iter = *(*obji);
                if (halfSeg2D == iter) {
                    if ((status_value != end_of_first) && (status_value != end_of_both)) {
                        (*obji)++;
                        Line2DImpl::ConstHalfSegIterator *result = obji;
                        return result;
                    }
                }

            }
        }
        return nullptr;
    }
    if (objectparam == second) {
        if (objG->isLine2D()) {
            for (*obji = ((Line2DImpl *) objG)->hBegin(); *obji <= ((Line2DImpl *) objG)->hEnd(); (*obji)++) {

                HalfSeg2D iter = *(*obji);
                if (halfSeg2D == iter) {
                    if ((status_value != end_of_second) && (status_value != end_of_both)) {
                        (*obji)++;
                        Line2DImpl::ConstHalfSegIterator *result = obji;
                        return result;
                    }
                }
            }
        }
        return nullptr;
    }
}

//TODO: DTj. commented out
Region2DImpl::ConstAttributedHalfSegmentIterator *ParallelObjectTraversal::getNextObjIterator(
        AttrHalfSeg2D attrhalfSeg2D, object objectparam) {
    Region2DImpl::ConstAttributedHalfSegmentIterator *obji;
    if (objectparam == first) {
        if (objF->isRegion2D()) {
            for (*obji = ((Region2DImpl *) objF)->cbegin(); *obji <= ((Region2DImpl *) objF)->cend(); (*obji)++) {

                AttrHalfSeg2D iter = *(*obji);
                if (attrhalfSeg2D == iter) {
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
        if (objG->isRegion2D()) {
            for (*obji = ((Region2DImpl *) objG)->cbegin(); *obji <= ((Region2DImpl *) objG)->cend(); (*obji)++) {

                AttrHalfSeg2D iter = *(*obji);
                if (attrhalfSeg2D == iter) {
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
    if (object2D == (*objF)) {
        return true;
    }
    else {
        return false;
    }
}

bool ParallelObjectTraversal::isObjectG(Object2D object2D) {
    if (object2D == (*objG)) {
        return true;
    }
    else {
        return false;
    }
}

Object2D ParallelObjectTraversal::getObjF() {
    return *objF;
}

Object2D ParallelObjectTraversal::getObjG() {
    return *objG;
}

Poi2D *ParallelObjectTraversal::getMinPoi2DF() {
    return minPoi2DF;
}

Poi2D *ParallelObjectTraversal::getMinPoi2DG() {
    return minPoi2DG;
}

HalfSeg2D *ParallelObjectTraversal::getMinHalfSeg2DF() {
    return minHalfSeg2DF;
}

HalfSeg2D *ParallelObjectTraversal::getMinHalfSeg2DG() {
    return minHalfSeg2DG;
}

AttrHalfSeg2D *ParallelObjectTraversal::getMinAttrHalfSeg2DF() {
    return minAttrHalfSeg2DF;
}

AttrHalfSeg2D *ParallelObjectTraversal::getMinAttrHalfSeg2DG() {
    return minAttrHalfSeg2DG;
}

// setter methods
void ParallelObjectTraversal::setObject(const object &object_value) {
    ParallelObjectTraversal::object_value = object_value;
}

void ParallelObjectTraversal::setStatus(const status &status_value) {
    ParallelObjectTraversal::status_value = status_value;
}
