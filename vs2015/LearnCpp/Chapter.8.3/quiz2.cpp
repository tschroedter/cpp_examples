#include "stdafx.h"
#include <iostream>

class Point3d
{
public:
    void setValues(double x,
        double y,
            double z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    void print()
    {
        std::cout
            << "<"
            << X
            << ", "
            << Y
            << ", "
            << Z
            << ">"
            << std::endl;
    }

private:
    double X;
    double Y;
    double Z;


};

void quiz2()
{
    Point3d point;
    point.setValues(1.0, 2.0, 3.0);

    point.print();
}

/*
 * 2) Write a simple class named Point3d. The class should contain:
 *    Three private member variables of type double named m_x, m_y, and m_z;
 *    A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
 *    A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>
 */