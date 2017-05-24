#include "stdafx.h"
#include <iostream>
#include <cassert>

class IntArray
{
public:
    IntArray(int size)
        : m_size(size)
    {
        m_array = new int[size];
    }

    IntArray(const IntArray &intArray)
    {
        resize(intArray);
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    int& operator[] (const int index);
    const int& operator[] (const int index) const;
    IntArray& IntArray::operator= (const IntArray &intArray);
    friend std::ostream& operator<<(std::ostream& out, const IntArray& intArray);

    void resize(const IntArray& intArray);
    void copyToInternalArray(const IntArray& intArray) const;

private:
    int m_size;
    int *m_array;
};

void IntArray::resize(const IntArray& intArray)
{
    delete[] m_array;
    m_size = intArray.m_size;
    m_array = new int[intArray.m_size];
    copyToInternalArray(intArray);
}

void IntArray::copyToInternalArray(const IntArray& intArray) const
{
    for (int i = 0; i < intArray.m_size; i++)
    {
        m_array[i] = intArray.m_array[i];
    }
}

IntArray& IntArray::operator= (const IntArray &intArray)
{
    // self-assignment guard
    if (this == &intArray)
        return *this;

    resize(intArray);

    // return the existing object so we can chain this operator
    return *this;
}

int& IntArray::operator[] (const int index) // for non-const objects: can be used for assignment
{
    assert(index >= 0 && index < m_size);

    return m_array[index];
}

const int& IntArray::operator[] (const int index) const // for const objects: can only be used for access
{
    assert(index >= 0 && index < m_size);

    return m_array[index];
}

std::ostream& operator<<(std::ostream& out, const IntArray& intArray)
{
    for(int i=0; i<intArray.m_size; i++)
    {
        out << intArray.m_array[i] << " ";
    }

    return out;
}

IntArray fillArray()
{
    IntArray a(5);
    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

void quiz3()
{

    IntArray a = fillArray();
    std::cout << a << '\n';

    IntArray b(1);
    a = a;
    b = a;

    std::cout << b << '\n';
}

/*
 * 3) Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). 
 *    Users should pass in the size of the array when it is created, and the array should be dynamically 
 *    allocated. Use assert statements to guard against bad data. Create any constructors or overloaded 
 *    operators needed to make the following program operate correctly:
 */