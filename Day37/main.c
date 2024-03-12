/*This code implements a better repeated deletion algorithm. This technique is called
two-pointer technique.
In this technique we iterate over the Array in two different places at the same time.
* readPointer-Read all the elements , to identify the duplicates.
* writePointer-Keep track of the next position in the front to write the next 
unique element we've found.*/
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int arrSize)
{
    /*Use the two pointer technique to remove the duplicates in-place.*/
    /*The first element shouldn't be touched; it's already in its correct place.*/

    /*Keep track of the next position in the front to write the next unique 
    element we've found.*/
    int writePointer = 1;

    /*Read all the elements to identify the duplicates.*/
    int readPointer = 1;

    /*Go through each element in the Array.*/
    for ( readPointer = 1; readPointer < arrSize; readPointer++) 
    {
        /*If the current element we're reading is *different* to the previous element...*/ 
        if (nums[readPointer] != nums[readPointer - 1]) 
        {
            /*Copy it into the next position at the front, tracked by writePointer.*/
            nums[writePointer] = nums[readPointer];

            /*And we need to now increment writePointer, because the next element
            should be written one space over.*/
            ++writePointer;
        }
    }

    /*This turns out to be the correct length value.*/
    return writePointer;
}

int main() 
{
    int arr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDuplicates(arr, arrSize);
    printf("New size: %d\n", newSize);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
