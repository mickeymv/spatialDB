#include "Number.h"
#include "BigRational.h"

struct Number::PrivateRec
{
	BigRational value;
	//float value;
};
Number::Number()
{
	p = new PrivateRec;
	p->value = BigRational("0", "1");
}

Number::Number(std::string value)
{
	int count = 0;
	std::string num = "", den = "";
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
			den = "1";
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
	/*float val = std::stof(value);
	p = new PrivateRec;
	p->value = val;*/

}

Number::Number(const Number& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
}

Number::Number(Number&& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
	obj.p->value = BigRational("0", "1");
}

Number Number::operator=(const Number& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
	}
	return *this;
}

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