#include <stdio.h>

#define MIN 0
#define MAX 10

int change(int);

void main()
{
	int num = MIN;

	printf("‰Šú‰»‘OF%d\n", num);

	num = change(num);

	printf("‰Šú‰»ŒãF%d\n", num);

	return;
}

int change(int num)
{
	num = MAX;

	return num;
}