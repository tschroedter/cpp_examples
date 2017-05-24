#include "stdafx.h"
#include <iostream>

class Fraction
{
public:
    Fraction(
        int numerator = 0,
        int denominator = 1)
        : m_Numerator(numerator),
        m_Denominator(denominator)
    {
        reduce();
    }

    void print() const;

    friend Fraction operator*(const Fraction &first, const Fraction &second);
    friend Fraction operator*(const Fraction &f1, int value);
    friend Fraction operator*(int value, const Fraction &f1);

private:
    int m_Numerator;
    int m_Denominator;
    int gcd(int a, int b) const;
    
    void reduce();
};

void Fraction::print() const
{
    std::cout << m_Numerator << "/" << m_Denominator << "\n";
}

int Fraction::gcd(int a, int b) const
{
    return b == 0 ? a : gcd(b, a % b);
}

void Fraction::reduce()
{
    int divisor = gcd(m_Numerator, m_Denominator);

    m_Numerator = m_Numerator / divisor;
    m_Denominator = m_Denominator / divisor;
}

Fraction operator*(Fraction const &first, Fraction const &second)
{
    int numerator = first.m_Numerator * second.m_Numerator;
    int denominator = first.m_Denominator * second.m_Denominator;

    return Fraction(
        numerator,
        denominator);
}

Fraction operator*(Fraction const &first, int second)
{
    int numerator = first.m_Numerator * second;
    int denominator = first.m_Denominator;

    return Fraction(
        numerator,
        denominator);
}

Fraction operator*(int first, Fraction const &second)
{
    int numerator = first * second.m_Numerator;
    int denominator = second.m_Denominator;

    return Fraction(
        numerator,
        denominator);
}

void quiz1()
{
    Fraction f1(2, 5);
    f1.print();

    Fraction f2(3, 8);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 2;
    f4.print();

    Fraction f5 = 2 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
}
/*
 * 1a) Write a class named Fraction that has a integer numerator and denominator member. 
 * Write a print() function that prints out the fraction.
 * 
 * 1b) Add overloaded multiplication operators to handle multiplication between a Fraction and integer, 
 * and between two Fractions. Use the friend function method.
 * 
 * Hint: To multiply two fractions, fist multiply the two numerators together, and then multiply the 
 * two denominators together. To multiply a fraction and an integer, multiply the numerator of the 
 * fraction by the integer and leave the denominator alone.
 * 
 * 1c) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. 
 * We can reduce any given fraction to lowest terms by finding the greatest common divisor (GCD) between 
 * the numerator and denominator, and then dividing both the numerator and denominator by the GCD.
 * The following is a function to find the GCD:
 * 
 * int gcd(int a, int b) {
 *  return b == 0 ? a : gcd(b, a % b);
 * }
 * 
 * Add this function to your class, and write a member function named reduce() that reduces your fraction. 
 * Make sure all fractions are properly reduced.
 */