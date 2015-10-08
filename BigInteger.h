#pragma once

#include"BigRational.h"
#include<iostream>

class BigRational;

class BigInteger
{
public:
	BigInteger();
	BigInteger(int value);
	~BigInteger();
	/* mathematical operations */
	BigInteger operator+(const BigInteger &operand);
	BigInteger operator-(const BigInteger& operand);
	BigInteger operator*(const BigInteger& operand);
	BigInteger operator/(const BigInteger& operand);
	BigInteger operator%(const BigInteger& operand);

	/* mathematical operations with BigRational*/
	BigRational operator+(const BigRational &operand);
	BigRational operator-(const BigRational& operand);
	BigRational operator*(const BigRational& operand);
	BigRational operator/(const BigRational& operand);

	/* logical operators */
	bool operator<(const BigInteger& operand);
	bool operator>(const BigInteger& operand);
	bool operator<=(const BigInteger& operand);
	bool operator>=(const BigInteger& operand);
	bool operator==(const BigInteger& operand);
	bool operator!=(const BigInteger& operand);

	/* logical operators with BigRational*/
	bool operator<(const BigRational& operand);
	bool operator>(const BigRational& operand);
	bool operator<=(const BigRational& operand);
	bool operator>=(const BigRational& operand);
	bool operator==(const BigRational& operand);
	bool operator!=(const BigRational& operand);

	/* output */
	friend std::ostream&operator<<(std::ostream& os, const BigInteger& output);
	friend BigInteger HCF(BigInteger& , BigInteger& );
	friend BigInteger LCM(BigInteger& , BigInteger& );

	int getvalue() const;

private:
	int value;
};


/* HCF and LCM*/

/**/


inline std::ostream& operator<<(std::ostream& os, const BigInteger& output)
{
	os << output.value;
	return os;
}
