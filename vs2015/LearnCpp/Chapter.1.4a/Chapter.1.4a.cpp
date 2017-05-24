#include "stdafx.h"
#include "iostream"

void doPrint()
{
    std::cout << "In doPrint()" << std::endl;
}

void printValue(int x)
{
    std::cout << x << std::endl;
}

int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

void printValues(int x, int y)
{
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

int doubleNumber(int x)
{
    return x * 2;
}

int main()
{
    printValues(6, 7);

    using namespace std;

    cout << add(4, 5) << endl;

    cout << multiply(4, 5) << endl;

    cout << add(1 + 2, 3 * 4) << endl; // within add(), x=3, y=12, so x+y=15

    // We can pass the value of variables
    int a = 5;
    cout << add(a, a) << endl; // evaluates (5 + 5)

    cout << add(1, multiply(2, 3)) << endl; // evaluates 1 + (2 * 3)
    cout << add(1, add(2, 3)) << endl; // evaluates 1 + (2 + 3)

    // ---
    int number;
    cout << "Input an integer: ";
    cin >> number;
    cout << "Double: " << doubleNumber(number) << endl;

    return 0;
}


