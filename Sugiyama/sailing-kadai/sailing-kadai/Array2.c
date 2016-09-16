#include<stdio.h>

#define MAX 10

/* プロトタイプ宣言 */
int hoge(int);


void main() {

	/*　変数　*/
	int score[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	/*　処理　*/
	hoge(score[0]);

	return;
}
int hoge(int x) {

	if (x == 10)
	{
		printf("%d\n", x);
	}
	else
	{
		printf("%d\n", x);
		hoge(x + 1);	//再起呼び出し
	}
	return;
}