// Chapter.6.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace Animals
{
    enum AnimalTypes
    {
        Chicken,
        Dog,
        Cat,
        Elephant,
        Duck,
        Snake
    };
}

int main()
{
    double highTemperature[365]{0.0};

    int legs[6]{ 0 };

    legs[Animals::Chicken] = 2;
    legs[Animals::Dog] = 4;
    legs[Animals::Cat] = 4;
    legs[Animals::Elephant] = 4;
    legs[Animals::Duck] = 2;
    legs[Animals::Snake] = 0;

    std::cout << "An elephant has " << legs[Animals::Elephant] << " legs.\n";

    return 0;
}
/*
 * 1) Declare an array to hold the high temperature (to the nearest tenth of a degree) for 
 * each day of a year (assume 365 days in a year). Initialize the array with a value of 0.0 for each day.
 * 
 * 2) Set up an enum with the names of the following animals: chicken, dog, cat, elephant, duck, and snake. 
 * Put the enum in a namespace. Define an array with an element for each of these animals, and use an 
 * initializer list to initialize each element to hold the number of legs that animal has.
 * Write a main function that prints the number of legs an elephant has, using the enumerator.
 */



