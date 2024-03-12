/*Leet code problem:-Array-in place operations
The below code implements a better deletion algorithm.
Given a sorted array, remove the duplicates such that each element appears only once.
Input: array = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
Output: [0, 1, 2, 3, 4]*/
#include <stdio.h>
#include <stdlib.h>

int copyWithRemovedDuplicates(int* nums, int numsSize) 
{
    /*Count how many unique elements are in the Array.*/
    int uniqueNumbers = 0;

    for (int i = 0; i < numsSize; i++)
    {
        /*An element should be counted as unique if it's the first
        element in the Array, or is different to the one before it.*/
        if (i == 0 || nums[i] != nums[i - 1])
        {
            nums[uniqueNumbers] = nums[i];
            ++uniqueNumbers;
        }
    }
    return uniqueNumbers;
}

int main() 
{
    int nums[] = { 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int newSize = copyWithRemovedDuplicates(nums, numsSize);
    printf("New size of the array is %d\n", newSize);
    printf("Array after removing duplicates:\n");
    for (int k = 0; k < newSize; k++)
    {
        printf("%d\t", nums[k]);
    }
    return 0;
}
