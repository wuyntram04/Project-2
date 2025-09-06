
#pragma once
class Statistician
{
private:

	int size = 0;
	double sum = 0.0;
	double mean = 0.0;
	
	double lastNumber = 0.0;
	double firstNumber = 0.0;

	double smallestNumber = 0.0;
	double largestNumber = 0.0;

public:


	//Accessor
	double getLength();
	double getSum();
	double getMean();
	double getLastNumber();
	double getFirstNumber();
	double getSmallest();
	double getLargest();

	//Mutator
	void next_number(double v);
	void erase();
};


//Precondition: none
//Postcondition: sets, finds and calculates (sum, count, mean, min, max, first and last value).
void Statistician::next_number(double v)
{
	sum += v;
	size += 1;
	
	if (size == 1)
	{
		firstNumber = v;
		smallestNumber = v;
		largestNumber = v;
	}

	lastNumber = v;
	
	mean = sum / size;

	// find the smallest
	if (smallestNumber > v)
	{
		smallestNumber = v;
	}


	// find the largest
	if (largestNumber < v)
	{
		largestNumber = v;
	}

}


//Precondition: none
//Postcondition: returns the number of values in the sequence.
double Statistician::getLength()
{
	return size;
}


//Precondition: none
//Postcondition: returns the sum of values in the sequence.
double Statistician::getSum()
{
	return sum;
}

//Precondition: the sequence must contain at least one value.
//Postcondition: returns the mean of values in the sequence.
double Statistician::getMean()
{
	return mean;
}

//Precondition: the sequence must contain at least one value.
//Postcondition: returns the first value in the sequence.
double Statistician::getFirstNumber()
{
	return firstNumber;
}

//Precondition: the sequence must contain at least one value.
//Postcondition: returns the last value in the sequence.
double Statistician::getLastNumber()
{
	return lastNumber;
}

//Precondition: the sequence must contain at least one value.
//Postcondition: returns the smallest value in the sequence.
double Statistician::getSmallest()
{
	return smallestNumber;
}

//Precondition: the sequence must contain at least one value.
//Postcondition: returns the largest value in the sequence.
double Statistician::getLargest()
{
	return largestNumber;
}

//Precondition: none
//Postcondition: reset the object to its initial state.
void Statistician::erase()
{
	size = 0;
    sum = 0.0;
	mean = 0.0;

	lastNumber = 0.0;
	firstNumber = 0.0;

	smallestNumber = 0.0;
	largestNumber = 0.0;
}


