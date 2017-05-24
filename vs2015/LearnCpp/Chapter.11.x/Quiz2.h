#pragma once
#include <string>
#include <iostream>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;
protected:
public:
    Fruit(
        std::string name,
        std::string color)
        : m_name(name), m_color(color)
    {
    }

    std::string getName() const
    {
        return m_name;
    }

    std::string getColor() const
    {
        return m_color;
    }
};

class Apple : public Fruit
{
public:
    Apple(
        std::string color = "green")
        :Fruit("apple", color)
    {
    }
    Apple(
        std::string name,
        std::string color)
        :Fruit(name, color)
    {
    }
};

class Banana : public Fruit
{
public:
    Banana(
        std::string color = "yellow")
        :Fruit("banana", color)
    {
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        : Apple(
            "granny smith apple",
            "green")
    {
    }
};

inline int quiz2()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
