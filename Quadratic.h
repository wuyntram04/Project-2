#pragma once
#include<iostream>
#include <stdexcept>
#include<algorithm>
#include<cmath>
using namespace std;

class Quadratic
{
private:
	double a;
	double b;
	double c;
	double x;
public:
	/*Quadratic();
	void setA(double coefficientA);
	void setB(double coefficientB);
	void setC(double coefficientC);
	void setX(double variable);
	double getA() const;
	double getB() const;
	double getC() const;
	double getX() const;
	
	int NumRealRoot() const;
	double SmallerRoot() const;
	double LargerRoot() const;*/

	//preCondition: none
	//postCondition: create a Quadratic object with a = 0, b = 0, c = 0, x = 0
	Quadratic() {
		a = 0;
		b = 0;
		c = 0;
		x = 0;
	}

	// Pre-condition: coefficientA is a valid double
	// Post-condition: set a as coefficientA
	void setA(double coefficientA) {
		a = coefficientA;
	 }

	//preCondition: none
	//postCondition: return a
	double getA() const
	{
		return a;
	}

	// Pre-condition: coefficientB is a valid double
	// Post-condition: set b as coefficientB
	void setB(double coefficientB)
	{
		b = coefficientB;
	}

	//preCondition: none
	//postCondition: return b
	double getB() const
	{
		return b;
	}

	// Pre-condition: coefficientC is a valid double
	// Post-condition: set c as coefficientC
	void setC(double coefficientC)
	{
		c = coefficientC;
	}

	//preCondition: none
	//postCondition: return c
	double getC() const
	{
		return c;
	}

	//preCondition: variable is a double
	//postCondition: sets x as variable
	void setX(double variable)
	{
		x = variable;
	}

	//preCondition: none
	//postCondition: return x
	double getX() const
	{
		return x;
	}

	//preCondition: coefficients a, b, and c must be finite values
	//postCondition: return the discriminant value (b^2 - 4ac)
	double discriminant() const {
		return b * b - 4 * a * c;
	}
	//preCondition: coefficients must be finite values
	//postCondition: return number of real roots: 
	// 0 (no solution), 1 (one root), 2 (two roots), or 3 (infinitely many)
	int NumRealRoot() const
	{

		if (a == 0 && b == 0 && c == 0) return 3;
	
		if (a == 0 && b == 0) return 0;

		if (a == 0) return 1;
		
		double D = discriminant();
		if (D < 0) return 0;
	
		if (D == 0) return 1;

		if (D > 0) return 2;
		

		return 0;
	}

	//preCondition: at least one real root exists (NumRealRoot() == 1 or 2)
	//postCondition: return the smaller root value; 
	// returns 0 if no valid root or infinitely many solutions
	double SmallerRoot() const
	{
		int n = NumRealRoot();

		if (n == 0 || n == 3) return 0;

		if (a == 0)
		{
			return -c / b;
		}

		double D = discriminant();
		if (D < 0) return 0;

		if (D == 0)
		{
			return -b / (2 * a);
		}

		if (D > 0)
		{
			double r1 = (-b + sqrt(D)) / (2 * a);
			double r2 = (-b - sqrt(D)) / (2 * a);

			if (r1 < r2) {
				return r1;
			}
			else {
				return r2;
			}
		}

	}

	//preCondition: at least one real root exists (NumRealRoot() == 1 or 2)
	//postCondition: return the larger root value; 
	// returns 0 if no valid root or infinitely many solutions
	double LargerRoot() const
	{
		int n = NumRealRoot();

		if (n == 0 || n == 3) return 0;

		if (a == 0)
		{
			return -c / b;
		}

		double D = discriminant();
		if (D < 0) return 0;

		if (D == 0)
		{
			return -b / (2 * a);
		}

		double r1 = (-b + sqrt(D)) / (2 * a);
		double r2 = (-b - sqrt(D)) / (2 * a);

		if (r1 > r2) {
			return r1;
		}
		else {
			return r2;
		}
	}

	//preCondition: none
	//postCondition: print the quadratic equation in standard form
	void showFormula() const {
		cout << "\n\t" << a << "x^2 + " << b << "x + " << c << endl;
	}

	//preCondition: x must have been set
	//postCondition: return the value of ax^2 + bx + c
	double quadratic() const {
		return a * pow(x, 2) + b * x + c;
	}
};

//preCondition: both q1 and q2 must be valid Quadratic objects
//postCondition: return new Quadratic whose coefficients are sum of q1 and q2
Quadratic operator +(const Quadratic& q1, const Quadratic& q2)
{
	Quadratic temp;
	temp.setA(q1.getA() + q2.getA());
	temp.setB(q1.getB() + q2.getB());
	temp.setC(q1.getC() + q2.getC());

	return temp;
}

//preCondition: r must be a finite double; q1 is a valid Quadratic object
//postCondition: return new Quadratic whose coefficients are q1’s coefficients scaled by r
Quadratic operator *(double r, const Quadratic& q1)
{
	Quadratic temp;
	temp.setA(q1.getA() * r);
	temp.setB(q1.getB() * r);
	temp.setC(q1.getC() * r);

	return temp;
}



