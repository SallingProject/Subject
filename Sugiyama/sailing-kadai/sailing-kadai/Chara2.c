#include<stdio.h>

/* �\���̂̌^�g�̐錾 */

struct STATUS {
		float HP;
		float AT;
		float DF;
};


void main() {

	/* �\���̂̃I�u�W�F�N�g�̏����� */

	struct STATUS status = {
		10,		//HP
		6,		//AT
		4		//DF
	};
	
	/* �I�u�W�F�N�g�̕\�� */

	printf("HP = %.5f\n", status.HP);
	printf("AT = %.5f\n", status.AT);
	printf("DF = %.5f\n", status.DF);


	return;
}