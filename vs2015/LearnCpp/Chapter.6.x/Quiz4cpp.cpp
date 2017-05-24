#include "stdafx.h"
#include <iostream>

void do_work(const char* pText)
{
    while(*pText != 0)
    {
        std::cout << *pText;

        pText++;
    }
}

void quiz4()
{
    char text[] = "Hello World!";

    do_work(text);
}

/*
 * 4) Write a function to print a C-style string character by character. Use a pointer to step through 
 * each character of the string and print that character. Stop when you hit a null terminator. Write a 
 * main function that tests the function with the string literal “Hello, world!”.
 * 
 * Hint: Use operator++ to advance the pointer to the next character
 */