// Chapter.5.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
    int toNumber = 1;

    while(toNumber <=5)
    {
        int spaces = 0;

        while (spaces < 5-toNumber)
        {
            std::cout << "X";

            spaces++;
        }

        int currentNumber = 1;

        while(currentNumber <= toNumber)
        {
            std::cout << currentNumber;
            currentNumber++;
        }

        std::cout << "\n";

        toNumber++;
    }

    return 0;
}

/*
 * 4) Now make the numbers print like this:
        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1
hint: Figure out how to make it print like this first:
X X X X 1
X X X 2 1
X X 3 2 1
X 4 3 2 1
5 4 3 2 1
 */