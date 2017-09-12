#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount 
	{
	int32 Bulls = 0;
	int32 Cows = 0;
	};

enum class EWordStatus 
	{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
	};

class FBullCowGame 
	{
	public:
		FBullCowGame(); // Constructor

		void Reset(int32 wordLength); // TODO make more rich return
		
		int32 getMaxTries() const;
		int32 getCurrentTry() const;
		int32 getHiddenWordLength() const;

		bool isGameWon() const;
		EWordStatus checkGuessValidity(FString) const;
		FBullCowCount submitGuess(FString);

	private:
		int32 maxTries;
		int32 currentTry;
		FString myHiddenWord;
		bool bGameIsWon;

		//bool isIsogram(FString);

	};