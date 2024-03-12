/*Leet code problem:-Array-In place operations
Given an integer array nums, move all the even integers at the beginning of 
the array followed by all the odd integers.Return any array that satisfies this condition.
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */
#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
{
	int writePointer = 0;
	*returnSize = numsSize;
	int* returnArray = (int*)malloc(sizeof(int) * numsSize);
	if (returnArray == NULL)
	{
		printf("Memory allocation failed\n");
		return NULL;
	}
	for (int readPointer = 0; readPointer < numsSize; readPointer++)
	{
		/*if number is even*/
		if ((nums[readPointer] % 2) == 0)
		{
			if (writePointer < numsSize)
			{
				returnArray[writePointer] = nums[readPointer];
				++writePointer;
			}
		}
	}
	for (int readPointer = 0; readPointer < numsSize; readPointer++)
	{
		/*if number is odd*/
		if ((nums[readPointer] % 2) != 0)
		{
			if (writePointer < numsSize)
			{
				returnArray[writePointer] = nums[readPointer];
				++writePointer;
			}
		}
	}
	return returnArray;
}

int main()
{
	int nums[] = { 3,1,2,4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize;
	int* newArray = sortArrayByParity(nums, numsSize, &returnSize);
	if (newArray != NULL)
	{
		for (int k = 0; k < numsSize; k++)
		{
			printf("%d\t", newArray[k]);
		}
	}
	
	free(newArray);
	return 0;
}