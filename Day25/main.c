/*Exercise 1.13:Coding problem from C Programming Language by k & R
 Write a program to print a histogram of the lengths of words in its input. It is easy 
 to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
int main()
{
    char c;
    int current_word_length = 0, i = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = { 0 };/*intialize to value 0 all locations
    inside the array */
    printf("Enter text (press Ctrl Z to exit)\n");
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))/*check whether an alphabet is entered*/
        {
            ++current_word_length;
        }
        else if (current_word_length > 0)/*if a character other than alphabet is entered 
            for example whitespace, indicating next word*/
        {
            if (current_word_length <= MAX_WORD_LENGTH)/*check whether the word length is 
                less than or equal to 20*/
            {
                word_lengths[current_word_length]++;/*if a word length is 5 then the value at
                 word_lengths[5] is incremented*/
            }
            current_word_length = 0;/*reset value to 0 to store length of next word*/
        }

    }
    //Horizontal histogram
    printf("\nHorizontal histogram\n");
    for (i = 1; i <= MAX_WORD_LENGTH; i++)
    {
        printf("%2d", i);/*length of words, 1 to 20*/
        for (int j = 0; j < word_lengths[i]; j++)
        {
            printf(" * ");/*if word_lengths[3]=6,then 6 *'s will be printed. That means
            there are 6 words with length 3.*/
        }
        printf("\n");
    }

    //Vertical histogram
    printf("\nVerical histogram\n");
    for (i = 1; i <= MAX_WORD_LENGTH; i++)
    {
        printf("%2d", i);/*indicates y-axis, corresponds to length of word, 1 to 20*/
        printf(" ");
        for (int j = 0; j < word_lengths[i]; j++)
        {
            printf("*");/*if word_lengths[3]=6,then 6 *'s will be printed. That means
            there are 6 words with length 3.*/
        }
        printf("\n");
    }
    printf("   ");
    for (i = 1; i <= MAX_WORD_LENGTH; i++)
        printf("%d", i % 10);/*indicates x-axis, corresponds to number of words*/
    return 0;
}