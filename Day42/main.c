/*LEET CODE PROBLEM:- Array-In place operations
Given an integer array nums, return the third distinct maximum number in this array.
If the third maximum does not exist, return the maximum number.
Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
*/
#include <stdio.h>
#include <stdlib.h>

int thirdMax(int* nums, int numsSize)
{
    /*Initialize firstMax, secondMax,and thirdMax to a value that’s smaller
    than any value that might appear in your array.This is done to handle the edge-cases
    and to ensure portability.Note that, depending on compilers minimum values of int and
    long may change.Here we are considering a general case which would work perfectly for
    any compiler.*/
    /*The minimum value of long is -2147483647-1*/
    long thirdMax = LONG_MIN;
    long secondMax = LONG_MIN;
    long firstMax = LONG_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > firstMax)
        {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        }
        else if ((nums[i] > secondMax) && (nums[i] < firstMax))
        {
            thirdMax = secondMax;
            secondMax = nums[i];
        }
        else if ((nums[i] > thirdMax) && (nums[i] < secondMax))
        {
            thirdMax = nums[i];
        }       
    }
    return thirdMax == LONG_MIN ? firstMax : thirdMax;
}
    
int main()
{
    int nums[] = { 1,6,0,3,8,4,5 };
    //int nums[] = { 1,2 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int third_Max = thirdMax (nums, numsSize);
    printf("%d\n", third_Max);
    return 0;
}