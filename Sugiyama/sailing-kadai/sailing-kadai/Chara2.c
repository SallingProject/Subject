#include<stdio.h>



/* �\���̂̌^�g�̐錾 */

typedef struct  {
		float HP;
		float AT;
		float DF;
}STATUS;

/* �v���g�^�C�v�錾 */

void Initialization_Variable(STATUS *);


/* �\���̂̃I�u�W�F�N�g�̏����� */

void main() {

	STATUS status;

	/* ���� */
	Initialization_Variable(&status);
		
	
	/* �I�u�W�F�N�g�̕\�� */

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