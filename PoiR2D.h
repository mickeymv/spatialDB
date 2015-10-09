#pragma once

#include "BigRational.h"
//#include "Seg2D.h"
#include <iostream>

class Seg2D;

class PoiR2D
{
public:
	PoiR2D();
	PoiR2D(BigRational x,BigRational y);
	~PoiR2D();
	/* logical operations. */
	bool operator<(const PoiR2D& operand);
	bool operator>(const PoiR2D& operand);
	bool operator<=(const PoiR2D& operand);
	bool operator>=(const PoiR2D& operand);
	bool operator==(const PoiR2D& operand);
	bool operator!=(const PoiR2D& operand);

	/* predicates */
	bool LiesOnSegment(const Seg2D& segment);

	/* output */
	friend std::ostream&operator<<(std::ostream& os, const PoiR2D& output);

private:
	BigRational x;
	BigRational y;
};


inline std::ostream& operator<<(std::ostream& os, const PoiR2D& output)
{
	os << "("<<output.x << ", "<<output.y<<")";
	return os;
}