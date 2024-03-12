/*Leet code problem:-Array-In place operations
Given an integer array nums and an integer val, remove all occurrences of val in 
nums in-place. The order of the elements may be changed. Then return the number 
of elements in nums which are not equal to val.
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
	int writePointer = 0;
	for (int readPointer = 0; readPointer < numsSize; readPointer++)
	{
		if (nums[readPointer] != val)
		{
			nums[writePointer] = nums[readPointer];
			++writePointer;
		}
	}
	return writePointer;
}

int main()
{
	int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
	int val = 2;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int count = removeElement(nums, numsSize, val);
	printf("Number of elements left after removing %d is %d\n", val, count);
	return 0;
}