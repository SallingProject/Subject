#include <stdio.h>

/***********************************************

構造体を作成しなさい。要件は以下のものとする。
�@ライフを表すfloat型の変数
�A攻撃力を表すfloat型の変数
�B防御力を表すfloat型の変数
main関数側で構造体オブジェクトを作成する。

***********************************************/


/****************************************

構造体変数名: status
メンバ名    : hp       ライフ
			  attack 　攻撃力
			  defense  防御力

****************************************/
struct status
{

	float hp;
	float attack;
	float defense;

};

/**************************************/

int main()
{

	/* 構造体の定義 */
	struct status data;

	return 0;

}