#include <stdio.h>

int change(int);

void main()
{
	int num = 0;

	printf("初期化前：%d\n", num);

	num = change(num);

	printf("初期化後：%d\n", num);

	return;
}

int change(int num)
{
	num = 10;

	return num;
}