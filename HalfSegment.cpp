#include "HalfSegment.h"


HalfSegment::HalfSegment()
{
	this->dominatingPoint = PoiR2D(0.0, 0.0);
	this->direction = true;
}


HalfSegment::~HalfSegment()
{
}

HalfSegment::HalfSegment(PoiR2D dominatingPoint, bool direction)
{
	this->dominatingPoint = dominatingPoint;
	this->direction = direction;
}

bool HalfSegment::Left(HalfSegment& operand)
{
	return true;
}

bool HalfSegment::Right(HalfSegment& operand)
{
	return true;
}