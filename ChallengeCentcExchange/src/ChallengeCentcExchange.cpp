// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.

	Write a program that asks the user to enter the following:
	An integer representing the number of cents

	You may assume that the number of cents entered is greater than or equal to zero

	The program should then display how to provide that change to the user.

	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.

	Here is a sample run:

	Enter an amount in cents :  92

	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2

	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter an amount in cents :  ";

	const int CENTS_DOLLARS{ 100 };
	const int CENTS_QUARTER{ 25 };
	const int CENTS_DIME{ 10 };
	const int CENTS_NICKEL{ 5 };
	const int CENTS_PENNY{ 1 };
	int entered_cents_amout{};
	int dollars{};
	int quarters{};
	int dimes{};
	int nickels{};
	int pennys{};

	cin >> entered_cents_amout;

	if (entered_cents_amout >= 0) {
		int parts_of_dollars{};
		int parts_of_quarters{};
		int parts_of_dimes{};
		int parts_of_nickels{};


		parts_of_dollars = entered_cents_amout % CENTS_DOLLARS;
		parts_of_quarters = parts_of_dollars % CENTS_QUARTER;
		parts_of_dimes = parts_of_quarters % CENTS_DIME;
		parts_of_nickels = parts_of_dimes % CENTS_NICKEL;

		dollars = entered_cents_amout / CENTS_DOLLARS;
		quarters = parts_of_dollars / CENTS_QUARTER;
		dimes = parts_of_quarters / CENTS_DIME;
		nickels = parts_of_dimes / CENTS_NICKEL;
		pennys = parts_of_nickels / CENTS_PENNY;

		cout << "\nYou can provide this change as follows: " << endl;
		cout << "dollars    :  " << dollars << endl;
		cout << "quartes    :  " << quarters << endl;
		cout << "dimes    :  " << dimes << endl;
		cout << "nickels    :  " << nickels << endl;
		cout << "pennys    :  " << pennys << endl;
	}
	else
	{
		cout << "You must provide number greater or equal 0!";
	}

	return 0;
}
