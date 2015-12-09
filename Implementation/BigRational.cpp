#include "BigRational.h"
#include "BigInteger.h"

struct BigRational::PrivateRec
{
	BigInteger numerator;
	BigInteger denominator;
};

BigRational::BigRational()
{
	p = new PrivateRec;
	p->numerator = BigInteger("0");
	p->denominator = BigInteger("1");
}

BigRational::BigRational(std::string num, std::string den)
{
	p = new PrivateRec;
	p->numerator = BigInteger(num);
	p->denominator = BigInteger(den);
}

BigRational::BigRational(const BigRational& obj)
{
	p = new PrivateRec;
	p->numerator = obj.p->numerator;
	p->denominator = obj.p->denominator;
}

BigRational::BigRational(BigRational&& obj)
{
	p = new PrivateRec;
	p->numerator = obj.p->numerator;
	p->denominator = obj.p->denominator;
	obj.p->numerator = BigInteger("0");
	obj.p->denominator = BigInteger("0");
}

BigRational BigRational::operator=(const BigRational& obj)
{
	if (this != &obj)
	{
		this->p->numerator = obj.p->numerator;
		this->p->denominator = obj.p->denominator;
	}
	return *this;
}

BigRational BigRational::operator=(BigRational&& obj)
{
	if (this != &obj)
	{
		this->p->numerator = obj.p->numerator;
		this->p->denominator = obj.p->denominator;
		obj.p->numerator = BigInteger("0");
		obj.p->denominator = BigInteger("0");
	}
	return *this;
}

BigRational::~BigRational()
{
	delete p;
}

BigRational BigRational::operator+(const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->denominator;
	answer.p->numerator = (this->p->numerator * operand.p->denominator) + (this->p->denominator * operand.p->numerator);
	BigInteger hcf = GCD(answer.p->denominator, answer.p->numerator);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

BigRational BigRational::operator-(const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->denominator;
	answer.p->numerator = (this->p->numerator * operand.p->denominator) - (this->p->denominator * operand.p->numerator);
	BigInteger hcf = GCD(answer.p->denominator, answer.p->numerator);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

BigRational BigRational::operator*(const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->denominator;
	answer.p->numerator = this->p->numerator * operand.p->numerator;
	BigInteger hcf = GCD(answer.p->denominator, answer.p->numerator);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

BigRational BigRational::operator/(const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->numerator;
	answer.p->numerator = this->p->numerator * operand.p->denominator;
	BigInteger hcf = GCD(answer.p->denominator, answer.p->numerator);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

bool BigRational::operator<(const BigRational& operand)
{
	BigInteger thisNumber = this->p->numerator * operand.p->denominator;
	BigInteger compareWith = operand.p->numerator* this->p->denominator;
	if (thisNumber<compareWith)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool BigRational::operator>(const BigRational& operand)
{
	BigInteger thisNumber = this->p->numerator * operand.p->denominator;
	BigInteger compareWith = operand.p->numerator* this->p->denominator;
	if (thisNumber>compareWith)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigRational::operator<=(const BigRational& operand)
{
	BigInteger thisNumber = this->p->numerator * operand.p->denominator;
	BigInteger compareWith = operand.p->numerator* this->p->denominator;
	if (thisNumber <= compareWith)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigRational::operator>=(const BigRational& operand)
{
	BigInteger thisNumber = this->p->numerator * operand.p->denominator;
	BigInteger compareWith = operand.p->numerator* this->p->denominator;
	if (thisNumber >= compareWith)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigRational::operator==(const BigRational& operand)
{
	BigInteger thisNumber = this->p->numerator * operand.p->denominator;
	BigInteger compareWith = operand.p->numerator* this->p->denominator;
	if (thisNumber == compareWith)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigRational::operator!=(const BigRational& operand)
{
	BigInteger thisNumber = this->p->numerator * operand.p->denominator;
	BigInteger compareWith = operand.p->numerator* this->p->denominator;
	if (thisNumber != compareWith)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream&operator<<(std::ostream& os, const BigRational& output)
{
	os << output.p->numerator << "/" << output.p->denominator;
	return os;
}

std::istream&operator>>(std::istream& is, const BigRational& input)
{
	is >> input.p->numerator >> input.p->denominator;
	//os << output.p->numerator << "/" << output.p->denominator;
	return is;
}
