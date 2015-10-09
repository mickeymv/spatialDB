#include "AttrHalfSegment.h"


AttrHalfSegment::AttrHalfSegment() :HalfSegment()
{
	this->regionInOut = true;
}

AttrHalfSegment::AttrHalfSegment(bool value, bool direction, PoiR2D dominatingPoint) : HalfSegment(dominatingPoint,direction)
{
	this->regionInOut = value;
}

AttrHalfSegment::~AttrHalfSegment()
{
}
