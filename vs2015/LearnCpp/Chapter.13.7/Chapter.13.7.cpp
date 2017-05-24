// Chapter.13.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
#include <string>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
    // The expression parameter controls the size of the array
    T m_array[size];

public:
    T* getArray ()
    {
        return m_array;
    }

    T& operator[] ( int index )
    {
        return m_array [ index ];
    }
};

template <typename T, int size>
void print ( StaticArray<T, size>& array )
{
    for ( int count = 0 ; count < size ; ++count )
        std::cout << array [ count ] << ' ';
}

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print ( StaticArray<char, 14>& array )
{
    for ( int count = 0 ; count < 14 ; ++count )
        std::cout << array [ count ];
}

template <class T>
class Pair1
{
    T m_first;
    T m_second;
public:
    Pair1 ( T one,
            T two )
        : m_first ( one )
        , m_second ( two )
    {
    }

    T& first()
    {
        return m_first;
    }

    T& second()
    {
        return m_second;
    }

    const T& first() const
    {
        return m_first;
    }

    const T& second() const
    {
        return m_second;
    }
};

template <class TFirst, class TSecond>
class Pair
{
    TFirst m_first;
    TSecond m_second;
public:
    Pair(TFirst one,
         TSecond two)
        : m_first(one)
        , m_second(two)
    {
    }

    TFirst& first()
    {
        return m_first;
    }

    TSecond& second()
    {
        return m_second;
    }

    const TFirst& first() const
    {
        return m_first;
    }

    const TSecond& second() const
    {
        return m_second;
    }
};

template <class T>
class StringValuePair
    : public Pair<std::string, T>
{
public:
    StringValuePair ( 
        const std::basic_string<char>& one, 
        const T& two )
        : Pair<std::basic_string<char>, T> ( one, two )
    {
    }
/*
    friend std::ostream& operator<< (std::ostream &out, const Derived &d)
    {
        out << "In Derived\n";
        out << static_cast<Base>(d);
        return out;
    }
    */
};

int main ()
{
    // declare an int array
    StaticArray<int, 4> int4;
    int4 [ 0 ] = 0;
    int4 [ 1 ] = 1;
    int4 [ 2 ] = 2;
    int4 [ 3 ] = 3;

    // Print the array
    print ( int4 );

    // declare an char array
    StaticArray<char, 14> char14;

    strcpy_s ( char14.getArray(), 14, "Hello, world!" );

    // Print the array
    print ( char14 );

    // --- 13.x

    Pair1<int> p1 ( 5, 8 );
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2 ( 2.3, 4.5 );
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    // --- 
    Pair<int, double> pp1(5, 6.7);
    std::cout << "Pair: " << pp1.first() << ' ' << pp1.second() << '\n';

    const Pair<double, int> pp2(2.3, 4);
    std::cout << "Pair: " << pp2.first() << ' ' << pp2.second() << '\n';

    // --- 
    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
