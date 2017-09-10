#include <iostream>
#include <string>
#include "FBullCowGame.h"

//using namespace std;
void intro();
void playGame();
std::string getGuess();
bool playAgain();

FBullCowGame BCGame; // make instance of new game

int main()
	{
	int pause;
	bool bAgain = false;

	intro();
	do
		{
		playGame();

		
		bAgain = playAgain();
		}
	while (bAgain);
	
	// pause console
	std::cin >> pause;
	return 0;
	}

void playGame()
	{
	BCGame.Reset(5);

	// TODO change to do while
	for (int i = 1; i <= BCGame.getMaxTries(); i++)
		{
		std::string Guess = getGuess(); // TODO Validation guesses

		// TODO submit valid guess
		// TODO print number of cows and bulls
		std::cout << "Your word is: " << Guess << std::endl << std::endl;
		}

	// TODO summary
	}

// welcome
void intro()
	{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to game Cows and Bulls." << std::endl;
	std::cout << "Can you guess " << WORD_LENGTH << " letter word" << std::endl;

	return;
	}

// get guess from player
std::string getGuess() 
	{
	std::string Guess = "";
	std::cout << BCGame.getCurrentTry() << ". try - Enter your word: ";
	std::getline(std::cin, Guess);
	
	return Guess;
	}

bool playAgain() 
	{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);


	if(Response[0] == 'y' || Response[0] == 'Y')
		return true;
	else
		return false;
	}
