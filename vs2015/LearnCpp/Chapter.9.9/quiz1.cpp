#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Mystring
{
public:
    Mystring(std::string string)
        : m_string(string)
    {
    }

    std::string operator() (
        int startindex,
        int size)
    {
        std::string substring{};

        int stopIndex = startindex + size;

        for (int i = startindex; i < stopIndex; i++)
        {
            substring += m_string[i];
        }
        
        return substring;
    }

private:
    std::string m_string = 0;
};

void quiz1()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 5); // start at index 7 and return 5 characters
}
/*
 * 1) Write a class that holds a string. Overload operator() to return the substring that starts 
 *    at the index of the first parameter, and includes however many characters are in the second parameter.
 *    
 *    Hint: You can use array indices to access individual chars within the std::string
 *    Hint: You can use operator+= to append something to a string
 */