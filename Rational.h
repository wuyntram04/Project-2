#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;
class Rational
{
private: 
	int num_;
	int den_;

public:
	Rational(int num = 0, int den = 1)
	{
		num_ = num;
		den_ = den;

		if (den_ == 0)
		{
			throw runtime_error("Denominator cannot be zero.");
		}
	}







	int numerator() const
	{
		return num_;
	}

	int denominator() const
	{
		return den_;
	}

};


