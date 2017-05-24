// Chapter.10.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "IntArray.h"

int main()
{
   // Declare an array with 10 elements
   IntArray array(10);

   // Fill the array with numbers 1 through 10
   for (int i = 0; i<10; i++)
      array[i] = i + 1;
   array.print();

   // Resize the array to 8 elements
   array.resize(8);
   array.print();

   // Insert the number 20 before element with index 5
   array.insertBefore(20, 5);
   array.print();

   // Remove the element with index 3
   array.remove(3);
   array.print();

   // Add 30 and 40 to the end and beginning
   array.insertAtEnd(30);
   array.print(); 
   
   array.insertAtBeginning(40);
   array.print();

   // Print out all the numbers
   array.print();

   return 0;
}

