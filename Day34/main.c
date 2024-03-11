/*LEET CODE PROBLEM:-ARRAY-In place operations
Given an Array of integers, return an Array where every element at an
even-indexed position is squared.
Example:arr[]={-2,3,4,0,-1,-5}
result after squaring even-indexed positions is {4,3,16,0,1,-5}*/
#include <stdio.h>
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8 };
	int length = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < length; i++)
	{
		if ((i % 2) == 0)
		{
			arr[i] = arr[i] * arr[i];/*we are over-writing the original array itself that's 
			why it is an in-place operation*/
		}
		printf("%d\t", arr[i]);
	}
	return 0;
}