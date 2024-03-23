/*Leet code problem:Array and Strings
You are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much as 
every other number in the array.If it is, return the index of the largest element, 
or return -1 otherwise.

Example 1:
Input: nums = [3, 6, 1, 0]
Output : 1
Explanation : 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.

Example 2 :
Input : nums = [1, 2, 3, 4]
Output : -1
Explanation : 4 is less than twice the value of 3, so we return -1.

Constraints :
2 <= nums.length <= 50
0 <= nums[i] <= 100
The largest element in nums is unique.
*/

#include <stdio.h>
#include <stdlib.h>

int dominantIndex(int* nums, int numsSize) 
{
	int largest = nums[0];
	int maxIndex = 0;

	/*Find the largest element in the array*/
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] > largest)
		{
			largest = nums[i];
			maxIndex = i;
		}		
	}

	/*Determine whether the largest element in the array is at least twice as much as 
    every other number in the array.If not return -1.*/
	for (int j = 0; j < numsSize; j++)
	{
		if ((nums[j] != largest) && (largest < 2 * nums[j]))
		{
			return -1;
		}
	}

	return maxIndex;/*If the largest element in the array is at least twice as much as 
    every other number in the array return maxIndex.*/
}

int main()
{
	//int nums[] = { 3, 6, 1, 0 };
	int nums[] = { 1, 2, 3, 4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int index = dominantIndex(nums, numsSize);
	printf("The dominant index in the array is %d", index);
	return 0;
}