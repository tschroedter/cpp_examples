#include "stdafx.h"
#include <iostream>

void quiz2()
{
    const int length = 5;
    int array[length] = { 30, 50, 20, 10, 40 };

    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            /*
            * 2) Rewrite the selection sort code above to sort in descending order(largest numbers first).
            * Although this may seem complex, it is actually surprisingly simple.
            */
            if (array[currentIndex] > array[smallestIndex])
            {
                smallestIndex = currentIndex;
            }
        }

        std::swap(array[startIndex], array[smallestIndex]);
    }

    for (int index = 0; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }
}