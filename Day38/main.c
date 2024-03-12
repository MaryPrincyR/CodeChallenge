/*Leet code Problem:-Array-In place operations
Given an integer array nums, move all 0's to the end of it while maintaining the 
relative order of the non-zero elements.Note that you must do this in-place without 
making a copy of the array.
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/
#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize)
{
	/*We are using two-pointer technique to solve this problem*/

	int writePointer = 0;

	/*Move all the non-zero elements to the front of the array*/
	for (int readPointer = 0; readPointer < numsSize; readPointer++)
	{
		if (nums[readPointer] != 0)
		{
			nums[writePointer] = nums[readPointer];
			++writePointer;
		}
	}

	/*Fill the rest of the array with zeros*/
	while (writePointer < numsSize)
	{
		nums[writePointer] = 0;
		++writePointer;
	}	
}

int main()
{
	int nums[] = {0, 1, 0, 3, 12};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	moveZeroes(nums, numsSize);

	/*Modified array*/
	for (int j = 0; j < numsSize; j++)
	{
		printf("%d\t", nums[j]);
	}
	return 0;
}