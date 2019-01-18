/* this is the console executable, that make use of the bull cows Class. 
this acts as the view in MVC pattern, and is reponsible ofr all 
user interaction. For game logic see the FBullCowGame Class.

*/




#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
Ftext GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// the entry level of the program
int main()
{
	

	bool Resp = true;
	do {
		PrintIntro();
		PlayGame();
		Resp=AskToPlayAgain();
	} while (Resp);

	return 0;
}

void PlayGame()
{

	BCGame.Reset();

	int32 MaxTries= BCGame.GetMaxTries();

	// loop asking for guesses while the game is not won and there are still tries remaing
	
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry()<= MaxTries)
	{

		Ftext Guess = GetValidGuess(); 
		
		


		//Submite valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		

		std::cout << "Bulls=" << BullCowCount.Bulls;
		std::cout << ". Cows=" << BullCowCount.Cows << "\n\n";


	}
	PrintGameSummary();
	

	return;
}

void PrintIntro() {
	// introduce the game
	
	std::cout << "\n Welcome to bull and Cows \n";
	std::cout << "can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram im thinking of \n";

	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "You WON!! \n\n";

	}
	else
	{
		std::cout << "Bad luck \n\n";
	}
}

// loop continuisly until the user give a valid guess
Ftext GetValidGuess() { 
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	Ftext Guess = "";
	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess here: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word . \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a Isogram. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter the word in Lowercases. \n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again (y/n)?  ";
	Ftext Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

