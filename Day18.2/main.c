/*Leet Code Problem:
Given an array nums of integers, return how many of them contain an even number of digits.
Example: Input: nums[] = {12,345,2,6,7896}
Output: 2
*/


#include<stdio.h>
int findNumbers(int* nums, int numsSize)
{
    int i = 0, count = 0, tracked = 0;

    for (i = 0; i < numsSize; i++)
    {
        count = 0;//reset count for the new number
        while (nums[i] != 0)
        {
            nums[i] = nums[i] / 10;
            ++count;
        }
        if (count % 2 == 0)
            ++tracked;//keep track of numbers with even number of digits
    }

    printf("%d numbers in the array have even number of digits\n", tracked);
    return tracked;
}
int main()
{
    int nums[] = { 123456, 12,345,2,6,7896,10,100 };
    findNumbers(nums, sizeof(nums) / sizeof(nums[0]));
    return 0;
}