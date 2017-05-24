#include "stdafx.h"
#include <iostream>

int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }

    return number * factorial(number - 1);
}

void quiz1()
{
    int result = factorial(7);

    std::cout << result;
}

/*
 * 1) A factorial of an integer N (written N!) is defined as the product (multiplication) of all the 
 * numbers between 1 and N (0! = 1). Write a recursive function called factorial that returns the factorial 
 * of the input. Test it with the first 7 factorials.
 * 
 * Hint: Remember that x * y = y * x, so the product of all the numbers between 1 and N is the same as the 
 * product of all the numbers between N and 1.
 */