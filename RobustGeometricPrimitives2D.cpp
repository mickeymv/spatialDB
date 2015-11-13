#include "RobustGeometricPrimitives2D.h"
 
 
/*POINT*/
 
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
/* logical operators */
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
 
std::ostream&operator << (std::ostream& os, const Poi2D& output)
{
        os << "(" << output.x << ", " << output.y << ")";
        return os;
}
std::istream&operator >> (std::istream& is, const Poi2D& input)
{

	std::cout << "Enter the x and y coordinates:";
	is >> input.x >> input.y;
	return is;
}
 
/*Segment*/
 
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
        os << "Point 1: " << output.p1 << "\nPoint 2: " << output.p2;
        return os;
}


//Overloading the instream operator for segments.
std::istream&operator >> (std::istream& is, const Seg2D& input)
{
	std::cout << "Enter the coordinates for the points p1 and p2: ";
	is >> input.p1 >> input.p2;
	return is;

}
 
/*HALFSEGMENT*/
 
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
 
/* logical operators */
bool HalfSeg2D::operator < (const HalfSeg2D& operand)
{

        Seg2D seg1 = this->seg;
        Seg2D seg2 = operand.seg;
        Poi2D dominatingPointOfSeg1;
        Poi2D dominatingPointOfSeg2;
        Poi2D nonDominatingPointOfSeg1;
        Poi2D nonDominatingPointOfSeg2;
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
 		
 		std::cout<< "dominatingPointOfSeg1" << dominatingPointOfSeg1;
 		std::cout << "dominatingPointOfSeg2" << dominatingPointOfSeg2;
 		std::cout << "nonDominatingPointOfSeg1" << nonDominatingPointOfSeg1;
 		std::cout << "nonDominatingPointOfSeg2" << nonDominatingPointOfSeg2;
 
        if(dominatingPointOfSeg1 < dominatingPointOfSeg2 
        	|| ( dominatingPointOfSeg1 == dominatingPointOfSeg2 && (!this->isLeft && operand.isLeft))
        	|| ( this->isLeft == operand.isLeft && 
	        		(
	        			(operand.isLeft == true && PointLiesAboveSegment(nonDominatingPointOfSeg2,seg1))
	        			||( operand.isLeft == false && PointLiesBelowSegment(nonDominatingPointOfSeg2,seg1) ) 
	        		)
        	    )
        	|| (this->isLeft == operand.isLeft && SegmentIsCollinearAndMeetsLeftEndpoint(seg1,seg2) && SegmentIsLesserThanSegment(seg1,seg2))
        	){
                return true;
        }
        else{
                return false;
        }
       
 
}
 

bool HalfSeg2D::operator > (const HalfSeg2D& operand)
{
        return true;
}
 
bool HalfSeg2D::operator <= (const HalfSeg2D& operand)
{
        return true;
}
 
bool HalfSeg2D::operator >= (const HalfSeg2D& operand)
{
        return true;
}
 
bool HalfSeg2D::operator == (const HalfSeg2D& operand)
{
        return true;
}
 
bool HalfSeg2D::operator != (const HalfSeg2D& operand)
{
        return true;
}
 
std::ostream&operator << (std::ostream& os, const HalfSeg2D& output)
{
        os << "Segment" << output.seg << "\nIs Left: " << output.isLeft;
        return os;
}
 
 
/*Atrributed Half Segment*/
 
AttrHalfSeg2D::AttrHalfSeg2D() :HalfSeg2D()
{
 
}
AttrHalfSeg2D::AttrHalfSeg2D(bool value, bool isLeft, Seg2D seg) : HalfSeg2D(seg, isLeft)
{
        this->insideAbove = true;
}
AttrHalfSeg2D::AttrHalfSeg2D(const AttrHalfSeg2D& obj)
{
 
}
AttrHalfSeg2D::AttrHalfSeg2D(AttrHalfSeg2D&& obj)
{
 
}
AttrHalfSeg2D AttrHalfSeg2D::operator = (const AttrHalfSeg2D& obj)
{
        return AttrHalfSeg2D(true, true, Seg2D());
}
AttrHalfSeg2D AttrHalfSeg2D::operator = (AttrHalfSeg2D&& obj)
{
        return AttrHalfSeg2D(true, true, Seg2D());
}
AttrHalfSeg2D::~AttrHalfSeg2D()
{

}
 
/* logical operators */
bool AttrHalfSeg2D::operator < (const AttrHalfSeg2D& operand)
{
        return true;
}
 
bool AttrHalfSeg2D::operator > (const AttrHalfSeg2D& operand)
{
        return true;
}
 
bool AttrHalfSeg2D::operator <= (const AttrHalfSeg2D& operand)
{
        return true;
}
 
bool AttrHalfSeg2D::operator >= (const AttrHalfSeg2D& operand)
{
        return true;
}
 
bool AttrHalfSeg2D::operator == (const AttrHalfSeg2D& operand)
{
        return true;
}
 
bool AttrHalfSeg2D::operator != (const AttrHalfSeg2D& operand)
{
        return true;
}
 
 
 
/*Minimum Bounding Rectangle*/
 
 
 
Rect2D::Rect2D()
{
 
}
Rect2D::Rect2D(Poi2D p1, Poi2D p2)
{
 
}
 
Rect2D::Rect2D(const Rect2D& obj)
{
 
}
Rect2D::Rect2D(Rect2D&& obj)
{
 
}
Rect2D Rect2D::operator = (const Rect2D& obj)
{
        return Rect2D(Poi2D(Number("0.0"), Number("0.0")), Poi2D(Number("0.0"), Number("0.0")));
}
Rect2D Rect2D::operator = (Rect2D&& obj)
{
        return Rect2D(Poi2D(Number("0.0"), Number("0.0")), Poi2D(Number("0.0"), Number("0.0")));
}
Rect2D::~Rect2D()
{

}
 
std::ostream&operator << (std::ostream& os, const Rect2D& output)
{
        os << "topLeft: " << output.topLeft << "\nbottomRight: " << output.bottomRight;
        return os;
}
 
std::istream&operator >> (std::istream& is, const Rect2D& input) //added
{
        std::cout << "input topLeft and bottomRight";
        is >> input.topLeft >> input.bottomRight;;
        return is;
}
 
/* Simple Polygon2D */
 
SimplePolygon2D::SimplePolygon2D()
{
}
SimplePolygon2D::SimplePolygon2D(std::vector<Seg2D> InitializationSegments)
{
 
}
SimplePolygon2D::SimplePolygon2D(const SimplePolygon2D& obj)
{
}
SimplePolygon2D::SimplePolygon2D(SimplePolygon2D&& obj)
{
}
SimplePolygon2D ::      ~SimplePolygon2D()
{

}
 
/* logical operators */
bool SimplePolygon2D::operator < (const SimplePolygon2D& operand)
{
        return true;
}
 
bool SimplePolygon2D::operator > (const SimplePolygon2D& operand)
{
        return true;
}
 
bool SimplePolygon2D::operator <= (const SimplePolygon2D& operand)
{
        return true;
}
 
bool SimplePolygon2D::operator >= (const SimplePolygon2D& operand)
{
        return true;
}
 
bool SimplePolygon2D::operator == (const SimplePolygon2D& operand)
{
        return true;
}
 
bool SimplePolygon2D::operator != (const SimplePolygon2D& operand)
{
        return true;
}
 
/*std::ostream&operator << (std::ostream& os, const SimplePolygon2D& output)
{
}
std::istream&operator >> (std::istream& is, const SimplePolygon2D& input)
{
}*/
 
struct SimplePolygon2DImplementation
{
        std::vector<Seg2D> initializationSegments;
};
 
//Geometric Primitives
 
//Geometric Primitives
 
// Functions between Segment and Point.
 
// Returns true if poi lies on the segment.
bool PointLiesOnSegment(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
// Returns true if poi PointLies above the segment.
bool PointLiesAboveSegment(Poi2D& poi, Seg2D& seg)
{
       Poi2D a = seg.p1;
       Poi2D b = seg.p2;
       Poi2D c = poi;
       Number isAntiClockWise = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
       std::cout<<"isAntiClockWise????"<<isAntiClockWise;
       //return true;
		if(isAntiClockWise >= Number("0")){
			return true;
		}else{
			return false;
		}

}
// Returns true if poi PointLies below the segment.
bool PointLiesBelowSegment(const Poi2D& poi, const Seg2D& seg)
{
       Poi2D a = seg.p1;
       Poi2D b = seg.p2;
       Poi2D c = poi;

       Number isAntiClockWise = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
       //std::cout<<"isAntiClockWise????"<<isAntiClockWise;
       //return true;
		if(isAntiClockWise <= Number("0")){
			return true;
		}else{
			return false;
		}
}
// Returns true if poi PointLies on or above the segment.
bool PointLiesAboveOrOnSegment(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
// Returns true if poi PointLies on or below the segment.
bool PointLiesBelowOrOnSegment(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
// Returns true if poi PointLies on the left end point of the segment.
bool PointLiesOnLeftEndPointOfSegment(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
// Returns true if poi PointLies on the right end point of the segment.
bool PointLiesOnRightEndPointOfSegment(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
// Returns true if poi PointLies to the left of the segment and is collinear.
bool PointLiesLeftOFSegmentAndIsCollinear(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
// Returns true if poi PointLies to the right of the segment and is collinear.
bool PointLiesRightOfSegmentAndIsCollinear(const Poi2D& poi, const Seg2D& seg)
{
        return true;
}
 
/*
Functions between segments
*/
//Returns true if seg1 lies on seg2.

bool SegmentIsLesserThanSegment(Seg2D& seg1, Seg2D& seg2)
{
		Poi2D p1 = seg1.p1;
		Poi2D p2 = seg1.p2;
		Poi2D p3 = seg2.p1;
		Poi2D p4 = seg2.p2;
        Number lengthOfSeg1 = (p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x);
        Number lengthOfSeg2 = (p4.y - p3.y)*(p4.y - p3.y) + (p4.x - p3.x)*(p4.x - p3.x);
        if(lengthOfSeg1 < lengthOfSeg2){
        	return true;
    	}else{
    		return false;
    	}
}

bool SegmentLiesOn(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
// Returns true if seg1 SegmentLies above seg2.
bool SegmentLiesAboveSegment(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
// Returns true if seg1 SegmentLies below seg2.
bool SegmentLiesBelowSegment(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
// Returns true if seg1 SegmentLies to the left of seg2.
bool SegmentLiesLeftOFSegment(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
// Returns true if seg1 SegmentLies to the right of seg2.
bool SegmentLiesRightOfSegment(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
bool SegmentIsCollinear(Seg2D& seg1, Seg2D& seg2)
{
	Number seg1slope = (seg1.p2.y - seg1.p1.y) / (seg1.p2.x - seg1.p1.x);
	Number seg2slope = (seg2.p2.y - seg2.p1.y) / (seg2.p2.x - seg2.p1.x);
	Number seg1yintercept = (seg1.p1.y) - ((seg1slope)*seg1.p1.x);
	Number seg2yintercept = (seg2.p1.y) - ((seg2slope)*seg2.p1.x);

	if (seg1slope == seg2slope && seg1yintercept == seg2yintercept)
		return true;
	else
		return false;

}
// Returns true if seg1 SegmentLies to the left and is collinear to seg2.
bool SegmentLiesLeftOFSegmentAndIsCollinear(Seg2D& seg1, Seg2D& seg2)
{
        return true;
}
// Returns true if seg1 SegmentLies to the right and is collinear to seg2.
bool SegmentLiesRightOfSegmentAndIsCollinear(Seg2D& seg1, Seg2D& seg2)
{
        return true;
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


	if (SegmentIsCollinear(seg1, seg2) && (seg1.p1 == seg2.p1)&&(seg1.p2==seg2.p2))
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
bool SegmentIsParallel(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
//Returns true if the segments are parallel and seg1 lies above seg2.
bool SegmentIsParallelAndAbove(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
//Returns true if the segments are parallel and seg1 lies below seg2
bool SegmentIsParallelAndBelow(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
//Returns true if the segments are parallel and seg1 lies to left of seg2.
bool SegmentIsParallelAndLiesLeft(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
//Returns true if the segments are parallel and seg1 lies to the right of seg2.
bool SegmentIsParallelAndLiesRight(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
//Returns true if seg1 intersects seg2.
bool Intersects(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
//Returns the point of intersection between seg1 and seg2.
Poi2D IntersectionPoint(const Seg2D& seg1, const Seg2D& seg2)
{
        return Poi2D(Number("0.0"), Number("0.0"));
}
//Returns true if the two segments have a common point.
bool Meet(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
// Returns the first common point between the two segments.
Poi2D MeetingPoint(const Seg2D& seg1, const Seg2D& seg2)
{
        return Poi2D(Number("0.0"), Number("0.0"));
}
//Returns true if a segment touches the other segment.
bool Touch(const Seg2D& seg1, const Seg2D& seg2)
{
        return true;
}
// Returns the point where the segment touches another segment.
Poi2D TouchingPoint(const Seg2D& seg1, const Seg2D& seg2)
{
        return Poi2D(Number("0.0"), Number("0.0"));
}
//Returns the midpoint of a given segment.
Poi2D MidPoint(const Seg2D& seg1)
{
        return Poi2D(Number("0.0"), Number("0.0"));
}
 
//Determines whether a point is located on theboundary of a simple polygon.
bool simplePointInsideSimplePolygon(const Poi2D& poi, const SimplePolygon2D& simplepolygon)
{
        return true;
}
//Determines whether the point is located in the interior or on the boundary of the simple polygon
bool simplePointOnBoundaryOfSimplePoly(const Poi2D& poi, const SimplePolygon2D& simplepolygon)
{
        return true;
}
//Determines whether the segment is located in the interior of the simple polygon
bool segInsideSimplePolygon(const Seg2D& seg, const SimplePolygon2D& simplepolygon)
{
        return true;
}
//Determines whether the segment is located on the boundary of the simple polygon
bool segOnBoundaryOfSimplePolygon(const Seg2D& seg, const SimplePolygon2D& simplepolygon)
{
        return true;
}
//Determines whether the segment is located in the interior and/or on the boundary of the simple polygon
bool segOnSimplePolygon(const Seg2D& seg, const SimplePolygon2D& simplepolygon)
{
        return true;
}
 
//Returns a minimum bounding rectangle for a segment
Rect2D computeRect2D(const Seg2D& seg1)
{
        return Rect2D();
}
//Returns a minimum bounding rectangle for a polygon
Rect2D computeRect2D(const SimplePolygon2D& simplepolygon)
{
        return Rect2D();
}
//Returns whether Rect2D computation is possible
bool isRect2DPossible();