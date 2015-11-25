#include "RobustGeometricPrimitives2D.h"
#include <iostream>

using namespace std;
/*POINT*/

Poi2D::Poi2D()
{
	this->x = Number(0.0);
	this->y = Number(0.0);
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

Poi2D Poi2D::operator=(const Poi2D& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	return *this;

}
Poi2D::~Poi2D()
{
}
/* logical operators */
bool Poi2D::operator<(const Poi2D& operand)
{
	 if(this->x < operand.x) return true;
	return false;
}

bool Poi2D::operator>(const Poi2D& operand)
{
	 if(this->x > operand.x) return true;
	return false;
}

bool Poi2D::operator<=(const Poi2D& operand)
{
    if(this->x <= operand.x) return true;
	return false;
}

bool Poi2D::operator>=(const Poi2D& operand)
{
	if(this->x >= operand.x) return true;
	return false;
}

bool Poi2D::operator==(const Poi2D& operand)
{
	if((this->x == operand.x)&&(this->y == operand.y)) 
	     return true;
	return false;
}

bool Poi2D::operator!=(const Poi2D& operand)
{
	return true;
}

std::ostream&operator<<(std::ostream& os, const Poi2D& output)
{
	os << "(" << output.x << ", " << output.y << ")";
	return os;
}
std::istream&operator>>(std::istream& is, const Poi2D& input)
{
	std::cout << "input x and y numbers";
	is >> input.x >> input.y;
	return is;
}

/*Segment*/

Seg2D::Seg2D()
{

}
Seg2D::Seg2D(Poi2D p1, Poi2D p2)
{
	if (p1 <= p2)
	{
		this->p1 = p1;
		this->p2 = p2;
		//set half segments
	}
	else
	{
		this->p2 = p1;
		this->p1 = p2;
		//set half segments
	}
	//set half segments
}
Seg2D::Seg2D(const Seg2D& obj)
{
        this->p1 = obj.p1;
		this->p2 = obj.p2;
}
Seg2D Seg2D::operator=(const Seg2D& obj)
{

	return Seg2D(Poi2D(obj.p1), Poi2D(obj.p2));
}
Seg2D::~Seg2D()
{
}

HalfSeg2D Seg2D::ComputeLeftHalfSegment()
{
	return HalfSeg2D(this->p1,true);
}

HalfSeg2D Seg2D::ComputeRightHalfSegment()
{
	return HalfSeg2D(this->p2,false);
}


MBR Seg2D::computeMBB()
{
	return MBR();
}

/* logical operators */
bool Seg2D::operator<(const Seg2D& operand)
{
	return true;
}

bool Seg2D::operator>(const Seg2D& operand)
{
	return true;
}

bool Seg2D::operator<=(const Seg2D& operand)
{
	return true;
}

bool Seg2D::operator>=(const Seg2D& operand)
{
	return true;
}

bool Seg2D::meets(const Seg2D& operand)
{
    if((this->p1 == operand.p1)||(this->p2 == operand.p2))
		return true;
	return false;
}

bool Seg2D::operator==(const Seg2D& operand)
{
    if((this->p1 == operand.p1)&&(this->p2 == operand.p2))
		return true;
	return false;
}

bool Seg2D::operator!=(const Seg2D& operand)
{
	return true;
}

std::ostream&operator<<(std::ostream& os, const Seg2D& output)
{
	os << "Point 1: " << output.p1 << "\nPoint 2: " << output.p2;
	return os;
}

std::istream&operator>>(std::istream& is, const Seg2D& input) //added
{
	std::cout << "input p1 and p2 ";
	is >> input.p1 >> input.p2;
	return is;
}

/*HALFSEGMENT*/

HalfSeg2D::HalfSeg2D()
{
	this->isLeft = true;
	this->dominatingPoint = Poi2D(Number(0.0), Number(0.0));
}
HalfSeg2D::HalfSeg2D(Poi2D dominatingPoint, bool direction)
{
	this->dominatingPoint = dominatingPoint;
	this->isLeft = direction;
}
HalfSeg2D::HalfSeg2D(const HalfSeg2D& obj)
{
	this->dominatingPoint = obj.dominatingPoint;
	this->isLeft = obj.isLeft;
}
HalfSeg2D HalfSeg2D::operator=(const HalfSeg2D& obj)
{
	this->dominatingPoint = obj.dominatingPoint;
	this->isLeft = obj.isLeft;
	return *this;
}
HalfSeg2D::~HalfSeg2D()
{
}

/* logical operators */
bool HalfSeg2D::operator<(const HalfSeg2D& operand)
{
	if(this->isLeft && operand.isLeft){
	  if(this->dominatingPoint < operand.dominatingPoint)
	    return true;
	}
	return false;
}

bool HalfSeg2D::operator>(const HalfSeg2D& operand)
{
	if(this->isLeft && operand.isLeft){
	  if(this->dominatingPoint > operand.dominatingPoint)
	    return true;
	}
	return false;
}

bool HalfSeg2D::operator<=(const HalfSeg2D& operand)
{
    cout<<"booom"<<endl;
	//if(this->isLeft && operand.isLeft){
	  if((this->dominatingPoint == operand.dominatingPoint)||((this->dominatingPoint < operand.dominatingPoint)))
	    return true;
	//}
	return false;
}

bool HalfSeg2D::operator>=(const HalfSeg2D& operand)
{
	if(this->isLeft && operand.isLeft){
	  if(this->dominatingPoint >= operand.dominatingPoint){
	    return true;
	    }
	}
	return false;
}

bool HalfSeg2D::operator==(const HalfSeg2D& operand)
{
	return true;
}

bool HalfSeg2D::operator!=(const HalfSeg2D& operand)
{
	return true;
}

std::ostream&operator<<(std::ostream& os, const HalfSeg2D& output)
{
	os << "Dominating Point: " << output.dominatingPoint << "\nIs Left: " << output.isLeft;
	return os;
}


/*Atrributed Half Segment*/

AttrHalfSeg2D::AttrHalfSeg2D() :HalfSeg2D()
{

}
AttrHalfSeg2D::AttrHalfSeg2D(bool value, bool direction, Poi2D dominatingPoint) : HalfSeg2D(dominatingPoint, direction)
{
	this->regionInside = true;
}
AttrHalfSeg2D::AttrHalfSeg2D(const AttrHalfSeg2D& obj)
{

}
AttrHalfSeg2D AttrHalfSeg2D::operator=(const AttrHalfSeg2D& obj)
{
	return AttrHalfSeg2D(true, true, Poi2D(Number(0.0), Number(0.0)));
}
AttrHalfSeg2D::~AttrHalfSeg2D()
{
}

/* logical operators */
bool AttrHalfSeg2D::operator<(const AttrHalfSeg2D& operand)
{
	return true;
}

bool AttrHalfSeg2D::operator>(const AttrHalfSeg2D& operand)
{
	return true;
}

bool AttrHalfSeg2D::operator<=(const AttrHalfSeg2D& operand)
{
	return true;
}

bool AttrHalfSeg2D::operator>=(const AttrHalfSeg2D& operand)
{
	return true;
}

bool AttrHalfSeg2D::operator==(const AttrHalfSeg2D& operand)
{
	return true;
}

bool AttrHalfSeg2D::operator!=(const AttrHalfSeg2D& operand)
{
	return true;
}



/*Minimum Bounding Rectangle*/



MBR::MBR()
{

}
MBR::MBR(Poi2D p1, Poi2D p2)
{

}

MBR::MBR(const MBR& obj)
{

}
MBR MBR::operator=(const MBR& obj)
{
	return MBR(Poi2D(Number(0.0), Number(0.0)), Poi2D(Number(0.0), Number(0.0)));
}
MBR::~MBR()
{

}

std::ostream&operator<<(std::ostream& os, const MBR& output)
{
	os << "topLeft: " << output.topLeft << "\nbottomRight: " << output.bottomRight;
	return os;
}

std::istream&operator>>(std::istream& is, const MBR& input) //added
{
	std::cout << "input topLeft and bottomRight";
	is >> input.topLeft >> input.bottomRight;;
	return is;
}


//Geometric Primitives

//Geometric Primitives

// Functions between Segment and Point.

// Returns true if poi lies on the segment.
bool LiesOnSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies above the segment.
bool LiesAboveSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies below the segment.
bool LiesBelowSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies on or above the segment.
bool LiesAboveOrOnSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies on or below the segment.
bool LiesBelowOrOnSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies on the left end point of the segment.
bool LiesOnLeftEndPointOfSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies on the right end point of the segment.
bool LiesOnRightEndPointOfSegment(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies to the left of the segment and is collinear.
bool LiesLeftOFSegmentAndIsCollinear(Poi2D poi, Seg2D seg)
{
	return true;
}
// Returns true if poi lies to the right of the segment and is collinear.
bool LiesRightOfSegmentAndIsCollinear(Poi2D poi, Seg2D seg)
{
	return true;
}

/*
Functions between segments
*/
//Returns true if seg1 lies on seg2.
bool LiesOn(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if seg1 lies above seg2.
bool LiesAboveSegment(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if seg1 lies below seg2.
bool LiesBelowSegment(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if seg1 lies to the left of seg2.
bool LiesLeftOFSegment(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if seg1 lies to the right of seg2.
bool LiesRightOfSegment(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if seg1 lies to the left and is collinear to seg2.
bool LiesLeftOFSegmentAndIsCollinear(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if seg1 lies to the right and is collinear to seg2.
bool LiesRightOfSegmentAndIsCollinear(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if the segments are collinear and meets only at the left endpoint of seg1.
bool IsCollinearAndMeetsLeftEndpoint(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if the segments are collinear and meets only at the right endpoint of seg1.
bool IsCollinearAndMeetsRightEndpoint(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if the segments are collinear and meet at both the left and right endpoints of seg1. The line lies exactly on top of the other.
bool IsCollinearAndMeetsBothEndpoint(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if the segments are collinear and seg2 goes beyond seg1's left endpoint.
bool IsCollinearAndCrossesLeftEndpoint(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns true if the segments are collinear and seg2 goes beyond seg1's right endpoint.
bool IsCollinearAndCrossesRightEndpoint(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns true if the segments are parallel
bool isParallel(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns true if the segments are parallel and seg1 lies above seg2.
bool isParallelAndAbove(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns true if the segments are parallel and seg1 lies below seg2
bool isParallelAndBelow(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns true if the segments are parallel and seg1 lies to left of seg2.
bool isParallelAndLiesLeft(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns true if the segments are parallel and seg1 lies to the right of seg2.
bool isParallelAndLiesRight(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns true if seg1 intersects seg2.
bool Intersects(Seg2D seg1, Seg2D seg2)
{
	return true;
}
//Returns the point of intersection between seg1 and seg2.
Poi2D IntersectionPoint(Seg2D seg1, Seg2D seg2)
{
	return Poi2D(Number(0.0), Number(0.0));
}
//Returns true if the two segments have a common point.
bool Meet(Seg2D seg1, Seg2D seg2){


	return false;
}
// Returns the first common point between the two segments.
Poi2D MeetingPoint(Seg2D seg1, Seg2D seg2)
{
	return Poi2D(Number(0.0), Number(0.0));
}
//Returns true if a segment touches the other segment.
bool Touch(Seg2D seg1, Seg2D seg2)
{
	return true;
}
// Returns the point where the segment touches another segment.
Poi2D TouchingPoint(Seg2D seg1, Seg2D seg2)
{
	return Poi2D(Number(0.0), Number(0.0));
}
//Returns the midpoint of a given segment.
Poi2D MidPoint(Seg2D seg1)
{
	return Poi2D(Number(0.0), Number(0.0));
}
