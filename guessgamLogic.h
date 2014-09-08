#ifndef _guessgamLogic_h
#define _guessgamLogic_h

#include <string>

#define NUM_DIGITS 4

class GuessGamAnswer
{
   private:

      int digits[NUM_DIGITS];

   public:

      void randomGenerate(void);
      void stringGenerate(const std::string &guess);

      void evaluateGuess(const std::string &guess, int &match1, int &match2);
      std::string getDigits(void);
};

#endif
