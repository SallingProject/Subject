#include<stdio.h>

#define MAX 10

// 意味のある名前にしよう
// たとえばloopなど
// あとは引数に最大数を設定できればいいかもね
void hoge(int *, int );

void main() {
	
	/*　変数　*/

	int score[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;

	/*　処理　*/

	hoge(score, i);

	return;

}


void hoge(int *data, int x) {

	
	if (x < MAX)	//仮引数ｘが10未満の場合
	{	
		printf("%d\n", *data);	//dataのポインタの中身を表示
		++data;					//ポインタを進める。
		hoge(data, x + 1);		//再起呼び出し
	}
	// このelse条件は無駄ないほうがわかりやすい
	else
	{
		return;
	}
	
}