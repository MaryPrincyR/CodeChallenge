/*This program is from the book 'The C Programming Language' by K & R */
#include <stdio.h>

/*power: raise base to n-th power;n >= 0*/
int power(int base, int n)
{
	int i, result = 1;
	for (i = 1; i <= n; i++)
	{
		result = result * base;
	}
	return result;
}

int main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%-2d %-4d %-4d\n", i, power(2, i), power(-3, i));
	}
	return 0;
}
