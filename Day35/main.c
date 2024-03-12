/*Leet code Problem:ARRAY Section-In place array oprations
Problem:Given an array arr, replace every element in that array with the greatest 
element among the elements to its right, and replace the last element with -1.
After doing so, return the array.
Example: arr[]=[17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
*/
#include <stdio.h>
#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize) 
{
    *returnSize = arrSize;
    int* returnArray = (int*)malloc(sizeof(int) * arrSize);
    if (returnArray == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    int max = -1;
    for (int i = arrSize - 1; i >= 0; i--)
    {
        returnArray[i] = max;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return returnArray;
}

int main() 
{
    int arr[] = { 17,18,5,4,6,1 };
    //int arr[] = { 400 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int returnSize = 0;
    int* returnArray = replaceElements(arr, arrSize, &returnSize);

    if (returnArray != NULL)
    {
        for (int k = 0; k < arrSize; k++)
        {
            printf("%d\t", returnArray[k]);
        }
        free(returnArray); // Free the memory only if it was successfully allocated
    }
    
    return 0;
}
