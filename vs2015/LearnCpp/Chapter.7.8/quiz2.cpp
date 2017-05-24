#include "stdafx.h"
#include <iostream>

int quiz2Add(int value1, int value2)
{
    return value1 + value2;
}

int quiz2Subtract(int value1, int value2)
{
    return value1 - value2;
}

int quiz2Multiply(int value1, int value2)
{
    return value1 * value2;
}

int quiz2Divide(int value1, int value2)
{
    return value1 / value2;
}

int getNumberChapter_7_8()
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

char quiz2GetOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op;
        std::cin >> op;

        // Check whether the user entered meaningful input
        if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            return op; // return it to the caller
        }
        else // otherwise tell the user what went wrong
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

typedef int(*arithmeticFcn)(int, int);

struct arithmeticStruct
{
    char mathematicalOperator;
    arithmeticFcn function;
};

static arithmeticStruct arithmeticArray[]
{
    { '+', quiz2Add },
    { '-', quiz2Subtract },
    { '*', quiz2Multiply },
    { '/', quiz2Divide }
};

arithmeticFcn quiz2GetArithmeticFunction(char function)
{
    for (arithmeticStruct arithmetic : arithmeticArray)
    {
        if (arithmetic.mathematicalOperator == function)
        {
            return arithmetic.function;
        }
    }

    return quiz2Add;    // todo default, better throw exception
}

void quiz2()
{
    int value1 = getNumberChapter_7_8();
    int value2 = getNumberChapter_7_8();
    char functionChar = quiz2GetOperator();

    arithmeticFcn function = quiz2GetArithmeticFunction(functionChar);
    int result = function(value1, value2);

    std::cout << "Result: " << result << std::endl;
}

/*
 * 2) Now let’s modify the program we wrote in quiz 1 to move the logic out of the getArithmeticFcn and into an array.
 * 2a) Create a struct named arithmeticStruct that has two members: a mathematical operator char, and an arithmeticFcn function pointer.
 * 2b) Create a static global array of arithmeticStruct named arithmeticArray, initialized with each of the four arithmetic functions.
 * 2c) Modify getArithmeticFcn to loop through the array and return the appropriate function pointer.
 */