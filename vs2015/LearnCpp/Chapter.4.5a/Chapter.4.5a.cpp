// Chapter.4.5a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
    enum class Color
    {
        RED,
        BLUE
    };

    enum class Fruit
    {
        BANNANA,
        APPLE
    };

    Color color = Color::RED;
    Fruit fruit = Fruit::BANNANA;

//    if (color == fruit)
//    {
//        std::cout << "color and fruit are equal\n";
//    }
//    else
//    {
//        std::cout << "color and fruit are not equal\n";
//    }
    return 0;
}

