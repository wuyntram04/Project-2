#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;
class Rational
{
private: 
	double numerator;
	double denominator;

	//preCondition: numerator and denominator must be integer value
	//postCondition: return the greatest common division value between 2 values
	int gcd(int numerator, int denominator)
	{
		if (numerator < 0)
		{
			numerator = -numerator;
		}

		if (denominator < 0)
		{
			denominator = -denominator;
		}

		if (numerator == 0 && denominator == 0)
		{
			return 1;
		}


		if (denominator == 0)
		{
			return numerator;
		}


		while (denominator != 0)
		{
			int t = numerator % denominator;
			numerator = denominator;
			denominator = t;
		}

		if (numerator == 0)
		{
			return 1;
		}
		else
		{
			return numerator; 
		}
	}


	//preCondition: none
	//postCondition: simplify the value 
	void simplify()
	{
		if (denominator == 0)
		{
			throw runtime_error("Denominator cannot be zero.");
		}

		if (numerator == 0)
		{
			denominator = 1;
		}
		else
		{
			int d = gcd(numerator, denominator);
			if (d == 0)
			{
				d = 1;
			}


			numerator = numerator / d;
			denominator = denominator / d;

			if (denominator < 0)
			{
				denominator = -denominator;
				numerator = -numerator;
			}

		}
	}

public:

	//Default Constructor
	//preCondition: none
	//postCondition: set numerator to 0 and denominator to 1
	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	//Constructor
	//preCondition: n and d are integer
	//postCondition: set numerator as n and denominator as d and check if denominator is 0
	Rational(int n, int d)
	{
		numerator = n;
		denominator = d;
		if (denominator == 0)
		{
			throw invalid_argument(". Denominator cannot be zero.");
		}
		simplify();

	}

	//preCondition: n is integer
	//postCondition: set numerator as n and simlify
	void setNumerator(int n)
	{
		numerator = n;
		simplify();
	}

	//preCondition: none
    //postCondition: return the value of numerator
	double getNumerator() const
	{
		return numerator;
	}

	//preCondition: n is integer
	//postCondition: check if the denominator is 0, set numerator as d and simlify
	void setDenominator(int d)
	{
		denominator = d;
		if (d == 0)
		{
			throw runtime_error("Denominator cannot be zero.");
		}
		simplify();
	}
	
	//preCondition: none
    //postCondition: return the value of denominator
	double getDenominator() const
	{
		return denominator;
	}



	// Overload operator> to compare Rational objects
	bool operator>(const Rational& obj) const {
		return (numerator * obj.denominator) > (obj.numerator * denominator);
	} 

	// Overload operator< for sorting (needed for std::sort)
	bool operator<(const Rational& obj) const {
		return (numerator * obj.denominator) < (obj.numerator * denominator);
	}

	//preCondition: obj is a object of Rational class
    //postCondition: check if equal
	bool operator==(const Rational& other) const
	{

		return (numerator == other.numerator) && (denominator == other.denominator);

	}

	
};


Rational operator * (const Rational& R1, const Rational& R2)
{
	Rational temp;
	temp.setNumerator(R1.getNumerator() * R2.getNumerator());
	temp.setDenominator(R1.getDenominator() * R2.getDenominator());
	return temp;
}

Rational operator / (const Rational& R1, const Rational& R2)
{
	if (R2.getNumerator() == 0) {
		throw runtime_error("Division by zero rational.");
	}
	Rational temp;
	temp.setNumerator(R1.getNumerator() * R2.getDenominator());
	temp.setDenominator(R1.getDenominator() * R2.getNumerator());
	return temp;
}

Rational operator + (const Rational& R1, const Rational& R2)
{
	Rational temp;
	temp.setNumerator(R1.getNumerator() * R2.getDenominator() + R2.getNumerator() * R1.getDenominator());
	temp.setDenominator(R1.getDenominator() * R2.getDenominator());
	return temp;
}

Rational operator - (const Rational& R1, const Rational& R2)
{
	Rational temp;
	temp.setNumerator(R1.getNumerator() * R2.getDenominator() - R2.getNumerator() * R1.getDenominator());
	temp.setDenominator(R1.getDenominator() * R2.getDenominator());
	return temp;
}
