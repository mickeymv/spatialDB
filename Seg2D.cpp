#include "Seg2D.h"


Seg2D::Seg2D()
{
	this->p1 = PoiR2D(0, 0);
	this->p2 = PoiR2D(1, 1);
}

Seg2D::Seg2D(PoiR2D p1, PoiR2D p2)
{
	this->p1 = p1;
	this->p2 = p2;
	if (p1 > p2)
	{
		this->LeftHalfSegment = HalfSegment(p1, false);
		this->RightHalfSegment = HalfSegment(p2, true);
	}
	else
	{
		this->LeftHalfSegment = HalfSegment(p2, false);
		this->RightHalfSegment = HalfSegment(p1, true);
	}
}

Seg2D::~Seg2D()
{
}


HalfSegment Seg2D::GetLeftHalfSegment()
{
	return LeftHalfSegment;
}
HalfSegment Seg2D::GetRightHalfSegment()
{
	return LeftHalfSegment;
}


bool Seg2D::Intersects(const Seg2D& segment)
{
	return true;
}
PoiR2D Seg2D::IntersectionPoint(const Seg2D& segment)
{
	return PoiR2D(0.0, 0.0);
}
bool Seg2D::Meets(const Seg2D& segment)
{
	return true;
}
PoiR2D Seg2D::MeetingPoint(const Seg2D& segment)
{
	return PoiR2D(0.0, 0.0);
}


