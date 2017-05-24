
#include "stdafx.h"
#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};

int getIntegerForFraction()
{
    int value = 0;
    std::cin >> value;
    std::cin.ignore(32767, '\n');

    return value;
}

Fraction getFraction()
{
    std::cout << "Numerator  : ";
    int numerator = getIntegerForFraction();

    std::cout << "Denominator: ";
    int denominator = getIntegerForFraction();

    return Fraction{ numerator, denominator };
}

Fraction multiplyFraction(Fraction one, Fraction two)
{
    int numerator = one.numerator * two.numerator;
    int denominator = one.denominator * two.denominator;

    return Fraction{ numerator, denominator };
}

void printFraction(Fraction fraction)
{
    std::cout << "Numerator  : " << fraction.numerator << "\n";
    std::cout << "Denominator: " << fraction.denominator << "\n";

    float decimal = static_cast<float>(fraction.numerator) / static_cast<float>(fraction.denominator);
    std::cout << "Decimal    : " << decimal;
}

void FractionTest()
{
    Fraction one = getFraction();
    Fraction two = getFraction();

    Fraction three = multiplyFraction(one, two);

    printFraction(three);
}
/*
 * Create a struct to hold a fraction. The struct should have an integer numerator and 
 * an integer denominator member. Declare 2 fraction variables and read them in from the user. 
 * Write a function called multiply that takes both fractions, multiplies them together, and 
 * prints the result out as a decimal number. You do not need to reduce the fraction to its 
 * lowest terms.
 */