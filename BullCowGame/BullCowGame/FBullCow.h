#pragma once
#include <string>

class FbullCow {

public:
	FbullCow(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string);

private:
	//see constructor for initilisation
	int MyCurrentTry;
	int MyMaxTries;

};