#include "PassHangman.h"
#include <cstring>
#include <cctype>  // for tolower function
#include <iostream>
using namespace std;


PassHangman::PassHangman(const char name[],int guesses) :Hangman(guesses)
{
  
 int i;
  for (i=0;i<ALPHABETSIZE;i++)
    lettersGuessed[i]=false;
  numGuessesAllowed = guesses;
  numWrongGuesses = 0;

  for (int i=0;i<strlen(name);i++)
   // secretWord[i]=tolower(name[i]);
  secretWord[i]=name[i];
  secretWord[i]='\0';
}


int PassHangman::letterToStoragePosition(char c) const
{
  int pos;
  if (c>='a' && c<='z')
    pos = c - 'a';
  else
    if (c>='A' && c<='Z')
      pos = c - 'A' + 26;
  else
    if (c>='0' && c<='9')
      pos = c - '0' + 52;
  else
    pos = -1;
  return pos;
}
