#include "stdafx.h"
#include <iostream>
#include <cmath>

class Point;

class FixedPoint2
{
public:
    FixedPoint2(
        int16_t nonFractional = 0,
        int8_t fractional = 0)
        : m_base(nonFractional),
          m_decimal(fractional)
    {
        m_decimal = round(m_decimal);
    }

    FixedPoint2(
        double number)
    {
        fromDouble(number);
    }

    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& fixedPoint2);
    friend std::istream& operator>>(std::istream& in, FixedPoint2& fixedPoint2);
    friend FixedPoint2 operator+(const FixedPoint2& one, const FixedPoint2& two);
    friend bool operator==(const FixedPoint2& one, const FixedPoint2& two);
    FixedPoint2 operator-() const;

private:
    int16_t m_base;
    int8_t m_decimal;

    void fromDouble(double number);
};

void FixedPoint2::fromDouble(double number)
{
    m_base = static_cast<int16_t>(number);
    m_decimal = round((number - m_base) * 100);
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fixedPoint2)
{
    out << fixedPoint2.m_base << ".";

    // If our decimal is a single digit, we need to pad with a 0
    if (fixedPoint2.m_decimal < 10 && fixedPoint2.m_decimal > -10)
    {
        out << '0';
    }

    if (fixedPoint2.m_decimal >= 0)
    {
        out << static_cast<int>(fixedPoint2.m_decimal);
    }
    else
    {
        out << static_cast<int>(-fixedPoint2.m_decimal);
    }

    return out;
}

std::istream& operator >>(std::istream& in, FixedPoint2& fixedPoint2)
{
    double number;

    do {
        if (in.fail()) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        in >> number;
    } while (in.fail());

    fixedPoint2.fromDouble(number);

    return in;
}

FixedPoint2 operator+(const FixedPoint2& one, const FixedPoint2& two)
{
    int16_t base = one.m_base + two.m_base;
    int8_t decimal = static_cast<int8_t>(one.m_decimal + two.m_decimal);

    return FixedPoint2(base, decimal);
}

FixedPoint2 FixedPoint2::operator-() const
{
    return FixedPoint2(
        -m_base,
        -m_decimal);
}

bool operator==(const FixedPoint2& one, const FixedPoint2& two)
{
    return (one.m_base == two.m_base) && (one.m_decimal == two.m_decimal);
}

void testAddition()
{
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

void quiz4()
{
    FixedPoint2 a_quiz3(34, 56);
    std::cout << a_quiz3 << '\n';

    FixedPoint2 b_quiz3(9.617); // any decimal digits beyond 2 should be rounded to 2 decimals
    std::cout << b_quiz3 << '\n';

    FixedPoint2 c_quiz3(5.01); // stored as 5.0099999... so we'll need to round this
    std::cout << c_quiz3 << '\n';

    FixedPoint2 d_quiz3(-5.01); // stored as -5.0099999... so we'll need to round this
    std::cout << d_quiz3 << '\n';

    testAddition();

    FixedPoint2 a(34, 56);
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';
}

/*
 * 4) Extra credit: This one is a little more tricky. A floating point number is a number with a decimal 
 *    where the number of digits after the decimal can be variable. A fixed point number is a number with 
 *    a fractional component where the number of digits in the fractional portion is fixed.
 *    
 *    In this quiz, we're going to write a class to implement a fixed point number with two fractional 
 *    digits (e.g. 12.34, 3.00, or 1278.99). Assume that the range of the class should be -32768.99 to 32767.99, 
 *    that the fractional component should hold any two digits, that we don't want precision errors, and that we 
 *    want to conserve space.
 *    
 *    4a) What type of member variable(s) do you think we should use to implement our fixed point number with 2 
 *    digits after the decimal? (Make sure you read the answer before proceeding with the next questions)
 *    
 *    4b) Write a class named FixedPoint2 that implements the recommended solution from the previous question. 
 *    Provide the overloaded operators and constructors required for the following program to run:
 *    
 *    4c) Overload operators >>, - (unary), + (binary) and the cast to double. todo
 */
