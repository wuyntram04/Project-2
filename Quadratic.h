#pragma once
#include<iostream>
#include <stdexcept>
#include<algorithm>
#include<cmath>
using namespace std;

struct Roots {
	// count = -1 → every x is a real root (a=b=c=0)
	// count =  0 → no real roots
	// count =  1 → one real root in r1
	// count =  2 → two real roots r1, r2
	int count;
	double r1;
	double r2;
};


class Quadratic
{
private:
	double a;
	double b;
	double c;
	double x;
public:
	Quadratic();
	void setA(double coefficientA);
	void setB(double coefficientB);
	void setC(double coefficientC);
	void setX(double variable);
	double getA() const;
	double getB() const;
	double getC() const;
	double getX() const;
	void showFormula() const {
		cout << "\n\t"<< a << "x^2 + " << b << "x + " << c << endl;
	}
	double quadratic() const {
		return a * pow(x, 2) + b * x + c;
	}

	int NumRealRoot() const;
	double SmallerRoot() const;
	double LargerRoot() const;
};

Quadratic::Quadratic() {
	a = 0;
	b = 0;
	c = 0;
}
void Quadratic:: setA(double coefficientA) {
	a = coefficientA;
}

double Quadratic::getA() const
{
	return a;
}

void Quadratic::setB(double coefficientB)
{
	b = coefficientB;
}

double Quadratic::getB() const
{
	return b;
}

void Quadratic::setC(double coefficientC)
{
	c = coefficientC;
}

double Quadratic::getC() const
{
	return c;
}

void Quadratic::setX(double variable)
{
	x = variable;
}

double Quadratic::getX() const
{
	return x;
}

int Quadratic::NumRealRoot() const 
{
	
	if (a == 0 && b == 0 && c == 0)
	{

		return 3;
	}
	
	if (a == 0 && b == 0)
	{
		return 0;
	}
	
	if (a == 0)
	{
		return 1;
	}
	
	double D = b * b - 4 * a * c;
	if (D < 0)
	{
		return 0;
	}

	if (D == 0)
	{
		return 1;
	}

	if (D > 0)
	{
		return 2;
	}
}

double Quadratic::SmallerRoot() const
{
	int n = NumRealRoot();

	if(n == 0 || n == 3) return 0;

	if (a == 0)
	{
		return -c / b;
	}

	double D = b * b - 4 * a * c;
	if (D < 0) return 0;

	if (D == 0)
	{
		return -b / (2*a);
	}

	double r1 = (-b + sqrt(D)) / 2 * a;
	double r2 = (-b - sqrt(D)) / 2 * a;

	if (r1 < r2) {
		return r1;
	}
	else {
		return r2;
	}
}

double Quadratic::LargerRoot() const
{
	int n = NumRealRoot();

	if (n == 0 || n == 3) return 0;

	if (a == 0)
	{
		return -c / b;
	}

	double D = b * b - 4 * a * c;
	if (D < 0) return 0;

	if (D == 0)
	{
		return -b / (2 * a);
	}

	double r1 = (-b + sqrt(D)) / 2 * a;
	double r2 = (-b - sqrt(D)) / 2 * a;

	if (r1 > r2) {
		return r1;
	}
	else {
		return r2;
	}
}



