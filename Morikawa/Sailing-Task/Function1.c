#include <stdio.h>

int change(int);

void main()
{
	int num = 0;

	printf("�������O�F%d\n", num);

	num = change(num);

	printf("��������F%d\n", num);

	return;
}

int change(int num)
{
	num = 10;

	return num;
}