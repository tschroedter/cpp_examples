// Chpater.9.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }

    friend bool operator> (const Cents &c1, const Cents &c2);
    friend bool operator<= (const Cents &c1, const Cents &c2);

    friend bool operator< (const Cents &c1, const Cents &c2);
    friend bool operator>= (const Cents &c1, const Cents &c2);
};

bool operator> (const Cents &c1, const Cents &c2)
{
    return c1.m_cents > c2.m_cents;
}

bool operator>= (const Cents &c1, const Cents &c2)
{
    return c1.m_cents >= c2.m_cents;
}

// The logical opposite of < is >=, so we can do >= and invert the result
bool operator< (const Cents &c1, const Cents &c2)
{
    return !(c1 >= c2);
}

// The logical opposite of <= is >, so we can do > and invert the result
bool operator<= (const Cents &c1, const Cents &c2)
{
    return !(c1 > c2);
}

int main()
{
    Cents dime(10);
    Cents nickle(5);

    if (nickle > dime)
        std::cout << "a nickle is greater than a dime.\n";
    if (nickle >= dime)
        std::cout << "a nickle is greater than or equal to a dime.\n";
    if (nickle < dime)
        std::cout << "a dime is greater than a nickle.\n";
    if (nickle <= dime)
        std::cout << "a dime is greater than or equal to a nickle.\n";

    return 0;
}

/*
 * 1) For the Cents example above, rewrite operators < and <= in terms of other overloaded operators.
 */