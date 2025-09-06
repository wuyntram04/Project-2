#include <algorithm>

#pragma once
class Pseudorandom
{
private:
	int seed = 1;
	int multiplier = 40;
	int modulus = 729;
	int increment = 725;

public:
	
	void setSeed(int);
	void setMultiplier(int);
	void setModulus(int);
	void setIncrement(int);
	
	int getSeed() const;
	int getMultiplier() const;
	int getModulus() const;
	int getIncrement() const;
	
	int getNextNumber();
	double getIndirectNumber();
	double generateGaussian();
};


void Pseudorandom::setSeed(int s)
{
	seed = s;
}

void Pseudorandom::setMultiplier(int m)
{
	multiplier = m;
}

void Pseudorandom::setModulus(int m)
{
	modulus = m;
}

void Pseudorandom::setIncrement(int i)
{
	increment = i;
}

int Pseudorandom::getSeed() const
{
	return seed;
}

int Pseudorandom::getMultiplier() const
{
	return multiplier;
}

int Pseudorandom::getModulus() const
{
	return modulus;
}

int Pseudorandom::getIncrement() const
{
	return increment;
}

int Pseudorandom::getNextNumber()
{
	int number = (multiplier * seed + increment) % modulus;
	seed = number;

	return number;
}

double Pseudorandom::getIndirectNumber()
{
	seed = getNextNumber();

	return seed / double(modulus);
}

double Pseudorandom::generateGaussian()
{
	const int SIZE = 12;
	double uniformDis[SIZE] = {0};
	//Find the sum
	double sum = 0.0;

	for (int i = 0; i < SIZE; i++)
	{
		uniformDis[i] = getIndirectNumber();
		sum += uniformDis[i];
	}

	sort(uniformDis, uniformDis + SIZE);

	//Find the median, (even only)
	double median = ((uniformDis[SIZE / 2 - 1])  + uniformDis[SIZE / 2]) / 2.0;

	//Find the standard deviation
	double mean = sum / SIZE;

	double sumOfsquared = 0.0;
	for (int i = 0; i < SIZE; i++)
	{
		sumOfsquared += pow(uniformDis[i] - mean, 2);
	}

	double stdDev = sqrt(sumOfsquared / (SIZE - 1));

	double gaussianApprox = median + (sum - 6.0) * stdDev;

	return gaussianApprox;
}