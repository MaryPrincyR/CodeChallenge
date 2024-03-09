/*Linear search algorithm*/

#include <stdio.h>
#include <stdbool.h>

bool linearSearch(int* array, int length, int element)
{
	/*Check each element starting from the first one*/
	for (int j = 0; j < length; j++)
	{
		/*Element found at index i, so return true.*/
		if (array[j] == element)
		{
			return true;
		}
	}
	/*Didn't find the element in the array.*/
	return false;
}

int main()
{
	/*Declare an array of 6 elements*/
	int array[6];

	/*Variable to keep track of the length of the array*/
	int length = 0;

	/*Iterate through the 6 indexes of the Array.*/
	for (int i = 0; i < 6; ++i)
	{
		/*Add a new element and increment the length as well*/
		array[length++] = i;	
	}

	/*Print out the results of searching for 4 and 30.*/
	printf("Does the array contain the element 4? - %s\n", linearSearch(array, length, 4) ? "true" : "false");
	printf("Does the array contain the element 10? - %s\n", linearSearch(array, length, 10) ? "true" : "false");

	return 0;
}