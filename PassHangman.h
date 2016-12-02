#include "Hangman.h"

class PassHangman : public Hangman{
  public:
  PassHangman(const char name[],int guess);
  int letterToStoragePosition(char c) const;

};