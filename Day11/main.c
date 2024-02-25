/*This program count lines ,words and characters in input*/

#include<stdio.h>
#define IN  1 //inside a word
#define OUT 0 //outside a word

int main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		else if ((c == ' ') || (c == '\n') || (c == '\t'))
		{
			state = OUT;

		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("No. of lines: %d\n", nl);
	printf("No. of words: %d\n", nw);
	printf("No. of characters: %d", nc);

}
