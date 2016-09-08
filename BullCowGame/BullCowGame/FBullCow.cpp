#include "FBullCow.h"

void FbullCow::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;

	return;
}
FbullCow::FbullCow()
{
	Reset();
}
//adding const is a saftey feature that will disregard any variable changes
//at compile time - opens variable for modification dynamically
int FbullCow::GetMaxTries () const
{
	return MyMaxTries;
}

int FbullCow::GetCurrentTry () const
{
	return MyCurrentTry;
}

bool FbullCow::IsGameWon() const
{
	return false;
}

bool FbullCow::CheckGuessValidity(std::string)
{
	return false;
}
