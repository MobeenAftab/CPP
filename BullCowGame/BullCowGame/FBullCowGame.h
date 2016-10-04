#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//a struct is like a class, all variables are public by default
struct BullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;
};

class FbullCow {

public:
	FbullCow(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);

	//A method for counting bulls & cows and increasing tru #
	BullCowCount SubmitGuess(FString);


private:
	//see constructor for initilisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString myHiddenWord;

};