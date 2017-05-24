// Chapter.2.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool isDigitPrime(int digit)
{
    if (digit == 1)
    {
        return true;
    }

    if (digit == 2)
    {
        return true;
    }

    if (digit == 3)
    {
        return true;
    }

    if (digit == 5)
    {
        return true;
    }

    if (digit == 7)
    {
        return true;
    }

    return false;
}

void printResult(int number)
{
    if (isDigitPrime(number))
    {
        std::cout << "The digit is prime";
    }
    else
    {
        std::cout << "The digit is not a prime";
    }
}

int main()
{
    std::cout << "Digit: ";

    int number = 0;
    std::cin >> number;

    printResult(number);

    return 0;
}

