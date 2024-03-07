/*Code from the leetcode topic - Array:Array Deletions.
This code shows how to delete the last element of an array, first element of an array
and any element inside the array.
*/

#include <stdio.h>
int main()
{
    /*Declare an array that can store up to 10 elements*/
    int intArray[10];

    /*The array currently contains 0 elements*/
    int length = 0;

    int i = 0;
    /*Add elements to the first seven indexes of the array*/
    for (i = 0; i < 7; i++)
    {
        intArray[i] = i;
        ++length;
    }

    printf("Original array:\n");
    for (i = 0; i < length; i++)
    {
        printf("Index % d contains % d\n", i, intArray[i]);
    }

    /*Deleting the last element of the array*/
    --length;

    printf("\n");
    printf("After deleting last element of the array:\n");
    for (i = 0; i < length; i++)
    {
        printf("Index % d contains % d\n", i, intArray[i]);
    }
    
    /*Deleting first element of the array*/

    /*Starting at index 1, we shift each element one position to the left.*/
    for (i = 1; i < length; i++)
    {
        intArray[i - 1] = intArray[i];
    }

    /*Note that it's important to reduce the length of the array by 1. Otherwise,
    we'll lose consistency of the size.This length variable is the only thing
    controlling where new elements might get added.*/
    --length;

    printf("\n");
    printf("After deleting first element of the array:\n");
    for (i = 0; i < length; i++)
    {
        printf("Index % d contains % d\n", i, intArray[i]);
    }

    /*Deleting From Anywhere in the Array*/

    /*Suppose I want to delete element at index 2*/
    /*Shift each element one position to the left*/
    for (i = 3; i < length; i++)
    {
        intArray[i - 1] = intArray[i];
    }

    /*Deleting the last element of the array*/
    --length;

    printf("\n");
    printf("After deleting element at index 2 of the array:\n");
    for (i = 0; i < length; i++)
    {
        printf("Index % d contains % d\n", i, intArray[i]);
    }

    return 0;
}

