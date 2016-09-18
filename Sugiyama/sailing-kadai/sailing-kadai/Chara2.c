#include<stdio.h>

/* 構造体の型枠の宣言 */

struct STATUS {
		float HP;
		float AT;
		float DF;
};


void main() {

	/* 構造体のオブジェクトの初期化 */

	struct STATUS status = {
		10,		//HP
		6,		//AT
		4		//DF
	};
	
	/* オブジェクトの表示 */

	printf("HP = %.5f\n", status.HP);
	printf("AT = %.5f\n", status.AT);
	printf("DF = %.5f\n", status.DF);


	return;
}