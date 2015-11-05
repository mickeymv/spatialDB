//
// Created by Djundi on 11/3/15.
//

#ifndef SPATIAL_PREDICATES_POT_H
#define SPATIAL_PREDICATES_POT_H

#include "Object2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Line2D.h"
#include "Region2D.h"



// since we do not have any base class for the spatial objects, we use template class
// class spatial2DObj is the base template class for the F and G objects


// class IPOT is the base class for the POT implementation
// it should contain all the basic stuffs for POT, but each of the spatial object combination can overide or add any needed methods
class IPOT {

public:
    IPOT() {
        // create vF and vG and initialize them with false ???
    }
//    IPOT(Object2D &F, Object2D &G) {
//        // create vF and vG and initialize them with false.
//    };


    virtual ~IPOT(){};

    virtual void select_first();
    virtual void select_next();


    // here we declare all enums we need that can be shared for all spatial object combinations,
    // we declare specific enums only within the respective child classes
    typedef enum  {
        none, first, second, both
    } object;

    typedef enum  {
        end_of_none, end_of_first, end_of_second, end_of_both
    } status;

    virtual object getObject();
    virtual status getStatus();


private:
//    Object2D * objF;
//    Object2D * objG;
    // declare vector vF
    // declare vector vG



};

// *** begin test temp
class POT_Test2DPoint2D : public IPOT {

public:
    POT_Test2DPoint2D(Object2D &F, Object2D &G) {
        F.set(fObj);
        G.set(gObj);
    }
    virtual ~POT_Test2DPoint2D() {}
    virtual void select_first() {}
    virtual void select_next() {}

    const int &getFoo(unsigned int index) const {
        return fObj.getFoo(index);
    }

private:
    Test2D fObj;
    Point2D gObj;

};
// *** end test temp

class POT_Point2DPoint2D : public IPOT {

public:
    POT_Point2DPoint2D(Object2D &, Object2D &);
    virtual ~POT_Point2DPoint2D();
    virtual void select_first();
    virtual void select_next();

    // declare required predicates for Point2D/Point2D
    // ...

private:
    Point2D fObj, gObj;

};


class POT_Point2DLine2D : public IPOT {

public:
    POT_Point2DLine2D(Object2D &, Object2D &) {}
    virtual ~POT_Point2DLine2D() {}
    virtual void select_first() {}
    virtual void select_next() {}

    // declare required predicates for Point2D/POT_Point2DLine2D
    // ...
};

class POT_Point2DRegion2D : public IPOT {

public:
    POT_Point2DRegion2D(Object2D &, Object2D &) {}
    virtual ~POT_Point2DRegion2D() {}
    virtual void select_first() {}
    virtual void select_next() {}

    // declare required predicates for Line2DLine2D
    // ...
};


class POT_Line2DLine2D : public IPOT {

public:
    POT_Line2DLine2D(Object2D &, Object2D &){}
    virtual ~POT_Line2DLine2D() {}
    virtual void select_first() {}
    virtual void select_next() {}

    // declare required predicates for Line2DLine2D
    // ...
};


class POT_Line2DRegion2D : public IPOT {

public:
    POT_Line2DRegion2D(Object2D &, Object2D &) {}
    virtual ~POT_Line2DRegion2D() {}
    virtual void select_first() {}
    virtual void select_next() {}

    // declare required predicates for Line2DLine2D
    // ...
};



class POT_Region2DRegion2D : public IPOT {

public:
    POT_Region2DRegion2D(Object2D &, Object2D &) {}
    virtual ~POT_Region2DRegion2D() {}
    virtual void select_first() {}
    virtual void select_next() {}

    // declare required predicates for Line2DLine2D
    // ...
};


#endif //SPATIAL_PREDICATES_POT_H
