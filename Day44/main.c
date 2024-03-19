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
    /*Allocate memory for a boolean array of size numsSize + 1 and initialize all 
    elements to false. This array is used to track the presence of numbers in the nums
    array.*/
    bool* boolArray = (bool*)calloc(numsSize + 1, sizeof(bool));/*calloc is used here
    because the allocated memory is initialized to 0 or false.*/

    if (boolArray == NULL)
    {
        printf("Memory allocation for boolArray has failed.\n");
        return NULL;
    }

    /*Iterate over the nums array and mark the corresponding index in boolArray as true.
    The remaining indexes in boolArray is already false.*/
    for (int i = 0; i < numsSize; i++)
    {
        boolArray[nums[i]] = true;
    }

    /*Allocate memory for the result array*/
    int* result = (int*)malloc(numsSize * sizeof(int));

    if (result == NULL)
    {
        printf("Memory allocation for result has failed.\n");
        free(boolArray);  /*Free boolArray if result allocation fails*/ 
        return NULL;
    }

    *returnSize = 0;

    /*Iterate over the boolArray and for each false value(indicating the number
    is missing in nums), and add the index to the result array.*/
    for (int i = 1; i <= numsSize; i++)
    {
        if (boolArray[i] == false)
        {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }

    free(boolArray);  /*Free boolArray before returning result*/
    return result;
}

int main()
{
    //int nums[] = { 1,1 };range:[1,2]
    //int nums[] = { 2,2,3,3,5 };//range:[1,5]
    int nums[] = { 1,2,4,9,1,2,7,4,9 };//range:[1,9]
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    //printf("%d\n", numsSize);
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
