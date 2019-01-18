#pragma once
#include <string>
#include <map>
#define TMap std::map 

using Fstring = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus 

{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_length,
	Numeric_values,
	Not_Lowercase
};



class FBullCowGame {

public:

	FBullCowGame(); //constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;

	EGuessStatus CheckGuessValidity(Fstring) const;
	void Reset(); //To do make a more rich return value
	
	// counts bull & cows, and incresing turn # assuming valid guess
	FBullCowCount SubmitValidGuess(Fstring);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord;
	bool bGameisWon;
	bool IsIsogram(Fstring) const;
	bool IsLowercase(Fstring) const;

};
