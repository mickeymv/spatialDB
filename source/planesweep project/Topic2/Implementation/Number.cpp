#include "Number.h"
#include "BigRational.h"

struct Number::PrivateRec
{
	BigRational value;
};

//the default constructor initializes the BigRational inner value as 
//zero
Number::Number()
{
	p = new PrivateRec;
	p->value = BigRational("0", "1");
}


//A string is taken and the respective numeratio and denominator
//are extracted from it. the default denominator will be one (if
//the number has no decimal numbers)
Number::Number(std::string value)
{
	int count = 0;
	std::string num = "", den = "1";
	for (int i = 0; i < value.length(); i++)
	{
		if (value.at(i) == '.')
		{
			count++;
			if (count>1)
			{
				std::cout << "wrong input";
				return;
			}
		}
		else
		{
			num += value.at(i);
			if (count == 1)
			{
				den += "0";
			}
		}
	}
	this->p = new PrivateRec;
	this->p->value = BigRational(num, den);

}

//copy constructor
Number::Number(const Number& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
}

//move constructor. the source becomes zero
Number::Number(Number&& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
	obj.p->value = BigRational("0", "1");
}

//copy operator overloaded
Number Number::operator=(const Number& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
	}
	return *this;
}

//move operator overloaded
Number Number::operator=(Number&& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
		obj.p->value = BigRational("0", "1");
	}
	return *this;
}

Number::~Number()
{
	delete p;
}

/*MATHEMATICAL OPERATIONS*/
//the calculations just use the BigRational operators to return a result. 
//The operations are self explanatory
Number Number::operator + (const Number& operand)
{
	Number answer;
	answer.p->value = p->value + operand.p->value;
	return answer;
}

Number Number::operator - (const Number& operand)
{
	Number answer;
	answer.p->value = p->value - operand.p->value;
	return answer;
}

Number Number::operator * (const Number& operand)
{
	Number answer;
	answer.p->value = p->value * operand.p->value;
	return answer;
}

Number Number::operator / (const Number& operand)
{
	Number answer;
	answer.p->value = p->value / operand.p->value;
	return answer;
}

/*LOGICAL OPERATIONS*/
//all logical operations again use the inner BigRational 
//operators to check for true or false. 
bool Number::operator < (const Number&operand)
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
bool Number::operator > (const Number&operand)
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
bool Number::operator <= (const Number&operand)
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
bool Number::operator >= (const Number&operand)
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
bool Number::operator == (const Number&operand)
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
bool Number::operator != (const Number&operand)
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

//output the decimal representation of the BigRational Number.
std::ostream& operator<<(std::ostream& os, const Number& output)
{
	os << output.p->value.toDecimalString(10);
	return os;
}

//take input as a string value and return the BigRational.
std::istream&operator>>(std::istream& is, Number& input)
{
	std::string in;
	is >> in;
	input = Number(in);
	return is;
}