#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int guessInput, remainingGuesses, newRangeMax, newRangeMin;

	// creates a seed for rand. # generation
	srand(time(0));
	int targetNumber = (rand() % 100) + 1;

	cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;

	// set initial range
	newRangeMax = 100;
	newRangeMin = 1;

	for(int currentGuess = 0; currentGuess <= 5; currentGuess++){

		remainingGuesses = 5 - currentGuess;

		if(remainingGuesses != 0) {
			cout << "Range: [" << newRangeMin << ", " << newRangeMax << "], Number of guesses left: "
			     << remainingGuesses << "\nYour guess: ";
			cin >> guessInput;
		}

		if(guessInput == targetNumber){
			cout<<"Congrats! You guessed my number in "<<currentGuess<<" guesses.";
			currentGuess = 6;
		} else if(remainingGuesses != 1) {
			if (guessInput > targetNumber) {
				cout << "Wrong! My number is smaller.\n" <<endl;
				newRangeMax = guessInput - 1;
			} else if (guessInput < targetNumber) {
				cout << "Wrong! My number is bigger.\n" <<endl;
				newRangeMin = guessInput + 1;
			}
		} else if(remainingGuesses == 1){
			cout<<"Out of guesses! My number is "<<targetNumber<<endl;
			currentGuess = 6;
		}
	}

	return 0;
}

