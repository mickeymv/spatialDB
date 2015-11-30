#include "Number.h"

struct PrivateRec
{
	float value;
};
Number::Number()
{
	p = new PrivateRec;
	p->value = 0;
}
Number::Number(float value)
{
	float val = value;
	p = new PrivateRec;
	p->value = val;
}
Number::Number(const Number& obj)
{

}

Number Number::operator=(const Number& obj)
{
	this->p->value = obj.p->value;
	return *this;
}
Number::~Number()
{
}

/*MATHEMATICAL OPERATIONS*/
Number Number::operator+(const Number& operand)
{
	Number answer;
	answer.p->value = p->value + operand.p->value;
	return answer;
}

Number Number::operator-(const Number& operand)
{
	Number answer;
	answer.p->value = p->value - operand.p->value;
	return answer;
}

Number Number::operator*(const Number& operand)
{
	Number answer;
	answer.p->value = p->value * operand.p->value;
	return answer;
}

Number Number::operator/(const Number& operand)
{
	Number answer;
	answer.p->value = p->value / operand.p->value;
	return answer;
}

/*LOGICAL OPERATIONS*/
bool Number::operator<(const Number&operand)
{
	if (p->value < operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//>
bool Number::operator>(const Number&operand)
{
	if (p->value > operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//<=
bool Number::operator<=(const Number&operand)
{
	if (p->value <= operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//>=
bool Number::operator>=(const Number&operand)
{
	if (p->value >= operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//==
bool Number::operator==(const Number&operand)
{
	if (p->value == operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//!=
bool Number::operator!=(const Number&operand)
{
	if (p->value != operand.p->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Number& output)
{
	os << output.p->value;
	return os;
}

std::istream&operator>>(std::istream& is, const Number& input)
{
	is >> input.p->value;
	return is;
}