/*Leet code problem:-Array:Searching for items in an array
Problem-Given an array of integers arr, return true if and 
only if it is a valid mountain array.
Example 1:[0,2,3,4,2,1] is a mountain array.
Example 2:[1,2,3,1,0] is a mountain array.
[0,2]is not a mountain array.
[0,1,2,3,3,4,2,1] is not a mountain array*/

#include <stdio.h>
#include <stdbool.h>

bool validMountainArray(int* arr, int arrSize)
{
    /*edge-case: check whether number of elements is less than 3. If so return,false*/
    if (arrSize < 3)
    {
        return false;
    }
    int i = 0;
    //climb up and find the peak
    while ((i + 1 < arrSize ) && (arr[i] < arr[i + 1]))
    {
        i++;
    }
    /*edge-case:peak can't be first or last element*/
    if ((i == 0) || (i == arrSize - 1))
    {
        return false;
    }
    //climb down
    while ((i + 1 < arrSize ) && (arr[i] > arr[i + 1]))
    {
        i++;
    }
    return i == arrSize - 1;
}

int main()
{
    //int arr[] = { 1,2,3 };/*this array is not a mountain array*/
    //int arr[] = { 3,2,1 };/*this array is not a mountain array*/
    int arr[] = { 0,2,3,4,5,2,1,0 };/*this array is a mountain array*/
    //int arr[] = { 0,2,3,3,5,2,1,0 };/*this array is not a mountain array*/
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    bool valid = validMountainArray(arr, arrSize);
    if (valid)
        printf("Valid mountain array\n");
    else
        printf("Not a valid mountain array\n");
    return 0;
}