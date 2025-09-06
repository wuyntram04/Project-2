#pragma once
#include<iostream>

using namespace std;
class Rational
{
private:
    short numerator;
    short denominator;

    //preCondition: numerator and denominator must be integer value
    //postCondition: return the greatest common division value between 2 values
    int gcd(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            denominator = 1;
            return denominator;
        }
        else if (numerator % denominator == 0)
        {
            return denominator;
        }
        else
            return gcd(denominator, numerator % denominator);
    }

    //preCondition: none
    //postCondition: simplify the value 
    void simplify()
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
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
            throw runtime_error(". Denominator cannot be zero.");
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
    short getNumerator() const
    {
        return numerator;
    }

    //preCondition: n is integer
    //postCondition: check if the denominator is 0, set numerator as d and simlify
    void setDenominator(int d)
    {
        if (d == 0)
        {
            throw runtime_error(". Denominator cannot be zero.");
        }
        denominator = d;
        simplify();
    }

    //preCondition: none
   //postCondition: return the value of denominator
    short getDenominator() const
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



    friend ostream& operator<< (ostream& out, const Rational& obj);
};

//preCondition: out is a object of ostream, obj is a object of Rational class
//postCondition: return out
ostream& operator<< (ostream& out, const Rational& obj)
{
    out << obj.getNumerator() << "/" << obj.getDenominator();
    return out;
}

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