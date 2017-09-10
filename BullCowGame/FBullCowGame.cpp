#include "FBullCowGame.h"

int FBullCowGame::getMaxTries() const { return maxTries; }
int FBullCowGame::getCurrentTry() const { return currentTry; }

FBullCowGame::FBullCowGame()
	{
	Reset(8);
	}
void FBullCowGame::Reset(int wordLength)
	{
	maxTries = 8;
	currentTry = 1;

	return;
	}

bool FBullCowGame::isGameWon() const
	{

	return false;
	}

bool FBullCowGame::checkGuessValidity(std::string)
	{

	return false;
	}
