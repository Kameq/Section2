/* This is the console executable, that makes use of FBullCow class
	 This acts as main view in a MVC pattern and i responsible for all user interaction
	 Game logic is in FBullCowGame class.

*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

//using namespace std;
void intro();
void summary();
void playGame();
FText getGuess();
bool playAgain();

FBullCowGame BCGame; // make instance of new game

int main()
	{
	int32 pause;
	bool bAgain = false;

	intro();
	do
		{
		BCGame.Reset(12);
		playGame();
		summary();
		bAgain = playAgain();
		}
	while (bAgain);
	
	// pause console
	std::cin >> pause;
	return 0;
	}

void playGame()
	{
	while (!BCGame.isGameWon() && BCGame.getCurrentTry() <= BCGame.getMaxTries())
		{
		FText Guess = getGuess();
		FBullCowCount bullCowCount = BCGame.submitGuess(Guess);
		std::cout << "Bull count: " << bullCowCount.Bulls << std::endl;
		std::cout << "Cows count: " << bullCowCount.Cows << std::endl << std::endl;
		}

	return;
	}

// welcome
void intro()
	{
	std::cout << "Welcome to game Cows and Bulls." << std::endl;
	std::cout << "Can you guess " << BCGame.getHiddenWordLength() << " letter word" << std::endl;

	return;
	}

// summary
void summary()
	{
	if (BCGame.isGameWon() && BCGame.getCurrentTry() <= BCGame.getMaxTries())
		std::cout << "You Win ! On " << BCGame.getCurrentTry() - 1 << " try." << std::endl;
	else if (BCGame.getCurrentTry() > BCGame.getMaxTries())
		std::cout << "You dont have any more tries !" << std::endl;

	return;
	}

// get guess from player
FText getGuess() 
	{
	FText Guess = "";
	EWordStatus status = EWordStatus::Invalid;

	do
		{
		std::cout << BCGame.getCurrentTry() << ". try - Enter your word: ";
		std::getline(std::cin, Guess);
		status = BCGame.checkGuessValidity(Guess);

		switch (status)
			{
			case EWordStatus::OK:
				break;

			case EWordStatus::Not_Isogram:
				std::cout << "Please enter isogram word" << std::endl;
				break;

			case EWordStatus::Not_Lowercase:
				std::cout << "Please enter a lowercase word" << std::endl;
				break;

			case EWordStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word." << std::endl;
				break;

			default:
				break;
			}
		}
	while (status != EWordStatus::OK);
	
	return Guess;
	}

bool playAgain() 
	{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	if(Response[0] == 'y' || Response[0] == 'Y')
		return true;
	else
		return false;
	}
