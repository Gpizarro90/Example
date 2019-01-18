#include "FBullCowGame.h"


void FBullCowGame::Reset()
{
	
	constexpr int MAX_TRIES=3;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const Fstring Hidden_WORD = "planeto";
	MyHiddenWord = Hidden_WORD;

	bGameisWon = false;
	return ;
}

// receives a Valid guess, increments turn, and return count
FBullCowCount FBullCowGame::SubmitValidGuess(Fstring Guess)

{
	//incremetar turno
	MyCurrentTry++;

	// setup a return variable

	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	// loop throught all letters in the guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				if (MHWChar == GChar) 
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameisWon = true;		
	}
	else
	{
		bGameisWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(Fstring Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;//setup our map
	for (auto letter : Word)   //for all letters of the word
	{
		letter = tolower(letter);
		if (LetterSeen[letter]) {
			return false;
		}
		else
		{
			LetterSeen[letter] = true;
		}
		// loop through all the letters of the word
			// if the letter is in the map
				// we do Not have an isogram
			// otherwise
				//add the letter to the maps as seen
	}
	
	return true;
}

bool FBullCowGame::IsLowercase(Fstring Word) const
{
	for (auto Letter : Word)
	{
		if(!islower(Letter)){ return false; }
		// if not a lowercase letter 

	}
	return true;
}

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	
	
	return int32(MyHiddenWord.length());
}

bool FBullCowGame::IsGameWon() const { return bGameisWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (!IsIsogram(Guess)) //if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;

	}
	else if (!IsLowercase(Guess)) // if the guess inst all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length())
	{
		return EGuessStatus::Wrong_length;
	}
	else
	{
		return EGuessStatus::OK;
	}



	return EGuessStatus::OK; 
}
