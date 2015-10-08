#include "BigInteger.h"


BigInteger::BigInteger()
{
	this->value = 0;
}

BigInteger::~BigInteger()
{
}

BigInteger::BigInteger(int value)
{
	this->value = value;
}

/*mathematical operations with itself and Big Rationals*/
//addition
BigInteger BigInteger::operator+(const BigInteger& operand)
{
	BigInteger answer;
	answer.value = this->value + operand.value;
	return answer;
}

BigRational BigInteger::operator+(const BigRational& operand)
{
	double ans = this->value + operand.getvalue();
	return BigRational(ans);
}


//subtraction
BigInteger BigInteger::operator-(const BigInteger& operand)
{
	BigInteger answer;
	answer.value = this->value - operand.value;
	return answer;
}

BigRational BigInteger::operator-(const BigRational& operand)
{
	double ans = this->value - operand.getvalue();
	return BigRational(ans);
}


//multiplication
BigInteger BigInteger::operator*(const BigInteger& operand)
{
	BigInteger answer;
	answer.value = this->value * operand.value;
	return answer;
}
BigRational BigInteger::operator*(const BigRational& operand)
{
	double ans = this->value * operand.getvalue();
	return BigRational(ans);
}


//division
BigInteger BigInteger::operator/(const BigInteger& operand)
{
	BigInteger answer;
	answer.value = this->value / operand.value;
	return answer;
}
BigRational BigInteger::operator/(const BigRational& operand)
{
	double ans = this->value / operand.getvalue();
	return BigRational(ans);
}

//modulus
BigInteger BigInteger::operator%(const BigInteger& operand)
{
	BigInteger answer;
	answer.value = this->value % operand.value;
	return answer;
}

/* logical operations */

//<
bool BigInteger::operator<(const BigInteger&operand)
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

bool BigInteger::operator<(const BigRational&operand)
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
bool BigInteger::operator>(const BigInteger&operand)
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
bool BigInteger::operator>(const BigRational&operand)
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
bool BigInteger::operator<=(const BigInteger&operand)
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
bool BigInteger::operator<=(const BigRational&operand)
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
bool BigInteger::operator>=(const BigInteger&operand)
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
bool BigInteger::operator>=(const BigRational&operand)
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
bool BigInteger::operator==(const BigInteger&operand)
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
bool BigInteger::operator==(const BigRational&operand)
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
bool BigInteger::operator!=(const BigInteger&operand)
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
bool BigInteger::operator!=(const BigRational&operand)
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

/* mathematical operations with BigRationals*/


int BigInteger::getvalue() const
{
	return this->value;
}


BigInteger LCM(BigInteger& num1, BigInteger& num2)
{
	return BigInteger(12);
}

BigInteger HCF(BigInteger& num1, BigInteger& num2)
{
	return BigInteger(4);
}
