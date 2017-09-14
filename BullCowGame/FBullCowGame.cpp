#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

int32 FBullCowGame::getCurrentTry() const { return currentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame()
	{
	Reset(8);
	}

int32 FBullCowGame::getMaxTries() const 
	{
	// word length -> max tries.
	TMap<int32, int32> WordLengthToMaxTries { {3, 3}, {4, 7}, { 5, 10 }, { 6, 15 }, { 7, 20 } };
	return WordLengthToMaxTries[myHiddenWord.length()];
	}

void FBullCowGame::Reset(int32 wordLength)
	{
	currentTry = 1;
	bGameIsWon = false;

	const FString HIDDEN_WORD = "pla"; // must be ISOGRAM
	myHiddenWord = HIDDEN_WORD;

	return;
	}

EWordStatus FBullCowGame::checkGuessValidity(FString aGuess) const
	{
	if (!isLowerCase(aGuess)) // if not lowerrcase
		{
		return EWordStatus::Not_Lowercase;
		}
	else if (!isIsogram(aGuess)) // if not isogram
		{
		return EWordStatus::Not_Isogram;
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

bool FBullCowGame::isIsogram(FString aWord) const
	{
	if (aWord.length() <= 1) { return true; }

	TMap<char, bool> letterSeen;

	for (auto letter : aWord)
		{
		letter = tolower(letter);
		if (!letterSeen[letter])
			letterSeen[letter] = true;
		else if (letterSeen[letter])
			return false;
		}

	return true;
	}

bool FBullCowGame::isLowerCase(FString aWord) const
	{
	for (auto letter : aWord)
		{
		if (!islower(letter))
			return false;
		}
	
	return true;
	}
