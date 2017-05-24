#include "stdafx.h"
#include <iostream>

int add(int value1, int value2)
{
    return value1 + value2;
}

int subtract(int value1, int value2)
{
    return value1 - value2;
}

int multiply(int value1, int value2)
{
    return value1 * value2;
}

int divide(int value1, int value2)
{
    return value1 / value2;
}

int getNumber()
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

char getOperator()
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

typedef int(*arithmeticFcn)(int,int);

arithmeticFcn getArithmeticFunction(char function)
{
    switch (function)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    default:
        return divide;
    }
}

void quiz1()
{
    int value1 = getNumber();
    int value2 = getNumber();
    char functionChar = getOperator();

    arithmeticFcn function = getArithmeticFunction(functionChar);
    int result = function(value1, value2);

    std::cout << "Result: " << result << std::endl;
}

/*
 * 1) In this quiz, we’re going to write a version of our basic calculator using function pointers.
 * 1a) Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). 
 *     Ensure the user enters a valid operation.
 * 1b) Write functions named add(), subtract(), multiply(), and divide(). These should take two integer parameters and return an integer.
 * 1c) Create a typedef named arithmeticFcn for a pointer to a function that takes two integer parameters and returns an integer.
 * 1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.
 * 1e) Modify your main() function to call getArithmeticFunction(). Call the return value from that function with your inputs and print the result.
 */