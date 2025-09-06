#include <iostream>
#include <iomanip>
#include "input.h"
#include "Statistician.h"
#include "Quadratics.h"
#include "Pseudorandom.h"
#include "Rational.h"
#include <ctime>
	
using namespace std;

//PROTOTYPE

void mainMenu();
// #1 
void statisticianMenu();

// #2 
void quadraticsMenu();

// #3 
void pseudorandomMenu();

// #4
void rationalMenu();

int main()
{
	do {

		mainMenu();

	} while (true);
	
}

void mainMenu()
{
	system("cls");

	cout << "\n\tCMPR131 Chapter2 - ADT Assignments by Team (09/05/2025)";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1> Statistician";
	cout << "\n\t\t2> Quadratic Expression";
	cout << "\n\t\t3> Pseudorandom";
	cout << "\n\t\t4> Rational number";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\tX. Exit";
	cout << "\n\t" << string(80, char(205));
	
	char option = inputChar("\n\t\tOption: ", static_cast<string>("1234X"));

	switch (option)
	{
	case 49: //1 Statistician
		statisticianMenu();
		break;
	case 50: //2 Quadratic Expression
		quadraticsMenu();
		break;
	case 51: //3 Pseudorandom
		pseudorandomMenu();
		break;
	case 52: //4 Rational
		rationalMenu();
		break;
	}

}

void statisticianMenu()
{
	Statistician s;

	do
	{
		system("cls");

		cout << "\n\t1> Statistician menu";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA. add a number";
		cout << "\n\t\tB. get the length";
		cout << "\n\t\tC. get the last number";
		cout << "\n\t\tD. get the sum of numbers";
		cout << "\n\t\tE. get the arithmetic mean of numbers";
		cout << "\n\t\tF. get the smallest number";
		cout << "\n\t\tG. get the largest number";
		cout << "\n\t\tH. erase the sequence";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(80, char(205));

		char option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHI0")));

		switch (option)
		{
		case 'A': //add a new value
		{
			double number = inputDouble("\n\tEnter a number: ");
			s.next_number(number);
		}
		break;

		case 'B': //get the length
		{
			cout << "\n\tLength: " << s.getLength();
		}
			break;

		case 'C': //get the last number
		{
			if (s.getLength() > 1)
			{
				cout << "\n\tThe last number: " << s.getLastNumber();

			}
			else
			{
				cout << "\n\tRequire at least two values";
			}

		}
			break;

		case 'D': //get the sum of numbers
		{
			cout << "\n\tThe sum of numbers: " << s.getSum();

		}
			break; //get the arithmetic mean
		case 'E':
		{
			if (s.getLength() > 1)
			{
				cout << "\n\tThe arithmetic mean of the numbers: " << s.getMean();

			}
			else
			{
				cout << "\n\tRequire at least two values";
			}

		}
			break;	
		case 'F': //get the smallest numbers
		{
			if (s.getLength() > 1)
			{
				cout << "\n\tThe smallest number: " << s.getSmallest();
			}
			else
			{
				cout << "\n\tRequire at least two values";
			}
		}
			break;

		case 'G': //get the largest numbers
		{
			if (s.getLength() > 1)
			{
				cout << "\n\tThe largest number: " << s.getLargest();
			}
			else
			{
				cout << "\n\tRequire at least two values";
			}
		}
			break;

		case 'H':
		{
			s.erase();
		}
			break;

		case 48: // 0
		{
			return;
		}

		}

		cout << "\n\n";
		system("pause");
	} while (true);

	
}

void quadraticsMenu()
{
	Quadratics q;
	do
	{
		system("cls");
		cout << "\n\t2> Quadratic Menu";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA. display the expression";
		cout << "\n\t\tB. set coefficient (a)";
		cout << "\n\t\tC. set coefficient (b)";
		cout << "\n\t\tD. set coefficient (c)";
		cout << "\n\t\tE. get evaluation (x)";
		cout << "\n\t\tF. get the number of real roots";
		cout << "\n\t\tG. get real root(s)";
		cout << "\n\t\tH. get sum of two equations";
		cout << "\n\t\tI. scale the equation";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(80, char(205));
		char option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHI0")));
		switch (option)
		{
		case 'A': //display the inputs of the user for the formula to show
		{
			cout << "\n\t" << q.getCoefficient1() << "x^2 + " << q.getCoefficient2() << "x + " << q.getCoefficient3();
			cout << "\n\n";
			system("pause");
		}
		break;
		case 'B': 
		{
			q.setCoefficient1(inputInteger("\n\tEnter a value and set coefficient (a): ", 0, 100));
			cout << "\n\n";
			system("pause");
		}
		break;
		case 'C':
		{
			q.setCoefficient2(inputInteger("\n\tEnter a value and set coefficient (b): ", 0, 100));
			cout << "\n\n";
			system("pause");
		}
		break;
		case 'D':
		{
			q.setCoefficient3(inputInteger("\n\tEnter a value and set coefficient (c): ", 0, 100));
			system("pause");
		}
		break;

		case 'E': 
		{
			int input = inputInteger("\n\tEnter a value of x: ", 0, 100);

			int result = (q.getCoefficient1() * pow(input, 2)) + (q.getCoefficient2() * input) + q.getCoefficient3();

			cout << "\n\tEvaluation result: " << result << "\n\n";
			system("pause");
		}
		break;

		case 'F':
		{
			int numberOfRR = q.getNumberRealRoots();
			
			if (numberOfRR == 3)
			{
				cout << "\n\tnumber of real roots: infinity";
			}
			else 
			{
				cout << "\n\tnumber of real roots: " + to_string(numberOfRR);
			}

			cout << "\n\n";
			system("pause");
		}
		break;

		case 'G':
		{
			cout << "\n\t" << q.getRealRoots();
			cout << "\n\n";
			system("pause");
		}
		break;

		case 'H':
		{
			Quadratics q2;
			
			cout << "\n\tPlease enter values for second equation\n\n";

			q2.setCoefficient1(inputInteger("\tEnter a value for 'a': "));
			q2.setCoefficient2(inputInteger("\tEnter a value for 'b': "));
			q2.setCoefficient3(inputInteger("\tEnter a value for 'c': "));

			Quadratics q3;

			q3 = q + q2;

			cout << "\n\tThe sum of [" << q.displayExpression() << "] and [" << q2.displayExpression() << "] is [" << q3.displayExpression() << "]";

			cout << "\n\n";
			system("pause");

		}
		break;

		case 'I':
		{
			double r = inputDouble("\n\tPlease enter a number to multiply each coefficient: ");
			
			cout << "\n\tBefore scaling: " << q.displayExpression();
			q = r * q;
			cout << "\n\tThe expression after scaling: " << q.displayExpression();

			cout << "\n\n";
			system("pause");
		}
		break;

		case 48: // 0
			return;
		}
	} while (true);
}

void pseudorandomMenu()
{

	Pseudorandom p;

	do
	{
		system("cls");
		cout << "\n\t3> Pseudorandom";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA. get seed";
		cout << "\n\t\tB. set seed";
		cout << "\n\t\tC. get multiplier";
		cout << "\n\t\tD. set multiplier";
		cout << "\n\t\tE. get modulus";
		cout << "\n\t\tF. set modulus";
		cout << "\n\t\tG. get increment";
		cout << "\n\t\tH. set increment";
		cout << "\n\t\tI. get next number";
		cout << "\n\t\tJ. get indirect next number";
		cout << "\n\t\tK. run experiment with different values (multiplier, increment, and modulus)";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(80, char(205));
		char option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJK0")));
		
		switch (option)
		{
			case 'A':
			{
				cout << "\n\tseed: " << p.getSeed();
			}
			break;

			case 'B':
			{
				p.setSeed(inputInteger("\n\tEnter a value for seed: ", true));
			}
			break;

			case 'C':
			{
				cout << "\n\tmutiplier: " << p.getMultiplier();
			}
			break;

			case 'D':
			{
				p.setMultiplier(inputInteger("\n\tEnter a value for multiplier: ", true));
			}
			break;

			case 'E':
			{
				cout << "\n\tmodulus: " << p.getModulus();
			}
			break;

			case 'F':
			{
				p.setModulus(inputInteger("\n\tEnter a value for modulus: ", true));
			}
			break;

			case 'G':
			{
				cout << "\n\tincrement: " << p.getIncrement();
			}
			break;

			case 'H':
			{
				p.setIncrement(inputInteger("\n\tEnter a value for increment: ", true));
			}
			break;

			case 'I':
			{
				cout << "\n\tnext Number: " << p.getNextNumber();
			}
			break;

			case 'J':
			{
				cout << "\n\tindirect next Number: " << p.getIndirectNumber();
			}
			break;

			case 'K':
			{
				unsigned seed = time(0);
				srand(seed);

				p.setMultiplier(rand());
				p.setIncrement(rand());
				p.setModulus(rand());

				cout << "\n\texperiment of pseudorandom with random multiplier, increment and modulus";
				cout << "\n\n\t" << string(80, char(196));
				cout << "\n\tmultiplier = " << p.getMultiplier() << ", increment = " << p.getIncrement() << ", modulus = " << p.getModulus();

				cout << "\n\n\t" << setw(16) << left << "Range " << "Number of Occurrences";

				const int intervals = 10;
				int count[intervals] = { 0 };

				for (int i = 0; i < 1000000; i++)
				{
					int index = int(p.getIndirectNumber() * 10);
					count[index]++;
				}

				for (int i = 0; i < 10; i++)
				{
					double lower = i * 0.1;
					double upper = (i + 1) * 0.1;
					cout << setprecision(1) << fixed;
					cout << "\n\t" << "[" << lower << " ... " << upper << ")   ";
					cout <<  count[i];
				}

				cout << setprecision(5) << fixed;
				cout << "\n\n\t" << p.generateGaussian();


			}
			break;

			case 48: //0
			{
				return;
			}
			break;

		}

		cout << "\n\n";
		system("pause");

	} while (true);
}

void rationalMenu()
{
	Rational R1;
	Rational R2;
	
	do
	{
		system("cls");
		cout << "\n\t4> Rational Number menu";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA. enter value of rational number R1";
		cout << "\n\t\tB. display R1";
		cout << "\n\t\tC. enter value of rational number R2";
		cout << "\n\t\tD. display R2";
		cout << "\n\t\tE. multiplication of 2 rational number (R1 * R2)";
		cout << "\n\t\tF. division of 2 rational numbers (R1 / R2)";
		cout << "\n\t\tG. addition of 2 rational numbers (R1 + R2)";
		cout << "\n\t\tH. subtraction 2 rational numbers (R1 - R2)";
		cout << "\n\t\tI. (R1 == R2)";
		cout << "\n\t\tJ. (R1 < R2)";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(80, char(205));
		char option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJ0")));
		
		try
		{
			switch (option)
			{
			case 'A':
				R1.setNumerator(inputInteger("\n\tEnter the value for the numerator: "));
				R1.setDenominator(inputInteger("\n\tEnter the value for the denominator: "));
				break;
			case 'B':
				cout << "\n\tRational number R1: " << R1;
				break;
			case 'C':
				R2.setNumerator(inputInteger("\n\tEnter the value for the numerator: "));
				R2.setDenominator(inputInteger("\n\tEnter the value for the denominator: "));
				break;
			case 'D':
				cout << "\n\tRational number R2: " << R2;
				break;
			case 'E':
				cout << "\n\tR1 * R2: " << R1 * R2;
				break;
			case 'F':
				cout << "\n\tR1 / R2: " << R1 / R2;
				break;
			case 'G':
				cout << "\n\tR1 + R2: " << R1 + R2;
				break;
			case 'H':
				cout << "\n\tR1 - R2: " << R1 - R2;
				break;
			case 'I':
				cout << "\n\tR1 == R2: " << (R1 == R2 ? "true" : "false");
				break;
			case 'J':
				cout << "\n\tR1 < R2: " << (R1 < R2 ? "true" : "false");
				break;
			case 48:
				return;
				break;
			}
		}
		catch (const runtime_error& e)
		{
			cout << "\n\tERROR: " << e.what();
		}
		
			
		cout << "\n\n";
		system("pause");

	} while (true);
	
}

