/*Leet code Problem:- Array-In place operations.
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
	long max_nums[3] = { LONG_MIN,LONG_MIN,LONG_MIN };

	for (int i = 0; i < numsSize; i++)
	{
		/*If the current number is equal to any of the numbers in maxNums, 
		then it’s not a new distinct number, so the continue statement skips 
		the rest of the loop for this iteration.*/
		if ((nums[i] == max_nums[0]) || (nums[i] == max_nums[1]) || (nums[i] == max_nums[2]))
		{
			continue;
		}
		 if (nums[i] > max_nums[0])
		{
			max_nums[2] = max_nums[1];
			max_nums[1] = max_nums[0];
			max_nums[0] = nums[i];
		}
		else if (nums[i] > max_nums[1])
		{
			max_nums[2] = max_nums[1];
			max_nums[1] = nums[i];
		}
		else if (nums[i] > max_nums[2])
		{
			max_nums[2] = nums[i];
		}
	}
	return max_nums[2] == LONG_MIN ? max_nums[0] : max_nums[2];
}

int main()
{
	int nums[] = { 1,0,9,8,4 };
	//int nums[] = { 2,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int third_Max = thirdMax(nums, numsSize);
	printf("%d", third_Max);
	return 0;
}