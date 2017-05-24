#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string name;
    char grade;
};

class GradeMap
{
public:
    GradeMap()
    {
    }

    char& operator[] (const std::string name);

private:
    std::vector<StudentGrade> m_Grades;
};

char& GradeMap::operator[] (const std::string name)
{
    StudentGrade studentGrade;

    for (StudentGrade grade : m_Grades)
    {
        if (grade.name == name)
        {
            return grade.grade;
        }
    }

    StudentGrade newStudentGrade = StudentGrade{ name, '?' };   

    m_Grades.push_back(newStudentGrade);
    
    return m_Grades.back().grade;
}

void quiz1()
{
    GradeMap grades;
    grades["Joe"] = 'A';
    grades["Frank"] = 'B';
    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
}

/*
 * 1) A map is a class that stores elements as a key-value pair. The key must be unique, 
 *    and is used to access the associated pair. In this quiz, we’re going to write an 
 *    application that lets us assign grades to students by name, using a simple map class. 
 *    The student’s name will be the key, and the grade (as a char) will be the value.
 *    
 *    1a) First, write a struct named StudentGrade that contains the student’s name 
 *        (as a std::string) and grade (as a char).
 *        
 *    1b) Add a class named GradeMap that contains a std::vector of StudentGrade named m_map. 
 *        Add a default constructor that does nothing.
 *        
 *    1c) Write an overloaded operator[] for this class. This function should take a std::string 
 *        parameter, and return a reference to a char. In the body of the function, first iterate 
 *        through the vector to see if the student’s name already exists (you can use a for-each loop 
 *        for this). If the student exists, return a reference to the grade and you’re done. 
 *        Otherwise, use the std::vector::push_back() function to add a StudentGrade for this new 
 *        tudent. When you do this, std::vector will add a copy of your StudentGrade to itself 
 *        (resizing if needed). Finally, we need to return a reference to the grade for the student 
 *        we just added to the std::vector. We can access the student we just added using the 
 *        std::vector::back() function.
 */