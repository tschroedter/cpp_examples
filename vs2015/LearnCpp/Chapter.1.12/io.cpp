#include "stdafx.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";

    int number;

    std::cin >> number;

    return number;
}

void writeAnswer(int number)
{
    std::cout << "The answer is " << number;
}