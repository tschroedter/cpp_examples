#include "stdafx.h"
#include <iostream>

class Average
{
public:
    Average(
        int sum = 0,
        int count = 0)
        : m_Sum(sum),
          m_Count(count)
    {
    }

    Average& operator+=(int number)
    {
        m_Sum += number;
        m_Count++;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Average& average);

private:
    int32_t m_Sum;
    int8_t m_Count;
};

std::ostream& operator<<(std::ostream& out, const Average& average)
{
    double result = static_cast<double>(average.m_Sum) / average.m_Count;
    out << result;
    return out;
}

void quiz2()
{
    Average avg;

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy = avg;
    std::cout << copy << '\n';
}

/*
 * 2) Write a class named Average that will keep track of the average of all integers passed to it. 
 *    Use two members: The first one should be type int32_t, and used to keep track of the sum of all 
 *    the numbers you’ve seen so far. The second should be of type int8_t, and used to keep track of 
 *    how many numbers you’ve seen so far. You can divide them to find your average.
 *    
 * 2a) Write all of the functions necessary for the following program to run:
 */
