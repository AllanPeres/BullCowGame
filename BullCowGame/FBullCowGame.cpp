#include "FBullCowGame.h";

FBullCowGame::FBullCowGame() {	Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (false) {
		return EGuessStatus::Not_Isogram;// if the guess isn't an isogram,
	} else if (false) {
		return EGuessStatus::Not_Lowercase;// if the guess isn't lowercase, 
	} else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;// if the guess length is wrong
	} else {
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns the count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				//if they match in the same place
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;//incriment bulls
				} else {
					BullCowCount.Cows++;//incriment cows
				}
			}
		}
	}

	return BullCowCount;
}


