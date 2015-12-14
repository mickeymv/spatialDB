#ifndef BIGRATIONAL_H_
#define BIGRATIONAL_H_

#include <iostream>
#include <string>

class BigRational
{
public:
	BigRational();
	BigRational(std::string num, std::string den);
	BigRational(const BigRational& obj);
	BigRational(BigRational&& obj);
	BigRational operator=(const BigRational& obj);
	BigRational operator=(BigRational&& obj);
	~BigRational();
	/* mathematical operations */
	BigRational operator + (const BigRational& operand);	
	BigRational operator - (const BigRational& operand);
	BigRational operator * (const BigRational& operand);
	BigRational operator / (const BigRational& operand);

	/* logical operators */
	bool operator < (const BigRational& operand);
	bool operator > (const BigRational& operand);
	bool operator <= (const BigRational& operand);
	bool operator >= (const BigRational& operand);
	bool operator == (const BigRational& operand);
	bool operator != (const BigRational& operand);

	/* output */
	friend std::ostream&operator<<(std::ostream& os, const BigRational& output);
	friend std::istream&operator>>(std::istream& is, const BigRational& input);

	//internal function

	std::string toDecimalString(int numberOfDecimals);
	std::string toFractionString();

private:
	struct PrivateRec;
	PrivateRec * p;
};

#endif
