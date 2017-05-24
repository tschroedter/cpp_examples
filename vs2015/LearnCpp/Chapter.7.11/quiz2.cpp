#include "stdafx.h"
#include <iostream>

int sum(int number)
{
    if (number < 10)
    {
        return number;
    }

    int value  = number % 10;

    return value + sum(number / 10);
}

void quiz2()
{
    std::cout << std::endl;
    int result357 = sum(357);
    std::cout << result357 << std::endl;

    int result93427 = sum(93427);
    std::cout << result93427 << std::endl;
}

/*
 * 2) Write a recursive function that takes an integer as input and returns the sum of all the numbers 
 * in the integer (e.g. 357 = 15). Print the answer for input 93427 (which is 25).
 */