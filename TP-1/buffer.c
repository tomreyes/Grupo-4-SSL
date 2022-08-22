#include <stdio.h>
#include "./buffer.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// getchar if not char in buffer
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push unwanted character to buffer to be used later
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("Cant ungetch anymore, there are too many characters\n");
	else
		buf[bufp++] = c;
}