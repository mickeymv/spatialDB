#ifndef ROBUSTGEOMETRICPRIMITIVES2D_H_
#define ROBUSTGEOMETRICPRIMITIVES2D_H_

#include <iostream>
#include <vector>
#include "Number.h"

/*
*Point Class
*/

class Poi2D
{
public:
	/*Member Variables*/
	Number x;
	Number y;
	/*Member functions*/
	Poi2D();
	Poi2D(const Number& x, const Number& y);
	Poi2D(const Poi2D& obj);
	Poi2D(Poi2D&& obj);
	Poi2D operator =(const Poi2D& obj);
	Poi2D operator =(Poi2D&& obj);
	~Poi2D();

	/* Logical Operations. */
	bool operator <(const Poi2D& operand);
	bool operator >(const Poi2D& operand);
	bool operator <=(const Poi2D& operand);
	bool operator >=(const Poi2D& operand);
	bool operator ==(const Poi2D& operand);
	bool operator !=(const Poi2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const Poi2D& output);
	friend std::istream&operator>>(std::istream& is, const Poi2D& input);

};

/*
*Segment Class
*/

class Seg2D
{
public:
	/*variables*/
	Poi2D p1;
	Poi2D p2;
	/*Member Functions*/
	Seg2D();
	Seg2D(Poi2D p1, Poi2D p2);
	Seg2D(const Seg2D& obj);
	Seg2D(Seg2D&& obj);
	Seg2D operator =(const Seg2D& obj);
	Seg2D operator =(Seg2D&& obj);
	~Seg2D();
	// removed compute halfseg functions

	//Rect2D BoundingRec();

	/*logical operators*/
	bool operator <(const Seg2D& operand);
	bool operator >(const Seg2D& operand);
	bool operator <=(const Seg2D& operand);
	bool operator >=(const Seg2D& operand);
	bool operator ==(const Seg2D& operand);
	bool operator !=(const Seg2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const Seg2D& output);
	friend std::istream&operator>>(std::istream& is, const Seg2D& input);
};

/*
*HalfSegment Class
*/

class HalfSeg2D
{
public:
	/*Member Variables*/
	bool isLeft;
	Seg2D seg;
	/*Member functions*/
	HalfSeg2D();
	HalfSeg2D(Seg2D seg, bool isLeft);
	HalfSeg2D(const HalfSeg2D& obj);
	HalfSeg2D(HalfSeg2D&& obj);
	HalfSeg2D operator =(const HalfSeg2D& obj);
	HalfSeg2D operator =(HalfSeg2D&& obj);
	~HalfSeg2D();

	/* logical operations. */
	bool operator <(const HalfSeg2D& operand);
	bool operator >(const HalfSeg2D& operand);
	bool operator <=(const HalfSeg2D& operand);
	bool operator >=(const HalfSeg2D& operand);
	bool operator ==(const HalfSeg2D& operand);
	bool operator !=(const HalfSeg2D& operand);
	friend std::ostream&operator <<(std::ostream& os, const HalfSeg2D& output);
	friend std::istream&operator >>(std::istream& is, const HalfSeg2D& input);

};

/*
*Attributed Half Segment Class
*/
struct AttHalfSegVariable;
class AttrHalfSeg2D :public HalfSeg2D
{
public:
	/*Member variables */
	bool insideAbove;
	/*Member Functions */
	AttrHalfSeg2D();
	AttrHalfSeg2D(bool value, bool isLeft, Seg2D seg);
	AttrHalfSeg2D(const AttrHalfSeg2D& obj);
	AttrHalfSeg2D(AttrHalfSeg2D&& obj);
	AttrHalfSeg2D operator=(const AttrHalfSeg2D& obj);
	AttrHalfSeg2D operator=(AttrHalfSeg2D&& obj);
	~AttrHalfSeg2D();

	/*logical operators*/
	bool operator <(const AttrHalfSeg2D& operand);
	bool operator >(const AttrHalfSeg2D& operand);
	bool operator <=(const AttrHalfSeg2D& operand);
	bool operator >=(const AttrHalfSeg2D& operand);
	bool operator ==(const AttrHalfSeg2D& operand);
	bool operator !=(const AttrHalfSeg2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const AttHalfSegVariable& output);
	friend std::istream&operator>>(std::istream& is, const AttHalfSegVariable& input);

};

/*
*Minimum Bounding Rectangle Class
*/
struct Rect2DVariable;
class Rect2D
{
public:
	/*Member variables*/
	Poi2D topLeft;
	Poi2D bottomRight;
	/*Member functions*/
	Rect2D();
	Rect2D(Poi2D topLeft, Poi2D bottomRight);
	Rect2D(const Rect2D& obj);
	Rect2D(Rect2D&& obj);
	Rect2D operator=(const Rect2D& obj);
	Rect2D operator=(Rect2D&& obj);
	~Rect2D();


	friend std::ostream&operator<<(std::ostream& os, const Rect2D& output);
	friend std::istream&operator>>(std::istream& is, const Rect2D& input);

};
//Class Polygon2D
class SimplePolygon2D
{
public:
	SimplePolygon2D();
	SimplePolygon2D(std::vector<Seg2D> initializationSegments);
	SimplePolygon2D(const SimplePolygon2D& obj);
	SimplePolygon2D(SimplePolygon2D&& obj);
	~SimplePolygon2D();

	/*Logical Operators */
	bool operator <  (const SimplePolygon2D& operand);
	bool operator >  (const SimplePolygon2D& operand);
	bool operator <= (const SimplePolygon2D& operand);
	bool operator >= (const SimplePolygon2D& operand);
	bool operator == (const SimplePolygon2D& operand);
	bool operator != (const SimplePolygon2D& operand);

	/* I/O Operators*/
	friend std::ostream&operator << (std::ostream& os, const SimplePolygon2D& output);
	friend std::istream&operator >> (std::istream& is, const SimplePolygon2D& input);

private:
	struct SimplePolygon2DImplementation;
	SimplePolygon2DImplementation *handle;
};



/*
*Relationships between point and segment
*/

bool PointLiesOnSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesAboveSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesBelowSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesAboveOrOnSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesBelowOrOnSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesOnLeftEndPointOfSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesOnRightEndPointOfSegment(const Poi2D& poi, const Seg2D& seg);
bool PointLiesLeftOFSegmentAndIsCollinear(const Poi2D& poi, const Seg2D& seg);
bool PointLiesRightOfSegmentAndIsCollinear(const Poi2D& poi, const Seg2D& seg);

/*
*Relationships between Segments
*/
bool SegmentLiesOn(const Seg2D& seg, const Seg2D& seg1);
bool SegmentLiesAboveSegment(const Seg2D& seg, const Seg2D& seg1);
bool SegmentLiesBelowSegment(const Seg2D& seg, const Seg2D& seg1);
bool SegmentLiesLeftOFSegment(const Seg2D& seg, const Seg2D& seg1);
bool SegmentLiesRightOfSegment(const Seg2D& seg, const Seg2D& seg1);
bool SegmentLiesLeftOFSegmentAndIsCollinear(const Seg2D& seg, const Seg2D& seg1);
bool SegmentLiesRightOfSegmentAndIsCollinear(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsCollinearAndMeetsLeftEndpoint(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsCollinearAndMeetsRightEndpoint(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsCollinearAndCrossesLeftEndpoint(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsCollinearAndCrossesRightEndpoint(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsCollinearAndMeetsBothEndpoint(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsParallel(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsParallelAndAbove(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsParallelAndBelow(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsParallelAndLiesLeft(const Seg2D& seg, const Seg2D& seg1);
bool SegmentIsParallelAndLiesRight(const Seg2D& seg, const Seg2D& seg1);
bool Intersects(const Seg2D& seg, const Seg2D& seg1);
Poi2D IntersectionPoint(const Seg2D& seg, const Seg2D& seg1);
bool Meet(const Seg2D& seg, const Seg2D& seg1);
Poi2D MeetingPoint(const Seg2D& seg, const Seg2D& seg1);
bool Touch(const Seg2D& seg, const Seg2D& seg1);
Poi2D TouchingPoint(const Seg2D& seg, const Seg2D& seg1);
Poi2D MidPoint(const Seg2D& seg1);

//Determines whether a point is located on theboundary of a simple polygon.
bool simplePointInsideSimplePolygon(const Poi2D& poi, const SimplePolygon2D& simplepolygon);
//Determines whether the point is located in the interior or on the boundary of the simple polygon 
bool simplePointOnBoundaryOfSimplePoly(const Poi2D& poi, const SimplePolygon2D& simplepolygon);
//Determines whether the segment is located in the interior of the simple polygon 
bool segInsideSimplePolygon(const Seg2D& seg, const SimplePolygon2D& simplepolygon);
//Determines whether the segment is located on the boundary of the simple polygon 
bool segOnBoundaryOfSimplePolygon(const Seg2D& seg, const SimplePolygon2D& simplepolygon);
//Determines whether the segment is located in the interior and/or on the boundary of the simple polygon
bool segOnSimplePolygon(const Seg2D& seg, const SimplePolygon2D& simplepolygon);

//Returns a minimum bounding rectangle for a segment
Rect2D computeRect2D(const Seg2D& seg);
//Returns a minimum bounding rectangle for a polygon
Rect2D computeRect2D(const SimplePolygon2D& simplepolygon);
//Returns whether Rect2D computation is possible
bool isRect2DPossible();
#endif


