#include "FBullCowGame.h"

using int32 = int;

void FbullCow::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}
FbullCow::FbullCow()
{
	Reset();
}
//adding const is a saftey feature that will disregard any variable changes
//at compile time - opens variable for modification dynamically
int32 FbullCow::GetMaxTries () const
{
	return MyMaxTries;
}

int32 FbullCow::GetCurrentTry () const
{
	return MyCurrentTry;
}

bool FbullCow::IsGameWon() const
{
	return false;
}

bool FbullCow::CheckGuessValidity(FString)
{
	return false;
}
//recieve a valid guess, increments turn and return count
BullCowCount FbullCow::SubmitGuess(FString)
{
	MyCurrentTry++;	//incremenet the turn number
	BullCowCount BullCowCount; //set up a return variable

	return BullCowCount;
}
