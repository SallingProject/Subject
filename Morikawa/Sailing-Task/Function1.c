#include <stdio.h>

void change(int);

void main()
{
	int num = 0;

	printf("初期化前：%d\n", num);
	change(num);

	return;
}

void change(int num)
{
	num = 10;
	printf("初期化後：%d\n", num);
}