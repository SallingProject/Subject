#include <stdio.h>

void change(int);

void main()
{
	int num = 0;

	printf("�������O�F%d\n", num);
	change(num);

	return;
}

void change(int num)
{
	num = 10;
	printf("��������F%d\n", num);
}