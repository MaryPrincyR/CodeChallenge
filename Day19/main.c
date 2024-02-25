/*Leet Code Problem:
Given an integer array nums sorted in non-decreasing order, return an array of the
squares of each number sorted in non-decreasing order.
Example:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
*/

#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    int left = 0, right = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            result[i] = nums[left] * nums[left];
            left++;
        }
        else
        {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}

int main()
{
    int nums[] = { -4, -1, 0, 3, 10 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int* result = sortedSquares(nums, numsSize, &returnSize);
    printf("Squared and sorted array is: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}