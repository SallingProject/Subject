#include <stdio.h>

#define MIN 0
#define MAX 10

void change(int);

void main()
{
	int num = MIN;

	printf("�������O�F%d\n", num);

	change(&num);

	printf("��������F%d\n", num);

	return;
}

void change(int *num)
{
	*num = MAX;
}