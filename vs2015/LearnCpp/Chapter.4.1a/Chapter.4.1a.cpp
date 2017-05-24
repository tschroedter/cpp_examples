// Chapter.4.1a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getInteger()
{
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    return number;
}

int main()
{
    int smaller = getInteger();
    int larger = getInteger();

    if (smaller > larger)
    {
        std::cout << "Swapping values" << std::endl;

        int help = larger;
        larger = smaller;
        smaller = help;
    }

    std::cout << "The smaller value is " << smaller << std::endl;
    std::cout << "The larger value is " << larger << std::endl;

    return 0;
}

