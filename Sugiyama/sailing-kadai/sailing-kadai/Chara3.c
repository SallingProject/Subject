#include<stdio.h>

/* �\���̂̌^�g�̐錾 */

typedef struct {
		float HP;
		float AT;
		float DF;
}STATUS;

/* STATUS�^�֐��FReturn_Initialization */

//STATUS�^�ϐ�status��Ԃ����Ƃɂ���āA�I�u�W�F�N�g���Ƃ��ɋA���Ă���B

STATUS Return_Initialization(){	

	STATUS status;

	status.HP = 10;
	status.AT = 6;
	status.DF = 4;

	return status;
}

void main() {

	STATUS data;	//STATUS�^�ϐ�data

	data = Return_Initialization();

	/*�@�\���@*/

	printf("HP:%.5f\n", data.HP);
	printf("AT:%.5f\n", data.AT);
	printf("DF:%.5f\n", data.DF);

	return;
}