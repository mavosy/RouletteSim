#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int InitialChipCount = 1000;
const int Bet100 = 100;
const int Bet300 = 300;
const int Bet500 = 500;
const int WinFactorNumber = 10;
const int WinFactorColor = 2;

/// <summary>
/// Takes an integer input from the player, validates it and returns it
/// </summary>
/// <param name="">Prompt to player to inform them of which input is expected</param>
/// <returns>An integer input by the player</returns>
int getInputInt(string prompt)
{
	int enteredNumber;

	while (true)
	{
		cout << prompt;
		cin >> enteredNumber;

		if (cin.fail())		// checks for fail flags in the input, for example if the value the player provided is not parsable to an integer.
		{
			cin.clear();											// clears the flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// flushes the buffer to make room for future validations
			cout << "Please enter a valid number." << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return enteredNumber;
		}
	}

	return enteredNumber;
}

/// <summary>
/// Takes a string input from the player and returns it
/// </summary>
/// <param name="">Prompt to player to inform them of which input is expected</param>
/// <returns>A string input by the player</returns>
string getInputString(string prompt)
{
	string enteredString;

	cout << prompt;
	getline(cin, enteredString);	// sets the second parameter to the value of the first input parameter

	return enteredString;
}

/// <summary>
/// Checks if a number is zero or less
/// </summary>
/// <param name="">Number to be validated</param>
/// <returns>Boolean: True if number is zero or less, otherwise false</returns>
bool isZeroOrLess(int number)
{
	return number <= 0;
}

/// <summary>
/// Checks if a number is even, using modulus
/// </summary>
/// <param name="">Number to be validated</param>
/// <returns>Boolean: True if number is even, otherwise false</returns>
bool isEven(int number)
{
	return number % 2 == 0;
}

/// <summary>
/// Prints a welcome message to the player
/// </summary>
void welcomeMessage()
{
	cout << "Welcome to the Roulette table!" << endl;
}

/// <summary>
/// Greets the player with the given name
/// </summary>
/// <param name="">Name of the player</param>
void greetPlayer(string playerName)
{
	cout << "Hello " << playerName << "!" << endl;
}

/// <summary>
/// Prompts the player to enter their name, and returns it
/// </summary>
/// <returns>The name of the player</returns>
string getPlayerName()
{
	string playerName = getInputString("Please tell me your name: ");
	return playerName;
}

// TODO : Add user decided buy-in
///// <summary>
///// Gets the amount the player wants to buy-in for
///// </summary>
///// <returns>The buy-in amount</returns>
//int getBuyIn()
//{
//	cout << "How much do you want to gamble for today?" << endl;
//	cout << "One chip is one dollar!" << endl;
//	int buyIn = getInputInt("Please enter you buy-in amount: ");
//
//	while (isZeroOrLess(buyIn))
//	{
//		cout << "You have to buy chips to play." << endl;
//		buyIn = getInputInt("Please enter you buy-in amount: ");
//	}
//	return buyIn;
//}

/// <summary>
/// Checks if the bet amount is allowed according to preset rules
/// </summary>
/// <param name="">The bet input by the player</param>
/// <returns>Boolean: True if bet amount is allowed, otherwise false</returns>
bool isAllowedBetAmount(int bet)
{
	return bet == Bet100 || bet == Bet300 || bet == Bet500;
}

/// <summary>
/// Gets and validates the bet amount as an input from the player
/// </summary>
/// <param name="">The players current balance</param>
/// <returns>The amount the player wants to bet</returns>
int getBetAmount(int balance)
{
	int bet = 0;
	while (true)
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
			break;
		}
		else
		{
			cout << "You cannot afford this bet!" << endl;
			cout << "Please adjust your bet." << endl;
		}
	}
	return bet;
}

/// <summary>
/// Checks if the given number is 1 or 2
/// </summary>
/// <param name="">The number to be validated</param>
/// <returns>Boolean: True if number is 1 or 2, otherwise false</returns>
bool isOneOrTwo(int number)
{
	return number == 1 || number == 2;
}

/// <summary>
/// Prints the player's current balance
/// </summary>
/// <param name="">The player's current balance</param>
void printBalance(int balance)
{
	cout << "Your current balance is " << balance << " chips." << endl;
}

/// <summary>
/// Gets the players choice of bet, numbers or colors
/// </summary>
/// <returns>1 for number, 2 for color</returns>
int getBetChoice()
{
	int betChoice = 0;
	while (true)
	{
		cout << "You can bet on a number or a color" << endl;
		cout << "Enter 1 for betting on a number (1-36)" << endl;
		cout << "Enter 2 for betting on a color (red or black)" << endl;
		betChoice = getInputInt("Choose what to bet on: ");

		if (isOneOrTwo(betChoice))
		{
			break;
		}
		else 
		{
			cout << "Invalid choice. Please try again." << endl;
		}

	}
	return betChoice;
}

/// <summary>
/// Checks if the given number is between 1 and 36 (both inclusive)
/// </summary>
/// <param name="">The number to be validated</param>
/// <returns>Boolean: True if number is in range 1-36, otherwise false</returns>
bool isOneToThirtySix(int number)
{
	return number >= 1 && number <= 36;
}

/// <summary>
/// Gets the number the player wants to bet on, in range 1-36
/// </summary>
/// <returns>The number the player wants to bet on</returns>
int getChosenNumber()
{
	int chosenNumber = 0;
	while (true)
	{
		cout << "You can bet on numbers 1-36" << endl;
		chosenNumber = getInputInt("Enter the number you want to bet on: ");

		if (isOneToThirtySix(chosenNumber))
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return chosenNumber;
}

/// <summary>
/// Derives the color as a string from the given color digit
/// </summary>
/// <param name="">The integer representing the color</param>
/// <returns>A string representing the color</returns>
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

/// <summary>
/// Gets the color the player wants to bet on as an integer
/// </summary>
/// <returns>An integer representing the chosen color</returns>
int getChosenColor()
{ 
	int chosenColorDigit = 0;
	while (true)
	{
		cout << "You can bet on red or black" << endl;
		chosenColorDigit = getInputInt("Enter 1 for red or 2 for black: ");

		if (isOneOrTwo(chosenColorDigit))
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return chosenColorDigit;
}

/// <summary>
/// Prompts the the player for a binary answer (y/n), validates and returns it
/// </summary>
/// <param name="">The prompt to which the player is asked to respond</param>
/// <returns>Boolean: True for y and false for n</returns>
bool getConfirmation(string prompt)
{
	char binaryChar;
	while (true)
	{
		cout << prompt << " (y/n)" << endl;
		cin >> binaryChar;

		if (binaryChar == 'y' || binaryChar == 'n')
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return binaryChar == 'y';
}

/// <summary>
/// The main entry point of the RouletteSim program.
/// Initializes the game, manages the main game loop, 
/// processes user bets and total chip cunt, and determines win or loss outcomes. 
/// The game loop continues until the player chooses to stop or runs out of money.
/// </summary>
/// <returns>
/// Returns 0 if the player decides to quit playing, upon which the program ends.
/// </returns>
int main()
{
	srand(time(0));
	welcomeMessage();

	const string playerName = getPlayerName();

	greetPlayer(playerName);

	int balance = InitialChipCount;

	while (balance >= 100)
	{
		printBalance(balance);
		int betAmount = getBetAmount(balance);
		int betChoice = getBetChoice();

		int chosenNumber = 0;
		int chosenColorDigit = 0;
		string chosenColor = "";

		if (betChoice == 1)
		{
			chosenNumber = getChosenNumber();
			cout << "You have chosen to bet on number " << chosenNumber << endl;

		}
		else		// if (betChoice == 2) Bet choice can only be 1 or 2.
		{
			chosenColorDigit = getChosenColor();
			chosenColor = getColorName(chosenColorDigit);
			cout << "You have chosen to bet on " << chosenColor << endl;
		}

		int resultNumber = rand() % 36 + 1;		// randomizing a number 1-36
		
		string resultColor = getColorName(resultNumber);

		cout << "The wheel spins... and stops at " << resultNumber << " - " << resultColor << endl;

		balance -= betAmount;		// paying for the bet

		if (resultNumber == chosenNumber)
		{
			int payout = betAmount * WinFactorNumber;
			balance += payout;
			cout << "You bet on the right number!" << endl;
			cout << "You won " << payout << " chips!" << endl;
		}
		else if (resultColor == chosenColor)
		{
			int payout = betAmount * WinFactorColor;
			balance += payout;
			cout << "You bet on the right color!" << endl;
			cout << "You won " << payout << " chips!" << endl;
		}
		else
		{
			cout << "I'm sorry, you didn't win. Better luck next time!" << endl;
			cout << "You lost " << betAmount << " chips." << endl;
		}

		printBalance(balance);
		if (balance < 100)
		{
			cout << "You have run out of money. The game is over." << endl;
			bool wantsToPlayAgain = getConfirmation("Do you want to play again from the beginning? Your chip count will be reset.");
			if (wantsToPlayAgain)
			{
				balance = InitialChipCount;
			}
			continue;
		}

		bool continueToNextRound = getConfirmation("Do you want to continue to the next round of betting?");
		if (continueToNextRound)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "Thanks for playing! Come again!" << endl;
	return 0;
}