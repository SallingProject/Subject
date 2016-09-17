#include<stdio.h>

/* プロトタイプ宣言 */
void hoge(int*);

void main() {

	/* 　変数　*/
	int score = 0;

	/*　処理　*/
	printf("初期化前：%d\n", score);

	hoge(&score);	//参照渡し

	printf("初期化後：%d\n", score);

	return;
}
void hoge(int* x) {

	*x = 10;

	return;
}
