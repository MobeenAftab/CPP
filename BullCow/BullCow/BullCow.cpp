#pragma once

#include "BullCow.h"
#include <map>

//unreal convention
#define TMap std::map

using int32 = int;

//constructor
BullCow::BullCow() {
	Reset();
}

int32 BullCow::GetCurrentTry() const {
	return currentTry;
}

int32 BullCow::GetWordLength() const {
	return hiddenWord.length();
}

bool BullCow::IsGameWon() const {
	return isGameWon;
}

int32 BullCow::GetMaxTries() const {
	TMap<int32, int32> wordLengthToMaxTries{
		{3,6}, {4,8}, {6,15}, {7,20},
	};
	return wordLengthToMaxTries[hiddenWord.length()];
}

void BullCow::Reset() {
								
	const FString HIDDEN_WORD = "drying";
	hiddenWord = HIDDEN_WORD;

	currentTry = 1;
	isGameWon = false;
}

EGuessStatus BullCow::GuessValidity(FString guess) const {

	if (!IsIsogram(guess)) {
		return EGuessStatus::NotIsogram;
	}
	else if (!IsLowercase(guess)) {
		return EGuessStatus::NotLowercase;
	}
	else if (guess.length() != GetWordLength()) {
		return EGuessStatus::WrongLength;
	}
	else {
		return EGuessStatus::OK;
	}

}

BullCowCount BullCow::Submit(FString guess) {

	currentTry++;
	BullCowCount BCC;
	int32 wordLength = hiddenWord.length();

	for (int32 isoChar = 0; isoChar < wordLength; isoChar++) {
		for (int32 guessChar = 0; guessChar < wordLength; guessChar++) {
			if (guess[guessChar] == hiddenWord[isoChar]) {
				if (isoChar == guessChar) {
					BCC.Bulls++;
				}
				else {
					BCC.Cows++;
				}
			}
		}
	}

	if (BCC.Bulls == wordLength) {
		isGameWon = true;
	}
	else {
		isGameWon = false;
	}
	return BCC;
}

bool BullCow::IsIsogram(FString word) const {
	
	if (word.length() <= 1) {
		return true;
	}

	TMap<char, bool> duplicate;
	for (auto dupeChar : word) {
		dupeChar = towlower(dupeChar);
		
		if (duplicate[dupeChar]) {
			return false;
		}
		else {
			duplicate[dupeChar] = true;
		}
	}
	return true;
}

bool BullCow::IsLowercase(FString word) const {

	for (auto chars : word) {
		if (!iswlower(chars)) {
			return false;
		}
	}
	return true;
}