// Section 12
// Challenge

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes

  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.

  The function should return a pointer to the newly allocated array.

  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.

  For example,

  Below is the output from the following code which would be in main:

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};


    cout << "Array 1: " ;
    print(array1,5);

    cout << "Array 2: " ;
    print(array2,3);

    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);

   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/

#include <iostream>

using namespace std;

//Function prototypes
int* apply_all(const int* const array1, size_t array1_size, const int* const array2, size_t array2_size);
void print(const int* const array, size_t array_size);

int main() {
    const size_t array1_size{ 5 };
    const size_t array2_size{ 3 };

    int array1[]{ 1,2,3,4,5 };
    int array2[]{ 10,20,30 };


    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int* results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{ array1_size * array2_size };

    cout << "Result : ";
    print(results, results_size);

    delete[] results;

    cout << endl;

    return 0;
}

/*
    This function expects:
    array1 - a pointer to an array of integers
    array1_size - the number of integers in array1
    array2 - a pointer to another array of integers
    array2_size - the number of integers in array2

    The function dynamically allocates a new array new_storage that is of size = array1_size * array2_size
    Then it loops through each element of arr2 and multiples it across all the
    elements of arr1 and each product is stored in the newly created array
*/
int* apply_all(const int* const array1, size_t array1_size, const int* const array2, size_t array2_size)
{
    int* new_storage{};
    new_storage = new int[array1_size * array2_size];
    int counter{ 0 };

    for (size_t i = 0; i < array2_size; i++)
    {
        for (size_t j = 0; j < array1_size; j++)
        {
            new_storage[counter] = array2[i] * array1[j];
            ++counter;
        }
    }
    return new_storage;
}

/*
    This function expects:
    array - a pointer to an array of integers
    array_size - the number of integers in array

    The function loops through array and displays all the integers
    in the array. Ex. [ 10 20 30 ]
*/
void print(const int* const array, size_t array_size)
{
    cout << "[ ";
    for (size_t i = 0; i < array_size; i++)
    {
        
        cout << array[i] << " ";
        
    }
    cout << "]";
    cout << endl;
}
