#include "stdafx.h"
#include "Department.h"

void Department::add(Teacher* teacher)
{
   m_teachers.push_back(teacher);
}

std::ostream& operator<<(std::ostream &out, const Department &dept)
{
   out << "Department: ";

   unsigned int size = dept.m_teachers.size();

   for (int i = 0; i < size; i++)
   {
      out << dept.m_teachers[i]->getName() << ' ';
   }

   out << '\n';

   return out;
}

