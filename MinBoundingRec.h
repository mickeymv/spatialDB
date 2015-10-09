#pragma once

#include "Seg2D.h"
class MinBoundingRec
{
public:
	MinBoundingRec();
	~MinBoundingRec();
	MinBoundingRec(Seg2D& operand);
	PoiR2D p1;
	PoiR2D p2;
	PoiR2D p3;
	PoiR2D p4;
};

