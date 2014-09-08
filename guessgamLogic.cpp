#include "guessgamLogic.h"
#include <cstdlib>

void GuessGamAnswer::randomGenerate(void)
{
   for (int i = 0; i < NUM_DIGITS; i++)
   {
      bool repeatDigit;
      do
      {
         repeatDigit = false;
	 digits[i] = rand() % 9 + 1;
      
         for (int j = 0; j < i; j++)
            if (digits[i] == digits[j])
               repeatDigit = true;
      }
      while(repeatDigit);
   }
}

void GuessGamAnswer::stringGenerate(const std::string &input)
{
   for (int i = 0; i < NUM_DIGITS; i++)
      digits[i] = input[i] - '0';
}

void GuessGamAnswer::evaluateGuess(const std::string &guess, int &match1, int &match2)
{
   match1 = match2 = 0;

   for (int i = 0; i < NUM_DIGITS; i++)
   {
      int testValue = guess[i] - '0';
      
      if (testValue == digits[i])
         match1 += 1;

      for (int j = 0; j < NUM_DIGITS; j++)
      {
         if (i == j)
            continue;

	 if (testValue == digits[j])
            match2 += 1;
      }
   }
}

std::string GuessGamAnswer::getDigits(void)
{
   std::string strDigits("XXXX");
   //strDigits[0] = 'X';
   //strDigits[1] = 'X';
   //strDigits[2] = 'X';
   //strDigits[3] = 'X';
   //strDigits[4] = '\0';

   for (int i = 0; i < NUM_DIGITS; i++)
      strDigits[i] = digits[i] + '0';

   return strDigits;
}
