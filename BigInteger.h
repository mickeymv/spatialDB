#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_

#include <iostream>
#include <string>


class BigInteger
{
public:
	BigInteger();
	BigInteger(std::string value);
	BigInteger(const BigInteger& obj);
	BigInteger(BigInteger&& obj);
	BigInteger operator=(const BigInteger& obj);
	BigInteger operator=(BigInteger&& obj);
	~BigInteger();
	/* mathematical operations */
	BigInteger operator+(const BigInteger& operand);

	BigInteger operator-(const BigInteger& operand);

	BigInteger operator*(const BigInteger& operand);

	BigInteger operator/(const BigInteger& operand);

	BigInteger operator%(const BigInteger& operand);

	/* logical operators */
	bool operator<(const BigInteger& operand);

	bool operator>(const BigInteger& operand);

	bool operator<=(const BigInteger& operand);

	bool operator>=(const BigInteger& operand);

	bool operator==(const BigInteger& operand);

	bool operator!=(const BigInteger& operand);

	/* output */
	friend std::ostream&operator<<(std::ostream& os, const BigInteger& output);
	friend std::istream&operator>>(std::istream& is, const BigInteger& input);
	/*friend BigInteger GCD(BigInteger&, BigInteger&);
	friend BigInteger LCM(BigInteger&, BigInteger&);*/

private:
	struct PrivateRec;
	PrivateRec* p;
};

BigInteger GCD(BigInteger& num1, BigInteger& num2);
BigInteger LCM(BigInteger& num1, BigInteger& num2);
#endif

