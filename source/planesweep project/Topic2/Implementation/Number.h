#ifndef NUMBER_H_
#define NUMBER_H_

#include <iostream>
#include <string>


class Number
{

public:
	Number();
	Number(std::string value);
	Number(const Number& obj);
	Number(Number&& obj);
	Number operator=(const Number& obj);
	Number operator=(Number&& obj);
	~Number();

	/*mathematical operations*/
	Number operator + (const Number& operand);
	Number operator - (const Number& operand);
	Number operator * (const Number& operand);
	Number operator / (const Number& operand);

	/*logical operations*/
	bool operator < (const Number& operand);
	bool operator > (const Number& operand);
	bool operator <= (const Number& operand);
	bool operator >= (const Number& operand);
	bool operator == (const Number& operand);
	bool operator != (const Number& operand);

	friend std::ostream&operator<<(std::ostream& os, const Number& output);
	friend std::istream&operator>>(std::istream& is, Number& input);

private:
	struct PrivateRec;
	PrivateRec * p;

};



#endif