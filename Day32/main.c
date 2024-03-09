/* Leet code problem from array section
 * Check If N and Its Double Exist
 * Example:Input: arr = [10,2,5,3]
 * Output: true
 * 
 */

#include <stdio.h>
#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            if ((i != j) && (arr[j] == 2 * arr[i]))/*we have to check whether i != j because,
                 suppose array has an element '0',0*2 evaluates to true; so in that case 
                 we have to make sure an to ensure that we’re not comparing an element 
                 to itself*/
                return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = { -2,0,10,-19,4,6,-8,-4 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    bool found = checkIfExist(arr, arrSize);
    if (found)
        printf("N and its double exists\n");
    else
        printf("N and its double does not exists\n");
    return 0;
}