// Chapter.13.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <typename T>
const T& max (
    const T& x,
    const T& y )
{
    return ( x > y ) ? x : y;
}

template <class T>
T average ( T* array, int length )
{
    T sum = 0;
    for ( int count = 0 ; count < length ; ++count )
        sum += array [ count ];

    sum /= length;
    return sum;
}

class Cents
{
private:
    int m_cents;
public:
    Cents ( int cents )
        : m_cents ( cents )
    {
    }

    friend bool operator> ( const Cents& c1, const Cents& c2 )
    {
        return ( c1.m_cents > c2.m_cents );
    }

    friend std::ostream& operator<< ( std::ostream& out, const Cents& c )
    {
        out << "Cents " << c.m_cents;
        return out;
    }

    void operator+= ( Cents cents )
    {
        m_cents += cents.m_cents;
    }

    void operator/= ( int value )
    {
        m_cents /= value;
    }
};

int main ()
{
    int i = max ( 3, 7 );
    std::cout << i << '\n';

    double d = max ( 6.34, 18.523 );
    std::cout << d << '\n';

    char c = max ( 'a', '6' );
    std::cout << c << '\n';

    Cents nickle ( 5 );
    Cents dime ( 10 );

    Cents bigger = max ( nickle, dime );
    std::cout << bigger << '\n';

    int array1[] = { 5, 3, 2, 1, 4 };
    std::cout << average ( array1, 5 ) << '\n';

    double array2[] = { 3.12, 3.45, 9.23, 6.34 };
    std::cout << average ( array2, 4 ) << '\n';

    Cents array3[] = { Cents ( 5 ), Cents ( 10 ), Cents ( 15 ), Cents ( 14 ) };
    std::cout << average ( array3, 4 ) << '\n';

    return 0;
}
