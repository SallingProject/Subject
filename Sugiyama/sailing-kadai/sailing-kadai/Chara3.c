#include<stdio.h>

/* 構造体の型枠の宣言 */

typedef struct {
		float HP;
		float AT;
		float DF;
}STATUS;

/* STATUS型関数：Return_Initialization */

//STATUS型変数statusを返すことによって、オブジェクトがともに帰ってくる。

STATUS Return_Initialization(){	

	STATUS status;

	status.HP = 10;
	status.AT = 6;
	status.DF = 4;

	return status;
}

void main() {

	STATUS data;	//STATUS型変数data

	data = Return_Initialization();

	/*　表示　*/

	printf("HP:%.5f\n", data.HP);
	printf("AT:%.5f\n", data.AT);
	printf("DF:%.5f\n", data.DF);

	return;
}