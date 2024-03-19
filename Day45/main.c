/*Leet code problem:- Array-In place operations
Given an array nums of n integers where nums[i] is in the range [1, n],
return an array of all the integers in the range [1, n] that do not appear in nums.

Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    /*Iterate over the nums array and for each number nums[i],mark the number at
    the index abs(nums[i]) - 1 as negative. This indicates that the number abs(nums[i])
    is present in the nums array.*/
    for (int i = 0; i < numsSize; i++)
    {
        int index = abs(nums[i]) - 1;
        nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
    } 

    /*Allocate memory for the result array*/
    int* result = (int*)malloc(numsSize * sizeof(int));

    /*Check whether memory allocation for result failed or not*/
    if (result == NULL)
    {
        printf("Memory allocation for result failed.\n");
        return NULL;
    }
    *returnSize = 0;

    /* Iterate over the nums array again and for each index i where nums[i]
    is positive,add i + 1 to the result array. This is because the number i + 1
    is missing from the nums array.*/
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] > 0)
        {
            result[*returnSize] = j + 1;
            (*returnSize)++;
        }
    }
    return result;
}

int main()
{
    int nums[] = { 1,1 };//range:[1,2]
    //int nums[] = { 2,2,3,3,5 };//range:[1,5]
    //int nums[] = { 1,2,4,9,1,2,7,4,9 };//range:[1,9]
    //int nums[] = { 4,3,2,7,8,2,3,1 };//range:[1,8]
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = findDisappearedNumbers(nums, numsSize, &returnSize);

    /*Print the result*/
    for (int j = 0; j < returnSize; j++)
    {
        printf("%d\t", result[j]);
    }

    /*Free the result array*/
    free(result);

    return 0;
}
