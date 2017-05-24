#include "stdafx.h"
#include <iostream>
#include <string>

std::string getName()
{
    std::string name;

    do {
        std::cout << "Enter a name? ";
        std::cin >> name;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
    } while (name.length() == 0);

    return name;
}

int getNumber(
    int minimum,
    int maximum)
{
    int number;

    do
    {
        std::cout << "Enter a number (" << minimum << "-" << maximum << "): ";
        std::cin >> number;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
    } while (number < minimum || number > maximum);

    return number;
}

struct Student
{
    std::string name;
    int grade;
};

int getNumberOfStudents()
{
    std::cout << "Total number of students? ";

    int number = getNumber(1, 5);

    return number;
}

void InputStudentDetails(const int numberOfStudents, Student* students)
{
    for(int i=0; i < numberOfStudents; i++)
    {
        std::string studentName = getName();
        int studentGrade = getNumber(0, 100);

        students[i].name = studentName;
        students[i].grade = studentGrade;
    }
}

void sortStudents(const int size, Student* students)
{
    bool hasSwapHappened;
    int iteration = 0;
    do
    {
        hasSwapHappened = false;
        iteration++;

        for (int i = 0; i < size - iteration; i++)
        {
            if (students[i].grade < students[i + 1].grade)
            {
                Student temp = students[i];

                students[i] = students[i + 1];
                students[i + 1] = temp;

                // todo creates error std::swap(students[i], students[i + 1]);

                hasSwapHappened = true;
            }
        }
    } while (hasSwapHappened);
}

void printStudent(const Student student)
{
    std::cout << student.name << " got a grade of " << student.grade << "\n";
}


void printStudents(const int size, const Student* students)
{
    for (int i = 0; i < size; i++)
    {
        printStudent(students[i]);
    }
}

void quiz2()
{
    int numberOfStudents = getNumberOfStudents();

    Student *students = new Student[numberOfStudents];

    InputStudentDetails(numberOfStudents, students);

    sortStudents(numberOfStudents, students);

    printStudents(numberOfStudents, students);
}
/*
 * 2) Write the following program: Create a struct that holds a student’s name and grade (on a scale of 0-100). 
 * Ask the user how many students they want to enter. Dynamically allocate an array to hold all of the students. 
 * Then prompt the user for each name and grade. Once the user has entered all the names and grades, sort the 
 * list by grade (highest first). Then print all the names and grades in sorted order.
 * For the following input:
 * Joe
 * 82
 * Terry
 * 73
 * Ralph
 * 4
 * Alex
 * 94
 * Mark
 * 88
 * The output should look like this:
 * Alex got a grade of 94
 * Mark got a grade of 88
 * Joe got a grade of 82
 * Terry got a grade of 73
 * Ralph got a grade of 4
 * 
 * Hint: You can modify the selection sort algorithm from lesson 6.4 -- Sorting an array using selection sort to sort your dynamic array.
 */