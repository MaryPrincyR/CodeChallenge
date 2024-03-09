/*Leet code:- Array:Search an element in the array
* This code implements linear search algorithm . 
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool linearSearch(int* array, int length, int element) 
{
    /* Carry out the linear search by checking each element,
    starting from the first one.*/ 
    for (int i = 0; i < length; i++)
    {
        /*Element found at index i.*/
        /*So return true to say it exists.*/
        if (array[i] == element) 
        {
            return true;
        }
    }

    /*Didn't find the element in the array.*/
    return false;
}

int main()
{
    int array[10] = { 0,1,2,3,4,5,6,7,8 };
    //int array[10];
    int length = sizeof(array) / sizeof(array[0]);
    int element = 0;
    bool found = linearSearch(array, length, element);
    
    if (found)
    {
        printf("Element found!\n");
    }
    else
    {
        printf("Element not found!\n");
    }

    return 0;
}

