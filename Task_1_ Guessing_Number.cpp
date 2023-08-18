#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
     srand(static_cast<unsigned int>( time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber =  rand() % 100 + 1;

    int userGuess;
    int numAttempts = 0;

     cout << "Welcome to the Number Guessing Game!" << endl;
     cout << "I've selected a random number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        numAttempts++;

        if (userGuess < randomNumber) {
             cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
             cout << "Too high! Try again." << endl;
        } else {
             cout << "Congratulations! You've guessed the correct number in " << numAttempts << " attempts." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
