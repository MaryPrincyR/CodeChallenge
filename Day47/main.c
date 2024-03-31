/*This code demonstrates the use of dynamic memory allocation in C using malloc,
realloc, and free. It also shows how to use the qsort function to sort an array.
*/
#include <stdio.h>
#include <stdlib.h>

/*The comparator function compare() is used by qsort to compare the elements of
the array during the sort.It takes two generic pointers (void*), casts them to int*,
dereferences them to get the integer values, and subtracts b from a. If the result is
negative, a is considered less than b. If it’s positive, a is considered greater than b.
If it’s zero, a and b are considered equal.*/
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    /* 1.initialize */
    int* array = malloc(5 * sizeof(int));/*allocate memory for 5 elements*/
    if (array == NULL)
    {
        printf("Memory allocation for array has failed.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        array[i] = i;
    }

    /* 2.get length */
    printf("The length of array is: 5\n");

    /* 3.access element */
    printf("The first element in array is: %d\n", array[0]);

    /* 4.iterate over the array */
    printf("The contents of array are: ");
    for (int i = 0; i < 5; ++i)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    /* 5.modify element */
    array[0] = 5;
    printf("[After modifying first element] The contents of array are: ");
    for (int i = 0; i < 5; ++i)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    /* 6.sort */
    qsort(array, 5, sizeof(int), compare);

    /* 7.add new element at the end of the array */
    int* temp = realloc(array, 6 * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory reallocation has failed.\n");
        free(array);
        return 1;
    }
    else
    {
        array = temp;
        array[5] = -1;
    }
    printf("[After sorting and adding new element at the end] The contents of v4 are: ");
    for (int i = 0; i < 6; ++i)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    /* 8.delete the last element */
    temp = realloc(array, 5 * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory reallocation has failed.\n");
        free(array);
        return 1;
    }
    else
    {
        array = temp;
    }
    printf("[After deleting last element] The contents of array are: ");
    for (int i = 0; i < 5; ++i)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    free(array);
    array = NULL; /* It's a good practice to set a freed pointer to NULL*/

    return 0;
}
