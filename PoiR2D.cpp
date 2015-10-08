#include "PoiR2D.h"

PoiR2D::PoiR2D()
{
	this->x = BigRational(0.0);
	this->y = BigRational(0.0);
}

PoiR2D::PoiR2D(BigRational x, BigRational y)
{
	this->x = x;
	this->y = y;
}

PoiR2D::~PoiR2D()
{
}

/* logical operators */
bool PoiR2D::operator<(const PoiR2D& operand)
{
	return true;
}

bool PoiR2D::operator>(const PoiR2D& operand)
{
	return true;
}

bool PoiR2D::operator<=(const PoiR2D& operand)
{
	return true;
}

bool PoiR2D::operator>=(const PoiR2D& operand)
{
	return true;
}

bool PoiR2D::operator==(const PoiR2D& operand)
{
	return true;
}

bool PoiR2D::operator!=(const PoiR2D& operand)
{
	return true;
}

/* predicates */
bool LiesOnSegment(const Seg2D& segment)
{
	return true;
}

