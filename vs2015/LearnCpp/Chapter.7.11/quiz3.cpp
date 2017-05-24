#include "stdafx.h"
#include <iostream>

int getNumber()
{
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    // if the user entered something invalid
    if (std::cin.fail())
    {
        std::cin.clear(); // reset any error flags
        std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
    }

    return number;
}

void toBinary(int number)
{
    if (number < 2)
    {
        std::cout << number;
        return;
    }

    toBinary(number / 2);

    int zeroOrOne = number % 2;

    std::cout << zeroOrOne;
}

void quiz3()
{
    int number = getNumber();

    toBinary(number);
}

/*
 * 3) This one is slightly trickier. Write a program that asks the user to enter an integer, 
 *    and then uses a recursive function to print out the binary representation for that number. 
 *    Use method 1 from lesson 3.7 -- Converting between binary and decimal.
 *    
 *    Hint: Using method 1, we want to print the bits from the "bottom up", which means in reverse 
 *    order. This means your print statement should be _after_ the recursive call.
 */