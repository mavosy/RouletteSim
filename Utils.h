#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using namespace std;

// Prompts the player about what input is expected, takes an integer input from the player, validates it and returns it
int getInputInt(string prompt);

// Prompts the player about what input is expected, takes a string input from the player and returns it
string getInputString(string prompt);

// Checks if a number is zero or less
bool isZeroOrLess(int number);

// Checks if a number is even, using modulus
bool isEven(int number);

// Checks if the bet amount is allowed according to preset rules
bool isAllowedBetAmount(int bet);

// Checks if the given number is within the specified range
bool isNumberInRange(int number, int min, int max);

// Prompts the the player for a binary answer as a char (y/n), validates and returns it
bool getConfirmation(string prompt);

#endif