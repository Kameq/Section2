#pragma once
#include <string>

class FBullCowGame 
	{
	public:
		FBullCowGame(); // Constructor

		void Reset(int wordLength); // TODO make more rich return
		int getMaxTries() const;
		int getCurrentTry() const;
		bool isGameWon() const;
		bool checkGuessValidity(std::string);
		// TODO provide methods for countinting bulls and cows, and increment try


	private:
		int maxTries;
		int currentTry;
		//bool isIsogram(std::string);

	};