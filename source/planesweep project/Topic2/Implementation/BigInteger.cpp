#include "BigInteger.h"

struct BigInteger::PrivateRec
{
	int value;
};

BigInteger::BigInteger()
{
	p = new PrivateRec;
	this->p->value = 0;
}

BigInteger::~BigInteger()
{
	delete p;
}

BigInteger::BigInteger(std::string value)
{
	p = new PrivateRec;
	int val = std::stoi(value);
	this->p->value = val;
}

BigInteger::BigInteger(const BigInteger& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
}
BigInteger::BigInteger(BigInteger&& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
	obj.p->value = 0;
}
BigInteger BigInteger::operator=(const BigInteger& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
	}
	return *this;
}
BigInteger BigInteger::operator=(BigInteger&& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
		obj.p->value = 0;
	}
	return *this;
}


/*mathematical operations*/
//addition
BigInteger BigInteger::operator+(const BigInteger& operand)
{
	BigInteger answer;
	answer.p->value = this->p->value + operand.p->value;
	return answer;
}

//subtraction
BigInteger BigInteger::operator-(const BigInteger& operand)
{
	BigInteger answer;
	answer.p->value = this->p->value - operand.p->value;
	return answer;
}

//multiplication
BigInteger BigInteger::operator*(const BigInteger& operand)
{
	BigInteger answer;
	answer.p->value = this->p->value * operand.p->value;
	return answer;
}

//division
BigInteger BigInteger::operator/(const BigInteger& operand)
{
	BigInteger answer;
	answer.p->value = this->p->value / operand.p->value;
	return answer;
}

//modulus
BigInteger BigInteger::operator%(const BigInteger& operand)
{
	BigInteger answer;
	answer.p->value = this->p->value % operand.p->value;
	return answer;
}

/* logical operations */

//<
bool BigInteger::operator<(const BigInteger&operand)
{
	if (this->p->value < operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//>
bool BigInteger::operator>(const BigInteger&operand)
{
	if (this->p->value > operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//<=
bool BigInteger::operator<=(const BigInteger&operand)
{
	if (this->p->value <= operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//>=
bool BigInteger::operator>=(const BigInteger&operand)
{
	if (this->p->value >= operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//==
bool BigInteger::operator==(const BigInteger&operand)
{
	if (this->p->value == operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//!=
bool BigInteger::operator!=(const BigInteger&operand)
{
	if (this->p->value != operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

BigInteger LCM(BigInteger& num1, BigInteger& num2)
{
	BigInteger i(num2);
	while ((num2%num1) != BigInteger("0"))
	{
		num2 = num2 + i;
	}
	return num2;
}


BigInteger GCD(BigInteger& num1, BigInteger& num2)
{
	if (num2 == BigInteger("0"))
	{
		return num1;
	}
	else
	{
		BigInteger temp = num1%num2;
		return GCD(num2, temp);
	}
}

std::ostream& operator<<(std::ostream& os, const BigInteger& output)
{
	os << output.p->value;
	return os;
}

std::istream&operator>>(std::istream& is, const BigInteger& input)
{
	is >> input.p->value;
	return is;
}