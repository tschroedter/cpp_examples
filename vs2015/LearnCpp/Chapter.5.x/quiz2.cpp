#include "stdafx.h"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // static used for efficiency, so we only calculate this value once
                                                                                // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void printIntroduction()
{
    std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";
}
 
int getInteger()
{
    while (true)
    {
        int x;
        std::cin >> x;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }
}

int getGuess()
{
    std::cout << "Guess: ";

    int number = getInteger();

    return number;
}

char getYesOrNo()
{
    while (true)
    {
        char x;
        std::cin >> x;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            switch (x)
            {
            case 'y':
                return 'y';
            case 'n':
                return 'n';
            default:
                std::cout << "Only 'y' or 'n'.  Please try again.\n";
                break;
            }
        }
    }
}

bool playAgain()
{
    std::cout << "Would you like to play again (y/n)? ";

    char yesOrNo = getYesOrNo();

    return 'y' == yesOrNo;
}

bool guess(int randomNumber)
{
    int guess = getGuess();

    if (guess == randomNumber)
    {
        std::cout << "Correct! You win!\n";
        return true;
    }
    else if (guess > randomNumber)
    {
        std::cout << "Your guess is too high.\n";
    }
    else
    {
        std::cout << "Your guess is too low.\n";
    }

    return false;
}

void playHighLow()
{
    const int MaxNumberOfTries = 7;

    int randomNumber = getRandomNumber(1, 100);

    int numberOfTries = 0;
    bool playerWon = false;

    do {
        numberOfTries++;

        if (numberOfTries > MaxNumberOfTries)
        {
            std::cout << "Sorry, you lose.The correct number was " << randomNumber << ".\n";
            break;
        }

        playerWon = guess(randomNumber);
    } while (!playerWon);
}

void quiz2()
{
    srand(static_cast<int>(time(0)));

    printIntroduction();

    do {
        playHighLow();
    } while (playAgain());
}

/*
 *2) Implement a game of hi-lo. First, your program should pick a random integer between 1 and 100. 
 *The user is given 7 tries to guess the number. If the user does not guess the correct number, the 
 *program should tell them whether they guessed too high or too low. If the user guesses the right 
 *number, the program should tell them they won. If they run out of guesses, the program should tell 
 *them they lost, and what the correct number is. At the end of the game, the user should be asked 
 *if they want to play again. If the user doesn’t enter ‘y’ or ‘n’, ask them again.
 *Here’s what your output should look like:
 *Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
 *Guess #1: 64
 *Your guess is too high.
 *Guess #2: 32
 *Your guess is too low.
 *Guess #3: 54
 *Your guess is too high.
 *Guess #4: 51
 *Correct! You win!
 *Would you like to play again (y/n)? y
 *Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
 *Guess #1: 64
 *Your guess is too high.
 *Guess #2: 32
 *Your guess is too low.
 *Guess #3: 54
 *Your guess is too high.
 *Guess #4: 51
 *Your guess is too high.
 *Guess #5: 36
 *Your guess is too low.
 *Guess #6: 45
 *Your guess is too low.
 *Guess #7: 48
 *Your guess is too low.
 *Sorry, you lose.  The correct number was 49.
 *Would you like to play again (y/n)? q
 *Would you like to play again (y/n)? f
 *Would you like to play again (y/n)? n
 *Thank you for playing.
 *Hints:
 * Seed your random number generator with time(0).
 * Visual Studio users: Due to a flaw in the Visual Studio implementation of rand(), call rand() once after seeding to discard the first result.
 * Use the getRandomNumber() function from lesson 5.9 -- Random number generation to pick a random number.
 * Write a function that allows the user to play a single game of hi-lo.
 * Write a function that asks the user if they want to play again and handles the looping logic for an incorrect input.
 *
 */