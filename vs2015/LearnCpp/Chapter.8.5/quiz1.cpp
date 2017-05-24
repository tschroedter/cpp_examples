#include "stdafx.h"
#include <string>
#include <iostream>

class Ball
{
public:
    Ball(double radius)
    {
        m_color = "black";
        m_radius = radius;
    }

    Ball(std::string const &color = "black",
        double radius = 10.0)
    {
        m_color = color;
        m_radius = radius;
    }

    void print() const
    {
        std::cout << "color : " << m_color << ", radius : " << m_radius << std::endl;
    };

private:
    std::string m_color;
    double m_radius;
};

void quiz1()
{
    Ball def;
    def.print();

    Ball blue("blue");
    blue.print();

    Ball twenty(20.0);
    twenty.print();

    Ball blueTwenty("blue", 20.0);
    blueTwenty.print();
}

/*
 * 1) Write a class named Ball. Ball should have two private member variables with default values: 
 *    m_color (“Black”) and m_radius (10.0). Ball should provide constructors to set only m_color, 
 *    set only m_radius, set both, or set neither value. For this quiz question, do not use default 
 *    parameters for your constructors. Also write a function to print out the color and radius of the ball.
 */
