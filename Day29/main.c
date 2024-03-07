/*Leet code Problem- Array:Deleting elements of array
Given an integer array nums sorted in non-decreasing order, remove the duplicates 
in-place such that each unique element appears only once. The relative order of the 
elements should be kept the same. Then return the number of unique elements in nums.
Example:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums 
being 0, 1, 2, 3, and 4 respectively.It does not matter what you leave beyond the 
returned k (hence they are underscores).*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) 
{
	/*In case if the array is empty*/
	if (numsSize == 0)
	{
		return 0;
	}
		
	int i = 0, k = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] != nums[k])
		{
			k++;
			nums[k] = nums[i];
		}
	}
	return k + 1;/*k is an index, to get exact count return k+1*/
}

int main()
{
	int nums[] = { 0,0,0,1,1,2,3,3,4,5,6,7,7 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int result = removeDuplicates(nums, numsSize);
	printf("The resulting array contains %d elements after removing all the duplicates.\n", result);
	return 0;
}



