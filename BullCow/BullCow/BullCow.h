#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	InvalidStatus, OK, NotIsogram, WrongLength, NotLowercase
};

class BullCow {

public:
	BullCow();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;
	bool IsGameWon() const;
	EGuessStatus GuessValidity(FString) const;

	void Reset();
	BullCowCount Submit(FString);

private:
	int32 currentTry;
	FString hiddenWord;
	bool isGameWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

};