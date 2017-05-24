// Chapter.3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getNumber()
{
    std::cout << "Number: ";

    int number;
    std::cin >> number;

    return number;
}

bool isEven(int number)
{
    return number % 2 == 0;
}

void displayResult(int number)
{
    if (isEven(number))
    {
        std::cout << "Even";
    }
    else
    {
        std::cout << "Odd";
    }
}

int main()
{
    int number = getNumber();

    displayResult(number);

    return 0;
}

/*
 * 2) Write a program that asks the user to input an integer, and tells the user whether the number 
 * is even or odd. Write a function called isEven() that returns true if an integer passed to it is 
 * even. Use the modulus operator to test whether the integer parameter is even.
 *
 * Hint: You’ll need to use if statements and the comparison operator (==) for this program. 
 * See section 2.7 -- Chars if you need a refresher on how to do this.
 */

