#include "SimpleHangman.h"
#include <cstring>
#include <cctype>  // for tolower function
#include <iostream>
using namespace std;


SimpleHangman::SimpleHangman(const char name[],int guesses) :Hangman(guesses)
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


int SimpleHangman::letterToStoragePosition(char c) const
{
  int pos;
  if (c>='a' && c<='z')
    pos = c - 'a';
  else
    if (c>='A' && c<='Z')
      pos = c - 'A';
  else
    pos = -1;
  return pos;
}
