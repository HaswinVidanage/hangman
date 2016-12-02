#include "SimpleHangman.h"
#include "PassHangman.h"

#include <iostream>
using namespace std;

int main()
{
  // Create a hangman game, given a secret word and a 
  // number representing the number of wrong guesses the player
  // is allowed to make
  
  
  SimpleHangman simple("rhythm", 10);
  PassHangman game("Rhythm123", 10);


  char letter;

  // Display the secret word - using the correct
  // letter when the letter has been guessed and a * otherwise
  // So, first time around, the display will be ******
  game.displaySecretWord();

  // continue while the game is not won and the player still has
  // guesses remaining
  while (!game.won() && game.guessesRemaining())
    {
      cout << "Please enter next guess " << endl;
      // get a letter as input and check if it is valid
      // i.e. if it is a proper letter ('a' to 'z') and has
      // not been guessed previously
      do 
	{
	  cin >> letter;
	} while (!game.validGuess(letter));
      // add the guessed letter to the game
      game.addGuess(letter);
      // display the secret word
      game.displaySecretWord();

      // write a message to say how many guesses remain

      cout << "Only " << game.getGuessesAllowed()-game.getWrongGuesses() <<
	" remaining." << endl;
    }
}

