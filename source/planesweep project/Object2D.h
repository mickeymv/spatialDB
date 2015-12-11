//
// Created by Djundi on 11/3/15.
//

#ifndef PLANESWEEP_PROJECT_OBJECT2D_H
#define PLANESWEEP_PROJECT_OBJECT2D_H

#include <memory>
#include <typeinfo>

#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Topic2/Implementation/Region2D.h"


// 11/03/2015 DT
// since we do not have any base (super) class for the spatial objects, we use this template
// class Object2D is the base template class for the F and G objects

/**This is a pure virtual class/ abstract base class/Interface class which will have no objects of its own.
* It's upto the derived classes; Poi, Line and Region2D to have definitions for
* the methods in this class.
*/

class Object2D {

public:

    Object2D();

    ~Object2D();

//    ObjectIterator cbegin() const;
//
//    ObjectIterator cend() const;
//
//    ObjectIterator chead() const;
//
//    ObjectIterator ctail() const;

    bool operator == (Object2D& operand);

    bool isPoint2D();

    bool isLine2D();

    bool isRegion2D();

};


#endif //PLANESWEEP_PROJECT_OBJECT2D_H
