#include "stdafx.h"
#include "io.h"

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int number1 = readNumber();
    int number2 = readNumber();
    int sum = add(number1, number2);

    writeAnswer(sum);

    return 0;
}