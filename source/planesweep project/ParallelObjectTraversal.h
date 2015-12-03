//
// Created by Djundi on 11/3/15.
//

#ifndef PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H
#define PLANESWEEP_PROJECT_PARALLELOBJECTTRAVERSAL_H

#include <memory>

#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic1/RobustGeometricPrimitives2D.h"
#include "Region2D.h"

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
	AttrHalfSeg2D getNextMin();

    bool isObjectF(Object2D);
    bool isObjectG(Object2D);

    ObjectIterator *getNextObjIterator(HalfSeg2D,object);
    ObjectIterator *getNextObjIterator(AttrHalfSeg2D,object);

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

    Poi2D getEvent(object objectEnumVal);

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
