#include <stdio.h>

#define MIN 0
#define MAX 10

void change(int);

void main()
{
	int num = MIN;

	printf("初期化前：%d\n", num);

	change(&num);

	printf("初期化後：%d\n", num);

	return;
}

void change(int *num)
{
	*num = MAX;
}