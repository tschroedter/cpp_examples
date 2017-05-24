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
    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    friend std::istream& operator >> (std::istream &in, Fraction &fraction);

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

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
    out << fraction.m_Numerator << "/" << fraction.m_Denominator;

    return out;
}

std::istream& operator >> (std::istream &in, Fraction &fraction)
{
    char c;
    in >> fraction.m_Numerator;
    in >> c; // ignore the '/' separator
    in >> fraction.m_Denominator;

    return in;
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
    Fraction f1;
    std::cout << "Enter fraction 1 (a/b): ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2 (a/b): ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
}

/*
* Take the Fraction class we wrote in the previous quiz (listed below) and add an overloaded operator<< and operator>> to it.
*/