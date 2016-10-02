#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FbullCow {

public:
	FbullCow(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);

private:
	//see constructor for initilisation
	int32 MyCurrentTry;
	int32 MyMaxTries;

};