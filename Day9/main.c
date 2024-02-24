/*This program reads characters from the standard input and
counts the number of lines , words , and characters */

#include <stdio.h>

int main()
{
    int c, no_of_lines = 0, no_of_words = 0, no_of_characters = 0;
    int inword = 0;/*flag indicating whether the program is currently inside a word or not*/

    while ((c = getchar()) != EOF)
    {
        ++no_of_characters;
        if (c == '\n')
        {
            ++no_of_lines;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            inword = 0;
        }
        else if (inword == 0)
        {
            inword = 1;
            ++no_of_words;
        }
    }

    printf("Lines: %d, Words: %d, Characters: %d\n", no_of_lines, no_of_words, no_of_characters);
    return 0;
}