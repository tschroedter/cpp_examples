// Chapter.11.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Base
{
private:
    int m_value;

public:
    Base(int value)
        : m_value(value)
    {
    }

    static void identify()
    {
       std::cout << "I am a Base\n";
    }

    friend std::ostream& operator<< (std::ostream &out, const Base &b)
    {
        out << "In Base\n";
        out << b.m_value << '\n';
        return out;
    }

    int getValue() const
    {
        return m_value;
    }

protected:
    void printValue() const
    {
        std::cout << m_value;
    }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }

    static void identify()
    {
        Base::identify();
        std::cout << "I am a Derived\n";
    }

    friend std::ostream& operator<< (std::ostream &out, const Derived &d)
    {
        out << "In Derived\n";
        out << static_cast<Base>(d);
        return out;
    }

    using Base::printValue;
};

int main()
{
    Derived derived5(5);

    std::cout << "derived has value " << derived5.getValue() << "\n";


    Base base5(5);
    base5.identify();

    Derived derived7(7);
    derived7.identify();

    std::cout << derived7;

    derived7.printValue();

    return 0;
}

