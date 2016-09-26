#include <stdio.h>

/*******************************************************************

Chara1.cで作成した構造体型オブジェクトと構造体型を
返り値とする関数を作成する。
関数の返り値を使って初期化しmain関数側でデータをすべてを表示し、
初期化されているか確認をする。

*******************************************************************/


/*******************************************

構造体変数名: status
メンバ名    : hp       ライフ
              attack 　攻撃力
              defense  防御力

*******************************************/

struct status
{

	float hp;
	float attack;
	float defense;

};


/*構造体のプロトタイプ宣言*/
struct status chara();


void main()
{

	/*構造体の定義*/
	struct status data;


	/*関数の参照*/
	data = chara();


	/*表示*/
	printf("HP: %f\n", data.hp);
	printf("ATK: %f\n", data.attack);
	printf("DEF: %f\n", data.defense);


	return;

}

/******************************

構造体タグ名: chara
引数        : なし
戻り値      : data

******************************/

struct status chara()
{

	/* 構造体の定義 */
	struct status data;

	data.hp = 10;
	data.attack = 6;
	data.defense = 4;

	return data;

}