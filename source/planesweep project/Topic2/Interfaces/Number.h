#ifndef NUMBER_H_
#define NUMBER_H_

#include <iostream>
#include <string>

struct PrivateRec;
class Number
{
private:
	PrivateRec * p;

public:
	Number();
	Number(float value);
	//Number(std::string value);
	Number(const Number& obj);
	Number(const Number&& obj);
	Number operator=(const Number& obj);
	//Number operator=(const Number&& obj);
	~Number();

	/*mathematical operations*/
	Number operator+(const Number& operand);
	Number operator-(const Number& operand);
	Number operator*(const Number& operand);
	Number operator/(const Number& operand);

	/*logical operations*/
	bool operator<(const Number& operand);
	bool operator>(const Number& operand);
	bool operator<=(const Number& operand);
	bool operator>=(const Number& operand);
	bool operator==(const Number& operand);
	bool operator!=(const Number& operand);

	friend std::ostream&operator<<(std::ostream& os, const Number& output);
	friend std::istream&operator>>(std::istream& is, const Number& input);
};



#endif