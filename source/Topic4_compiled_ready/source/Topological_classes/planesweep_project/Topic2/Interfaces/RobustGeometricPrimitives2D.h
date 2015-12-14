#ifndef ROBUSTGEOMETRICPRIMITIVES2D_H_
#define ROBUSTGEOMETRICPRIMITIVES2D_H_

#include <iostream>
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
	//Poi2D(Poi2D&& obj);
	Poi2D operator=(const Poi2D& obj);
	//Poi2D operator=(Poi2D&& obj);
	~Poi2D();

	/* Logical Operations. */
	bool operator<(const Poi2D& operand);
	bool operator>(const Poi2D& operand);
	bool operator<=(const Poi2D& operand);
	bool operator>=(const Poi2D& operand);
	bool operator==(const Poi2D& operand);
	bool operator!=(const Poi2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const Poi2D& output);
	friend std::istream&operator>>(std::istream& is, const Poi2D& input);

};

/*
*Segment Class
*/
class HalfSeg2D;
class MBR;
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
	//Seg2D(const Seg2D&& obj);
	Seg2D operator=(const Seg2D& obj);
	//Seg2D operator=(const Seg2D&& obj);
	~Seg2D();
	// Replacing GetLeftHalfSegment with ComputeLeftHalfSegment and so on for right
	HalfSeg2D ComputeLeftHalfSegment();
	HalfSeg2D ComputeRightHalfSegment();

	//MBR BoundingRec();
	MBR computeMBB();
	bool MBRPossible();//returns whether MBR computation is possible?
	/*logical operators*/
	bool meets(const Seg2D& operand);
	
	
	bool operator<(const Seg2D& operand);
	bool operator>(const Seg2D& operand);
	bool operator<=(const Seg2D& operand);
	bool operator>=(const Seg2D& operand);
	bool operator==(const Seg2D& operand);
	bool operator!=(const Seg2D& operand);
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
	Poi2D dominatingPoint;
	/*Member functions*/
	HalfSeg2D();
	HalfSeg2D(Poi2D dominatingPoint, bool isLeft);
	HalfSeg2D(const HalfSeg2D& obj);
	//HalfSeg2D(const HalfSeg2D&& obj);
	HalfSeg2D operator=(const HalfSeg2D& obj);
	//HalfSeg2D operator=(const HalfSeg2D&& obj);
	~HalfSeg2D();

	/* logical operations. */
	bool operator<(const HalfSeg2D& operand);
	bool operator>(const HalfSeg2D& operand);
	bool operator<=(const HalfSeg2D& operand);
	bool operator>=(const HalfSeg2D& operand);
	bool operator==(const HalfSeg2D& operand);
	bool operator!=(const HalfSeg2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const HalfSeg2D& output);
	friend std::istream&operator>>(std::istream& is, const HalfSeg2D& input);

};

/*
*Attributed Half Segment Class
*/
struct AttHalfSegVariable;
class AttrHalfSeg2D :public HalfSeg2D
{
public:
	/*Member variables */
	bool regionInside;
	/*Member Functions */
	AttrHalfSeg2D();
	AttrHalfSeg2D(bool value, bool isDirectionLeft, Poi2D dominatingPoint);
	AttrHalfSeg2D(const AttrHalfSeg2D& obj);
	//AttrHalfSeg2D(const AttrHalfSeg2D&& obj);
	AttrHalfSeg2D operator=(const AttrHalfSeg2D& obj);
	//AttrHalfSeg2D operator=(const AttrHalfSeg2D&& obj);
	~AttrHalfSeg2D();

	/*logical operators*/
	bool operator<(const AttrHalfSeg2D& operand);
	bool operator>(const AttrHalfSeg2D& operand);
	bool operator<=(const AttrHalfSeg2D& operand);
	bool operator>=(const AttrHalfSeg2D& operand);
	bool operator==(const AttrHalfSeg2D& operand);
	bool operator!=(const AttrHalfSeg2D& operand);
	friend std::ostream&operator<<(std::ostream& os, const AttHalfSegVariable& output);
	friend std::istream&operator>>(std::istream& is, const AttHalfSegVariable& input);

};

/*
*Minimum Bounding Rectangle Class
*/
struct MBRVariable;
class MBR
{
public:
	/*Member variables*/
	Poi2D topLeft;
	Poi2D topRight;
	Poi2D bottomLeft;
	Poi2D bottomRight;
	/*Member functions*/
	MBR();
	MBR(Poi2D topLeft, Poi2D bottomRight);
	MBR(const MBR& obj);
	//MBR(const MBR&& obj);
	MBR operator=(const MBR& obj);
	//MBR operator=(const MBR&& obj);
	~MBR();
	friend std::ostream&operator<<(std::ostream& os, const MBR& output);
	friend std::istream&operator>>(std::istream& is, const MBR& input);

};


/*
*Relationships between point and segment
*/

bool LiesOnSegment(Poi2D poi, Seg2D seg);
bool LiesAboveSegment(Poi2D poi, Seg2D seg);
bool LiesBelowSegment(Poi2D poi, Seg2D seg);
bool LiesAboveOrOnSegment(Poi2D poi, Seg2D seg);
bool LiesBelowOrOnSegment(Poi2D poi, Seg2D seg);
bool LiesOnLeftEndPointOfSegment(Poi2D poi, Seg2D seg);
bool LiesOnRightEndPointOfSegment(Poi2D poi, Seg2D seg);
bool LiesLeftOFSegmentAndIsCollinear(Poi2D poi, Seg2D seg);
bool LiesRightOfSegmentAndIsCollinear(Poi2D poi, Seg2D seg);

/*
*Relationships between Segments
*/
bool LiesOn(Seg2D seg, Seg2D seg1);
bool LiesAboveSegment(Seg2D seg, Seg2D seg1);
bool LiesBelowSegment(Seg2D seg, Seg2D seg1);
bool LiesLeftOFSegment(Seg2D seg, Seg2D seg1);
bool LiesRightOfSegment(Seg2D seg, Seg2D seg1);
bool LiesLeftOFSegmentAndIsCollinear(Seg2D seg, Seg2D seg1);
bool LiesRightOfSegmentAndIsCollinear(Seg2D seg, Seg2D seg1);
bool IsCollinearAndMeetsLeftEndpoint(Seg2D seg1, Seg2D seg2);
bool IsCollinearAndMeetsRightEndpoint(Seg2D seg1, Seg2D seg2);
bool IsCollinearAndCrossesLeftEndpoint(Seg2D seg1, Seg2D seg2);
bool IsCollinearAndCrossesRightEndpoint(Seg2D seg1, Seg2D seg2);
bool IsCollinearAndMeetsBothEndpoint(Seg2D seg1, Seg2D seg2);
bool isParallel(Seg2D seg1, Seg2D seg2);
bool isParallelAndAbove(Seg2D seg1, Seg2D seg2);
bool isParallelAndBelow(Seg2D seg1, Seg2D seg2);
bool isParallelAndLiesLeft(Seg2D seg1, Seg2D seg2);
bool isParallelAndLiesRight(Seg2D seg1, Seg2D seg2);
bool Intersects(Seg2D seg1, Seg2D seg2);
Poi2D IntersectionPoint(Seg2D seg1, Seg2D seg2);
bool Meet(Seg2D seg1, Seg2D seg2);
Poi2D MeetingPoint(Seg2D seg1, Seg2D seg2);
bool Touch(Seg2D seg1, Seg2D seg2);
Poi2D TouchingPoint(Seg2D seg1, Seg2D seg2);
Poi2D MidPoint(Seg2D seg1);
#endif


