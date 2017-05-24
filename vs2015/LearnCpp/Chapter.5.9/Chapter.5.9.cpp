// Chapter.5.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

unsigned int PRNG()
{
    static unsigned int seed = 5323;
    seed = (8253729 * seed + 2396403);

    return seed % 32768;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // static used for efficiency, so we only calculate this value once
                                                                                // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int main()
{
    for (int i=0; i < 100; i++)
    {
        std::cout << PRNG() << "\t";

        if ( (i+1)%5 == 0 )
        {
            std::cout << "\n";
        }
    }

    std::cout << "\n\n";

    // using build in random number generator
    srand(5323); // set initial seed value to 5323

    // Print 100 random numbers
    for (int count = 0; count < 100; ++count)
    {
        std::cout << rand() << "\t";

        // If we've printed 5 numbers, start a new row
        if ((count + 1) % 5 == 0)
            std::cout << "\n";
    }

    std::cout << "\n\n";

    // using build in random number generator
    srand(static_cast<int>(time(0))); 

                 // Print 100 random numbers
    for (int count = 0; count < 100; ++count)
    {
        std::cout << getRandomNumber(1,10) << "\t";

        // If we've printed 5 numbers, start a new row
        if ((count + 1) % 5 == 0)
            std::cout << "\n";
    }
    return 0;
}

