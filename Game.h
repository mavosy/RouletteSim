#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

using namespace std;

// Prints a welcome message to the player
void welcomeMessage();

// Prompts the player to enter their name, and returns it as a string
string getPlayerName();

// Greets the player with the given name
void greetPlayer(string playerName);

// Gets and validates the bet amount as an input from the player
int getBetAmount(int balance);

// Prints the player's current balance
void printBalance(int balance);

// Gets the players choice of bet, either numbers or colors, as an integer
int getBetChoice();

// Gets the number the player wants to bet on, in range 1-36
int getChosenNumber();

// Derives the color as a string from the given color digit
string getColorName(int colorDigit);

// Gets the color the player wants to bet on as an integer
int getChosenColor();

// Asks the player if they want to play again from the beginning
bool wantsToRestartGame();

// Asks the player if they want to continue to the next round
bool continueToNextRound();

#endif