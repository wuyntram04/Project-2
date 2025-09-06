#include <iostream>

#pragma once
class Quadratics
{
private:
	int a = 0;
	int b = 0;
	int c = 0;
public:

	Quadratics();

	void setCoefficient1(int);
	void setCoefficient2(int);
	void setCoefficient3(int);
	int getCoefficient1() const;
	int getCoefficient2() const;
	int getCoefficient3() const;
	int getNumberRealRoots() const;
	string getRealRoots() const;
	string displayExpression() const;

	
};

Quadratics::Quadratics()
{
	int a = 0;
	int b = 0;
	int c = 0;
}

void Quadratics::setCoefficient1(int c1)
{
	a = c1;
}

void Quadratics::setCoefficient2(int c2)
{
	b = c2;
}

void Quadratics::setCoefficient3(int c3)
{
	c = c3;
}

int Quadratics::getCoefficient1() const
{
	return a;
}

int Quadratics::getCoefficient2() const
{
	return b;
}

int Quadratics::getCoefficient3() const
{
	return c;
}

int Quadratics::getNumberRealRoots() const
{
	//#1
	if (a == 0 && b == 0 && c == 0)
	{
		return 3;
	}

	//#2
	if (a == 0 && b == 0 && c != 0)
	{
		return 0;
	}

	//#3
	if (a == 0 && b != 0)
	{
		// x = -c/b.
		return 1;
	}

	//#4
	if (a != 0 && pow(b, 2) < (4 * a * c))
	{
		return 0;
	}

	//#5
	if (a != 0 && pow(b, 2) == (4 * a * c))
	{
		// x = -b/2a
		return  1;
	}

	//#6
	if (a != 0 && pow(b, 2) > (4 * a * c))
	{
		// 2 formula
		return 2;
	}
}

string Quadratics::getRealRoots() const
{
	int numberOfRR = getNumberRealRoots();
	
	if (numberOfRR == 0)
	{
		return "no real roots";
	}

	if (numberOfRR == 1)
	{
		if (a == 0)
		{
			double x = -c / b;
			return "only real roots: " + to_string(x);

		}
		else
		{
			double x = -b / 2.0 * a;
			return "only real roots: " + to_string(x);
		}
			
	}

	if (numberOfRR == 2)
	{
		double x1 = (-b - sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a);
		double x2 = (-b + sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a);

		return "two real roots are: " + to_string(x1) + " and " + to_string(x2);
	}

	if (numberOfRR == 3)
	{
		return "every value of x is a real root";
	}

	return "";
}

string Quadratics::displayExpression() const
{
	return to_string(getCoefficient1()) + "x^2 + " + to_string(getCoefficient2()) + "x + " + to_string(getCoefficient3());
}


Quadratics operator+ (const Quadratics& q1, const Quadratics& q2)
{
	Quadratics temp;
	temp.setCoefficient1(q1.getCoefficient1() + q2.getCoefficient1());
	temp.setCoefficient2(q1.getCoefficient2() + q2.getCoefficient2());
	temp.setCoefficient3(q1.getCoefficient3() + q2.getCoefficient3());
	
	return temp;
}

Quadratics operator* (double r, const Quadratics& q1)
{
	Quadratics temp;
	temp.setCoefficient1(r * q1.getCoefficient1());
	temp.setCoefficient2(r * q1.getCoefficient2());
	temp.setCoefficient3(r * q1.getCoefficient3());

	return temp;
}

Quadratics operator* (const Quadratics& q1, double r)
{
	Quadratics temp;
	temp.setCoefficient1(r * q1.getCoefficient1());
	temp.setCoefficient2(r * q1.getCoefficient2());
	temp.setCoefficient3(r * q1.getCoefficient3());

	return temp;
}

