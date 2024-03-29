/*Leet code problem:
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
Example:
Input: arr = {1,0,2,3,0,4,5,0}
Output: {1,0,0,2,3,0,0,4}
*/

#include <stdio.h>
void duplicateZeros(int* arr, int arrSize)
{
    int i = 0, countZeros = 0;

    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] == 0)
        {
            ++countZeros;
        }
    }

    for (i = arrSize - 1; i >= 0; i--)
    {
        if (i + countZeros < arrSize)
        {
            arr[i + countZeros] = arr[i];
        }

        if (arr[i] == 0)
        {
            --countZeros;
            if (i + countZeros < arrSize)
            {
                arr[i + countZeros] = 0;
            }
        }
    }

    for (i = 0; i < arrSize; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int arr[] = { 1,0,2,3,0,4,5,0 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    duplicateZeros(arr, arrSize);
    return 0;
}