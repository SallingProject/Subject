#include <stdio.h>

/**************************************************************

Chara1.cで作成した構造体型オブジェクトと構造体型を
引数とする関数を作成する。関数内部で構造体の各種データを
初期化しmain関数側でデータをすべてを表示し、
初期化されているか確認をする。


**************************************************************/


/*******************************************

構造体変数名: status
メンバ名    : hp       ライフ
              attack 　攻撃力
              defense  防御力

*******************************************/

typedef struct
{

	float hp;
	float attack;
	float defense;

}status;


/*構造体のプロトタイプ宣言*/
void hoge(status *data);


int main()
{

	/*構造体の定義*/
	 status data;


	 /*関数の参照*/
	 hoge(&data);

	 /*表示*/
	 printf("HP: %f\n", data.hp);
	 printf("ATK: %f\n", data.attack);
	 printf("DEF: %f\n", data.defense);

	return 0;

}

/******************************

構造体タグ名: hoge
引数        : data

******************************/

void  hoge(status *data)
{

	data->hp = 10;
	data->attack = 6;
	data->defense = 4;



	return;

}