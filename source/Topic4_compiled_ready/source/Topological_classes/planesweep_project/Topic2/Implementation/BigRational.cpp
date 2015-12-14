#include "BigRational.h"
#include "BigInteger.h"

#include <vector>

struct BigRational::PrivateRec
{
	BigInteger numerator;
	BigInteger denominator;
};

//The default constructor intializes a rational number with 
//zero number. The denominator is 1 to handle the corner case
//for division by zero. 
BigRational::BigRational()
{
	p = new PrivateRec;
	p->numerator = BigInteger("0");
	p->denominator = BigInteger("1");
}

//Initialize a BigRational number based on a numerator 
//and a denominator value both of which will be pased as strings.
BigRational::BigRational(std::string num, std::string den)
{
	p = new PrivateRec;
	p->numerator = BigInteger(num);
	p->denominator = BigInteger(den);
}

//copy constructor
BigRational::BigRational(const BigRational& obj)
{
	p = new PrivateRec;
	p->numerator = obj.p->numerator;
	p->denominator = obj.p->denominator;
}

//move constructor. The original number is reverted to a
//default value
BigRational::BigRational(BigRational&& obj)
{
	p = new PrivateRec;
	p->numerator = obj.p->numerator;
	p->denominator = obj.p->denominator;
	obj.p->numerator = BigInteger("0");
	obj.p->denominator = BigInteger("1");
}

//copy operator overloaded
BigRational BigRational::operator = (const BigRational& obj)
{
	if (this != &obj)
	{
		this->p->numerator = obj.p->numerator;
		this->p->denominator = obj.p->denominator;
	}
	return *this;
}

//move operator overloaded
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

//the addition is handled by using the BigInteger operators. 
// x/y + z/w = (x*w + z*y)/yw
//the numerator and the denominator are then divided by their
//GCD to simplify the result
BigRational BigRational::operator + (const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->denominator;
	answer.p->numerator = (this->p->numerator * operand.p->denominator) + (this->p->denominator * operand.p->numerator);
	BigInteger temp = Abs(answer.p->numerator);
	BigInteger hcf = GCD(answer.p->denominator, temp);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

//the subtractio is handled by using the BigInteger operators. 
// x/y - z/w = (x*w - z*y)/yw
//the numerator and the denominator are then divided by their
//GCD to simplify the result
BigRational BigRational::operator - (const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->denominator;
	answer.p->numerator = (this->p->numerator * operand.p->denominator) - (this->p->denominator * operand.p->numerator);
	BigInteger temp = Abs(answer.p->numerator);
	BigInteger hcf = GCD(answer.p->denominator, temp);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

//the multiplication is handled by using the BigInteger operators. 
// x/y * z/w = xz/yw
//the numerator and the denominator are then divided by their
//GCD to simplify the result
BigRational BigRational::operator * (const BigRational& operand)
{
	BigRational answer;
	answer.p->denominator = this->p->denominator * operand.p->denominator;
	answer.p->numerator = this->p->numerator * operand.p->numerator;
	BigInteger temp = Abs(answer.p->numerator);
	BigInteger hcf = GCD(answer.p->denominator, temp);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

//the division is the same as multiplication. just with the operand inverted. 
// (x/y) / (z/w) = xw/yz
//the numerator and the denominator are then divided by their
//GCD to simplify the result
BigRational BigRational::operator / (const BigRational& operand)
{
	BigRational answer;
	BigInteger zero(0);
	answer.p->denominator = this->p->denominator * operand.p->numerator;
	answer.p->numerator = this->p->numerator * operand.p->denominator;
	if (answer.p->numerator < zero && answer.p->denominator < zero)
	{
		answer.p->numerator = Abs(answer.p->numerator);
		answer.p->denominator = Abs(answer.p->denominator);
	}
	else if (answer.p->numerator > zero && answer.p->denominator < zero)
	{
		answer.p->numerator = answer.p->numerator * BigInteger(-1);
		answer.p->denominator = Abs(answer.p->denominator);
	}	
	BigInteger temp = Abs(answer.p->numerator);
	BigInteger hcf = GCD(answer.p->denominator, temp);
	answer.p->denominator = answer.p->denominator / hcf;
	answer.p->numerator = answer.p->numerator / hcf;
	return answer;
}

//< operator
bool BigRational::operator < (const BigRational& operand)
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

//> operator
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

//<= operator
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

//>= operator
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

//== operator
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

//!= operator
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

//output. the default output is just outputting the numerator and the 
//denominator as bigIntegers. with a "/" sign ====> p/q
std::ostream&operator<<(std::ostream& os, const BigRational& output)
{
	os << output.p->numerator << "/" << output.p->denominator;
	return os;
}

//input operator. the user has to input the numerator and the 
//denominator as bigIntegers. 
std::istream&operator>>(std::istream& is, const BigRational& input)
{
	is >> input.p->numerator >> input.p->denominator;
	return is;
}

//to Decimal string takes the BigInteger and returns the decimal representation
//algorithm: 
// calculate quotient and the remainder. 
//the quotient.toString() gets appended to the resulting string output.
//if the remainder is zero, done.
//else push remainder to a vector<BigInteger> to keep track of the remainders
//Enter a while loop(while remainder is not equal to zero)
// multiply the remainder by 10
// append(remainder / denominator).toString() to the resulting string
// update the remainder : remainder%denominator
//  if the remainder exists in the vector, append brackets("|") to the resulting string output      
//	to show repeating part, and break the loop.
//  else, push the remainder in the vector and continue the loop.
//update: only ten decimal numbers are shown. to make it easy for the user to read the result. 
std::string BigRational::toDecimalString(int numberOfDecimals)
{
	std::string answer;
	std::string rem = "";
	BigInteger AbsNum = Abs(this->p->numerator);
	BigInteger den = this->p->denominator;
	BigInteger ten(10);
	BigInteger zero(0);
	std::vector<BigInteger> remaindertracker;
	if (this->p->numerator < BigInteger(0))
	{
		answer = "-";
	}
	answer += (AbsNum / den).toString();
	BigInteger remainder = AbsNum%den;
	if (remainder == zero)
	{
		return answer;
	}
	if (remainder != zero)
	{
		answer += ".";
		remaindertracker.push_back(remainder);
	}
	bool flag = false;
	for (int i = 0; i < numberOfDecimals; i++)
	{
		remainder = remainder * 10; 
		rem += (remainder / den).toString();
		remainder = remainder % den;
		if (remainder == zero)
		{
			break;
		}
		for (int j = 0; j < remaindertracker.size(); j++)
		{
			if (remaindertracker[j] == remainder)
			{
				rem.insert(j, "|");
				flag = true;
			}
		}
		if (flag == true)
		{
			rem += "|";
			//the remainder is found;
			break;
		}
		else
		{
			remaindertracker.push_back(remainder);
		}
	}
	/*while (remainder != zero)
	{
		remainder = remainder * ten;
		rem += (remainder / den).toString();
		remainder = remainder % den;

		for (int i = 0; i < remaindertracker.size(); i++)
		{
			if (remaindertracker[i] == remainder)
			{
				rem.insert(i, "|");
				flag = true;
			}
		}
		if (flag == true)
		{
			rem += "|";
			//the remainder is found;
			break;
		}
		else
		{
			remaindertracker.push_back(remainder);
		}
	}*/
	if (remainder != zero && flag == false)
	{
		rem += "...";
	}
	return answer + rem;
}

//returning the string representation of the BigRational Number as a 
//fraction. 
std::string BigRational::toFractionString()
{
	std::string answer;
	answer = this->p->numerator.toString() + "/" + this->p->denominator.toString();
	return answer;
}