#include <stdio.h>

// 改善案
// 数値リテラルなどをそのまんま使わずに
// 不変の数値なら定数としておいておくと可読性の向上につながります
#define MAX 10

void main()
{
	//int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// 改善案
	int data[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;

	/*for (i = 0; i < 10; i++)
	{
		printf("%d\n", data[i]);
	}*/

	for (i = 0; i < MAX; i++)
	{
		printf("%d\n", data[i]);
	}
	return;
}