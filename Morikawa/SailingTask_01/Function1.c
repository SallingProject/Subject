#include <stdio.h>

#define MIN 0
#define MAX 10

void change(int);

void main()
{
	int num = MIN;

	printf("‰Šú‰»‘OF%d\n", num);

	change(&num);

	printf("‰Šú‰»ŒãF%d\n", num);

	return;
}

void change(int *num)
{
	*num = MAX;
}