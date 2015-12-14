#include "BigInteger.h"
#include <vector>
#include <math.h>
#include <algorithm>

//A constant long long int value for the base that is used
//Since the maximum number a cell can hold is UINT_MAX, 
//The base would be UINT_MAX + 1, which is 4294967296
const unsigned long long int base = 4294967296; //--UINT_MAX + 1

//Helper functions
std::vector<unsigned int> Sum(std::vector<unsigned int> a, std::vector<unsigned int> b);
std::vector<unsigned int> Multiply(std::vector<unsigned int> a, std::vector<unsigned int> b);
std::vector<unsigned int> Subtract(std::vector<unsigned int> a, std::vector<unsigned int> b);

struct BigInteger::PrivateRec
{
	std::vector<unsigned int> value;
};

//The default constructor for bigInteger
//It initialized a bigInteger with zero value
//The sign bit is zero (positive)
BigInteger::BigInteger()
{
	p = new PrivateRec;
	this->p->value.push_back(0);
	this->p->value.push_back(0);
}

BigInteger::~BigInteger()
{
	delete p;
}

//The constructor used by te users. The user initializes
//a big Integer as BigInteger("1312312"). The constructor 
//extracts each value and keeps on creating a BigInteger 
//The subsequent values are appended to the BigInteger using 
//the + and the * operators. 
BigInteger::BigInteger(const std::string& value)
{
	this->p = new PrivateRec;
	this->p->value.push_back(0);
	this->p->value.push_back(0);
	BigInteger ten(10);
	std::string::const_iterator charIt = value.cbegin();

	if (*charIt == '-') {
		++charIt;
		while (charIt != value.cend()) {
			*this = *this*ten + BigInteger(static_cast<int>(*charIt - '0'));
			++charIt;
		}
		this->p->value.pop_back();
		this->p->value.push_back(1);
	}
	else {
		while (charIt != value.cend()) {
			*this = *this*ten + BigInteger(static_cast<int>(*charIt - '0'));
			++charIt;
		}
	}

}


//The Integer constuctor. The constructor is responsible for creating a 
//BigInteger out of a respective Integer value. The constructor takes the
//value and creates a bigInteger with one cell value and a positive or a 
//negitive sign. The BigInteger will always be a one cell value because the 
//maximum value a cell can hold is greater than the max value of an int. 
BigInteger::BigInteger(const int& value)
{
	this->p = new PrivateRec;
	int temp = abs(value);
	if (temp == 0)
	{
		this->p->value.push_back(0);
	}
	else
	{
		while (temp != 0)
		{
			this->p->value.push_back(temp % base);
			temp /= base;
		}
	}
	//this->p->value.push_back(abs(value));
	if (value < 0)
	{
		this->p->value.push_back(1);
	}
	else
	{
		this->p->value.push_back(0);
	}
}


//Copy constructor.
BigInteger::BigInteger(const BigInteger& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
}

//Move constructor. Moves the contents of one BigInteger to the other.
//The original BigInteger becomes zero
BigInteger::BigInteger(BigInteger&& obj)
{
	this->p = new PrivateRec;
	this->p->value = obj.p->value;
	while (obj.p->value.size() != 0)
	{
		obj.p->value.pop_back();
	}
	obj.p->value.push_back(0);
	obj.p->value.push_back(0);
}

//copy operator overloaded
BigInteger BigInteger::operator=(const BigInteger& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
	}
	return *this;
}

//move operator overloaded
BigInteger BigInteger::operator=(BigInteger&& obj)
{
	if (this != &obj)
	{
		this->p->value = obj.p->value;
		while (obj.p->value.size() != 0)
		{
			obj.p->value.pop_back();
		}
		obj.p->value.push_back(0);
		obj.p->value.push_back(0);
	}
	return *this;
}


/*mathematical operations*/

//Power
//A BigInteger raised to the power (int value). The operation returns 
//A biginteger. the implementation uses a recursive approach using the * 
//operator. 
BigInteger Pow(BigInteger& num, int power)
{
	if (power <= 0)
	{
		return BigInteger(1);
	}
	return num * Pow(num, power - 1);
}

//Absolute
//Takes a BigInteger. Changes its sign value to zero (to make it positive)
//and returns a BigInteger. This is a friend function to the BigInteger class
//because it has to access the inner vector of the BigInteger value
BigInteger Abs(const BigInteger& operand)
{
	BigInteger answer = operand;
	answer.p->value[answer.p->value.size() - 1] = 0;
	return answer;
}

//addition
//The add operator will either add, or subtract two respective bigIntegers based
//on the sign values. the respective cases are handled under different if clauses
BigInteger BigInteger::operator + (const BigInteger& operand)
{
	BigInteger answer;
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	//a+b
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 0)
	{
		answer.p->value = Sum(this->p->value, operand.p->value);
		answer.p->value.push_back(0);
	}
	//-a-b = -(a+b)
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)
	{
		answer.p->value = Sum(this->p->value, operand.p->value);
		answer.p->value.push_back(1);
	}
	//b is negative
	else if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1) 
	{
		if (*this >= Abs(operand))//a-b
		{
			answer.p->value = Subtract(this->p->value, operand.p->value);
			answer.p->value.push_back(0);
		}
		else //-(b-a) Abs(b) is greater than a
		{
			answer.p->value = Subtract(operand.p->value, this->p->value);
			answer.p->value.push_back(1);
		}
		//a is negative
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0) 
	{
		if (Abs(*this) <= operand)//-a+b
		{
			answer.p->value = Subtract(operand.p->value, this->p->value);
			answer.p->value.push_back(0);
		}
		else //-a+b where Abs(a) is greater than b = -(a-b)
		{
			answer.p->value = Subtract(this->p->value, operand.p->value);
			answer.p->value.push_back(1);
		}
	}
	return answer;
}

//subtraction
//The subtract operator will either add, or subtract two respective bigIntegers based
//on the sign values. the respective cases are handled under different if clauses
BigInteger BigInteger::operator - (const BigInteger& operand)
{
	BigInteger answer;
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	//a-b
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 0)
	{
		//a-b
		if (*this >= operand)
		{
			answer.p->value = Subtract(this->p->value, operand.p->value);
			answer.p->value.push_back(0);
		}
		else //a-b = -(b-a)
		{
			answer.p->value = Subtract(operand.p->value, this->p->value);
			answer.p->value.push_back(1);

		}
	}
	//-a-(-b) = -a+b
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)
	{
		if (Abs(*this) <= Abs(operand)) //b-a
		{
			answer.p->value = Subtract(operand.p->value, this->p->value);
			answer.p->value.push_back(0);
		}
		else//-a+b = -(a-b)
		{
			answer.p->value = Subtract(this->p->value, operand.p->value);
			answer.p->value.push_back(1);
		}
	}
	//b is negative
	else if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1) 	
	{
		//a-(-b) = a+b
		answer.p->value = Sum(this->p->value, operand.p->value);
		answer.p->value.push_back(0);
	}
	//a is negative -a-b = -(a+b)
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0) 	
	{
		answer.p->value = Sum(this->p->value, operand.p->value);
		answer.p->value.push_back(1);
	}
	return answer;
}

//multiplication
//Does the paper multiplication for two numbers. each value is multiplicand 
//is calculated and added to the previous value. the final answer is appended
//with a sign based on the sign of the two bigIntegers
BigInteger BigInteger::operator * (const BigInteger& operand)
{
	BigInteger answer;
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	answer.p->value = Multiply(this->p->value, operand.p->value);
	if ((this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 0) || (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1))
	{
		answer.p->value.push_back(0);
	}
	else
	{
		answer.p->value.push_back(1);
	}
	return answer;
}


//division
//Does the paper division for two numbers.It uses the BaseCaseDivRem approach
//for the division. 
BigInteger BigInteger::operator / (const BigInteger& operand)
{
	BigInteger dividand(Abs(*this));
	BigInteger divisor(Abs(operand));

	if (dividand < divisor)
	{
		return BigInteger(0);
	}

	BigInteger two(2);
	BigInteger baseValue(std::to_string(base));
	BigInteger quotient(0);
	int k = 0;

	//NORMALIZATION STEP
	//if B is not normalized we compute A' = 2^k A and 
	//B' = 2^k B
	while (divisor.p->value[divisor.p->value.size() - 2] < (base / 2))
	{
		divisor = divisor * two;
		dividand = dividand * two;
		k++;
	}

	//calculating size
	int sizeThis = dividand.p->value.size();
	int sizeOther = divisor.p->value.size();


	int m = sizeThis - sizeOther;

	//quotient initialization
	unsigned int * q;
	q = new unsigned int[m + 1];


	BigInteger BmB = Pow(baseValue, m) * divisor;
	if (dividand >= BmB)
	{
		q[m] = 1;
		dividand = dividand - BmB;
	}
	else
	{
		q[m] = 0;
	}

	for (int i = m - 1; i >= 0; i--)
	{
		unsigned long long int valOne;
		unsigned long long int valTwo;
		if (sizeOther - 1 + i <= dividand.p->value.size() - 2)
		{
			valOne = dividand.p->value[sizeOther - 1 + i];
		}
		else
		{
			valOne = 0;
		}
		if (sizeOther - 1 + i - 1 <= dividand.p->value.size() - 2)
		{
			valTwo = dividand.p->value[sizeOther - 1 + i - 1];
		}
		else
		{
			valTwo = 0;
		}
		unsigned long long int temp = (valOne * base + valTwo) / (unsigned long long int)divisor.p->value[sizeOther - 2];

		if (temp > base - 1)
		{
			q[i] = base - 1;
		}
		else
		{
			q[i] = temp;
		}
		BigInteger Bj = Pow(baseValue, i);
		BigInteger QBjB = BigInteger(std::to_string(q[i]))*Bj*divisor;
		dividand = dividand - QBjB;
		while (dividand < BigInteger(0))
		{
			q[i] = q[i] - 1;
			dividand = dividand + Bj*divisor;
		}

	}

	for (int i = 0; i <= m; i++)
	{
		quotient = quotient + BigInteger(std::to_string(q[i]))* Pow(baseValue, i);
	}

	if (quotient.p->value.size() >= 2)
	{
		while (quotient.p->value[quotient.p->value.size() - 1] == 0 && quotient.p->value.size() >= 2)
		{
			quotient.p->value.pop_back();
		}
	}

	if ((this->p->value[this->p->value.size() - 1] == 0 && operand.p->value[operand.p->value.size() - 1] == 0) || (this->p->value[this->p->value.size() - 1] == 1 && operand.p->value[operand.p->value.size() - 1] == 1))
	{
		quotient.p->value.push_back(0);
	}
	else
	{
		quotient.p->value.push_back(1);
	}

	return quotient;
}


//modulus
//uses the / operator to calculate the modulus. Since the modulus can be different
//based on the sign values of the two numbers. It is handled under different if 
//conditions. The quotient calculation is done on Absolute values. 
BigInteger BigInteger::operator % (const BigInteger& operand)
{
	BigInteger dividand = Abs(*this);
	BigInteger divisor = Abs(operand);
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1)
	{
		BigInteger quotient = dividand / divisor;
		BigInteger remainder = ((quotient + BigInteger(1)) * divisor) - dividand;
		if (remainder != BigInteger(0))
		{
			remainder.p->value.pop_back();
			remainder.p->value.push_back(1);
		}
		return remainder;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0)
	{
		BigInteger quotient = dividand / divisor;
		BigInteger remainder = ((quotient + BigInteger(1)) * divisor) - dividand;
		return remainder;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)// both negative
	{
		BigInteger quotient = dividand / divisor;
		BigInteger remainder = dividand - (quotient * divisor);
		if (remainder != BigInteger(0))
		{
			remainder.p->value.pop_back();
			remainder.p->value.push_back(1);
		}
		return remainder;
	}
	else //both positive
	{
		BigInteger quotient = *this / operand;
		return *this - (quotient * operand);
	}
}

/* logical operations */

//<
bool BigInteger::operator < (const BigInteger&operand) //0 is positive, 1 is negative
{
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1)
	{
		return false;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0)
	{
		return true;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)// both negative
	{
		if (sizeThis < sizeOther)
		{
			return false;
		}
		else if (sizeThis > sizeOther)
		{
			return true;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i]>operand.p->value[i])
				{
					return true;
				}
				else if (this->p->value[i]<operand.p->value[i])
				{
					return false;
				}
			}
			return false;
		}
	}
	else // both positive
	{
		if (sizeThis > sizeOther)
		{
			return false;
		}
		else if (sizeThis < sizeOther)
		{
			return true;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i]<operand.p->value[i])
				{
					return true;
				}
				else if (this->p->value[i]>operand.p->value[i])
				{
					return false;
				}
			}
			return false;
		}
	}
}

//>
bool BigInteger::operator > (const BigInteger&operand)
{
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1)
	{
		return true;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0)
	{
		return false;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)// both negative
	{
		if (sizeThis < sizeOther)
		{
			return true;
		}
		else if (sizeThis > sizeOther)
		{
			return false;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i]<operand.p->value[i])
				{
					return true;
				}
				else if (this->p->value[i]>operand.p->value[i])
				{
					return false;
				}
			}
			return false;
		}
	}
	else // both positive
	{
		if (sizeThis > sizeOther)
		{
			return true;
		}
		else if (sizeThis < sizeOther)
		{
			return false;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i]>operand.p->value[i])
				{
					return true;
				}
				else if (this->p->value[i]<operand.p->value[i])
				{
					return false;
				}
			}
			return false;
		}
	}
}

//<=
bool BigInteger::operator <= (const BigInteger&operand)
{
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1)
	{
		return false;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0)
	{
		return true;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)// both negative
	{
		if (sizeThis < sizeOther)
		{
			return false;
		}
		else if (sizeThis > sizeOther)
		{
			return true;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i] < operand.p->value[i])
				{
					return false;
				}
				else if (this->p->value[i] > operand.p->value[i])
				{
					return true;
				}
			}
			return true;
		}
	}
	else // both positive
	{
		if (sizeThis > sizeOther)
		{
			return false;
		}
		else if (sizeThis < sizeOther)
		{
			return true;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i] > operand.p->value[i])
				{
					return false;
				}
				else if (this->p->value[i] < operand.p->value[i])
				{
					return true;
				}
			}
			return true;
		}
	}
}

//>=
bool BigInteger::operator >= (const BigInteger&operand)
{
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (this->p->value[sizeThis - 1] == 0 && operand.p->value[sizeOther - 1] == 1)
	{
		return true;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 0)
	{
		return false;
	}
	else if (this->p->value[sizeThis - 1] == 1 && operand.p->value[sizeOther - 1] == 1)// both negative
	{
		if (sizeThis < sizeOther)
		{
			return true;
		}
		else if (sizeThis > sizeOther)
		{
			return false;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i]>operand.p->value[i])
				{
					return false;
				}
				else if (this->p->value[i]<operand.p->value[i])
				{
					return true;
				}
			}
			return true;
		}
	}
	else // both positive
	{
		if (sizeThis > sizeOther)
		{
			return true;
		}
		else if (sizeThis < sizeOther)
		{
			return false;
		}
		else
		{
			//for (int i = 0; i < sizeOther - 1; i++)
			for (int i = sizeOther - 2; i >= 0; i--)
			{
				if (this->p->value[i]<operand.p->value[i])
				{
					return false;
				}
				else if (this->p->value[i]>operand.p->value[i])
				{
					return true;
				}
			}
			return true;
		}
	}
}

//==
bool BigInteger::operator == (const BigInteger&operand)
{
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (sizeThis != sizeOther)
	{
		return false;
	}
	else
	{
		if (this->p->value[sizeThis - 1] != operand.p->value[sizeOther - 1])
		{
			return false;
		}
		else
		{
			for (int i = 0; i < sizeOther - 1; i++)
			{
				if (this->p->value[i] != operand.p->value[i])
				{
					return false;
				}
			}
			return true;
		}
	}
}

//!=
bool BigInteger::operator != (const BigInteger&operand)
{
	int sizeThis = this->p->value.size();
	int sizeOther = operand.p->value.size();
	if (sizeThis != sizeOther)
	{
		return true;
	}
	else
	{
		if (this->p->value[sizeThis - 1] != operand.p->value[sizeOther - 1])
		{
			return true;
		}
		else
		{
			for (int i = 0; i < sizeOther - 1; i++)
			{
				if (this->p->value[i] != operand.p->value[i])
				{
					return true;
				}
			}
			return false;
		}
	}
}

//calculate LCM of two BigIntegers. 
BigInteger LCM(BigInteger& num1, BigInteger& num2)
{
	BigInteger i(num2);
	while ((num2%num1) != BigInteger("0"))
	{
		num2 = num2 + i;
	}
	return num2;
}

//calculate GCD (HCF) of two BigIntegers. 
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

//output operator. Takes a bigInteger and returns the respective 
//decimal value representation of it. 
std::ostream& operator<<(std::ostream& os, const BigInteger& output)
{
	BigInteger result(Abs(output));
	BigInteger temp;
	BigInteger ten("10"); //base converted back to decimal
	std::string out = "";
	if (result == BigInteger(0))
	{
		out += "0";
	}
	else
	{
		while (result != BigInteger(0))
		{
			temp = result%ten;
			result = result / ten;
			out += std::to_string(temp.p->value[0]);
		}
	}
	output.p->value[output.p->value.size() - 1] == 1 ? out += "-" : out += "";

	for (std::string::reverse_iterator rit = out.rbegin(); rit != out.rend(); ++rit)
		os << *rit;

	return os;
}


//the input operator. takes the input in string form and calls the
//BigInteger(string value) constructor.
std::istream&operator>>(std::istream& is, BigInteger& input)
{
	std::string in;
	is >> in;
	input = BigInteger(in);
	return is;
}

//Helper Functions

//Sum takes two positive vectors and returns a vector with sum of the
//two numbers. the algorithm followed is the basic schoolbook addition.
std::vector<unsigned int> Sum(std::vector<unsigned int> a, std::vector<unsigned int> b)
{
	std::vector<unsigned int> answer;
	unsigned long long int temp;
	unsigned long long int carry = 0;
	int sizea = a.size();
	int sizeb = b.size();
	//for (int i = 0; i < (sizea <= sizeb ? sizeb : sizea); i++)
	for (int i = 0; i < (sizea <= sizeb - 1 ? sizeb : sizea - 1); i++)
	{
		if (i > sizea - 2)
		{
			temp = (unsigned long long int)b[i] + carry;
			carry = temp / base;
			answer.push_back(temp % base);
		}
		else if (i > sizeb - 2)
		{
			temp = (unsigned long long int)a[i] + carry;
			carry = temp / base;
			answer.push_back(temp % base);
		}
		else
		{
			temp = (unsigned long long int)a[i] + (unsigned long long int)b[i] + carry;
			carry = temp / base;
			answer.push_back(temp % base);
		}
	}
	if (carry != 0)
	{
		while (carry != 0)
		{
			answer.push_back(carry % base);
			carry = carry / base;
		}
	}
	return answer;
}

//multiply a and b
//Multiply takes two positive vectors and returns a vector with multiplication
//of the two numbers. the algorithm followed is the basic schoolbook multiplication.
std::vector<unsigned int> Multiply(std::vector<unsigned int> a, std::vector<unsigned int> b)
{
	std::vector<unsigned int> answer;
	unsigned long long int temp;
	unsigned long long int carry = 0;
	int sizea = a.size();
	int sizeb = b.size();
	//for (int i = 0; i < sizea; i++)
	for (int i = 0; i < sizea - 1; i++)
	{
		//for (int j = 0; j < sizeb; j++)
		for (int j = 0; j < sizeb - 1; j++)
		{
			temp = (unsigned long long int)a[i] * (unsigned long long int)b[j] + carry;
			if (answer.size() == 0)
			{
				answer.push_back(temp % base);
				carry = temp / base;
			}
			else if (i + j > answer.size() - 1)
			{
				answer.push_back(temp % base);
				carry = temp / base;
			}
			else
			{
				unsigned long long int temp1 = (unsigned long long int)answer[i + j] + temp;
				answer[i + j] = (temp1) % base;
				carry = temp1 / base;
			}
		}
		if (carry != 0)
		{
			while (carry != 0)
			{
				answer.push_back(carry % base);
				carry = carry / base;
			}
		}
	}
	if (answer.size() >= 2)
	{
		while (answer[answer.size() - 1] == 0 && answer.size() >= 2)
		{
			answer.pop_back();
		}
	}
	return answer;
}

//subtract a and b as long as a is greater than b
//since a < b will result in b-a and appending negative sign. this function always 
//assumes that a will be a greater vector than b. the algorithm is simple schoolbook 
//subtraction
std::vector<unsigned int> Subtract(std::vector<unsigned int> a, std::vector<unsigned int> b)
{
	std::vector<unsigned int> answer;
	unsigned long long int temp;
	unsigned int carry = 0;
	int sizea = a.size();
	int sizeb = b.size();

	//for (int i = 0; i < (sizea <= sizeb ? sizeb : sizea); i++)
	for (int i = 0; i < (sizea <= sizeb - 1 ? sizeb : sizea - 1); i++)
	{
		if (i > sizea - 2)
		{
			temp = b[i];
			answer.push_back(temp);
		}
		else if (i > sizeb - 2)
		{
			temp = a[i];
			answer.push_back(temp);
		}
		else
		{
			if (a[i] >= b[i])
			{
				temp = (unsigned long long int)a[i] - (unsigned long long int)b[i];
				answer.push_back(temp);
			}
			else
			{
				//adding base to a[i]
				unsigned long long int temp1 = (unsigned long long int)a[i] + base - (unsigned long long int)b[i];
				answer.push_back(temp1);
				if (a[i + 1] > 0)
				{
					a[i + 1] -= 1;
				}
				else
				{
					int j = i + 1;
					while (a[j] == 0)
					{
						a[j] = base - 1;
						j++;
					}
					a[j] -= 1;
				}
			}
		}
	}
	if (answer.size() >= 2)
	{
		while (answer[answer.size() - 1] == 0 && answer.size() >= 2)
		{
			answer.pop_back();
		}
	}
	return answer;
}

//type casting to string
//instead of outputting the number after its respective decimal value
//representation. this returns a string with the answer. 
std::string BigInteger::toString()
{
	BigInteger result(Abs(*this));
	BigInteger temp;
	BigInteger ten("10"); //base converted back to decimal
	std::string out = "";
	if (result == BigInteger(0))
	{
		out += "0";
	}
	else
	{
		while (result != BigInteger(0))
		{
			temp = result%ten;
			result = result / ten;
			out += std::to_string(temp.p->value[0]);
		}
	}
	this->p->value[this->p->value.size() - 1] == 1 ? out += "-" : out += "";

	std::reverse(out.begin(),out.end());
	return out;
}
