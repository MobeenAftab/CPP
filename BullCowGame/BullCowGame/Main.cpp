//Author: Mobeen Aftab
//Date: 26/06/2016

// # - preprocessor directives, importing a library
#include <iostream>	//<> shevrons import standered libraries
					//#include "myCode.h" //use "" for your own library
//Using this method prevents us from writing 'std::' for every function
//Warning: this can create a namespace clash if libraries share same function name
using namespace std;
int main() {

	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows\n";	//std=standered ::=namespace access << = overload operator
	//std::cout << std::endl; //this method std::endl == \n
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram i'm thinking of?\n";
	return 0;
}