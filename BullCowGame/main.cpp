#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main(){

	std::cout << BCGame.GetCurrentTry();

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	system("pause");
	return 0;
}

void PrintIntro() {
	//Introduce the game
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop the game to the number of turns
	
	for (int32 count = 0; count < MaxTries; count++) { // TODO change from FOR to WHILE loop once we are validating tries
		FText Guess = GetValidGuess(); 

		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	//TODO summarise game

}


// loop continually until user gives a valid guess
FText GetValidGuess() { 

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try: " << CurrentTry << " Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an word without repeating letters.";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please use just lowercase.";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we got no errors
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 's' || Response[0] == 'Y' || Response[0] == 'S');
}
