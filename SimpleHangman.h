#include "Hangman.h"

class SimpleHangman : public Hangman{
  public:
  SimpleHangman(const char name[],int guess);
  int letterToStoragePosition(char c) const;

};