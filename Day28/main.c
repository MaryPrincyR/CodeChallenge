/*Leet code problem: Array-Deleting items from array
Given an integer array nums and an integer val, remove all occurrences of val in nums
in-place. The order of the elements may be changed. Then return the number of elements 
in nums which are not equal to val.Consider the number of elements in nums which are not 
equal to val be k, to get accepted, you need to do the following things:Change the array 
nums such that the first k elements of nums contain the elements which are not equal to val.
The remaining elements of nums are not important as well as the size of nums.
Return k.*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
   /*use two pointers, one to iterate through the array (i), and another to keep track of the
   position where the next non-val element should be placed(j).*/
		 
	int i = 0, k = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[k] = nums[i];
			k++;
		}
	}
	return k;
}

int main()
{
	int nums[] = { 0,1,2,2,3,0,4,2 };
	int val = 2;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int result = removeElement(nums, numsSize, val);
	printf("There are %d elements left after removing all %d's from the array\n", result, val);
	return 0;
}