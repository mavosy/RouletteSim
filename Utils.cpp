#include "Utils.h"

#include <iostream>
#include <string>

using namespace std;

const int Bet100 = 100;
const int Bet300 = 300;
const int Bet500 = 500;

// Prompts the player about what input is expected, takes an integer input from the player, validates it and returns it
int getInputInt(string prompt)
{
	int enteredNumber;
	bool isValidInput = false;

	while (!isValidInput)
	{
		cout << prompt;
		cin >> enteredNumber;

		if (cin.fail())		// checks for fail flags in the input, for example if the value the player provided is not parsable to an integer.
		{
			cin.clear();											// clears the flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// discards the input buffer to make room for future validations
			cout << "Please enter a valid number." << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			isValidInput = true;
		}
	}

	return enteredNumber;
}

// Prompts the player about what input is expected, takes a string input from the player and returns it
string getInputString(string prompt)
{
	string enteredString;

	cout << prompt;
	getline(cin, enteredString);	// sets the second parameter to the value of the first input parameter

	return enteredString;
}

// Checks if a number is zero or less
bool isZeroOrLess(int number)
{
	return number <= 0;
}

// Checks if a number is even, using modulus
bool isEven(int number)
{
	return number % 2 == 0;
}

// Checks if the bet amount is allowed according to preset rules
bool isAllowedBetAmount(int bet)
{
	return bet == Bet100 || bet == Bet300 || bet == Bet500;
}

// Checks if the given number is within the specified range
bool isNumberInRange(int number, int min, int max)
{
	return number >= min && number <= max;
}

// Prompts the the player for a binary answer as a char (y/n), validates and returns it
bool getAffirmation(string prompt)
{
	char binaryChar;
	bool isValidInput = false;

	while (!isValidInput)
	{
		cout << prompt << " (y/n)" << endl;
		cin >> binaryChar;

		if (binaryChar == 'y' || binaryChar == 'n')
		{
			isValidInput = true;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return binaryChar == 'y';
}