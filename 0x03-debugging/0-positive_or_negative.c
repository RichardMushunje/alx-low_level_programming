#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - checks weather the generated number positive, zero or negative.
**/

void positive_or_negative(int i)
{
	if (i > 0)
	{
		printf("%d is positive\n", i);
	}
	else if (i == 0)
	{
		printf("%d is zero\n", i);
	}
	else
	{
		printf("%d is negative\n", i);
	}
}
