#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_
#include <iostream>
#include <string>


class BigInteger
{
public:
	BigInteger();
	BigInteger(const std::string& value);
	BigInteger(const int& value);
	BigInteger(const BigInteger& obj);
	BigInteger(BigInteger&& obj);
	BigInteger operator = (const BigInteger& obj);
	BigInteger operator = (BigInteger&& obj);
	~BigInteger();
	/* mathematical operations */
	BigInteger operator + (const BigInteger& operand);
	BigInteger operator - (const BigInteger& operand);
	BigInteger operator * (const BigInteger& operand);
	BigInteger operator / (const BigInteger& operand);
	BigInteger operator % (const BigInteger& operand);
	/* logical operators */
	bool operator < (const BigInteger& operand);
	bool operator > (const BigInteger& operand);
	bool operator <= (const BigInteger& operand);
	bool operator >= (const BigInteger& operand);
	bool operator == (const BigInteger& operand);
	bool operator != (const BigInteger& operand);

	//type casting to string
	std::string toString();

	/* output */
	friend std::ostream&operator<<(std::ostream& os, const BigInteger& output);
	friend std::istream&operator>>(std::istream& is, BigInteger& input);

	/*friend function for absolute value*/
	friend BigInteger Abs(const BigInteger& operand);

private:
	struct PrivateRec;
	PrivateRec* p;
};
BigInteger GCD(BigInteger& num1, BigInteger& num2);
BigInteger LCM(BigInteger& num1, BigInteger& num2);
BigInteger Pow(BigInteger& num, int power);
//BigInteger Abs(const BigInteger& operand);

#endif