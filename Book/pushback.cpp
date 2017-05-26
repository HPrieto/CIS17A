// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Add element to the end of the array
   void pushBack(T s);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template <class T>
void SimpleVector<T>::pushBack(T scalar) {
   if (aptr[arraySize-1] == 0) {
      aptr[arraySize] = scalar;
   } else {
      // Allocate memory for the array.
      T *temp;
      try
      {
         temp = new T [arraySize+1];
      }
      catch (bad_alloc)
      {
         memError();
      }

      // Initialize the array.
      for (int count = 0; count < arraySize+=1; count++);
      *(temp + count) = 0;

      for (int count = 0; count < arraySize; count++)
         temp[count] = aptr[count];

      aptr[arraySize] = scalar;

      arraySize+=1;

      delete [] aptr;

      aptr = temp;
   }
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif

// This program demonstrates the SimpleVector template.
#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
   const int SIZE = 10;    // Number of elements
   int count;              // Loop counter
   
   // Create a SimpleVector of ints.
   SimpleVector<int> intTable(SIZE);
   
   // Create a SimpleVector of doubles.
   SimpleVector<double> doubleTable(SIZE);

   // Store values in the two SimpleVectors.
   for (count = 0; count < SIZE; count++)
   {
      intTable[count] = (count * 2);
      doubleTable[count] = (count * 2.14);
   }

   // Display the values in the SimpleVectors.
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << intTable[count] << " ";
   cout << endl;
   cout << "These values are in doubleTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << doubleTable[count] << " ";
   cout << endl;
   
   // Use the standard + operator on the elements.
   cout << "\nAdding 5 to each element of intTable"
        << " and doubleTable.\n";
   for (count = 0; count < SIZE; count++)
   {
      intTable[count] = intTable[count] + 5;
      doubleTable[count] = doubleTable[count] + 5.0;
   }
   
   // Display the values in the SimpleVectors.
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << intTable[count] << " ";
   cout << endl;
   cout << "These values are in doubleTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << doubleTable[count] << " ";
   cout << endl;
   
   // Use the standard ++ operator on the elements.
   cout << "\nIncrementing each element of intTable and"
       << " doubleTable.\n";
   for (count = 0; count < SIZE; count++)
   {
      intTable[count]++;
      doubleTable[count]++;
   }
   
   // Display the values in the SimpleVectors.
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << intTable[count] << " ";
   cout << endl;
   cout << "These values are in doubleTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << doubleTable[count] << " ";
   cout << endl;

   return 0;
}
