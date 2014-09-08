#include <iostream>
#include <string>
#include <cstdlib>

#include "guessgamLogic.h"

void showRules(void);
void showGuessResults(int match1, int match2);
void showWin(void);
void showLose(GuessGamAnswer &answer);
std::string getInput(void);
bool isInputLegal(const std::string &input);

int main(void)
{
   srand(time(NULL));
   GuessGamAnswer answer;
   answer.randomGenerate();

   showRules();

   // allow 10 guesses at maximum
   for (int i = 0; i < 10; ++i)
   { 
      std::string input;
      do
      {
         input = getInput();
      } while (!isInputLegal(input));

      int match1 = 0, match2 = 0;
      answer.evaluateGuess(input, match1, match2);
      if (match1 < 4)
         showGuessResults(match1, match2);
      else
	 showWin();
   }

   showLose(answer);
}

void showRules(void)
{
   std::cout << "Guessing game" << std::endl;
   std::cout << std::endl;

   std::cout << "The answer is a 4 digit number of the form #-#-#-# with no repeats." << std::endl;
   std::cout << "You get 10 guesses.  For each guess you will be told how many digits" << std::endl;
   std::cout << "are correct and in the right spot, along with how many are correct but" << std::endl;
   std::cout << "in the wrong spot." << std::endl;
   std::cout << std::endl;

   std::cout << "Good luck!" << std::endl;
   std::cout << std::endl;
}

void showGuessResults(int match1, int match2)
{
   std::cout << match1 << " correct/right, " << match2 << " correct/wrong" << std::endl;
}

void showWin(void)
{
   std::cout << "Correct!  You win." << std::endl;
}

void showLose(GuessGamAnswer &answer)
{
   std::cout << "Game Over!  The answer was : " << answer.getDigits() << std::endl;
}

std::string getInput(void)
{
   std::cout << "Guess >> ";	
   std::string input = "";
   getline(std::cin, input);
   return input;
}

bool isInputLegal(const std::string &input)
{
   if (input.length() != 4)
      return false;

   for (int i = 0; i < NUM_DIGITS; i++)
   {
      if (input[i] < '0' || input[i] > '9')
         return false;
   }   

   return true;
}
