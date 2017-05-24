#include "stdafx.h"
#include <iostream>
#include <cassert>

using namespace std;

class Stack
{
public:
    void reset()
    {
        for (int i =0; i < StackCapacity; i++)
        {
            stack[i] = 0;
        };

        nextEmptySlot = 0;
    };

    void print()
    {
        for (int i = 0; i < StackCapacity; i++)
        {
            std::cout << stack[i] << " ";
        };

        std::cout << "\n";
    };

    bool push(int number)
    {
        if (nextEmptySlot >= StackCapacity)
        {
            return false;
        }

        stack[nextEmptySlot++] = number;

        return true;
    };

    int pop()
    {
        assert(nextEmptySlot >= 0);

        nextEmptySlot--;

        int headValue = stack[nextEmptySlot];

        stack[nextEmptySlot] = 0;

        return headValue;
    };

private:
    static int const StackCapacity = 10;
    int stack[StackCapacity] {};
    int nextEmptySlot = 0;
};

void quiz3() {
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();
}

/*
* 3) Now let’s try something a little more complex. Let’s write a class that implements a simple stack from scratch. Review lesson 7.9 -- The stack and the heap if you need a refresher on a what a stack is.
* The class should be named Stack, and should contain:
* A private fixed array of integers of length 10.
* A private integer to keep track of the length of the stack.
* A public member function named reset() that sets the length to 0 and all of the element values to 0.
* A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
* A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, it should assert out.
* A public member function named print() that prints all the values in the stack.
*/