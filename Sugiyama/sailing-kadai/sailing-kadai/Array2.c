/*
この問題の正答は、関数に配列の先頭のアドレスを引数として渡し、再起呼びだしを使ってひとつづつアドレスをずらして
表示するのだと思いましたが、ポインタ変数で引数宣言した場合、再起呼びだしがうまくいきませんでした。
調べるのはプライドが許してくれなかったので、構造を変えました。
*/

#include<stdio.h>

#define MAX 10


void main() {
	
	/*　変数　*/

	int score[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;

	/*　処理　*/

LABEL:

	if (i == MAX - 1)
	{
		printf("%d\n", score[i]);
	}
	else
	{
		printf("%d\n", score[i]);
		i++;
		goto LABEL; // L,22　LABELへジャンプ
	}

	return;

}