#pragma once

#include "BigInteger.h"
#include<iostream>

class BigInteger;

class BigRational
{
public:
	BigRational();
	BigRational(double value);
	~BigRational();
	/* mathematical operations */
	BigRational operator+(const BigRational& operand);
	BigRational operator-(const BigRational& operand);
	BigRational operator*(const BigRational& operand);
	BigRational operator/(const BigRational& operand);

	/* mathematical operations with BigRational*/
	BigRational operator+(const BigInteger& operand);
	BigRational operator-(const BigInteger& operand);
	BigRational operator*(const BigInteger& operand);
	BigRational operator/(const BigInteger& operand);

	/* logical operators */
	bool operator<(const BigRational& operand);
	bool operator>(const BigRational& operand);
	bool operator<=(const BigRational& operand);
	bool operator>=(const BigRational& operand);
	bool operator==(const BigRational& operand);
	bool operator!=(const BigRational& operand);

	/* logical operators with BigIntegers*/
	bool operator<(const BigInteger& operand);
	bool operator>(const BigInteger& operand);
	bool operator<=(const BigInteger& operand);
	bool operator>=(const BigInteger& operand);
	bool operator==(const BigInteger& operand);
	bool operator!=(const BigInteger& operand);

	/* output */
	friend std::ostream&operator<<(std::ostream& os, const BigRational& output);

	double getvalue() const;

private:
	double value;
};



inline std:: ostream& operator<<(std::ostream& os, const BigRational& output)
{
	os << output.value;
	return os;
}
