#include<stdio.h>


// 改善前
//void main(){
//
//	/* 変数宣言 */
//	int score[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i;  
//
//	/* 処理 */
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", score[i]);
//	}
//
//	return;
//}

// 改善後
// 配列の最大数やループの回数などは直接数値リテラルを使うのではなく
// 定数を定義して扱ったほうがコードの可読性があがるよ( ｀ー´)ノ
#define MAX 10
void main() {
	
	/* 変数宣言 */
	int score[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	/* 処理 */
	for (int i = 0; i < MAX; ++i) 
	{
		printf("%d\n", score[i]);
	}

	return;
}