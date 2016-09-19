#include<stdio.h>



/* 構造体の型枠の宣言 */

typedef struct  {
		float HP;
		float AT;
		float DF;
}STATUS;

/* プロトタイプ宣言 */

void Initialization_Variable(STATUS *);


/* 構造体のオブジェクトの初期化 */

void main() {

	STATUS status;

	/* 処理 */
	Initialization_Variable(&status);
		
	
	/* オブジェクトの表示 */

	printf("HP = %.5f\n", status.HP);
	printf("AT = %.5f\n", status.AT);
	printf("DF = %.5f\n", status.DF);


	return;
}

void Initialization_Variable(STATUS *data){

	data->HP = 10;
	data->AT = 6;
	data->DF = 4;

	return;
}