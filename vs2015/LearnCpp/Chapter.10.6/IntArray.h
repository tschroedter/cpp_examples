#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // for assert()

class IntArray
{
private:
   int m_length;
   int *m_data;

public:
   IntArray() :
      m_length(0), m_data(nullptr)
   {
   }

   IntArray(int length) :
      m_length(length)
   {
      m_data = new int[length];
   }

   ~IntArray()
   {
      delete[] m_data;
      // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
   }

   void erase()
   {
      delete[] m_data;
      // We need to make sure we set m_data to 0 here, otherwise it will
      // be left pointing at deallocated memory!
      m_data = 0;
      m_length = 0;
   }

   int& operator[](int index) const
   {
      assert(index >= 0 && index < m_length);
      return m_data[index];
   }

   int getLength() const { return m_length; }

   void reallocate(int newLength)
   {
      erase();

      if (newLength <= 0)
      {
         return;
      }

      m_data = new int[newLength];
      m_length = newLength;
   }

   void resize(int newLength)
   {
      if (m_length == newLength)
      {
         return;
      }

      if (newLength <= 0)
      {
         erase();

         return;
      }

      int *data = new int[newLength];

      if (m_length > 0)
      {
         int elementsToCopy = (newLength > m_length) ? m_length : newLength;

         for (int i = 0; i < elementsToCopy; i++)
         {
            data[i] = m_data[i];
         }
      }

      delete m_data;

      m_data = data;
      m_length = newLength;
   }

   void insertBefore(int value, int index)
   {
      assert(index >= 0 && index <= m_length);

      int newLength = m_length + 1;

      int *data = new int[newLength];

      for (int i = 0; i < index; i++)
      {
         data[i] = m_data[i];
      }

      data[index] = value;

      for (int i = index + 1; i < newLength; i++)
      {
         data[i] = m_data[i-1];
      }

      delete m_data;

      m_data = data;
      m_length = newLength;
   }

   void remove(int index)
   {
      assert(index >= 0 && index <= m_length);

      if (m_length == 1)
      {
         erase();
         return;
      }

      int newLength = m_length - 1;

      int *data = new int[newLength];

      for (int i = 0; i < index; i++)
      {
         data[i] = m_data[i];
      }

      for (int i = index + 1; i < m_length; i++)
      {
         data[i - 1] = m_data[i];
      }

      delete m_data;

      m_data = data;
      m_length = newLength;
   }

   // A couple of additional functions just for convenience
   void insertAtBeginning(int value) { insertBefore(value, 0); }
   void insertAtEnd(int value) { insertBefore(value, m_length); }
   void print() const
   {
      std::cout << "\n";

      for (int i = 0; i < getLength(); i++) 
      {
         std::cout << m_data[i] << " ";
      }
   }
};

#endif
