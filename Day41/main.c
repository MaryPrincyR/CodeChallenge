/*Leet code problem:- Array-In place operations
A school is trying to take an annual photo of all the students. The students are
asked to stand in a single file line in non-decreasing order by height. Let this 
ordering be represented by the integer array expected where expected[i] is the 
expected height of the ith student in line.You are given an integer array heights
representing the current order that the students are standing in. Each heights[i] 
is the height of the ith student in line (0-indexed).
Return the number of indices where heights[i] != expected[i].
Example:-
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int heightChecker(int* heights, int heightsSize) 
{
    int count = 0;
    int* expected = (int*)malloc(sizeof(int) * heightsSize);
    if (expected == NULL) 
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Copy the heights array to the expected array
    for (int i = 0; i < heightsSize; i++)
    {
        expected[i] = heights[i];
    }

    // Sort the expected array
    for (int i = 0; i < heightsSize - 1; i++)
    {
        for (int j = 0; j < heightsSize - i - 1; j++)
        {
            if ((j + 1) < heightsSize)
            {
                if (expected[j] > expected[j + 1])
                {
                    swap(&expected[j], &expected[j + 1]);
                }
            }
        }
    }

    // Compare the heights array with the expected array
    for (int k = 0; k < heightsSize; k++)
    {
        if (heights[k] != expected[k])
        {
            ++count;
        }
    }
    free(expected);
    return count;
}

int main() 
{
    int heights[] = { 1, 1, 4, 2, 1, 3 };
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int count = heightChecker(heights, heightsSize);
    printf("%d", count);
    return 0;
}
