#include "stdafx.h"
#include <iostream>

class Point2d
{
private:
    double m_X;
    double m_Y;

public:
    Point2d(double x = 0.0,
            double y = 0.0)
        : m_X(x), m_Y(y)
    {
    }

    void print() const
    {
        std::cout << "Point2d(" << m_X << ", " << m_Y << ")\n";
    }

    friend double distanceFrom(Point2d const &first, Point2d const &second);
};

double distanceFrom(Point2d const &first, Point2d const &second)
{
    double x1MinusX2 = first.m_X - second.m_X;
    double y1MinusY2 = first.m_Y - second.m_Y;

    double distance = sqrt(x1MinusX2 * x1MinusX2 + y1MinusY2 * y1MinusY2);

    return distance;
}

void quiz1()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();

    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}

/*
 * 1a) Write a class named Point2d. Point2d should contain two member variables of type double: 
 *     m_x, and m_y, both defaulted to 0.0. Provide a constructor and a print function.
 *     
 * 1b) Now add a member function named distanceTo that takes another Point2d as a parameter, and 
 *     calculates the distance between them. Given two points (x1, y1) and (x2, y2), the distance 
 *     between them can be calculated as sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). 
 *     The sqrt function lives in header cmath.
 */
