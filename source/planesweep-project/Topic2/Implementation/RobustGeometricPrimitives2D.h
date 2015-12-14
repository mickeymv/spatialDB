
/*---------------------------------------------------------------------------------
* File: RobustGeometricPrimitives2D.h
-----------------------------------------------------------------------------------
- Description:
- 
- This file contains the definitions of the Spatial datatypes Poi2D,Seg2D,
- HalfSeg2D,AttrHalfSeg2D,Rect2D and SimplePolygon2D and additional helper
- functions.
- 
- Created by:
- Prerna Mandal, Sivasubramanian Kandaswami, Umar Majeed, Jyotsana Walia
------------------------------------------------------------------------------------*/


#ifndef ROBUSTGEOMETRICPRIMITIVES2D_H_ 
#define ROBUSTGEOMETRICPRIMITIVES2D_H_

#include <iostream>
#include <vector>
#include "Number.h"


/*
*Point Class
*/

class AttrHalfSeg2D;
class HalfSeg2D;
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
	bool operator < (HalfSeg2D& operand);
	bool operator > (HalfSeg2D& operand);
	bool operator <(AttrHalfSeg2D& operand);
	bool operator >(AttrHalfSeg2D& operand);
	bool operator >(const Poi2D& operand);
	bool operator <=(const Poi2D& operand);
	bool operator >=(const Poi2D& operand);
	bool operator ==(const Poi2D& operand);
	bool operator !=(const Poi2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const Poi2D& output);
	friend std::istream&operator>>(std::istream& is, Poi2D& input);

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
	friend std::istream&operator>>(std::istream& is, Seg2D& input);
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
	bool operator <(Poi2D& operand);
	bool operator >(Poi2D& operand);
	bool operator <(AttrHalfSeg2D& operand);
	bool operator >(AttrHalfSeg2D& operand);
	bool operator >(const HalfSeg2D& operand);
	bool operator <=(const HalfSeg2D& operand);
	bool operator >=(const HalfSeg2D& operand);
	bool operator ==(const HalfSeg2D& operand);
	bool operator !=(const HalfSeg2D& operand);
	Poi2D dominatingPoint();
	friend std::ostream&operator <<(std::ostream& os, const HalfSeg2D& output);
	friend std::istream&operator >>(std::istream& is, HalfSeg2D& input);

};

/*
*Attributed Half Segment Class
*/
struct AttHalfSegVariable;
class AttrHalfSeg2D
{
public:
	/*Member variables */
	HalfSeg2D hseg;
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
	bool operator <(Poi2D& operand);
	bool operator >(Poi2D& operand);
	bool operator <(HalfSeg2D& operand);
	bool operator >(HalfSeg2D& operand);
	bool operator <=(const AttrHalfSeg2D& operand);
	bool operator >=(const AttrHalfSeg2D& operand);
	bool operator ==(const AttrHalfSeg2D& operand);
	bool operator !=(const AttrHalfSeg2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const AttrHalfSeg2D& output);
	friend std::istream&operator>>(std::istream& is, AttHalfSegVariable& input);

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


	friend std::ostream&operator<<(std::ostream& os, Rect2D& output);
	friend std::istream&operator>>(std::istream& is, Rect2D& input);

};
//Class Polygon2D
class SimplePolygon2D
{
public:
	std::vector<Poi2D> vertices;

	SimplePolygon2D();
	SimplePolygon2D(std::vector<Poi2D> vertices);
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
	friend std::ostream&operator << (std::ostream& os, SimplePolygon2D& output);
	friend std::istream&operator >> (std::istream& is, SimplePolygon2D& input);

};



/*
*Relationships between point and segment
*/

bool PointLiesOnSegment(Poi2D& poi, Seg2D& seg);
Poi2D getPointLiesOnSegmentAndNotEndpoints(Poi2D& poi, Seg2D& seg);
bool PointLiesOnSegmentAndNotEndpoints(Poi2D& poi, Seg2D& seg);
bool PointLiesAboveSegment(Poi2D& poi, Seg2D& seg);
bool PointLiesBelowSegment(Poi2D& poi, Seg2D& seg);
bool PointLiesAboveOrOnSegment(Poi2D& poi, Seg2D& seg);
bool PointLiesBelowOrOnSegment(Poi2D& poi, Seg2D& seg);
bool PointLiesOnLeftEndPointOfSegment(Poi2D& poi, Seg2D& seg);
bool PointLiesOnRightEndPointOfSegment(Poi2D& poi, Seg2D& seg);
bool PointIsCollinearToSegment(Poi2D& poi, Seg2D& seg);
bool PointLiesLeftOFSegmentAndIsCollinear(Poi2D& poi, Seg2D& seg);
bool PointLiesRightOfSegmentAndIsCollinear(Poi2D& poi, Seg2D& seg);

/*
*Relationships between Segments
*/
bool SegmentLiesOnSegment(Seg2D& seg, Seg2D& seg1);
bool SegmentLiesAboveSegment(Seg2D& seg, Seg2D& seg1);
bool SegmentLiesBelowSegment(Seg2D& seg, Seg2D& seg1);
bool SegmentLiesLeftOFSegment(Seg2D& seg, Seg2D& seg1);
bool SegmentLiesRightOfSegment(Seg2D& seg, Seg2D& seg1);
bool SegmentIsCollinear(Seg2D& seg, Seg2D& seg1);
bool SegmentLiesLeftOFSegmentAndIsCollinear(Seg2D& seg, Seg2D& seg1);
bool SegmentLiesRightOfSegmentAndIsCollinear(Seg2D& seg, Seg2D& seg1);
bool SegmentIsCollinearAndMeetsLeftEndpoint(Seg2D& seg, Seg2D& seg1);
bool SegmentIsCollinearAndMeetsRightEndpoint(Seg2D& seg, Seg2D& seg1);
bool SegmentIsCollinearAndCrossesLeftEndpoint(Seg2D& seg, Seg2D& seg1);
bool SegmentIsCollinearAndCrossesRightEndpoint(Seg2D& seg, Seg2D& seg1);
bool SegmentIsCollinearAndMeetsBothEndpoint(Seg2D& seg, Seg2D& seg1);
bool SegmentIsParallel(Seg2D& seg, Seg2D& seg1);
bool SegmentIsParallelAndAbove(Seg2D& seg, Seg2D& seg1);
bool SegmentIsParallelAndBelow(Seg2D& seg, Seg2D& seg1);
bool SegmentIsParallelAndLiesLeft(Seg2D& seg, Seg2D& seg1);
bool SegmentIsParallelAndLiesRight(Seg2D& seg, Seg2D& seg1);
bool Intersects(Seg2D& seg, Seg2D& seg1);
int orientation(Poi2D p, Poi2D q, Poi2D r);
bool SegmentIsLesserThanSegment(Seg2D& seg1, Seg2D& seg2);
Poi2D IntersectionPoint(Seg2D& seg, Seg2D& seg1);
bool IntersectsAndNotCollinearAndNotEndpoints(Seg2D& seg1, Seg2D& seg2);
bool Meet(Seg2D& seg, Seg2D& seg1);
Poi2D MeetingPoint(Seg2D& seg, Seg2D& seg1);
bool Touch(Seg2D& seg, Seg2D& seg1);
Poi2D TouchingPoint(Seg2D& seg, Seg2D& seg1);
Poi2D MidPoint(Seg2D& seg1);
bool BasicPointInBoundingBox(Poi2D& poi, SimplePolygon2D& polygon);

//Determines whether a point is located on theboundary of a simple polygon.
bool simplePointInsideSimplePolygon(Poi2D& poi, SimplePolygon2D& simplepolygon);
//Determines whether the point is located in the interior or on the boundary of the simple polygon 
bool simplePointOnBoundaryOfSimplePoly(Poi2D& poi, SimplePolygon2D& simplepolygon);
//Determines whether the segment is located in the interior of the simple polygon 
bool segInsideSimplePolygon(Seg2D& seg,SimplePolygon2D& simplepolygon);
//Determines whether the segment is located on the boundary of the simple polygon 
bool segOnBoundaryOfSimplePolygon(Seg2D& seg, SimplePolygon2D& simplepolygon);

//Returns a minimum bounding rectangle for a segment
Rect2D computeRect2D(Seg2D& seg);
//Returns a minimum bounding rectangle for a polygon
Rect2D computeRect2D(SimplePolygon2D& simplepolygon);
//Returns whether Rect2D computation is possible
bool isRect2DPossible();

#endif
