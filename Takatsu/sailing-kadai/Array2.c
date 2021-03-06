#include <stdio.h>

/*************************************************

初期値として1~10までの整数値を入れた配列を用意し
その値をループ構文(for,do-while,while)
を一切使用せずループを実現し表示しなさい。

*************************************************/

#define MAX 10
//質問:関数内でdefineのMAXを呼び出そうとしたのですがうまくいきませんでした。
//関数内で呼び出す方法はないのでしょうか?
// A.#defineは定数定義としても記述できるマクロであることを示します。
//   #defineでは10と言うプログラムのコードをMAXというコードに変換しているのです。
//   つまり細かくなりますが、#define MAX 10;のように最後に;をつけてしまうとMAXは10;というコードに置き換わってしまいます。
//   なので関数では呼び出せなかったのでしょう。関数の内部で使用したい場合は上記の定義を#define MAX 10としてください。


/*プロトタイプ宣言*/
// loopやで
int loop(int data[], int);




int main()
{
	
	/*変数宣言*/
	int Array[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	

	/*関数呼び出し*/
	loop(Array, i);


	return 0;

}

/*****************************************

関数名: loop
引数  : 配列Array int型変数i
返り値: なし
備考  : 関数内で変数iの値を表示
変数iがMAX(10)より小さい時iの値を増やし
loop関数を再度呼び出す

*****************************************/

int loop(int data[],int i)
{

	
	if(i < MAX)
	{

		printf("%d\n", data[i]);
		
		
		/*関数呼び出し*/
		loop(data, i + 1);

	}
	
	return;

}