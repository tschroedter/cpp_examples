#include "stdafx.h"
#include <iostream>

void swap(int &one, int &two)
{
    int temp = one;
    one = two;
    two = temp;
}

void quiz3()
{
    int one = 1;
    int two = 2;

    std::cout << "one: " << one << " two: " << two << std::endl;;

    swap(one, two);

    std::cout << "one: " << one << " two: " << two << std::endl;;
}
/*
 * 3) Write your own function to swap the value of two integer variables. Write a main() function to test it.
 * Hint: Use reference parameters
 */