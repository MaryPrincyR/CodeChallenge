#include <stdio.h>
int main()
{
    // Declare an integer array of 6 elements
    int array[6];
    int length = 0;

    // Add 3 elements to the Array
    for (int i = 0; i < 3; i++)
    {
        array[i] = i;
        length++;
    }
    
    /* Insert a new element at the end of the Array.*/
    array[length] = 10;
    length++;

    /*Again,it's important to ensure that there is enough space in the array for inserting a new element.*/
    
    /*Insert a new element at the beginning of the Array.*/

    /*First, we will have to create space for a new element.We do that by shifting each 
    element one index to the right.This will firstly move the element at index 3, then 2, 
    then 1, then finally 0.We need to go backwards to avoid overwriting any elements.*/
    for (int i = 3; i >= 0; i--)
    {
        array[i + 1] = array[i];
    }

    // Now that we have created space for the new element,
    // we can insert it at the beginning.
    array[0] = 20;
    length++;

    /*Inserting an element anywhere in the array*/
    // Say we want to insert the element at index 2.
    // First, we will have to create space for the new element.
    for (int i = 4; i >= 2; i--)
    {
        array[i + 1] = array[i];
    }
    
    // Now that we have created space for the new element,
    // we can insert it at index 2.
    array[2] = 30;
    length++;

    for (int i = 0; i < length; i++)
    {
        printf("Index %d contains %d\n", i, array[i]);
    }

    return 0;
}




