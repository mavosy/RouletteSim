#include "Utils.h"
#include "Game.h"

#include <iostream>
#include <string>

using namespace std;

// Prints a welcome message to the player
void welcomeMessage()
{
	cout << "Welcome to the Roulette table!" << endl;
}

// Prompts the player to enter their name, and returns it as a string
string getPlayerName()
{
	return getInputString("Please tell me your name: ");
}

// Greets the player with the given name
void greetPlayer(string playerName)
{
	cout << "Hello " << playerName << "!" << endl;
}

// Gets and validates the bet amount as an input from the player
int getBetAmount(int balance)
{
	int bet = 0;
	bool isValidInput = false;

	while (!isValidInput)
	{
		cout << "You can bet 100 chips, 300 chips or 500 chips" << endl;

		cout << "How much do you want to bet for this roll?" << endl;
		bet = getInputInt("Please enter you bet amount: ");

		if (isZeroOrLess(bet))
		{
			cout << "You have to bet chips to play." << endl;
			cout << "Please adjust your bet." << endl;
		}
		else if (!isAllowedBetAmount(bet))
		{
			cout << "The bet amount is not allowed" << endl;
			cout << "Please adjust your bet." << endl;
		}
		else if (bet <= balance)
		{
			cout << "You have chosen to bet " << bet << " chips." << endl << endl;
			isValidInput = true;
		}
		else
		{
			cout << "You cannot afford this bet!" << endl;
			cout << "Please adjust your bet." << endl;
		}
	}
	return bet;
}

// Prints the player's current balance
void printBalance(int balance)
{
	cout << "Your current balance is " << balance << " chips." << endl;
}

// Gets the players choice of bet, either numbers or colors, as an integer
int getBetChoice()
{
	int betChoice = 0;
	bool isValidInput = false;

	while (!isValidInput)
	{
		cout << "You can bet on a number or a color" << endl;
		cout << "Enter 1 for betting on a number (1-36)" << endl;
		cout << "Enter 2 for betting on a color (red or black)" << endl;
		betChoice = getInputInt("Choose what to bet on: ");

		if (isNumberInRange(betChoice, 1, 2))	// Checks if betChoice is 1-2
		{
			isValidInput = true;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return betChoice;
}

// Gets the number the player wants to bet on, in range 1-36
int getChosenNumber()
{
	int chosenNumber = 0;
	bool isValidInput = false;

	while (!isValidInput)
	{
		cout << "You can bet on numbers 1-36" << endl;
		chosenNumber = getInputInt("Enter the number you want to bet on: ");

		if (isNumberInRange(chosenNumber, 1, 36))	// Checks if chosenNumber is 1-36
		{
			isValidInput = true;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return chosenNumber;
}

// Derives the color as a string from the given color digit
string getColorName(int colorDigit)
{
	if (isEven(colorDigit))
	{
		return "black";
	}
	else
	{
		return "red";
	}
}

// Gets the color the player wants to bet on as an integer
int getChosenColor()
{
	int chosenColorDigit = 0;
	bool isValidInput = false;

	while (!isValidInput)
	{
		cout << "You can bet on red or black" << endl;
		chosenColorDigit = getInputInt("Enter 1 for red or 2 for black: ");

		if (isNumberInRange(chosenColorDigit, 1, 2))
		{
			isValidInput = true;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return chosenColorDigit;
}

// Asks the player if they want to play again from the beginning
bool wantsToRestartGame()
{
	return getAffirmation("Do you want to play again from the beginning? Your chip count will be reset.");
}

// Asks the player if they want to continue to the next round
bool continueToNextRound()
{
	return getAffirmation("Do you want to continue to the next round of betting?");
}