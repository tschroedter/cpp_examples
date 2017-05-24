// Chapter.6.12a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

std::string getName()
{
    std::string name;

    do {
        std::cout << "Enter a name? ";
        std::cin >> name;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
    } while (name.length() == 0);

    return name;
}

int main()
{
    const std::string names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::string name = getName();

    bool isInNames(false);

    for(const auto currentName : names)
    {
        if (currentName == name)
        {
            isInNames = true;
            break;
        }
    }

    if (isInNames)
    {
        std::cout << name << " was found.\n";
    }
    else
    {
        std::cout << name << " was not found.\n";
    }

    return 0;
}

/*
 * Quiz
 * This one should be easy.
 * 1) Declare a fixed array with the following names: Alex, Betty, Caroline, Dave, Emily, Fred, Greg, and Holly. Ask the user to enter a name. Use a for each loop to see if the name the user entered is in the array.
 * Sample output:
 * Enter a name: Betty
 * Betty was found.
 * Enter a name: Megatron
 * Megatron was not found.
 * Hint: Use std::string as your array type.
 */