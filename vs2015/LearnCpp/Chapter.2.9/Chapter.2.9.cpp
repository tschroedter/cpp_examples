// Chapter.2.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    const int usersAge{ age }; // usersAge can not be changed

    return 0;
}

