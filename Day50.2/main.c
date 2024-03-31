/*Leet code problem: Array and Strings 
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer.The digits are ordered from most significant
to least significant in left - to - right order.The large integer does not contain any 
leading 0's.Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1, 2, 3]
Output : [1, 2, 4]
Explanation : The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be[1, 2, 4].

Example 2 :
Input : digits = [4, 3, 2, 1]
Output : [4, 3, 2, 2]
Explanation : The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be[4, 3, 2, 2].

Example 3 :
Input : digits = [9]
Output : [1, 0]
Explanation : The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be[1, 0].

Constraints :
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		/*if digit[i] is a number other than 9, increment it and return the array*/
		if (digits[i] < 9)
		{
			++digits[i];
			*returnSize = digitsSize;
			return digits;
		}
		/*if digit[i] is 9, set digit[i] to 0*/
		digits[i] = 0;
	}

	/*suppose digits[] = {9,9}, after incrementing last digit ,the resulting array
	size becomes 3, so we have to add an extra memory for the new element */
	*returnSize = digitsSize + 1;
	int* newArray = (int*)malloc((*returnSize) * sizeof(int));
	if (newArray == NULL)
	{
		return NULL;
	}
	newArray[0] = 1;
	for (int i = 1; i < *returnSize; i++)
	{
		newArray[i] = digits[i - 1];
	}
	
	return newArray;
}
int main()
{
    //int digits[] = { 1,2,3 };
    //int digits[] = { 9 };
    //int digits[] = { 4,3,2,1 };
    int digits[] = { 9,9,9 };
	int digitsSize = sizeof(digits) / sizeof(digits[0]);
	int returnSize;
	int* newArray = plusOne(digits, digitsSize, &returnSize);
	if (newArray == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1; // Return an error code
	}
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d\t", newArray[i]);
	}
	free(newArray);
	return 0;
}
