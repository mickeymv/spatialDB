#include "MinBoundingRec.h"


MinBoundingRec::MinBoundingRec()
{
	this->p1 = PoiR2D();
	this->p2 = PoiR2D();
	this->p3 = PoiR2D();
	this->p4 = PoiR2D();
}

MinBoundingRec::MinBoundingRec(Seg2D& operand)
{
	//do the segment magic here 
	this->p1 = PoiR2D();
	this->p2 = PoiR2D();
	this->p3 = PoiR2D();
	this->p4 = PoiR2D();
}


MinBoundingRec::~MinBoundingRec()
{
}
