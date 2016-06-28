/*Author: Mobeen Aftab
*Date: 26/06/2016
*Messing around with C++, going to build a small guess the word gameto learn 
*the syntax and libarary functions C++ offers befre i start building games in UE4
*/


// # - preprocessor directives, importing a library
#include <iostream>	//<> shevrons import standered libraries
					//#include "myCode.h" //use "" for your own library
#include <string>
using namespace std;	//Using this method prevents us from writing 'std::' for every function
						//Warning: this can create a namespace clash if libraries share same function name

//Normally these would be stored in a header file
void PrintIntro();	//calling the function as a method before main for compile.
					//otherwise main will not find printintro
void PlayGame();
string  GetGuess();
//The entry point for our application
int main() {
	
	//method calling function - will run at this stage of main
	PrintIntro();	
	PlayGame();
	
	cout << endl;
	return 0;	//end application

}

//intro function that takes in 0 parameters and returns nothing.
void PrintIntro() {
	//this is an example of encapsulation by bringing 
	//all the abstract variables relevent into this one function scope
	//introduce the game
	constexpr int WORD_LENGTH = 9;	//constexpr = static - evaluated at compile time
	std::cout << "Welcome to Bulls and Cows\n";	//std=standered ::=namespace access << = overload operator
												//std::cout << std::endl; //this method std::endl == \n
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram i'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame() {
	//loop for number of turns available
	constexpr int MAX_TURNS = 5;
	for (int count = 1;count <= MAX_TURNS;count++) {
		string Guess= GetGuess();	//take return value from getGuess and input it into local variable Guess
		cout << "Your Guess " + Guess << endl;
		cout << endl;
	}
}

//Get Player guess from Keyboard
string GetGuess() {
	cout << "Enter your Guess: ";
	string Guess = "";
	getline(cin, Guess);	//port user input to Guess
	return Guess;
}


/*Notes:
*Abstraction is a technique for managing complexity, by taking a high level (top-down) solution approach
*Encapsulation is a way to make sure your abstractions are adhered to
*/