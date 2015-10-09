#pragma once

#include "PoiR2D.h"

//class PoiR2D;
class HalfSegment
{
public:
	HalfSegment();
	HalfSegment(PoiR2D dominatingPoint, bool direction);
	~HalfSegment();
	bool Left(HalfSegment& operand);
	bool Right(HalfSegment& operand);
private:
	PoiR2D dominatingPoint;
	bool direction;
};

