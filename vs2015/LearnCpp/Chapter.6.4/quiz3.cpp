#include "stdafx.h"
#include <iostream>

void quiz3()
{
    const int length(9);
    int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    bool hasSwapHappened;

    do
    {
        hasSwapHappened = false;

        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i+1])
            {
                std::swap(array[i], array[i+1]);

                hasSwapHappened = true;
            }
        }
    } while (hasSwapHappened);

    for (int index = 0; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }

    /*
     * Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
     * A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
     * B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the 
     *    end of the array. At this point, the last element in the array will be sorted.
     * C) Repeat the first two steps again until the array is sorted.
     */
}