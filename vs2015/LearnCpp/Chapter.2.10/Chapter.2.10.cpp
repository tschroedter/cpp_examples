// Chapter.2.10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "question4.h"

double calculate(
    double one,
    double two,
    char selectedOperator)
{
    if ('+' == selectedOperator)
    {
        return one + two;
    }
    if ('-' == selectedOperator)
    {
        return one - two;
    }
    if ('*' == selectedOperator)
    {
        return one * two;
    }
    if ('/' == selectedOperator)
    {
        return one / two;
    }

    return 0.0;
}

double getDouble()
{
    std::cout << "Enter a double value: ";
    double value = 0.0;
    std::cin >> value;

    return value;
}

char getOperator()
{
    std::cout << "Enter one of the following: +. -. *, or / ";
    char selectedOperator;
    std::cin >> selectedOperator;

    return selectedOperator;
}


void question3()
{
    double first = getDouble();
    double second = getDouble();
    char selectedOperator = getOperator();

    double result = calculate(
        first,
        second,
        selectedOperator);

    std::cout << first << " " << selectedOperator << " " << second << " is " << result;

    /*
    Question 3
        Write the following program : The user is asked to enter 2 floating point numbers(use doubles).The user is then asked to enter one of the following mathematical symbols : +, -, *, or / .The program computes the answer on the two numbers the user entered and prints the results.If the user enters an invalid symbol, the program should print nothing.
        Example of program :
        Enter a double value : 7
        Enter a second double value : 5
        Enter one of the following : +, -, *, or / : *
        7 * 5 is 35
    */
}


int main()
{
    //question3();

    question4();

    return 0;
}
