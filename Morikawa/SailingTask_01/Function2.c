#include <stdio.h>

#define MIN 0
#define MAX 10

int change(int);

void main()
{
	int num = MIN;

	printf("�������O�F%d\n", num);

	num = change(num);

	printf("��������F%d\n", num);

	return;
}

int change(int num)
{
	num = MAX;

	return num;
}