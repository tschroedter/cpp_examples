// Chapter.4.4a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

std::string getFullname()
{
    std::cout << "Enter your full name: ";
    std::string fullname;
    std::getline(std::cin, fullname);

    return fullname;
}

int getAge()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    std::cin.ignore(32767, '\n');

    return age;
}

float calculate(std::string fullname, int age)
{
    return static_cast<float>(age) / fullname.length();
}

int main()
{
    std::string fullname = getFullname();
    int age = getAge();
    float years = calculate(fullname, age);

    std::cout << "You've lived " << years << " years for each letter in your name.";

    return 0;
}


/*
*
*/
