// Chapter.6.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getNumber()
{
    int number;

    do
    {
        std::cout << "Enter a number (1-9): ";
        std::cin >> number;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
    } while (number < 1 || number > 9);
    
    return number;
}

void displayArray(const int arrayLength, int array[9])
{
    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << "[" << i << "] " << array[i] << "\n";
    }
}

void quiz3()
{
    /*
    * 3) Modify the following program so that instead of having maxScore hold the largest score directly,
    * a variable named maxIndex holds the index of the largest score.
    */

    int scores[] = { 84, 92, 76, 81, 56 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);

    int maxScore = 0; // keep track of our largest score
    int maxScoreIndex = 0;

    for (int student = 0; student < numStudents; ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
            maxScoreIndex = student;
        }
    }

    std::cout << "The best score was " << maxScore << " at index " << maxScoreIndex << '\n';
}

int main()
{
    // 1) Print the following array to the screen using a loop :
    const int arrayLength(9);
    int array[arrayLength] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    displayArray(arrayLength, array);

    /*2) Given the array in question 1:
     *Ask the user for a number between 1 and 9. If the user does not enter a number between 1 and 9, 
     *repeatedly ask for a number until they do.Once they have entered a number between 1 and 9, 
     *print the array.Then search the array for the number that the user entered and print the 
     *index of that element.
     */

    int number = getNumber();
    displayArray(arrayLength, array);

    quiz3();

    return 0;
}

