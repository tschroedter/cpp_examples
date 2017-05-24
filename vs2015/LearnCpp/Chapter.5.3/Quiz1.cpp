#include "stdafx.h"
#include <iostream>

int getNumber()
{
    std::cout << "Number: ";

    int number;
    std::cin >> number;

    return number;
}

char getOperation()
{
    std::cout << "Operation +, -, *, /, or %: ";

    char operation;
    std::cin >> operation;

    return operation;
}

int calculate(int one, int two, char operation)
{
    switch (operation)
    {
    case '+':
        return one + two;
    case '-':
        return one - two;
    case '*':
        return one * two;
    case '/':
        return one / two;
    case '%':
        return one % two;
    default:
        std::cout << "Unknown operation '" << operation << "'\n";
        return 0.0;
    }
}

void quiz1()
{
    int one = getNumber();
    int two = getNumber();
    char operation = getOperation();
    int result = calculate(one, two, operation);

    std::cout << "Result of " << one << " " << operation << " " << two << " = " << result;
}
/*
 * 1) Write a function called calculate() that takes two integers and a char representing 
 * one of the following mathematical operations: +, -, *, /, or % (modulus). Use a switch 
 * statement to perform the appropriate mathematical operation on the integers, and return 
 * the result. If an invalid operator is passed into the function, the function should print 
 * an error. For the division operator, do an integer division.
 */
