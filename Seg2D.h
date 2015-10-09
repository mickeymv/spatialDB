#pragma once

#include "PoiR2D.h"
#include "HalfSegment.h"

//class PoiR2D;

class Seg2D
{
public:
	Seg2D();
	Seg2D(PoiR2D p1, PoiR2D p2);
	~Seg2D();

	HalfSegment GetLeftHalfSegment();
	HalfSegment GetRightHalfSegment();

	bool Intersects(const Seg2D& segment);
	PoiR2D IntersectionPoint(const Seg2D& segment);
	bool Meets(const Seg2D& segment);
	PoiR2D MeetingPoint(const Seg2D& segment); 
private:
	PoiR2D p1;
	PoiR2D p2;
	HalfSegment LeftHalfSegment;
	HalfSegment RightHalfSegment;
};
