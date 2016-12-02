#ifndef HANGMAN_H
#define HANGMAN_H
const int ALPHABETSIZE=62;
const int MAXWORDLENGTH=100;
class Hangman
{
public:
  Hangman();
  Hangman(int guesses);
  Hangman(const char name[],int guesses);
  void addGuess(char c);

  bool letterUsed(char c) const;
  bool guessesRemaining() const;
  void displaySecretWord() const;
  void uncoverSecretWord() const;
  int getNumWrongGuesses() const;
  bool validGuess(char c) const;
  int getGuessesAllowed() const;
  int getWrongGuesses() const;
  bool won() const;

 protected:
  virtual int letterToStoragePosition(char c) const = 0;
  char secretWord[MAXWORDLENGTH];
  bool lettersGuessed[ALPHABETSIZE];
  int numGuessesAllowed;
  int numWrongGuesses;
};

#endif