/*Author: Mobeen Aftab
*Date: 26/06/2016
*Messing around with C++, going to build a small guess the word gameto learn 
*the syntax and libarary functions C++ offers befre i start building games in UE4
*/


// # - preprocessor directives, importing a library
#include <iostream>	//<> shevrons import standered libraries
					//#include "myCode.h" //use "" for your own library
#include <string>

#include "FBullCow.h"	//getting access to our header file

/* dont use 'using namespace' anymore as it complicates c++ file and is no longer industry standard
use 'include<>' and 'std::' for imported libraries
using namespace std;	//Using this method prevents us from writing 'std::' for every function
						//Warning: this can create a namespace clash if libraries share same function name
						*/

//Normally these would be stored in a header file
void PrintIntro();	//calling the function as a method before main for compile.
					//otherwise main will not find printintro
void PlayGame();
std::string  GetGuess();
bool AskToPlayAgain();
FbullCow BCGame; //instance of our class FBullCow called BCGame

//The entry point for our application
int main() {

	bool playAgain = false;

	do {
		//method calling function - will run at this stage of main
		PrintIntro();
		PlayGame();
		playAgain = AskToPlayAgain();
	} while (playAgain);
	
	return 0;	//end application

}

//intro function that takes in 0 parameters and returns nothing.
void PrintIntro() {
	//this is an example of encapsulation by bringing 
	//all the abstract variables relevent into this one function scope
	//introduce the game
	constexpr int WORD_LENGTH = 9;	//constexpr = static - evaluated at compile time
	std::cout << "Welcome to Bulls and Cows\n";	//std=standered ::=namespace access << = overload operator
												//std::std::cout << std::endl; //this method std::endl == \n
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram i'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	//loop for number of turns available
	for (int count = 1;count <= MaxTries;count++) {
		std::string Guess= GetGuess();	//take return value from getGuess and input it into local variable Guess
		std::cout << "Your Guess " + Guess << std::endl;
		std::cout << std::endl;
	}
}

//Get Player guess from Keyboard
std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try: " << CurrentTry << " enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);	//port user input to Guess
	return Guess;
}
//Ask player for another round
bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	//boolean to repeat game
	return (Response[0] == 'y') || (Response[0] =='Y');
}


/*Notes:
*Abstraction is a technique for managing complexity, by taking a high level (top-down) solution approach
*Encapsulation is a way to make sure your abstractions are adhered to
*/