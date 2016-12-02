#include "Hangman.h"
#include <cstring>
#include <cctype>  // for tolower function
#include <iostream>
using namespace std;

Hangman::Hangman()
{
  cout<<"In default Constructor";
}
Hangman::Hangman(int guesses)
{
  int i;
  for (i=0;i<ALPHABETSIZE;i++)
    lettersGuessed[i]=false;
  numGuessesAllowed = guesses;
  numWrongGuesses = 0;
}


Hangman::Hangman(const char name[], int guesses)
{

  int i;
  for (i=0;i<ALPHABETSIZE;i++)
    lettersGuessed[i]=false;
  numGuessesAllowed = guesses;
  numWrongGuesses = 0;

  for (int i=0;i<strlen(name);i++)
    secretWord[i]=tolower(name[i]);
  secretWord[i]='\0';

}



// int Hangman::letterToStoragePosition(char c) const
// {
//   int pos;
//   if (c>='a' && c<='z')
//     pos = c - 'a';
//   else
//     if (c>='A' && c<='Z')
//       pos = c - 'A';
//   else
//     pos = -1;
//   return pos;
// }

int Hangman::getNumWrongGuesses() const
{
  return numWrongGuesses;
}

bool Hangman::validGuess(char c) const
{
  return (letterToStoragePosition(c)!=-1  && !letterUsed(c));
}

void Hangman::addGuess(char c)
{
  bool letterfound=false;
  int i=0;
  
  while (i<strlen(secretWord) && !(letterfound=(secretWord[i++]==c)));

  if (!letterfound)
    numWrongGuesses++;

  int pos = letterToStoragePosition(c);

  lettersGuessed[pos] = true;
}

bool Hangman::letterUsed(char c) const
{
  int pos = letterToStoragePosition(c);

  return lettersGuessed[pos];
}

void Hangman::displaySecretWord() const
{
  for (int i=0;i<strlen(secretWord);i++)
    if (letterUsed(secretWord[i]))
      cout << secretWord[i];
    else
      cout << '*';
  cout << endl;
}


void Hangman::uncoverSecretWord() const
{
  cout << secretWord << endl;
}

bool Hangman::guessesRemaining() const
{
  return numGuessesAllowed > numWrongGuesses;
}

int Hangman::getGuessesAllowed() const
{
  return numGuessesAllowed;
}

int Hangman::getWrongGuesses() const
{
  return numWrongGuesses;
}

bool Hangman::won() const
{
  bool gamewon=true;

  int i=0;
  while (i<strlen(secretWord) && letterUsed(secretWord[i++]));

  return letterUsed(secretWord[i-1]);
}


	
