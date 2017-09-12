#include "FBullCowGame.h"

int32 FBullCowGame::getMaxTries() const { return maxTries; }
int32 FBullCowGame::getCurrentTry() const { return currentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame()
	{
	Reset(8);
	}

void FBullCowGame::Reset(int32 wordLength)
	{
	maxTries = 8;
	currentTry = 1;
	bGameIsWon = false;

	const FString HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;

	return;
	}

EWordStatus FBullCowGame::checkGuessValidity(FString aGuess) const
	{
	if (false) // if not isogram
		{
		return EWordStatus::Not_Isogram;
		}
	else if (false) // if not lowerrcase
		{
		return EWordStatus::Not_Lowercase;
		}
	else if (aGuess.length() != getHiddenWordLength()) // if wrong length
		{
		return EWordStatus::Wrong_Length;
		}
	else
		return EWordStatus::OK;
	}

// receives valid guess, increments turn, return count.
FBullCowCount FBullCowGame::submitGuess(FString aGuess)
	{
	currentTry++;

	FBullCowCount BullCowCount;
	int32 hiddenWordLength = myHiddenWord.length();

	for (int32 i = 0; i < hiddenWordLength; i++)
		{
		for (int32 j = 0; j < hiddenWordLength; j++)
			{
			if (aGuess[j] == myHiddenWord[i])
				{
				if (i == j)
					BullCowCount.Bulls++;
				else
					BullCowCount.Cows++;
				}
			}
		}

	if (BullCowCount.Bulls == hiddenWordLength)
		bGameIsWon = true;
	else
		bGameIsWon = false;

	return BullCowCount;
	}
