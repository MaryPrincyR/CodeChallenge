/*This code demonstrates how 2D arrays can be initialized and used in C,
and how they can be passed to functions. It also shows that if a 2D array 
is partially initialized, the rest of the elements will be automatically 
initialized to zero.(However, please note that this automatic initialization
to zero does not apply to dynamically allocated memory using malloc, calloc,
etc.) The printArray function demonstrates how to iterate over a 2D array
and print its elements. The (int*) cast is used when passing the 2D array to
the printArray function to ensure the array decays to a pointer correctly. 
This is necessary because in C, when you pass an array to a function, it
decays to a pointer to the first element of the array.*/

#include <stdio.h>

void printArray(int* a, int rows, int cols) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(a + i * cols + j));/*If i=2 and j=3, it computes
            to *(a + 2 * cols + 3), which is equivalent to *(a + 2*cols + 3).
            Since a is a pointer to the first element of the 2D array,
            a + 2*cols points to the first element of the third row 
            (since each row has cols number of elements). Therefore, 
            *(a + 2*cols + 3) gives the value at the fourth location 
            (since indexing starts from 0) of the third row of the array.*/
        }
        printf("\n");
    }      
}

int main() 
{
    printf("Example I\n");
    int a[2][5] = { 0 };
    printArray((int*)a, 2, 5);/* Here this line may be substituted by printArray(a, 2, 5).
    The reason it works without the cast is because array names in C are essentially 
    pointers to the first element of the array. When you pass a 2D array to a function, 
    it decays to a pointer to the first element (which is a 1D array), and this pointer 
    can be implicitly converted to a pointer to an int.However, using the (int*) cast can
    make the code more explicit and clear to readers, indicating that the function is 
    expecting a pointer to an int. */

    printf("Example II\n");
    int b[2][5] = { {1,2,3,4,5} };
    printArray((int*)b, 2, 5);

    printf("Example III\n");
    int c[2][5] = { {1,2,3,4,5},{5,6} };
    printArray((int*)c, 2, 5);

    printf("Example IV\n");
    int d[3][5] = { {1,2,3,4},{5,6},{7,8} };
    printArray((int*)d, 3, 5);

    return 0;
}
