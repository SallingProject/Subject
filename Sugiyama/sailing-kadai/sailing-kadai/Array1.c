#include<stdio.h>

void main(){
	
	// 変数宣言 //
	
	int score[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;

	// 処理 //

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", score[i]);
	}

	return;
}