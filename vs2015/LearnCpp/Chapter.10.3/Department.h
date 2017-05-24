#pragma once
#include "Teacher.h"
#include <vector>

class Department
{
private:
   std::vector<Teacher *> m_teachers;
public:
   void add(Teacher* t1);

   friend std::ostream& operator<<(std::ostream &out, const Department &dept);
};
