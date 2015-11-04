//
// Created by Djundi on 11/3/15.
//

#include "POT.h"

#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"

//using namespace std;

IPOT::object IPOT::getObject() {
    object temp;  // temporary, to be replaced
    return temp;

};
IPOT::status IPOT::getStatus()
{
    status temp;  // temporary, to be replaced
    return temp;
};


void IPOT::select_first(){
    // select the f, g
    // value witll be updated: status and object
    // implement here...
};

void IPOT::select_next(){
    // select the f, g
    // value witll be updated: status and object
    // implement here...
};

POT_Point2DPoint2D::POT_Point2DPoint2D(Object2D &F, Object2D &G) : IPOT() {
    F.set(fObj);
    G.set(gObj);

};

POT_Point2DPoint2D::~POT_Point2DPoint2D(){};

void POT_Point2DPoint2D::select_first() {

};

void POT_Point2DPoint2D::select_next() {

};