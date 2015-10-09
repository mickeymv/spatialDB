#pragma once
#include "HalfSegment.h"
class AttrHalfSegment :
	public HalfSegment
{
public:
	AttrHalfSegment();
	AttrHalfSegment(bool value, bool direction, PoiR2D dominatingPoint);
	~AttrHalfSegment();

private: 
	bool regionInOut;
};

