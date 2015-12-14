
#include "RobustGeometricPrimitives2D.h"
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

/*Poi2D*/

Poi2D::Poi2D()
{
	this->x = Number("0.0");
	this->y = Number("0.0");
}

Poi2D::Poi2D(const Number& x, const Number& y)
{
	this->x = x;
	this->y = y;
}

Poi2D::Poi2D(const Poi2D& obj)
{
	this->x = obj.x;
	this->y = obj.y;
}

Poi2D::Poi2D(Poi2D&& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	obj.x = Number("0.0");
	obj.y = Number("0.0");
}

Poi2D Poi2D::operator = (const Poi2D& obj)
{
	if (this != &obj)
	{
		this->x = obj.x;
		this->y = obj.y;
	}
	return *this;
}

Poi2D Poi2D::operator = (Poi2D&& obj)
{
	if (this != &obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		obj.x = Number("0.0");
		obj.y = Number("0.0");
	}
	return *this;
}

Poi2D::~Poi2D()
{

}

/* Poi2D's logical operators */
bool Poi2D::operator < (const Poi2D& operand)
{
	if (this->x < operand.x)
		return true;

	else if (this->x == operand.x && this->y < operand.y)
		return true;
	else
		return false;
}

bool Poi2D::operator >(const Poi2D& operand)
{
	if (this->x > operand.x)
		return true;
	else if (this->x == operand.x && this->y > operand.y)
		return true;
	else
		return false;
}

bool Poi2D::operator == (const Poi2D& operand)
{
	if ((this->x == operand.x) && (this->y == operand.y))
		return true;
	else
		return false;
}

bool Poi2D::operator <= (const Poi2D& operand)
{
	if (this->x < operand.x)
		return true;

	else if (this->x == operand.x && this->y < operand.y)
		return true;

	else if (this->x == operand.x && this->y == operand.y)
		return true;
	else
		return false;
}

bool Poi2D::operator >= (const Poi2D& operand)
{
	if (this->x > operand.x)
		return true;

	else if (this->x == operand.x && this->y > operand.y)
		return true;

	else if (this->x == operand.x && this->y == operand.y)
		return true;
	else
		return false;
}

bool Poi2D::operator != (const Poi2D& operand)
{
	if ((this->x != operand.x) || (this->y != operand.y))
		return true;
	else
		return false;
}
bool Poi2D:: operator < (HalfSeg2D& operand)
{

	if (*(this) < operand.dominatingPoint())
		return true;
	else
		return false;
}
bool Poi2D:: operator > (HalfSeg2D& operand)
{

	if (*(this) > operand.dominatingPoint())
		return true;
	else
		return false;
}
bool Poi2D:: operator < (AttrHalfSeg2D& operand)
{

	if (*(this) < operand.hseg.dominatingPoint())
		return true;
	else
		return false;
}
bool Poi2D:: operator > (AttrHalfSeg2D& operand)
{

	if (*(this) > operand.hseg.dominatingPoint())
		return true;
	else
		return false;
}
std::ostream&operator << (std::ostream& os, const Poi2D& output)
{
	os << "(" << output.x << ", " << output.y << ")";
	return os;
}
std::istream&operator >> (std::istream& is, Poi2D& input)
{
	std::cout << "Enter the x and y coordinates:";
	is >> input.x >> input.y;
	return is;
}

/*Segment*/

Seg2D::Seg2D()
{
	this->p1 = Poi2D();
	this->p2 = Poi2D(Number("0.0"), Number("1.0"));
}
Seg2D::Seg2D(Poi2D p1, Poi2D p2)
{
	if (p1 <= p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}
	else
	{
		this->p1 = p2;
		this->p2 = p1;
	}
}
Seg2D::Seg2D(const Seg2D& obj)
{
	this->p1 = obj.p1;
	this->p2 = obj.p2;
}
Seg2D::Seg2D(Seg2D&& obj)
{
	this->p1 = obj.p1;
	this->p2 = obj.p2;
	obj.p1 = Poi2D();
	obj.p2 = Poi2D(Number("1.0"), Number("1.0"));

}
Seg2D Seg2D::operator = (const Seg2D& obj)
{
	if (this != &obj)
	{
		this->p1 = obj.p1;
		this->p2 = obj.p2;
	}
	return *this;
}
Seg2D Seg2D::operator = (Seg2D&& obj)
{

	if (this != &obj){

		this->p1 = obj.p1;
		this->p2 = obj.p2;

		obj.p1 = Poi2D(Number("0.0"), Number("0.0"));
		obj.p2 = Poi2D(Number("1.0"), Number("1.0"));
	}
	return *this;
}
Seg2D::~Seg2D()
{

}

/*  Seg2D's logical operators */

//Overloading the < operator for segments.
bool Seg2D::operator < (const Seg2D& operand)
{
	if (this->p1 < operand.p1)
		return true;

	else if (this->p1 == operand.p1 && this->p2 < operand.p2)
		return true;

	else
		return false;

}

//Overloading the > operator for segments.
bool Seg2D::operator >(const Seg2D& operand)
{
	if (this->p1 > operand.p1)
		return true;

	else if (this->p1 == operand.p1 && this->p2 > operand.p2)
		return true;

	else
		return false;
}

//Overloading the == operator for segments.
bool Seg2D::operator == (const Seg2D& operand)
{
	if ((this->p2 == operand.p2) && (this->p2 == operand.p2))
		return true;
	else
		return false;
}

//Overloading the <= operator for segments.
bool Seg2D::operator <= (const Seg2D& operand)
{
	if (this->p1 < operand.p1)
		return true;

	else if (this->p1 == operand.p1 && this->p2 < operand.p2)
		return true;

	else if (this->p1 == operand.p1 && this->p2 == operand.p2)
		return true;

	else
		return false;
}

//Overloading the >= operator for segments.
bool Seg2D::operator >= (const Seg2D& operand)
{
	if (this->p1 > operand.p1)
		return true;

	else if (this->p1 == operand.p1 && this->p2 > operand.p2)
		return true;

	else if (this->p1 == operand.p1 && this->p2 == operand.p2)
		return true;
	else
		return false;
}

//Overloading the != operator for segments.
bool Seg2D::operator != (const Seg2D& operand)
{
	if (this->p1 != operand.p1 || this->p2 != operand.p2)
		return true;
	else
		return false;
}

//Overloading the ostream operator for segments.
std::ostream&operator << (std::ostream& os, const Seg2D& output)
{
	os << "Point 1:" << output.p1 << " ,Point 2: " << output.p2;
	return os;
}

//Overloading the instream operator for segments.
std::istream&operator >> (std::istream& is, Seg2D& input)
{
	std::cout << "Enter the coordinates of the Segment: ";
	is >> input.p1 >> input.p2;
	return is;
}

/*Halfsegments*/

HalfSeg2D::HalfSeg2D()
{
	this->isLeft = true;
	this->seg = Seg2D(Poi2D(Number("0.0"), Number("0.0")), Poi2D(Number("1.0"), Number("1.0")));
}

HalfSeg2D::HalfSeg2D(Seg2D seg, bool isLeft)
{
	this->seg = seg;
	this->isLeft = isLeft;
}

HalfSeg2D::HalfSeg2D(const HalfSeg2D& obj)
{
	this->seg = obj.seg;
	this->isLeft = obj.isLeft;
}
HalfSeg2D::HalfSeg2D(HalfSeg2D&& obj)
{
	Seg2D defaultSeg;
	this->seg = obj.seg;
	this->isLeft = obj.isLeft;
	obj.seg = defaultSeg;
	obj.isLeft = true;
}
HalfSeg2D HalfSeg2D::operator = (const HalfSeg2D& obj)
{
	this->seg = obj.seg;
	this->isLeft = obj.isLeft;
	return *this;
}
HalfSeg2D HalfSeg2D::operator = (HalfSeg2D&& obj)
{
	return HalfSeg2D(Seg2D(), true);
}
HalfSeg2D::~HalfSeg2D()
{

}

/* Overloading halfsegment's logical operators */
bool HalfSeg2D::operator < (const HalfSeg2D& operand)
{
	Seg2D seg1 = this->seg;
	Seg2D seg2 = operand.seg;
	Poi2D dominatingPointOfSeg1;
	Poi2D dominatingPointOfSeg2;
	Poi2D nonDominatingPointOfSeg1;
	Poi2D nonDominatingPointOfSeg2;
	
	if (this->isLeft == true)
	{
		dominatingPointOfSeg1 = seg1.p1;
		nonDominatingPointOfSeg1 = seg1.p2;
	}
	
	else
	{
		dominatingPointOfSeg1 = seg1.p2;
		nonDominatingPointOfSeg1 = seg1.p1;
	}

	if (operand.isLeft == true){
		dominatingPointOfSeg2 = seg2.p1;
		nonDominatingPointOfSeg2 = seg2.p2;
	}
	else
	{
		dominatingPointOfSeg2 = seg2.p2;
		nonDominatingPointOfSeg2 = seg2.p1;
	}

	if (dominatingPointOfSeg1 < dominatingPointOfSeg2
		|| (dominatingPointOfSeg1 == dominatingPointOfSeg2 && (!this->isLeft && operand.isLeft))
		|| (this->isLeft == operand.isLeft &&
		(
		(operand.isLeft == true && PointLiesAboveSegment(nonDominatingPointOfSeg2, seg1))
		|| (operand.isLeft == false && PointLiesBelowSegment(nonDominatingPointOfSeg2, seg1))
		)
		)
		|| (this->isLeft == operand.isLeft && SegmentIsCollinearAndMeetsLeftEndpoint(seg1, seg2) && SegmentIsLesserThanSegment(seg1, seg2))
		)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool HalfSeg2D::operator > (const HalfSeg2D& operand)
{
	if (!(*this < operand) && *this != operand)
		return true;
	else 
		return false;
}

bool HalfSeg2D::operator <= (const HalfSeg2D& operand)
{
	Seg2D seg1 = this->seg;
	Seg2D seg2 = operand.seg;
	Poi2D dominatingPointOfSeg1;
	Poi2D dominatingPointOfSeg2;
	Poi2D nonDominatingPointOfSeg1;
	Poi2D nonDominatingPointOfSeg2;

	if (seg1 == seg2 && this->isLeft == operand.isLeft){
		return true;
	}
	else{
		if (this->isLeft == true){
			dominatingPointOfSeg1 = seg1.p1;
			nonDominatingPointOfSeg1 = seg1.p2;
		}
		else
		{
			dominatingPointOfSeg1 = seg1.p2;
			nonDominatingPointOfSeg1 = seg1.p1;
		}

		if (operand.isLeft == true){
			dominatingPointOfSeg2 = seg2.p1;
			nonDominatingPointOfSeg2 = seg2.p2;
		}
		else
		{
			dominatingPointOfSeg2 = seg2.p2;
			nonDominatingPointOfSeg2 = seg2.p1;
		}

		//std::cout << "dominatingPointOfSeg1" << dominatingPointOfSeg1;
		//std::cout << "dominatingPointOfSeg2" << dominatingPointOfSeg2;
		//std::cout << "nonDominatingPointOfSeg1" << nonDominatingPointOfSeg1;
		//std::cout << "nonDominatingPointOfSeg2" << nonDominatingPointOfSeg2;

		if (dominatingPointOfSeg1 < dominatingPointOfSeg2
			|| (dominatingPointOfSeg1 == dominatingPointOfSeg2 && (!this->isLeft && operand.isLeft))
			|| (this->isLeft == operand.isLeft &&
			(
			(operand.isLeft == true && PointLiesAboveSegment(nonDominatingPointOfSeg2, seg1))
			|| (operand.isLeft == false && PointLiesBelowSegment(nonDominatingPointOfSeg2, seg1))
			)
			)
			|| (this->isLeft == operand.isLeft && SegmentIsCollinearAndMeetsLeftEndpoint(seg1, seg2) && SegmentIsLesserThanSegment(seg1, seg2))
			){
			return true;
		}
		else{
			return false;
		}
	}


}
Poi2D HalfSeg2D::dominatingPoint()
{
	if (isLeft == true)
		return seg.p1;
	else
		return seg.p2;
}

bool HalfSeg2D::operator >= (const HalfSeg2D& operand)
{
	if (!(*this < operand))
		return true;
	else
		return false;
}

bool HalfSeg2D::operator == (const HalfSeg2D& operand)
{
	Seg2D seg1 = this->seg;
	Seg2D seg2 = operand.seg;
	if (seg1 == seg2 && this->isLeft == operand.isLeft){
		return true;
	}
	else{
		return false;
	}

}

bool HalfSeg2D::operator != (const HalfSeg2D& operand)
{
	Seg2D seg1 = this->seg;
	Seg2D seg2 = operand.seg;
	if (seg1 != seg2 || this->isLeft != operand.isLeft){
		return true;
	}
	else{
		return false;
	}
}
bool HalfSeg2D :: operator < (Poi2D& operand)
{
	if (this->dominatingPoint() < operand)
		return true;
	else
		return false;
}
bool HalfSeg2D :: operator > (Poi2D& operand)
{
	if (this->dominatingPoint() > operand)
		return true;
	else
		return false;
}
bool HalfSeg2D :: operator <(AttrHalfSeg2D& operand)
{
	if (*(this) < operand.hseg)
		return true;
	else
		return false;
}
bool HalfSeg2D ::operator >(AttrHalfSeg2D& operand)
{

	if (*(this) > operand.hseg)
		return true;
	else
		return false;
}
std::ostream&operator << (std::ostream& os, const HalfSeg2D& output)
{
	os << "\nSegment:" << output.seg << " ,Is Left: " << output.isLeft;
	return os;
}


/*Atrributed Half Segment*/

AttrHalfSeg2D::AttrHalfSeg2D()
{
	this->hseg.isLeft = true;
	this->hseg.seg = Seg2D(Poi2D(Number("0.0"), Number("0.0")), Poi2D(Number("1.0"), Number("1.0")));
	this->insideAbove = true;
}
AttrHalfSeg2D::AttrHalfSeg2D(bool insideabove, bool isLeft, Seg2D seg)
{
	this->insideAbove = insideabove;
	this->hseg.isLeft = isLeft;
	this->hseg.seg = seg;
}
AttrHalfSeg2D::AttrHalfSeg2D(const AttrHalfSeg2D& obj)
{
	this->insideAbove = obj.insideAbove;
	this->hseg.isLeft = obj.hseg.isLeft;
	this->hseg.seg = obj.hseg.seg;
}
AttrHalfSeg2D::AttrHalfSeg2D(AttrHalfSeg2D&& obj)
{
	this->insideAbove = obj.insideAbove;
	this->hseg.isLeft = obj.hseg.isLeft;
	this->hseg.seg = obj.hseg.seg;
	obj.insideAbove = true;
	obj.hseg.seg = Seg2D(Poi2D(Number("0.0"), Number("0.0")), Poi2D(Number("1.0"), Number("1.0")));
	obj.hseg.isLeft = true;
}
AttrHalfSeg2D AttrHalfSeg2D::operator = (const AttrHalfSeg2D& obj)
{
	if (this != &obj)
	{
		this->insideAbove = obj.insideAbove;
		this->hseg.isLeft = obj.hseg.isLeft;
		this->hseg.seg = obj.hseg.seg;
	}
	return *this;
}
AttrHalfSeg2D AttrHalfSeg2D::operator = (AttrHalfSeg2D&& obj)
{
	if (this != &obj)
	{
		this->insideAbove = obj.insideAbove;
		this->hseg.isLeft = obj.hseg.isLeft;
		this->hseg.seg = obj.hseg.seg;

		obj.insideAbove = true;
		obj.hseg.seg = Seg2D(Poi2D(Number("0.0"), Number("0.0")), Poi2D(Number("1.0"), Number("1.0")));
		obj.hseg.isLeft = true;
	}
	return *this;
}
AttrHalfSeg2D::~AttrHalfSeg2D()
{

}

/* Overloading the logical operators of  Attributed halfsegment.*/
bool AttrHalfSeg2D::operator < (const AttrHalfSeg2D& operand)
{
	if (this->hseg < operand.hseg)
		return true;
	else if (this->hseg == operand.hseg && (this->insideAbove == false && operand.insideAbove == true))
		return true;
	else
		return false;
}

bool AttrHalfSeg2D::operator >(const AttrHalfSeg2D& operand)
{

	if (this->hseg > operand.hseg)
		return true;
	else if (this->hseg == operand.hseg && (this->insideAbove == true && operand.insideAbove == false))
		return true;
	else
		return false;
}
bool AttrHalfSeg2D::operator == (const AttrHalfSeg2D& operand)
{
	if (this->hseg == operand.hseg && this->insideAbove == operand.insideAbove)
		return true;
	else
		return false;
}

bool AttrHalfSeg2D::operator <= (const AttrHalfSeg2D& operand)
{

	if (this->hseg < operand.hseg)
		return true;
	else if (this->hseg == operand.hseg && (this->insideAbove == false && operand.insideAbove == true))
		return true;
	else if (this->hseg == operand.hseg && this->insideAbove == operand.insideAbove)
		return true;
	else
		return false;
}

bool AttrHalfSeg2D::operator >= (const AttrHalfSeg2D& operand)
{
	if (this->hseg > operand.hseg)
		return true;
	else if (this->hseg == operand.hseg && (this->insideAbove == true && operand.insideAbove == false))
		return true;
	else if (this->hseg == operand.hseg && this->insideAbove == operand.insideAbove)
		return true;
	else
		return true;
}

bool AttrHalfSeg2D::operator != (const AttrHalfSeg2D& operand)
{
	if (this->hseg != operand.hseg || this->insideAbove != operand.insideAbove)
		return true;
	else
		return false;
}
bool AttrHalfSeg2D::operator <(Poi2D& operand)
{
	if (this->hseg.dominatingPoint() < operand)
		return true;
	else
		return false;
}
bool AttrHalfSeg2D:: operator >(Poi2D& operand)
{
	if (this->hseg.dominatingPoint() > operand)
		return true;
	else
		return false;
}
bool AttrHalfSeg2D::operator <(HalfSeg2D& operand)
{
	if (this->hseg < operand)
		return true;
	else
		return false;
}
bool AttrHalfSeg2D::operator >(HalfSeg2D& operand)
{
	if (this->hseg > operand)
		return true;
	else
		return false;
}
std::ostream&operator << (std::ostream& os, const AttrHalfSeg2D& output)
{
	os << "\nSegment:" << output.hseg.seg << " ,Is Left: " << output.hseg.isLeft << " ,Inside above:" << output.insideAbove;
	return os;
}
/*Minimum Bounding Rectangle*/
Rect2D::Rect2D()
{
	this->topLeft = Poi2D(Number("0.0"), Number("1.0"));
	this->bottomRight = Poi2D(Number("1.0"), Number("0.0"));
}
Rect2D::Rect2D(Poi2D p1, Poi2D p2)
{
	this->topLeft = p1;
	this->bottomRight = p2;
}

Rect2D::Rect2D(const Rect2D& obj)
{
	this->topLeft = obj.topLeft;
	this->bottomRight = obj.bottomRight;
}
Rect2D::Rect2D(Rect2D&& obj)
{
	this->topLeft = obj.topLeft;
	this->bottomRight = obj.bottomRight;
	obj.topLeft = Poi2D(Number("0.0"), Number("1.0"));
	obj.bottomRight = Poi2D(Number("1.0"), Number("0.0"));
}
Rect2D Rect2D::operator = (const Rect2D& obj)
{
	if (this != &obj)
	{
		this->topLeft = obj.topLeft;
		this->bottomRight = obj.bottomRight;
	}
	return *this;
}
Rect2D Rect2D::operator = (Rect2D&& obj)
{
	if (this != &obj)
	{
		this->topLeft = obj.topLeft;
		this->bottomRight = obj.bottomRight;
		obj.topLeft = Poi2D(Number("0.0"), Number("1.0"));
		obj.bottomRight = Poi2D(Number("1.0"), Number("0.0"));
	}
	return *this;
}
Rect2D::~Rect2D()
{


}

std::ostream&operator << (std::ostream& os, Rect2D& output)
{
	os << "topLeft: " << output.topLeft << "\nbottomRight: " << output.bottomRight;
	return os;
}

std::istream&operator >> (std::istream& is, Rect2D& input)
{
	std::cout << "Enter the topLeft and bottomRight:";
	is >> input.topLeft >> input.bottomRight;
	return is;
}

/* Simple Polygon2D */

SimplePolygon2D::SimplePolygon2D()
{
}
SimplePolygon2D::SimplePolygon2D(std::vector<Poi2D> vertices)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		this->vertices.push_back(vertices[i]);
	}
}
SimplePolygon2D::SimplePolygon2D(const SimplePolygon2D& obj)
{
	for (int i = 0; i < obj.vertices.size(); i++)
	{
		this->vertices.push_back(obj.vertices[i]);
	}
}
SimplePolygon2D::SimplePolygon2D(SimplePolygon2D&& obj)
{
	Poi2D defaultPoint;
	for (int i = 0; i < obj.vertices.size(); i++)
	{
		this->vertices.push_back(obj.vertices[i]);
	}

	for (int i = 0; i < obj.vertices.size(); i++)
	{
		obj.vertices[i] = defaultPoint;
	}
}
SimplePolygon2D :: 	~SimplePolygon2D()
{

}

/* Logical operators */

bool SimplePolygon2D::operator == (const SimplePolygon2D& operand)
{
	if (this->vertices.size() != operand.vertices.size())
		return false;
	
	else
	{
		for (int i = 0; i < operand.vertices.size(); i++)
		{
			if (!(this->vertices[i] == operand.vertices[i]))
				return false;
		}
	}
	return true;
}

bool SimplePolygon2D::operator != (const SimplePolygon2D& operand)
{
	if (!(*this == operand))
		return true;
	else
		return false;
}

std::ostream&operator << (std::ostream& os, SimplePolygon2D& output)
{
	for (int i = 0; i < output.vertices.size(); i++)
		std::cout << "Point" << i <<":"<< output.vertices[i]<<" ";
	
	return os;
}


/*
Geometric Primitives
Functions between Segment and Point.
*/

//Returns true if poi lies on the segment.
bool PointLiesOnSegment(Poi2D& q, Seg2D& seg)
{
	
	Number minp1p2x;
	Number maxp1p2x;
	Number minp1p2y;
	Number maxp1p2y;
	
	if (!PointIsCollinearToSegment(q, seg))
	{
		//std::cout << "not collinear";
		return false;
	}
	
	if (seg.p1.x>seg.p2.x)
	{
		minp1p2x = seg.p2.x;
		maxp1p2x = seg.p1.x;
	}
	else
	{
		minp1p2x = seg.p1.x;
		maxp1p2x = seg.p2.x;
	}

	if (seg.p1.y>seg.p2.y)
	{
		minp1p2y = seg.p2.y;
		maxp1p2y = seg.p1.y;
	}
	else
	{
		minp1p2y = seg.p1.y;
		maxp1p2y = seg.p2.y;
	}

	//std::cout << "\nseg" << seg << std::endl;
	//std::cout << "\npoi" << q << std::endl;
	//std::cout << "\nminp1p2x" << minp1p2x << "maxp1p2x" << maxp1p2x << "minp1p2y" << minp1p2y << "maxp1p2y" << maxp1p2y;
	if (minp1p2x <= q.x && q.x <= maxp1p2x
		&& minp1p2y <= q.y && q.y <= maxp1p2y)
	{
		//std::cout << "seg" << seg << std::endl;
		//std::cout << "poi" << q << std::endl;
		//std::cout << "minp1p2x" << minp1p2x << "maxp1p2x" << maxp1p2x << "minp1p2y" << minp1p2y << "maxp1p2y" << maxp1p2y;
		//std::cout << "point lies check true";
		return true;
	}
	else
		return false;
}
//Returns the point that lies on the segment and not on the endpoints.
bool PointLiesOnSegmentAndNotEndpoints(Poi2D& poi, Seg2D& seg)
{	
	if (!PointIsCollinearToSegment(poi, seg))
	{
		//std::cout << "not collinear";
		return false;
	}
	if (PointLiesOnSegment(poi, seg) && ((poi != seg.p1)&&(poi != seg.p2)))
		return true;
	else
		return false;
}
//Returns the point that lies on the segment
Poi2D getPointLiesOnSegmentAndNotEndpoints(Poi2D& poi1, Poi2D& poi2, Seg2D& seg)
{

	if (PointLiesOnSegmentAndNotEndpoints(poi1, seg))
		return poi1;
	if (PointLiesOnSegmentAndNotEndpoints(poi2, seg))
		return poi2;

}

// Returns true if poi PointLies above the segment.
bool PointLiesAboveSegment(Poi2D& poi, Seg2D& seg)
{
	Number isAntiClockWise = (seg.p2.x - seg.p1.x) * (poi.y - seg.p1.y) - (poi.x - seg.p1.x) * (seg.p2.y - seg.p1.y);

	if (isAntiClockWise > Number("0"))
		return true;
	else
		return false;
}

// Returns true if poi PointLies below the segment.
bool PointLiesBelowSegment(Poi2D& poi, Seg2D& seg)
{
	Number isAntiClockWise = (seg.p2.x - seg.p1.x) * (poi.y - seg.p1.y) - (poi.x - seg.p1.x) * (seg.p2.y - seg.p1.y);

	if (isAntiClockWise < Number("0"))
		return true;

	else
		return false;
}
//Return true if both points passed to it are either to the left of the segment or to the right of the segment.
bool PointLiesOnSameSideOfSegment(Poi2D& poi1, Poi2D& poi2, Seg2D& seg)
{
	//std::cout << "\nseg" << seg;
	if (PointIsCollinearToSegment(poi1, seg) || PointIsCollinearToSegment(poi2, seg)) //change on to collinear
	{
		return true;
	}
	//std::cout << "\npoint liesabove1:" << PointLiesAboveSegment(poi1, seg) << "p2above:" << PointLiesAboveSegment(poi2, seg);
	if (PointLiesAboveSegment(poi1, seg) == PointLiesAboveSegment(poi2, seg))
		return true;
	else
		return false;
}
//Returns true if poi PointLies on or above the segment.
bool PointLiesAboveOrOnSegment(Poi2D& poi, Seg2D& seg)
{
	if (PointLiesAboveSegment(poi, seg) || PointLiesOnSegment(poi, seg))
		return true;
	else
		return false;
}

// Returns true if poi PointLies on or below the segment.
bool PointLiesBelowOrOnSegment(Poi2D& poi, Seg2D& seg)
{

	if (PointLiesBelowSegment(poi, seg) || PointLiesOnSegment(poi, seg))
		return true;
	else
		return false;
}

// Returns true if poi PointLies on the left end point of the segment.
bool PointLiesOnLeftEndPointOfSegment(Poi2D& poi, Seg2D& seg)
{
	
	if (PointLiesOnSegment(poi, seg) && (seg.p1 == poi))
		return true;
	else
		return false;
}

// Returns true if poi PointLies on the right end point of the segment.
bool PointLiesOnRightEndPointOfSegment(Poi2D& poi, Seg2D& seg)
{
	//std::cout << "PointLiesonsegment:" << PointLiesOnSegment(poi, seg) << "seg.p1" << seg.p1 << "poi:" << poi;
	if (PointLiesOnSegment(poi, seg) && (seg.p2 == poi))
		return true;
	else
		return false;
}

//Returns true if the point is collinear to the segment.
bool PointIsCollinearToSegment(Poi2D& poi, Seg2D& seg)
{
	//std::cout << seg.p2.x - seg.p1.x << "diff";
	if (seg.p2.x - seg.p1.x != Number("0"))
	{
		if (poi == seg.p1 || poi == seg.p2)
			return true;
		else
		{
			if (seg.p1.x - poi.x == Number("0"))
			{
				if (poi.y == seg.p1.y)
					return true;
				else
					return false;
			}
			else
			{
				Number segslope = (seg.p2.y - seg.p1.y) / (seg.p2.x - seg.p1.x);
				Number pointslope = (seg.p1.y - poi.y) / (seg.p1.x - poi.x);
				if (pointslope == segslope)
					return true;
				else
					return false;
			}
			
		}
	}
		
	else
	{
		if (poi.x == seg.p1.x)
			return true;
		else
			return false;
	}
}

// Returns true if poi PointLies to the left of the segment and is collinear.
bool PointLiesLeftOFSegmentAndIsCollinear(Poi2D& poi, Seg2D& seg)
{
	//Checking whether the point lies to the left of the segment.
	if ((poi.x < seg.p1.x) && PointIsCollinearToSegment(poi, seg))
		return true;
	else
		return false;
}

// Returns true if poi PointLies to the right of the segment and is collinear.
bool PointLiesRightOfSegmentAndIsCollinear(Poi2D& poi, Seg2D& seg)
{
	if ((poi.x > seg.p2.x) && PointIsCollinearToSegment(poi, seg))
		return true;
	else
		return false;
}

/*
Functions between segments
*/

//Returns true if seg1 lies on seg2.
bool SegmentLiesOnSegment(Seg2D& seg1, Seg2D& seg2)
{
	//Checking four cases here.
	if ((PointLiesOnSegment(seg1.p1, seg2) && (PointLiesOnSegment(seg1.p2, seg2))) || (PointIsCollinearToSegment(seg1.p1, seg1)) && (PointLiesOnSegment(seg1.p2, seg2)) || (PointIsCollinearToSegment(seg1.p2, seg1)) && (PointLiesOnSegment(seg1.p1, seg2)) || (PointLiesOnSegment(seg2.p1, seg1) && (PointLiesOnSegment(seg2.p2, seg1))))
		return true;
	else
		return false;
}

// Returns true if the segment seg1 lies entirely above seg2. i.e. both endpoints of seg1 are above seg2.
bool SegmentLiesAboveSegment(Seg2D& seg1, Seg2D& seg2)
{
	if (PointLiesAboveSegment(seg1.p1, seg2) && PointLiesAboveSegment(seg1.p2, seg2))
		return true;
	else 
		return false;
}

// Returns true if the segment seg1 lies entirely above seg2. i.e. both endpoints of seg1 are above seg2..
bool SegmentLiesBelowSegment(Seg2D& seg1, Seg2D& seg2)
{
	if (PointLiesBelowSegment(seg1.p1, seg2) && PointLiesBelowSegment(seg1.p2, seg2))
		return true;
	else
		return false;
}

// Returns true if seg1 SegmentLies to the left of seg2.
bool SegmentLiesLeftOFSegment(Seg2D& seg1, Seg2D& seg2)
{
	if (seg1.p1.x < seg2.p1.x)
		return true;
	else
		return false;
}

// Returns true if seg1 SegmentLies to the right of seg2.
bool SegmentLiesRightOfSegment(Seg2D& seg1, Seg2D& seg2)
{
	if (seg1.p2.x > seg2.p2.x)
		return true;
	else
		return false;
}

// Returns true if the segment is collinear.
bool SegmentIsCollinear(Seg2D& seg1, Seg2D& seg2)
{
	if (PointIsCollinearToSegment(seg1.p1, seg2) && PointIsCollinearToSegment(seg1.p2, seg2))
		return true;
	else
		return false;
	/*if (seg1.p2.x - seg1.p1.x == Number("0") || seg2.p2.x - seg2.p1.x == Number("0"))
	if (seg1.p1.x == seg2.p2.x)
		return true;
	else
		return false;
	else
	{
		Number seg1slope = (seg1.p2.y - seg1.p1.y) / (seg1.p2.x - seg1.p1.x);
		Number seg2slope = (seg2.p2.y - seg2.p1.y) / (seg2.p2.x - seg2.p1.x);
		Number seg1yintercept = (seg1.p1.y) - ((seg1slope)*seg1.p1.x);
		Number seg2yintercept = (seg2.p1.y) - ((seg2slope)*seg2.p1.x);
		if (seg1slope == seg2slope && seg1yintercept == seg2yintercept)
			return true;
		else
			return false;
	}*/
}

// Returns true if seg1 SegmentLies to the left and is collinear to seg2.
bool SegmentLiesLeftOFSegmentAndIsCollinear(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentLiesLeftOFSegment(seg1, seg2) && SegmentIsCollinear(seg1, seg2))
		return true;
	else
		return false;
}

// Returns true if seg1 SegmentLies to the right and is collinear to seg2.
bool SegmentLiesRightOfSegmentAndIsCollinear(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentLiesRightOfSegment(seg1, seg2) && SegmentIsCollinear(seg1, seg2))
		return true;
	else
		return false;
}

// Returns true if the segments are collinear and meets only at the left endpoint of seg1.
bool SegmentIsCollinearAndMeetsLeftEndpoint(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsCollinear(seg1, seg2) && seg1.p1 == seg2.p1)
		return true;
	else
		return false;
}

// Returns true if the segments are collinear and meets only at the right endpoint of seg1.
bool SegmentIsCollinearAndMeetsRightEndpoint(Seg2D& seg1, Seg2D& seg2)
{

	if (SegmentIsCollinear(seg1, seg2) && seg1.p2 == seg2.p2)
		return true;
	else
		return false;

}
// Returns true if the segments are collinear and meet at both the left and right endpoints of seg1. The line lies exactly on top of the other.
bool SegmentIsCollinearAndMeetsBothEndpoint(Seg2D& seg1, Seg2D& seg2)
{

	if (SegmentIsCollinear(seg1, seg2) && (seg1.p1 == seg2.p1) && (seg1.p2 == seg2.p2))
		return true;
	else
		return false;
}
// Returns true if the segments are collinear and seg2 goes beyond seg1's left endpoint.
bool SegmentIsCollinearAndCrossesLeftEndpoint(Seg2D& seg1, Seg2D& seg2)
{

	if (SegmentIsCollinear(seg1, seg2) && (seg2.p1 < seg1.p1))
		return true;
	else
		return false;
}
// Returns true if the segments are collinear and seg2 goes beyond seg1's right endpoint.
bool SegmentIsCollinearAndCrossesRightEndpoint(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsCollinear(seg1, seg2) && (seg2.p2 > seg1.p2))
		return true;
	else
		return false;
}
//Returns true if the segments are parallel
bool SegmentIsParallel(Seg2D& seg1, Seg2D& seg2)
{
	if (seg1.p2.x - seg1.p1.x == Number("0") && seg2.p2.x - seg2.p1.x != Number("0"))
	{
		return false;
	}
	if (seg2.p2.x - seg2.p1.x != Number("0") && seg2.p2.x - seg2.p1.x == Number("0"))
	{
		return false;
	}
	if (seg1.p2.x - seg1.p1.x == Number("0") && seg2.p2.x - seg2.p1.x == Number("0"))
	if (seg1.p1.x == seg2.p2.x)
		return false;
	else
		return true;
	else
	{
		Number seg1slope = (seg1.p2.y - seg1.p1.y) / (seg1.p2.x - seg1.p1.x);
		Number seg2slope = (seg2.p2.y - seg2.p1.y) / (seg2.p2.x - seg2.p1.x);

		if (seg1slope == seg2slope && (!SegmentIsCollinear(seg1, seg2)))
			return true;
		else
			return false;
	}

}
//Returns true if the segments are parallel and seg1 lies above seg2.
bool SegmentIsParallelAndAbove(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsParallel(seg1, seg2) && SegmentLiesAboveSegment(seg1, seg2))
		return true;
	else
		return false;
}
//Returns true if the segments are parallel and seg1 lies below seg2
bool SegmentIsParallelAndBelow(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsParallel(seg1, seg2) && SegmentLiesBelowSegment(seg1, seg2))
		return true;
	else
		return false;
}
//Returns true if the segments are parallel and seg1 lies to left of seg2.
bool SegmentIsParallelAndLiesLeft(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsParallel(seg1, seg2) && SegmentLiesLeftOFSegment(seg1, seg2))
		return true;
	else
		return false;
}
//Returns true if the segments are parallel and seg1 lies to the right of seg2.
bool SegmentIsParallelAndLiesRight(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsParallel(seg1, seg2) && SegmentLiesRightOfSegment(seg1, seg2))
		return true;
	else
		return false;
}

//Returns true if the magnitude of the segment seg1 is lesser than that of seg2.
bool SegmentIsLesserThanSegment(Seg2D& seg1, Seg2D& seg2)
{
	Poi2D p1 = seg1.p1;
	Poi2D p2 = seg1.p2;
	Poi2D p3 = seg2.p1;
	Poi2D p4 = seg2.p2;
	Number lengthOfSeg1 = (p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x);
	Number lengthOfSeg2 = (p4.y - p3.y)*(p4.y - p3.y) + (p4.x - p3.x)*(p4.x - p3.x);
	if (lengthOfSeg1 < lengthOfSeg2){
		return true;
	}
	else{
		return false;
	}
}
bool SegmentLiesOnOrWithinSegment(Seg2D& seg1, Seg2D& seg2)
{
	if (SegmentIsCollinear(seg1, seg2) && (PointLiesOnSegment(seg1.p1, seg2) && PointLiesOnSegment(seg1.p2, seg2)))
		return true;
	else
		return false;
}
int poly_orientation(Poi2D& p1, Poi2D& p2, Poi2D& q1) 
{
	Number val = (p2.y - p1.y) * (q1.x - p2.x) - (q1.y - p2.y) * (p2.x - p1.x);
	
	if (val == Number("0"))
		return 0;
	else
		return (val < Number("0")) ? -1 : 1;
}

//Returns true if line segment 'seg1' and 'seg2' intersect.
bool IntersectsAndNotCollinearAndNotEndpoints(Seg2D& seg1, Seg2D& seg2)
{

	if (SegmentIsCollinear(seg1, seg2) || Meet(seg1, seg2) || PointLiesOnSegment(seg1.p1, seg2) || PointLiesOnSegment(seg1.p2, seg2) || PointLiesOnSegment(seg2.p1, seg1) || PointLiesOnSegment(seg2.p2, seg1))
	{
		return false;
	}
	else
	{
		//std::cout << "came here";
		int o1 = poly_orientation(seg1.p1, seg1.p2, seg2.p1);
		int o2 = poly_orientation(seg1.p1, seg1.p2, seg2.p2);
		int o3 = poly_orientation(seg2.p1, seg2.p2, seg1.p1);
		int o4 = poly_orientation(seg2.p1, seg2.p2, seg1.p2);
		if (o1 != o2 && o3 != o4)
		{
			return true;
		}
		else
			return false;
	}
}
bool Intersects(Seg2D& seg1, Seg2D& seg2)
{
	// Find the four orientations needed for general and special cases

	int o1 = poly_orientation(seg1.p1, seg1.p2, seg2.p1);
	//std::cout << "jjj" << std::endl;
	int o2 = poly_orientation(seg1.p1, seg1.p2, seg2.p2);
	int o3 = poly_orientation(seg2.p1, seg2.p2, seg1.p1);
	int o4 = poly_orientation(seg2.p1, seg2.p2, seg1.p2);


	if (o1 != o2 && o3 != o4)
		return true;

	if (PointLiesOnSegment(seg1.p1, seg2) || PointLiesOnSegment(seg1.p2, seg2) || PointLiesOnSegment(seg2.p1, seg1) || PointLiesOnSegment(seg2.p2, seg1))
		return true;
	// Special Cases

	if (o1 == 0 && PointLiesOnSegment(seg2.p1, seg1))
		return true;

	// seg1.p1, seg1.p2 and seg2.p1 are collinear and seg2.p2 lies on segment seg1
	if (o2 == 0 && PointLiesOnSegment(seg2.p2, seg1))
		return true;

	// p2, q2 and p1 are collinear and p1 lies on segment p2q2
	if (o3 == 0 && PointLiesOnSegment(seg1.p1, seg2))
		return true;


	// p2, q2 and q1 are collinear and q1 lies on segment p2q2
	if (o4 == 0 && PointLiesOnSegment(seg1.p2, seg2))
		return true;

	return false;

}

bool Poly_intersects(Seg2D& seg1, Seg2D& seg2)
{
	// Find the four orientations needed for general and special cases

	int o1 = poly_orientation(seg1.p1, seg1.p2, seg2.p1);
	//std::cout << "jjj" << std::endl;
	int o2 = poly_orientation(seg1.p1, seg1.p2, seg2.p2);
	int o3 = poly_orientation(seg2.p1, seg2.p2, seg1.p1);
	int o4 = poly_orientation(seg2.p1, seg2.p2, seg1.p2);

	//std::cout << "\n o1:" << o1 << "\n o2:" << o2 << "\n o3:" << o3 << "\n o4:" << o4;
	
	if (o1 != o2 && o3 != o4)
	{
		//std::cout << "weird case";
		return true;
	}
	if (PointLiesOnSegment(seg1.p1, seg2) || PointLiesOnSegment(seg1.p2, seg2) || PointLiesOnSegment(seg2.p1, seg1) || PointLiesOnSegment(seg2.p2, seg1))
	{
	
		//std::cout << "case 1";
		return true;
	// Special Cases
	}
	if (o1 == 0 && PointLiesOnSegment(seg2.p1, seg1))
	{
	
		//std::cout << "case 2";
		return true;
	}
	// seg1.p1, seg1.p2 and seg2.p1 are collinear and seg2.p2 lies on segment seg1
	if (o2 == 0 && PointLiesOnSegment(seg2.p2, seg1))
	{
		//std::cout << "case 3";
		return true;
	}
	// p2, q2 and p1 are collinear and p1 lies on segment p2q2
	if (o3 == 0 && PointLiesOnSegment(seg1.p1, seg2))
	{
		//std::cout << "case 4";
		return true;
	}

	// p2, q2 and q1 are collinear and q1 lies on segment p2q2
	if (o4 == 0 && PointLiesOnSegment(seg1.p2, seg2))
	{
		//std::cout << "case 5";
		return true;
	}
	return false;

}


//Returns the first point of intersection between seg1 and seg2.
Poi2D IntersectionPoint(Seg2D& seg1, Seg2D& seg2)
{
	Number segSlope;
	Number segYintercept;
	Number yCord;
	Number xCord;
	//Number max
	if (seg1.p1.y == seg1.p2.y && seg2.p1.x == seg2.p2.x){
		return Poi2D(seg2.p1.x, seg1.p1.y);
	}
	else if (seg2.p1.y == seg2.p2.y && seg1.p1.x == seg1.p2.x){
		return Poi2D(seg1.p1.x, seg2.p1.y);
	}
	else if (seg1.p1.x == seg1.p2.x && seg2.p1.x != seg2.p2.x){
		segSlope = (seg2.p2.y - seg2.p1.y) / (seg2.p2.x - seg2.p1.x);
		segYintercept = (seg2.p1.y) - ((segSlope)*seg2.p1.x);
		xCord = seg1.p1.x;
		yCord = segSlope * xCord + segYintercept;
	}
	else if (seg2.p1.x == seg2.p2.x && seg2.p1.x != seg2.p2.x){
		segSlope = (seg1.p2.y - seg1.p1.y) / (seg1.p2.x - seg1.p1.x);
		segYintercept = (seg1.p1.y) - ((segSlope)*seg1.p1.x);
		xCord = seg2.p1.x;
		yCord = segSlope * xCord + segYintercept;
	}
	else if (seg1.p1.y == seg1.p2.y && seg2.p1.x != seg2.p2.x){
		yCord = seg1.p1.y;
		segSlope = (seg2.p2.y - seg2.p1.y) / (seg2.p2.x - seg2.p1.x);
		segYintercept = (seg2.p1.y) - ((segSlope)*seg2.p1.x);
		xCord = (yCord - segYintercept) / segSlope;
	}
	else if (seg2.p1.y == seg2.p2.y && seg1.p1.x != seg1.p2.x){
		yCord = seg2.p1.y;
		segSlope = (seg1.p2.y - seg1.p1.y) / (seg1.p2.x - seg1.p1.x);
		segYintercept = (seg1.p1.y) - ((segSlope)*seg1.p1.x);
		xCord = (yCord - segYintercept) / segSlope;
	}
	else if (seg1.p1.x == seg1.p2.x && seg1.p2.x == seg2.p1.x && seg2.p1.x == seg2.p2.x){
		xCord = seg1.p1.x;
		yCord = seg1.p2.y;
	}
	else if (seg1.p1.y == seg1.p2.y && seg1.p2.y == seg2.p1.y && seg2.p1.y == seg2.p2.y){
		yCord = seg1.p1.y;
		xCord = seg1.p2.x;
	}
	else{
		Number seg1slope = (seg1.p2.y - seg1.p1.y) / (seg1.p2.x - seg1.p1.x);
		Number seg2slope = (seg2.p2.y - seg2.p1.y) / (seg2.p2.x - seg2.p1.x);
		Number seg1yintercept = (seg1.p1.y) - ((seg1slope)*seg1.p1.x);
		Number seg2yintercept = (seg2.p1.y) - ((seg2slope)*seg2.p1.x);
		xCord = (seg2yintercept - seg1yintercept) / (seg1slope - seg2slope);
		yCord = (seg2slope*xCord) + seg2yintercept;
	}
	return Poi2D(xCord, yCord);
}
//Returns true if the two segments have a common endpoint.
bool Meet(Seg2D& seg1, Seg2D& seg2)
{
	if ((seg1.p1 == seg2.p1) || (seg1.p1 == seg2.p2) || (seg1.p2 == seg2.p1) || (seg1.p2 == seg2.p2))
		return true;

	else
		return false;
}
// Returns the first common endpoint between the two segments.
Poi2D MeetingPoint(Seg2D& seg1, Seg2D& seg2)
{
	if (seg1.p1 == seg2.p1)
		return Poi2D(seg1.p1);

	if (seg1.p1 == seg2.p2)
		return Poi2D(seg1.p1);

	if (seg1.p2 == seg2.p1)
		return Poi2D(seg1.p2);

	if (seg1.p2 == seg2.p2)
		return Poi2D(seg1.p2);
}

//Returns the midpoint of a given segment.
Poi2D MidPoint(Seg2D& seg1)
{
	Number two = Number("2");
	Number xcord = (seg1.p2.x - seg1.p1.x) / two;
	Number ycord = (seg1.p2.y - seg1.p1.y) / two;

	return Poi2D(xcord, ycord);
}

//Returns true if a segment touches the other segment at any point other than its endpoints.
bool Touch(Seg2D& seg1, Seg2D& seg2)
{
	if ((!SegmentIsCollinear(seg1, seg2)) && (PointLiesOnSegmentAndNotEndpoints(seg1.p1, seg2) || PointLiesOnSegmentAndNotEndpoints(seg1.p2, seg2)))
		return true;
	else
		return false;
}
// Returns the point where the segment touches another segment. Use this function only after confirming that two segments touch.
Poi2D TouchingPoint(Seg2D& seg1, Seg2D& seg2)
{
	if (Touch(seg1, seg2)){
		return getPointLiesOnSegmentAndNotEndpoints(seg1.p1, seg1.p2, seg2);
	}

}
//Basic polygon in bouding box test.
bool BasicPointInBoundingBox(Poi2D& poi, SimplePolygon2D& polygon)
{

	Number minx = polygon.vertices[0].x;
	Number miny = polygon.vertices[0].y;
	Number maxx = polygon.vertices[0].x;
	Number maxy = polygon.vertices[0].y;
	
	for (int i = 1; i < polygon.vertices.size(); i++)
	{
		if (polygon.vertices[i].x < minx)
			minx = polygon.vertices[i].x;
		if (polygon.vertices[i].x > maxx)
			maxx = polygon.vertices[i].x;
		if (polygon.vertices[i].y < miny)
			miny = polygon.vertices[i].y;
		if (polygon.vertices[i].y > maxy)
			maxy = polygon.vertices[i].y;
		
	}
	//std::cout << "BOUNDING BOX:\nminx" << minx << "maxx:" << maxx << "maxy" << maxy << "miny" << miny;
	if (poi.x < minx || poi.y < miny || poi.x > maxx || poi.y > maxy)
		return false;
	else
		return true;
}

//Determines whether a point is located on theboundary of a simple polygon.
bool simplePointInsideSimplePolygon(Poi2D& poi, SimplePolygon2D& polygon)
{
	Poi2D PtoInfinity(poi.x, Number("100.0"));
	//Poi2D PtoInfinity = { INF, poi.y };
	//Check if the point is inside the polygon by simple check!

	int j = 0;
	int i;
	int k;
	int l;
	int prevPoint;
	int nextPoint;
	bool simpleCheck = BasicPointInBoundingBox(poi, polygon);
	//std::cout << "simpleCheck" << simpleCheck << std::endl;
	int numbeOfIntersection = 0;
	int forI = 0;
	
	if (simpleCheck == false){
		return false;
	}
	else{
		Seg2D segC(poi, PtoInfinity);
		//std::cout << "segC : " << segC << std::endl;
		int totalNumberOfVertices = polygon.vertices.size();
		//std::cout << "totalNumberOfVertices" << totalNumberOfVertices << std::endl;
		for (i = 0; i<totalNumberOfVertices; i++){
			//std::cout << "----------i is --------" << i;
			bool pointCheck = false;
			bool pointsOntheSameSideOfSeg = false;
			if (forI == 1 && i == (totalNumberOfVertices - 1)){
				//do nothing , skip this loop
				continue;
			}
			else{
				if (i == 0){
					j = totalNumberOfVertices - 1;
					//l = totalNumberOfVertices - 1;
				}
				else{
					j = i - 1;
					//l = i - 1;
				}
				if (i == totalNumberOfVertices - 1){
					k = 0;

				}
				else{
					k = i + 1;
				}

				//std::cout << "j:i" << j << i << std::endl;
				Seg2D segI(polygon.vertices[i], polygon.vertices[k]);
				//std::cout << "segI : " << segI << std::endl;
				//check if they intersect with segC
				//std::cout << "segI" << segI;
				//std::cout << "segC" << segC;
				bool intersects = Poly_intersects(segI, segC);
				//std::cout << "value of intersects" << intersects << std::endl;
				if (intersects){
					bool isCollinear = PointIsCollinearToSegment(poi, segI);
					//std::cout << "isCollinear" << isCollinear << std::endl;
					// Poi2D pointOfIntersection = IntersectionPoint(segI,segC);
					// std::cout << "pointOfIntersection" << pointOfIntersection << std::endl;
					// if(pointOfIntersection == polygon.vertices[i] || pointOfIntersection == polygon.vertices[k]){
					// 	i++;
					// 	pointCheck = true;
					// 	std::cout << "pointCheck" << pointCheck << std::endl;
					// 	if(pointOfIntersection == polygon.vertices[0]){
					// 	forI = 1;
					// 	}
					// }


					Poi2D pointOfIntersection;
					//std::cout << "pointOfIntersection" << pointOfIntersection << std::endl;
					if (PointLiesOnSegmentAndNotEndpoints(polygon.vertices[i], segC) || PointLiesOnSegmentAndNotEndpoints(polygon.vertices[k], segC)){

						
						pointCheck = true;
						if (PointLiesOnSegmentAndNotEndpoints(polygon.vertices[i], segC)){
							pointOfIntersection = polygon.vertices[i];
							l = i;
							//std::cout << "pointCheckoth" << pointCheck << std::endl;
						}
						else{
							l = k;
							pointOfIntersection = polygon.vertices[k];
						}
						//std::cout << "pointCheck1st" << pointCheck << std::endl;
						if (pointOfIntersection == polygon.vertices[0]){
							forI = 1;
						}
						else{
							i = i + 1;
						}
					}


					if (isCollinear){
						bool pointOnSeg = PointLiesOnSegmentAndNotEndpoints(poi, segI);
						if (pointOnSeg){
							return true;
						}
						else{
							//std::cout<<"polygon.vertices[j]" << polygon.vertices[j] << "polygon.vertices[j +3]" << polygon.vertices[j+3] << "segI" << segI;
							pointsOntheSameSideOfSeg = PointLiesOnSameSideOfSegment(polygon.vertices[j], polygon.vertices[j + 3], segI);
							//std::cout << "pointsOntheSameSideOfSeg -" << pointsOntheSameSideOfSeg << std::endl;
							if (!pointsOntheSameSideOfSeg){
								//std::cout <<"incremented here seggg";
								numbeOfIntersection++;
							}
						}

					}else if (pointCheck){
						Seg2D segR(poi, pointOfIntersection);
						if(l==0){
							prevPoint = totalNumberOfVertices - 1;

						}else{
							prevPoint = l - 1;
						}
						if(l== totalNumberOfVertices - 1 ){
							nextPoint = 0;
						}else{
							nextPoint = l + 1;
						}

						//std::cout << "polygon.vertices[prevPoint]" << polygon.vertices[prevPoint];
						//std::cout << "polygon.vertices[nextPoint]" << polygon.vertices[nextPoint];
						if(PointIsCollinearToSegment(polygon.vertices[nextPoint],segC)){
							i = i - 1;
						}

						pointsOntheSameSideOfSeg = PointLiesOnSameSideOfSegment(polygon.vertices[prevPoint], polygon.vertices[nextPoint], segR);
						//std::cout << "pointsOntheSameSideOfSeg -" << pointsOntheSameSideOfSeg << std::endl;
						if (!pointsOntheSameSideOfSeg){
							//std::cout <<"incremented here";
							numbeOfIntersection++;
						}

					}
					else {
						//std::cout <<"incremented here tooooo";
						numbeOfIntersection++;
					}

				}
			}


		}
		//std::cout <<"numbeOfIntersection"<< numbeOfIntersection << "------";
		if (numbeOfIntersection % 2 == 0){
			return false;
		}
		else{
			return true;
		}


	}

	
}
//Determines whether the point is located in the interior or on the boundary of the simple polygon 
bool simplePointOnBoundaryOfSimplePoly(Poi2D& poi, SimplePolygon2D& simplepolygon)
{
	Seg2D tempSegment;
	int polygonSize = simplepolygon.vertices.size();
	for (int i = 0; i <polygonSize; i++)
	{
		if (i == polygonSize - 1)
			tempSegment = Seg2D(simplepolygon.vertices[i], simplepolygon.vertices[0]);
		
		else
			tempSegment = Seg2D(simplepolygon.vertices[i], simplepolygon.vertices[i + 1]);
		
		if (PointLiesOnSegment(poi, tempSegment))
			return true;
	}
	return false;
}
//Determines whether the segment is located in the interior of the simple polygon 
bool segInsideSimplePolygon(Seg2D& seg, SimplePolygon2D& simplepolygon)
{
	if (simplePointInsideSimplePolygon(seg.p1, simplepolygon) && simplePointInsideSimplePolygon(seg.p2, simplepolygon))
		return true;
	else
		return false;
}
//Determines whether the segment is located on the boundary of the simple polygon 
bool segOnBoundaryOfSimplePolygon(Seg2D& seg, SimplePolygon2D& simplepolygon)
{
	Seg2D tempSegment;
	int polygonSize = simplepolygon.vertices.size();
	for (int i = 0; i <polygonSize; i++)
	{
		if (i == polygonSize - 1)
			tempSegment = Seg2D(simplepolygon.vertices[i], simplepolygon.vertices[0]);

		else
			tempSegment = Seg2D(simplepolygon.vertices[i], simplepolygon.vertices[i + 1]);

		if (SegmentLiesOnOrWithinSegment(seg, tempSegment))
			return true;
	}
	return false;
}

//Returns a minimum bounding rectangle for a polygon
Rect2D computeRect2D(SimplePolygon2D& polygon)
{
	Number minx = polygon.vertices[0].x;
	Number miny = polygon.vertices[0].y;
	Number maxx = polygon.vertices[0].x;
	Number maxy = polygon.vertices[0].y;
	//std::cout << "initial topleft and bottomright:" << topLeft << " and" << bottomRight<<"\n";
	//std::cout << "vertices size:" << polygon.vertices.size();
	for (int i = 0; i < polygon.vertices.size(); i++)
	{
		if (polygon.vertices[i].x < minx)
			minx = polygon.vertices[i].x;
		if (polygon.vertices[i].x > maxx)
			maxx = polygon.vertices[i].x;
		if (polygon.vertices[i].y < miny)
			miny = polygon.vertices[i].x;
		if (polygon.vertices[i].y > maxy)
			maxy = polygon.vertices[i].x;
	}
	Poi2D topLeft = Poi2D(minx, maxy);
	Poi2D bottomRight = Poi2D(maxx, miny);
	Rect2D rect = Rect2D(topLeft, bottomRight);
	return rect;
}



