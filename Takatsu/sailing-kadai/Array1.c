#include <stdio.h>

/***********************************************************

初期値として1~10までの整数値を入れた配列を用意し
その値をループ構文(for,do-while,while)を用いて表示しなさい。

***********************************************************/

int main()
{

	//変数宣言
	int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i;

	//表示
	for (i = 0; i < 10; ++i)
	{

		printf("%d\n", Array[i]);

	}

	return 0;

}