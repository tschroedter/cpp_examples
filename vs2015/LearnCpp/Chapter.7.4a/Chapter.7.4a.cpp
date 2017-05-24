// Chapter.7.4a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int sumTo(int number)
{
    int sum = 0;

    for(int i=1; i <= number; i++)
    {
        sum += i;
    }

    return sum;
}


void quiz1()
{
    int sum = sumTo(3);

    std::cout << "Sum: " << sum << std::endl;
}

int main()
{
    quiz1();

    return 0;
}

/*
 * 1) A function named sumTo() that takes an integer parameter and returns the sum of all the numbers between 1 and the input number.
 */