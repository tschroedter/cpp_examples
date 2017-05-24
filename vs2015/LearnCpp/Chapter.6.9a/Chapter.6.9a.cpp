// Chapter.6.9a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int getNumber()
{
    int number;

    do
    {
        std::cout << "How many names would you like to enter? ";
        std::cin >> number;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
    } while (number < 1 );

    return number;
}


std::string getName(int number)
{
    std::string name;

    do
    {
        std::cout << "Enter name #" << number << "? ";
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

void getNames(int numberOfNames, std::string* names)
{
    for(int i=0; i < numberOfNames; i++)
    {
        names[i] = getName(i+1);
    }
}

void printNames(int numberOfNames, std::string* names)
{
    for (int i = 0; i < numberOfNames; i++)
    {
        std::cout << "Name #" << (i+1) << " " << names[i] << "\n";
    }
}

void sortNames(int numberOfNames, std::string* names)
{
    bool hasSwapHappened;
    int iteration = 0;
    do
    {
        hasSwapHappened = false;
        iteration++;

        for (int i = 0; i < numberOfNames - iteration; i++)
        {
            if (names[i] > names[i + 1])
            {
                std::swap(names[i], names[i + 1]);

                hasSwapHappened = true;
            }
        }
    } while (hasSwapHappened);
}

int main()
{
    int numberOfNames = getNumber();

    std::string *names = new std::string[numberOfNames];

    getNames(numberOfNames, names);

    sortNames(numberOfNames, names);

    std::cout << "\nHere is your sorted list:\n";

    printNames(numberOfNames, names);

    delete[] names;
    
    names = nullptr;

    return 0;
}

/*
 * Quiz
 * 1) Write a program that:
* Asks the user how many names they wish to enter.
* Asks the user to enter each name.
* Calls a function to sort the names (modify the selection sort code from lesson 6.4 -- Sorting an array using selection sort)
* Prints the sorted list of names.
* Hint: Use a dynamic array of std::string to hold the names.
* Hint: std::string supports comparing strings via the comparison operators < and >
* Your output should match this:
* How many names would you like to enter? 5
* Enter name #1: Jason
* Enter name #2: Mark
* Enter name #3: Alex
* Enter name #4: Chris
* Enter name #5: John
*
* Here is your sorted list:
* Name #1: Alex
* Name #2: Chris
* Name #3: Jason
* Name #4: John
* Name #5: Mark
*/

