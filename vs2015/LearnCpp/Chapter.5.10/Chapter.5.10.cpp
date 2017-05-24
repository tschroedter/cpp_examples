#include "stdafx.h"
#include <iostream>

double getDouble()
{
    while (true)
    {
        std::cout << "Enter a double value: ";
        double x;
        std::cin >> x;

        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767, '\n'); // and remove the bad input
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // and remove the bad input
            return x;
        }
    }
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

void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
    double x = getDouble();
    char op = getOperator();
    double y = getDouble();

    printResult(x, op, y);

    return 0;
}

