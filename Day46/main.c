/*Leet code problem-Array:In place operations
Given an integer array nums sorted in non-decreasing order, return an array of the 
squares of each number sorted in non-decreasing order.
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));

    /*Check whether memory allocation failed or not*/
    if (result == NULL)
    {
        printf("Memory allocation for result has failed.\n");
        return NULL;
    }

    int left = 0, right = numsSize - 1;/*Two pointers to iterate over the array at the
    same time*/

    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            result[i] = nums[left] * nums[left];
            ++left;
        }
        else
        {
            result[i] = nums[right] * nums[right];
            --right;
        }
    }
    return result;
}

int main()
{
    int nums[] = { -4, -1, 0, 3, 10 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = sortedSquares(nums, numsSize, &returnSize);
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }
    /*Print the result*/
    for (int k = 0; k < numsSize; k++)
    {
        printf("%d\t", result[k]);
    }

    free(result);

    return 0;
}