/*Write a program to count the number of occurrences of each digit,white space characters
(blank,tab,newline), and of all the other characters.*/

#include <stdio.h>
int main()
{
    int c, i, nWhite = 0, nOther = 0;
    int nDigit[10];/*array to hold the number of occurrences of each digit, rather than
    individual variables*/

    for (i = 0; i < 10; i++)
    {
        nDigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if ((c == ' ') || (c == '\t') || (c == '\n'))
            ++nWhite;
        else if ((c >= '0') && (c <= '9'))
        {
            ++nDigit[c - '0'];/*numeric value of the entered digit is obtained by subtracting
            the ASCII value of the character '0'from ASCII value of the entered digit.*/
        }
        else
            ++nOther;
    }
    printf("Digits = ");
    for (i = 0; i < 10; i++)
        printf("%d", nDigit[i]);
    printf("\twhite spaces = %d\tother characters = %d", nWhite, nOther);
    return 0;
}