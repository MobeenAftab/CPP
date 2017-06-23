/*
	Bulls and Cows game: player must geuss (cows) the pre selected 
	isogram word (bull), each correct character from guess in bull word position 
	will increment the bull counter by 1. Game won when word is guessed
	correctly withing attempt range.

	@author Mobeen Aftab
	@version 1 23/06/2017
*/

/*
	TODO:: Updates for later versions
		- New Menu with extra features described below
		- Two player mode where one person can select the isogram word
		- Dictonary library where hidden word is randomly selected from lib
		- 
*/

//packages
#include <iostream>
#include <string>
#include "BullCow.h"

//unreal convention
using FText = std::string;
using int32 = int;

//global functions
void Menu();
void Game();
void Summary();
FText PlayerGuess();
bool Reset();

//Instantiate new BC class
BullCow BC;

int main() {

	bool retry = false;
	do {
		Menu();
		Game();
		retry = Reset();
	} while (retry);

	return 0;
}

void Menu() {
	
	std::cout << "\nBulls & Cows ! \n";
	std::cout << "Try to guess the isogram word within the limit. \n";
	std::cout << "Want A challenge ? try a harder difficulty !\n";
	std::cout << "Select your difficulty below\n";
	std::cout << "easy, normal, hard, very hard\n";
	std::cout << std::endl;
	return;
}

void Game() {
	
	BC.Reset();
	int32 maxTries = BC.GetMaxTries();

	while (!BC.IsGameWon() && BC.GetCurrentTry() <= maxTries) {
		FText guess = PlayerGuess();
		BullCowCount BCC = BC.Submit(guess);

		std::cout << "Bulls = " << BCC.Bulls << " ";
		std::cout << "Cows = " << BCC.Cows << " ";

	}

	Summary();
	return;
}

FText PlayerGuess() {

	FText guess = "";
	EGuessStatus status = EGuessStatus::InvalidStatus;

	do {
		int32 currentTry = BC.GetCurrentTry();
		std::cout << "Try " << currentTry << " of " << BC.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, guess);

		status = BC.GuessValidity(guess);
		switch (status) {
		case EGuessStatus::WrongLength:
			std::cout << "Please enter a " << BC.GetWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::NotIsogram:
			std::cout << "Please enter a word without repeating letters. \n\n";
			break;
		case EGuessStatus::NotLowercase:
			std::cout << "Please enter all lowercase letters. \n\n";
			break;
		default:
			break;
		}
	} 
	while (status != EGuessStatus::OK);
	
	return guess;
}

bool Reset() {
	
	std::cout << "Try Again ? (y/n) ";
	FText input = "";
	std::getline(std::cin, input);
	return (input[0] == 'y' || input[1] == 'Y');

}

void Summary() {

	if (BC.IsGameWon()) {
		std::cout << "You Won !\n";
	}
	else {
		std::cout << "Better luck next time!\n";
	}
}