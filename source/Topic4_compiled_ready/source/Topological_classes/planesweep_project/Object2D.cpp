//
// Created by Djundi on 11/3/15.
//

#include "Object2D.h"
#include "Topic2/Implementation/Region2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"


// Equal operator that checks if the Object2D object and the operand Object2D are the same
bool Object2D::operator == (const Object2D& operand)const {
    if(this==&operand)
        return true;
    else
        return false;
}

bool Object2D::isPoint2D() const
{
 if(dynamic_cast<const Point2D*>(this))
 {
     return true;
 }
 else
 {
     return false;
 }
//    if(typeid(*this)== typeid(const Point2D))
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
}

bool Object2D::isLine2D() const
{

    if(dynamic_cast<const Line2D*>(this))
    {
        return true;
    }
    else
    {
        return false;
    }
//    if(typeid(*this)== typeid(const Line2D))
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
}

bool Object2D::isRegion2D() const
{
    if(dynamic_cast<const Region2D*>(this))
    {
        return true;
    }
    else
    {
        return false;
    }
//    if(typeid(*this)== typeid(const Region2D))
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
}
