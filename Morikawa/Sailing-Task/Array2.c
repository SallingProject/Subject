#include <stdio.h>

#define START 0
#define END 10

void loop(int);

void main()
{
	loop(START);

	return;
}

void loop(int i)
{
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("%d\n", array[i]);
	i++;

	if (i >= END) return;

	loop(i);
}