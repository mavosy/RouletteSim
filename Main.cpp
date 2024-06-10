#include "Game.h"

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int InitialChipCount = 1000;
const int WinFactorNumbers = 10;
const int WinFactorColors = 2;

// The main entry point of the RouletteSim program.
// Initializes the game, manages the main game loop, 
// processes user bets and total chip cunt, and determines win or loss outcomes. 
// The game loop continues until the player chooses to stop or runs out of money.
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
		else		// Bet choice can only be 1 or 2.
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
			int payout = betAmount * WinFactorNumbers;
			balance += payout;
			cout << "You bet on the right number!" << endl;
			cout << "You won " << payout << " chips!" << endl;
		}
		else if (resultColor == chosenColor)
		{
			int payout = betAmount * WinFactorColors;
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
		if (balance < 100)		// minimum bet is 100
		{
			cout << "You have run out of money. The game is over." << endl;
			if (wantsToRestartGame())		// asks the player if they want to restart the game from beginning
			{
				balance = InitialChipCount;
			}
			continue;
		}

		if (continueToNextRound())		// asks the player if they want to continue to the next round
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