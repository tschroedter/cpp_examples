#include "stdafx.h"
#include <iostream>
#include <string>

enum class Animal
{
    Pig,
    Chicken,
    Goat,
    Cat,
    Dog,
    Ostrich
};

std::string getAnimalName(Animal animal)
{
    switch (animal)
    {
    case Animal::Pig:
        return "Pig";
    case Animal::Chicken:
        return "Chicken";
    case Animal::Goat:
        return "Goat";
    case Animal::Cat:
        return "Cat";
    case Animal::Dog:
        return "Dog";
    case Animal::Ostrich:
        return "Ostrich";
    default:
        return "Unknown Animal";
    }
}

std::string printNumberOfLegs(Animal animal)
{
    switch (animal)
    {
    case Animal::Pig:
        return "4";
    case Animal::Chicken:
        return "2";
    case Animal::Goat:
        return "4";
    case Animal::Cat:
        return "4";
    case Animal::Dog:
        return "4";
    case Animal::Ostrich:
        return "2";
    default:
        return "Unknown";
    }
}

void quiz2()
{
    std::cout << "A " << getAnimalName(Animal::Cat) << " has " << printNumberOfLegs(Animal::Cat) << " legs\n";
    std::cout << "A " << getAnimalName(Animal::Chicken) << " has " << printNumberOfLegs(Animal::Chicken) << " legs\n";
}
/*
 *2) Define an enum (or enum class, if using a C++11 capable compiler) named Animal that 
 *contains the following animals: pig, chicken, goat, cat, dog, ostrich. Write a function 
 *named getAnimalName() that takes an Animal parameter and uses a switch statement to return 
 *the name for that animal as a std::string. Write another function named printNumberOfLegs() 
 *that uses a switch statement to print the number of legs each animal walks on. Make sure both 
 *functions have a default case that prints an error message. Call printNumberOfLegs() from main() 
 *with a cat and a chicken. Your output should look like this:
 * A cat has 4 legs.
 * A chicken has 2 legs.
 */