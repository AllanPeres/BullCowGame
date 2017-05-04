#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString Guess) const; //TODO make a more rich return value;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value;
	
	// counts bulls & cows, and increases try # assuming valid guess
	FBullCowCount SubmitGuess(FString Guess);


private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
	FString MyHiddenWord;

};