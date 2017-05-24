#include "stdafx.h"
#include "iostream"

void doPrint()
{
    std::cout << "In doPrint()" << std::endl;
}

void returnNothing()
{
}

int return5()
{
    return 5;
}

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;

    return a;
}

void printA()
{
    std::cout << "A" << std::endl;
}

void printB()
{
    std::cout << "B" << std::endl;
}

void printAB()
{
    printA();
    printB();
}

int main()
{
    std::cout << "Starting main()" << std::endl;
    doPrint();
    std::cout << "Ending main()" << std::endl;

    std::cout << return5() << std::endl;
    std::cout << return5() + 2 << std::endl;

    returnNothing();

    // ---
    int x = getValueFromUser();
    int y = getValueFromUser();

    std::cout << x << " + " << y << " = " << x + y << std::endl;
    // ---

    std::cout << "Starting main()" << std::endl;
    printAB();
    std::cout << "Starting main()" << std::endl;

    return 0;
}