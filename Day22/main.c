/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 
respectively.Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead 
be stored inside the array nums1. To accommodate this, nums1 has a length 
of m + n, where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example:
Input: nums1 = {1,2,3,0,0,0}, m = 3, nums2 = {2,5,6}, n = 3
Output: {1,2,2,3,5,6}
Explanation: The arrays we are merging are {1,2,3} and {2,5,6}.
The result of the merge is {1,2,2,3,5,6} with the underlined elements coming from nums1.
*/

#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	/*two pointers (or indices) to keep track of the current position
	in nums1 and nums2 during the merge process.*/
	int i = 0, j = 0;

	/*These pointers should initially point to the last valid element in each array, 
	which are m - 1 for nums1 and n - 1 for nums2.*/
	i = m - 1;
	j = n - 1;

	/*pointer to keep track of current position of merged array*/
	int k;

	/*length of merged array will be m+n. k points to last element of
	merged array so k = m+n-1*/
	k = m + n - 1;

	while ((i >= 0) && (j >= 0))
	{
		if (nums1[i] > nums2[j])
		{
			nums1[k] = nums1[i];
			--i;
		}
		else
		{
			nums1[k] = nums2[j];
			--j;
		}
		--k;
	}

	/*This loop handles the general case where there might be remaining elements
	in nums2 after all elements in nums1 have been processed. In such a case, these 
	remaining elements in nums2 should be copied to nums1.*/
	while (j >= 0)
	{
		nums1[k] = nums2[j];
		--j;
		--k;
	}
	/*Print the merged array*/
	for (i = 0; i < nums1Size; i++)
	{
		printf("%d\t", nums1[i]);
	}
}


int main()
{
	int nums1[] = { 1,2,3,0,0,0 };
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2[] = { 2,5,6 };
	int num2Size = sizeof(nums2) / sizeof(nums2[0]);
	int m = 3, n = 3;
	merge(nums1, nums1Size, m, nums2, num2Size, n);

	return 0;
}