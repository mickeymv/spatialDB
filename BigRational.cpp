#include "BigRational.h"


BigRational::BigRational()
{
	this->value = 0.0;
}

BigRational::~BigRational()
{
}

BigRational::BigRational(double value)
{
	this->value = value;
}


//adition
BigRational BigRational::operator+(const BigRational& operand)
{
	BigRational answer;
	answer.value = this->value + operand.value;
	return answer;
}

BigRational BigRational::operator+(const BigInteger& operand)
{
	double ans = this->value + operand.getvalue();
	return BigRational(ans);
}


//subtraction
BigRational BigRational::operator-(const BigRational& operand)
{
	BigRational answer;
	answer.value = this->value - operand.value;
	return answer;
}
BigRational BigRational::operator-(const BigInteger& operand)
{
	double ans = this->value - operand.getvalue();
	return BigRational(ans);
}


//multiplication
BigRational BigRational::operator*(const BigRational& operand)
{
	BigRational answer;
	answer.value = this->value * operand.value;
	return answer;
}
BigRational BigRational::operator*(const BigInteger& operand)
{
	double ans = this->value * operand.getvalue();
	return BigRational(ans);
}


//division
BigRational BigRational::operator/(const BigRational& operand)
{
	BigRational answer;
	answer.value = this->value / operand.value;
	return answer;
}
BigRational BigRational::operator/(const BigInteger& operand)
{
	double ans = this->value / operand.getvalue();
	return BigRational(ans);
}

/* Logical operations */
//<
bool BigRational::operator<(const BigRational&operand)
{
	if (this->value < operand.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigRational::operator<(const BigInteger&operand)
{
	if (this->value < operand.getvalue())
	{
		return true;
	}
	else
	{
		return false;
	}
}


//>
bool BigRational::operator>(const BigRational&operand)
{
	if (this->value > operand.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigRational::operator>(const BigInteger&operand)
{
	if (this->value > operand.getvalue())
	{
		return true;
	}
	else
	{
		return false;
	}
}


//<=
bool BigRational::operator<=(const BigRational&operand)
{
	if (this->value <= operand.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigRational::operator<=(const BigInteger&operand)
{
	if (this->value <= operand.getvalue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//>=
bool BigRational::operator>=(const BigRational&operand)
{
	if (this->value >= operand.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigRational::operator>=(const BigInteger&operand)
{
	if (this->value >= operand.getvalue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//==
bool BigRational::operator==(const BigRational&operand)
{
	if (this->value == operand.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigRational::operator==(const BigInteger&operand)
{
	if (this->value == operand.getvalue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//!=
bool BigRational::operator!=(const BigRational&operand)
{
	if (this->value != operand.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigRational::operator!=(const BigInteger&operand)
{
	if (this->value != operand.getvalue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

double BigRational::getvalue() const
{
	return this->value;
}

